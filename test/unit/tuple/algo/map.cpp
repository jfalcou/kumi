//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::map<F,Tuple...> behavior")
{
  auto lambda = [](auto const& m) { return &m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS((kumi::result::map_t<func_t, kumi::tuple<char, short, int, double>>),
              (kumi::tuple<char const*, short const*, int const*, double const*>));

  auto add = [](auto a, auto b) { return a + b; };
  using add_t = decltype(add);

  TTS_TYPE_IS((kumi::result::map_t<add_t, kumi::tuple<char, short, int, double>, kumi::tuple<char, short, int, float>>),
              (kumi::tuple<int, int, int, double>));

  auto to_tuple = [](auto) { return kumi::make_tuple(1); };
  using to_t = decltype(to_tuple);
  TTS_TYPE_IS((kumi::result::map_t<to_t, kumi::tuple<int>>), (kumi::tuple<kumi::tuple<int>>));
};

TTS_CASE("Check map(f, {}) behavior")
{
  bool was_run = false;
  auto s = map(
    [&](auto m) {
      was_run = true;
      return sizeof(m);
    },
    kumi::tuple{});
  TTS_EQUAL(s.size(), 0ULL);
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check map(f, tuple) behavior"){{auto t = kumi::tuple{1, 2., 3.4f, '5'};

{
  auto s = map([](auto m) { return sizeof(m); }, t);

  auto [s0, s1, s2, s3] = s;
  auto m0 = s0;
  auto m1 = s1;
  auto m2 = s2;
  auto m3 = s3;
  TTS_EQUAL(m0, sizeof(int));
  TTS_EQUAL(m1, sizeof(double));
  TTS_EQUAL(m2, sizeof(float));
  TTS_EQUAL(m3, sizeof(char));
}

{
  auto u = kumi::tuple{2, 3, 4, 5};
  auto s = map([](auto m, auto n) { return n * sizeof(m); }, t, u);

  auto [s0, s1, s2, s3] = s;
  auto m0 = s0;
  auto m1 = s1;
  auto m2 = s2;
  auto m3 = s3;
  TTS_EQUAL(m0, 2 * sizeof(int));
  TTS_EQUAL(m1, 3 * sizeof(double));
  TTS_EQUAL(m2, 4 * sizeof(float));
  TTS_EQUAL(m3, 5 * sizeof(char));
}
{
  auto t2 = kumi::tuple{1, 2., 3.4f, '5', moveonly{}};
  auto u = kumi::tuple{2, 3, 4, 5, 6};
  auto s = map([](auto m, auto n) { return n * sizeof(m); }, std::move(t2), std::move(u));

  auto [s0, s1, s2, s3, s4] = s;
  auto m0 = s0;
  auto m1 = s1;
  auto m2 = s2;
  auto m3 = s3;
  auto m4 = s4;
  TTS_EQUAL(m0, 2 * sizeof(int));
  TTS_EQUAL(m1, 3 * sizeof(double));
  TTS_EQUAL(m2, 4 * sizeof(float));
  TTS_EQUAL(m3, 5 * sizeof(char));
  TTS_EQUAL(m4, 6 * sizeof(moveonly));
}
{
  auto tpl = kumi::tuple{1, 2, 3};
  auto tpl2 = kumi::tuple{'x', moveonly{}, 5};
  TTS_EXPECT_COMPILES(tpl, tpl2, {
    kumi::map([](auto&& m0, auto&& ms) { return kumi::make_tuple(KUMI_FWD(m0), KUMI_FWD(ms)); }, std::move(tpl2), tpl);
  });
}
}
}
;

TTS_CASE("Check map(f, tuple) constexpr behavior"){{constexpr auto t = kumi::tuple{1, 2., 3.4f, '5'};

{
  constexpr auto s = map([](auto m) { return sizeof(m); }, t);

  TTS_CONSTEXPR_EQUAL(get<0>(s), sizeof(int));
  TTS_CONSTEXPR_EQUAL(get<1>(s), sizeof(double));
  TTS_CONSTEXPR_EQUAL(get<2>(s), sizeof(float));
  TTS_CONSTEXPR_EQUAL(get<3>(s), sizeof(char));
}

{
  constexpr auto u = kumi::tuple{2, 3, 4, 5};
  constexpr auto s = map([](auto m, auto n) { return n * sizeof(m); }, t, u);

  TTS_CONSTEXPR_EQUAL(get<0>(s), 2 * sizeof(int));
  TTS_CONSTEXPR_EQUAL(get<1>(s), 3 * sizeof(double));
  TTS_CONSTEXPR_EQUAL(get<2>(s), 4 * sizeof(float));
  TTS_CONSTEXPR_EQUAL(get<3>(s), 5 * sizeof(char));
}
}
}
;
