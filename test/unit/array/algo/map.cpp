//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/map.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::map<F,Array...> behavior")
{
  [[maybe_unused]] auto func = [](auto const& m) { return &m; };
  using func_t = decltype(func);

  TTS_TYPE_IS((kumi::result::map_t<func_t, kumi::array<int, 4>>), (kumi::array<int const*, 4>));

  [[maybe_unused]] auto add = [](auto a, auto b) { return a + b; };
  using add_t = decltype(add);

  TTS_TYPE_IS((kumi::result::map_t<add_t, kumi::array<int, 4>, kumi::array<short, 4>>), (kumi::array<int, 4>));
};

TTS_CASE("Check map(f, {}) behavior")
{
  bool was_run = false;
  [[maybe_unused]] auto s = kumi::map(
    [&](auto m) {
      was_run = true;
      return sizeof(m);
    },
    kumi::array<int, 0>{});
  TTS_EQUAL(s.size(), 0ULL);
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check map(f, array) behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  {
    auto s = kumi::map([](auto m) { return sizeof(m); }, t);
    TTS_EQUAL(s, (kumi::array{4ull, 4ull, 4ull, 4ull}));
  }

  {
    auto u = kumi::array{2, 3, 4, 5};
    auto s = kumi::map([](auto m, auto n) { return n * sizeof(m); }, t, u);
    TTS_EQUAL(s, (kumi::array{8ull, 12ull, 16ull, 20ull}));
  }
};

TTS_CASE("Check map(f, array) constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  {
    constexpr auto s = kumi::map([](auto m) { return sizeof(m); }, t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4ull, 4ull, 4ull, 4ull}));
  }

  {
    constexpr auto u = kumi::array{2, 3, 4, 5};
    constexpr auto s = kumi::map([](auto m, auto n) { return n * sizeof(m); }, t, u);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{8ull, 12ull, 16ull, 20ull}));
  }
};
