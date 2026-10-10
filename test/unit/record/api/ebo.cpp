//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <tuple>
#include <kumi/record.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

struct final_empty final
{
};

TTS_CASE("Check EBO behavior of kumi::tuple construction")
{
  using namespace kumi::literals;
  [[maybe_unused]] auto k0 = kumi::record<>{};
  [[maybe_unused]] auto k1 = kumi::record{"a"_id = empty{}};
  [[maybe_unused]] auto k2 = kumi::record{"a"_id = empty{}, "b"_id = empty{}};
  [[maybe_unused]] auto k3 = kumi::record{"a"_id = empty{}, "b"_id = kumi::none};
  [[maybe_unused]] auto k4 = kumi::record{"a"_id = int{1}, "b"_id = empty{}};
  [[maybe_unused]] auto k5 = kumi::record{"a"_id = int{1}, "b"_id = empty{}, "c"_id = char{'c'}};
  [[maybe_unused]] auto k6 = kumi::record{"a"_id = kumi::tuple{empty{}}, "c"_id = int{1}};
  [[maybe_unused]] auto k7 = kumi::record{"a"_id = final_empty{}};

  [[maybe_unused]] auto s0 = std::tuple<>{};
  [[maybe_unused]] auto s1 = std::tuple{empty{}};
  [[maybe_unused]] auto s2 = std::tuple{empty{}, empty{}};
  [[maybe_unused]] auto s3 = std::tuple{empty{}, kumi::none};
  [[maybe_unused]] auto s4 = std::tuple{int{1}, empty{}};
  [[maybe_unused]] auto s5 = std::tuple{int{1}, empty{}, char{'c'}};
  [[maybe_unused]] auto s6 = std::tuple{std::tuple{empty{}}, int{1}};
  [[maybe_unused]] auto s7 = std::tuple{final_empty{}};

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
