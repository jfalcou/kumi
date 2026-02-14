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

using namespace kumi::literals;

TTS_CASE("Check result::reduce_t with prod/sum/bit_* behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;
  using size_t_f = kumi::field<kumi::name<"e">, std::size_t>;

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::numeric_add, kumi::record<char_f, short_f, int_f, double_f>>), double);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::numeric_prod, kumi::record<char_f, short_f, int_f, double_f>>), double);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::boolean_or, kumi::record<short_f, size_t_f, int_f>>), std::size_t);

  TTS_TYPE_IS((kumi::result::reduce_t<kumi::boolean_and, kumi::record<short_f, size_t_f, int_f>>), std::size_t);

  auto lambda = [](auto const& m) { return m; };
  using func_t = decltype(lambda);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::numeric_add, kumi::record<char_f, short_f, int_f, double_f>>),
              double);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::numeric_prod, kumi::record<char_f, short_f, int_f, double_f>>),
              double);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::boolean_or, kumi::record<short_f, size_t_f, int_f>>),
              std::size_t);

  TTS_TYPE_IS((kumi::result::map_reduce_t<func_t, kumi::boolean_and, kumi::record<short_f, size_t_f, int_f>>),
              std::size_t);
};

TTS_CASE("Check kumi::reduce with kumi::plus behavior")
{
  constexpr auto t = kumi::record{"a"_id = 2., "b"_id = 1, "c"_id = short{55}, "d"_id = 'z'};
  auto t2 = kumi::record{"a"_id = 2., "b"_id = 1, "c"_id = short{55}, "d"_id = 'z'};

  TTS_EQUAL(kumi::reduce(kumi::function::plus, t2), 180);
  TTS_EQUAL(kumi::reduce(kumi::function::plus, std::move(t2)), 180);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 180);
};

TTS_CASE("Check kumi::reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::record{"a"_id = 2., "b"_id = 3, "c"_id = short{5}, "d"_id = '\a'};
  auto t2 = kumi::record{"a"_id = 2., "b"_id = 3, "c"_id = short{5}, "d"_id = '\a'};

  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, t2), 210);
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, std::move(t)), 210);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies, t), 210);
};

TTS_CASE("Check kumi::reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::record{"a"_id = 14UL, "b"_id = char{7}, "c"_id = short{6}};
  auto t2 = kumi::record{"a"_id = 14UL, "b"_id = char{7}, "c"_id = short{6}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, t2), 6UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, std::move(t2)), 6UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 6UL);
};

TTS_CASE("Check kumi::reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::record{"a"_id = 2UL, "b"_id = 3, "c"_id = short{5}, "d"_id = char{64}};
  auto t2 = kumi::record{"a"_id = 2UL, "b"_id = 3, "c"_id = short{5}, "d"_id = char{64}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, t2), 71UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, std::move(t2)), 71UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 71UL);
};
