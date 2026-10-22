//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/predicates.hpp>
#include <tts/tts.hpp>

TTS_CASE("kumi predicates runtime behavior on arrays")
{
  auto yay_values = kumi::array{1, 2, -3, 4};
  auto nay_values = kumi::array{1, 6, 13, 4};

  auto ptr_values = kumi::array<int*, 4>{};

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

  TTS_EXPECT(kumi::all_of(yay_values, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::any_of(yay_values, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT(kumi::none_of(yay_values, kumi::predicate<std::is_pointer>()));
  TTS_EQUAL(kumi::count_if(yay_values, kumi::predicate<std::is_integral>()), 4ULL);

  TTS_EXPECT(kumi::all_of(ptr_values, kumi::predicate<std::is_pointer>()));
  TTS_EXPECT_NOT(kumi::any_of(ptr_values, kumi::predicate<std::is_arithmetic>()));
  TTS_EXPECT_NOT(kumi::none_of(ptr_values, kumi::predicate<std::is_pointer>()));

  TTS_EXPECT(kumi::all_of(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 5; }));
  TTS_EXPECT(kumi::any_of(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 0; }));
  TTS_EXPECT(kumi::none_of(kumi::array{1, 2, 3, 4}, [](auto e) { return e > 12; }));
  TTS_EQUAL(kumi::count_if(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 0; }), 1ULL);
  TTS_EQUAL(kumi::count(kumi::array{1, 2, -3, 4}), yay_values.size());
};

TTS_CASE("kumi predicates constexpr behavior on arrays")
{
  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::array{1, 2, 3, 4}, [](auto e) { return e > 12; }));
  TTS_CONSTEXPR_EQUAL(kumi::count_if(kumi::array{1, 2, -3, 4}, [](auto e) { return e < 0; }), 1ULL);
  TTS_CONSTEXPR_EQUAL(kumi::count(kumi::array{1, 2, -3, 4}), 4ULL);

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::array{1, 2, -3, 4}));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::array{1, 2, -3, 4}));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::array{1, 2, -3, 4}));

  TTS_CONSTEXPR_EXPECT_NOT(kumi::all_of(kumi::array{1, 6, 13, 4}, [](auto e) { return e < 5; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::any_of(kumi::array{1, 6, 13, 4}, [](auto e) { return e < 0; }));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::none_of(kumi::array{1, 6, 13, 4}, [](auto e) { return e > 12; }));

  TTS_CONSTEXPR_EXPECT(kumi::all_of(kumi::array{1, 2, -3, 4}, kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(kumi::any_of(kumi::array{1, 2, -3, 4}, kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::array{1, 2, -3, 4}, kumi::predicate<std::is_pointer>()));
  TTS_CONSTEXPR_EQUAL(kumi::count_if(kumi::array{1, 2, -3, 4}, kumi::predicate<std::is_integral>()), 4ULL);

  TTS_CONSTEXPR_EXPECT_NOT(kumi::all_of(kumi::array<int*, 4>{}, kumi::predicate<std::is_arithmetic>()));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::any_of(kumi::array<int*, 4>{}, kumi::predicate<std::is_lvalue_reference>()));
  TTS_CONSTEXPR_EXPECT(kumi::none_of(kumi::array<int*, 4>{}, kumi::predicate<std::is_arithmetic>()));
};
