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

using namespace kumi::literals;

TTS_CASE("Check tuple_element of kumi::forward_as_record")
{
  int i{};
  float const f{};
  auto forwarded = kumi::forward_as_record<"a", "b", "c", "d">('z', ctor_tracker(), i, f);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(forwarded)>), (kumi::field_capture<"a", char&&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(forwarded)>), (kumi::field_capture<"b", ctor_tracker&&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(forwarded)>), (kumi::field_capture<"c", int&>));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(forwarded)>), (kumi::field_capture<"d", float const&>));
};

TTS_CASE("Check usage of kumi::record via forward_as_tuple")
{
  TTS_EQUAL(move_ctor_fwd(kumi::forward_as_record<"a">(ctor_tracker())), operations::move_ctor);
  TTS_EQUAL(copy_ctor_fwd(kumi::forward_as_record<"b">(ctor_tracker())), operations::copy_ctor);
  TTS_EQUAL(move_assign_fwd(kumi::forward_as_record<"c">(ctor_tracker())), operations::move_assign);
  TTS_EQUAL(copy_assign_fwd(kumi::forward_as_record<"d">(ctor_tracker())), operations::copy_assign);
};
