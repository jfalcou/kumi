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

using namespace kumi::literals;

TTS_CASE("Check result::flatten/flatten_all<record> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  TTS_TYPE_IS((kumi::result::flatten_t<kumi::record<>>), (kumi::record<>));

  TTS_TYPE_IS((kumi::result::flatten_t<kumi::record<char_f, short_f, int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS(
    (kumi::result::flatten_t<kumi::record<
       char_f, kumi::field<kumi::name<"e">,
                           kumi::record<short_f, int_f, kumi::field<kumi::name<"f">, kumi::record<double_f>>>>>>)

      ,
    (kumi::record<char_f, kumi::field<kumi::name<"e.b">, short>, kumi::field<kumi::name<"e.c">, int>,
                  kumi::field<kumi::name<"e.f">, kumi::record<double_f>>>));

  auto func = [](auto& m) { return &m; };
  auto cfunc = [](auto const& m) { return &m; };
  using func_t = decltype(func);
  using cfunc_t = decltype(cfunc);

  TTS_TYPE_IS(
    (kumi::result::flatten_all_t<
      kumi::record<
        kumi::field<kumi::name<"e">, kumi::record<char_f, short_f>>,
        kumi::field<kumi::name<"f">, kumi::record<int_f, kumi::field<kumi::name<"g">, kumi::record<double_f>>>>>,
      func_t>),
    (kumi::record<kumi::field<kumi::name<"e.a">, char*>, kumi::field<kumi::name<"e.b">, short*>,
                  kumi::field<kumi::name<"f.c">, int*>, kumi::field<kumi::name<"f.g.d">, double*>>));

  TTS_TYPE_IS(
    (kumi::result::flatten_all_t<
      kumi::record<
        kumi::field<kumi::name<"e">, kumi::record<char_f, short_f>>,
        kumi::field<kumi::name<"g">, kumi::record<int_f, kumi::field<kumi::name<"f">, kumi::record<double_f>>>>>,
      cfunc_t>),
    (kumi::record<kumi::field<kumi::name<"e.a">, char const*>, kumi::field<kumi::name<"e.b">, short const*>,
                  kumi::field<kumi::name<"g.c">, int const*>, kumi::field<kumi::name<"g.f.d">, double const*>>));
};

TTS_CASE("Check record::flatten behavior")
{
  TTS_EQUAL(kumi::flatten(kumi::record{}), kumi::record{});
  TTS_EQUAL((kumi::flatten(kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}})),
            (kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}}));
  TTS_EQUAL((kumi::flatten(kumi::record{"a"_n = 3.25f, "b"_n = kumi::record{"c"_n = 2., "d"_n = 1, "e"_n = short{55}},
                                        "f"_n = 'z'})),
            (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.d"_n = 1, "b.e"_n = short{55}, "f"_n = 'z'}));
  TTS_EQUAL((kumi::flatten(kumi::record{
              "a"_n = 3.25f,
              "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}},
                                   "h"_n = short{55}},
              "i"_n = 'z'})),
            (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}},
                          "b.h"_n = short{55}, "i"_n = 'z'}));
};

TTS_CASE("Check record::flatten constexpr behavior")
{
  constexpr auto t0 = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}};
  constexpr auto t1 =
    kumi::record{"a"_n = 3.25f, "b"_n = kumi::record{"c"_n = 2., "d"_n = 1, "e"_n = short{55}}, "f"_n = 'z'};
  constexpr auto t2 = kumi::record{
    "a"_n = 3.25f,
    "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}}, "h"_n = short{55}},
    "i"_n = 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten(kumi::record{}), kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t0), (kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t1),
                      (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.d"_n = 1, "b.e"_n = short{55}, "f"_n = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t2), (kumi::record{"a"_n = 3.25f, "b.c"_n = 2.,
                                                       "b.d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}},
                                                       "b.h"_n = short{55}, "i"_n = 'z'}));
};

