//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <vector>

using namespace kumi::literals;

TTS_CASE("Check result::zip<record...> behavior")
{
  using char_f      = kumi::field_capture<"a", char>;
  using short_f     = kumi::field_capture<"b", short>;
  using int_f       = kumi::field_capture<"c", int>;

  using ld_f        = kumi::field_capture<"d", long double>;
  using double_f    = kumi::field_capture<"e", double>;
  using float_f     = kumi::field_capture<"f", float>;

  using voidp_f     = kumi::field_capture<"g", void*>;
  using voidpp_f    = kumi::field_capture<"h", void**>;
  using voidppp_f   = kumi::field_capture<"i", void***>;

  using record1_t = kumi::record<char_f,short_f,int_f>;
  using record2_t = kumi::record<ld_f, double_f, float_f>;
  using record3_t = kumi::record<voidp_f,voidpp_f,voidppp_f>;

  TTS_TYPE_IS ( (kumi::result::zip_t<record1_t, record2_t,record3_t>)
              , (kumi::tuple< kumi::record<char_f, ld_f, voidp_f>
                            , kumi::record<short_f, double_f, voidpp_f>
                            , kumi::record<int_f, float_f, voidppp_f>
                            >)
              );
};


TTS_CASE("Check record::zip behavior")
{
  auto numbers = kumi::record {"a"_f = 1  , "b"_f = 2   , "c"_f = 3   , "d"_f = 4   };
  auto letters = kumi::record {"e"_f = 'a', "f"_f = 'b' , "g"_f = 'c' , "h"_f = 'd' };
  auto ratio   = kumi::record {"i"_f = 1.f, "j"_f = 0.5f, "k"_f = 0.25, "l"_f = 12.0};

  TTS_EQUAL((kumi::zip(kumi::record{},kumi::record{})),kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)),
            (kumi::tuple{ kumi::record{"a"_f = 1, "e"_f = 'a'}
                        , kumi::record{"b"_f = 2, "f"_f = 'b'}
                        , kumi::record{"c"_f = 3, "g"_f = 'c'}
                        , kumi::record{"d"_f = 4, "h"_f = 'd'}
                        }));

  TTS_EQUAL((kumi::zip(numbers, letters, ratio)),
            (kumi::tuple{ kumi::record{"a"_f = 1, "e"_f = 'a', "i"_f = 1.0f}
                        , kumi::record{"b"_f = 2, "f"_f = 'b', "j"_f = 0.5f}
                        , kumi::record{"c"_f = 3, "g"_f = 'c', "k"_f = 0.25}
                        , kumi::record{"d"_f = 4, "h"_f = 'd', "l"_f = 12.0}
                        }
            ));
};

TTS_CASE("Check record::zip behavior")
{
  constexpr auto numbers = kumi::record {"a"_f = 1  , "b"_f = 2   , "c"_f = 3   , "d"_f = 4     };
  constexpr auto letters = kumi::record {"e"_f = 'a', "f"_f = 'b' , "g"_f = 'c' , "h"_f = 'd'   };
  constexpr auto ratio   = kumi::record {"i"_f = 1.f, "j"_f = 0.5f, "k"_f = 0.25, "l"_f = 12.0  };

  TTS_CONSTEXPR_EQUAL((kumi::zip(kumi::record{},kumi::record{})),kumi::tuple{});

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)),
            (kumi::tuple{ kumi::record{"a"_f = 1, "e"_f = 'a'}
                        , kumi::record{"b"_f = 2, "f"_f = 'b'}
                        , kumi::record{"c"_f = 3, "g"_f = 'c'}
                        , kumi::record{"d"_f = 4, "h"_f = 'd'}
                        }));

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters, ratio)),
            (kumi::tuple{ kumi::record{"a"_f = 1, "e"_f = 'a', "i"_f = 1.0f}
                        , kumi::record{"b"_f = 2, "f"_f = 'b', "j"_f = 0.5f}
                        , kumi::record{"c"_f = 3, "g"_f = 'c', "k"_f = 0.25}
                        , kumi::record{"d"_f = 4, "h"_f = 'd', "l"_f = 12.0}
                        }
            ));
};
