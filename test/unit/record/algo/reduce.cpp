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
  constexpr auto t = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};
  auto t2 = kumi::record{"a"_n = 2., "b"_n = 1, "c"_n = short{55}, "d"_n = 'z'};

  TTS_EQUAL(kumi::reduce(kumi::function::plus, t2), 180);
  TTS_EQUAL(kumi::reduce(kumi::function::plus, std::move(t2)), 180);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::plus, t), 180);
};

TTS_CASE("Check kumi::reduce with kumi::multiplies behavior")
{
  constexpr auto t = kumi::record{"a"_n = 2., "b"_n = 3, "c"_n = short{5}, "d"_n = '\a'};
  auto t2 = kumi::record{"a"_n = 2., "b"_n = 3, "c"_n = short{5}, "d"_n = '\a'};

  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, t2), 210);
  TTS_EQUAL(kumi::reduce(kumi::function::multiplies, std::move(t)), 210);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::multiplies, t), 210);
};

TTS_CASE("Check kumi::reduce with kumi::bit_and behavior")
{
  constexpr auto t = kumi::record{"a"_n = 14UL, "b"_n = char{7}, "c"_n = short{6}};
  auto t2 = kumi::record{"a"_n = 14UL, "b"_n = char{7}, "c"_n = short{6}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, t2), 6UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_and, std::move(t2)), 6UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_and, t), 6UL);
};

TTS_CASE("Check kumi::reduce with kumi::bit_or behavior")
{
  constexpr auto t = kumi::record{"a"_n = 2UL, "b"_n = 3, "c"_n = short{5}, "d"_n = char{64}};
  auto t2 = kumi::record{"a"_n = 2UL, "b"_n = 3, "c"_n = short{5}, "d"_n = char{64}};

  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, t2), 71UL);
  TTS_EQUAL(kumi::reduce(kumi::function::bit_or, std::move(t2)), 71UL);
  TTS_CONSTEXPR_EQUAL(kumi::reduce(kumi::function::bit_or, t), 71UL);
};
