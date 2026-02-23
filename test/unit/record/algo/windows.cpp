//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::result::windows_t behavior on records")
{
  using namespace kumi;
  using int_f = field<name<"i">, int>;
  using float_c_f = field<name<"fc">, float const>;
  using char_r_f = field<name<"cr">, char&>;
  using short_f = field<name<"vs">, short>;
  using long_c_f = field<name<"lc">, long const>;
  using char_f = field<name<"c">, char>;
  using int_r_f = field<name<"ir">, int&>;
  using double_p_f = field<name<"dp">, double*>;

  using r1 = record<int_f, float_c_f, char_r_f, short_f>;
  using r2_inner = record<long_c_f, char_f>;
  using r2 = record<int_r_f, double_p_f, field<name<"inner">, r2_inner>>;

  TTS_TYPE_IS((result::windows_t<1, r1>), (tuple<record<int_f>, record<float_c_f>, record<char_r_f>, record<short_f>>));
  TTS_TYPE_IS((result::windows_t<2, r2>),
              (tuple<record<int_r_f, double_p_f>, record<double_p_f, field<name<"inner">, r2_inner>>>));
};

TTS_CASE("Check runtime kumi::windows behavior on records")
{
  using namespace kumi;

  auto r1 = record{"a"_id = 1, "b"_id = 3.f, "c"_id = 5., "d"_id = 'x', "e"_id = short{77}};
  auto r2 =
    record{"a"_id = 112, "b"_id = -18.f, "c"_id = record{"d"_id = '1', "e"_id = long{22}, "f"_id = kumi::str{"Yes"}}};

  auto r_test = record{"a"_id = 1, "b"_id = 3.f, "c"_id = 5., "d"_id = 'x', "e"_id = short{77}, "f"_id = long{22}};
  auto r3 = windows<3>(kumi::to_ref(r_test));
  for_each(
    [&](auto& tile) {
      auto [f, s, t] = values_of(tile);
      f += 1;
      s += 2;
      t += 3;
      return tile;
    },
    r3);

  TTS_EQUAL((windows<1>(r1)), (make_tuple(record{"a"_id = 1}, record{"b"_id = 3.f}, record{"c"_id = 5.},
                                          record{"d"_id = 'x'}, record{"e"_id = short{77}})));

  TTS_EQUAL(
    (windows<2>(r2)),
    (make_tuple(record{"a"_id = 112, "b"_id = -18.f},
                record{"b"_id = -18.f, "c"_id = record{"d"_id = '1', "e"_id = long{22}, "f"_id = str{"Yes"}}})));

  TTS_EQUAL(
    (windows<2>(std::move(r2))),
    (make_tuple(record{"a"_id = 112, "b"_id = -18.f},
                record{"b"_id = -18.f, "c"_id = record{"d"_id = '1', "e"_id = long{22}, "f"_id = str{"Yes"}}})));

  auto r4 = record{"a"_id = 1, "b"_id = 2, "c"_id = moveonly{}, "d"_id = 'x', "e"_id = 5.f};
  TTS_EXPECT_COMPILES(r4, { kumi::windows<2>(std::move(r4)); });
};

TTS_CASE("Check constexpr kumi::chunks behavior on records")
{
  using namespace kumi;

  constexpr auto r1 = record{"a"_id = 1, "b"_id = 3.f, "c"_id = 5., "d"_id = 'x', "e"_id = short{77}};
  constexpr auto r2 =
    record{"a"_id = 112, "b"_id = -18.f, "c"_id = record{"d"_id = '1', "e"_id = long{22}, "f"_id = kumi::str{"Yes"}}};

  TTS_EQUAL((windows<1>(r1)), (make_tuple(record{"a"_id = 1}, record{"b"_id = 3.f}, record{"c"_id = 5.},
                                          record{"d"_id = 'x'}, record{"e"_id = short{77}})));

  TTS_EQUAL(
    (windows<2>(r2)),
    (make_tuple(record{"a"_id = 112, "b"_id = -18.f},
                record{"b"_id = -18.f, "c"_id = record{"d"_id = '1', "e"_id = long{22}, "f"_id = str{"Yes"}}})));
};
