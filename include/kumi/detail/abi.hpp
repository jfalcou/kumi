//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

//======================================================================================================================
// C++ version check
//======================================================================================================================
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

//======================================================================================================================
/**
 Frontend  detection

 Order matters, compilers can impersonate others.
   - EDG   : nvcc (cudafe++) and other EDG compilers. Defines __GNUC__ / _MSC_VER too, so it is tested first.
   - clang : defines __GNUC__, and also _MSC_VER for clang-cl. Tested before gcc and msvc.
   - gcc   : anything else defining __GNUC__
   - msvc  : cl.exe
**/
//======================================================================================================================
#if defined(__EDG__) || defined(__EDG_VERSION__)
#define KUMI_FRONTEND_EDG 1
#elif defined(__clang__)
#define KUMI_FRONTEND_CLANG 1
#elif defined(__GNUC__)
#define KUMI_FRONTEND_GCC 1
#elif defined(_MSC_VER)
#define KUMI_FRONTEND_MSVC 1
#endif

//======================================================================================================================
/**
  Device backend detection

   - NVIDIA : nvcc, clang -x cuda, and hipcc when HIP targets the NVIDIA platform.
   - AMD    : clang -x hip (hipcc on ROCm).

 The HIP platform macros are tested first: on the NVIDIA platform __CUDACC__ is also defined.
**/
//======================================================================================================================
#if defined(__HIP_PLATFORM_NVIDIA__) || defined(__HIP_PLATFORM_NVCC__)
#define KUMI_DEVICE_NVIDIA 1
#elif defined(__HIP__) || defined(__HIPCC__) || defined(__HIP_PLATFORM_AMD__) || defined(__HIP_PLATFORM_HCC__)
#define KUMI_DEVICE_AMD 1
#elif defined(__CUDACC__) || defined(__NVCC__) || defined(__CUDA__)
#define KUMI_DEVICE_NVIDIA 1
#endif

#if defined(KUMI_DEVICE_NVIDIA) || defined(KUMI_DEVICE_AMD)
#define KUMI_GPU_COMPILER 1
#define KUMI_GPU __host__ __device__
#else
#define KUMI_GPU
#endif

// Are we currently generating device code?
#if (defined(KUMI_DEVICE_NVIDIA) && defined(__CUDA_ARCH__)) ||                                                         \
  (defined(KUMI_DEVICE_AMD) && defined(__HIP_DEVICE_COMPILE__))
#define KUMI_DEVICE_PASS 1
#endif

//======================================================================================================================
/**
  KUMI_ABI : public functions. Attributes are fixed per frontend.

  frontend  always_inline              flatten             artificial
  --------  -------------------------  ------------------  ----------------
   EDG       __forceinline__            (not available)     (not available)
   clang     [[clang::always_inline]]   (too aggressive)    [[gnu::artificial]]
   gcc       [[gnu::always_inline]]     [[gnu::flatten]]    [[gnu::artificial]]
   msvc      [[msvc::forceinline]]      [[msvc::flatten]]   (not available)

 The device backend does not change the spelling: it is the frontend that parses it.
**/
//======================================================================================================================
#if defined(KUMI_DEBUG)
#define KUMI_ABI KUMI_GPU
#elif defined(KUMI_FRONTEND_EDG)
#if defined(KUMI_GPU_COMPILER)
#define KUMI_ABI KUMI_GPU __forceinline__
#else
#define KUMI_ABI inline
#endif
#elif defined(KUMI_FRONTEND_CLANG)
// Flatten is not that great on clang, it already inlines too much
#define KUMI_ABI [[clang::always_inline, gnu::artificial]] KUMI_GPU inline
#elif defined(KUMI_FRONTEND_GCC)
#define KUMI_ABI [[using gnu: always_inline, flatten, artificial]] KUMI_GPU inline
#elif defined(KUMI_FRONTEND_MSVC)
#define KUMI_ABI [[msvc::forceinline, msvc::flatten]] KUMI_GPU inline
#else
#define KUMI_ABI KUMI_GPU inline
#endif

//======================================================================================================================
// KUMI_HIDDEN_ABI : functions in namespace detail. Not force-inlined, so they keep a distinct ABI.
//======================================================================================================================
#define KUMI_HIDDEN_ABI KUMI_GPU inline

//======================================================================================================================
/**
  KUMI_VARIABLE_ABI : namespace-scope objects.

  A namespace-scope object lives in host memory, so a kernel naming kumi::apply finds nothing under
  nvcc or hipcc. The device pass gets a copy of its own; every other pass keeps the inline variable.
**/
//======================================================================================================================
#if defined(KUMI_DEVICE_PASS)
#define KUMI_VARIABLE_ABI __device__
#else
#define KUMI_VARIABLE_ABI inline
#endif

//======================================================================================================================
/**
  KUMI_ERROR : misuse reporting.

  Device code has no exceptions: the same misuse aborts the kernel there. __builtin_trap() is the
  portable spelling that the NVIDIA (nvcc, clang) and AMD (clang) device back-ends lower to a trap.
**/
//======================================================================================================================
#if defined(KUMI_DEVICE_PASS)
#define KUMI_ERROR(MESSAGE) __builtin_trap()
#else
#define KUMI_ERROR(MESSAGE) throw MESSAGE
#endif

//======================================================================================================================
/**
  KUMI_UNREACHABLE : invokes UB.

  Device code has no exceptions: the same misuse aborts the kernel there. __builtin_trap() is the
  portable spelling that the NVIDIA (nvcc, clang) and AMD (clang) device back-ends lower to a trap.
**/
//======================================================================================================================
#if defined(__cpp_lib_unreachable)
#define KUMI_UNREACHABLE() std::unreachable()
#elif defined(KUMI_FRONTEND_MSVC)
#define KUMI_UNREACHABLE() __assume(false)
#else
#define KUMI_UNREACHABLE() __builtin_unreachable()
#endif

//======================================================================================================================
// Diagnostics
//======================================================================================================================
#if defined(KUMI_FRONTEND_CLANG)
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif
