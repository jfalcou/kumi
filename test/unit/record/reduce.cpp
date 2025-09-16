//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <vector>


TTS_CASE("Check result::prod/sum/bit_* behavior")
{
  using char_f      = kumi::field_capture<"a", char>;
  using short_f     = kumi::field_capture<"b", short>;
  using int_f       = kumi::field_capture<"c", int>;
  using double_f    = kumi::field_capture<"d", double>;
  using size_t_f    = kumi::field_capture<"e", std::size_t>;

  TTS_TYPE_IS ( (kumi::result::sum_t<kumi::record<char_f,short_f,int_f,double_f>,int>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::prod_t<kumi::record<char_f,short_f,int_f,double_f>,int>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::bit_or_t<kumi::record<short_f,size_t_f,int_f>,char>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::bit_and_t<kumi::record<short_f,size_t_f,int_f>,char>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::sum_t<kumi::record<char_f,short_f,int_f,double_f>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::prod_t<kumi::record<char_f,short_f,int_f,double_f>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::bit_or_t<kumi::record<short_f,size_t_f,int_f>>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::bit_and_t<kumi::record<short_f,size_t_f,int_f>>)
              , std::size_t
              );
};


TTS_CASE("Check record::sum behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}, "d"_f = 'z'};

  TTS_EQUAL(kumi::sum(kumi::record{}, 42),  42 );
  TTS_EQUAL(kumi::sum(t, 0)             , 180 );

  TTS_CONSTEXPR_EQUAL(kumi::sum(kumi::record{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::sum(t, 0)             , 180 );
  TTS_CONSTEXPR_EQUAL(kumi::sum(t)                , 180 );
};

TTS_CASE("Check record::prod behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record {"a"_f = 2., "b"_f = 3, "c"_f = short {5}, "d"_f = '\a'};

  TTS_EQUAL(kumi::prod(kumi::record{}, 42),  42 );
  TTS_EQUAL(kumi::prod(t, 1)             , 210 );

  TTS_CONSTEXPR_EQUAL(kumi::prod(kumi::record{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::prod(t, 1)             , 210 );
  TTS_CONSTEXPR_EQUAL(kumi::prod(t)                , 210 );
};

TTS_CASE("Check record::bit_and behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record {"a"_f = 14UL, "b"_f = char{7}, "c"_f = short{6}};

  TTS_EQUAL(kumi::bit_and(kumi::record{}, 42),  42 );
  TTS_EQUAL(kumi::bit_and(t, 255)           , 6UL );

  TTS_CONSTEXPR_EQUAL(kumi::bit_and(kumi::record{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::bit_and(t, 255)           , 6UL );
  TTS_CONSTEXPR_EQUAL(kumi::bit_and(t)                , 6UL );
};

TTS_CASE("Check record::bit_or behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record {"a"_f = 2UL, "b"_f = 3, "c"_f = short {5}, "d"_f = char{64}};

  TTS_EQUAL(kumi::bit_or(kumi::record{}, 42),  42  );
  TTS_EQUAL(kumi::bit_or(t, 1)             , 71UL );

  TTS_CONSTEXPR_EQUAL(kumi::bit_or(kumi::record{}, 42),  42  );
  TTS_CONSTEXPR_EQUAL(kumi::bit_or(t, 1)             , 71UL );
  TTS_CONSTEXPR_EQUAL(kumi::bit_or(t)                , 71UL );
};