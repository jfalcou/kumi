//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check tuple_element of kumi::forward_as_array")
{
  int i;
  auto forwarded = kumi::forward_as_array(i, i, i);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(forwarded)>), int&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(forwarded)>), int&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(forwarded)>), int&);

  int const ci{};
  auto const_forwarded = kumi::forward_as_array(ci, ci, ci);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(const_forwarded)>), int const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(const_forwarded)>), int const&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(const_forwarded)>), int const&);
};

TTS_CASE("Check usage of kumi::array via forward_as_array")
{
  TTS_EQUAL(move_ctor_fwd(kumi::forward_as_array(ctor_tracker())), operations::move_ctor);
  TTS_EQUAL(copy_ctor_fwd(kumi::forward_as_array(ctor_tracker())), operations::copy_ctor);
  TTS_EQUAL(move_assign_fwd(kumi::forward_as_array(ctor_tracker())), operations::move_assign);
  TTS_EQUAL(copy_assign_fwd(kumi::forward_as_array(ctor_tracker())), operations::copy_assign);
};
