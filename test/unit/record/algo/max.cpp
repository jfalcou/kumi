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

  auto t0 = kumi::record{"a"_id = 'e', "b"_id = 2, "c"_id = 7894.5, "d"_id = short{55}, "e"_id = 'z'};
  TTS_EQUAL(kumi::max(t0), 7894.5);
  TTS_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  auto f0 =
    kumi::record{"a"_id = 'e', "b"_id = 2., "c"_id = kumi::record{"d"_id = 1., "e"_id = short{55}, "f"_id = 'u'},
                 "g"_id = 3.f, "h"_id = 'z'};
  TTS_EQUAL((kumi::max(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(double));
  TTS_EQUAL((kumi::max_flat(f0, [](auto m) { return sizeof(m); })), sizeof(double));

  auto t1 = kumi::record{"a"_id = 1.5, "b"_id = 3.6f, "c"_id = 8, "d"_id = -3.6, "e"_id = 2.4, "f"_id = 0};
  TTS_EQUAL((kumi::max(t1, [](auto m) { return (m - 5) < 0 ? (5 - m) : (m - 5); })), 8.6);
};

TTS_CASE("Check record::max/max_flat constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record{"a"_id = 'e', "b"_id = 2, "c"_id = 7894.5, "d"_id = short{55}, "e"_id = 'z'};
  TTS_CONSTEXPR_EQUAL(kumi::max(t0), 7894.5);
  TTS_CONSTEXPR_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  constexpr auto f0 =
    kumi::record{"a"_id = 'e', "b"_id = 2., "c"_id = kumi::record{"d"_id = 1., "e"_id = short{55}, "f"_id = 'u'},
                 "g"_id = 3.f, "h"_id = 'z'};
  TTS_CONSTEXPR_EQUAL((kumi::max(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(double));
  TTS_CONSTEXPR_EQUAL((kumi::max_flat(f0, [](auto m) { return sizeof(m); })), sizeof(double));

  constexpr auto t1 = kumi::record{"a"_id = 1.5, "b"_id = 3.6f, "c"_id = 8, "d"_id = -3.6, "e"_id = 2.4, "f"_id = 0};
  TTS_CONSTEXPR_EQUAL((kumi::max(t1, [](auto m) { return (m - 5) < 0 ? (5 - m) : (m - 5); })), 8.6);
};
