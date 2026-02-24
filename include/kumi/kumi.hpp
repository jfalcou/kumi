//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#if defined(_MSC_VER)
#if _MSVC_LANG < 202002L
#error "KUMI requires C++20 or higher. Use /std:c++20 or higher to enable C++20 features."
#endif
#elif __cplusplus < 202002L
#error "KUMI requires C++20 or higher. Use -std=c++20 or higher to enable C++20 features."
#else
#include <kumi/detail.hpp>
#include <kumi/utils.hpp>
#include <kumi/product_types.hpp>
#include <kumi/algorithm.hpp>
#endif
