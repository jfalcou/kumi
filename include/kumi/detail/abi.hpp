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
#error "Kumi requires C++20 or higher. Use /std:c++20 or higher to enable C++20 features."
#endif
#else
#if __cplusplus < 202002L
#error "KUMI requires C++20 or higher. Use -std=c++20 or higher to enable C++20 features."
#endif
#endif

// Macro to replace std::forward. Better compile-time + less error-prone
#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)

#if defined(__CUDACC__)
#define KUMI_CUDA __host__ __device__
#else
#define KUMI_CUDA
#endif

#if defined(KUMI_DEBUG)
#define KUMI_ABI
#elif defined(__GNUC__) ||                                                                                             \
  defined(__clang__) // Clang-CL does not define __GNUC__ https://github.com/llvm/llvm-project/issues/53259
#define KUMI_ABI [[using gnu: always_inline, flatten, artificial]] KUMI_CUDA inline
#elif defined(_MSC_VER)
#define KUMI_ABI [[using msvc: forceinline, flatten]] KUMI_CUDA inline
#endif

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif
