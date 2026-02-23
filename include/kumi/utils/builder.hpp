//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  //! @ingroup traits
  //! @brief   Extracts the common product_type of a parameter pack, if all the types are `record`
  //!          then it returns an empty record, otherwise returns an empty `kumi::tuple`. As we
  //!          are unable to compute the Least Restrictive Subtype of a pack, this trait should
  //!          be specialized for each case one would want to write.
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
  //====================================================================================================================
  template<typename... Ts> struct common_product_type
  {
  };

  template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;

  //====================================================================================================================
  //! @ingroup utility
  //! @class builder
  //! @brief Helper structure to build the correct output `product_type`. If the provided Product
  //!        type is a not a record_type the builder will output a tuple otherwise a record.
  //!
  //! builder provides a generic way of defining a kumi::product_type which depending on the
  //! given semantic (product_type or record_type) will output respectively a kumi::tuple or a
  //! kumi::record
  //!
  //! @tparam T the template template type to be built.
  //====================================================================================================================
  template<typename T> struct builder;

  template<typename T> struct builder<T&> : builder<T>
  {
  };

  template<typename T> struct builder<T&&> : builder<T>
  {
  };

  template<typename T> struct builder<T const&> : builder<T>
  {
  };

  template<typename T> struct builder<T const&&> : builder<T>
  {
  };

  template<typename T> using builder_t = typename builder<T>::type;

  template<typename T, typename... Args> using builder_make_t = typename builder<T>::template to<Args...>;
}
