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
#include <string_view>

using namespace kumi::literals;
using namespace std::literals;

TTS_CASE("Check result::map_field<F,record...> behavior")
{

  using char_f      = kumi::field_capture<"a", char>;
  using short_f     = kumi::field_capture<"b", short>;
  using int_f       = kumi::field_capture<"c", int>;
  using double_f    = kumi::field_capture<"d", double>;
  using float_f     = kumi::field_capture<"d", float>;

  auto lambda = [](auto, auto const& m) { return &m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::map_field_t<func_t,kumi::record<char_f,short_f,int_f,double_f>>)
              , (kumi::record<kumi::field_capture<"a", char const*>, kumi::field_capture<"b", short const*> 
                            , kumi::field_capture<"c", int const*> , kumi::field_capture<"d", double const*>>)
              );

  auto add = [](auto name, auto a, auto b) 
  { 
    if (std::string_view{name.data(), name.size()}.compare("a") == 0)
      return (a*b)/(a+1.); 
    else
      return (a*b)/(b+1.);
  };
  using add_t = decltype(add);

  TTS_TYPE_IS ( (kumi::result::map_field_t<add_t, kumi::record<char_f,short_f,int_f,double_f>
                                               , kumi::record<char_f,short_f,int_f,float_f>
                                    >
                )
              , (kumi::record<kumi::field_capture<"a",double>,kumi::field_capture<"b",double>,
                              kumi::field_capture<"c",double>,kumi::field_capture<"d",double>>)
              );
};

TTS_CASE("Check map_field(f, {}) behavior")
{
  bool was_run = false;
  auto s = map_field([&](auto, auto m) { was_run = true; return sizeof(m); }, kumi::record{});
  TTS_EQUAL( s.size(), 0ULL );
  TTS_EXPECT_NOT( was_run );
};

TTS_CASE("Check map_name(f, record) behavior")
{
  {
    auto t = kumi::record {"boat"_f = 1, "biologic"_f = 2., "coat"_f = 3.4f, "dystopic"_f = '5', "whatever"_f = short{55}};

    {
      auto s = map_field([](auto name, auto m) 
            { 
              if (std::string_view{name.data(), name.size()}.ends_with('t'))
                return sizeof(m); 
              else if (std::string_view{name.data(), name.size()}.ends_with('c'))
                return 1+sizeof(m);
              else
                return 2+sizeof(m);
            }, t);

      auto [s0, s1, s2, s3, s4] = s;
      auto m0 = s0.value;
      auto m1 = s1.value;
      auto m2 = s2.value;
      auto m3 = s3.value;
      auto m4 = s4.value;
      TTS_EQUAL(m0, sizeof(int));
      TTS_EQUAL(m1, 1+sizeof(double));
      TTS_EQUAL(m2, sizeof(float));
      TTS_EQUAL(m3, 1+sizeof(char));
      TTS_EQUAL(m4, 2+sizeof(short));
    }

    {
      auto u = kumi::record {"whatever"_f = short{2}, "coat"_f = 2.3f, "boat"_f = 4, "biologic"_f = 5., "dystopic"_f = 'a'};
      auto s = map_field([](auto name, auto m, auto n) 
            { 
              if (std::string_view{name.data(), name.size()}.find('o') < name.size())
                return sizeof(m);
              else
                return static_cast<int>(n) * sizeof(m); 
            }, t, u);

      auto [s0, s1, s2, s3, s4] = s;
      auto m0 = s0.value;
      auto m1 = s1.value;
      auto m2 = s2.value;
      auto m3 = s3.value;
      auto m4 = s4.value;
      TTS_EQUAL(m0, sizeof(int));
      TTS_EQUAL(m1, sizeof(double));
      TTS_EQUAL(m2, sizeof(float));
      TTS_EQUAL(m3, sizeof(char));
      TTS_EQUAL(m4, 2 * sizeof(short));
    }
  }
};

TTS_CASE("Check map_field(f, record) constexpr behavior")
{
  {
    constexpr auto t = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};

    {
      constexpr auto s = map_field([](auto, auto m) { return sizeof(m); }, t);

      TTS_CONSTEXPR_EQUAL(get<"a"_f>(s), sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<"b"_f>(s), sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<"c"_f>(s), sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<"d"_f>(s), sizeof(char));
    }

    {
      constexpr auto u = kumi::record {"d"_f = 2, "b"_f = 3, "c"_f = 4, "a"_f = 5};
      constexpr auto s = map_field([](auto name, auto m, auto n) 
            { 
              if (std::string_view{name.data(), name.size()}.compare("a"sv) == 0)
                return sizeof(m);
              else
                return n * sizeof(m); 
            }, t, u);

      TTS_CONSTEXPR_EQUAL(get<"a"_f>(s), sizeof(int));
      TTS_CONSTEXPR_EQUAL(get<"b"_f>(s), 3 * sizeof(double));
      TTS_CONSTEXPR_EQUAL(get<"c"_f>(s), 4 * sizeof(float));
      TTS_CONSTEXPR_EQUAL(get<"d"_f>(s), 2 * sizeof(char));
    }
  }
};
