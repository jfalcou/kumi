//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

enum Direction
{
  left,
  right
};

template<Direction d> struct sizeof_monoid
{
  template<typename T1, typename T2> constexpr auto operator()([[maybe_unused]] T1&& a, [[maybe_unused]] T2&& b)
  {
    if constexpr (d == Direction::left) return sizeof(b);
    else return sizeof(a);
  };

  static constexpr std::size_t identity = 0;
};

template<Direction d> struct acc_monoid
{
  template<typename T1, typename T2> constexpr auto operator()(T1&& a, T2&& b)
  {
    if constexpr (d == Direction::left) return a + sizeof(b);
    else return b + sizeof(a);
  };

  static constexpr std::size_t identity = 0;
};

TTS_CASE("Check result::inclusive_scan_right/inclusive_scan_left<...> behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;

  using right_func_t = acc_monoid<Direction::right>;
  using left_func_t = acc_monoid<Direction::left>;

  TTS_TYPE_IS((kumi::result::inclusive_scan_right_t<right_func_t, kumi::tuple<char, short, int, double>, int>),
              res_tuple);
  TTS_TYPE_IS((kumi::result::inclusive_scan_left_t<left_func_t, kumi::tuple<char, short, int, double>, int>),
              res_tuple);

  TTS_TYPE_IS((kumi::result::inclusive_scan_right_t<right_func_t, kumi::tuple<char, short, int, double>>), res_tuple);
  TTS_TYPE_IS((kumi::result::inclusive_scan_left_t<left_func_t, kumi::tuple<char, short, int, double>>), res_tuple);

  TTS_TYPE_IS((kumi::result::exclusive_scan_right_t<right_func_t, kumi::tuple<char, short, int, double>, std::size_t>),
              res_tuple);
  TTS_TYPE_IS((kumi::result::exclusive_scan_left_t<left_func_t, kumi::tuple<char, short, int, double>, std::size_t>),
              res_tuple);

  TTS_TYPE_IS((kumi::result::exclusive_scan_right_t<right_func_t, kumi::tuple<char, short, int, double>>), res_tuple);
  TTS_TYPE_IS((kumi::result::exclusive_scan_left_t<left_func_t, kumi::tuple<char, short, int, double>>), res_tuple);
};

