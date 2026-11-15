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
#include <tuple>
#include <array>

TTS_CASE("Check generic concepts on product_types")
{
  TTS_WHEN("Initialize different product types")
  {
    using namespace kumi::literals;

    using empty_t = kumi::tuple<>;
    using empty_std = std::tuple<>;
    using empty_r = kumi::record<>;

    using tuple_2 = kumi::tuple<int, float>;
    using std_t_2 = std::tuple<int, float>;
    using std_a_2 = std::array<int, 2>;
    using std_p_2 = std::pair<int, float>;

    using tuple_3 = kumi::tuple<int, char, float>;
    using tuple_3_nc = kumi::tuple<int, char, tts::text>;

    using rec_ab = decltype(kumi::record{"a"_id = 1, "b"_id = 2.f});
    using rec_ab_alt = decltype(kumi::record{"a"_id = 10, "b"_id = 5.5f});
    using rec_ab_diff = decltype(kumi::record{"a"_id = 1, "b"_id = tts::text{"hi"}});
    using rec_ba = decltype(kumi::record{"b"_id = 2.f, "a"_id = 1});
    using rec_xyz = decltype(kumi::record{"x"_id = 1, "y"_id = 2, "z"_id = 3});

    TTS_AND_THEN("Check semantic requirements")
    {
      TTS_EXPECT((kumi::concepts::follows_same_semantic<tuple_2, std_t_2, std_a_2, empty_t>));
      TTS_EXPECT((kumi::concepts::follows_same_semantic<rec_ab, rec_ba, rec_xyz>));

      TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<tuple_2, rec_ab>));

      TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<int, int>));
      TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<tuple_2, int>));
    }

    TTS_AND_THEN("Check comparable for equality")
    {
      TTS_EXPECT((kumi::concepts::equality_comparable<tuple_2, std_t_2>));
      TTS_EXPECT((kumi::concepts::equality_comparable<std_a_2, std_t_2>));

      TTS_EXPECT_NOT((kumi::concepts::equality_comparable<tuple_3, tuple_3_nc>));
      TTS_EXPECT_NOT((kumi::concepts::equality_comparable<tuple_2, tuple_3>));

      TTS_EXPECT((kumi::concepts::equality_comparable<rec_ab, rec_ba>));
      TTS_EXPECT((kumi::concepts::equality_comparable<rec_ab, rec_ab_alt>));

      TTS_EXPECT_NOT((kumi::concepts::equality_comparable<rec_ab, rec_ab_diff>));
      TTS_EXPECT_NOT((kumi::concepts::equality_comparable<rec_ab, rec_xyz>));

      TTS_EXPECT((kumi::concepts::equality_comparable<empty_t, empty_std>));
      TTS_EXPECT((kumi::concepts::equality_comparable<empty_t, empty_r>));
      TTS_EXPECT_NOT((kumi::concepts::equality_comparable<int, int>));
    }

    TTS_AND_THEN("Check Compatibility")
    {
      TTS_EXPECT((kumi::concepts::compatible_product_types<tuple_2, std_t_2, std_p_2, std_a_2>));
      TTS_EXPECT((kumi::concepts::compatible_product_types<empty_t, empty_std>));

      TTS_EXPECT((kumi::concepts::compatible_product_types<rec_ab, rec_ba, rec_ab_diff>));

      TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<tuple_2, tuple_3>));
      TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<rec_ab, rec_xyz>));
      TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<std_a_2, rec_ab>));
    }
  }
};

namespace
{
  template<kumi::concepts::homogeneous_product_type T> constexpr int pick(T const&)
  {
    return 1;
  }

  template<kumi::concepts::power_type T> constexpr int pick(T const&)
  {
    return 2;
  }

  template<kumi::concepts::homogeneous_product_type T> constexpr int only_homogeneous(T const&)
  {
    return 1;
  }

  template<kumi::concepts::power_type T> constexpr int only_power(T const&)
  {
    return 1;
  }

  template<typename T>
  concept can_pick = requires(T&& t) { pick(std::forward<T>(t)); };
}

TTS_CASE("power_type and homogeneous_product_type overloads are not ambiguous")
{
  TTS_EXPECT((can_pick<kumi::array<int, 3>>));
  TTS_EXPECT((can_pick<kumi::array<int, 3> const&>));
  TTS_EXPECT((can_pick<kumi::array<int, 3>&>));
  TTS_EXPECT((can_pick<kumi::array<int, 3>&&>));

  kumi::array<int, 3> a{1, 2, 3};
  TTS_EQUAL(pick(a), 2);
  TTS_EQUAL((pick(kumi::array<int, 3>{1, 2, 3})), 2);

  kumi::array<double, 1> single{1.};
  TTS_EQUAL(pick(single), 2);
};

TTS_CASE("homogeneous non-power types still select the homogeneous overload")
{
  TTS_EXPECT((can_pick<kumi::tuple<int, int, int>>));
  TTS_EQUAL((pick(kumi::tuple<int, int, int>{1, 2, 3})), 1);
  TTS_EQUAL((only_homogeneous(kumi::array<int, 3>{1, 2, 3})), 1);

  auto t = kumi::tuple{1, 'x', 3.f};
  auto a = kumi::array{1, 2, 3, 4, 5};
  auto h = kumi::tuple{1, 2, 3, 4, 5};

  TTS_EXPECT_NOT_COMPILES(t, { only_homogeneous(t); });
  TTS_EXPECT_NOT_COMPILES(t, { only_power(t); });

  TTS_EXPECT_COMPILES(a, { only_homogeneous(a); });
  TTS_EXPECT_COMPILES(a, { only_power(a); });

  TTS_EXPECT_COMPILES(h, { only_homogeneous(h); });
  TTS_EXPECT_NOT_COMPILES(h, { only_power(h); });
};

TTS_CASE("non-homogeneous types match neither overload")
{
  TTS_EXPECT_NOT((can_pick<kumi::tuple<int, float>>));
  TTS_EXPECT_NOT(can_pick<int>);
};

TTS_CASE("concept relationship is as documented")
{
  using arr_t = kumi::array<int, 3>;
  using tup_t = kumi::tuple<int, int, int>;

  TTS_EXPECT(kumi::concepts::power_type<arr_t>);
  TTS_EXPECT(kumi::concepts::homogeneous_product_type<arr_t>);

  TTS_EXPECT(kumi::concepts::homogeneous_product_type<tup_t>);
  TTS_EXPECT_NOT(kumi::concepts::power_type<tup_t>);
};
