//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <vector>

TTS_CASE("Check result::max/max_flat<...> behavior")
{
  using namespace kumi::literals;

  auto lambda = [](auto m) { return sizeof(m); };
  using func_t = decltype(lambda);

  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using double_f = kumi::field<kumi::name<"c">, double>;
  using int_f = kumi::field<kumi::name<"d">, int>;

  TTS_TYPE_IS((kumi::result::max_t<kumi::record<char_f, short_f, double_f, int_f>>), double);

  TTS_TYPE_IS((kumi::result::max_t<kumi::record<char_f, short_f, int_f, double_f>, func_t>), std::size_t);

  TTS_TYPE_IS((kumi::result::max_flat_t<kumi::record<char_f, short_f, int_f, double_f>, func_t>), std::size_t);

  TTS_TYPE_IS((kumi::result::max_flat_t<
                kumi::record<char_f, kumi::field<kumi::name<"e">, kumi::record<short_f, int_f>>, double_f>, func_t>),
              std::size_t);
};

TTS_CASE("Check record::max/max_flat behavior")
{
  using namespace kumi::literals;

  auto t0 = kumi::record{"a"_n = 'e', "b"_n = 2, "c"_n = 7894.5, "d"_n = short{55}, "e"_n = 'z'};
  TTS_EQUAL(kumi::max(t0), 7894.5);
  TTS_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  auto f0 = kumi::record{"a"_n = 'e', "b"_n = 2., "c"_n = kumi::record{"d"_n = 1., "e"_n = short{55}, "f"_n = 'u'},
                         "g"_n = 3.f, "h"_n = 'z'};
  TTS_EQUAL((kumi::max(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(double));
  TTS_EQUAL((kumi::max_flat(f0, [](auto m) { return sizeof(m); })), sizeof(double));

  auto t1 = kumi::record{"a"_n = 1.5, "b"_n = 3.6f, "c"_n = 8, "d"_n = -3.6, "e"_n = 2.4, "f"_n = 0};
  TTS_EQUAL((kumi::max(t1, [](auto m) { return (m - 5) < 0 ? (5 - m) : (m - 5); })), 8.6);
};

TTS_CASE("Check record::max/max_flat constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record{"a"_n = 'e', "b"_n = 2, "c"_n = 7894.5, "d"_n = short{55}, "e"_n = 'z'};
  TTS_CONSTEXPR_EQUAL(kumi::max(t0), 7894.5);
  TTS_CONSTEXPR_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  constexpr auto f0 =
    kumi::record{"a"_n = 'e', "b"_n = 2., "c"_n = kumi::record{"d"_n = 1., "e"_n = short{55}, "f"_n = 'u'}, "g"_n = 3.f,
                 "h"_n = 'z'};
  TTS_CONSTEXPR_EQUAL((kumi::max(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(double));
  TTS_CONSTEXPR_EQUAL((kumi::max_flat(f0, [](auto m) { return sizeof(m); })), sizeof(double));

  constexpr auto t1 = kumi::record{"a"_n = 1.5, "b"_n = 3.6f, "c"_n = 8, "d"_n = -3.6, "e"_n = 2.4, "f"_n = 0};
  TTS_CONSTEXPR_EQUAL((kumi::max(t1, [](auto m) { return (m - 5) < 0 ? (5 - m) : (m - 5); })), 8.6);
};
