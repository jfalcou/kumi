//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include <string>
#include <type_traits>
#include <utility>

namespace
{
  struct may_throw
  {
    may_throw() = default;

    may_throw(may_throw const&) noexcept(false) {}

    may_throw(may_throw&&) noexcept(false) {}

    may_throw& operator=(may_throw const&) noexcept(false) { return *this; }

    may_throw& operator=(may_throw&&) noexcept(false) { return *this; }
  };

  struct throwing_swap
  {
    friend void swap(throwing_swap&, throwing_swap&) noexcept(false) {}
  };

  struct tracked
  {
    int value = 0;
    inline static int swaps = 0;

    friend void swap(tracked& a, tracked& b) noexcept
    {
      ++swaps;
      std::swap(a.value, b.value);
    }
  };
}

//==================================================================================================
// Assignment is gated on assignability of the destination's element, source -> dest.
//==================================================================================================
TTS_CASE("Check array assignment gating")
{
  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::array<std::string, 1>&, kumi::array<char const*, 1> const&>));
  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::array<double, 2>&, kumi::array<int, 2> const&>));

  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::array<char const*, 1>&, kumi::array<std::string, 1> const&>));
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::array<int const, 1>&, kumi::array<int, 1> const&>));
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::array<int, 2>&, kumi::array<int, 1> const&>));
};

TTS_CASE("Check array runtime assignment")
{
  kumi::array<int, 3> a{1, 2, 3};
  kumi::array<char, 3> b{'x', 'y', 'z'};

  a = b;
  TTS_EQUAL(get<0>(a), 'x');
  TTS_EQUAL(get<1>(a), 'y');
  TTS_EQUAL(get<2>(a), 'z');
};

TTS_CASE("Check array assignment noexcept propagation")
{
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_assignable_v<kumi::array<int, 2>&, kumi::array<char, 2> const&>));
  TTS_CONSTEXPR_EXPECT((!std::is_nothrow_assignable_v<kumi::array<may_throw, 1>&, kumi::array<may_throw, 1> const&>));
};

TTS_CASE("Check array swappability")
{
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::array<int, 3>>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<kumi::array<int, 3>>));
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::array<int, 0>>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<kumi::array<int, 0>>));

  TTS_CONSTEXPR_EXPECT((!std::is_swappable_v<kumi::array<int const, 1>>));

  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::array<throwing_swap, 1>>));
  TTS_CONSTEXPR_EXPECT((!std::is_nothrow_swappable_v<kumi::array<throwing_swap, 1>>));
};

TTS_CASE("Check array swap runtime")
{
  kumi::array<int, 3> a{1, 2, 3};
  kumi::array<int, 3> b{4, 5, 6};

  using std::swap;
  swap(a, b);
  TTS_EQUAL(get<0>(a), 4);
  TTS_EQUAL(get<1>(a), 5);
  TTS_EQUAL(get<2>(a), 6);
  TTS_EQUAL(get<0>(b), 1);
};

TTS_CASE("Check array swap uses ADL-reachable element swap")
{
  kumi::array<tracked, 2> a{tracked{1}, tracked{3}};
  kumi::array<tracked, 2> b{tracked{2}, tracked{4}};

  tracked::swaps = 0;
  using std::swap;
  swap(a, b);
  TTS_EQUAL(tracked::swaps, 2);
  TTS_EQUAL(get<0>(a).value, 2);
  TTS_EQUAL(get<1>(a).value, 4);
  TTS_EQUAL(get<0>(b).value, 1);
  TTS_EQUAL(get<1>(b).value, 3);
};

TTS_CASE("Check empty array swap")
{
  kumi::array<int, 0> a{}, b{};
  using std::swap;
  swap(a, b);
  TTS_EXPECT(true);
};
