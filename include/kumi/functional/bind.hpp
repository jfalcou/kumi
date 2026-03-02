//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::_
{
  template<typename F, typename... Ts> KUMI_ABI constexpr auto bind_front(F&& f, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) {
      return invoke(KUMI_FWD(f), KUMI_FWD(ts)..., KUMI_FWD(call_args)...);
    };
  }

  template<typename F, typename... Ts> KUMI_ABI constexpr auto bind_back(F&& f, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) {
      return invoke(KUMI_FWD(f), KUMI_FWD(call_args)..., KUMI_FWD(ts)...);
    };
  }

  template<typename F, typename... Ts> KUMI_ABI constexpr auto bind(F&& f, Ts&&... ts)
  {
    return [&] { return invoke(KUMI_FWD(f), KUMI_FWD(ts)...); };
  }
}
