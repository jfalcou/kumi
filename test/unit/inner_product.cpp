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

TTS_CASE("Check result::inner_product_t behavior")
{
  auto sum = [](auto a, auto b) { return sizeof(a) + sizeof(b); };
  auto prod = [](auto a, auto b) { return a * b; };
  using sfunc_t = decltype(sum);
  using pfunc_t = decltype(prod);

  TTS_TYPE_IS((kumi::result::inner_product_t<kumi::tuple<int, double>, kumi::tuple<char, short>, int>), double);

  TTS_TYPE_IS(
    (kumi::result::inner_product_t<kumi::tuple<int, double>, kumi::tuple<char, short>, int, sfunc_t, pfunc_t>),
    std::size_t);
};

TTS_CASE("Check tuple::inner_product behavior")
{
  auto t1 = kumi::tuple{2, 4, 8};
  auto t2 = kumi::tuple{2.5, 4.5, 7.5};

  TTS_EQUAL(kumi::inner_product(t1, t2, 0.f), 83);
  TTS_EQUAL(kumi::inner_product(
              t1, t2, 1ULL, [](auto a, auto b) { return a * b; }, [](auto a, auto b) { return a + b; }),
            592.875);
};

TTS_CASE("Check tuple::inner_product constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL(kumi::inner_product(kumi::tuple{2, 4, 8}, kumi::tuple{2.5, 4.5, 7.5}, 0.f), 83);
  TTS_CONSTEXPR_EQUAL(kumi::inner_product(
                        kumi::tuple{2, 4, 8}, kumi::tuple{2.5, 4.5, 7.5}, 1ULL, [](auto a, auto b) { return a * b; },
                        [](auto a, auto b) { return a + b; }),
                      592.875);
};
