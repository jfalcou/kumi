//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/flatten.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::result::compress behavior on tuples")
{
  TTS_TYPE_IS((kumi::result::compress_t<kumi::tuple<>>), (kumi::tuple<>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::tuple<kumi::tuple<>>>), (kumi::tuple<>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::tuple<kumi::tuple<kumi::tuple<double, char, short>>>>),
              (kumi::tuple<double, char, short>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::tuple<char, short, int, double>>),
              (kumi::tuple<char, short, int, double>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::tuple<char, kumi::tuple<short, int, kumi::tuple<double>>>>),
              (kumi::tuple<char, kumi::tuple<short, int, kumi::tuple<double>>>));
};

TTS_CASE("Check kumi::compress behavior on tuples")
{
  TTS_EQUAL(kumi::compress(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL((kumi::compress(kumi::tuple{2., 1, short{55}})), (kumi::tuple{2., 1, short{55}}));
  TTS_EQUAL((kumi::compress(kumi::tuple{kumi::tuple{2., 1, short{55}}})), (kumi::tuple{2., 1, short{55}}));
  TTS_EQUAL((kumi::compress(kumi::tuple{kumi::tuple{kumi::tuple{2., 1, short{55}}}})), (kumi::tuple{2., 1, short{55}}));
  TTS_EQUAL((kumi::compress(kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'})),
            (kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'}));
  TTS_EQUAL((kumi::compress(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'})),
            (kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'}));

  auto t = kumi::tuple{1.f, 'x', short{66}, moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::compress(std::move(t)); });
};

TTS_CASE("Check kumi::compress constexpr behavior on tuples")
{
  constexpr auto t0 = kumi::tuple{2., 1, short{55}};
  constexpr auto t1 = kumi::tuple{kumi::tuple{2., 1, short{55}}};
  constexpr auto t2 = kumi::tuple{kumi::tuple{kumi::tuple{2., 1, short{55}}}};
  constexpr auto t3 = kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'};
  constexpr auto t4 = kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::compress(kumi::tuple{}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::compress(t0), (kumi::tuple{2., 1, short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::compress(t1), (kumi::tuple{2., 1, short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::compress(t2), (kumi::tuple{2., 1, short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::compress(t3), (t3));
  TTS_CONSTEXPR_EQUAL(kumi::compress(t4), (t4));
};
