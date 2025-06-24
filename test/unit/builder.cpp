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

#include<kumi/detail/builder.hpp>
#include <array>

TTS_CASE("Check _::builder<Tuple...> behavior")
{
    TTS_EQUAL((kumi::_::builder<kumi::tuple<int, float>>::is_primary), false);
    TTS_EQUAL((kumi::_::builder<int>::is_primary), true);
    TTS_EQUAL((kumi::_::builder<std::array<int, 30>>::is_primary), true);
};
