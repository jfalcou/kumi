//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <type_traits>

TTS_CASE("kumi locate runtime behavior")
{
  using namespace kumi::literals;

  auto values = kumi::make_record("a"_f = 1, "b"_f = 2.5, "c"_f = -3.6f, "d"_f = 4ULL);

  TTS_EQUAL(kumi::locate(values, [](auto e) { return e < 0; }), 2ULL);
  TTS_EQUAL(kumi::locate(values, kumi::predicate<std::is_unsigned>()), 3ULL);
};

TTS_CASE("kumi locate constexpr behavior")
{
  using namespace kumi::literals;

  TTS_CONSTEXPR_EQUAL(
    kumi::locate(kumi::make_record("a"_f = 1, "b"_f = 2.5, "c"_f = -3.6f, "d"_f = 4ULL), [](auto e) { return e < 0; }),
    2ULL);

  TTS_CONSTEXPR_EQUAL(kumi::locate(kumi::make_record("a"_f = 1, "b"_f = 2.5, "c"_f = -3.6f, "d"_f = 4ULL),
                                   kumi::predicate<std::is_unsigned>()),
                      3ULL);
};
