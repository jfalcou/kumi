//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <tts/tts.hpp>
#include <string>
#include <type_traits>
#include <utility>

using namespace kumi::literals;

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
// Assignment is gated on assignability of the destination's field, source -> dest, matched by name.
//==================================================================================================
TTS_CASE("Check record assignment gating")
{
  using dst = kumi::record<kumi::field<kumi::name<"a">, std::string>>;
  using src = kumi::record<kumi::field<kumi::name<"a">, char const*>>;

  TTS_CONSTEXPR_EXPECT((std::is_assignable_v<dst&, src const&>));
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<src&, dst const&>));

  using dstc = kumi::record<kumi::field<kumi::name<"a">, int const>>;
  using srci = kumi::record<kumi::field<kumi::name<"a">, int>>;
  TTS_CONSTEXPR_EXPECT((!std::is_assignable_v<dstc&, srci const&>));
};

TTS_CASE("Check record runtime assignment")
{
  kumi::record<kumi::field<kumi::name<"a">, std::string>, kumi::field<kumi::name<"b">, double>> dst{std::string{"old"},
                                                                                                    0.};
  kumi::record<kumi::field<kumi::name<"a">, char const*>, kumi::field<kumi::name<"b">, int>> src{"new", 42};

  dst = src;
  TTS_EQUAL(dst["a"_id], std::string{"new"});
  TTS_EQUAL(dst["b"_id], 42.);
};

TTS_CASE("Check record assignment noexcept propagation")
{
  using r = kumi::record<kumi::field<kumi::name<"a">, may_throw>>;
  TTS_CONSTEXPR_EXPECT((!std::is_nothrow_assignable_v<r&, r const&>));

  using ri = kumi::record<kumi::field<kumi::name<"a">, int>>;
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_assignable_v<ri&, ri const&>));
};

TTS_CASE("Check record swappability")
{
  using rint = kumi::record<kumi::field<kumi::name<"a">, int>>;
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<rint>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<rint>));

  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<kumi::record<>>));
  TTS_CONSTEXPR_EXPECT((std::is_nothrow_swappable_v<kumi::record<>>));

  using rconst = kumi::record<kumi::field<kumi::name<"a">, int const>>;
  TTS_CONSTEXPR_EXPECT((!std::is_swappable_v<rconst>));

  using rthrow = kumi::record<kumi::field<kumi::name<"a">, throwing_swap>>;
  TTS_CONSTEXPR_EXPECT((std::is_swappable_v<rthrow>));
  TTS_CONSTEXPR_EXPECT((!std::is_nothrow_swappable_v<rthrow>));
};

TTS_CASE("Check record swap runtime")
{
  auto a = kumi::make_record("GPA"_id = 3.8, "grade"_id = 'A');
  auto b = kumi::make_record("GPA"_id = 2.9, "grade"_id = 'B');

  using std::swap;
  swap(a, b);
  TTS_EQUAL(a["GPA"_id], 2.9);
  TTS_EQUAL(b["GPA"_id], 3.8);
  TTS_EQUAL(a["grade"_id], 'B');
  TTS_EQUAL(b["grade"_id], 'A');
};

TTS_CASE("Check record swap uses ADL-reachable field swap")
{
  auto a = kumi::make_record("x"_id = tracked{1});
  auto b = kumi::make_record("x"_id = tracked{2});

  tracked::swaps = 0;
  using std::swap;
  swap(a, b);
  TTS_EQUAL(tracked::swaps, 1);
  TTS_EQUAL(a["x"_id].value, 2);
  TTS_EQUAL(b["x"_id].value, 1);
};

TTS_CASE("Check empty record swap")
{
  kumi::record<> a{}, b{};
  using std::swap;
  swap(a, b);
  TTS_EXPECT(true);
};
