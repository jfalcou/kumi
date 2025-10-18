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
#include "test.hpp"

TTS_CASE("Check result::unique/all_unique<T> behavior")
{
    TTS_TYPE_IS( (kumi::result::unique_t<kumi::tuple<char, int, int, char, double>>)
                ,(kumi::tuple<char, int, char, double>));

    TTS_TYPE_IS( (kumi::result::unique_t<
                   kumi::tuple<kumi::tuple<int, char>, kumi::tuple<int, char>, char, int>>) 
                , (kumi::tuple<kumi::tuple<int, char>, char, int> ));

    TTS_TYPE_IS( (kumi::result::unique_t<
                   kumi::tuple<int&, int, const int, volatile int, const int*, int&&>>)
                , (kumi::tuple<int&, int, const int, volatile int, const int*, int&&>));

    TTS_TYPE_IS( (kumi::result::all_unique_t<kumi::tuple<char, int, int, char, double>>)
                ,(kumi::tuple<char, int, double>));

    TTS_TYPE_IS( (kumi::result::all_unique_t<
                    kumi::tuple<kumi::tuple<int, char>, kumi::tuple<int, char>, char, int>>) 
                , (kumi::tuple<kumi::tuple<int, char>, char, int> ));

    TTS_TYPE_IS( (kumi::result::all_unique_t<
                   kumi::tuple<int&, int, const int, volatile int, const int*, int&&>>)
                , (kumi::tuple<int&, int, const int, volatile int, const int*, int&&>));
};

TTS_CASE("Check runtime kumi::unique behavior")
{
  auto r = kumi::tuple{1, 1,  3., 3, 'x', 'x', 12., short{55} };
  int a = 1;

  TTS_EQUAL ( kumi::unique(kumi::tuple{})   , kumi::tuple{});
  TTS_EQUAL ( kumi::unique(kumi::tuple{1})  , (kumi::tuple{1}) );
  TTS_EQUAL ( kumi::unique(kumi::tuple{1, 2.f, 3.f, 3., 4, 'x', 'y', 12., short{55} }) 
                        , (kumi::tuple{1, 2.f, 3., 4, 'x', 12., short{55}} ) );
  TTS_EQUAL ( kumi::unique(std::move(r)) ,  (kumi::tuple{1, 3., 3, 'x', 12., short{55}} ) );
    
  auto t = kumi::tuple{ moveonly{}, 1, std::ref(a)};
  TTS_EXPECT_COMPILES (t, { kumi::unique(std::move(t)); });
};

TTS_CASE("Check constexpr kumi::unique behavior")
{
  constexpr auto r = kumi::tuple{1, 1,  3., 3, 'x', 'x', 12., short{55} };
  
  TTS_CONSTEXPR_EQUAL ( kumi::unique(kumi::tuple{})   , kumi::tuple{});
  TTS_CONSTEXPR_EQUAL ( kumi::unique(kumi::tuple{1}   ) , (kumi::tuple{1}) );
  TTS_CONSTEXPR_EQUAL ( kumi::unique(kumi::tuple{1, 2.f, 3.f, 3., 4, 'x', 'y', 12., short{55} }) 
                                  , (kumi::tuple{1, 2.f, 3., 4, 'x', 12., short{55}} ) );
  TTS_CONSTEXPR_EQUAL ( kumi::unique(std::move(r)) ,  (kumi::tuple{1, 3., 3, 'x', 12., short{55}} ) );
};

TTS_CASE("Check runtime kumi::all_unique behavior")
{
  auto r = kumi::tuple{1, 1,  3., 3, 'x', 'x', 12., short{55} };
  int a = 1;

  TTS_EQUAL ( kumi::all_unique(kumi::tuple{})   , kumi::tuple{});
  TTS_EQUAL ( kumi::all_unique(kumi::tuple{1}   ) , (kumi::tuple{1}) );
  TTS_EQUAL ( kumi::all_unique(kumi::tuple{1, 2.f, 3.f, 3., 4, 'x', 'y', 12., short{55} }) 
                         , (kumi::tuple{1, 2.f, 3., 'x', short{55}} ) );
  TTS_EQUAL ( kumi::all_unique(std::move(r)) ,  (kumi::tuple{1, 3., 'x', short{55}} ) );

  auto t = kumi::tuple{ moveonly{}, 1, std::ref(a)};
  TTS_EXPECT_COMPILES (t, { kumi::all_unique(std::move(t)); });
};

TTS_CASE("Check constexpr kumi::all_unique behavior")
{
  constexpr auto r = kumi::tuple{1, 1,  3., 3, 'x', 'x', 12., short{55} };
  TTS_CONSTEXPR_EQUAL ( kumi::all_unique(kumi::tuple{})   , kumi::tuple{});
  TTS_CONSTEXPR_EQUAL ( kumi::all_unique(kumi::tuple{1}   ) , (kumi::tuple{1}) );
  TTS_CONSTEXPR_EQUAL ( kumi::all_unique(kumi::tuple{1, 2.f, 3.f, 3., 4, 'x', 'y', 12., short{55} }) 
                         , (kumi::tuple{1, 2.f, 3., 'x', short{55}} ) );
  TTS_CONSTEXPR_EQUAL ( kumi::all_unique(std::move(r)) ,  (kumi::tuple{1, 3., 'x', short{55}} ) );
};
