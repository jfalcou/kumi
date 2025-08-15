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

TTS_CASE("Check result::cat<Tuple...> behavior")
{
  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<>,kumi::tuple<char,short,int,double>>)
              , (kumi::tuple<char,short,int,double>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char>,kumi::tuple<short,int,double>>)
              , (kumi::tuple<char,short,int,double>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char,short>,kumi::tuple<int,double>>)
              , (kumi::tuple<char,short,int,double>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char>,kumi::tuple<short>,kumi::tuple<int,double>>)
              , (kumi::tuple<char,short,int,double>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char,short&>,kumi::tuple<int&,double>>)
              , (kumi::tuple<char,short&,int&,double>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char &&> &&>)
              , (kumi::tuple<char &&>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char &&> &&, kumi::tuple<char &> &, kumi::tuple<char> &>)
              , (kumi::tuple<char &&, char &, char>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char &&> &&, kumi::tuple<char &> &&, kumi::tuple<char> &>)
                , (kumi::tuple<char &&, char &, char>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char &&> &&, kumi::tuple<char &> &, kumi::tuple<char> &&>)
              , (kumi::tuple<char &&, char &, char>)
              );

  TTS_TYPE_IS ( (kumi::result::cat_t<kumi::tuple<char &&> &&, kumi::tuple<char &> &&, kumi::tuple<char> &&>)
                , (kumi::tuple<char &&, char &, char>)
              );
};

TTS_CASE("Check cat(tuple) behavior")
{
  short s = 55;
  TTS_EQUAL((cat(kumi::tuple {}     , kumi::tuple {})), (kumi::tuple {}));
  TTS_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {})), (kumi::tuple {1, 2.}));
  TTS_EQUAL((cat(kumi::tuple {}, kumi::tuple {1, 2.})), (kumi::tuple {1, 2.}));
  TTS_EQUAL((cat(kumi::tuple {1}, kumi::tuple {2., 3.f, 4})), (kumi::tuple {1, 2., 3.f, 4}));
  TTS_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {3.f, 4})), (kumi::tuple {1, 2., 3.f, 4}));
  TTS_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {3.f, 4}, kumi::tuple {s, 6.7})),
            (kumi::tuple {1, 2., 3.f, 4, s, 6.7}));

  // Check behavior with tuple of references
  {
    auto ref = kumi::tie(s);
    auto val = kumi::tuple<float const>{3.14f};

    TTS_EQUAL(kumi::cat(ref, val), (kumi::tuple<short&,float const>{s,3.14f}) );
  }
  {
    auto ref = kumi::tie(s);
    auto rref = kumi::tuple<short &&>{std::move(s)};
    auto val = kumi::tuple<float const>{3.14f};

    TTS_EQUAL(kumi::cat(ref, std::move(rref), val), (kumi::tuple<short&, short &&, float const>{s,std::move(s),3.14f}) );
  }
  {
    auto tmp    = kumi::tuple{1,2,3,4,5};
    auto tmp2   = kumi::tuple{'a', 'b', 'c'};
    TTS_EQUAL((kumi::cat(std::move(tmp), std::move(tmp2))),(kumi::tuple{1,2,3,4,5,'a','b','c'}) );
  }
};

TTS_CASE("Check cat(tuple) constexpr behavior")
{
  constexpr short s = 55;
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {}, kumi::tuple {})), (kumi::tuple {}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {})), (kumi::tuple {1, 2.}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {}, kumi::tuple {1, 2.})), (kumi::tuple {1, 2.}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {1}, kumi::tuple {2., 3.f, 4})),
                      (kumi::tuple {1, 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {3.f, 4})),
                      (kumi::tuple {1, 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((cat(kumi::tuple {1, 2.}, kumi::tuple {3.f, 4}, kumi::tuple {s, 6.7})),
                      (kumi::tuple {1, 2., 3.f, 4, s, 6.7}));
};
