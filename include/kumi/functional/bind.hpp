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

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    Binds a certain amount of values into a callable reducing it's arity.

    @param c	Callable object to be bound.
    @param ts elements to be used as prefilled arguments to c
    @return   A new callable matching C with ts arguments prefilled by the front.

    @note Replaces std::bind_front to avoid depending on `functional`.
  **/
  //====================================================================================================================
  template<typename C, typename... Ts> KUMI_ABI constexpr auto bind_front(C&& c, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) -> decltype(auto) {
      return invoke(KUMI_FWD(c), KUMI_FWD(ts)..., KUMI_FWD(call_args)...);
    };
  }

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    Binds a certain amount of values into a callable reducing it's arity.

    @param c	Callable object to be bound.
    @param ts elements to be used as prefilled arguments to c
    @return   A new callable matching C with ts arguments prefilled by the back.

    @note Replaces std::bind_front to avoid depending on `functional`.
  **/
  //====================================================================================================================
  template<typename C, typename... Ts> KUMI_ABI constexpr auto bind_back(C&& c, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) -> decltype(auto) {
      return invoke(KUMI_FWD(c), KUMI_FWD(call_args)..., KUMI_FWD(ts)...);
    };
  }

  template<typename C, typename... Ts> KUMI_ABI constexpr auto bind(C&& c, Ts&&... ts)
  {
    return [&]() -> decltype(auto) { return invoke(KUMI_FWD(c), KUMI_FWD(ts)...); };
  }
}
