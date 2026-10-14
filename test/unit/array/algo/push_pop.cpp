//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/push_pop.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::push_front/pop_front type computation")
{
  using namespace kumi::result;

  TTS_TYPE_IS((push_front_t<kumi::array<int, 0>, int>), (kumi::array<int, 1>));
  TTS_TYPE_IS((push_front_t<kumi::array<float, 1>, float>), (kumi::array<float, 2>));
  TTS_TYPE_IS((push_front_t<kumi::array<float, 2>, float>), (kumi::array<float, 3>));

  TTS_TYPE_IS((pop_front_t<kumi::array<int, 0>>), (kumi::array<>));
  TTS_TYPE_IS((pop_front_t<kumi::array<float, 1>>), (kumi::array<>));
  TTS_TYPE_IS((pop_front_t<kumi::array<float, 2>>), (kumi::array<float, 1>));
  TTS_TYPE_IS((pop_front_t<kumi::array<int, 3>>), (kumi::array<int, 2>));
};

TTS_CASE("Check kumi::push_front function behavior")
{
  TTS_EQUAL((kumi::push_front(kumi::array<int, 0>{}, 4)), (kumi::array{4}));
  TTS_EQUAL((kumi::push_front(kumi::array{3, 4}, 2)), (kumi::array{2, 3, 4}));

  TTS_EQUAL(kumi::pop_front(kumi::array<int, 0>{}), (kumi::array<int, 0>{}));
  TTS_EQUAL(kumi::pop_front(kumi::array{3}), (kumi::array<int, 0>{}));
  TTS_EQUAL(kumi::pop_front(kumi::array{3, 4}), (kumi::array{4}));
  TTS_EQUAL(kumi::pop_front(kumi::array{2, 3, 4}), (kumi::array{3, 4}));
};

TTS_CASE("Check kumi::push_front/pop_front constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::array<int, 0>{}, 4)), (kumi::array{4}));
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::array{3, 4}, 2)), (kumi::array{2, 3, 4}));

  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::array<int, 0>{}), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::array{3}), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::array{3, 4}), (kumi::array{4}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::array{2, 3, 4}), (kumi::array{3, 4}));
};

TTS_CASE("Check kumi::push_back/pop_back type computation")
{
  using namespace kumi::result;

  TTS_TYPE_IS((push_back_t<kumi::array<int, 0>, int>), (kumi::array<int, 1>));
  TTS_TYPE_IS((push_back_t<kumi::array<float, 1>, float>), (kumi::array<float, 2>));
  TTS_TYPE_IS((push_back_t<kumi::array<float, 2>, float>), (kumi::array<float, 3>));

  TTS_TYPE_IS((pop_back_t<kumi::array<int, 0>>), (kumi::array<>));
  TTS_TYPE_IS((pop_back_t<kumi::array<float, 1>>), (kumi::array<>));
  TTS_TYPE_IS((pop_back_t<kumi::array<float, 2>>), (kumi::array<float, 1>));
  TTS_TYPE_IS((pop_back_t<kumi::array<int, 3>>), (kumi::array<int, 2>));
};

TTS_CASE("Check kumi::push_back/pop_back function behavior")
{
  TTS_EQUAL((kumi::push_back(kumi::array<int, 0>{}, 4)), (kumi::array{4}));
  TTS_EQUAL((kumi::push_back(kumi::array{3, 4}, 5)), (kumi::array{3, 4, 5}));

  TTS_EQUAL(kumi::pop_back(kumi::array<int, 0>{}), (kumi::array<int, 0>{}));
  TTS_EQUAL(kumi::pop_back(kumi::array{3}), (kumi::array<int, 0>{}));
  TTS_EQUAL(kumi::pop_back(kumi::array{3, 4}), (kumi::array{3}));
  TTS_EQUAL(kumi::pop_back(kumi::array{2, 3, 4}), (kumi::array{2, 3}));
};

TTS_CASE("Check kumi::push_back/pop_back constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL((kumi::push_back(kumi::array<int, 0>{}, 4)), (kumi::array{4}));
  TTS_CONSTEXPR_EQUAL((kumi::push_back(kumi::array{3, 4}, 5)), (kumi::array{3, 4, 5}));

  TTS_CONSTEXPR_EQUAL(kumi::pop_back(kumi::array<int, 0>{}), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_back(kumi::array{3}), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_back(kumi::array{3, 4}), (kumi::array{3}));
  TTS_CONSTEXPR_EQUAL(kumi::pop_back(kumi::array{2, 3, 4}), (kumi::array{2, 3}));
};
