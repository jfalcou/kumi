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

#include <sstream>
#include <cstdint>

namespace ns
{
  struct price
  {
    std::uint64_t integer;
    std::uint64_t decimal;
  };

  auto as_streamable(price const& p)
  {
    return tts::text("%ld", p.integer) + "." + tts::text("%ld", p.decimal);
  }

  struct person
  {
    tts::text name;
    tts::text surname;

    friend auto as_streamable(person const& p) { return p.name + " " + p.surname; }
  };

  struct unprintable
  {
    int t;
    char s;
    long z;
  };
}

TTS_CASE("Check make_streamable behavior with tuple")
{
  ns::price cards{7, 90};
  ns::person marty{tts::text("Marty"), tts::text("Macfly")};
  ns::unprintable a{1, 'x', 12};

  kumi::tuple t = {'t', "rofl", cards, marty, a};

  std::ostringstream s;
  s << t;

  TTS_EQUAL(s.str(), "( t, rofl, 7.90, Marty Macfly, kumi::unknown )");
};

TTS_CASE("Check make_streamable behavior with record")
{
  using namespace kumi::literals;
  ns::price cards{7, 90};
  ns::person marty{tts::text("Marty"), tts::text("Macfly")};
  ns::unprintable a{1, 'x', 12};

  kumi::record r = {"a"_id = 't', "b"_id = "rofl", "c"_id = cards, "d"_id = marty, "e"_id = a};

  std::ostringstream s;
  s << r;

  TTS_EQUAL(s.str(), "{ 'a' : t, 'b' : rofl, 'c' : 7.90, 'd' : Marty Macfly, 'e' : kumi::unknown }");
};
