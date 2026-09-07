//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#if defined(_MSC_VER)
#if _MSVC_LANG < 202002L
#error "KUMI C++ version error"
#include "KUMI requires C++20 or higher. Use /std:c++20 or higher to enable C++20 features."
#endif
#else
#if __cplusplus < 202002L
#error "KUMI C++ version error"
#include "KUMI requires C++20 or higher. Use -std=c++20 or higher to enable C++20 features."
#endif
#endif

#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)

#if defined(__CUDACC__) || defined(__NVCC__)
#define KUMI_CUDA __host__ __device__
#else
#define KUMI_CUDA
#endif

// Clang-CL does not define __GNUC__ https://github.com/llvm/llvm-project/issues/53259
#if defined(KUMI_DEBUG)
#define KUMI_ABI KUMI_CUDA
#elif defined(__EDG__) || defined(__EDG_VERSION__) || defined(__CUDACC__) || defined(__NVCC__)
#define KUMI_ABI KUMI_CUDA inline
#elif defined(__GNUC__) || defined(__clang__)
#define KUMI_ABI [[using gnu: always_inline, flatten, artificial]] KUMI_CUDA inline
#elif defined(_MSC_VER)
#define KUMI_ABI [[using msvc: forceinline, flatten]] KUMI_CUDA inline
#endif

// Functions in namespace detail should not be forceinline and have a different abi
#define KUMI_HIDDEN_ABI KUMI_CUDA inline

// A namespace-scope object lives in host memory, so a kernel naming kumi::apply finds nothing under
// nvcc. The device pass gets a copy of its own; every other pass keeps the inline variable.
#if defined(__CUDA_ARCH__)
#define KUMI_VARIABLE_ABI __device__
#else
#define KUMI_VARIABLE_ABI inline
#endif

// Device code has no exceptions: the same misuse aborts the kernel there.
#if defined(__CUDA_ARCH__)
#define KUMI_ERROR(MESSAGE) __trap()
#else
#define KUMI_ERROR(MESSAGE) throw MESSAGE
#endif

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif
