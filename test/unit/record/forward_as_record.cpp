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

using namespace kumi::literals;

enum class operations
{
  def_ctor,
  move_ctor,
  move_assign,
  copy_ctor,
  copy_assign
};

struct ctor_tracker
{
  operations value = operations::def_ctor;
  ctor_tracker()   = default;
  ctor_tracker(ctor_tracker &&) : value(operations::move_ctor) {}
  ctor_tracker(ctor_tracker const &) : value(operations::copy_ctor) {}
  ctor_tracker &operator=(ctor_tracker &&)
  {
    value = operations::move_assign;
    return *this;
  }
  ctor_tracker &operator=(ctor_tracker const &)
  {
    value = operations::copy_assign;
    return *this;
  }
};

TTS_CASE("Check tuple_element of kumi::forward_as_record")
{
  int         i {};
  float const f {};
  auto forwarded = kumi::forward_as_record("a"_f = 'z', "b"_f = ctor_tracker(), "c"_f = std::ref(i), "d"_f = std::cref(f));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(forwarded)>), (kumi::field_capture<"a", char &&>        ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(forwarded)>), (kumi::field_capture<"b", ctor_tracker &&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(forwarded)>), (kumi::field_capture<"c", int &>          ));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(forwarded)>), (kumi::field_capture<"d", float const &>  ));
};

template<kumi::record_type Tuple>
operations
move_ctor_fwd(Tuple &&t)
{
  ctor_tracker local = std::forward<Tuple>(t)["a"_f];
  return local.value;
}

template<kumi::record_type Tuple>
operations
copy_ctor_fwd(Tuple &&t)
{
  ctor_tracker local = t["b"_f];
  return local.value;
}

template<kumi::record_type Tuple>
operations
move_assign_fwd(Tuple &&t)
{
  ctor_tracker local;
  local = std::forward<Tuple>(t)["c"_f];
  return local.value;
}

template<kumi::record_type Tuple>
operations
copy_assign_fwd(Tuple &&t)
{
  ctor_tracker local;
  local = t["d"_f];
  return local.value;
}


TTS_CASE("Check usage of kumi::record via forward_as_tuple")
{
  TTS_EQUAL(move_ctor_fwd(kumi::forward_as_record("a"_f = ctor_tracker())), operations::move_ctor);
  TTS_EQUAL(copy_ctor_fwd(kumi::forward_as_record("b"_f = ctor_tracker())), operations::copy_ctor);
  TTS_EQUAL(move_assign_fwd(kumi::forward_as_record("c"_f = ctor_tracker())), operations::move_assign);
  TTS_EQUAL(copy_assign_fwd(kumi::forward_as_record("d"_f = ctor_tracker())), operations::copy_assign);
};
