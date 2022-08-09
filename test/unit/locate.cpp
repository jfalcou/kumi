//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <type_traits>

TTS_CASE("kumi locate runtime behavior")
{
  auto values = kumi::make_tuple(1, 2.5, -3.6f, 4ULL);

  TTS_EQUAL(kumi::locate(values, [](auto e) { return e < 0; })        , 2ULL);
  TTS_EQUAL(kumi::locate(values, kumi::predicate<std::is_unsigned>()) , 3ULL);
};

TTS_CASE("kumi locate constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL ( kumi::locate(kumi::make_tuple(1, 2.5, -3.6f, 4ULL)
                                    , [](auto e) { return e < 0; }
                                    )
                      , 2ULL
                      );

  TTS_CONSTEXPR_EQUAL ( kumi::locate(kumi::make_tuple(1, 2.5, -3.6f, 4ULL)
                                    , kumi::predicate<std::is_unsigned>()
                                    )
                      , 3ULL
                      );
};
