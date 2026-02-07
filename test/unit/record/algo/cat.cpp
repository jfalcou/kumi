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

TTS_CASE("Check result::cat<record...> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;
  using short_ref_f = kumi::field<kumi::name<"f">, short&>;
  using int_ref_f = kumi::field<kumi::name<"g">, int&>;
  using char_ref_f = kumi::field<kumi::name<"h">, char&>;
  using char_rv_f = kumi::field<kumi::name<"i">, char&&>;

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<>, kumi::record<char_f, short_f, int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_f>, kumi::record<short_f, int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_f, short_f>, kumi::record<int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_f>, kumi::record<short_f>, kumi::record<int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_f, short_ref_f>, kumi::record<int_ref_f, double_f>>),
              (kumi::record<char_f, short_ref_f, int_ref_f, double_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_rv_f>&&>), (kumi::record<char_rv_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_rv_f>&&, kumi::record<char_ref_f>&, kumi::record<char_f>&>),
              (kumi::record<char_rv_f, char_ref_f, char_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_rv_f>&&, kumi::record<char_ref_f>&&, kumi::record<char_f>&>),
              (kumi::record<char_rv_f, char_ref_f, char_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_rv_f>&&, kumi::record<char_ref_f>&, kumi::record<char_f>&&>),
              (kumi::record<char_rv_f, char_ref_f, char_f>));

  TTS_TYPE_IS((kumi::result::cat_t<kumi::record<char_rv_f>&&, kumi::record<char_ref_f>&&, kumi::record<char_f>&&>),
              (kumi::record<char_rv_f, char_ref_f, char_f>));
};

TTS_CASE("Check cat(record) behavior")
{
  using namespace kumi::literals;

  short s = 55;
  TTS_EQUAL((cat(kumi::record{}, kumi::record{})), (kumi::record{}));
  TTS_EQUAL((cat(kumi::record{"x"_n = 1, "y"_n = 2.}, kumi::record{})), (kumi::record{"x"_n = 1, "y"_n = 2.}));
  TTS_EQUAL((cat(kumi::record{}, kumi::record{"x"_n = 1, "y"_n = 2.})), (kumi::record{"x"_n = 1, "y"_n = 2.}));
  TTS_EQUAL((cat(kumi::record{"x"_n = 1}, kumi::record{"y"_n = 2., "z"_n = 3.f, "t"_n = 4})),
            (kumi::record{"x"_n = 1, "y"_n = 2., "z"_n = 3.f, "t"_n = 4}));
  TTS_EQUAL((cat(kumi::record{"x"_n = 1, "y"_n = 2.}, kumi::record{"z"_n = 3.f, "t"_n = 4})),
            (kumi::record{"x"_n = 1, "y"_n = 2., "z"_n = 3.f, "t"_n = 4}));
  TTS_EQUAL((cat(kumi::record{"a"_n = 1, "b"_n = 2.}, kumi::record{"c"_n = 3.f, "d"_n = 4},
                 kumi::record{"e"_n = s, "f"_n = 6.7})),
            (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = s, "f"_n = 6.7}));

  // Check behavior with record of references
  {
    auto ref = kumi::tie<"a"_n>(s);
    auto val = kumi::record<kumi::field<kumi::name<"b">, float const>>{3.14f};

    TTS_EQUAL(
      kumi::cat(ref, val),
      (kumi::record<kumi::field<kumi::name<"a">, short&>, kumi::field<kumi::name<"b">, float const>>{s, 3.14f}));
  }
  {
    auto ref = kumi::tie<"a"_n>(s);
    auto rref = kumi::record<kumi::field<kumi::name<"b">, short&&>>{std::move(s)};
    auto val = kumi::record<kumi::field<kumi::name<"c">, float const>>{3.14f};

    TTS_EQUAL(kumi::cat(ref, std::move(rref), val),
              (kumi::record<kumi::field<kumi::name<"a">, short&>, kumi::field<kumi::name<"b">, short&&>,
                            kumi::field<kumi::name<"c">, float const>>{s, std::move(s), 3.14f}));
  }
};

TTS_CASE("Check cat(record) constexpr behavior")
{
  using namespace kumi::literals;
  constexpr short s = 55;
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{}, kumi::record{})), (kumi::record{}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{"x"_n = 1, "y"_n = 2.}, kumi::record{})),
                      (kumi::record{"x"_n = 1, "y"_n = 2.}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{}, kumi::record{"x"_n = 1, "y"_n = 2.})),
                      (kumi::record{"x"_n = 1, "y"_n = 2.}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{"x"_n = 1}, kumi::record{"y"_n = 2., "z"_n = 3.f, "t"_n = 4})),
                      (kumi::record{"x"_n = 1, "y"_n = 2., "z"_n = 3.f, "t"_n = 4}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{"x"_n = 1, "y"_n = 2.}, kumi::record{"z"_n = 3.f, "t"_n = 4})),
                      (kumi::record{"x"_n = 1, "y"_n = 2., "z"_n = 3.f, "t"_n = 4}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::record{"a"_n = 1, "b"_n = 2.}, kumi::record{"c"_n = 3.f, "d"_n = 4},
                           kumi::record{"e"_n = s, "f"_n = 6.7})),
                      (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = s, "f"_n = 6.7}));
};
