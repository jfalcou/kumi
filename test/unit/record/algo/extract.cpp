//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check record::extract behavior")
{
  using namespace kumi::literals;

  kumi::record t = {"a"_f = '1', "b"_f = 2., "c"_f = 3.f, "d"_f = 4};

  TTS_EQUAL((kumi::extract(t, 0_c)), (kumi::record{"a"_f = '1', "b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 0_c, 4_c)), (kumi::record{"a"_f = '1', "b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 0_c, 3_c)), (kumi::record{"a"_f = '1', "b"_f = 2., "c"_f = 3.f}));
  TTS_EQUAL((kumi::extract(t, 0_c, 2_c)), (kumi::record{"a"_f = '1', "b"_f = 2.}));
  TTS_EQUAL((kumi::extract(t, 0_c, 1_c)), kumi::record{"a"_f = '1'});
  TTS_EQUAL((kumi::extract(t, 0_c, 0_c)), kumi::record{});
  TTS_EQUAL((kumi::extract(t, 1_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 1_c, 4_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 1_c, 3_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f}));
  TTS_EQUAL((kumi::extract(t, 1_c, 2_c)), kumi::record{"b"_f = 2.});
  TTS_EQUAL((kumi::extract(t, 1_c, 1_c)), kumi::record{});
  TTS_EQUAL((kumi::extract(t, 2_c)), (kumi::record{"c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 2_c, 4_c)), (kumi::record{"c"_f = 3.f, "d"_f = 4}));
  TTS_EQUAL((kumi::extract(t, 2_c, 3_c)), (kumi::record{"c"_f = 3.f}));
  TTS_EQUAL((kumi::extract(t, 2_c, 2_c)), kumi::record{});
  TTS_EQUAL((kumi::extract(t, 3_c)), kumi::record{"d"_f = 4});
  TTS_EQUAL((kumi::extract(t, 3_c, 4_c)), kumi::record{"d"_f = 4});
  TTS_EQUAL((kumi::extract(t, 3_c, 3_c)), kumi::record{});
  TTS_EQUAL((kumi::extract(t, 4_c)), kumi::record{});
  TTS_EQUAL((kumi::extract(t, 4_c, 4_c)), kumi::record{});
};

TTS_CASE("Check record::extract constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::record t = {"a"_f = '1', "b"_f = 2., "c"_f = 3.f, "d"_f = 4};

  TTS_CONSTEXPR_EQUAL(kumi::extract(t, 0_c), t);
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 0_c, 4_c)), t);
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 0_c, 3_c)), (kumi::record{"a"_f = '1', "b"_f = 2., "c"_f = 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 0_c, 2_c)), (kumi::record{"a"_f = '1', "b"_f = 2.}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 0_c, 1_c)), kumi::record{"a"_f = '1'});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 0_c, 0_c)), kumi::record{});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 1_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 1_c, 4_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f, "d"_f = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 1_c, 3_c)), (kumi::record{"b"_f = 2., "c"_f = 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 1_c, 2_c)), kumi::record{"b"_f = 2.});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 1_c, 1_c)), kumi::record{});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 2_c)), (kumi::record{"c"_f = 3.f, "d"_f = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 2_c, 4_c)), (kumi::record{"c"_f = 3.f, "d"_f = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 2_c, 3_c)), (kumi::record{"c"_f = 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 2_c, 2_c)), kumi::record{});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 3_c)), kumi::record{"d"_f = 4});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 3_c, 4_c)), kumi::record{"d"_f = 4});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 3_c, 3_c)), kumi::record{});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 4_c)), kumi::record{});
  TTS_CONSTEXPR_EQUAL((kumi::extract(t, 4_c, 4_c)), kumi::record{});
};
