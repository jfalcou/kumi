//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <vector>


TTS_CASE("Check result::fold_right/fold_left<...> behavior")
{
  auto lambda = [](auto a, auto m) { return a + sizeof(m); };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::fold_right_t<func_t,kumi::tuple<char,short,int,double>,int>)
              , std::size_t
              );
  TTS_TYPE_IS ( (kumi::result::fold_left_t<func_t,kumi::tuple<char,short,int,double>,int>)
              , std::size_t
              );
};

TTS_CASE("Check tuple::fold_right behavior")
{
  auto t = kumi::tuple {2., 1, short {55}, 'z'};

  std::vector<int> output;

  auto empty = kumi::fold_right( [](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, 42);

  auto accumulated = kumi::fold_right(
      [](auto acc, auto m) {
        acc.push_back(sizeof(m));
        return acc;
      },
      t,
      output);

  TTS_EQUAL(accumulated, (std::vector<int> {8, 4, 2, 1}));
};

TTS_CASE("Check tuple::fold_right constexpr behavior")
{
  constexpr auto t = kumi::tuple {2., 1, short {55}, 'z'};

  constexpr auto empty = kumi::fold_right( [](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_right(
      []<std::size_t N>(std::array<int, N> acc, auto m) {
        if constexpr( N == 0 )
        {
          std::array<int, 1> res {sizeof(m)};
          return res;
        }
        else
        {
          std::array<int, N + 1> res;
          for( std::size_t i = 0; i < N; ++i ) res[i] = acc[i];
          res[N] = sizeof(m);
          return res;
        }
      },
      t,
      std::array<int, 0> {});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4> {8, 4, 2, 1}));
};

TTS_CASE("Check tuple::fold_left behavior")
{
  auto t = kumi::tuple {2., 1, short {55}, 'z'};

  auto empty = kumi::fold_left( [](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, 42);

  std::vector<int> output;

  auto accumulated = kumi::fold_left(
      [](auto acc, auto m) {
        acc.push_back(sizeof(m));
        return acc;
      },
      t,
      output);

  TTS_EQUAL(accumulated, (std::vector<int> {1, 2, 4, 8}));
};

TTS_CASE("Check tuple::fold_left constexpr behavior")
{
  constexpr auto t = kumi::tuple {2., 1, short {55}, 'z'};

  constexpr auto empty = kumi::fold_left( [](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, 42);

  constexpr auto accumulated = kumi::fold_left(
      []<std::size_t N>(std::array<int, N> acc, auto m) {
        if constexpr( N == 0 )
        {
          std::array<int, 1> res {sizeof(m)};
          return res;
        }
        else
        {
          std::array<int, N + 1> res;
          for( std::size_t i = 0; i < N; ++i ) res[i] = acc[i];
          res[N] = sizeof(m);
          return res;
        }
      },
      t,
      std::array<int, 0> {});

  TTS_CONSTEXPR_EQUAL(accumulated, (std::array<int, 4> {1, 2, 4, 8}));
};
