//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/minmax.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::min/min_flat<...> behavior")
{
  [[maybe_unused]] auto func = [](auto m) { return sizeof(m); };
  using func_t = decltype(func);

  TTS_TYPE_IS((kumi::result::min_t<kumi::array<int, 4>>), int);

  TTS_TYPE_IS((kumi::result::min_t<kumi::array<int, 4>, func_t>), std::size_t);

  TTS_TYPE_IS((kumi::result::min_flat_t<kumi::array<int, 4>, func_t>), std::size_t);

  TTS_TYPE_IS((kumi::result::min_flat_t<kumi::array<kumi::array<int, 3>, 3>, func_t>), std::size_t);
};

TTS_CASE("Check array::min/min_flat behavior")
{
  auto t0 = kumi::array{10, 2, 1, 55, 100};
  TTS_EQUAL(kumi::min(t0), 1);
  TTS_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(int));

  auto f0 = kumi::array{kumi::array{5, 4, 3}, kumi::array{2, 1, 0}, kumi::array{9, 8, 7}};
  auto fcp = f0;

  TTS_EQUAL((kumi::min(f0, [](auto m) { return sizeof(m); })), 3 * sizeof(int));
  TTS_EQUAL((kumi::min_flat(f0, [](auto m) { return sizeof(m); })), sizeof(int));

  TTS_EQUAL((kumi::min(std::move(f0), [](auto m) { return sizeof(m); })), 3 * sizeof(int));
  TTS_EQUAL((kumi::min_flat(std::move(fcp), [](auto m) { return sizeof(m); })), sizeof(int));

  auto t1 = kumi::array{1, 3, 8, -3, 2, 0};
  TTS_EQUAL((kumi::min(t1, [](auto m) { return m < 0 ? -m : m; })), 0);
};

TTS_CASE("Check array::min/min_flat constexpr behavior")
{
  constexpr auto t0 = kumi::array{10, 2, 1, 55, 100};
  TTS_CONSTEXPR_EQUAL(kumi::min(t0), 1);
  TTS_CONSTEXPR_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(int));

  constexpr auto f0 = kumi::array{kumi::array{5, 4, 3}, kumi::array{2, 1, 0}, kumi::array{9, 8, 7}};
  TTS_CONSTEXPR_EQUAL((kumi::min(f0, [](auto m) { return sizeof(m); })), 3 * sizeof(int));
  TTS_CONSTEXPR_EQUAL((kumi::min_flat(f0, [](auto m) { return sizeof(m); })), sizeof(int));

  constexpr auto t1 = kumi::array{1, 3, 8, -3, 2, 0};
  TTS_CONSTEXPR_EQUAL((kumi::min(t1, [](auto m) { return m < 0 ? -m : m; })), 0);
};
