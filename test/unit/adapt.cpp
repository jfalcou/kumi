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
#include <tuple>
#include "test.hpp"

TTS_CASE("Check adapted types model kumi::product_type concept")
{
  TTS_EXPECT( kumi::product_type<tuple_box>             );
  TTS_EXPECT( (kumi::product_type<std::array<int,4>>   ));
  TTS_EXPECT( (kumi::product_type<std::pair<int,float>>));
  TTS_EXPECT( (kumi::product_type<std::tuple<int, char, float>>));
};

TTS_CASE("Check adapted type behave like a product_type")
{
  auto r = kumi::apply( [](auto... x) { return (x + ...); }, tuple_box{1,2.5,'4'});
  TTS_EQUAL(r, 55.5);

  auto zz = kumi::zip( tuple_box{1,2.5,'4'}, tuple_box{99,69.25,'Z'});
  TTS_EQUAL ( zz, ( kumi::tuple { kumi::tuple{1   , 99    }
                                , kumi::tuple{2.5 , 69.25 }
                                , kumi::tuple{'4' ,'Z'    }
                                })
            );

  auto cc = kumi::cat( tuple_box{1,2.5,'4'}, tuple_box{99,69.25,'Z'});
  TTS_EQUAL ( cc, ( kumi::tuple {1, 2.5, '4', 99, 69.25, 'Z'}) );
};

TTS_CASE("Check adapted external type behave like a product_type")
{
  auto r = kumi::apply( [](auto... x) { return (x + ...); }, std::array{1,2,5,4});
  TTS_EQUAL(r, 12);

  auto zz = kumi::zip( std::array{1,2,5}, std::array{0.1,2.3,4.5});
  TTS_EQUAL ( zz, ( kumi::tuple { kumi::tuple{1 , 0.1 }
                                , kumi::tuple{2 , 2.3 }
                                , kumi::tuple{5 , 4.5 }
                                })
            );

  auto cc = kumi::cat( std::array{1,2,5}, std::array{0.1,2.3,4.5} );
  TTS_EQUAL ( cc, ( kumi::tuple {1, 2, 5, 0.1, 2.3, 4.5}) );
};
