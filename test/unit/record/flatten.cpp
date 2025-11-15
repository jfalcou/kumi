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

using namespace kumi::literals;

TTS_CASE("Check result::flatten/flatten_all<record> behavior")
{
  using char_f      = kumi::field_capture<"a", char>;
  using short_f     = kumi::field_capture<"b", short>;
  using int_f       = kumi::field_capture<"c", int>;
  using double_f    = kumi::field_capture<"d", double>;
  
  TTS_TYPE_IS( (kumi::result::flatten_t<kumi::record<>>), (kumi::record<>));

  TTS_TYPE_IS ( (kumi::result::flatten_t<kumi::record<char_f,short_f,int_f,double_f>>)
              , (kumi::record<char_f,short_f,int_f,double_f>)
              );

  TTS_TYPE_IS ( (kumi::result::flatten_t<kumi::record<char_f
                                                    , kumi::field_capture<"e"
                                                        , kumi::record<short_f,int_f, kumi::field_capture<"f"
                                                            , kumi::record<double_f>>
                                                        >
                                                    >
                                                >>)

              , (kumi::record<char_f,
                              kumi::field_capture<"e.b", short>,
                              kumi::field_capture<"e.c",int>, 
                              kumi::field_capture<"e.f", kumi::record<double_f>>>)
              );
  
  auto func     = [](auto& m)        { return &m; };
  auto cfunc    = [](auto const& m)  { return &m; };
  using func_t  = decltype(func);
  using cfunc_t = decltype(cfunc);

  TTS_TYPE_IS ( (kumi::result::flatten_all_t<kumi::record<kumi::field_capture<"e", kumi::record<char_f,short_f>>
                                                        , kumi::field_capture<"f", kumi::record<int_f, kumi::field_capture<"g", kumi::record<double_f>>>>
                                                        >
                                            , func_t
                                            >
                )
              , (kumi::record<kumi::field_capture<"e.a",char*>,kumi::field_capture<"e.b",short*>,kumi::field_capture<"f.c", int*>,kumi::field_capture<"f.g.d", double*>>)
              );

  TTS_TYPE_IS ( (kumi::result::flatten_all_t<kumi::record< kumi::field_capture<"e", kumi::record<char_f,short_f>>
                                                        , kumi::field_capture<"g",  kumi::record<int_f, kumi::field_capture<"f",kumi::record<double_f>>>>
                                                        >
                                            , cfunc_t
                                            >
                )
              , (kumi::record<kumi::field_capture<"e.a",char const*>,kumi::field_capture<"e.b", short const*>,kumi::field_capture<"g.c", int const*>,kumi::field_capture<"g.f.d", double const*>>)
              );
};

TTS_CASE("Check record::flatten behavior")
{
  TTS_EQUAL( kumi::flatten(kumi::record {}), kumi::record {});
  TTS_EQUAL((kumi::flatten(kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}})), (kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}}));
  TTS_EQUAL((kumi::flatten(kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = 1, "e"_f = short {55}}, "f"_f = 'z'})),
            (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d"_f = 1, "b.e"_f = short {55}, "f"_f = 'z'}));
  TTS_EQUAL((kumi::flatten(kumi::record {
                "a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "h"_f = short {55}}, "i"_f = 'z'})),
            (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "b.h"_f = short {55}, "i"_f  = 'z'}));
};

TTS_CASE("Check record::flatten constexpr behavior")
{
  constexpr auto t0 = kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}};
  constexpr auto t1 = kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = 1, "e"_f = short {55}}, "f"_f = 'z'};
  constexpr auto t2 =
      kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "h"_f = short {55}}, "i"_f = 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten(kumi::record{}), kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t0), (kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t1), (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d"_f = 1, "b.e"_f = short {55}, "f"_f = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t2),
                      (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "b.h"_f = short {55}, "i"_f = 'z'}));
};


