//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wmissing-braces"
#endif

// Macro to replace std::forward. Better compile-time + less error-prone
#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__) &&>(__VA_ARGS__)
