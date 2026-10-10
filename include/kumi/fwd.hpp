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
  // Forward declarations

  // This avoids including size_t at this level
  template<decltype(sizeof(0)) N> struct str;
  template<typename... Ts> struct tuple;
  template<typename... Ts> struct record;
  template<auto... Vs> struct projection_map;
}
