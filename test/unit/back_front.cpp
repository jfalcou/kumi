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

TTS_CASE("Check access via kumi::back")
{
  kumi::tuple t1 = {1};
  kumi::tuple t2 = {1.f, 2};
  kumi::tuple t3 = {1., 2.f, 3};
  kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_EQUAL(kumi::back(t1), 1);
  kumi::back(t1) = 42;
  TTS_EQUAL(kumi::back(t1), 42);

  TTS_EQUAL(kumi::back(t2), 2);
  kumi::back(t2) = 42;
  TTS_EQUAL(kumi::back(t2), 42);

  TTS_EQUAL(kumi::back(t3), 3);
  kumi::back(t3) = 1337;
  TTS_EQUAL(kumi::back(t3), 1337);

  TTS_EQUAL(kumi::back(t4), 4);
  kumi::back(t4) = 357;
  TTS_EQUAL(kumi::back(t4), 357);
};


TTS_CASE("Check access via constexpr kumi::back")
{
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::tuple{1}), 1);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::tuple{1.f, 2}), 2);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::tuple{1., 2.f, 3}), 3);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::tuple{'1', 2., 3.f, 4}), 4);
};

TTS_CASE("Check access via kumi::front")
{
  kumi::tuple t1 = {1};
  kumi::tuple t2 = {1.f, 2};
  kumi::tuple t3 = {1., 2.f, 3};
  kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_EQUAL(kumi::front(t1), 1);
  kumi::front(t1) = 42;
  TTS_EQUAL(kumi::front(t1), 42);

  TTS_EQUAL(kumi::front(t2), 1.f);
  kumi::front(t2) = 4.2f;
  TTS_EQUAL(kumi::front(t2), 4.2f);

  TTS_EQUAL(kumi::front(t3), 1.);
  kumi::front(t3) = 13.37;
  TTS_EQUAL(kumi::front(t3), 13.37);

  TTS_EQUAL(kumi::front(t4), '1');
  kumi::front(t4) = 'Z';
  TTS_EQUAL(kumi::front(t4), 'Z');
};

TTS_CASE("Check access via constexpr kumi::front")
{
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::tuple{1}), 1  );
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::tuple{1.f, 2}), 1.f);
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::tuple{1., 2.f, 3}), 1. );
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::tuple{'1', 2., 3.f, 4}), '1');
};
