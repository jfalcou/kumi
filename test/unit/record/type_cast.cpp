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
#include <functional>

using namespace kumi::literals;

struct from_type
{
  int value;

  from_type(int& i) : value{i} {}

  template<typename T, typename U> from_type(kumi::record<T, U>) : value{15} {}

  friend constexpr auto operator==(from_type const& a, from_type const& b) noexcept { return a.value == b.value; }
};

TTS_CASE("Check runtime kumi::type_cast behavior on records")
{
  int a = 15;
  from_type b{a};

  auto base = kumi::record{"a"_f = 1UL, "b"_f = short{55}, "c"_f = 12.5, "d"_f = 3.f, "e"_f = std::ref(a)};
  auto t1 = kumi::record{"a"_f = 1.f, "b"_f = 55.f, "c"_f = 12, "d"_f = 3, "e"_f = 15.f};
  auto t2 = kumi::record{"a"_f = 1, "b"_f = '7', "c"_f = 12, "d"_f = 3.f, "e"_f = b};

  auto base2 = kumi::record{"a"_f = 1, "b"_f = 3.f, "c"_f = 'x', "d"_f = kumi::record{"a"_f = 3.f, "b"_f = 3.f}};
  auto dest2 = kumi::record{"a"_f = 1, "b"_f = 3., "c"_f = 'x', "d"_f = b};

  TTS_EQUAL((kumi::type_cast<float, float, int, int, float>(base)), (t1));
  TTS_EQUAL((kumi::type_cast<int, char, int, float, from_type>(base)), (t2));
  TTS_EQUAL((kumi::type_cast<int, double, char, from_type>(base2)), (dest2));
};

TTS_CASE("Check runtime kumi::type_cast behavior on records")
{
  constexpr auto base = kumi::record{"a"_f = 1UL, "b"_f = short{55}, "c"_f = 12.5, "d"_f = 3.f};
  constexpr auto t1 = kumi::record{"a"_f = 1.f, "b"_f = 55.f, "c"_f = 12, "d"_f = 3};
  constexpr auto t2 = kumi::record{"a"_f = 1, "b"_f = '7', "c"_f = 12, "d"_f = 3.f};

  TTS_CONSTEXPR_EQUAL((kumi::type_cast<float, float, int, int>(base)), (t1));
  TTS_CONSTEXPR_EQUAL((kumi::type_cast<int, char, int, float>(base)), (t2));
};

TTS_CASE("Check result::type_cast behavior on records")
{
  using namespace kumi;
  using base = record<field_capture<"a", int>, field_capture<"b", char&&>, field_capture<"c", float>,
                      field_capture<"d", short const>, field_capture<"e", long&>>;
  using t1 = record<field_capture<"a", double>, field_capture<"b", double>, field_capture<"c", double const>,
                    field_capture<"d", double>, field_capture<"e", double>>;
  using t2 = record<field_capture<"a", char const>, field_capture<"b", char const>, field_capture<"c", char const>,
                    field_capture<"d", char const>, field_capture<"e", char const>>;

  TTS_TYPE_IS((kumi::result::type_cast_t<base, double, double, double const, double, double>), (t1));
  TTS_TYPE_IS((kumi::result::type_cast_t<base, char const, char const, char const, char const, char const>), (t2));
};
