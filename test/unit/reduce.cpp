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

TTS_CASE("Check result::reduce_t with prod/sum/bit_* behavior")
{
  TTS_TYPE_IS((kumi::result::reduce_t<kumi::numeric_add, kumi::tuple<char, short, int, double>>), double);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::numeric_prod, kumi::tuple<char, short, int, double>>), double);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::boolean_or, kumi::tuple<short, std::size_t, int>>), std::size_t);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::boolean_and, kumi::tuple<short, std::size_t, int>>), std::size_t);

  auto lambda = [](auto const& m) { return m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::numeric_add, kumi::tuple<char, short, int, double>>), double);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::numeric_prod, kumi::tuple<char, short, int, double>>), double);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::boolean_or, kumi::tuple<short, std::size_t, int>>),
              std::size_t);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::boolean_and, kumi::tuple<short, std::size_t, int>>),
              std::size_t);
};

TTS_CASE("Check kumi::reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};
  auto t2 = kumi::tuple{2., 1, short{55}, 'z'};

  TTS_EQUAL(kumi::reduce(kumi::function::plus, t2), 180);
  TTS_EQUAL(kumi::reduce(kumi::function::plus, std::move(t2)), 180);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 180);
};

TTS_CASE("Check kumi::reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::tuple{2., 3, short{5}, '\a'};
  auto t2 = kumi::tuple{2., 3, short{5}, '\a'};

  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, t2), 210);
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, std::move(t)), 210);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies, t), 210);
};

TTS_CASE("Check kumi::reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::tuple{14UL, char{7}, short{6}};
  auto t2 = kumi::tuple{14UL, char{7}, short{6}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, t2), 6UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, std::move(t2)), 6UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 6UL);
};

TTS_CASE("Check kumi::reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::tuple{2UL, 3, short{5}, char{64}};
  auto t2 = kumi::tuple{2UL, 3, short{5}, char{64}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, t2), 71UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, std::move(t2)), 71UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 71UL);
};

TTS_CASE("Check kumi::reduce with kumi::bit_xor behavior")
{
  constexpr auto t = kumi::tuple{2UL, 3, short{5}, char{64}};
  auto t2 = kumi::tuple{2UL, 3, short{5}, char{64}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_xor, t2), 68UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_xor, std::move(t2)), 68UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_xor, t), 68UL);
};

TTS_CASE("Check kumi::map_reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};
  auto t2 = kumi::tuple{2., 1, short{55}, 'z'};

  auto times_two = [](auto e) { return 2 * e; };

  TTS_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, t2), 360);
  TTS_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, std::move(t2)), 360);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, t), 360);
};

TTS_CASE("Check kumi::map_reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::tuple{2., 3, short{5}, '\a'};
  auto t2 = kumi::tuple{2., 3, short{5}, '\a'};

  auto plus_two = [](auto e) { return e + 2; };

  TTS_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, t2), 1260);
  TTS_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, std::move(t)), 1260);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, t), 1260);
};

TTS_CASE("Check kumi::map_reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::tuple{14UL, char{7}, short{6}};
  auto t2 = kumi::tuple{14UL, char{7}, short{6}};

  auto shift_left = [](auto e) { return e << 2; };

  TTS_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, t2), 24UL);
  TTS_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, std::move(t2)), 24UL);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, t), 24UL);
};

TTS_CASE("Check kumi::map_reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::tuple{2UL, 3, short{5}, char{64}};
  auto t2 = kumi::tuple{2UL, 3, short{5}, char{64}};

  auto shift_right = [](auto e) { return e >> 2; };

  TTS_EQUAL(kumi::map_reduce(shift_right, kumi::function::bit_or, t2), 17UL);
  TTS_EQUAL(kumi::map_reduce(shift_right, kumi::function::bit_or, std::move(t2)), 17UL);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(shift_right, kumi::function::bit_or, t), 17UL);
};

TTS_CASE("Check kumi::map_reduce with kumi::bit_xor behavior")
{
  constexpr auto t = kumi::tuple{2UL, 3, short{5}, char{64}};
  auto t2 = kumi::tuple{2UL, 3, short{5}, char{64}};

  auto positive_not = [](auto e) { return -(~e); };

  TTS_EQUAL(kumi::map_reduce(positive_not, kumi::function::bit_xor, t2), 64UL);
  TTS_EQUAL(kumi::map_reduce(positive_not, kumi::function::bit_xor, std::move(t2)), 64UL);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(positive_not, kumi::function::bit_xor, t), 64UL);
};
