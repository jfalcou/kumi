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
#include <tuple>
#include "test.hpp"
#include <tts/tts.hpp>

struct final_empty
{
} final;

TTS_CASE("Check EBO behavior of kumi::tuple construction")
{
  using namespace kumi::literals;
  auto k0 = kumi::record<>{};
  auto k1 = kumi::record{"a"_f = empty{}};
  auto k2 = kumi::record{"a"_f = empty{}, "b"_f = empty{}};
  auto k3 = kumi::record{"a"_f = empty{}, "b"_f = kumi::none};
  auto k4 = kumi::record{"a"_f = int{1}, "b"_f = empty{}};
  auto k5 = kumi::record{"a"_f = int{1}, "b"_f = empty{}, "c"_f = char{'c'}};
  auto k6 = kumi::record{"a"_f = kumi::tuple{empty{}}, "c"_f = int{1}};
  auto k7 = kumi::record{"a"_f = final_empty{}};

  auto s0 = std::tuple<>{};
  auto s1 = std::tuple{empty{}};
  [[maybe_unused]] auto s2 = std::tuple{empty{}, empty{}};
  [[maybe_unused]] auto s3 = std::tuple{empty{}, kumi::none};
  [[maybe_unused]] auto s4 = std::tuple{int{1}, empty{}};
  auto s5 = std::tuple{int{1}, empty{}, char{'c'}};
  auto s6 = std::tuple{std::tuple{empty{}}, int{1}};
  auto s7 = std::tuple{final_empty{}};

#if defined(_MSC_VER)
  TTS_EQUAL(sizeof(k0), sizeof(s0));
  TTS_EQUAL(sizeof(k1), sizeof(s1));
  TTS_EQUAL(sizeof(k2), sizeof(s1)); // k2 should be optimized
  TTS_EQUAL(sizeof(k3), sizeof(s1));
  TTS_EQUAL(sizeof(k4), sizeof(std::tuple{int{1}}));
  TTS_EQUAL(sizeof(k5), sizeof(s5));
  TTS_EQUAL(sizeof(k6), sizeof(s6));
  TTS_EQUAL(sizeof(k7), sizeof(s7));
#else
  TTS_EQUAL(sizeof(k0), sizeof(s0));
  TTS_EQUAL(sizeof(k1), sizeof(s1));
  TTS_EQUAL(sizeof(k2), sizeof(s2));
  TTS_EQUAL(sizeof(k3), sizeof(s3));
  TTS_EQUAL(sizeof(k4), sizeof(s4));
  TTS_EQUAL(sizeof(k5), sizeof(s5));
  TTS_EQUAL(sizeof(k6), sizeof(s6));
  TTS_EQUAL(sizeof(k7), sizeof(s7));
#endif
};
