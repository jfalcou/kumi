//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/scan.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check kumi::inclusive_scan_right behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  auto empty = kumi::inclusive_scan_right([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sum = kumi::inclusive_scan_right([](auto m, auto acc) { return m + acc; }, t, 0);
  TTS_EQUAL(sum, (kumi::tuple{10, 9, 7, 4}));
};

TTS_CASE("Check array::inclusive_scan_right constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::inclusive_scan_right([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto sum = kumi::inclusive_scan_right([](auto m, auto acc) { return m + acc; }, t, 0);
  TTS_CONSTEXPR_EQUAL(sum, (kumi::tuple{10, 9, 7, 4}));
};

TTS_CASE("Check kumi::exclusive_scan_right behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  auto empty = kumi::exclusive_scan_right([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sum = kumi::exclusive_scan_right([](auto m, auto acc) { return m + acc; }, t, 0);
  TTS_EQUAL(sum, (kumi::tuple{9, 7, 4, 0}));
};

TTS_CASE("Check array::exclusive_scan_right constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::exclusive_scan_right([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto sum = kumi::exclusive_scan_right([](auto m, auto acc) { return m + acc; }, t, 0);
  TTS_CONSTEXPR_EQUAL(sum, (kumi::tuple{9, 7, 4, 0}));
};

TTS_CASE("Check kumi::inclusive_scan_left behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  auto empty = kumi::inclusive_scan_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sum = kumi::inclusive_scan_left([](auto acc, auto m) { return acc + m; }, t, 0);
  TTS_EQUAL(sum, (kumi::tuple{1, 3, 6, 10}));
};

TTS_CASE("Check array::inclusive_scan_left constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::inclusive_scan_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto sum = kumi::inclusive_scan_left([](auto acc, auto m) { return acc + m; }, t, 0);
  TTS_CONSTEXPR_EQUAL(sum, (kumi::tuple{1, 3, 6, 10}));
};

TTS_CASE("Check kumi::exclusive_scan_left behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  auto empty = kumi::exclusive_scan_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_EQUAL(empty, kumi::tuple{});

  auto sum = kumi::exclusive_scan_left([](auto acc, auto m) { return acc + m; }, t, 0);
  TTS_EQUAL(sum, (kumi::tuple{0, 1, 3, 6}));
};

TTS_CASE("Check array::exclusive_scan_left constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  constexpr auto empty = kumi::exclusive_scan_left([](auto acc, auto) { return acc; }, kumi::array<int, 0>{}, 42);
  TTS_CONSTEXPR_EQUAL(empty, kumi::tuple{});

  constexpr auto sum = kumi::exclusive_scan_left([](auto acc, auto m) { return acc + m; }, t, 0);
  TTS_CONSTEXPR_EQUAL(sum, (kumi::tuple{0, 1, 3, 6}));
};
