//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <vector>

TTS_CASE("Check result::min/min_flat<...> behavior")
{
  auto lambda = [](auto m) { return sizeof(m); };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::min_t<kumi::tuple<char,short,int,double>,func_t>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::min_flat_t<kumi::tuple<char,short,int,double>,func_t>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::min_flat_t<kumi::tuple<char,kumi::tuple<short,int>,double>,func_t>)
              , std::size_t
              );
};

TTS_CASE("Check tuple::min/min_flat behavior")
{
  auto t0 = kumi::tuple {'e', 2., 1, short {55}, 'z'};
  TTS_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(char));

  auto f0 = kumi::tuple {2., 1.,  kumi::tuple{'u','z'}, 3.f};
  TTS_EQUAL((kumi::min      (f0 , [](auto m) { return sizeof(m); })), 2*sizeof(char));
  TTS_EQUAL((kumi::min_flat (f0 , [](auto m) { return sizeof(m); })),   sizeof(char));

  auto t1 = kumi::tuple {1.5,3.6f,8,-3.6,2.4,-0.5};
  TTS_EQUAL((kumi::min(t1, [](auto m) { return m<0 ? -m : m; })), 0.5);
};

TTS_CASE("Check tuple::min/min_flat constexpr behavior")
{
  constexpr auto t0 = kumi::tuple {'e', 2., 1, short {55}, 'z'};
  TTS_CONSTEXPR_EQUAL((kumi::min(t0, [](auto m) { return sizeof(m); })), sizeof(char));

  constexpr auto f0 = kumi::tuple {2., 1.,  kumi::tuple{'u','z'}, 3.f};
  TTS_CONSTEXPR_EQUAL((kumi::min      (f0 , [](auto m) { return sizeof(m); })), 2*sizeof(char));
  TTS_CONSTEXPR_EQUAL((kumi::min_flat (f0 , [](auto m) { return sizeof(m); })),   sizeof(char));

  constexpr auto t1 = kumi::tuple {1.5,3.6f,8,-3.6,2.4,-0.5};
  TTS_CONSTEXPR_EQUAL((kumi::min(t1, [](auto m) { return m<0 ? -m : m; })), 0.5);
};
