//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi.hpp>
#include <tts/tts.hpp>
#include <tuple>

template<typename... T>
struct kumi::is_product_type<std::tuple<T...>> : std::true_type {};

// --
// -- Make a pre adapted type
// --
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

// --

TTS_CASE("Check as_tuple behavior")
{
  TTS_TYPE_IS( (kumi::as_tuple_t<kumi::tuple<int,char>>), (kumi::tuple<int,char>));
  TTS_TYPE_IS( (kumi::as_tuple_t<std::tuple<int,char>>) , (kumi::tuple<int,char>));
  TTS_TYPE_IS( (kumi::as_tuple_t<some_box>) , (kumi::tuple<int,float,char>));
};

TTS_CASE("Check as_tuple behavior with traits")
{
  TTS_TYPE_IS( (kumi::as_tuple_t<kumi::tuple<int,char>, std::add_pointer>), (kumi::tuple<int*,char*>));
  TTS_TYPE_IS( (kumi::as_tuple_t<std::tuple<int,char>, std::add_pointer>) , (kumi::tuple<int*,char*>));
  TTS_TYPE_IS( (kumi::as_tuple_t<some_box, std::add_pointer>) , (kumi::tuple<int*,float*,char*>));
};