TTS_CASE("Check kumi::inclusive_scan_right behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;
  auto t = kumi::tuple{2., 1, short{55}, 'z'};

  auto empty = kumi::inclusive_scan_right([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sizeof_init = kumi::inclusive_scan_right([](auto m, auto) { return sizeof(m); }, t, 0);

  auto sizeof_raw = kumi::inclusive_scan_right(sizeof_monoid<Direction::right>{}, t);

  auto accumulated_init = kumi::inclusive_scan_right([](auto m, auto acc) { return acc + sizeof(m); }, t, 0);

  auto accumulated_raw = kumi::inclusive_scan_right(acc_monoid<Direction::right>{}, t);

  TTS_EQUAL(sizeof_init, (res_tuple{8, 4, 2, 1}));
  TTS_EQUAL(sizeof_raw, (res_tuple{8, 4, 2, 1}));

  TTS_EQUAL(accumulated_init, (res_tuple{15, 7, 3, 1}));
  TTS_EQUAL(accumulated_raw, (res_tuple{15, 7, 3, 1}));
};

TTS_CASE("Check tuple::inclusive_scan_right constexpr behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;

  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};

  constexpr auto empty = kumi::inclusive_scan_right([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto accumulated = kumi::inclusive_scan_right([](auto m, auto) { return sizeof(m); }, t, 0);

  TTS_CONSTEXPR_EQUAL(accumulated, (res_tuple{8, 4, 2, 1}));
};

TTS_CASE("Check kumi::exclusive_scan_right behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;
  auto t = kumi::tuple{2., 1, short{55}, 'z'};

  auto empty = kumi::exclusive_scan_right([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, kumi::tuple{42});

  auto sizeof_init = kumi::exclusive_scan_right([](auto m, auto) { return sizeof(m); }, t, std::size_t{0});

  auto sizeof_raw = kumi::exclusive_scan_right(sizeof_monoid<Direction::right>{}, t);

  auto accumulated_init =
    kumi::exclusive_scan_right([](auto m, auto acc) { return acc + sizeof(m); }, t, std::size_t{0});

  auto accumulated_raw = kumi::exclusive_scan_right(acc_monoid<Direction::right>{}, t);

  TTS_EQUAL(sizeof_init, (res_tuple{4, 2, 1, 0}));
  TTS_EQUAL(sizeof_raw, (res_tuple{4, 2, 1, 0}));

  TTS_EQUAL(accumulated_init, (res_tuple{7, 3, 1, 0}));
  TTS_EQUAL(accumulated_raw, (res_tuple{7, 3, 1, 0}));
};

TTS_CASE("Check tuple::exclusive_scan_right constexpr behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;

  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};

  constexpr auto empty = kumi::exclusive_scan_right([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{42});

  constexpr auto accumulated = kumi::exclusive_scan_right([](auto m, auto) { return sizeof(m); }, t, std::size_t{0});

  TTS_CONSTEXPR_EQUAL(accumulated, (res_tuple{4, 2, 1, 0}));
};

TTS_CASE("Check kumi::inclusive_scan_left behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;
  auto t = kumi::tuple{2., 1, short{55}, 'z'};

  auto empty = kumi::inclusive_scan_left([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sizeof_init = kumi::inclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, 0);

  auto sizeof_raw = kumi::inclusive_scan_left(sizeof_monoid<Direction::left>{}, t);

  auto accumulated_init = kumi::inclusive_scan_left([](auto acc, auto m) { return acc + sizeof(m); }, t, 0);

  auto accumulated_raw = kumi::inclusive_scan_left(acc_monoid<Direction::left>{}, t);

  TTS_EQUAL(sizeof_init, (res_tuple{8, 4, 2, 1}));
  TTS_EQUAL(sizeof_raw, (res_tuple{8, 4, 2, 1}));

  TTS_EQUAL(accumulated_init, (res_tuple{8, 12, 14, 15}));
  TTS_EQUAL(accumulated_raw, (res_tuple{8, 12, 14, 15}));
};

TTS_CASE("Check tuple::inclusive_scan_left constexpr behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;

  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};

  constexpr auto empty = kumi::inclusive_scan_left([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto accumulated = kumi::inclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, 0);

  TTS_CONSTEXPR_EQUAL(accumulated, (res_tuple{8, 4, 2, 1}));
};

TTS_CASE("Check kumi::exclusive_scan_left behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;
  auto t = kumi::tuple{2., 1, short{55}, 'z'};

  auto empty = kumi::exclusive_scan_left([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_EQUAL(empty, kumi::tuple{42});

  auto sizeof_init = kumi::exclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, std::size_t{0});

  auto sizeof_raw = kumi::exclusive_scan_left(sizeof_monoid<Direction::left>{}, t);

  auto accumulated_init =
    kumi::exclusive_scan_left([](auto acc, auto m) { return acc + sizeof(m); }, t, std::size_t{0});

  auto accumulated_raw = kumi::exclusive_scan_left(acc_monoid<Direction::left>{}, t);

  TTS_EQUAL(sizeof_init, (res_tuple{0, 8, 4, 2}));
  TTS_EQUAL(sizeof_raw, (res_tuple{0, 8, 4, 2}));

  TTS_EQUAL(accumulated_init, (res_tuple{0, 8, 12, 14}));
  TTS_EQUAL(accumulated_raw, (res_tuple{0, 8, 12, 14}));
};

TTS_CASE("Check tuple::exclusive_scan_left constexpr behavior")
{
  using res_tuple = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;

  constexpr auto t = kumi::tuple{2., 1, short{55}, 'z'};

  constexpr auto empty = kumi::exclusive_scan_left([](auto acc, auto) { return acc; }, kumi::tuple{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{42});

  constexpr auto accumulated = kumi::exclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, std::size_t{0});

  TTS_CONSTEXPR_EQUAL(accumulated, (res_tuple{0, 8, 4, 2}));
};
