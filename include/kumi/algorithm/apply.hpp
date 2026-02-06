//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @ingroup transforms
  //! @brief Invoke the Callable object f with a product_type of arguments. f is applied on the
  //!        values if the given product_type is a kumi::record
  //!
  //! @param f	Callable object to be invoked
  //! @param t  kumi::product_type whose elements to be used as arguments to f
  //! @return The value returned by f.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T> struct apply;
  //!
  //!   template<typename Function, product_type T>
  //!   using apply_t = typename apply<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::apply
  //!
  //! ## Example
  //! @include doc/tuple/algo/apply.cpp
  //! @include doc/record/algo/apply.cpp
  //================================================================================================
  template<typename Function, product_type T>
  KUMI_ABI constexpr decltype(auto) apply(Function&& f, T&& t) noexcept(_::supports_nothrow_apply<Function&&, T&&>)
  requires _::supports_apply<Function, T>
  {
    if constexpr (sized_product_type<T, 0>) return invoke(KUMI_FWD(f));
    else if constexpr (record_type<T>) return apply(KUMI_FWD(f), values_of(KUMI_FWD(t)));
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto) {
        return invoke(KUMI_FWD(f), get<I>(KUMI_FWD(t))...);
      }(std::make_index_sequence<size_v<T>>{});
  }

  namespace result
  {
    template<typename Function, product_type T> struct apply
    {
      using type = decltype(kumi::apply(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, product_type T> using apply_t = typename apply<Function, T>::type;
  }

  namespace _
  {
    template<typename Function, record_type R> KUMI_ABI constexpr decltype(auto) apply_field(Function&& f, R&& t)
    {
      if constexpr (sized_product_type<R, 0>) return invoke(KUMI_FWD(f));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto) {
          return invoke(KUMI_FWD(f), get<I>(KUMI_FWD(t))...);
        }(std::make_index_sequence<size_v<R>>{});
      ;
    }

    namespace result
    {
      template<typename Function, record_type R> struct apply_field
      {
        using type = decltype(kumi::_::apply_field(std::declval<Function>(), std::declval<R>()));
      };

      template<typename Function, record_type R> using apply_field_t = typename apply_field<Function, R>::type;
    }
  }
}
