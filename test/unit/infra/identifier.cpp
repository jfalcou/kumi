//==================================================================================================
/**
  RABERU - Fancy Parameters Library
  Copyright : RABERU Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
//==================================================================================================
#define TTS_MAIN
#include "test.hpp"
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

struct key
{
};

template<typename T> struct flag : kumi::identifier<T>
{
  using kumi::identifier<T>::operator=;
};

TTS_CASE("Check kumi::concepts::identifier concept")
{
  using namespace kumi::literals;

  // Direct type
  TTS_EXPECT(kumi::concepts::identifier<flag<key>>);
  TTS_EXPECT(kumi::concepts::identifier<kumi::identifier<key>>);
  TTS_EXPECT((kumi::concepts::identifier<kumi::identifier<key, kumi::only_t<double>>>));
  TTS_EXPECT((kumi::concepts::identifier<kumi::identifier<key, kumi::traits_check<small_type>>>));

  // Predefined identifier object
  TTS_EXPECT(kumi::concepts::identifier<decltype(custom_)>);
  TTS_EXPECT(kumi::concepts::identifier<decltype(coord_)>);

  // Type from polymorphic constructor
  TTS_EXPECT(kumi::concepts::identifier<decltype(kumi::identifier("any"_id))>);
  TTS_EXPECT(kumi::concepts::identifier<decltype(kumi::identifier("small"_id, kumi::if_<small_type>))>);
  TTS_EXPECT(kumi::concepts::identifier<decltype(kumi::identifier("real_value"_id, kumi::only<float>))>);
  TTS_EXPECT(kumi::concepts::identifier<decltype(kumi::identifier("modal"_id))>);

  // Type from literals
  TTS_EXPECT(kumi::concepts::identifier<decltype("any"_id)>);
  TTS_EXPECT(kumi::concepts::identifier<decltype("modal"_id)>);

  // Obviously wrong type
  TTS_EXPECT_NOT(kumi::concepts::identifier<float**>);
};

struct my_little_identifier : kumi::identifier<struct key, kumi::traits_check<small_type>>
{
  using parent = kumi::identifier<struct key, kumi::traits_check<small_type>>;
  using parent::operator=;
};

TTS_CASE("Check kumi::concepts::field concept")
{
  TTS_EXPECT((kumi::concepts::field<kumi::field<kumi::identifier<struct key>, int>>));
  TTS_EXPECT((kumi::concepts::field<kumi::field<my_little_identifier, int>>));
  TTS_EXPECT((kumi::concepts::field<decltype(flag<struct key>{} = std::bool_constant<true>{})>));
  TTS_EXPECT_NOT(kumi::concepts::field<float**>);
};
