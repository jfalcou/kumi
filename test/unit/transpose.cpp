//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <vector>

TTS_CASE("Check result::transpose<Tuple> behavior")
{
  using tuple1_t = kumi::tuple<char,short,int>;
  using tuple2_t = kumi::tuple<long double, double, float>;
  using tuple_t  = kumi::tuple<tuple1_t, tuple2_t>;

  TTS_TYPE_IS ( (kumi::result::transpose_t<tuple_t>), ( kumi::tuple < kumi::tuple<char, long double>
                                                                    , kumi::tuple<short, double>
                                                                    , kumi::tuple<int, float>
                                                                    >
                                                      )
              );
};

TTS_CASE("Check tuple::transpose behavior")
{
  using kumi::tuple;

  auto numbers = tuple {1, 2, 3, 4};
  auto letters = tuple {'a', 'b', 'c', 'd'};
  auto ratio   = tuple {1.f, 0.1f, 0.01f, 0.001f};

  TTS_EQUAL(kumi::transpose(kumi::tuple{}),kumi::tuple{});

  TTS_EQUAL((kumi::transpose(tuple{ numbers, letters, ratio })),
            (tuple {tuple {1, 'a' , 1.f}, tuple {2, 'b',0.1f}, tuple {3, 'c',0.01f}, tuple {4, 'd',0.001f}}));
};

TTS_CASE("Check constexpr tuple::transpose behavior")
{
  using kumi::tuple;

  constexpr auto numbers = tuple {1, 2, 3, 4};
  constexpr auto letters = tuple {'a', 'b', 'c', 'd'};
  constexpr auto ratio   = tuple {1.f, 0.1f, 0.01f, 0.001f};

  TTS_CONSTEXPR_EQUAL((kumi::transpose(tuple{ numbers, letters, ratio })),
            (tuple {tuple {1, 'a' , 1.f}, tuple {2, 'b',0.1f}, tuple {3, 'c',0.01f}, tuple {4, 'd',0.001f}}));
};
