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
#include <type_traits>

TTS_CASE("kumi predicates runtime behavior on tuples")
{
  auto yay_values = kumi::make_tuple(1, 2.5, -3.6f, 4ULL);
  auto nay_values = kumi::make_tuple(1, 12.5, 3.6f, 4ULL);

  auto yay_types = kumi::make_tuple(1, 8.5, 3.6f, 4ULL);
  auto nay_types = kumi::make_tuple(1, (int*)(nullptr), 3.6f, 4ULL);

  TTS_EXPECT(kumi::all_of(yay_values, [](auto e) { return e < 5; }));
  TTS_EXPECT(kumi::any_of(yay_values, [](auto e) { return e < 0; }));
  TTS_EXPECT(kumi::none_of(yay_values, [](auto e) { return e > 12; }));
  TTS_EQUAL (kumi::count_if(yay_values, [](auto e) { return e < 0; }), 1ULL);
  TTS_EQUAL (kumi::count(yay_values), yay_values.size());

  TTS_EXPECT_NOT(kumi::all_of(nay_values, [](auto e) { return e < 5; }));
  TTS_EXPECT_NOT(kumi::any_of(nay_values, [](auto e) { return e < 0; }));
  TTS_EXPECT_NOT(kumi::none_of(nay_values, [](auto e) { return e > 12; }));

  TTS_EXPECT(kumi::all_of(yay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::any_of(nay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::none_of(yay_types, kumi::predicate<std::is_pointer>()));
  TTS_EQUAL (kumi::count_if(yay_types, kumi::predicate<std::is_integral>()), 2ULL);

  TTS_EXPECT_NOT(kumi::all_of(nay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT_NOT(kumi::any_of(nay_types, kumi::predicate<std::is_lvalue_reference>()));
  TTS_EXPECT_NOT(kumi::none_of(yay_types, kumi::predicate<std::is_arithmetic>()));
};

TTS_CASE("kumi predicates constexpr behavior on tuples")
{
  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::make_tuple(1, 2.5, -3.6f, 4ULL), [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::make_tuple(1, 2.5, -3.6f, 4ULL), [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::make_tuple(1, 2.5, -3.6f, 4ULL), [](auto e) { return e > 12; }));
  TTS_CONSTEXPR_EQUAL (kumi::count_if(kumi::make_tuple(1, 2.5, -3.6f, 4ULL), [](auto e) { return e < 0; }), 1ULL);
  TTS_CONSTEXPR_EQUAL (kumi::count(kumi::make_tuple(1, 2.5, -3.6f, 4ULL)), 4ULL);

  TTS_CONSTEXPR_EXPECT_NOT(kumi::all_of(kumi::make_tuple(1, 12.5, 3.6f, 4ULL), [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::any_of(kumi::make_tuple(1, 12.5, 3.6f, 4ULL), [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::make_tuple(1, 12.5, 3.6f, 4ULL), [](auto e) { return e > 12; }));

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::make_tuple(1, 8.5, 3.6f, 4ULL), kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::make_tuple(1, (int*)(nullptr), 3.6f, 4ULL), kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::make_tuple(1, 8.5, 3.6f, 4ULL), kumi::predicate<std::is_pointer>()));
  TTS_CONSTEXPR_EQUAL (kumi::count_if(kumi::make_tuple(1, 8.5, 3.6f, 4ULL), kumi::predicate<std::is_integral>()), 2ULL);

  TTS_CONSTEXPR_EXPECT_NOT(kumi::all_of(kumi::make_tuple(1, (int*)(nullptr), 3.6f, 4ULL), kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::any_of(kumi::make_tuple(1, (int*)(nullptr), 3.6f, 4ULL), kumi::predicate<std::is_lvalue_reference>()));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::make_tuple(1, 8.5, 3.6f, 4ULL), kumi::predicate<std::is_arithmetic>()));
};

TTS_CASE("kumi predicates behavior on non-tuples")
{
  TTS_EXPECT(kumi::all_of(4.5, [](auto e) { return e < 5; }));
  TTS_EXPECT(kumi::any_of(4.5f, [](auto e) { return e > 2; }));
  TTS_EXPECT(kumi::none_of(45, [](auto e) { return e > 100; }));
  TTS_EQUAL (kumi::count_if('4', [](auto e) { return e != 'A'; }), 1ULL);
  TTS_EQUAL (kumi::count(4), 1ULL);

  TTS_CONSTEXPR_EXPECT(kumi::all_of(4.5, [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(4.5f, [](auto e) { return e > 2; }));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(45, [](auto e) { return e > 100; }));
  TTS_CONSTEXPR_EQUAL (kumi::count_if('4', [](auto e) { return e != 'A'; }), 1ULL);
  TTS_CONSTEXPR_EQUAL (kumi::count(4), 1ULL);
};
