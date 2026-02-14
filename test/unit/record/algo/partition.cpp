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

TTS_CASE("Check result::partition<Func,record> behavior")
{
  TTS_TYPE_IS((kumi::result::partition_t<std::is_integral, kumi::record<>>),
              (kumi::tuple<kumi::record<>, kumi::record<>>));

  TTS_TYPE_IS(
    (kumi::result::partition_t<std::is_integral,
                               kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, float>,
                                            kumi::field<kumi::name<"c">, double>>>),
    (kumi::tuple<kumi::record<kumi::field<kumi::name<"a">, int>>,
                 kumi::record<kumi::field<kumi::name<"b">, float>, kumi::field<kumi::name<"c">, double>>>));

  TTS_TYPE_IS(
    (kumi::result::partition_t<std::is_rvalue_reference,
                               kumi::record<kumi::field<kumi::name<"a">, int&>, kumi::field<kumi::name<"b">, float&&>,
                                            kumi::field<kumi::name<"c">, double const&>>>),
    (kumi::tuple<kumi::record<kumi::field<kumi::name<"b">, float&&>>,
                 kumi::record<kumi::field<kumi::name<"a">, int&>, kumi::field<kumi::name<"c">, double const&>>>));
};

TTS_CASE("Check partition(kumi::record<>{}) behavior")
{
  TTS_EQUAL((kumi::partition<std::is_pointer>(kumi::record{})), (kumi::tuple<kumi::record<>, kumi::record<>>{}));
};

TTS_CASE("Check partition() behavior with values")
{
  using namespace kumi::literals;

  int a = 4;
  double b = 3.1415;
  float c = 0.01f;

  auto original = kumi::record{"a"_id = a, "b"_id = &a, "c"_id = b,   "d"_id = &b,
                               "e"_id = c, "f"_id = &c, "g"_id = 'z', "h"_id = nullptr};

  TTS_EQUAL(kumi::partition<std::is_pointer>(original),
            (kumi::tuple{kumi::record{"b"_id = &a, "d"_id = &b, "f"_id = &c},
                         kumi::record{"a"_id = a, "c"_id = b, "e"_id = c, "g"_id = 'z', "h"_id = nullptr}}));

  TTS_EQUAL(
    kumi::partition<std::is_floating_point>(original),
    (kumi::tuple{kumi::record{"c"_id = b, "e"_id = c},
                 kumi::record{"a"_id = a, "b"_id = &a, "d"_id = &b, "f"_id = &c, "g"_id = 'z', "h"_id = nullptr}}));

  TTS_EQUAL(kumi::partition<std::is_null_pointer>(original),
            (kumi::tuple{kumi::record{"h"_id = nullptr}, kumi::record{
                                                           "a"_id = a,
                                                           "b"_id = &a,
                                                           "c"_id = b,
                                                           "d"_id = &b,
                                                           "e"_id = c,
                                                           "f"_id = &c,
                                                           "g"_id = 'z',
                                                         }}));
};

TTS_CASE("Check partition() behavior with reference")
{
  using namespace kumi::literals;

  int a = 4;
  double b = 3.1415;

  auto original = kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, int&>,
                               kumi::field<kumi::name<"c">, double>, kumi::field<kumi::name<"d">, double&>>{a, a, b, b};

  TTS_EQUAL(kumi::partition<std::is_lvalue_reference>(original),
            (kumi::tuple{kumi::record<kumi::field<kumi::name<"b">, int&>, kumi::field<kumi::name<"d">, double&>>{a, b},
                         kumi::record{"a"_id = a, "c"_id = b}}));
};
