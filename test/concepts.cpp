//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <concepts>

struct no_cmp { };
struct cmp    { constexpr auto operator<=>(cmp const&) const = default; };

TTS_CASE("Check equality_comparable for tuple")
{
  TTS_CONSTEXPR_EXPECT(   !std::equality_comparable<kumi::tuple<no_cmp>>      );
  TTS_CONSTEXPR_EXPECT( ( !std::equality_comparable<kumi::tuple<cmp,no_cmp>>) );

  TTS_CONSTEXPR_EXPECT(  std::equality_comparable<kumi::tuple<cmp>>                   );
  TTS_CONSTEXPR_EXPECT( (std::equality_comparable<kumi::tuple<cmp,kumi::tuple<cmp>>>) );
};
