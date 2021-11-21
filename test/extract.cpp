//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple::extract behavior")
{
  using namespace kumi::literals;

  kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_EQUAL((t.extract(0_c))      , (kumi::tuple{'1', 2., 3.f, 4})  );
  TTS_EQUAL((t.extract(0_c, 4_c)) , (kumi::tuple{'1', 2., 3.f, 4})  );
  TTS_EQUAL((t.extract(0_c, 3_c)) , (kumi::tuple {'1', 2., 3.f})    );
  TTS_EQUAL((t.extract(0_c, 2_c)) , (kumi::tuple {'1', 2.})         );
  TTS_EQUAL((t.extract(0_c, 1_c)) , kumi::tuple {'1'}               );
  TTS_EQUAL((t.extract(0_c, 0_c)) , kumi::tuple {}                  );
  TTS_EQUAL((t.extract(1_c))      , (kumi::tuple {2., 3.f, 4})      );
  TTS_EQUAL((t.extract(1_c, 4_c)) , (kumi::tuple {2., 3.f, 4})      );
  TTS_EQUAL((t.extract(1_c, 3_c)) , (kumi::tuple {2., 3.f})         );
  TTS_EQUAL((t.extract(1_c, 2_c)) , kumi::tuple {2.}                );
  TTS_EQUAL((t.extract(1_c, 1_c)) , kumi::tuple {}                  );
  TTS_EQUAL((t.extract(2_c))      , (kumi::tuple {3.f, 4})          );
  TTS_EQUAL((t.extract(2_c, 4_c)) , (kumi::tuple {3.f, 4})          );
  TTS_EQUAL((t.extract(2_c, 3_c)) , (kumi::tuple {3.f})             );
  TTS_EQUAL((t.extract(2_c, 2_c)) , kumi::tuple {}                  );
  TTS_EQUAL((t.extract(3_c))      , kumi::tuple {4}                 );
  TTS_EQUAL((t.extract(3_c, 4_c)) , kumi::tuple {4}                 );
  TTS_EQUAL((t.extract(3_c, 3_c)) , kumi::tuple {}                  );
  TTS_EQUAL((t.extract(4_c))      , kumi::tuple {}                  );
  TTS_EQUAL((t.extract(4_c, 4_c)) , kumi::tuple {}                  );
};

TTS_CASE("Check tuple::extract constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EQUAL( t.extract(0_c)       , t                               );
  TTS_CONSTEXPR_EQUAL((t.extract(0_c, 4_c)) , t                               );
  TTS_CONSTEXPR_EQUAL((t.extract(0_c, 3_c)) , (kumi::tuple {'1', 2., 3.f})    );
  TTS_CONSTEXPR_EQUAL((t.extract(0_c, 2_c)) , (kumi::tuple {'1', 2.})         );
  TTS_CONSTEXPR_EQUAL((t.extract(0_c, 1_c)) , kumi::tuple {'1'}               );
  TTS_CONSTEXPR_EQUAL((t.extract(0_c, 0_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((t.extract(1_c))      , (kumi::tuple {2., 3.f, 4})      );
  TTS_CONSTEXPR_EQUAL((t.extract(1_c, 4_c)) , (kumi::tuple {2., 3.f, 4})      );
  TTS_CONSTEXPR_EQUAL((t.extract(1_c, 3_c)) , (kumi::tuple {2., 3.f})         );
  TTS_CONSTEXPR_EQUAL((t.extract(1_c, 2_c)) , kumi::tuple {2.}                );
  TTS_CONSTEXPR_EQUAL((t.extract(1_c, 1_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((t.extract(2_c))      , (kumi::tuple {3.f, 4})          );
  TTS_CONSTEXPR_EQUAL((t.extract(2_c, 4_c)) , (kumi::tuple {3.f, 4})          );
  TTS_CONSTEXPR_EQUAL((t.extract(2_c, 3_c)) , (kumi::tuple {3.f})             );
  TTS_CONSTEXPR_EQUAL((t.extract(2_c, 2_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((t.extract(3_c))      , kumi::tuple {4}                 );
  TTS_CONSTEXPR_EQUAL((t.extract(3_c, 4_c)) , kumi::tuple {4}                 );
  TTS_CONSTEXPR_EQUAL((t.extract(3_c, 3_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((t.extract(4_c))      , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((t.extract(4_c, 4_c)) , kumi::tuple {}                  );
};
