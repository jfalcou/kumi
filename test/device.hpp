//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cuda_runtime.h>

//==================================================================================================
//! Running a kernel and reading back what it computed
//==================================================================================================

// The kernel writes what it computed into one trivially copyable object, so a failure shows the value
// the device produced instead of a flag. A run that never reached a device returns false, and a
// machine without one fails its tests rather than passing an empty check.
template<typename Kernel, typename Result> inline bool run_on_device(Kernel kernel, Result& out)
{
  int devices = 0;
  if (cudaGetDeviceCount(&devices) != cudaSuccess || devices == 0) return false;

  Result* on_device = nullptr;
  if (cudaMalloc(&on_device, sizeof(Result)) != cudaSuccess) return false;
  cudaMemset(on_device, 0, sizeof(Result));

  kernel<<<1, 1>>>(on_device);

  auto launched = cudaGetLastError();
  auto ran = cudaDeviceSynchronize();
  auto copied = cudaMemcpy(&out, on_device, sizeof(Result), cudaMemcpyDeviceToHost);
  cudaFree(on_device);

  return (launched == cudaSuccess) && (ran == cudaSuccess) && (copied == cudaSuccess);
}
