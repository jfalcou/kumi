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

  TTS_WHEN("Given a tuple of size 4")
  {
    kumi::tuple t = {'1', 2., 3.f, 4};

    TTS_AND_THEN("We extract [0-...]")
    {
      auto sub = t.extract(0_c);
      TTS_EQUAL(sub, t);
    }

    TTS_AND_THEN("We extract [0-4[")
    {
      auto sub = t.extract(0_c, 4_c);
      TTS_EQUAL(sub, t);
    }

    TTS_AND_THEN("We extract [0-3[")
    {
      auto sub = t.extract(0_c, 3_c);
      TTS_EQUAL(sub, (kumi::tuple {'1', 2., 3.f}));
    }

    TTS_AND_THEN("We extract [0-2[")
    {
      auto sub = t.extract(0_c, 2_c);
      TTS_EQUAL(sub, (kumi::tuple {'1', 2.}));
    }

    TTS_AND_THEN("We extract [0-1[")
    {
      auto sub = t.extract(0_c, 1_c);
      TTS_EQUAL(sub, kumi::tuple {'1'});
    }

    TTS_AND_THEN("We extract [0-0[")
    {
      auto sub = t.extract(0_c, 0_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [1,...[")
    {
      auto sub = t.extract(1_c);
      TTS_EQUAL(sub, (kumi::tuple {2., 3.f, 4}));
    }

    TTS_AND_THEN("We extract [1,4[")
    {
      auto sub = t.extract(1_c, 4_c);
      TTS_EQUAL(sub, (kumi::tuple {2., 3.f, 4}));
    }

    TTS_AND_THEN("We extract [1,3[")
    {
      auto sub = t.extract(1_c, 3_c);
      TTS_EQUAL(sub, (kumi::tuple {2., 3.f}));
    }

    TTS_AND_THEN("We extract [1,2[")
    {
      auto sub = t.extract(1_c, 2_c);
      TTS_EQUAL(sub, kumi::tuple {2.});
    }

    TTS_AND_THEN("We extract [1,1[")
    {
      auto sub = t.extract(1_c, 1_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [2,...[")
    {
      auto sub = t.extract(2_c);
      TTS_EQUAL(sub, (kumi::tuple {3.f, 4}));
    }

    TTS_AND_THEN("We extract [2,4[")
    {
      auto sub = t.extract(2_c, 4_c);
      TTS_EQUAL(sub, (kumi::tuple {3.f, 4}));
    }

    TTS_AND_THEN("We extract [2,3[")
    {
      auto sub = t.extract(2_c, 3_c);
      TTS_EQUAL(sub, (kumi::tuple {3.f}));
    }

    TTS_AND_THEN("We extract [2,2[")
    {
      auto sub = t.extract(2_c, 2_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [3,...[")
    {
      auto sub = t.extract(3_c);
      TTS_EQUAL(sub, kumi::tuple {4});
    }

    TTS_AND_THEN("We extract [3,4[")
    {
      auto sub = t.extract(3_c, 4_c);
      TTS_EQUAL(sub, kumi::tuple {4});
    }

    TTS_AND_THEN("We extract [3,3[")
    {
      auto sub = t.extract(3_c, 3_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [4,...[")
    {
      auto sub = t.extract(4_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [4,4[")
    {
      auto sub = t.extract(4_c, 4_c);
      TTS_EQUAL(sub, kumi::tuple {});
    }
  }
};

TTS_CASE("Check tuple::extract constexpr behavior")
{
  using namespace kumi::literals;

  TTS_WHEN("Given a tuple of size 4")
  {
    constexpr kumi::tuple t = {'1', 2., 3.f, 4};

    TTS_AND_THEN("We extract [0-...]")
    {
      constexpr auto sub = t.extract(0_c);
      TTS_CONSTEXPR_EQUAL(sub, t);
    }

    TTS_AND_THEN("We extract [0-4[")
    {
      constexpr auto sub = t.extract(0_c, 4_c);
      TTS_CONSTEXPR_EQUAL(sub, t);
    }

    TTS_AND_THEN("We extract [0-3[")
    {
      constexpr auto sub = t.extract(0_c, 3_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {'1', 2., 3.f}));
    }

    TTS_AND_THEN("We extract [0-2[")
    {
      constexpr auto sub = t.extract(0_c, 2_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {'1', 2.}));
    }

    TTS_AND_THEN("We extract [0-1[")
    {
      constexpr auto sub = t.extract(0_c, 1_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {'1'});
    }

    TTS_AND_THEN("We extract [0-0[")
    {
      constexpr auto sub = t.extract(0_c, 0_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [1,...[")
    {
      constexpr auto sub = t.extract(1_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {2., 3.f, 4}));
    }

    TTS_AND_THEN("We extract [1,4[")
    {
      constexpr auto sub = t.extract(1_c, 4_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {2., 3.f, 4}));
    }

    TTS_AND_THEN("We extract [1,3[")
    {
      constexpr auto sub = t.extract(1_c, 3_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {2., 3.f}));
    }

    TTS_AND_THEN("We extract [1,2[")
    {
      constexpr auto sub = t.extract(1_c, 2_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {2.});
    }

    TTS_AND_THEN("We extract [1,1[")
    {
      constexpr auto sub = t.extract(1_c, 1_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [2,...[")
    {
      constexpr auto sub = t.extract(2_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {3.f, 4}));
    }

    TTS_AND_THEN("We extract [2,4[")
    {
      constexpr auto sub = t.extract(2_c, 4_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {3.f, 4}));
    }

    TTS_AND_THEN("We extract [2,3[")
    {
      constexpr auto sub = t.extract(2_c, 3_c);
      TTS_CONSTEXPR_EQUAL(sub, (kumi::tuple {3.f}));
    }

    TTS_AND_THEN("We extract [2,2[")
    {
      constexpr auto sub = t.extract(2_c, 2_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [3,...[")
    {
      constexpr auto sub = t.extract(3_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {4});
    }

    TTS_AND_THEN("We extract [3,4[")
    {
      constexpr auto sub = t.extract(3_c, 4_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {4});
    }

    TTS_AND_THEN("We extract [3,3[")
    {
      constexpr auto sub = t.extract(3_c, 3_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [4,...[")
    {
      constexpr auto sub = t.extract(4_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }

    TTS_AND_THEN("We extract [4,4[")
    {
      constexpr auto sub = t.extract(4_c, 4_c);
      TTS_CONSTEXPR_EQUAL(sub, kumi::tuple {});
    }
  }
};
