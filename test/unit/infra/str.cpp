//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <tts/tts.hpp>
#include <kumi/kumi.hpp>

TTS_CASE("Test constructor and basic properties")
{
  constexpr kumi::str s("hello");
  TTS_EQUAL(s.size(), 5ULL);
  TTS_EQUAL(s.data()[0], 'h');
};

TTS_CASE("Test substr operations")
{
  constexpr kumi::str s("hello world");
  constexpr auto sub = s.substr(6, 5);
  TTS_EQUAL(sub.size(), 5ULL);
  TTS_EXPECT(sub.starts_with("world"));
};

TTS_CASE("Test prefix and suffix removal")
{
  constexpr kumi::str s("foobar");
  constexpr auto p = s.remove_prefix(3);
  constexpr auto sf = s.remove_suffix(3);

  TTS_EQUAL(p.size(), 3ULL);
  TTS_EXPECT(p.starts_with("bar"));

  TTS_EQUAL(sf.size(), 3ULL);
  TTS_EXPECT(sf.starts_with("foo"));
};

TTS_CASE("Test search utilities")
{
  constexpr kumi::str s("banana");
  TTS_EQUAL(s.find("ana"), 1ULL);
  TTS_EQUAL(s.rfind("ana"), 3ULL);
  TTS_EXPECT(s.contains("nan"));
  TTS_EXPECT(!s.contains("xyz"));
};

TTS_CASE("Test edge cases and failures")
{
  constexpr kumi::str s("test");
  TTS_EXPECT(s.starts_with("test"));
  TTS_EXPECT(!s.starts_with("testing"));

  TTS_EQUAL(s.find("not_found"), kumi::str::npos);
};

TTS_CASE("Test concatenation")
{
  constexpr kumi::str s1("hello");
  constexpr kumi::str s2(" world");
  constexpr auto s3 = s1 + s2;

  TTS_EQUAL(s3.size(), 12ULL);
  TTS_EXPECT(s3.ends_with("world"));
};

TTS_CASE("Test character search")
{
  constexpr kumi::str s("abracadabra");
  TTS_EQUAL(s.find_first_of("c"), 4ULL);
  TTS_EQUAL(s.find_last_of("a"), 10ULL);
  TTS_EQUAL(s.find_first_not_of("ab"), 2ULL);
};

TTS_CASE("Test user-defined literal operator")
{
  using namespace kumi;

  constexpr auto s = "hello"_str;

  TTS_EQUAL(s.size(), 5ULL);
  TTS_EXPECT(s.starts_with("he"_str));

  constexpr auto s2 = "hello"_str + "world"_str;
  TTS_EQUAL(s2.size(), 11ULL);
  TTS_EXPECT(s2 == "hello.world"_str);
};

TTS_CASE("Test complex chain with literals")
{
  using namespace kumi;

  constexpr auto result = ("abcd"_str.remove_prefix(1)).remove_suffix(1);

  TTS_EQUAL(result.size(), 2ULL);
  TTS_EXPECT(result == "bc"_str);
};

TTS_CASE("Test comparison operators")
{
  using namespace kumi;

  constexpr auto s1 = "abc"_str;
  constexpr auto s2 = "abd"_str;
  constexpr auto s3 = "abc"_str;

  TTS_EXPECT(s1 < s2);
  TTS_EXPECT(s2 > s1);
  TTS_EXPECT(s1 == s3);
  TTS_EXPECT(s1 != s2);
};
