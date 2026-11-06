//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/inner_product.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::inner_product_t behavior")
{
  [[maybe_unused]] auto sfunc = [](auto a, auto b) { return sizeof(a) + sizeof(b); };
  [[maybe_unused]] auto pfunc = [](auto a, auto b) { return a * b; };
  using sfunc_t = decltype(sfunc);
  using pfunc_t = decltype(pfunc);

  TTS_TYPE_IS((kumi::result::inner_product_t<kumi::array<int, 2>, kumi::array<int, 2>, int>), int);

  TTS_TYPE_IS((kumi::result::inner_product_t<kumi::array<int, 2>, kumi::array<int, 2>, int, sfunc_t, pfunc_t>),
              std::size_t);
};

TTS_CASE("Check array::inner_product behavior")
{
  auto t1 = kumi::array{2, 4, 8};
  auto t2 = kumi::array{2, 4, 8};

  TTS_EQUAL(kumi::inner_product(t1, t2, 0), 84);
  TTS_EQUAL(
    kumi::inner_product(t1, t2, 1ULL, [](auto a, auto b) { return a * b; }, [](auto a, auto b) { return a + b; }), 512);
};

TTS_CASE("Check array::inner_product constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL(kumi::inner_product(kumi::array{2, 4, 8}, kumi::array{2, 4, 8}, 0), 84);
  TTS_CONSTEXPR_EQUAL(kumi::inner_product(
                        kumi::array{2, 4, 8}, kumi::array{2, 4, 8}, 1ULL, [](auto a, auto b) { return a * b; },
                        [](auto a, auto b) { return a + b; }),
                      512);
};