TTS_CASE("Check record::flatten_all behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL( kumi::flatten_all(kumi::record{}),kumi::record{});
  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_f = kumi::record{},"b"_f = kumi::record{},"c"_f = kumi::record{}})),kumi::record{});
  TTS_EQUAL((kumi::flatten_all(kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}})),
            (kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}}));
  TTS_EQUAL((kumi::flatten_all(kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = 1, "e"_f = short {55}}, "f"_f = 'z'})),
            (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d"_f = 1, "b.e"_f = short {55}, "f"_f = 'z'}));
  TTS_EQUAL((kumi::flatten_all(kumi::record {
                "a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "h"_f = short {55}}, "i"_f = 'z'})),
            (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.d.e"_f = 2., "b.d.f"_f = 1, "b.d.g"_f = short {55}, "b.h"_f = short {55}, "i"_f = 'z'}));
  TTS_EQUAL((kumi::flatten_all(kumi::record {
                "a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record{}, "e"_f = short {55}}, "f"_f = 'z'})),
            (kumi::record {"a"_f = 3.25f, "b.c"_f = 2., "b.e"_f = short {55}, "f"_f = 'z'}));
};

TTS_CASE("Check record::flatten_all constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}};
  constexpr auto t1 = kumi::record {"d"_f = 3.25f, "e"_f = kumi::record {"f"_f = 2., "g"_f = 1, "h"_f = short {55}},"i"_f = 'z'};
  constexpr auto t2 = kumi::record {"j"_f = 3.25f, "k"_f = t0, "l"_f = t1, "m"_f = 'z'};
  constexpr auto te = kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {}, "c"_f = 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::record{}),kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0), (kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1), (kumi::record {"d"_f = 3.25f, "e.f"_f = 2., "e.g"_f = 1, "e.h"_f = short {55}, "i"_f = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te), (kumi::record {"a"_f = 3.25f, "c"_f = 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2),
                      (kumi::record {"j"_f = 3.25f, "k.a"_f = 2., "k.b"_f = 1, "k.c"_f = short {55}, "l.d"_f = 3.25f, "l.e.f"_f = 2., "l.e.g"_f = 1, "l.e.h"_f = short {55}, "l.i"_f = 'z', "m"_f = 'z'}));
};


TTS_CASE("Check record::flatten_all + function behavior")
{
  auto inc = [](auto m) { return m+1; };

  TTS_EQUAL( kumi::flatten_all(kumi::record{}, inc),kumi::record{});
  
  TTS_EQUAL((kumi::flatten_all(kumi::record{"a"_f = kumi::record{},"b"_f = kumi::record{}, "c"_f = kumi::record{}},inc))
            ,kumi::record{}
            );

  TTS_EQUAL((kumi::flatten_all(kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}}, inc)),
            (kumi::record {"a"_f = 3., "b"_f = 2, "c"_f = short {56}}));

  TTS_EQUAL((kumi::flatten_all(kumi::record {"a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = 1, "e"_f = short {55}}, "f"_f = 'a'}, inc)),
            (kumi::record {"a"_f = 4.25f, "b.c"_f = 3., "b.d"_f = 2, "b.e"_f = short {56}, "f"_f = 'b'}));

  TTS_EQUAL((kumi::flatten_all(kumi::record {
                "a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record {"e"_f = 2., "f"_f = 1, "g"_f = short {55}}, "h"_f = short {55}}, "i"_f = 'a'}, inc)),
            (kumi::record {"a"_f = 4.25f, "b.c"_f = 3., "b.d.e"_f = 3., "b.d.f"_f = 2, "b.d.g"_f = short {56}, "b.h"_f = short {56}, "i"_f = 'b'}));

  TTS_EQUAL((kumi::flatten_all(kumi::record {
                "a"_f = 3.25f, "b"_f = kumi::record {"c"_f = 2., "d"_f = kumi::record{}, "e"_f = short {55}}, "f"_f = 'a'}, inc)),
            (kumi::record {"a"_f = 4.25f, "b.c"_f = 3.,"b.e"_f = short {56}, "f"_f = 'b'}));
};


TTS_CASE("Check record::flatten_all + function constexpr behavior")
{
  constexpr auto t0 = kumi::record {"a"_f = 2., "b"_f = 1, "c"_f = short {55}};
  constexpr auto t1 = kumi::record {"d"_f = 3.25f, "e"_f = kumi::record {"f"_f = 2., "g"_f = 1, "h"_f = short {55}}, "i"_f = 'a'};
  constexpr auto t2 = kumi::record {"j"_f = 3.25f, "k"_f = t0, "l"_f = t1, "m"_f = 'a'};
  constexpr auto te = kumi::record {"n"_f = 3.25f, "o"_f = kumi::record {}, "p"_f = 'a'};

  auto inc = [](auto m) { return m+1; };

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::record{}, inc),kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0, inc), (kumi::record {"a"_f = 3., "b"_f = 2, "c"_f = short {56}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1, inc), (kumi::record {"d"_f = 4.25f, "e.f"_f = 3., "e.g"_f = 2, "e.h"_f = short {56}, "i"_f = 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te, inc), (kumi::record {"n"_f = 4.25f, "p"_f = 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2, inc),
                      (kumi::record {"j"_f = 4.25f, "k.a"_f = 3., "k.b"_f = 2, "k.c"_f = short {56}, "l.d"_f = 4.25f, "l.e.f"_f = 3., "l.e.g"_f = 2, "l.e.h"_f = short {56}, "l.i"_f = 'b', "m"_f = 'b'}));
};
