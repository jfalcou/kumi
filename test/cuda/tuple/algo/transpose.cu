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
  __global__ void rows_to_columns(char* flags)
  {
    auto t  = kumi::tuple{1., 'x', moveonly{}, short{55}};
    auto t2 = kumi::tuple{2., 'y', moveonly{}, short{66}};
    auto r  = kumi::transpose(kumi::tuple{std::move(t), std::move(t2)});

    flags[0] = (r.size() == 4);
    flags[1] = (kumi::get<0>(kumi::get<0>(r)) == 1.) && (kumi::get<1>(kumi::get<0>(r)) == 2.);
    flags[2] = (kumi::get<0>(kumi::get<3>(r)) == 55) && (kumi::get<1>(kumi::get<3>(r)) == 66);
  }
}

TTS_CASE("Check transpose device behavior")
{
  auto r = run_on_device(rows_to_columns, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
