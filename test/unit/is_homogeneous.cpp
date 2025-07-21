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
#include <array>
#include <concepts>

TTS_CASE("Check is_homogeneous for kumi::tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT( kumi::tuple<>::is_homogeneous                     );
  TTS_CONSTEXPR_EXPECT    ( kumi::tuple<int>::is_homogeneous                  );
  TTS_CONSTEXPR_EXPECT    ((kumi::tuple<int,int>::is_homogeneous             ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int,float>::is_homogeneous           ));
  TTS_CONSTEXPR_EXPECT    ((kumi::tuple<int,int,int>::is_homogeneous         ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int,float,int>::is_homogeneous       ));
  TTS_CONSTEXPR_EXPECT    ((kumi::tuple<int,int,int,int>::is_homogeneous     ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int,float,int,int>::is_homogeneous   ));

  TTS_CONSTEXPR_EXPECT_NOT( kumi::homogeneous_product_type<kumi::tuple<>>                    );
  TTS_CONSTEXPR_EXPECT    ( kumi::homogeneous_product_type<kumi::tuple<int>>                 );
  TTS_CONSTEXPR_EXPECT    ( kumi::homogeneous_product_type<kumi::tuple<int>>                 );
  TTS_CONSTEXPR_EXPECT    ((kumi::homogeneous_product_type<kumi::tuple<int,int>>            ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int,float>>          ));
  TTS_CONSTEXPR_EXPECT    ((kumi::homogeneous_product_type<kumi::tuple<int,int,int>>        ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int,float,int>>      ));
  TTS_CONSTEXPR_EXPECT    ((kumi::homogeneous_product_type<kumi::tuple<int,int,int,int>>    ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int,float,int,int>>  ));
};

template<typename T, bool isHomogeneous>
struct trivial_product_type : kumi::tuple<T,T,T,T,T>
{};

template<typename T>
struct trivial_product_type<T,false> : kumi::tuple<T,T,T,T,void*>
{};

template<typename T, bool B>
struct std::tuple_size<trivial_product_type<T,B>> : std::integral_constant<std::size_t,5>
{};

template<std::size_t N, typename T, bool B>
struct std::tuple_element<N,trivial_product_type<T,B>> { using type = T; };

template<typename T>
struct std::tuple_element<4,trivial_product_type<T,false>> { using type = void*; };

TTS_CASE("Check is_homogeneous for kumi::tuple derived types")
{
  TTS_CONSTEXPR_EXPECT((trivial_product_type<int,true>::is_homogeneous                ));
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<trivial_product_type<int,true>>));

  TTS_CONSTEXPR_EXPECT_NOT((trivial_product_type<int,false>::is_homogeneous                ));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<trivial_product_type<int,false>>));
};

struct some_box
{
  using is_product_type = void;

  int i;
  float f;
  char c;

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
template<> struct std::tuple_element<0,some_box> { using type = int;   };
template<> struct std::tuple_element<1,some_box> { using type = float; };
template<> struct std::tuple_element<2,some_box> { using type = char;  };

TTS_CASE("Check is_homogeneous for kumi::product_type adapted types")
{
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<std::array<int,7>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<some_box>));
};
