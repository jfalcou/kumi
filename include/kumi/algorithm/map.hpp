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
  namespace _
  {
    template<kumi::_::case_ Case, typename F, typename T, typename... Ts>
    KUMI_HIDDEN_ABI constexpr decltype(auto) map_switch(auto N, F f, T&& t, Ts&&... ts)
    {
      if constexpr (Case == kumi::_::case_::normal)
      {
        if constexpr (kumi::concepts::record_type<T>)
        {
          constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
          return kumi::capture_field<field>(kumi::invoke(f, get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...));
        }
        else return kumi::invoke(f, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
      }
      else if constexpr (Case == kumi::_::case_::indexed)
      {
        return kumi::invoke(f, N, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
      }
      else if constexpr (Case == kumi::_::case_::field)
      {
        constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
        return kumi::capture_field<field>(
          kumi::invoke(f, kumi::_::make_str(field), get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...));
      }
    }

    template<kumi::_::case_ Case, typename F, std::size_t... I, typename T, typename... Ts>
    KUMI_HIDDEN_ABI constexpr decltype(auto) map_(
      kumi::_::adl_tag_t, F&& f, std::index_sequence<I...>, T&& t, Ts&&... ts)
    {
      if constexpr (sizeof...(I) == 0) return kumi::builder<T>::make();
      else
        return kumi::builder<T>::make(map_switch<Case>(kumi::index<I>, KUMI_FWD(f), KUMI_FWD(t), KUMI_FWD(ts)...)...);
    }
  }

  struct map_t
  {
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t, Ts&&... ts) const
    requires(kumi::concepts::compatible_product_types<T, Ts...>) && (kumi::_::supports_call<Function, T &&, Ts && ...>)
    {
      return map_<kumi::_::case_::normal>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<T>>{}, KUMI_FWD(t),
                                          KUMI_FWD(ts)...);
    }
  };

  struct map_index_t
  {
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t, Ts&&... ts) const
    requires(!kumi::concepts::record_type<T> && (!kumi::concepts::record_type<Ts> && ...))
    {
      return map_<kumi::_::case_::indexed>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<T>>{},
                                           KUMI_FWD(t), KUMI_FWD(ts)...);
    }
  };

  struct map_field_t
  {
    template<typename Function,
             kumi::concepts::record_type R,
             kumi::concepts::sized_product_type<kumi::size_v<R>>... Rs>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, R&& r, Rs&&... rs) const
    requires(kumi::concepts::compatible_product_types<R, Rs...>)
    {
      return map_<kumi::_::case_::field>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<R>>{}, KUMI_FWD(r),
                                         KUMI_FWD(rs)...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_transforms

    @var map
    @brief Callable object applying the Callable object `f` on each product types' elements

    Applies the given function to all the product types passed as arguments and stores the result in another product
    type, keeping the original elements order. On records, the order is determined via the order of definition of
    the fields.

    @note Does not participate in overload resolution if product types' size are not equal or if
          `f` can't be called on each product type's elements. All product type must either be
          record types or product types, mixing is not supported.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_t

    Computes the return type of a call to kumi::map

    @see kumi::map_index
    @see kumi::map_field

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/map.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/map.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr map_t map{};

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_transforms

    @var map_index
    @brief Callable object applying the Callable object `f` on each product types elements and their indexes

    Applies the given function to all the product types passed as arguments along with their indexes and stores the
  result in another product type, keeping the original elements order.

    @note Does not participate in overload resolution if tuples' size are not equal or if `f`
          can't be called on each tuple's elements and their indexes.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map_index(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_index_t

    Computes the return type of a call to kumi::map_index

    @see kumi::map
    @see kumi::map_field

    @groupheader{Example}

    @godbolt{doc/tuple/algo/map_index.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr map_index_t map_index{};

  //====================================================================================================================
  /**
    @ingroup kumi_record_transforms

    @var map_field
    @brief Callable object applying the Callable object `f` on each product types elements and their associated labels.

    Applies the given function to all the records passed as arguments along with their names and
    stores the result in another records, keeping the original elements order.

    @note Does not participate in overload resolution if records' size are not equal or if `f`
          can't be called on each record's fields and their names.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map_index(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_field_t

    Computes the return type of a call to kumi::map_field

    @see kumi::map
    @see kumi::map_index

    @groupheader{Example}

    @godbolt{doc/record/algo/map_field.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr map_field_t map_field{};

  namespace result
  {
    //! [map_t]
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_t = decltype(kumi::map(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));

    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map
    {
      using type = kumi::result::map_t<Function, T, Ts...>;
    };

    //! [map_t]

    //! [map_index_t]
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_index_t = decltype(kumi::map_index(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));

    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map_index
    {
      using type = kumi::result::map_index_t<Function, T, Ts...>;
    };

    //! [map_index_t]

    //! [map_field_t]
    template<typename Function,
             kumi::concepts::record_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_field_t = decltype(kumi::map_field(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));

    template<typename Function,
             kumi::concepts::record_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map_field
    {
      using type = kumi::result::map_field_t<Function, T, Ts...>;
    };

    //! [map_field_t]
  }
}
