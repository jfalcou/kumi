//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <vector>
#include "test.hpp"

TTS_CASE("Check result::flatten/flatten_all<Tuple> behavior")
{
  TTS_TYPE_IS((kumi::result::flatten_t<kumi::tuple<char, short, int, double>>),
              (kumi::tuple<char, short, int, double>));

  TTS_TYPE_IS((kumi::result::flatten_t<kumi::tuple<char, kumi::tuple<short, int, kumi::tuple<double>>>>),
              (kumi::tuple<char, short, int, kumi::tuple<double>>));

  TTS_TYPE_IS(
    (kumi::result::flatten_all_t<kumi::tuple<kumi::tuple<char, short>, kumi::tuple<int, kumi::tuple<double>>>>),
    (kumi::tuple<char, short, int, double>));

  auto func = [](auto& m) { return &m; };
  auto cfunc = [](auto const& m) { return &m; };
  using func_t = decltype(func);
  using cfunc_t = decltype(cfunc);

  TTS_TYPE_IS(
    (kumi::result::flatten_all_t<kumi::tuple<kumi::tuple<char, short>, kumi::tuple<int, kumi::tuple<double>>>, func_t>),
    (kumi::tuple<char*, short*, int*, double*>));

  TTS_TYPE_IS((kumi::result::flatten_all_t<kumi::tuple<kumi::tuple<char, short>, kumi::tuple<int, kumi::tuple<double>>>,
                                           cfunc_t>),
              (kumi::tuple<char const*, short const*, int const*, double const*>));
};

TTS_CASE("Check tuple::flatten behavior")
{
  TTS_EQUAL(kumi::flatten(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL((kumi::flatten(kumi::tuple{2., 1, short{55}})), (kumi::tuple{2., 1, short{55}}));
  TTS_EQUAL((kumi::flatten(kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'})),
            (kumi::tuple{3.25f, 2., 1, short{55}, 'z'}));
  TTS_EQUAL((kumi::flatten(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'})),
            (kumi::tuple{3.25f, 2., kumi::tuple{2., 1, short{55}}, short{55}, 'z'}));

  auto t = kumi::tuple{1.f, 'x', short{66}, moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::flatten(std::move(t)); });
};

TTS_CASE("Check tuple::flatten constexpr behavior")
{
  constexpr auto t0 = kumi::tuple{2., 1, short{55}};
  constexpr auto t1 = kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'};
  constexpr auto t2 = kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten(kumi::tuple{}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t0), (kumi::tuple{2., 1, short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t1), (kumi::tuple{3.25f, 2., 1, short{55}, 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten(t2), (kumi::tuple{3.25f, 2., kumi::tuple{2., 1, short{55}}, short{55}, 'z'}));
};

TTS_CASE("Check tuple::flatten_all behavior")
{
  TTS_EQUAL(kumi::flatten_all(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL((kumi::flatten_all(kumi::tuple{kumi::tuple{}, kumi::tuple{}, kumi::tuple{}})), kumi::tuple{});
  TTS_EQUAL((kumi::flatten_all(kumi::tuple{2., 1, short{55}})), (kumi::tuple{2., 1, short{55}}));
  TTS_EQUAL((kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'})),
            (kumi::tuple{3.25f, 2., 1, short{55}, 'z'}));
  TTS_EQUAL((kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'z'})),
            (kumi::tuple{3.25f, 2., 2., 1, short{55}, short{55}, 'z'}));
  TTS_EQUAL((kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{}, short{55}}, 'z'})),
            (kumi::tuple{3.25f, 2., short{55}, 'z'}));

  auto t = kumi::tuple{1.f, 'x', short{66}, moveonly{}, kumi::tuple{3., moveonly{}}};
  TTS_EXPECT_COMPILES(t, { kumi::flatten_all(std::move(t)); });
};

TTS_CASE("Check tuple::flatten_all + function behavior")
{
  auto inc = [](auto m) { return m + 1; };

  TTS_EQUAL(kumi::flatten_all(kumi::tuple{}, inc), kumi::tuple{});

  TTS_EQUAL((kumi::flatten_all(kumi::tuple{kumi::tuple{}, kumi::tuple{}, kumi::tuple{}}, inc)), kumi::tuple{});

  TTS_EQUAL((kumi::flatten_all(kumi::tuple{2., 1, short{55}}, inc)), (kumi::tuple{3., 2, short{56}}));

  TTS_EQUAL((kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'a'}, inc)),
            (kumi::tuple{4.25f, 3., 2, short{56}, 'b'}));

  TTS_EQUAL(
    (kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'a'}, inc)),
    (kumi::tuple{4.25f, 3., 3., 2, short{56}, short{56}, 'b'}));

  TTS_EQUAL((kumi::flatten_all(kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{}, short{55}}, 'a'}, inc)),
            (kumi::tuple{4.25f, 3., short{56}, 'b'}));
};

TTS_CASE("Check tuple::flatten_all constexpr behavior")
{
  constexpr auto t0 = kumi::tuple{2., 1, short{55}};
  constexpr auto t1 = kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'z'};
  constexpr auto t2 = kumi::tuple{3.25f, t0, t1, 'z'};
  constexpr auto te = kumi::tuple{3.25f, kumi::tuple{}, 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::tuple{}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0), (kumi::tuple{2., 1, short{55}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1), (kumi::tuple{3.25f, 2., 1, short{55}, 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te), (kumi::tuple{3.25f, 'z'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2), (kumi::tuple{3.25f, 2., 1, short{55}, 3.25f, 2., 1, short{55}, 'z', 'z'}));
};

TTS_CASE("Check tuple::flatten_all + function constexpr behavior")
{
  constexpr auto t0 = kumi::tuple{2., 1, short{55}};
  constexpr auto t1 = kumi::tuple{3.25f, kumi::tuple{2., 1, short{55}}, 'a'};
  constexpr auto t2 = kumi::tuple{3.25f, t0, t1, 'a'};
  constexpr auto te = kumi::tuple{3.25f, kumi::tuple{}, 'a'};

  auto inc = [](auto m) { return m + 1; };

  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(kumi::tuple{}, inc), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t0, inc), (kumi::tuple{3., 2, short{56}}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t1, inc), (kumi::tuple{4.25f, 3., 2, short{56}, 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(te, inc), (kumi::tuple{4.25f, 'b'}));
  TTS_CONSTEXPR_EQUAL(kumi::flatten_all(t2, inc),
                      (kumi::tuple{4.25f, 3., 2, short{56}, 4.25f, 3., 2, short{56}, 'b', 'b'}));
};
