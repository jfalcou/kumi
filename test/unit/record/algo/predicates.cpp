//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <type_traits>

TTS_CASE("kumi predicates runtime behavior on records")
{
  using namespace kumi::literals;

  auto yay_values = kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL);
  auto nay_values = kumi::make_record("a"_id = 1, "b"_id = 12.5, "c"_id = 3.6f, "d"_id = 4ULL);

  auto yay_types = kumi::make_record("a"_id = 1, "b"_id = 8.5, "c"_id = 3.6f, "d"_id = 4ULL);
  auto nay_types = kumi::make_record("a"_id = 1, "b"_id = (int*)(nullptr), "c"_id = 3.6f, "d"_id = 4ULL);

  TTS_EXPECT(kumi::all_of(yay_values));
  TTS_EXPECT(kumi::any_of(yay_values));
  TTS_EXPECT_NOT(kumi::none_of(yay_values));

  TTS_EXPECT(kumi::all_of(yay_values, [](auto e) { return e < 5; }));
  TTS_EXPECT(kumi::any_of(yay_values, [](auto e) { return e < 0; }));
  TTS_EXPECT(kumi::none_of(yay_values, [](auto e) { return e > 12; }));
  TTS_EQUAL(kumi::count_if(yay_values, [](auto e) { return e < 0; }), 1ULL);
  TTS_EQUAL(kumi::count(yay_values), yay_values.size());

  TTS_EXPECT_NOT(kumi::all_of(nay_values, [](auto e) { return e < 5; }));
  TTS_EXPECT_NOT(kumi::any_of(nay_values, [](auto e) { return e < 0; }));
  TTS_EXPECT_NOT(kumi::none_of(nay_values, [](auto e) { return e > 12; }));

  TTS_EXPECT(kumi::all_of(yay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::any_of(nay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::none_of(yay_types, kumi::predicate<std::is_pointer>()));
  TTS_EQUAL(kumi::count_if(yay_types, kumi::predicate<std::is_integral>()), 2ULL);

  TTS_EXPECT_NOT(kumi::all_of(nay_types, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT_NOT(kumi::any_of(nay_types, kumi::predicate<std::is_lvalue_reference>()));
  TTS_EXPECT_NOT(kumi::none_of(yay_types, kumi::predicate<std::is_arithmetic>()));
};

TTS_CASE("kumi predicates constexpr behavior on records")
{
  using namespace kumi::literals;

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL),
                                    [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL),
                                    [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL),
                                     [](auto e) { return e > 12; }));
  TTS_CONSTEXPR_EQUAL(kumi::count_if(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL),
                                     [](auto e) { return e < 0; }),
                      1ULL);
  TTS_CONSTEXPR_EQUAL(kumi::count(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL)), 4ULL);

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL)));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL)));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::make_record("a"_id = 1, "b"_id = 2.5, "c"_id = -3.6f, "d"_id = 4ULL)));

  TTS_CONSTEXPR_EXPECT_NOT(kumi::all_of(kumi::make_record("a"_id = 1, "b"_id = 12.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                        [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::any_of(kumi::make_record("a"_id = 1, "b"_id = 12.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                        [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::make_record("a"_id = 1, "b"_id = 12.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                         [](auto e) { return e > 12; }));

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::make_record("a"_id = 1, "b"_id = 8.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                    kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(
    kumi::any_of(kumi::make_record("a"_id = 1, "b"_id = (int*)(nullptr), "c"_id = 3.6f, "d"_id = 4ULL),
                 kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::make_record("a"_id = 1, "b"_id = 8.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                     kumi::predicate<std::is_pointer>()));
  TTS_CONSTEXPR_EQUAL(kumi::count_if(kumi::make_record("a"_id = 1, "b"_id = 8.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                     kumi::predicate<std::is_integral>()),
                      2ULL);

  TTS_CONSTEXPR_EXPECT_NOT(
    kumi::all_of(kumi::make_record("a"_id = 1, "b"_id = (int*)(nullptr), "c"_id = 3.6f, "d"_id = 4ULL),
                 kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT_NOT(
    kumi::any_of(kumi::make_record("a"_id = 1, "b"_id = (int*)(nullptr), "c"_id = 3.6f, "d"_id = 4ULL),
                 kumi::predicate<std::is_lvalue_reference>()));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::make_record("a"_id = 1, "b"_id = 8.5, "c"_id = 3.6f, "d"_id = 4ULL),
                                         kumi::predicate<std::is_arithmetic>()));
};
