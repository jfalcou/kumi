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

TTS_CASE("Check kumi::result::windows behavior")
{
  using t1 = kumi::tuple<int, const float, char&, volatile short>;
  using t2_inner = kumi::tuple<const long, char>;
  using t2 = kumi::tuple<int&, double*, t2_inner>;

  TTS_TYPE_IS((kumi::result::windows_t<1, t1>), (kumi::tuple<kumi::tuple<int>, kumi::tuple<const float>, kumi::tuple<char&>, kumi::tuple<volatile short>>));
  TTS_TYPE_IS((kumi::result::windows_t<2, t2>), (kumi::tuple<kumi::tuple<int&, double*>, kumi::tuple<double*, t2_inner>>));
};

TTS_CASE("Check runtime kumi::windows behavior")
{
  auto t1 = kumi::tuple{1, 3.f, 5., 'x', short{77}}; 
  auto t2 = kumi::tuple{112, -18.f, kumi::tuple{'1', long{22}, kumi::str{"Yes"}}};
   
  auto t_test = kumi::tuple{1, 3.f, 5., 'x', short{77}}; 
  auto t3 = kumi::windows<3>(kumi::to_ref(t_test));
  kumi::for_each([&](auto &tile)
  {
    auto [f,s,t] = tile;
    f += 1;
    s += 2;
    t += 3;
    return tile;
  }, t3);

  TTS_EQUAL ( ( kumi::windows<1>(t1)), ( kumi::tuple{ kumi::tuple{1}, kumi::tuple{3.f}, kumi::tuple{5.}
                                       , kumi::tuple{'x'}, kumi::tuple{short{77}} }));

  TTS_EQUAL ( ( t_test ), ( kumi::tuple{ 2, 6.f, 11., '}', short{80} }));

  TTS_EQUAL ( (kumi::windows<2>(t2)), (kumi::tuple{kumi::tuple{112, -18.f}, kumi::tuple{-18.f, kumi::tuple{'1', long{22}, kumi::str{"Yes"}}}} ) );
};

TTS_CASE("Check constexpr kumi::windows behavior")
{
  constexpr auto t1 = kumi::tuple{1, 3.f, 5., 'x', short{77}}; 
  constexpr auto t2 = kumi::tuple{112, -18.f, kumi::tuple{'1', long{22}, kumi::str{"Yes"}}};
    
  TTS_CONSTEXPR_EQUAL ( (kumi::windows<1>(t1)), ( kumi::tuple{ kumi::tuple{1}, kumi::tuple{3.f}, kumi::tuple{5.}
                                                , kumi::tuple{'x'}, kumi::tuple{short{77}}}));
  TTS_CONSTEXPR_EQUAL ( (kumi::windows<2>(t2)), (kumi::tuple{kumi::tuple{112, -18.f}, kumi::tuple{-18.f, kumi::tuple{'1', long{22}, kumi::str{"Yes"}}}} ) );
};
