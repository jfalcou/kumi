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
#include <functional>
#include "test.hpp"

/*
TTS_CASE("Check result::unique/all_unique<T> behavior on records")
{
  using namespace kumi;

  TTS_TYPE_IS((result::unique_t<record<char, int, int, char, double>>),
              (record<char, int, char, double>));

  TTS_TYPE_IS((result::unique_t<record<record<int, char>, record<int, char>, char, int>>),
              (record<record<int, char>, char, int>));

  TTS_TYPE_IS((kumi::result::unique_t<record<int&, int, int const, int const*, int&&>>),
              (record<int&, int, int const, int const*, int&&>));

  TTS_TYPE_IS((result::all_unique_t<record<char, int, int, char, double>>),
              (record<char, int, double>));

  TTS_TYPE_IS((result::all_unique_t<record<record<int, char>, record<int, char>, char, int>>),
              (record<record<int, char>, char, int>));

  TTS_TYPE_IS((result::all_unique_t<record<int&, int, int const, int const*, int&&>>),
              (record<int&, int, int const, int const*, int&&>));
};
*/

TTS_CASE("Check runtime kumi::unique behavior")
{
  using namespace kumi;
  auto r = record{"a"_id = 1,   "b"_id = 1,   "c"_id = 3.,  "d"_id = 3,
                  "e"_id = 'x', "f"_id = 'x', "g"_id = 12., "h"_id = short{55}};
  int a = 1;

  TTS_EQUAL(unique(record{}), record{});
  TTS_EQUAL(unique(record{"a"_id = 1}), (record{"a"_id = 1}));
  TTS_EQUAL(
    unique(record{"a"_id = 1, "b"_id = 2.f, "c"_id = 3.f, "d"_id = 3., "e"_id = 4, "f"_id = 'x', "g"_id = 'y',
                  "h"_id = 12., "i"_id = short{55}}),
    (record{"a"_id = 1, "b"_id = 2.f, "d"_id = 3., "e"_id = 4, "f"_id = 'x', "h"_id = 12., "i"_id = short{55}}));
  TTS_EQUAL(unique(std::move(r)),
            (record{"a"_id = 1, "c"_id = 3., "d"_id = 3, "e"_id = 'x', "g"_id = 12., "h"_id = short{55}}));

  auto t = record{"a"_id = moveonly{}, "b"_id = 1, "c"_id = std::ref(a)};
  TTS_EXPECT_COMPILES(t, { unique(std::move(t)); });
};

TTS_CASE("Check constexpr kumi::unique behavior")
{
  using namespace kumi;
  constexpr auto r = record{"a"_id = 1,   "b"_id = 1,   "c"_id = 3.,  "d"_id = 3,
                            "e"_id = 'x', "f"_id = 'x', "g"_id = 12., "h"_id = short{55}};

  TTS_CONSTEXPR_EQUAL(unique(record{}), record{});
  TTS_CONSTEXPR_EQUAL(unique(record{"a"_id = 1}), (record{"a"_id = 1}));
  TTS_CONSTEXPR_EQUAL(
    unique(record{"a"_id = 1, "b"_id = 2.f, "c"_id = 3.f, "d"_id = 3., "e"_id = 4, "f"_id = 'x', "g"_id = 'y',
                  "h"_id = 12., "i"_id = short{55}}),
    (record{"a"_id = 1, "b"_id = 2.f, "d"_id = 3., "e"_id = 4, "f"_id = 'x', "h"_id = 12., "i"_id = short{55}}));
  TTS_CONSTEXPR_EQUAL(unique(std::move(r)),
                      (record{"a"_id = 1, "c"_id = 3., "d"_id = 3, "e"_id = 'x', "g"_id = 12., "h"_id = short{55}}));
};

TTS_CASE("Check runtime kumi::all_unique behavior")
{
  using namespace kumi;
  auto r = record{"a"_id = 1,   "b"_id = 1,   "c"_id = 3.,  "d"_id = 3,
                  "e"_id = 'x', "f"_id = 'x', "g"_id = 12., "h"_id = short{55}};
  int a = 1;

  TTS_EQUAL(all_unique(record{}), record{});
  TTS_EQUAL(all_unique(record{"a"_id = 1}), (record{"a"_id = 1}));
  TTS_EQUAL(all_unique(record{"a"_id = 1, "b"_id = 2.f, "c"_id = 3.f, "d"_id = 3., "e"_id = 4, "f"_id = 'x',
                              "g"_id = 'y', "h"_id = 12., "i"_id = short{55}}),
            (record{"a"_id = 1, "b"_id = 2.f, "d"_id = 3., "f"_id = 'x', "i"_id = short{55}}));
  TTS_EQUAL(all_unique(std::move(r)), (record{"a"_id = 1, "c"_id = 3., "e"_id = 'x', "h"_id = short{55}}));

  auto t = record{"a"_id = moveonly{}, "b"_id = 1, "c"_id = std::ref(a)};
  TTS_EXPECT_COMPILES(t, { all_unique(std::move(t)); });
};

TTS_CASE("Check constexpr kumi::all_unique behavior")
{
  constexpr auto r = kumi::tuple{1, 1, 3., 3, 'x', 'x', 12., short{55}};
  TTS_CONSTEXPR_EQUAL(kumi::all_unique(kumi::tuple{}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::all_unique(kumi::tuple{1}), (kumi::tuple{1}));
  TTS_CONSTEXPR_EQUAL(kumi::all_unique(kumi::tuple{1, 2.f, 3.f, 3., 4, 'x', 'y', 12., short{55}}),
                      (kumi::tuple{1, 2.f, 3., 'x', short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::all_unique(std::move(r)), (kumi::tuple{1, 3., 'x', short{55}}));
};
