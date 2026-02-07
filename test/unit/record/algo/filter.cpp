
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
#include <type_traits>
#include "test.hpp"

using namespace kumi::literals;

TTS_CASE("Check result::filter_t<Func,record> behavior")
{
  TTS_TYPE_IS((kumi::result::filter_t<std::is_integral, kumi::record<>>), (kumi::record<>));

  TTS_TYPE_IS(
    (kumi::result::filter_t<std::is_integral,
                            kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, float>,
                                         kumi::field<kumi::name<"c">, double>>>),
    (kumi::record<kumi::field<kumi::name<"a">, int>>));

  TTS_TYPE_IS(
    (kumi::result::filter_t<std::is_rvalue_reference,
                            kumi::record<kumi::field<kumi::name<"a">, int&>, kumi::field<kumi::name<"b">, float&&>,
                                         kumi::field<kumi::name<"c">, double const&>>>),
    (kumi::record<kumi::field<kumi::name<"b">, float&&>>));
};

TTS_CASE("Check filter(kumi::record<>{}) behavior")
{
  TTS_EQUAL((kumi::filter<std::is_pointer>(kumi::record{})), (kumi::record<>{}));
};

TTS_CASE("Check filter() behavior with values")
{
  int a = 4;
  double b = 3.1415;
  float c = 0.01f;

  auto original =
    kumi::record{"a"_n = a, "b"_n = &a, "c"_n = b, "d"_n = &b, "e"_n = c, "f"_n = &c, "g"_n = 'z', "h"_n = nullptr};

  TTS_EQUAL(kumi::filter<std::is_pointer>(original), (kumi::record{"b"_n = &a, "d"_n = &b, "f"_n = &c}));

  TTS_EQUAL(kumi::filter<std::is_floating_point>(original), (kumi::record{"c"_n = b, "e"_n = c}));

  TTS_EQUAL(kumi::filter<std::is_null_pointer>(original), (kumi::record{"h"_n = nullptr}));

  auto t = kumi::record{"a"_n = 1.f, "b"_n = 2, "c"_n = 'x', "d"_n = moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::filter<is_moveonly_type>(std::move(t)); });
};

TTS_CASE("Check filter() behavior with reference")
{
  int a = 4;
  double b = 3.1415;

  auto original = kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, int&>,
                               kumi::field<kumi::name<"c">, double>, kumi::field<kumi::name<"d">, double&>>{a, a, b, b};

  TTS_EQUAL(kumi::filter<std::is_lvalue_reference>(original),
            (kumi::record<kumi::field<kumi::name<"b">, int&>, kumi::field<kumi::name<"d">, double&>>{a, b}));
};
