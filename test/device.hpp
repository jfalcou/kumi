//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cuda_runtime.h>
#include <cstddef>
#include <vector>

//==================================================================================================
//! Running a kernel and reading back what it checked
//==================================================================================================

// A run that never reached a device reports every flag false, so a machine without a GPU fails its tests.
struct device_result
{
  bool ran = false;
  std::vector<char> flags = {};

  bool operator[](std::size_t i) const { return ran && (i < flags.size()) && (flags[i] != 0); }
};

// Every CUDA call is checked before the flags are trusted.
template<typename Kernel> inline device_result run_on_device(Kernel kernel, std::size_t count)
{
  int devices = 0;
  if (cudaGetDeviceCount(&devices) != cudaSuccess || devices == 0) return {};

  char* on_device = nullptr;
  if (cudaMalloc(&on_device, count) != cudaSuccess) return {};
  cudaMemset(on_device, 0, count);

  kernel<<<1, 1>>>(on_device);

  std::vector<char> flags(count, 0);
  auto launched = cudaGetLastError();
  auto ran = cudaDeviceSynchronize();
  auto copied = cudaMemcpy(flags.data(), on_device, count, cudaMemcpyDeviceToHost);
  cudaFree(on_device);

  if (launched != cudaSuccess || ran != cudaSuccess || copied != cudaSuccess) return {};
  return {true, flags};
}
