//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check kumi::push_front/pop_front type computation")
{
  using namespace kumi::result;
  using namespace kumi::literals;

  using int_f = kumi::field<kumi::name<"a">, int>;
  using float_f = kumi::field<kumi::name<"b">, float>;
  using char_f = kumi::field<kumi::name<"c">, char>;

  TTS_TYPE_IS((push_front_t<kumi::record<>, int_f>), kumi::record<int_f>);
  TTS_TYPE_IS((push_front_t<kumi::record<float_f>, int_f>), (kumi::record<int_f, float_f>));
  TTS_TYPE_IS((push_front_t<kumi::record<float_f, char_f>, int_f>), (kumi::record<int_f, float_f, char_f>));

  TTS_TYPE_IS((pop_front_t<kumi::record<>>), kumi::record<>);
  TTS_TYPE_IS((pop_front_t<kumi::record<float_f>>), kumi::record<>);
  TTS_TYPE_IS((pop_front_t<kumi::record<float_f, char_f>>), kumi::record<char_f>);
  TTS_TYPE_IS((pop_front_t<kumi::record<int_f, float_f, char_f>>), (kumi::record<float_f, char_f>));
};

TTS_CASE("Check kumi::push_front/pop_front function behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL((kumi::push_front(kumi::record{}, "a"_n = 4)), kumi::record{"a"_n = 4});
  TTS_EQUAL((kumi::push_front(kumi::record{"a"_n = 3.5}, "b"_n = 4)), (kumi::record{"b"_n = 4, "a"_n = 3.5}));
  TTS_EQUAL((kumi::push_front(kumi::record{"a"_n = 3.5, "b"_n = 'e'}, "c"_n = 4)),
            (kumi::record{"c"_n = 4, "a"_n = 3.5, "b"_n = 'e'}));

  TTS_EQUAL(kumi::pop_front(kumi::record{}), kumi::record{});
  TTS_EQUAL(kumi::pop_front(kumi::record{"a"_n = 3.5}), kumi::record{});
  TTS_EQUAL(kumi::pop_front(kumi::record{"a"_n = 3.5, "b"_n = 'e'}), kumi::record{"b"_n = 'e'});
  TTS_EQUAL(kumi::pop_front(kumi::record{"a"_n = 4, "b"_n = 3.5, "c"_n = 'e'}),
            (kumi::record{"b"_n = 3.5, "c"_n = 'e'}));
};

TTS_CASE("Check kumi::push_front/pop_front constexpr behavior")
{
  using namespace kumi::literals;

  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::record{}, "a"_n = 4)), kumi::record{"a"_n = 4});
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::record{"a"_n = 3.5}, "b"_n = 4)), (kumi::record{"b"_n = 4, "a"_n = 3.5}));
  TTS_CONSTEXPR_EQUAL((kumi::push_front(kumi::record{"a"_n = 3.5, "b"_n = 'e'}, "c"_n = 4)),
                      (kumi::record{"c"_n = 4, "a"_n = 3.5, "b"_n = 'e'}));

  // TTS_CONSTEXPR_EQUAL( kumi::pop_front(kumi::record{})         , kumi::record{}         );
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::record{"a"_n = 3.5}), kumi::record{});
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::record{"a"_n = 3.5, "b"_n = 'e'}), kumi::record{"b"_n = 'e'});
  TTS_CONSTEXPR_EQUAL(kumi::pop_front(kumi::record{"a"_n = 4, "b"_n = 3.5, "c"_n = 'e'}),
                      (kumi::record{"b"_n = 3.5, "c"_n = 'e'}));
};

TTS_CASE("Check kumi::push_back/pop_back type computation")
{
  using namespace kumi::result;
  using namespace kumi::literals;

  using int_f = kumi::field<kumi::name<"a">, int>;
  using float_f = kumi::field<kumi::name<"b">, float>;
  using char_f = kumi::field<kumi::name<"c">, char>;

  TTS_TYPE_IS((push_back_t<kumi::record<>, int_f>), kumi::record<int_f>);
  TTS_TYPE_IS((push_back_t<kumi::record<float_f>, int_f>), (kumi::record<float_f, int_f>));
  TTS_TYPE_IS((push_back_t<kumi::record<float_f, char_f>, int_f>), (kumi::record<float_f, char_f, int_f>));

  TTS_TYPE_IS((pop_back_t<kumi::record<>>), kumi::record<>);
  TTS_TYPE_IS((pop_back_t<kumi::record<float_f>>), kumi::record<>);
  TTS_TYPE_IS((pop_back_t<kumi::record<float_f, char_f>>), kumi::record<float_f>);
  TTS_TYPE_IS((pop_back_t<kumi::record<int_f, float_f, char_f>>), (kumi::record<int_f, float_f>));
};

TTS_CASE("Check kumi::push_back/pop_back function behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL((kumi::push_back(kumi::record{}, "a"_n = 4)), kumi::record{"a"_n = 4});
  TTS_EQUAL((kumi::push_back(kumi::record{"a"_n = 3.5}, "b"_n = 4)), (kumi::record{"a"_n = 3.5, "b"_n = 4}));
  TTS_EQUAL((kumi::push_back(kumi::record{"a"_n = 3.5, "b"_n = 'e'}, "c"_n = 4)),
            (kumi::record{"a"_n = 3.5, "b"_n = 'e', "c"_n = 4}));

  TTS_EQUAL(kumi::pop_back(kumi::record{}), kumi::record{});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 3.5}), kumi::record{});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 3.5, "b"_n = 'e'}), kumi::record{"a"_n = 3.5});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 4, "b"_n = 3.5, "c"_n = 'e'}), (kumi::record{"a"_n = 4, "b"_n = 3.5}));
};

TTS_CASE("Check kumi::push_back/pop_back constexpr behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL((kumi::push_back(kumi::record{}, "a"_n = 4)), kumi::record{"a"_n = 4});
  TTS_EQUAL((kumi::push_back(kumi::record{"a"_n = 3.5}, "b"_n = 4)), (kumi::record{"a"_n = 3.5, "b"_n = 4}));
  TTS_EQUAL((kumi::push_back(kumi::record{"a"_n = 3.5, "b"_n = 'e'}, "c"_n = 4)),
            (kumi::record{"a"_n = 3.5, "b"_n = 'e', "c"_n = 4}));

  TTS_EQUAL(kumi::pop_back(kumi::record{}), kumi::record{});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 3.5}), kumi::record{});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 3.5, "b"_n = 'e'}), kumi::record{"a"_n = 3.5});
  TTS_EQUAL(kumi::pop_back(kumi::record{"a"_n = 4, "b"_n = 3.5, "c"_n = 'e'}), (kumi::record{"a"_n = 4, "b"_n = 3.5}));
};
