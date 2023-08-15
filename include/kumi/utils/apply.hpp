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
  //! @brief Invoke the Callable object f with a tuple of arguments.
  //!
  //! @param f	Callable object to be invoked
  //! @param t  kumi::product_type whose elements to be used as arguments to f
  //! @return The value returned by f.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct apply;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using apply_t = typename apply<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::apply
  //!
  //! ## Example
  //! @include doc/apply.cpp
  //================================================================================================
  template<typename Function, product_type Tuple>
  constexpr decltype(auto) apply(Function &&f, Tuple &&t)
  {
    if constexpr(sized_product_type<Tuple,0>) return  KUMI_FWD(f)();
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto)
      {
        return KUMI_FWD(f)(get<I>(KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size<Tuple>::value>());
    }
  }

  namespace result
  {
    template<typename Function, product_type Tuple>
    struct apply
    {
      using type = decltype(kumi::apply(std::declval<Function>(), std::declval<Tuple>()));
    };

    template<typename Function, product_type Tuple>
    using apply_t = typename apply<Function,Tuple>::type;
  }
}
