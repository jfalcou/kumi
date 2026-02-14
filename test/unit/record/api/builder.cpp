//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"
#include <array>

TTS_CASE("Check tuple_element of the output of result::builder_make_t")
{

  using rec =
    kumi::builder_make_t<kumi::record<>, kumi::field<kumi::name<"a">, float const>, kumi::field<kumi::name<"b">, int&>>;
  TTS_TYPE_IS(rec, (kumi::record<kumi::field<kumi::name<"a">, float const>, kumi::field<kumi::name<"b">, int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, rec>), (kumi::field<kumi::name<"a">, float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, rec>), (kumi::field<kumi::name<"b">, int&>));

  using rt =
    kumi::builder_make_t<record_box, kumi::field<kumi::name<"a">, float const>, kumi::field<kumi::name<"b">, int&>>;
  TTS_TYPE_IS(rt, (kumi::record<kumi::field<kumi::name<"a">, float const>, kumi::field<kumi::name<"b">, int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, rt>), (kumi::field<kumi::name<"a">, float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, rt>), (kumi::field<kumi::name<"b">, int&>));

  using trt = kumi::builder_make_t<trivial_record_type<int, true>, kumi::field<kumi::name<"a">, float const>,
                                   kumi::field<kumi::name<"b">, int&>>;
  TTS_TYPE_IS(trt, (kumi::record<kumi::field<kumi::name<"a">, float const>, kumi::field<kumi::name<"b">, int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, trt>), (kumi::field<kumi::name<"a">, float const>));
  TTS_TYPE_IS((std::tuple_element_t<1, trt>), (kumi::field<kumi::name<"b">, int&>));
};

TTS_CASE("Check tuple_element of the output of builder")
{
  using namespace kumi::literals;

  auto rec = kumi::builder<kumi::record<>>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(rec)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                             kumi::field<kumi::name<"c">, short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rec)>), (kumi::field<kumi::name<"a">, int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rec)>), (kumi::field<kumi::name<"b">, char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rec)>), (kumi::field<kumi::name<"c">, short>));

  auto rt = kumi::builder<record_box>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(rt)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                            kumi::field<kumi::name<"c">, short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (kumi::field<kumi::name<"a">, int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (kumi::field<kumi::name<"b">, char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (kumi::field<kumi::name<"c">, short>));

  auto trt = kumi::builder<trivial_record_type<int, true>>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(trt)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                             kumi::field<kumi::name<"c">, short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(trt)>), (kumi::field<kumi::name<"a">, int>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(trt)>), (kumi::field<kumi::name<"b">, char>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(trt)>), (kumi::field<kumi::name<"c">, short>));
};

TTS_CASE("Check constexpr tuple_element of the output of builder")
{
  using namespace kumi::literals;

  constexpr auto rec = kumi::builder<kumi::record<>>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(rec)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                             kumi::field<kumi::name<"c">, short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rec)>), (kumi::field<kumi::name<"a">, int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rec)>), (kumi::field<kumi::name<"b">, char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rec)>), (kumi::field<kumi::name<"c">, short> const));

  constexpr auto rt = kumi::builder<record_box>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(rt)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                            kumi::field<kumi::name<"c">, short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (kumi::field<kumi::name<"a">, int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (kumi::field<kumi::name<"b">, char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (kumi::field<kumi::name<"c">, short> const));

  constexpr auto trt =
    kumi::builder<trivial_record_type<int, true>>::make("a"_id = 2, "b"_id = 'y', "c"_id = short{77});
  TTS_TYPE_IS((decltype(trt)), (kumi::record<kumi::field<kumi::name<"a">, int>, kumi::field<kumi::name<"b">, char>,
                                             kumi::field<kumi::name<"c">, short>> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(trt)>), (kumi::field<kumi::name<"a">, int> const));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(trt)>), (kumi::field<kumi::name<"b">, char> const));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(trt)>), (kumi::field<kumi::name<"c">, short> const));
};
