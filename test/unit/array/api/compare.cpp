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
#include <array>
#include <ostream>
#include <string>

TTS_CASE("Lexicographical comparison - Empty arrays (N = 0)")
{
  constexpr kumi::array<> t0_a{};
  constexpr kumi::array<> t0_b{};

  TTS_EXPECT_NOT(t0_a < t0_b);
  TTS_EXPECT(t0_a <= t0_b);
  TTS_EXPECT_NOT(t0_a > t0_b);
  TTS_EXPECT(t0_a >= t0_b);
};

TTS_CASE("Lexicographical comparison - Single element arrays (N = 1)")
{
  constexpr kumi::array<int, 1> t1_a{10};
  constexpr kumi::array<int, 1> t1_b{20};
  constexpr kumi::array<int, 1> t1_c{10};

  TTS_EXPECT(t1_a < t1_b);
  TTS_EXPECT(t1_a <= t1_b);
  TTS_EXPECT(t1_b > t1_a);
  TTS_EXPECT(t1_b >= t1_a);

  TTS_EXPECT_NOT(t1_a < t1_c);
  TTS_EXPECT(t1_a <= t1_c);
};

TTS_CASE("Lexicographical comparison - Multi-element arrays (N > 1)")
{
  constexpr kumi::array<int, 3> t_a{1, 5, 1};
  constexpr kumi::array<int, 3> t_b{2, 1, 1};
  TTS_EXPECT(t_a < t_b);

  constexpr kumi::array<int, 3> t_c{1, 5, 1};
  constexpr kumi::array<int, 3> t_d{1, 6, 1};
  TTS_EXPECT(t_c < t_d);

  constexpr kumi::array<int, 3> t_e{1, 5, 1};
  constexpr kumi::array<int, 3> t_f{1, 5, 7};
  TTS_EXPECT(t_e < t_f);

  constexpr kumi::array<int, 3> t_g{1, 5, 1};
  TTS_EXPECT_NOT(t_a < t_g);
  TTS_EXPECT(t_a <= t_g);
  TTS_EQUAL(t_a, t_g);
};

TTS_CASE("Lexicographical comparison - String arrays")
{
  kumi::array<std::string, 1> t1{"apple"};
  kumi::array<std::string, 1> t2{"banana"};

  TTS_EXPECT(t1 < t2);
  TTS_EXPECT(t1 <= t2);
  TTS_EXPECT(t2 > t1);
  TTS_EXPECT(t2 >= t1);
  TTS_NOT_EQUAL(t1, t2);
};

namespace
{
  constexpr int power_of_3(std::size_t n) noexcept
  {
    return n == 0 ? 1 : 3 * power_of_3(n - 1);
  }

  // Element I is the I-th base 3 digit of code: 0, 1 and 2 give each position less, equal and greater
  template<typename Array, std::size_t... I> constexpr Array from_code(int code, std::index_sequence<I...>)
  {
    return Array{static_cast<std::tuple_element_t<I, Array>>(code / power_of_3(I) % 3)...};
  }

  template<typename Array, typename Reference> void check_order()
  {
    constexpr auto indexes = std::make_index_sequence<std::tuple_size_v<Array>>{};
    constexpr int count = power_of_3(std::tuple_size_v<Array>);

    auto order = [](auto const& x, auto const& y) { return kumi::tuple{(x < y), (x <= y), (x > y), (x >= y)}; };

    for (int i = 0; i < count; ++i)
    {
      for (int j = 0; j < count; ++j)
      {
        auto a = from_code<Array>(i, indexes);
        auto b = from_code<Array>(j, indexes);
        auto sa = from_code<Reference>(i, indexes);
        auto sb = from_code<Reference>(j, indexes);

        TTS_EQUAL((kumi::tuple{a, b, order(a, b)}), (kumi::tuple{a, b, order(sa, sb)}));
      }
    }
  }

  template<typename T, std::size_t N> void check_against_std()
  {
    check_order<kumi::array<T, N>, std::array<T, N>>();
  }

  // Comparison result that does not convert to bool, as a SIMD mask
  struct boolean
  {
    bool value;

    friend constexpr boolean operator!(boolean a) noexcept { return {!a.value}; }

    friend constexpr boolean operator&&(boolean a, boolean b) noexcept { return {a.value && b.value}; }

    friend constexpr boolean operator||(boolean a, boolean b) noexcept { return {a.value || b.value}; }

    friend constexpr bool operator==(boolean a, bool b) noexcept { return a.value == b; }

    // friend std::ostream& operator<<(std::ostream& os, boolean a) { return os << a.value; }
  };

  struct number
  {
    constexpr number(int v) noexcept : value(v) {}

    int value;

    friend constexpr boolean operator<(number a, number b) noexcept { return {a.value < b.value}; }

    friend constexpr bool operator==(number a, number b) noexcept = default;

    // friend std::ostream& operator<<(std::ostream& os, number a) { return os << a.value; }
  };
}

TTS_CASE("Lexicographical comparison - Every pair of arrays over {0, 1, 2}^N against std::array")
{
  check_against_std<int, 1>();
  check_against_std<int, 2>();
  check_against_std<double, 3>();
  check_against_std<short, 4>();
};

TTS_CASE("Lexicographical comparison - Element comparisons returning a type other than bool")
{
  [[maybe_unused]] kumi::array<number, 3> t{0, 1, 2};

  TTS_TYPE_IS(decltype(t < t), boolean);
  TTS_TYPE_IS(decltype(t <= t), boolean);
  TTS_TYPE_IS(decltype(t > t), boolean);
  TTS_TYPE_IS(decltype(t >= t), boolean);

  check_order<kumi::array<number, 1>, std::array<int, 1>>();
  check_order<kumi::array<number, 3>, std::array<int, 3>>();
};
