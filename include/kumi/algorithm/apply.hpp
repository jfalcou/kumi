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
  template<typename F, typename T, std::size_t... I>
  KUMI_ABI constexpr decltype(auto) apply_(kumi::adl_tag_t, F&& f, T&& t, std::index_sequence<I...>)
  {
    if constexpr (kumi::concepts::empty_product_type<T>) return kumi::invoke(KUMI_FWD(f));
    else return kumi::invoke(KUMI_FWD(f), get<I>(KUMI_FWD(t))...);
  }

  struct apply_t
  {
    template<typename Function, kumi::concepts::product_type T>
    KUMI_ABI constexpr decltype(auto) operator()(Function&& f, T&& t) const
      noexcept(kumi::_::supports_nothrow_apply<Function&&, T&&>)
    requires(kumi::_::supports_apply<Function, T>)
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(KUMI_FWD(f), kumi::values_of(KUMI_FWD(t)));
      else return apply_(kumi::adl_tag, KUMI_FWD(f), KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct apply_field_t
  {
    template<typename Function, kumi::concepts::record_type R>
    KUMI_ABI constexpr decltype(auto) operator()(Function&& f, R&& t) const
    {
      return apply_(kumi::adl_tag, KUMI_FWD(f), KUMI_FWD(t), std::make_index_sequence<kumi::size_v<R>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup transforms

    @var apply
    @brief Callable object invoking the callable object f with the elements of the product type unrolled as arguments.

    `f` is applied on the underlying values when the input `t` is a record type.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t`.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/apply.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T>
      constexpr decltype(auto) apply(Function && f, T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to be invoked
      - `t`: Product Type whose elements are used as arguments to f

    @subgroupheader{Return value}

      - The value returned by f.

    @groupheader{Helper type}

    @snippet algorithm/apply.hpp apply_t

    Computes the return type of a call to kumi::apply

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/apply.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/apply.cpp}
  **/
  //====================================================================================================================
  inline constexpr apply_t apply{};

  //====================================================================================================================
  /**
    @ingroup transforms

    @var apply_field
    @brief Callable object invoking the callable object f with the elements of the product type unrolled as arguments.

    `f` is applied on the fields when the input `t` is a record type.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t`.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/apply.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T>
      constexpr decltype(auto) apply_field(Function && f, T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to be invoked
      - `t`: Product Type whose elements are used as arguments to f

    @subgroupheader{Return value}

      - The value returned by f.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/apply.hpp apply_field_t

    Computes the return type of a call to kumi::apply_field

    @groupheader{Example}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/apply_field.cpp}
  **/
  //====================================================================================================================
  inline constexpr apply_field_t apply_field{};

  namespace result
  {
    //! [apply_t]
    template<typename Function, kumi::concepts::product_type T> struct apply
    {
      using type = decltype(kumi::apply(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T> using apply_t = typename apply<Function, T>::type;

    //! [apply_t]

    //! [apply_field_t]
    template<typename Function, kumi::concepts::record_type R> struct apply_field
    {
      using type = decltype(kumi::apply_field(std::declval<Function>(), std::declval<R>()));
    };

    template<typename Function, concepts::record_type R> using apply_field_t = typename apply_field<Function, R>::type;
    //! [apply_field_t]

  }
}
