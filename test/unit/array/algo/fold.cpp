//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/fold.hpp>
#include <tts/tts.hpp>

#include <array>
#include <vector>

TTS_CASE("Check result::fold_right/fold_left<...> behavior")
{
  [[maybe_unused]] auto func = [](auto a, auto m) { return a + m; };
  using func_t = decltype(func);

  TTS_TYPE_IS((kumi::result::fold_right_t<func_t, kumi::array<int, 4>, int>), int);
  TTS_TYPE_IS((kumi::result::fold_left_t<func_t, kumi::array<int, 4>, int>), int);

  TTS_TYPE_IS((kumi::result::fold_right_t<func_t, kumi::array<int, 4>, unsigned>), unsigned);
  TTS_TYPE_IS((kumi::result::fold_left_t<func_t, kumi::array<int, 4>, unsigned>), unsigned);
};

TTS_CASE("Check array::fold_right behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  std::vector<int> output;

  auto empty = kumi::fold_right([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, 42);

  auto accumulated = kumi::fold_right(
    [](auto m, auto acc) {
      acc.push_back(m);
      return acc;
    },
    t, output);

  TTS_EQUAL(accumulated, (std::vector<int>{4, 3, 2, 1}));
};

TTS_CASE("Check array::fold_right constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::fold_right([](auto, auto acc) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_right(
    []<std::size_t N>(auto m, std::array<int, N> acc) {
      if constexpr (N == 0)
      {
        std::array<int, 1> res{m};
        return res;
      }
      else
      {
        std::array<int, N + 1> res;
        for (std::size_t i = 0; i < N; ++i) res[i] = acc[i];
        res[N] = m;
        return res;
      }
    },
    t, std::array<int, 0>{});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4>{4, 3, 2, 1}));
};

TTS_CASE("Check array::fold_left behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  auto empty = kumi::fold_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, 42);

  std::vector<int> output;

  auto accumulated = kumi::fold_left(
    [](auto acc, auto m) {
      acc.push_back(m);
      return acc;
    },
    t, output);

  TTS_EQUAL(accumulated, (std::vector<int>{1, 2, 3, 4}));
};

TTS_CASE("Check array::fold_left constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::fold_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_left(
    []<std::size_t N>(std::array<int, N> acc, auto m) {
      if constexpr (N == 0)
      {
        std::array<int, 1> res{m};
        return res;
      }
      else
      {
        std::array<int, N + 1> res;
        for (std::size_t i = 0; i < N; ++i) res[i] = acc[i];
        res[N] = m;
        return res;
      }
    },
    t, std::array<int, 0>{});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4>{1, 2, 3, 4}));
};
