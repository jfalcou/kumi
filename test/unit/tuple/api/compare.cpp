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
#include <string>

TTS_CASE("Lexicographical comparison - Empty tuples (N = 0)")
{
  constexpr kumi::tuple<> t0_a{};
  constexpr kumi::tuple<> t0_b{};

  TTS_EXPECT_NOT(t0_a < t0_b);
  TTS_EXPECT(t0_a <= t0_b);
  TTS_EXPECT_NOT(t0_a > t0_b);
  TTS_EXPECT(t0_a >= t0_b);
};

TTS_CASE("Lexicographical comparison - Single element tuples (N = 1)")
{
  constexpr kumi::tuple<int> t1_a{10};
  constexpr kumi::tuple<int> t1_b{20};
  constexpr kumi::tuple<int> t1_c{10};

  TTS_EXPECT(t1_a < t1_b);
  TTS_EXPECT(t1_a <= t1_b);
  TTS_EXPECT(t1_b > t1_a);
  TTS_EXPECT(t1_b >= t1_a);

  TTS_EXPECT_NOT(t1_a < t1_c);
  TTS_EXPECT(t1_a <= t1_c);
};

TTS_CASE("Lexicographical comparison - Multi-element tuples (N > 1)")
{
  constexpr kumi::tuple<int, double, char> t_a{1, 5.0, 'a'};
  constexpr kumi::tuple<int, double, char> t_b{2, 1.0, 'a'};
  TTS_EXPECT(t_a < t_b);

  constexpr kumi::tuple<int, double, char> t_c{1, 5.0, 'a'};
  constexpr kumi::tuple<int, double, char> t_d{1, 6.0, 'a'};
  TTS_EXPECT(t_c < t_d);

  constexpr kumi::tuple<int, double, char> t_e{1, 5.0, 'a'};
  constexpr kumi::tuple<int, double, char> t_f{1, 5.0, 'z'};
  TTS_EXPECT(t_e < t_f);

  constexpr kumi::tuple<int, double, char> t_g{1, 5.0, 'a'};
  TTS_EXPECT_NOT(t_a < t_g);
  TTS_EXPECT(t_a <= t_g);
  TTS_EQUAL(t_a, t_g);
};

TTS_CASE("Lexicographical comparison - Heterogeneous types")
{
  kumi::tuple<int, std::string> t1{1, "apple"};
  kumi::tuple<int, std::string> t2{1, "banana"};

  TTS_EXPECT(t1 < t2);
  TTS_EXPECT(t1 <= t2);
  TTS_EXPECT(t2 > t1);
  TTS_EXPECT(t2 >= t1);
  TTS_NOT_EQUAL(t1, t2);
};
