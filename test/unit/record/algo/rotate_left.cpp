//==================================================================================================
/*
  KUMI - Compact record Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::rotate_left<R,record> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  using record_t = kumi::record<char_f, short_f, int_f, double_f>;

  TTS_TYPE_IS((kumi::result::rotate_left_t<0, record_t>), record_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, record_t>), (kumi::record<short_f, int_f, double_f, char_f>));
  TTS_TYPE_IS((kumi::result::rotate_left_t<2, record_t>), (kumi::record<int_f, double_f, char_f, short_f>));
  TTS_TYPE_IS((kumi::result::rotate_left_t<kumi::size_v<record_t>, record_t>), record_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, kumi::record<>>), kumi::record<>);

  using nested_t = kumi::record<kumi::field<kumi::name<"a">, kumi::record<int_f, double_f>>, int_f>;
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, nested_t>),
              (kumi::record<int_f, kumi::field<kumi::name<"a">, kumi::record<int_f, double_f>>>));
};

TTS_CASE("Check rotate_left<I...>(record) behavior")
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

  {
    auto s = kumi::rotate_left<0>(t);
    TTS_EQUAL(s, t);
  }
  {
    auto s = kumi::rotate_left<1>(t);
    TTS_EQUAL(s, (kumi::record{"b"_n = 2., "c"_n = 3.4f, "d"_n = '5', "a"_n = 1}));
  }

  {
    auto s = kumi::rotate_left<2>(t);
    TTS_EQUAL(s, (kumi::record{"c"_n = 3.4f, "d"_n = '5', "a"_n = 1, "b"_n = 2.}));
  }

  {
    auto s = kumi::rotate_left<3>(t);
    TTS_EQUAL(s, (kumi::record{"d"_n = '5', "a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
  }

  {
    auto s = kumi::rotate_left<4>(t);
    TTS_EQUAL(s, t);
  }
};

TTS_CASE("Check rotate_left<I...>(record) behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

  {
    constexpr auto s = kumi::rotate_left<0>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
  {
    constexpr auto s = kumi::rotate_left<1>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::record{"b"_n = 2., "c"_n = 3.4f, "d"_n = '5', "a"_n = 1}));
  }

  {
    constexpr auto s = kumi::rotate_left<2>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::record{"c"_n = 3.4f, "d"_n = '5', "a"_n = 1, "b"_n = 2.}));
  }

  {
    constexpr auto s = kumi::rotate_left<3>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_n = '5', "a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
  }

  {
    constexpr auto s = kumi::rotate_left<4>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
};
