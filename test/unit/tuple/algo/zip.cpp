//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <vector>
#include "test.hpp"

TTS_CASE("Check result::zip/zip_min/zip_max<Tuple...> behavior")
{
  using tuple1_t = kumi::tuple<char, short, int>;
  using tuple2_t = kumi::tuple<long double, double, float>;
  using tuple3_t = kumi::tuple<void*, void**, void***>;

  TTS_TYPE_IS((kumi::result::zip_t<tuple1_t, tuple2_t, tuple3_t>),
              (kumi::tuple<kumi::tuple<char, long double, void*>, kumi::tuple<short, double, void**>,
                           kumi::tuple<int, float, void***>>));

  using one_element_t = kumi::tuple<int>;
  TTS_TYPE_IS((kumi::result::zip_t<one_element_t>), (kumi::tuple<kumi::tuple<int>>));
  TTS_TYPE_IS((kumi::result::zip_max_t<one_element_t>), (kumi::tuple<kumi::tuple<int>>));
  TTS_TYPE_IS((kumi::result::zip_min_t<one_element_t>), (kumi::tuple<kumi::tuple<int>>));

  using tuple4_t = kumi::tuple<char, short, int, long, long long>;
  using tuple5_t = kumi::tuple<void*, void**, void***>;

  TTS_TYPE_IS((kumi::result::zip_min_t<tuple4_t, tuple5_t>),
              (kumi::tuple<kumi::tuple<char, void*>, kumi::tuple<short, void**>, kumi::tuple<int, void***>>));

  TTS_TYPE_IS((kumi::result::zip_max_t<tuple4_t, tuple5_t>),
              (kumi::tuple<kumi::tuple<char, void*>, kumi::tuple<short, void**>, kumi::tuple<int, void***>,
                           kumi::tuple<long, kumi::unit>, kumi::tuple<long long, kumi::unit>>));
};

TTS_CASE("Check tuple::zip/zip_min/zip_max behavior")
{
  using kumi::tuple;

  auto numbers = tuple{1, 2, 3, 4};
  auto letters = tuple{'a', 'b', 'c', 'd'};
  auto ratio = tuple{1.f, 0.5f, 0.25, 0.01};
  auto uneven = tuple{1., 2., 3., 4., 5., 6.};

  TTS_EQUAL((kumi::zip(kumi::tuple{}, kumi::tuple{})), kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)), (tuple{tuple{1, 'a'}, tuple{2, 'b'}, tuple{3, 'c'}, tuple{4, 'd'}}));

  TTS_EQUAL((kumi::zip_min(numbers, uneven)), (tuple{tuple{1, 1.}, tuple{2, 2.}, tuple{3, 3.}, tuple{4, 4.}}));

  TTS_EQUAL((kumi::zip_max(numbers, uneven)), (tuple{tuple{1, 1.}, tuple{2, 2.}, tuple{3, 3.}, tuple{4, 4.},
                                                     tuple{kumi::none, 5.}, tuple{kumi::none, 6.}}));

  TTS_EQUAL((kumi::zip(numbers, letters, ratio)),
            (tuple{tuple{1, 'a', 1.f}, tuple{2, 'b', 0.5f}, tuple{3, 'c', 0.25}, tuple{4, 'd', 0.01}}));

  TTS_EQUAL((kumi::zip(std::move(numbers), std::move(letters), std::move(ratio))),
            (tuple{tuple{1, 'a', 1.f}, tuple{2, 'b', 0.5f}, tuple{3, 'c', 0.25}, tuple{4, 'd', 0.01}}));

  auto t = tuple{1, 2, 3};
  auto t2 = tuple{2.f, moveonly{}, 'x'};
  auto t3 = tuple{5.f, 'y', 3.5, moveonly{}, 50ULL};

  TTS_EXPECT_COMPILES(t, t2, { kumi::zip(t, std::move(t2)); });
  TTS_EXPECT_COMPILES(t, t3, { kumi::zip_min(t, std::move(t3)); });
  TTS_EXPECT_COMPILES(t, t3, { kumi::zip_max(t, std::move(t3)); });
};

TTS_CASE("Check tuple::zip/zip_min/zip_max constexpr behavior")
{
  using kumi::tuple;

  constexpr auto numbers = tuple{1, 2, 3, 4};
  constexpr auto letters = tuple{'a', 'b', 'c', 'd'};
  constexpr auto ratio = tuple{1.f, 0.5f, 0.25, 0.01};
  constexpr auto uneven = tuple{1., 2., 3., 4., 5., 6.};

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)),
                      (tuple{tuple{1, 'a'}, tuple{2, 'b'}, tuple{3, 'c'}, tuple{4, 'd'}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip_min(numbers, uneven)),
                      (tuple{tuple{1, 1.}, tuple{2, 2.}, tuple{3, 3.}, tuple{4, 4.}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip_max(numbers, uneven)), (tuple{tuple{1, 1.}, tuple{2, 2.}, tuple{3, 3.}, tuple{4, 4.},
                                                               tuple{kumi::none, 5.}, tuple{kumi::none, 6.}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters, ratio)),
                      (tuple{tuple{1, 'a', 1.f}, tuple{2, 'b', 0.5f}, tuple{3, 'c', 0.25}, tuple{4, 'd', 0.01}}));
};
