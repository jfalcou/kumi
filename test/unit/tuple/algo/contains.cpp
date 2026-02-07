//==================================================================================================
/**
  RABERU - Fancy Parameters Library
  Copyright : RABERU Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
//==================================================================================================
#define TTS_MAIN
#include "test.hpp"
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <string>

struct foo
{
  int value = 42;
};

TTS_CASE("Check kumi::contains behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  kumi::tuple values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, "aligned"_id = std::bool_constant<true>{},
                     is_transparent_};
  TTS_EXPECT(kumi::contains(values, custom_));
  TTS_EXPECT(kumi::contains(values, "surname"_id));
  TTS_EXPECT(kumi::contains(values, value_));
  TTS_EXPECT(kumi::contains(values, "is_transparent_"_id));
  TTS_EXPECT(kumi::contains(values, "aligned"_id));

  TTS_EXPECT_NOT(kumi::contains(values, "is_modal_"_id));
  TTS_EXPECT_NOT(kumi::contains(values, "compact"_id));
};

TTS_CASE("Check kumi::contains constexpr behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  constexpr kumi::tuple values{"custom"_id = foo{}, value_ = 3.f, is_modal_};
  ;

  TTS_CONSTEXPR_EXPECT(kumi::contains(values, "custom"_id));
  TTS_CONSTEXPR_EXPECT(kumi::contains(values, value_));
  TTS_CONSTEXPR_EXPECT(kumi::contains(values, "is_modal_"_id));

  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains(values, "is_transparent_"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains(values, "compact"_id));
};

TTS_CASE("Check kumi::contains_any behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  kumi::tuple values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, "aligned"_id, is_transparent_};

  TTS_EXPECT(kumi::contains_any(values, "custom_"_id, "is_transparent_"_id, "compact"_id));
  TTS_EXPECT_NOT(kumi::contains_any(values, "is_modal_"_id, "compact"_id));
};

TTS_CASE("Check kumi::contains_any constexpr behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  constexpr kumi::tuple values{"custom"_id = foo{}, value_ = 3.f, is_modal_};
  ;

  TTS_CONSTEXPR_EXPECT(kumi::contains_any(values, "value_"_id, "is_modal_"_id, "custom"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_any(values, "is_transparent_"_id, "compact"_id));
};

TTS_CASE("Check kumi::contains_only behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  kumi::tuple values{"kw1"_id = 1, "kw2"_id = 1, "kw3"_id = 1};
  ;

  TTS_EXPECT(kumi::contains_only(values, "kw1"_id, "kw2"_id, "kw3"_id));
  TTS_EXPECT(kumi::contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id));
  TTS_EXPECT(kumi::contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id, "xyz"_id));

  TTS_EXPECT_NOT(kumi::contains_only(values, "kw1"_id, "kw2"_id));
  TTS_EXPECT_NOT(kumi::contains_only(values, "kw1"_id));
  TTS_EXPECT_NOT(kumi::contains_only(values, "a"_id));
  TTS_EXPECT_NOT(kumi::contains_only(values, "a"_id, "b"_id));
};

TTS_CASE("Check kumi::contains_only constexpr behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  constexpr kumi::tuple values{"kw1"_id = 1, "kw2"_id = 1, "kw3"_id = 1};
  ;

  TTS_CONSTEXPR_EXPECT(kumi::contains_only(values, "kw1"_id, "kw2"_id, "kw3"_id));
  TTS_CONSTEXPR_EXPECT(kumi::contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id));
  TTS_CONSTEXPR_EXPECT(kumi::contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id, "xyz"_id));

  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_only(values, "kw1"_id, "kw2"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_only(values, "kw1"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_only(values, "a"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_only(values, "a"_id, "b"_id));
};

TTS_CASE("Check kumi::contains_none behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  kumi::tuple values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, "aligned"_id, "is_transparent_"_id};

  TTS_EXPECT(kumi::contains_none(values, "is_modal_"_id, "compact"_id));
  TTS_EXPECT_NOT(kumi::contains_none(values, value_, "is_transparent_"_id));
};

TTS_CASE("Check kumi::contains_none constexpr behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  constexpr kumi::tuple values{"custom"_id = foo{}, value_ = 3.f, "is_modal_"_id};
  ;

  TTS_CONSTEXPR_EXPECT(kumi::contains_none(values, "is_transparent_"_id, "compact"_id));
  TTS_CONSTEXPR_EXPECT_NOT(kumi::contains_none(values, "value_"_id));
};
