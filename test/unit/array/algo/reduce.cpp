//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN

#include <kumi/array.hpp>
#include <kumi/algorithm/reduce.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::reduce_t with prod/sum/bit_* behavior")
{
  using namespace kumi::function;
  TTS_TYPE_IS((kumi::result::reduce_t<numeric_add, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::reduce_t<numeric_prod, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::reduce_t<boolean_or, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::reduce_t<boolean_and, kumi::array<int, 4>>), int);

  [[maybe_unused]] auto func = [](auto const& m) { return m; };
  using func_t = decltype(func);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, numeric_add, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, numeric_prod, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, boolean_or, kumi::array<int, 4>>), int);
  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, boolean_and, kumi::array<int, 4>>), int);
};

TTS_CASE("Check kumi::reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::array{2, 3, 5, 7};
  auto t2 = kumi::array{2, 3, 5, 7};

  TTS_EQUAL(kumi::reduce(kumi::function::plus, t2), 17);
  TTS_EQUAL(kumi::reduce(kumi::function::plus, std::move(t2)), 17);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 17);
};

TTS_CASE("Check kumi::reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::array{2, 3, 5, 7};
  auto t2 = kumi::array{2, 3, 5, 7};

  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, t2), 210);
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, std::move(t2)), 210);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies, t), 210);
};

TTS_CASE("Check kumi::reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::array{14, 7, 6, 4};
  auto t2 = kumi::array{14, 7, 6, 4};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, t2), 4);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, std::move(t2)), 4);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 4);
};

TTS_CASE("Check kumi::reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::array{2, 4, 8, 16};
  auto t2 = kumi::array{2, 4, 8, 16};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, t2), 30);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, std::move(t2)), 30);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 30);
};

TTS_CASE("Check kumi::reduce with kumi::bit_xor behavior")
{
  constexpr auto t = kumi::array{2, 4, 8, 16};
  auto t2 = kumi::array{2, 4, 8, 16};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_xor, t2), 30);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_xor, std::move(t2)), 30);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_xor, t), 30);
};

TTS_CASE("Check kumi::map_reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::array{2, 3, 5, 7};
  auto t2 = kumi::array{2, 3, 5, 7};

  auto times_two = [](auto e) { return 2 * e; };

  TTS_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, t2), 34);
  TTS_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, std::move(t2)), 34);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(times_two, kumi::function::plus, t), 34);
};

TTS_CASE("Check kumi::map_reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::array{2, 3, 5, 7};
  auto t2 = kumi::array{2, 3, 5, 7};

  auto plus_two = [](auto e) { return e + 2; };

  TTS_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, t2), 1260);
  TTS_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, std::move(t2)), 1260);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(plus_two, kumi::function::multiplies, t), 1260);
};

TTS_CASE("Check kumi::map_reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::array{14, 7, 6, 4};
  auto t2 = kumi::array{14, 7, 6, 4};

  auto shift_left = [](auto e) { return e << 2; };

  TTS_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, t2), 16);
  TTS_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, std::move(t2)), 16);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(shift_left, kumi::function::bit_and, t), 16);
};

TTS_CASE("Check kumi::map_reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::array{2, 4, 8, 16};
  auto t2 = kumi::array{2, 4, 8, 16};

  auto one = [](auto) { return 1; };

  TTS_EQUAL(kumi::map_reduce(one, kumi::function::bit_or, t2), 1);
  TTS_EQUAL(kumi::map_reduce(one, kumi::function::bit_or, std::move(t2)), 1);
  TTS_CONSTEXPR_EQUAL(kumi::map_reduce(one, kumi::function::bit_or, t), 1);
};
