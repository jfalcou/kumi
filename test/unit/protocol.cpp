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

TTS_CASE("Check adapted types model kumi::product_type concept")
{
  TTS_EXPECT    ( kumi::product_type<tuple_box>      );
  TTS_EXPECT    ( kumi::product_type<record_box>   );

  TTS_EXPECT_NOT( kumi::record_type<tuple_box> );
  TTS_EXPECT    ( kumi::record_type<record_box> );
};

TTS_CASE("Check get methods on adapted types")
{
  tuple_box tb  = {1, 3.f, 'x'};
  record_box rb = {1, 3.f, 'x'};

  TTS_EQUAL(( get<0>(tb) ), 1);
  TTS_EQUAL(( get<1>(tb) ), 3.f);
  TTS_EQUAL(( get<2>(tb) ), 'x');

  TTS_EXPECT_NOT_COMPILES(tb, { get<"i">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"f">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"c">(tb); });

  TTS_EQUAL((kumi::get<int  >(tb)), 1 );
  TTS_EQUAL((kumi::get<float>(tb)), 3.f);
  TTS_EQUAL((kumi::get<char >(tb)), 'x');

  TTS_EQUAL(( get<0>(rb).value ), (  1  ));
  TTS_EQUAL(( get<1>(rb).value ), ( 3.f ));
  TTS_EQUAL(( get<2>(rb).value ), ( 'x' ));

  TTS_EQUAL(( kumi::get<"i">(rb)), ( 1));
  TTS_EQUAL(( kumi::get<"f">(rb)), (3.f));
  TTS_EQUAL(( kumi::get<"c">(rb)), ('x'));
};

TTS_CASE("Check get return type on adapted types")
{
  tuple_box tb  = {1, 3.f, 'x'};
  record_box rb = {1, 3.f, 'x'};

  const tuple_box ctb   = {1, 3.f, 'x'};
  const record_box crb  = {1, 3.f, 'x'};

  TTS_TYPE_IS(( decltype(get<0>(tb)) ), ( int   & ));
  TTS_TYPE_IS(( decltype(get<1>(tb)) ), ( float & ));
  TTS_TYPE_IS(( decltype(get<2>(tb)) ), ( char  & ));

  TTS_TYPE_IS(( decltype(get<0>(rb)) ), ( kumi::field_capture<"i", int  &> ));
  TTS_TYPE_IS(( decltype(get<1>(rb)) ), ( kumi::field_capture<"f", float&> ));
  TTS_TYPE_IS(( decltype(get<2>(rb)) ), ( kumi::field_capture<"c", char &> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<int  >(tb))), ( int   & ));
  TTS_TYPE_IS(( decltype(kumi::get<float>(tb))), ( float & ));
  TTS_TYPE_IS(( decltype(kumi::get<char >(tb))), ( char  & ));

  TTS_TYPE_IS(( decltype(kumi::get<"i">(rb)) ), ( int   & ));
  TTS_TYPE_IS(( decltype(kumi::get<"f">(rb)) ), ( float & ));
  TTS_TYPE_IS(( decltype(kumi::get<"c">(rb)) ), ( char  & ));

  TTS_TYPE_IS(( decltype(get<0>(ctb)) ), ( int    const& ));
  TTS_TYPE_IS(( decltype(get<1>(ctb)) ), ( float  const& ));
  TTS_TYPE_IS(( decltype(get<2>(ctb)) ), ( char   const& ));

  TTS_TYPE_IS(( decltype(get<0>(crb)) ), ( kumi::field_capture<"i", int   const&> ));
  TTS_TYPE_IS(( decltype(get<1>(crb)) ), ( kumi::field_capture<"f", float const&> ));
  TTS_TYPE_IS(( decltype(get<2>(crb)) ), ( kumi::field_capture<"c", char  const&> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<int  >(ctb))), ( int   const& ));
  TTS_TYPE_IS(( decltype(kumi::get<float>(ctb))), ( float const& ));
  TTS_TYPE_IS(( decltype(kumi::get<char >(ctb))), ( char  const& ));

  TTS_TYPE_IS(( decltype(kumi::get<"i">(crb)) ), ( int    const& ));
  TTS_TYPE_IS(( decltype(kumi::get<"f">(crb)) ), ( float  const& ));
  TTS_TYPE_IS(( decltype(kumi::get<"c">(crb)) ), ( char   const& ));
};
