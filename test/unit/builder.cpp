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

using kt = kumi::tuple<int, float*, char&, const double>;

namespace udt 
{
    struct point_2D 
    {
        using is_product_type = void;
        kumi::str name; int x; int y; float t;
         
        template<std::size_t I>
        friend constexpr auto const& get(point_2D const& s) noexcept requires(I < 4)
        {
          if constexpr(I==0) return s.name;
          if constexpr(I==1) return s.x;
          if constexpr(I==2) return s.y;
          if constexpr(I==3) return s.t;
        }

        template<std::size_t I>
        friend  constexpr auto & get(point_2D& s) noexcept requires(I < 4)
        {
          if constexpr(I==0) return s.name;
          if constexpr(I==1) return s.x;
          if constexpr(I==2) return s.y;
          if constexpr(I==3) return s.t;
        }
    };
}

template<> struct std::tuple_size<udt::point_2D> : std::integral_constant<std::size_t,4> {};
template<> struct std::tuple_element<0,udt::point_2D> { using type = kumi::str;   };
template<> struct std::tuple_element<1,udt::point_2D> { using type = int;           };
template<> struct std::tuple_element<2,udt::point_2D> { using type = int;           };
template<> struct std::tuple_element<3,udt::point_2D> { using type = float;         };

TTS_CASE("Check tuple_element of the output of result::builder_make_t")
{
  using namespace kumi::literals;

  using tpl = kumi::_::builder_make_t<kumi::tuple<double, float, char, int>, const char, double& ,float>; 
  TTS_TYPE_IS(tpl, (kumi::tuple<const char, double&, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, tpl>), const char);
  TTS_TYPE_IS((std::tuple_element_t<1, tpl>), double&);
  TTS_TYPE_IS((std::tuple_element_t<2, tpl>), float);

  using arr = kumi::_::builder_make_t<std::array<int, 5>, int, int, int, int, int>; 
  TTS_TYPE_IS(arr, (kumi::tuple<int, int, int, int, int>));
  TTS_TYPE_IS((std::tuple_element_t<0, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, arr>), int);

  using pt = kumi::_::builder_make_t<udt::point_2D, int&, const char*, double>; 
  TTS_TYPE_IS(pt, (kumi::tuple<int&, const char*, double>));
  TTS_TYPE_IS((std::tuple_element_t<0, pt>), int&);
  TTS_TYPE_IS((std::tuple_element_t<1, pt>), const char*);
  TTS_TYPE_IS((std::tuple_element_t<2, pt>), double);

  using rt = kumi::_::builder_make_t<kumi::record<>, kumi::field_capture<"a", const float>, kumi::field_capture<"b", int&>>; 
  TTS_TYPE_IS(rt, (kumi::record<kumi::field_capture<"a", const float>, kumi::field_capture<"b", int&>>));
  TTS_TYPE_IS((std::tuple_element_t<0, rt>), (kumi::field_capture<"a", const float>));
  TTS_TYPE_IS((std::tuple_element_t<1, rt>), (kumi::field_capture<"b", int&>));
};

TTS_CASE("Check tuple_element of the output of builder")
{
  using namespace kumi::literals;

  auto tpl = kumi::_::builder<kumi::tuple<char, float>>::make('1', 2., 3.f);
  TTS_TYPE_IS((decltype(tpl)), (kumi::tuple<char, double, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpl)>), char);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpl)>), double);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpl)>), float);

  auto arr = kumi::_::builder<std::array<int, 5>>::make(1,2,3,4,5);
  TTS_TYPE_IS((decltype(arr)), (kumi::tuple<int, int, int, int, int>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(arr)>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(arr)>), int);

  auto pt = kumi::_::builder<udt::point_2D>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(pt)), (kumi::tuple<kumi::str, int, int, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(pt)>), kumi::str);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(pt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(pt)>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(pt)>), float);

  auto rt = kumi::_::builder<kumi::record<>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS((decltype(rt)), (kumi::record< kumi::field_capture<"a", int>, kumi::field_capture<"b", char>
                                           , kumi::field_capture<"c", short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (kumi::field_capture<"a", int>   ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (kumi::field_capture<"b", char>  ));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (kumi::field_capture<"c", short> ));

  auto nt = kumi::_::builder<kumi::tuple<>>::make(kumi::tuple{1});
  TTS_TYPE_IS((decltype(nt)), (kumi::tuple<kumi::tuple<int>>));

  auto ft = kumi::_::builder<kumi::tuple<>>::build(kumi::tuple{1});
  TTS_TYPE_IS((decltype(ft)), (kumi::tuple<int>));
};

TTS_CASE("Check constexpr tuple_element of the output of builder")
{
  using namespace kumi::literals;

  constexpr auto tpl = kumi::_::builder<kumi::tuple<char, float>>::make('1', 2., 3.f);
  TTS_TYPE_IS((decltype(tpl)), (const kumi::tuple<char, double, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tpl)>), const char);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tpl)>), const double);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tpl)>), const float);

  constexpr auto arr = kumi::_::builder<std::array<int, 5>>::make(1,2,3,4,5);
  TTS_TYPE_IS((decltype(arr)), (const kumi::tuple<int, int, int, int, int>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(arr)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(arr)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(arr)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(arr)>), const int);

  constexpr auto pt = kumi::_::builder<udt::point_2D>::make(kumi::str{"Cain"}, 1, 2, 3.0f);
  TTS_TYPE_IS((decltype(pt)), (const kumi::tuple<kumi::str, int, int, float>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(pt)>), const kumi::str);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(pt)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(pt)>), const int);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(pt)>), const float);

  constexpr auto rt = kumi::_::builder<kumi::record<>>::make("a"_f = 2, "b"_f = 'y', "c"_f = short{77});
  TTS_TYPE_IS((decltype(rt)), (const kumi::record< kumi::field_capture<"a", int>, kumi::field_capture<"b", char>
                                           , kumi::field_capture<"c", short>>));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rt)>), (const kumi::field_capture<"a", int>   ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rt)>), (const kumi::field_capture<"b", char>  ));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(rt)>), (const kumi::field_capture<"c", short> ));

  constexpr auto nt = kumi::_::builder<kumi::tuple<>>::make(kumi::tuple{1});
  TTS_TYPE_IS((decltype(nt)), (const kumi::tuple<kumi::tuple<int>>));

  constexpr auto ft = kumi::_::builder<kumi::tuple<>>::build(kumi::tuple{1});
  TTS_TYPE_IS((decltype(ft)), (const kumi::tuple<int>));
};
