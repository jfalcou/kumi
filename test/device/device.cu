//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <cuda_runtime.h>
#include <iostream>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

using struct_t = kumi::tuple<float, int, char>;

__global__ void kernel(struct_t input, struct_t *output)
{
  kumi::get<0>(input) *= 2.0f;
  kumi::get<1>(input) += 100;
  kumi::get<2>(input) = 's';
  *output = input;
}

TTS_CASE("Check kumi::tuple behavior on cuda device")
{
  struct_t h_input = {3.14f, 10, 'a'};
  struct_t h_output;

  struct_t* d_output;
  cudaMalloc(&d_output, sizeof(struct_t));

  kernel<<<1, 1>>>(h_input, d_output);

  cudaDeviceSynchronize();
  cudaMemcpy(&h_output, d_output, sizeof(struct_t), cudaMemcpyDeviceToHost);

  auto [f, i, l] = h_output;
  cudaFree(d_output);

  TTS_EQUAL(f, 6.28f);
  TTS_EQUAL(i, 110);
  TTS_EQUAL(l, 's');
};
