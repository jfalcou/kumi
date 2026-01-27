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
#include "test.hpp"
#include <array>

TTS_CASE("Check tuple_element of the output of result::builder_make_t")
{
  using namespace kumi::literals;

  using tpl = kumi::builder_make_t<kumi::tuple<double, float, char, int>, char const, double&, float>;
  TTS_TYPE_IS(tpl, (kumi::tuple<char const, double&, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, tpl>), char const);
  TTS_TYPE_IS((std::tuple_element_t<1, tpl>), double&);
  TTS_TYPE_IS((std::tuple_element_t<2, tpl>), float);

  using arr = kumi::builder_make_t<std::array<int, 5>, int, int, int, int, int>;
  TTS_TYPE_IS(arr, (kumi::tuple<int, int, int, int, int>));
  TTS_TYPE_IS((std::tuple_element_t<0, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, arr>), int);

  using pt = kumi::builder_make_t<tuple_box, int&, char const*, double>;
  TTS_TYPE_IS(pt, (kumi::tuple<int&, char const*, double>));
  TTS_TYPE_IS((std::tuple_element_t<0, pt>), int&);
  TTS_TYPE_IS((std::tuple_element_t<1, pt>), char const*);
  TTS_TYPE_IS((std::tuple_element_t<2, pt>), double);

  using tpt = kumi::builder_make_t<trivial_product_type<int, true>, int&, char const*, double>;
  TTS_TYPE_IS(tpt, (kumi::tuple<int&, char const*, double>));
  TTS_TYPE_IS((std::tuple_element_t<0, tpt>), int&);
  TTS_TYPE_IS((std::tuple_element_t<1, tpt>), char const*);
  TTS_TYPE_IS((std::tuple_element_t<2, tpt>), double);

  using rec =
    kumi::builder_make_t<kumi::record<>, kumi::field_capture<"a", float const>, kumi::field_capture<"b", int&>>;
  TTS_TYPE_IS(rec, (kumi::record<kumi::field_capture<"a", float const>, kumi::field_capture<"b", int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, rec>), (kumi::field_capture<"a", float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, rec>), (kumi::field_capture<"b", int&>));

  using rt = kumi::builder_make_t<record_box, kumi::field_capture<"a", float const>, kumi::field_capture<"b", int&>>;
  TTS_TYPE_IS(rt, (kumi::record<kumi::field_capture<"a", float const>, kumi::field_capture<"b", int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, rt>), (kumi::field_capture<"a", float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, rt>), (kumi::field_capture<"b", int&>));

  using trt = kumi::builder_make_t<trivial_record_type<int, true>, kumi::field_capture<"a", float const>,
                                   kumi::field_capture<"b", int&>>;
  TTS_TYPE_IS(trt, (kumi::record<kumi::field_capture<"a", float const>, kumi::field_capture<"b", int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, trt>), (kumi::field_capture<"a", float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, trt>), (kumi::field_capture<"b", int&>));
};

TTS_CASE("Check tuple_element of the output of builder")
{
  using namespace kumi::literals;

  auto tpl = kumi::builder<kumi::tuple<char, float>>::make('1', 2., 3.f);
  TTS_TYPE_IS((decltype(tpl)), (kumi::tuple<char, double, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpl)>), char);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpl)>), double);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpl)>), float);

  auto arr = kumi::builder<std::array<int, 5>>::make(1, 2, 3, 4, 5);
  TTS_TYPE_IS((decltype(arr)), (kumi::tuple<int, int, int, int, int>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(arr)>), int);

  auto pt = kumi::builder<tuple_box>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(pt)), (kumi::tuple<kumi::str, int, int, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(pt)>), kumi::str);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(pt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(pt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(pt)>), float);

  auto tpt = kumi::builder<trivial_product_type<int, true>>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(tpt)), (kumi::tuple<kumi::str, int, int, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpt)>), kumi::str);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(tpt)>), float);

  auto rec = kumi::builder<kumi::record<>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS(
    (decltype(rec)),
    (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>, kumi::field_capture<"c", short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rec)>), (kumi::field_capture<"a", int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rec)>), (kumi::field_capture<"b", char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rec)>), (kumi::field_capture<"c", short>));

  auto rt = kumi::builder<record_box>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS(
    (decltype(rt)),
    (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>, kumi::field_capture<"c", short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (kumi::field_capture<"a", int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (kumi::field_capture<"b", char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (kumi::field_capture<"c", short>));

  auto trt = kumi::builder<trivial_record_type<int, true>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS(
    (decltype(trt)),
    (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>, kumi::field_capture<"c", short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(trt)>), (kumi::field_capture<"a", int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(trt)>), (kumi::field_capture<"b", char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(trt)>), (kumi::field_capture<"c", short>));

  auto nt = kumi::builder<kumi::tuple<>>::make(kumi::tuple{1});
  TTS_TYPE_IS((decltype(nt)), (kumi::tuple<kumi::tuple<int>>));

  auto ft = kumi::builder<kumi::tuple<>>::build(kumi::tuple{1});
  TTS_TYPE_IS((decltype(ft)), (kumi::tuple<int>));
};

TTS_CASE("Check constexpr tuple_element of the output of builder")
{
  using namespace kumi::literals;

  constexpr auto tpl = kumi::builder<kumi::tuple<char, float>>::make('1', 2., 3.f);
  TTS_TYPE_IS((decltype(tpl)), (kumi::tuple<char, double, float> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpl)>), char const);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpl)>), double const);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpl)>), float const);

  constexpr auto arr = kumi::builder<std::array<int, 5>>::make(1, 2, 3, 4, 5);
  TTS_TYPE_IS((decltype(arr)), (kumi::tuple<int, int, int, int, int> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(arr)>), int const);

  constexpr auto pt = kumi::builder<tuple_box>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(pt)), (kumi::tuple<kumi::str, int, int, float> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(pt)>), kumi::str const);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(pt)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(pt)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(pt)>), float const);

  constexpr auto tpt = kumi::builder<trivial_product_type<int, true>>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(tpt)), (kumi::tuple<kumi::str, int, int, float> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpt)>), kumi::str const);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpt)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpt)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(tpt)>), float const);

  constexpr auto rec = kumi::builder<kumi::record<>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS((decltype(rec)), (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>,
                                             kumi::field_capture<"c", short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rec)>), (kumi::field_capture<"a", int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rec)>), (kumi::field_capture<"b", char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rec)>), (kumi::field_capture<"c", short> const));

  constexpr auto rt = kumi::builder<record_box>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS((decltype(rt)), (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>,
                                            kumi::field_capture<"c", short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (kumi::field_capture<"a", int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (kumi::field_capture<"b", char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (kumi::field_capture<"c", short> const));

  constexpr auto trt = kumi::builder<trivial_record_type<int, true>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS((decltype(trt)), (kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", char>,
                                             kumi::field_capture<"c", short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(trt)>), (kumi::field_capture<"a", int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(trt)>), (kumi::field_capture<"b", char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(trt)>), (kumi::field_capture<"c", short> const));

  constexpr auto nt = kumi::builder<kumi::tuple<>>::make(kumi::tuple{1});
  TTS_TYPE_IS((decltype(nt)), (kumi::tuple<kumi::tuple<int>> const));

  constexpr auto ft = kumi::builder<kumi::tuple<>>::build(kumi::tuple{1});
  TTS_TYPE_IS((decltype(ft)), (kumi::tuple<int> const));
};
