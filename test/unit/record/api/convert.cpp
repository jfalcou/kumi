//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

void takes_nullptr_t(std::nullptr_t);
void takes_unit(kumi::unit);
void takes_empty_tuple(kumi::tuple<>);
void takes_empty_record(kumi::record<>);

TTS_CASE("Check empty record conversions")
{
  kumi::unit n{};
  kumi::tuple empty_t{};
  kumi::record empty_r{};

  TTS_EXPECT_COMPILES(empty_t, { takes_empty_record(empty_t); });
  TTS_EXPECT_COMPILES(n, { takes_empty_record(n); });
  TTS_EXPECT_COMPILES(empty_r, { takes_nullptr_t(empty_r); });
  TTS_EXPECT_COMPILES(empty_r, { takes_unit(empty_r); });
  TTS_EXPECT_COMPILES(empty_r, { takes_empty_tuple(empty_r); });
  TTS_EXPECT_COMPILES(empty_r, { takes_empty_record(empty_r); });
};
