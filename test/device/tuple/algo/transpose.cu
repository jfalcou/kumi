//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/transpose.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using columns = kumi::tuple<double, double, short, short>;

  __global__ void rows_to_columns(columns* out)
  {
    auto t = kumi::tuple{1., 'x', 3, short{55}};
    auto t2 = kumi::tuple{2., 'y', 3, short{66}};
    auto r = kumi::transpose(kumi::tuple{t, t2});

    *out = {kumi::get<0>(kumi::get<0>(r)), kumi::get<1>(kumi::get<0>(r)), kumi::get<0>(kumi::get<3>(r)),
            kumi::get<1>(kumi::get<3>(r))};
  }

  // nvcc miscompiles a tuple carrying a move-only member, so the host fixture runs under clang only.
#if !defined(__NVCC__)
  __global__ void rows_to_columns_moveonly(columns* out)
  {
    auto t = kumi::tuple{1., 'x', moveonly{}, short{55}};
    auto t2 = kumi::tuple{2., 'y', moveonly{}, short{66}};
    auto r = kumi::transpose(kumi::tuple{std::move(t), std::move(t2)});

    *out = {kumi::get<0>(kumi::get<0>(r)), kumi::get<1>(kumi::get<0>(r)), kumi::get<0>(kumi::get<3>(r)),
            kumi::get<1>(kumi::get<3>(r))};
  }
#endif
}

TTS_CASE("Check transpose device behavior")
{
  columns out;

  TTS_EXPECT(run_on_device(rows_to_columns, out));
  TTS_EQUAL(out, (columns{1., 2., short{55}, short{66}}));
};

#if !defined(__NVCC__)
TTS_CASE("Check transpose device behavior on a moveonly element")
{
  columns out;

  TTS_EXPECT(run_on_device(rows_to_columns_moveonly, out));
  TTS_EQUAL(out, (columns{1., 2., short{55}, short{66}}));
};
#endif
