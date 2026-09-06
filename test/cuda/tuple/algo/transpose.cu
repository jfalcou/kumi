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
#include "test.hpp"

namespace
{
  // The transposed tuple carries a moveonly, so the kernel reports the elements it can copy back.
  __global__ void rows_to_columns(kumi::tuple<double, double, short, short>* out)
  {
    auto t = kumi::tuple{1., 'x', moveonly{}, short{55}};
    auto t2 = kumi::tuple{2., 'y', moveonly{}, short{66}};
    auto r = kumi::transpose(kumi::tuple{std::move(t), std::move(t2)});

    *out = {kumi::get<0>(kumi::get<0>(r)), kumi::get<1>(kumi::get<0>(r)), kumi::get<0>(kumi::get<3>(r)),
            kumi::get<1>(kumi::get<3>(r))};
  }
}

TTS_CASE("Check transpose device behavior")
{
  kumi::tuple<double, double, short, short> out;

  TTS_EXPECT(run_on_device(rows_to_columns, out));
  TTS_EQUAL(out, (kumi::tuple{1., 2., short{55}, short{66}}));
};
