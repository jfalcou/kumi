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

TTS_CASE("Check result::min/min_flat<...> behavior")
{
  using namespace kumi::literals;

  using char_f = kumi::field_capture<"a", char>;
  using short_f = kumi::field_capture<"b", short>;
  using int_f = kumi::field_capture<"c", int>;
  using double_f = kumi::field_capture<"d", double>;

  auto lambda = [](auto m) { return sizeof(m); };
  using func_t = decltype(lambda);

  TTS_TYPE_IS((kumi::result::min_t<kumi::record<char_f, short_f, int_f, double_f>>), double);

  TTS_TYPE_IS((kumi::result::min_t<kumi::record<char_f, short_f, int_f, double_f>, func_t>), std::size_t);

  TTS_TYPE_IS((kumi::result::min_flat_t<kumi::record<char_f, short_f, int_f, double_f>, func_t>), std::size_t);

  TTS_TYPE_IS(
    (kumi::result::min_flat_t<kumi::record<char_f, kumi::field_capture<"e", kumi::record<short_f, int_f>>, double_f>,
                              func_t>),
    std::size_t);
};

TTS_CASE("Check record::min/min_flat behavior")
{
  using namespace kumi::literals;

  auto t0 = kumi::record{"a"_f = 'e', "b"_f = 2, "c"_f = 1., "d"_f = short{55}, "e"_f = 'z'};
  TTS_EQUAL(kumi::min(t0), 1.);
  TTS_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(char));

  auto f0 = kumi::record{"a"_f = 2., "b"_f = 1., "c"_f = kumi::record{"d"_f = 'u', "e"_f = 'z'}, "f"_f = 3.f};
  TTS_EQUAL((kumi::min(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(char));
  TTS_EQUAL((kumi::min_flat(f0, [](auto m) { return sizeof(m); })), sizeof(char));

  auto t1 = kumi::record{"a"_f = 1.5, "b"_f = 3.6f, "c"_f = 8, "d"_f = -3.6, "e"_f = 2.4, "f"_f = -0.5};
  TTS_EQUAL((kumi::min(t1, [](auto m) { return m < 0 ? -m : m; })), 0.5);
};

TTS_CASE("Check record::min/min_flat constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record{"a"_f = 'e', "b"_f = 2, "c"_f = 1., "d"_f = short{55}, "e"_f = 'z'};
  TTS_CONSTEXPR_EQUAL(kumi::min(t0), 1.);
  TTS_CONSTEXPR_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(char));

  constexpr auto f0 = kumi::record{"a"_f = 2., "b"_f = 1., "c"_f = kumi::record{"d"_f = 'u', "e"_f = 'z'}, "f"_f = 3.f};
  TTS_CONSTEXPR_EQUAL((kumi::min(f0, [](auto m) { return sizeof(m); })), 2 * sizeof(char));
  TTS_CONSTEXPR_EQUAL((kumi::min_flat(f0, [](auto m) { return sizeof(m); })), sizeof(char));

  constexpr auto t1 = kumi::record{"a"_f = 1.5, "b"_f = 3.6f, "c"_f = 8, "d"_f = -3.6, "e"_f = 2.4, "f"_f = -0.5};
  TTS_CONSTEXPR_EQUAL((kumi::min(t1, [](auto m) { return m < 0 ? -m : m; })), 0.5);
};
