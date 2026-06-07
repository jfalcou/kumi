//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::function
{
  struct identity_t
  {
    template<typename T> KUMI_ABI constexpr T&& operator()(T&& t) const noexcept { return KUMI_FWD(t); }
  };

  inline constexpr identity_t identity{};
}
