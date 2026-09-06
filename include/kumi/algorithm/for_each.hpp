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
    KUMI_HIDDEN_ABI constexpr void for_each_switch(auto N, F f, T&& t, Ts&&... ts)
    {
      if constexpr (Case == kumi::_::case_::normal)
      {
        if constexpr (kumi::concepts::record_type<T>)
        {
          constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
          kumi::invoke(f, get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...);
        }
        else kumi::invoke(f, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
      }
      else if constexpr (Case == kumi::_::case_::indexed)
      {
        kumi::invoke(f, N, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
      }
      else if constexpr (Case == kumi::_::case_::field)
      {
        constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
        kumi::invoke(f, kumi::_::make_str(field), get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...);
      }
    }

    template<kumi::_::case_ Case, typename F, std::size_t... I, typename T, typename... Ts>
    KUMI_HIDDEN_ABI constexpr void for_each_(kumi::_::adl_tag_t, F&& f, std::index_sequence<I...>, T&& t, Ts&&... ts)
    {
      if constexpr (sizeof...(I) == 0) return;
      else ((for_each_switch<Case>(kumi::index<I>, KUMI_FWD(f), KUMI_FWD(t), KUMI_FWD(ts)...)), ...);
    }
  }

  struct for_each_t
  {
    template<typename Function, kumi::concepts::product_type T, kumi::concepts::product_type... Ts>
    KUMI_ABI constexpr void operator()(Function f, T&& t, Ts&&... ts) const
    requires(kumi::concepts::compatible_product_types<T, Ts...>) && (kumi::_::supports_call<Function&, T, Ts...>)
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return;
      else
        for_each_<kumi::_::case_::normal>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<T>>{}, KUMI_FWD(t),
                                          KUMI_FWD(ts)...);
    }
  };

  struct for_each_index_t
  {
    template<typename Function, kumi::concepts::product_type T, kumi::concepts::product_type... Ts>
    KUMI_ABI constexpr void operator()(Function f, T&& t, Ts&&... ts) const
    requires(!kumi::concepts::record_type<T> && (!kumi::concepts::record_type<Ts> && ...))
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return;
      else
        for_each_<kumi::_::case_::indexed>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<T>>{},
                                           KUMI_FWD(t), KUMI_FWD(ts)...);
    }
  };

  struct for_each_field_t
  {
    template<typename Function, kumi::concepts::record_type R, kumi::concepts::record_type... Rs>
    KUMI_ABI constexpr void operator()(Function f, R&& r, Rs&&... rs) const
    requires(kumi::concepts::compatible_product_types<R, Rs...>)
    {
      if constexpr (kumi::concepts::empty_product_type<R>) return;
      else
        for_each_<kumi::_::case_::field>(kumi::_::adl_tag, f, std::make_index_sequence<kumi::size_v<R>>{}, KUMI_FWD(r),
                                         KUMI_FWD(rs)...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_transforms

    @var for_each
    @brief Callable object applying the Callable object f on each element of a product type.

    `f` is applied on the values if the given product_type is a record type.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and/or `ts`, or if the product type are not compatible. @see compatible_product_types.

    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/for_each.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr decltype(auto) for_each(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to be invoked
      - `t`: Product Type whose elements are used as arguments to f
      - `ts`: Other product types whose elements are used as arguments to f

    @see kumi::for_each_index
    @see kumi::for_each_field

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/for_each.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/for_each.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr for_each_t for_each{};

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_transforms

    @var for_each
    @brief Callable object applying the Callable object f on each element of a product type and its index.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and/or `ts` and an integral constant. This function cannot be applied
          on record types.

    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/for_each.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr decltype(auto) for_each_index(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to be invoked
      - `t`: Product Type whose elements are used as arguments to f
      - `ts`: Other product types whose elements are used as arguments to f

    @see kumi::for_each
    @see kumi::for_each_field

    @groupheader{Examples}

    @godbolt{doc/tuple/algo/for_each_index.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr for_each_index_t for_each_index{};

  //====================================================================================================================
  /**
    @ingroup kumi_record_transforms

    @var for_each
    @brief Callable object applying the Callable object f on each element of a product type and its field.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and/or `ts` and a field or if the product types are not compatible.
          @see compatible_product_types


    This function can only be applied to record types.
    The function needs to be defined to handle types modeling kumi::concepts::field.

    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/for_each.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr decltype(auto) for_each_field(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to be invoked
      - `t`: Product Type whose elements are used as arguments to f
      - `ts`: Other product types whose elements are used as arguments to f

    @see kumi::for_each
    @see kumi::for_each_index

    @groupheader{Examples}

    @godbolt{doc/tuple/algo/for_each_field.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr for_each_field_t for_each_field{};
}
