//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi.hpp>
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
