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

TTS_CASE("Check result::map<F,Record...> behavior")
{
  using namespace kumi::literals;
  
  using char_f      = kumi::field_capture<"a", char>;
  using short_f     = kumi::field_capture<"b", short>;
  using int_f       = kumi::field_capture<"c", int>;
  using double_f    = kumi::field_capture<"d", double>;
  using float_f     = kumi::field_capture<"d", float>;

  auto lambda = [](auto const& m) { return &m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::map_t<func_t,kumi::record<char_f,short_f,int_f,double_f>>)
              , (kumi::record<kumi::field_capture<"a", char const*>, kumi::field_capture<"b", short const*>
                            , kumi::field_capture<"c", int const*> , kumi::field_capture<"d", double const*>>)
              );

  auto add = [](auto a, auto b) { return a+b; };
  using add_t = decltype(add);

  TTS_TYPE_IS ( (kumi::result::map_t<add_t, kumi::record<char_f,short_f,int_f,double_f>
                                          , kumi::record<char_f,short_f,int_f,float_f>
                                    >
                )
              , (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", int>
                            , kumi::field_capture<"c", int>, kumi::field_capture<"d", double>>)
              );
};

TTS_CASE("Check map(f, {}) behavior")
{
  bool was_run = false;
  auto s = map([&](auto m) { was_run = true; return sizeof(m); }, kumi::record{});
  TTS_EQUAL( s.size(), 0ULL );
  TTS_EXPECT_NOT( was_run );
};

TTS_CASE("Check map(f, record) behavior")
{
  using namespace kumi::literals;

  {
    auto t = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};

    {
      auto s = map([](auto m) { return sizeof(m); }, t);

      auto [s0, s1, s2, s3] = s;
      auto m0 = s0.value;
      auto m1 = s1.value;
      auto m2 = s2.value;
      auto m3 = s3.value;
      TTS_EQUAL(m0, sizeof(int));
      TTS_EQUAL(m1, sizeof(double));
      TTS_EQUAL(m2, sizeof(float));
      TTS_EQUAL(m3, sizeof(char));
    }

    {
      auto u = kumi::record { "c"_f = 4, "b"_f = 3, "d"_f = 5, "a"_f = 2,};
      auto s = map([](auto m, auto n) { return n * sizeof(m); }, t, u);

      auto [s0, s1, s2, s3] = s;
      auto m0 = s0.value;
      auto m1 = s1.value;
      auto m2 = s2.value;
      auto m3 = s3.value;
      TTS_EQUAL(m0, 2 * sizeof(int));
      TTS_EQUAL(m1, 3 * sizeof(double));
      TTS_EQUAL(m2, 4 * sizeof(float));
      TTS_EQUAL(m3, 5 * sizeof(char));
    }
  }
};

TTS_CASE("Check map(f, record) constexpr behavior")
{
  using namespace kumi::literals;

  {
    constexpr auto t = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};

    {
      constexpr auto s = map([](auto m) { return sizeof(m); }, t);

      TTS_CONSTEXPR_EQUAL(get<"a"_f>(s), sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<"b"_f>(s), sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<"c"_f>(s), sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<"d"_f>(s), sizeof(char));
    }

    {
      constexpr auto u = kumi::record {"a"_f = 2, "b"_f = 3, "c"_f = 4, "d"_f = 5};
      constexpr auto s = map([](auto m, auto n) { return n * sizeof(m); }, t, u);

      TTS_CONSTEXPR_EQUAL(get<"a"_f>(s), 2 * sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<"b"_f>(s), 3 * sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<"c"_f>(s), 4 * sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<"d"_f>(s), 5 * sizeof(char));
    }
  }
};