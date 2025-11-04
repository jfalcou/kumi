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
// --
// -- Make a pre adapted product_type
// --
struct tuple_box
{
  using is_product_type = void;

  int     i;
  double  f;
  char    c;

  template<std::size_t I>
  friend constexpr auto const& get(tuple_box const& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }

  template<std::size_t I>
  friend  constexpr auto & get(tuple_box& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }
};

template<> struct std::tuple_size<tuple_box> : std::integral_constant<std::size_t,3> {};
template<> struct std::tuple_element<0,tuple_box> { using type = int;    };
template<> struct std::tuple_element<1,tuple_box> { using type = double; };
template<> struct std::tuple_element<2,tuple_box> { using type = char;   };

// --
// -- Make a pre adapted record_type
// --
struct record_box
{
  using is_product_type = void;
  using is_record_type  = void;

  int     i;
  double  f;
  char    c;

  template<std::size_t I>
  friend constexpr decltype(auto) get(record_box const& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return kumi::capture_field<"i"> ( s.i );
    if constexpr(I==1) return kumi::capture_field<"f"> ( s.f );
    if constexpr(I==2) return kumi::capture_field<"c"> ( s.c );
  }

  template<std::size_t I>
  friend constexpr decltype(auto) get(record_box& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return kumi::capture_field<"i"> ( s.i );
    if constexpr(I==1) return kumi::capture_field<"f"> ( s.f );
    if constexpr(I==2) return kumi::capture_field<"c"> ( s.c );
  }
};

template<> struct std::tuple_size<record_box> : std::integral_constant<std::size_t,3> {};
template<> struct std::tuple_element<0,record_box> { using type = kumi::field_capture<"i", int   >; };
template<> struct std::tuple_element<1,record_box> { using type = kumi::field_capture<"f", double>; };
template<> struct std::tuple_element<2,record_box> { using type = kumi::field_capture<"c", char  >; };

TTS_CASE("Check adapted types model kumi::product_type concept")
{
  TTS_EXPECT    ( kumi::product_type<tuple_box>      );
  TTS_EXPECT    ( kumi::product_type<record_box>   );

  TTS_EXPECT_NOT( kumi::record_type<tuple_box> );
  TTS_EXPECT    ( kumi::record_type<record_box> );
};

TTS_CASE("Check get methods on adapted types")
{
  tuple_box tb = {1, 3.f, 'x'};
  record_box rb = {1, 3.f, 'x'};

  TTS_EQUAL(( get<0>(tb) ), 1);
  TTS_EQUAL(( get<1>(tb) ), 3.f);
  TTS_EQUAL(( get<2>(tb) ), 'x');

  TTS_EXPECT_NOT_COMPILES(tb, { get<"i">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"f">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"c">(tb); });

  TTS_EQUAL((kumi::get<int     >(tb)), 1 );
  TTS_EQUAL((kumi::get<double  >(tb)), 3.f);
  TTS_EQUAL((kumi::get<char    >(tb)), 'x');

  TTS_EQUAL(( get<0>(rb).value ), (  1  ));
  TTS_EQUAL(( get<1>(rb).value ), ( 3.f ));
  TTS_EQUAL(( get<2>(rb).value ), ( 'x' ));

  TTS_EQUAL(( kumi::get<kumi::field_capture<"i",int   >>(rb).value ), (  1  ));
  TTS_EQUAL(( kumi::get<kumi::field_capture<"f",double>>(rb).value ), ( 3.f ));
  TTS_EQUAL(( kumi::get<kumi::field_capture<"c",char  >>(rb).value ), ( 'x' ));

  TTS_EQUAL(( kumi::get<"i">(rb)), ( 1));
  TTS_EQUAL(( kumi::get<"f">(rb)), (3.f));
  TTS_EQUAL(( kumi::get<"c">(rb)), ('x'));
};

TTS_CASE("Check get return type on adapted types")
{
  tuple_box tb = {1, 3.f, 'x'};
  record_box rb = {1, 3.f, 'x'};

  const tuple_box ctb = {1, 3.f, 'x'};
  const record_box crb = {1, 3.f, 'x'};

  TTS_TYPE_IS(( decltype(get<0>(tb)) ), ( int   & ));
  TTS_TYPE_IS(( decltype(get<1>(tb)) ), ( double& ));
  TTS_TYPE_IS(( decltype(get<2>(tb)) ), ( char  & ));

  TTS_TYPE_IS(( decltype(get<0>(rb)) ), ( kumi::field_capture<"i", int     &> ));
  TTS_TYPE_IS(( decltype(get<1>(rb)) ), ( kumi::field_capture<"f", double  &> ));
  TTS_TYPE_IS(( decltype(get<2>(rb)) ), ( kumi::field_capture<"c", char    &> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<int     >(tb))), ( int   &   ));
  TTS_TYPE_IS(( decltype(kumi::get<double  >(tb))), ( double&   ));
  TTS_TYPE_IS(( decltype(kumi::get<char    >(tb))), ( char  &   ));

  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"i", int   >>(rb)) ), ( kumi::field_capture<"i", int     &> ));
  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"f", double>>(rb)) ), ( kumi::field_capture<"f", double  &> ));
  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"c", char  >>(rb)) ), ( kumi::field_capture<"c", char    &> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<"i">(rb)) ), ( int   & ));
  TTS_TYPE_IS(( decltype(kumi::get<"f">(rb)) ), ( double& ));
  TTS_TYPE_IS(( decltype(kumi::get<"c">(rb)) ), ( char  & ));

  TTS_TYPE_IS(( decltype(get<0>(ctb)) ), ( int    const& ));
  TTS_TYPE_IS(( decltype(get<1>(ctb)) ), ( double const& ));
  TTS_TYPE_IS(( decltype(get<2>(ctb)) ), ( char   const& ));

  TTS_TYPE_IS(( decltype(get<0>(crb)) ), ( kumi::field_capture<"i", int     const&> ));
  TTS_TYPE_IS(( decltype(get<1>(crb)) ), ( kumi::field_capture<"f", double  const&> ));
  TTS_TYPE_IS(( decltype(get<2>(crb)) ), ( kumi::field_capture<"c", char    const&> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<int     >(ctb))), ( int    const&   ));
  TTS_TYPE_IS(( decltype(kumi::get<double  >(ctb))), ( double const&   ));
  TTS_TYPE_IS(( decltype(kumi::get<char    >(ctb))), ( char   const&   ));

  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"i", int   >>(crb)) ), ( kumi::field_capture<"i", int     const&> ));
  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"f", double>>(crb)) ), ( kumi::field_capture<"f", double  const&> ));
  TTS_TYPE_IS(( decltype(kumi::get<kumi::field_capture<"c", char  >>(crb)) ), ( kumi::field_capture<"c", char    const&> ));
  
  TTS_TYPE_IS(( decltype(kumi::get<"i">(crb)) ), ( int    const& ));
  TTS_TYPE_IS(( decltype(kumi::get<"f">(crb)) ), ( double const& ));
  TTS_TYPE_IS(( decltype(kumi::get<"c">(crb)) ), ( char   const& ));

};
