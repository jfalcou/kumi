//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <vector>
#include "test.hpp"

TTS_CASE("Check result::zip<Tuple...> behavior")
{
  using tuple1_t = kumi::tuple<char,short,int>;
  using tuple2_t = kumi::tuple<long double, double, float>;
  using tuple3_t = kumi::tuple<void*,void**,void***>;

  TTS_TYPE_IS ( (kumi::result::zip_t<tuple1_t, tuple2_t,tuple3_t>)
              , ( kumi::tuple < kumi::tuple<char, long double,void*>
                              , kumi::tuple<short, double,void**>
                              , kumi::tuple<int, float,void***>
                              >
                )
              );

  using one_element_t = kumi::tuple<int>;
  TTS_TYPE_IS((kumi::result::zip_t<one_element_t>), (kumi::tuple<kumi::tuple<int>>));
};

TTS_CASE("Check tuple::zip behavior")
{
  using kumi::tuple;

  auto numbers = tuple {1, 2, 3, 4};
  auto letters = tuple {'a', 'b', 'c', 'd'};
  auto ratio   = tuple {1.f, 0.5f, 0.25, 0.01};

  TTS_EQUAL((kumi::zip(kumi::tuple{},kumi::tuple{})),kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)),
            (tuple {tuple {1, 'a'}, tuple {2, 'b'}, tuple {3, 'c'}, tuple {4, 'd'}}));

  TTS_EQUAL(
      (kumi::zip(numbers, letters, ratio)),
      (tuple {
          tuple {1, 'a', 1.f}, tuple {2, 'b', 0.5f}, tuple {3, 'c', 0.25}, tuple {4, 'd', 0.01}}));

  TTS_EQUAL(
      (kumi::zip(std::move(numbers), std::move(letters), std::move(ratio))),
      (tuple {
          tuple {1, 'a', 1.f}, tuple {2, 'b', 0.5f}, tuple {3, 'c', 0.25}, tuple {4, 'd', 0.01}}));

  auto t    = tuple{1, 2, 3};
  auto t2   = tuple{2.f, moveonly{}, 'x'};
  auto t3   = kumi::make_tuple(t, std::move(t2));
  TTS_EXPECT_COMPILES(t3, { kumi::zip(get<0>(t3), std::move(get<1>(t3))); });
};

TTS_CASE("Check tuple::zip constexpr behavior")
{
  using kumi::tuple;

  constexpr auto numbers = tuple {1, 2, 3, 4};
  constexpr auto letters = tuple {'a', 'b', 'c', 'd'};
  constexpr auto ratio   = tuple {1.f, 0.5f, 0.25, 0.01};

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)),
                      (tuple {tuple {1, 'a'}, tuple {2, 'b'}, tuple {3, 'c'}, tuple {4, 'd'}}));

  TTS_CONSTEXPR_EQUAL(
      (kumi::zip(numbers, letters, ratio)),
      (tuple {
          tuple {1, 'a', 1.f}, tuple {2, 'b', 0.5f}, tuple {3, 'c', 0.25}, tuple {4, 'd', 0.01}}));
};
