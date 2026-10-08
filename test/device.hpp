//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>

#if defined(__HIPCC__)
#include <hip/hip_runtime.h>
#else
#include <cuda_runtime.h>
#endif

//==================================================================================================
//! Device backend interface
//! HIP is AMD's CUDA-compatible interface, so the handful of runtime calls a kernel needs are
//! gathered in one small interface per vendor backend. A namespace alias then selects the backend
//! matching the compiler building the unit, so a single harness drives both NVIDIA and AMD devices.
//==================================================================================================
namespace kumi_test
{
  namespace cuda
  {
    inline int count()
    {
      int n = 0;
      return (cudaGetDeviceCount(&n) == cudaSuccess) ? n : 0;
    }

    inline bool allocate(void** ptr, std::size_t bytes)
    {
      return cudaMalloc(ptr, bytes) == cudaSuccess;
    }

    inline bool set(void* ptr, int value, std::size_t n)
    {
      return cudaMemset(ptr, value, n) == cudaSuccess;
    }

    inline bool launch_ok()
    {
      return cudaGetLastError() == cudaSuccess;
    }

    inline bool synchronize()
    {
      return cudaDeviceSynchronize() == cudaSuccess;
    }

    inline bool copy_out(void* dst, void const* src, std::size_t bytes)
    {
      return cudaMemcpy(dst, src, bytes, cudaMemcpyDeviceToHost) == cudaSuccess;
    }

    inline bool release(void* ptr)
    {
      return cudaFree(ptr) == cudaSuccess;
    }
  }

  namespace hip
  {
    inline int count()
    {
      int n = 0;
      return (hipGetDeviceCount(&n) == hipSuccess) ? n : 0;
    }

    inline bool allocate(void** ptr, std::size_t bytes)
    {
      return hipMalloc(ptr, bytes) == hipSuccess;
    }

    inline bool set(void* ptr, int value, std::size_t n)
    {
      return hipMemset(ptr, value, n) == hipSuccess;
    }

    inline bool launch_ok()
    {
      return hipGetLastError() == hipSuccess;
    }

    inline bool synchronize()
    {
      return hipDeviceSynchronize() == hipSuccess;
    }

    inline bool copy_out(void* dst, void const* src, std::size_t bytes)
    {
      return hipMemcpy(dst, src, bytes, hipMemcpyDeviceToHost) == hipSuccess;
    }

    inline bool release(void* ptr)
    {
      return hipFree(ptr) == hipSuccess;
    }
  }

#if defined(__HIPCC__)
  namespace backend = hip;
#else
  namespace backend = cuda;
#endif
}

//==================================================================================================
//! Running a kernel and reading back what it computed
//==================================================================================================

// The kernel writes what it computed into one trivially copyable object, so a failure shows the value
// the device produced instead of a flag. A run that never reached a device returns false, and a
// machine without one fails its tests rather than passing an empty check.
template<typename Kernel, typename Result> inline bool run_on_device(Kernel kernel, Result& out)
{
  if (kumi_test::backend::count() == 0) return false;

  Result* on_device = nullptr;
  if (!kumi_test::backend::allocate(&on_device, sizeof(Result))) return false;
  kumi_test::backend::set(on_device, 0, sizeof(Result));

  kernel<<<1, 1>>>(on_device);

  auto launched = kumi_test::backend::launch_ok();
  auto ran = kumi_test::backend::synchronize();
  auto copied = kumi_test::backend::copy_out(&out, on_device, sizeof(Result));
  kumi_test::backend::release(on_device);

  return launched && ran && copied;
}
