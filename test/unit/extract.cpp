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

TTS_CASE("Check tuple::extract behavior")
{
  using namespace kumi::literals;

  kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_EQUAL((kumi::extract(t,0_c))      , (kumi::tuple{'1', 2., 3.f, 4})  );
  TTS_EQUAL((kumi::extract(t,0_c, 4_c)) , (kumi::tuple{'1', 2., 3.f, 4})  );
  TTS_EQUAL((kumi::extract(t,0_c, 3_c)) , (kumi::tuple {'1', 2., 3.f})    );
  TTS_EQUAL((kumi::extract(t,0_c, 2_c)) , (kumi::tuple {'1', 2.})         );
  TTS_EQUAL((kumi::extract(t,0_c, 1_c)) , kumi::tuple {'1'}               );
  TTS_EQUAL((kumi::extract(t,0_c, 0_c)) , kumi::tuple {}                  );
  TTS_EQUAL((kumi::extract(t,1_c))      , (kumi::tuple {2., 3.f, 4})      );
  TTS_EQUAL((kumi::extract(t,1_c, 4_c)) , (kumi::tuple {2., 3.f, 4})      );
  TTS_EQUAL((kumi::extract(t,1_c, 3_c)) , (kumi::tuple {2., 3.f})         );
  TTS_EQUAL((kumi::extract(t,1_c, 2_c)) , kumi::tuple {2.}                );
  TTS_EQUAL((kumi::extract(t,1_c, 1_c)) , kumi::tuple {}                  );
  TTS_EQUAL((kumi::extract(t,2_c))      , (kumi::tuple {3.f, 4})          );
  TTS_EQUAL((kumi::extract(t,2_c, 4_c)) , (kumi::tuple {3.f, 4})          );
  TTS_EQUAL((kumi::extract(t,2_c, 3_c)) , (kumi::tuple {3.f})             );
  TTS_EQUAL((kumi::extract(t,2_c, 2_c)) , kumi::tuple {}                  );
  TTS_EQUAL((kumi::extract(t,3_c))      , kumi::tuple {4}                 );
  TTS_EQUAL((kumi::extract(t,3_c, 4_c)) , kumi::tuple {4}                 );
  TTS_EQUAL((kumi::extract(t,3_c, 3_c)) , kumi::tuple {}                  );
  TTS_EQUAL((kumi::extract(t,4_c))      , kumi::tuple {}                  );
  TTS_EQUAL((kumi::extract(t,4_c, 4_c)) , kumi::tuple {}                  );

  TTS_EQUAL((kumi::extract(std::move(t), 0_c)), (kumi::tuple{'1', 2., 3.f, 4}));
};

TTS_CASE("Check tuple::extract constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EQUAL( kumi::extract(t,0_c)       , t                               );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,0_c, 4_c)) , t                               );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,0_c, 3_c)) , (kumi::tuple {'1', 2., 3.f})    );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,0_c, 2_c)) , (kumi::tuple {'1', 2.})         );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,0_c, 1_c)) , kumi::tuple {'1'}               );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,0_c, 0_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,1_c))      , (kumi::tuple {2., 3.f, 4})      );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,1_c, 4_c)) , (kumi::tuple {2., 3.f, 4})      );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,1_c, 3_c)) , (kumi::tuple {2., 3.f})         );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,1_c, 2_c)) , kumi::tuple {2.}                );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,1_c, 1_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,2_c))      , (kumi::tuple {3.f, 4})          );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,2_c, 4_c)) , (kumi::tuple {3.f, 4})          );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,2_c, 3_c)) , (kumi::tuple {3.f})             );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,2_c, 2_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,3_c))      , kumi::tuple {4}                 );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,3_c, 4_c)) , kumi::tuple {4}                 );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,3_c, 3_c)) , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,4_c))      , kumi::tuple {}                  );
  TTS_CONSTEXPR_EQUAL((kumi::extract(t,4_c, 4_c)) , kumi::tuple {}                  );
};
