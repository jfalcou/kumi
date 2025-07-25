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

TTS_CASE("Check result::map_index<F,Tuple...> behavior")
{
  auto lambda = [](auto, auto const& m) { return &m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::map_index_t<func_t,kumi::tuple<char,short,int,double>>)
              , (kumi::tuple<char const*,short const*,int const*,double const*>)
              );

  auto add = [](auto i, auto a, auto b) { return (a*b)/(i+1.); };
  using add_t = decltype(add);

  TTS_TYPE_IS ( (kumi::result::map_index_t<add_t, kumi::tuple<char,short,int,double>
                                          , kumi::tuple<char,short,int,float>
                                    >
                )
              , (kumi::tuple<double,double,double,double>)
              );
};

TTS_CASE("Check map_index(f, {}) behavior")
{
  bool was_run = false;
  auto s = map_index([&](auto, auto m) { was_run = true; return sizeof(m); }, kumi::tuple{});
  TTS_EQUAL( s.size(), 0ULL );
  TTS_EXPECT_NOT( was_run );
};

TTS_CASE("Check map_index(f, tuple) behavior")
{
  {
    auto t = kumi::tuple {1, 2., 3.4f, '5'};

    {
      auto s = map_index([](auto i, auto m) { return i+sizeof(m); }, t);

      auto [s0, s1, s2, s3] = s;
      auto m0 = s0;
      auto m1 = s1;
      auto m2 = s2;
      auto m3 = s3;
      TTS_EQUAL(m0, sizeof(int));
      TTS_EQUAL(m1, 1+sizeof(double));
      TTS_EQUAL(m2, 2+sizeof(float));
      TTS_EQUAL(m3, 3+sizeof(char));
    }

    {
      auto u = kumi::tuple {2, 3, 4, 5};
      auto s = map_index([](auto i, auto m, auto n) { return (n+i) * sizeof(m); }, t, u);

      auto [s0, s1, s2, s3] = s;
      auto m0 = s0;
      auto m1 = s1;
      auto m2 = s2;
      auto m3 = s3;
      TTS_EQUAL(m0, 2 * sizeof(int));
      TTS_EQUAL(m1, 4 * sizeof(double));
      TTS_EQUAL(m2, 6 * sizeof(float));
      TTS_EQUAL(m3, 8 * sizeof(char));
    }
  }
};

#if 0
TTS_CASE("Check map_index(f, tuple) constexpr behavior")
{
  {
    constexpr auto t = kumi::tuple {1, 2., 3.4f, '5'};

    {
      constexpr auto s = map_index([](auto m) { return sizeof(m); }, t);

      TTS_CONSTEXPR_EQUAL(get<0>(s), sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<1>(s), sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<2>(s), sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<3>(s), sizeof(char));
    }

    {
      constexpr auto u = kumi::tuple {2, 3, 4, 5};
      constexpr auto s = map_index([](auto m, auto n) { return n * sizeof(m); }, t, u);

      TTS_CONSTEXPR_EQUAL(get<0>(s), 2 * sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<1>(s), 3 * sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<2>(s), 4 * sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<3>(s), 5 * sizeof(char));
    }
  }
};
#endif
