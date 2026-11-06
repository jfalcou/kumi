//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/back_front.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check access via kumi::back")
{
  kumi::array t1 = {1};
  kumi::array t2 = {1, 2};
  kumi::array t3 = {1, 2, 3};
  kumi::array t4 = {1, 2, 3, 4};
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
  kumi::array t5 = {3, 4, 5};
  TTS_EXPECT_COMPILES(t5, { kumi::back(std::move(t5)); });
};

TTS_CASE("Check access via constexpr kumi::back")
{
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::array{1}), 1);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::array{1, 2}), 2);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::array{1, 2, 3}), 3);
  TTS_CONSTEXPR_EQUAL(kumi::back(kumi::array{1, 2, 3, 4}), 4);
};

TTS_CASE("Check access via kumi::front")
{
  kumi::array t1 = {1};
  kumi::array t2 = {1, 2};
  kumi::array t3 = {1, 2, 3};
  kumi::array t4 = {1, 2, 3, 4};
  TTS_EQUAL(kumi::front(t1), 1);
  kumi::front(t1) = 42;
  TTS_EQUAL(kumi::front(t1), 42);
  TTS_EQUAL(kumi::front(t2), 1);
  kumi::front(t2) = 4;
  TTS_EQUAL(kumi::front(t2), 4);
  TTS_EQUAL(kumi::front(t3), 1);
  kumi::front(t3) = 13;
  TTS_EQUAL(kumi::front(t3), 13);
  TTS_EQUAL(kumi::front(t4), 1);
  kumi::front(t4) = 9;
  TTS_EQUAL(kumi::front(t4), 9);
  kumi::array t5 = {3, 4, 5};
  TTS_EXPECT_COMPILES(t5, { kumi::front(std::move(t5)); });
};

TTS_CASE("Check access via constexpr kumi::front")
{
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::array{1}), 1);
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::array{1, 2}), 1);
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::array{1, 2, 3}), 1);
  TTS_CONSTEXPR_EQUAL(kumi::front(kumi::array{1, 2, 3, 4}), 1);
};
