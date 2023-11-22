//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>


// --
// -- Make a pre adapted type
// --
struct some_box
{
  using is_product_type = void;

  int     i;
  double  f;
  char    c;

  template<std::size_t I>
  friend constexpr auto const& get(some_box const& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }

  template<std::size_t I>
  friend  constexpr auto & get(some_box& s) noexcept requires(I < 3)
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }
};

template<> struct std::tuple_size<some_box> : std::integral_constant<std::size_t,3> {};
template<> struct std::tuple_element<0,some_box> { using type = int;    };
template<> struct std::tuple_element<1,some_box> { using type = double; };
template<> struct std::tuple_element<2,some_box> { using type = char;   };

// --

TTS_CASE("Check adapted types model kumi::product_type concept")
{
  TTS_EXPECT    ( kumi::product_type<some_box>              );
  TTS_EXPECT    ( (kumi::product_type<std::array<int,4>>   ));
  TTS_EXPECT_NOT( (kumi::product_type<std::pair<int,float>>));
};

TTS_CASE("Check adapted type behave like a product_type")
{
  auto r = kumi::apply( [](auto... x) { return (x + ...); }, some_box{1,2.5,'4'});
  TTS_EQUAL(r, 55.5);

  auto zz = kumi::zip( some_box{1,2.5,'4'}, some_box{99,69.25,'Z'});
  TTS_EQUAL ( zz, ( kumi::tuple { kumi::tuple{1   , 99    }
                                , kumi::tuple{2.5 , 69.25 }
                                , kumi::tuple{'4' ,'Z'    }
                                })
            );

  auto cc = kumi::cat( some_box{1,2.5,'4'}, some_box{99,69.25,'Z'});
  TTS_EQUAL ( cc, ( kumi::tuple {1, 2.5, '4', 99, 69.25, 'Z'}) );
};

TTS_CASE("Check adapted external type behave like a product_type")
{
  auto r = kumi::apply( [](auto... x) { return (x + ...); }, std::array{1,2,5,4});
  TTS_EQUAL(r, 12);

  auto zz = kumi::zip( std::array{1,2,5}, std::array{0.1,2.3,4.5});
  TTS_EQUAL ( zz, ( kumi::tuple { kumi::tuple{1 , 0.1 }
                                , kumi::tuple{2 , 2.3 }
                                , kumi::tuple{5 , 4.5 }
                                })
            );

  auto cc = kumi::cat( std::array{1,2,5}, std::array{0.1,2.3,4.5} );
  TTS_EQUAL ( cc, ( kumi::tuple {1, 2, 5, 0.1, 2.3, 4.5}) );
};
