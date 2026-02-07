//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <vector>

TTS_CASE("Check result::fold_right/fold_left<...> behavior")
{
  using namespace kumi::literals;

  auto lambda = [](auto a, auto m) { return a + sizeof(m); };
  using func_t = decltype(lambda);

  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  TTS_TYPE_IS((kumi::result::fold_right_t<func_t, kumi::record<char_f, short_f, int_f, double_f>, int>), std::size_t);
  TTS_TYPE_IS((kumi::result::fold_left_t<func_t, kumi::record<char_f, short_f, int_f, double_f>, int>), std::size_t);

  TTS_TYPE_IS((kumi::result::fold_right_t<func_t, kumi::record<char_f, short_f, int_f, double_f>>), std::size_t);
  TTS_TYPE_IS((kumi::result::fold_left_t<func_t, kumi::record<char_f, short_f, int_f, double_f>>), std::size_t);
};

TTS_CASE("Check tuple::fold_right behavior")
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};

  std::vector<int> output;

  auto empty = kumi::fold_right([](auto, auto acc) { return acc; }, kumi::record{}, 42);
  TTS_EQUAL(empty, 42);

  auto accumulated = kumi::fold_right(
    [](auto m, auto acc) {
      acc.push_back(sizeof(m));
      return acc;
    },
    t, output);

  TTS_EQUAL(accumulated, (std::vector<int>{1, 2, 4, 8}));
};

TTS_CASE("Check tuple::fold_right constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};

  constexpr auto empty = kumi::fold_right([](auto, auto acc) { return acc; }, kumi::record{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_right(
    []<std::size_t N>(auto m, std::array<int, N> acc) {
      if constexpr (N == 0)
      {
        std::array<int, 1> res{sizeof(m)};
        return res;
      }
      else
      {
        std::array<int, N + 1> res;
        for (std::size_t i = 0; i < N; ++i) res[i] = acc[i];
        res[N] = sizeof(m);
        return res;
      }
    },
    t, std::array<int, 0>{});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4>{1, 2, 4, 8}));
};

TTS_CASE("Check tuple::fold_left behavior")
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};

  auto empty = kumi::fold_left([](auto acc, auto) { return acc; }, kumi::record{}, 42);
  TTS_EQUAL(empty, 42);

  std::vector<int> output;

  auto accumulated = kumi::fold_left(
    [](auto acc, auto m) {
      acc.push_back(sizeof(m));
      return acc;
    },
    t, output);

  TTS_EQUAL(accumulated, (std::vector<int>{8, 4, 2, 1}));
};

TTS_CASE("Check tuple::fold_left constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};

  constexpr auto empty = kumi::fold_left([](auto acc, auto) { return acc; }, kumi::record{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_left(
    []<std::size_t N>(std::array<int, N> acc, auto m) {
      if constexpr (N == 0)
      {
        std::array<int, 1> res{sizeof(m)};
        return res;
      }
      else
      {
        std::array<int, N + 1> res;
        for (std::size_t i = 0; i < N; ++i) res[i] = acc[i];
        res[N] = sizeof(m);
        return res;
      }
    },
    t, std::array<int, 0>{});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4>{8, 4, 2, 1}));
};
