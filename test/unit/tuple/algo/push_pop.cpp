//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::push_front/pop_front type computation")
{
  using namespace kumi::result;

  TTS_TYPE_IS((push_front_t<kumi::tuple<>, int>), kumi::tuple<int>);
  TTS_TYPE_IS((push_front_t<kumi::tuple<float>, int>), (kumi::tuple<int, float>));
  TTS_TYPE_IS((push_front_t<kumi::tuple<float, char>, int>), (kumi::tuple<int, float, char>));
  TTS_TYPE_IS((push_front_t<kumi::tuple<>, kumi::tuple<int>>), (kumi::tuple<kumi::tuple<int>>));

  TTS_TYPE_IS((pop_front_t<kumi::tuple<>>), kumi::tuple<>);
  TTS_TYPE_IS((pop_front_t<kumi::tuple<float>>), kumi::tuple<>);
  TTS_TYPE_IS((pop_front_t<kumi::tuple<float, char>>), kumi::tuple<char>);
  TTS_TYPE_IS((pop_front_t<kumi::tuple<int, float, char>>), (kumi::tuple<float, char>));
};

TTS_CASE("Check kumi::push_front function behavior")
{
  TTS_EQUAL((kumi::push_front(kumi::tuple{}, 4)), kumi::tuple{4});
  TTS_EQUAL((kumi::push_front(kumi::tuple{3.5}, 4)), (kumi::tuple{4, 3.5}));
  TTS_EQUAL((kumi::push_front(kumi::tuple{3.5, 'e'}, 4)), (kumi::tuple{4, 3.5, 'e'}));

  TTS_EQUAL(kumi::pop_front(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_front(kumi::tuple{3.5}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_front(kumi::tuple{3.5, 'e'}), kumi::tuple{'e'});
  TTS_EQUAL(kumi::pop_front(kumi::tuple{4, 3.5, 'e'}), (kumi::tuple{3.5, 'e'}));

  auto t = kumi::tuple{moveonly{}, 1.f, 'x'};
  TTS_EXPECT_COMPILES(t, { kumi::push_front(std::move(t), moveonly{}); });
  TTS_EXPECT_COMPILES(t, { kumi::pop_front(std::move(t)); });
};

TTS_CASE("Check kumi::push_front/pop_front constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::tuple{}, 4)), kumi::tuple{4});
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::tuple{3.5}, 4)), (kumi::tuple{4, 3.5}));
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::tuple{3.5, 'e'}, 4)), (kumi::tuple{4, 3.5, 'e'}));

  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::tuple{}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::tuple{3.5}), kumi::tuple{});
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::tuple{3.5, 'e'}), kumi::tuple{'e'});
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::tuple{4, 3.5, 'e'}), (kumi::tuple{3.5, 'e'}));
};

TTS_CASE("Check kumi::push_back/pop_back type computation")
{
  using namespace kumi::result;

  TTS_TYPE_IS((push_back_t<kumi::tuple<>, int>), kumi::tuple<int>);
  TTS_TYPE_IS((push_back_t<kumi::tuple<float>, int>), (kumi::tuple<float, int>));
  TTS_TYPE_IS((push_back_t<kumi::tuple<float, char>, int>), (kumi::tuple<float, char, int>));
  TTS_TYPE_IS((push_back_t<kumi::tuple<>, kumi::tuple<int>>), (kumi::tuple<kumi::tuple<int>>));

  TTS_TYPE_IS((pop_back_t<kumi::tuple<>>), kumi::tuple<>);
  TTS_TYPE_IS((pop_back_t<kumi::tuple<float>>), kumi::tuple<>);
  TTS_TYPE_IS((pop_back_t<kumi::tuple<float, char>>), kumi::tuple<float>);
  TTS_TYPE_IS((pop_back_t<kumi::tuple<int, float, char>>), (kumi::tuple<int, float>));
};

TTS_CASE("Check kumi::push_back/pop_back function behavior")
{
  TTS_EQUAL((kumi::push_back(kumi::tuple{}, 4)), kumi::tuple{4});
  TTS_EQUAL((kumi::push_back(kumi::tuple{3.5}, 4)), (kumi::tuple{3.5, 4}));
  TTS_EQUAL((kumi::push_back(kumi::tuple{3.5, 'e'}, 4)), (kumi::tuple{3.5, 'e', 4}));

  TTS_EQUAL(kumi::pop_back(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{3.5}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{3.5, 'e'}), kumi::tuple{3.5});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{4, 3.5, 'e'}), (kumi::tuple{4, 3.5}));

  auto t = kumi::tuple{moveonly{}, 1.f, 'x'};
  TTS_EXPECT_COMPILES(t, { kumi::push_back(std::move(t), moveonly{}); });
  TTS_EXPECT_COMPILES(t, { kumi::pop_back(std::move(t)); });
};

TTS_CASE("Check kumi::push_back/pop_back constexpr behavior")
{
  TTS_EQUAL((kumi::push_back(kumi::tuple{}, 4)), kumi::tuple{4});
  TTS_EQUAL((kumi::push_back(kumi::tuple{3.5}, 4)), (kumi::tuple{3.5, 4}));
  TTS_EQUAL((kumi::push_back(kumi::tuple{3.5, 'e'}, 4)), (kumi::tuple{3.5, 'e', 4}));

  TTS_EQUAL(kumi::pop_back(kumi::tuple{}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{3.5}), kumi::tuple{});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{3.5, 'e'}), kumi::tuple{3.5});
  TTS_EQUAL(kumi::pop_back(kumi::tuple{4, 3.5, 'e'}), (kumi::tuple{4, 3.5}));
};
