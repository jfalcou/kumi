//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kumi/utils/concepts.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup traits
  //! @brief   Extracts the common product_type of a parameter pack, if all the types are `record`
  //!          then it returns an empty record, otherwise returns an empty `kumi::tuple`
  //!
  //! @tparam Ts The `product_types` to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename... Ts> using common_product_type_t
  //!       = typename common_product_type<Ts...>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<product_type... Ts> [[nodiscard]] KUMI_ABI constexpr auto common_product_type(Ts...)
  {
    if constexpr ((record_type<Ts> && ...)) return kumi::record{};
    else return kumi::tuple{};
  }

  namespace result
  {
    template<product_type... Ts> struct common_product_type
    {
      using type = decltype(kumi::common_product_type(std::declval<Ts>()...));
    };

    template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;
  }

  namespace _
  {
    template<typename T> struct builder_impl
    {
    };

    template<product_type Tuple>
    requires(!record_type<Tuple>)
    struct builder_impl<Tuple>
    {
      using type = Tuple;

      template<typename... Us> using to = kumi::tuple<Us...>;
    };

    template<record_type Record> struct builder_impl<Record>
    {
      using type = Record;

      template<typename... Us> using to = kumi::record<Us...>;
    };

    //================================================================================================
    //! @ingroup tuple
    //! @class builder
    //! @brief Helper structure to build the correct output `product_type`. If the provided Typle
    //!        is a not a record_type the builder will output a tuple otherwise a record.
    //!
    //! builder provides a generic way of defining a kumi::product_type which depending on the
    //! given semantic (product_type or record_type) will output respectively a kumi::tuple or a
    //! kumi::record
    //!
    //! @tparam T the template template type to be built.
    //================================================================================================

    template<kumi::product_type T> struct builder : builder_impl<std::remove_cvref_t<T>>
    {
      template<typename... Args> static constexpr auto make(Args&&... args)
      {
        if constexpr (record_type<T>) return kumi::make_record(KUMI_FWD(args)...);
        else return kumi::make_tuple(KUMI_FWD(args)...);
      }

      template<typename... Args> static constexpr auto build(Args&&... args)
      {
        if constexpr (record_type<T>) return kumi::record{KUMI_FWD(args)...};
        else return kumi::tuple{KUMI_FWD(args)...};
      }
    };

    template<kumi::product_type T> using builder_t = typename builder<T>::type;

    template<kumi::product_type T, typename... Args> using builder_make_t = typename builder<T>::template to<Args...>;
  }
}