TTS_CASE("Check record::flatten_all behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL(kumi::flatten_all(kumi::record{}), kumi::record{});
  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_n = kumi::record{}, "b"_n = kumi::record{}, "c"_n = kumi::record{}})),
            kumi::record{});
  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}})),
            (kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}}));
  TTS_EQUAL((kumi::flatten_all(kumi::record{
              "a"_n = 3.25f, "b"_n = kumi::record{"c"_n = 2., "d"_n = 1, "e"_n = short{55}}, "f"_n = 'z'})),
            (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.d"_n = 1, "b.e"_n = short{55}, "f"_n = 'z'}));
  TTS_EQUAL((kumi::flatten_all(kumi::record{
              "a"_n = 3.25f,
              "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}},
                                   "h"_n = short{55}},
              "i"_n = 'z'})),
            (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.d.e"_n = 2., "b.d.f"_n = 1, "b.d.g"_n = short{55},
                          "b.h"_n = short{55}, "i"_n = 'z'}));
  TTS_EQUAL(
    (kumi::flatten_all(kumi::record{
      "a"_n = 3.25f, "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{}, "e"_n = short{55}}, "f"_n = 'z'})),
    (kumi::record{"a"_n = 3.25f, "b.c"_n = 2., "b.e"_n = short{55}, "f"_n = 'z'}));
};

TTS_CASE("Check record::flatten_all constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}};
  constexpr auto t1 =
    kumi::record{"d"_n = 3.25f, "e"_n = kumi::record{"f"_n = 2., "g"_n = 1, "h"_n = short{55}}, "i"_n = 'z'};
  constexpr auto t2 = kumi::record{"j"_n = 3.25f, "k"_n = t0, "l"_n = t1, "m"_n = 'z'};
  constexpr auto te = kumi::record{"a"_n = 3.25f, "b"_n = kumi::record{}, "c"_n = 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::record{}), kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0), (kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1),
                      (kumi::record{"d"_n = 3.25f, "e.f"_n = 2., "e.g"_n = 1, "e.h"_n = short{55}, "i"_n = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te), (kumi::record{"a"_n = 3.25f, "c"_n = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2),
                      (kumi::record{"j"_n = 3.25f, "k.a"_n = 2., "k.b"_n = 1, "k.c"_n = short{55}, "l.d"_n = 3.25f,
                                    "l.e.f"_n = 2., "l.e.g"_n = 1, "l.e.h"_n = short{55}, "l.i"_n = 'z', "m"_n = 'z'}));
};

TTS_CASE("Check record::flatten_all + function behavior")
{
  auto inc = [](auto m) { return m + 1; };

  TTS_EQUAL(kumi::flatten_all(kumi::record{}, inc), kumi::record{});

  TTS_EQUAL(
    (kumi::flatten_all(kumi::record{"a"_n = kumi::record{}, "b"_n = kumi::record{}, "c"_n = kumi::record{}}, inc)),
    kumi::record{});

  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}}, inc)),
            (kumi::record{"a"_n = 3., "b"_n = 2, "c"_n = short{56}}));

  TTS_EQUAL(
    (kumi::flatten_all(
      kumi::record{"a"_n = 3.25f, "b"_n = kumi::record{"c"_n = 2., "d"_n = 1, "e"_n = short{55}}, "f"_n = 'a'}, inc)),
    (kumi::record{"a"_n = 4.25f, "b.c"_n = 3., "b.d"_n = 2, "b.e"_n = short{56}, "f"_n = 'b'}));

  TTS_EQUAL(
    (kumi::flatten_all(
      kumi::record{"a"_n = 3.25f,
                   "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{"e"_n = 2., "f"_n = 1, "g"_n = short{55}},
                                        "h"_n = short{55}},
                   "i"_n = 'a'},
      inc)),
    (kumi::record{"a"_n = 4.25f, "b.c"_n = 3., "b.d.e"_n = 3., "b.d.f"_n = 2, "b.d.g"_n = short{56},
                  "b.h"_n = short{56}, "i"_n = 'b'}));

  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_n = 3.25f,
                                            "b"_n = kumi::record{"c"_n = 2., "d"_n = kumi::record{}, "e"_n = short{55}},
                                            "f"_n = 'a'},
                               inc)),
            (kumi::record{"a"_n = 4.25f, "b.c"_n = 3., "b.e"_n = short{56}, "f"_n = 'b'}));
};

TTS_CASE("Check record::flatten_all + function constexpr behavior")
{
  constexpr auto t0 = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}};
  constexpr auto t1 =
    kumi::record{"d"_n = 3.25f, "e"_n = kumi::record{"f"_n = 2., "g"_n = 1, "h"_n = short{55}}, "i"_n = 'a'};
  constexpr auto t2 = kumi::record{"j"_n = 3.25f, "k"_n = t0, "l"_n = t1, "m"_n = 'a'};
  constexpr auto te = kumi::record{"n"_n = 3.25f, "o"_n = kumi::record{}, "p"_n = 'a'};

  auto inc = [](auto m) { return m + 1; };

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::record{}, inc), kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0, inc), (kumi::record{"a"_n = 3., "b"_n = 2, "c"_n = short{56}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1, inc),
                      (kumi::record{"d"_n = 4.25f, "e.f"_n = 3., "e.g"_n = 2, "e.h"_n = short{56}, "i"_n = 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te, inc), (kumi::record{"n"_n = 4.25f, "p"_n = 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2, inc),
                      (kumi::record{"j"_n = 4.25f, "k.a"_n = 3., "k.b"_n = 2, "k.c"_n = short{56}, "l.d"_n = 4.25f,
                                    "l.e.f"_n = 3., "l.e.g"_n = 2, "l.e.h"_n = short{56}, "l.i"_n = 'b', "m"_n = 'b'}));
};
