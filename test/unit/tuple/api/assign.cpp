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
#include "test.hpp"
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

//==================================================================================================
// Assignment is gated on assignability of the destination's element, source -> dest,
// not on convertibility.
//==================================================================================================
TTS_CASE("Check tuple assignment gating")
{
  // Widening assignment is allowed.
  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::tuple<std::string>&, kumi::tuple<char const*> const&>));
  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::tuple<double>&, kumi::tuple<int> const&>));

  // Narrowing (dest cannot be assigned the source element) is rejected.
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::tuple<char const*>&, kumi::tuple<std::string> const&>));

  // const destination elements are not assignable.
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::tuple<int const>&, kumi::tuple<int> const&>));

  // Arity mismatch is rejected.
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<kumi::tuple<int, int>&, kumi::tuple<int> const&>));
};

TTS_CASE("Check tuple converting assignment direction")
{
  // The source element is assigned into the destination element, so a destination element that is
  // assignable from the source element is fine even though the two types are not convertible.
  kumi::tuple<std::string> dst{"old"};
  kumi::tuple<char const*> src{"new"};

  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::tuple<std::string>&, kumi::tuple<char const*> const&>));
  dst = src;
  TTS_EQUAL(get<0>(dst), std::string{"new"});
};

TTS_CASE("Check tuple runtime assignment")
{
  kumi::tuple<int, double> a{1, 2.};
  kumi::tuple<char, float> b{'x', 3.f};

  a = b;
  TTS_EQUAL(get<0>(a), 'x');
  TTS_EQUAL(get<1>(a), 3.);
};

TTS_CASE("Check tuple move assignment")
{
  kumi::tuple<std::unique_ptr<int>> dst{};
  kumi::tuple<std::unique_ptr<int>> src{std::make_unique<int>(7)};

  dst = std::move(src);
  TTS_EXPECT(get<0>(src) == nullptr);
  TTS_EXPECT(get<0>(dst) != nullptr);
  TTS_EQUAL(*get<0>(dst), 7);
};

//==================================================================================================
// no-throw propagation of assignment and swap.
//==================================================================================================
TTS_CASE("Check tuple assignment noexcept propagation")
{
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_assignable_v<kumi::tuple<int, double>&, kumi::tuple<char, float> const&>));
  TTS_CONSTEXPR_EXPECT(
    (!std::is_nothrow_assignable_v<kumi::tuple<int, may_throw>&, kumi::tuple<int, may_throw> const&>));
};

TTS_CASE("Check tuple swappability")
{
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::tuple<>>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<kumi::tuple<>>));
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::tuple<int, std::string>>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<kumi::tuple<int, std::string>>));

  // const elements are not swappable.
  TTS_CONSTEXPR_EXPECT((!std::is_swappable_v<kumi::tuple<int const>>));
  TTS_CONSTEXPR_EXPECT((!std::is_swappable_v<kumi::tuple<int, int const>>));

  // swap is not no-throw if an element swap may throw.
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::tuple<int, throwing_swap>>));
  TTS_CONSTEXPR_EXPECT((!std::is_nothrow_swappable_v<kumi::tuple<int, throwing_swap>>));
};

TTS_CASE("Check tuple swap runtime")
{
  kumi::tuple<int, std::string> a{1, "one"};
  kumi::tuple<int, std::string> b{2, "two"};

  using std::swap;
  swap(a, b);
  TTS_EQUAL(a, (kumi::tuple<int, std::string>{2, "two"}));
  TTS_EQUAL(b, (kumi::tuple<int, std::string>{1, "one"}));
};

TTS_CASE("Check tuple swap uses ADL-reachable element swap")
{
  kumi::tuple<tracked, int> a{tracked{1}, 10};
  kumi::tuple<tracked, int> b{tracked{2}, 20};

  tracked::swaps = 0;
  using std::swap;
  swap(a, b);
  TTS_EQUAL(tracked::swaps, 1);
  TTS_EQUAL(get<0>(a).value, 2);
  TTS_EQUAL(get<0>(b).value, 1);
  TTS_EQUAL(get<1>(a), 20);
  TTS_EQUAL(get<1>(b), 10);
};

TTS_CASE("Check tuple of references swap")
{
  int x = 1, y = 2;
  kumi::tuple<int&> a{x};
  kumi::tuple<int&> b{y};

  using std::swap;
  swap(a, b);
  TTS_EQUAL(x, 2);
  TTS_EQUAL(y, 1);
};

TTS_CASE("Check empty tuple swap")
{
  kumi::tuple<> a{}, b{};
  using std::swap;
  swap(a, b);
  TTS_EXPECT(true);
};

TTS_CASE("Check tuple conversion is distinct from assignment")
{
  // A tuple of assignable_from_int is assignable from a tuple<int> even though assignable_from_int
  // cannot be constructed from an int, hence no conversion from tuple<int> is available. This proves
  // assignment is gated on per-element assignability (destination-driven), not on conversion.
  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<kumi::tuple<assignable_from_int>&, kumi::tuple<int> const&>));
  TTS_CONSTEXPR_EXPECT((!std::is_convertible_v<kumi::tuple<int> const&, kumi::tuple<assignable_from_int>>));
};
