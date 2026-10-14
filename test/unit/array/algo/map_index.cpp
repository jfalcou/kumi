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

TTS_CASE("Check result::map_index<F,Array...> behavior")
{
  [[maybe_unused]] auto func = [](auto, auto const& m) { return &m; };
  using func_t = decltype(func);

  TTS_TYPE_IS((kumi::result::map_index_t<func_t, kumi::array<int, 4>>), (kumi::array<int const*, 4>));

  [[maybe_unused]] auto add = [](auto i, auto a, auto b) { return (a * b) / (i + 1.); };
  using add_t = decltype(add);

  TTS_TYPE_IS((kumi::result::map_index_t<add_t, kumi::array<int, 4>, kumi::array<int, 4>>), (kumi::array<double, 4>));

  [[maybe_unused]] auto to = [](auto, auto) { return kumi::make_tuple(1); };
  using to_t = decltype(to);
  TTS_TYPE_IS((kumi::result::map_index_t<to_t, kumi::array<int, 4>>), (kumi::array<kumi::tuple<int>, 4>));
};

TTS_CASE("Check map_index(f, {}) behavior")
{
  bool was_run = false;
  [[maybe_unused]] auto s = kumi::map_index(
    [&](auto, auto m) {
      was_run = true;
      return sizeof(m);
    },
    kumi::array<int, 0>{});
  TTS_EQUAL(s.size(), 0ULL);
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check map_index(f, array) behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  {
    auto s = kumi::map_index([](auto i, auto m) { return i + sizeof(m); }, t);

    auto [s0, s1, s2, s3] = s;
    TTS_EQUAL(s0, sizeof(int));
    TTS_EQUAL(s1, 1 + sizeof(int));
    TTS_EQUAL(s2, 2 + sizeof(int));
    TTS_EQUAL(s3, 3 + sizeof(int));
  }

  {
    auto u = kumi::array{2, 3, 4, 5};
    auto s = kumi::map_index([](auto i, auto m, auto n) { return (n + i) * sizeof(m); }, t, u);

    auto [s0, s1, s2, s3] = s;
    TTS_EQUAL(s0, 2 * sizeof(int));
    TTS_EQUAL(s1, 4 * sizeof(int));
    TTS_EQUAL(s2, 6 * sizeof(int));
    TTS_EQUAL(s3, 8 * sizeof(int));
  }
};
