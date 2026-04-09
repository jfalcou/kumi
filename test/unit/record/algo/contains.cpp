//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include "test.hpp"
#include <kumi/record.hpp>
#include <tts/tts.hpp>
#include <string>

struct foo
{
  int value = 42;
};

TTS_CASE("Check kumi::contains behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, "aligned"_id = std::bool_constant<true>{},
                is_transparent_};

  TTS_EXPECT((result::contains_t<decltype(values), decltype(custom_)>{}));
  TTS_EXPECT((result::contains_t<decltype(values), decltype("surname"_id)>{}));
  TTS_EXPECT((result::contains_t<decltype(values), decltype(value_)>{}));
  TTS_EXPECT((result::contains_t<decltype(values), decltype("is_transparent_"_id)>{}));
  TTS_EXPECT((result::contains_t<decltype(values), decltype("aligned"_id)>{}));

  TTS_EXPECT_NOT((result::contains_t<decltype(values), decltype("is_modal_"_id)>{}));
  TTS_EXPECT_NOT((result::contains_t<decltype(values), decltype("compact"_id)>{}));
};

TTS_CASE("Check kumi::contains behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, "aligned"_id = std::bool_constant<true>{},
                is_transparent_};
  TTS_EXPECT(contains(values, custom_));
  TTS_EXPECT(contains(values, "surname"_id));
  TTS_EXPECT(contains(values, value_));
  TTS_EXPECT(contains(values, "is_transparent_"_id));
  TTS_EXPECT(contains(values, "aligned"_id));

  TTS_EXPECT_NOT(contains(values, "is_modal_"_id));
  TTS_EXPECT_NOT(contains(values, "compact"_id));
};

TTS_CASE("Check kumi::contains constexpr behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  constexpr record values{"custom"_id = foo{}, value_ = 3.f, is_modal_};

  TTS_CONSTEXPR_EXPECT(contains(values, "custom"_id));
  TTS_CONSTEXPR_EXPECT(contains(values, value_));
  TTS_CONSTEXPR_EXPECT(contains(values, "is_modal_"_id));

  TTS_CONSTEXPR_EXPECT_NOT(contains(values, "is_transparent_"_id));
  TTS_CONSTEXPR_EXPECT_NOT(contains(values, "compact"_id));
};

TTS_CASE("Check kumi::result::contains_any behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, is_transparent_};

  TTS_EXPECT((result::contains_any_t<decltype(values), decltype("custom_"_id), decltype("is_transparent_"_id),
                                     decltype("compact"_id)>{}));
  TTS_EXPECT_NOT((result::contains_any_t<decltype(values), decltype("is_modal_"_id), decltype("compact"_id)>{}));
};

TTS_CASE("Check kumi::contains_any behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f, is_transparent_};

  TTS_EXPECT(contains_any(values, "custom_"_id, "is_transparent_"_id, "compact"_id));
  TTS_EXPECT_NOT(contains_any(values, "is_modal_"_id, "compact"_id));
};

TTS_CASE("Check kumi::contains_any constexpr behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  constexpr record values{"custom"_id = foo{}, value_ = 3.f, is_modal_};

  TTS_CONSTEXPR_EXPECT(contains_any(values, "value_"_id, "is_modal_"_id, "custom"_id));
  TTS_CONSTEXPR_EXPECT_NOT(contains_any(values, "is_transparent_"_id, "compact"_id));
};

TTS_CASE("Check kumi::result::contains_only behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{"kw1"_id = 1, "kw2"_id = 1, "kw3"_id = 1};

  TTS_EXPECT((result::contains_only_t<decltype(values), decltype("kw1"_id), decltype("kw2"_id), decltype("kw3"_id)>{}));
  TTS_EXPECT((result::contains_only_t<decltype(values), decltype("kw1"_id), decltype("kw3"_id), decltype("kw2"_id)>{}));
  TTS_EXPECT((result::contains_only_t<decltype(values), decltype("kw1"_id), decltype("kw3"_id), decltype("kw2"_id),
                                      decltype("xyz"_id)>{}));

  TTS_EXPECT_NOT((result::contains_only_t<decltype(values), decltype("kw1"_id), decltype("kw2"_id)>{}));
  TTS_EXPECT_NOT((result::contains_only_t<decltype(values), decltype("kw1"_id)>{}));
  TTS_EXPECT_NOT((result::contains_only_t<decltype(values), decltype("a"_id)>{}));
  TTS_EXPECT_NOT((result::contains_only_t<decltype(values), decltype("a"_id), decltype("b"_id)>{}));
};

TTS_CASE("Check kumi::contains_only behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{"kw1"_id = 1, "kw2"_id = 1, "kw3"_id = 1};

  TTS_EXPECT(contains_only(values, "kw1"_id, "kw2"_id, "kw3"_id));
  TTS_EXPECT(contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id));
  TTS_EXPECT(contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id, "xyz"_id));

  TTS_EXPECT_NOT(contains_only(values, "kw1"_id, "kw2"_id));
  TTS_EXPECT_NOT(contains_only(values, "kw1"_id));
  TTS_EXPECT_NOT(contains_only(values, "a"_id));
  TTS_EXPECT_NOT(contains_only(values, "a"_id, "b"_id));
};

TTS_CASE("Check kumi::contains_only constexpr behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  constexpr record values{"kw1"_id = 1, "kw2"_id = 1, "kw3"_id = 1};

  TTS_CONSTEXPR_EXPECT(contains_only(values, "kw1"_id, "kw2"_id, "kw3"_id));
  TTS_CONSTEXPR_EXPECT(contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id));
  TTS_CONSTEXPR_EXPECT(contains_only(values, "kw1"_id, "kw3"_id, "kw2"_id, "xyz"_id));

  TTS_CONSTEXPR_EXPECT_NOT(contains_only(values, "kw1"_id, "kw2"_id));
  TTS_CONSTEXPR_EXPECT_NOT(contains_only(values, "kw1"_id));
  TTS_CONSTEXPR_EXPECT_NOT(contains_only(values, "a"_id));
  TTS_CONSTEXPR_EXPECT_NOT(contains_only(values, "a"_id, "b"_id));
};

TTS_CASE("Check kumi::result::contains_none behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f};

  TTS_EXPECT((result::contains_none_t<decltype(values), decltype("is_modal_"_id), decltype("compact"_id)>{}));
  TTS_EXPECT_NOT((result::contains_none_t<decltype(values), decltype(value_), decltype("is_transparent_"_id)>{}));
};

TTS_CASE("Check kumi::contains_none behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  record values{custom_ = foo{}, "surname"_id = "john"s, value_ = 3.f};

  TTS_EXPECT(contains_none(values, "is_modal_"_id, "compact"_id));
  TTS_EXPECT_NOT(contains_none(values, value_, "is_transparent_"_id));
};

TTS_CASE("Check kumi::contains_none constexpr behavior on records")
{
  using namespace std::literals;
  using namespace kumi;

  constexpr record values{"custom"_id = foo{}, value_ = 3.f};

  TTS_CONSTEXPR_EXPECT(contains_none(values, "is_transparent_"_id, "compact"_id));
  TTS_CONSTEXPR_EXPECT(contains_none(values, "value_"_id));
};
