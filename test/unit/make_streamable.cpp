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

#include <string>
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
    return std::to_string(p.integer) + "."
         + std::to_string(p.decimal);
  }

  struct person
  {
    std::string name;
    std::string surname;

    friend auto as_streamable(person const& p)
    {
      return p.name + " " + p.surname;
    }
  };

  struct unprintable
  {
    int t; char s; long z;
  };
}

TTS_CASE("Check make_streamable behavior")
{
  ns::price cards   { 7, 90             };
  ns::person marty  { "Marty", "Macfly" };
  ns::unprintable a { 1, 'x', 12        };

  kumi::tuple t = {'t', "rofl", cards, marty, a};

  std::ostringstream s;
  s << t;

  TTS_EQUAL(s.str(), "( t rofl 7.90 Marty Macfly (unknown) )");
};
