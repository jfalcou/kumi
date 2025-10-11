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


TTS_CASE("Check result::prod/sum/bit_* behavior")
{
  TTS_TYPE_IS ( (kumi::result::reduce_t<kumi::numeric_add, kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::reduce_t<kumi::numeric_prod, kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::reduce_t<kumi::boolean_or, kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );
    
  TTS_TYPE_IS ( (kumi::result::reduce_t<kumi::boolean_and, kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );
 
  auto lambda = [](auto const& m) { return m; };
  using func_t = decltype(lambda);
 
  TTS_TYPE_IS ( (kumi::result::map_reduce_t<func_t, kumi::numeric_add, kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::map_reduce_t<func_t, kumi::numeric_prod, kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::map_reduce_t<func_t, kumi::boolean_or, kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::map_reduce_t<func_t, kumi::boolean_and, kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );
};


TTS_CASE("Check kumi::reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::tuple {2., 1, short {55}, 'z'};
  auto t2 = kumi::tuple {2., 1, short{55}, 'z'};  

  //TTS_EQUAL(kumi::reduce(kumi::tuple{}, 42),  42 );
  TTS_EQUAL(kumi::reduce(kumi::function::plus, t2)            , 180 );
  TTS_EQUAL(kumi::reduce(kumi::function::plus, std::move(t2))    , 180 );

  //TTS_CONSTEXPR_EQUAL(kumi::sum(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 180 );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 180 );
};

TTS_CASE("Check kumi::reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::tuple {2., 3, short {5}, '\a'};
  auto t2 = kumi::tuple {2., 3, short {5}, '\a'};

  //TTS_EQUAL(kumi::reduce(kumi::tuple{}, 42),  42 );
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, t2)            , 210 );
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, std::move(t))  , 210 );

  //TTS_CONSTEXPR_EQUAL(kumi::prod(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies ,t)             , 210 );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies ,t)                , 210 );
};

TTS_CASE("Check kumi::reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::tuple {14UL, char{7}, short{6}};
  auto t2 = kumi::tuple {14UL, char{7}, short{6}};

  //TTS_EQUAL(kumi::bit_and(kumi::tuple{}, 42)  ,  42 );
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, t2)            , 6UL );
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, std::move(t2)) , 6UL );

  //TTS_CONSTEXPR_EQUAL(kumi::bit_and(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 6UL );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 6UL );
};

TTS_CASE("Check kumi::reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::tuple {2UL, 3, short {5}, char{64}};
  auto t2 = kumi::tuple {2UL, 3, short {5}, char{64}};

  //TTS_EQUAL(kumi::bit_or(kumi::tuple{}, 42),  42  );
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, t2)            , 71UL );
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, std::move(t2)) , 71UL );

  //TTS_CONSTEXPR_EQUAL(kumi::bit_or(kumi::tuple{}, 42),  42  );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 71UL );
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 71UL );
};
