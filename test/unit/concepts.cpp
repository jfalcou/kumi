//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <concepts>

struct no_cmp   { };
struct cmp      { constexpr auto operator<=>(cmp const&) const = default; };
struct strange  { constexpr float operator==(strange const&) const { return -1.f; }; };

TTS_CASE("Check equality_comparable for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(  std::equality_comparable<kumi::tuple<no_cmp>>      );
  TTS_CONSTEXPR_EXPECT_NOT( (std::equality_comparable<kumi::tuple<cmp,no_cmp>>) );

  TTS_CONSTEXPR_EXPECT(  std::equality_comparable<kumi::tuple<cmp>>                   );
  TTS_CONSTEXPR_EXPECT( (std::equality_comparable<kumi::tuple<cmp,kumi::tuple<cmp>>>) );

  TTS_CONSTEXPR_EXPECT(  std::equality_comparable<kumi::tuple<strange>>                       );
  TTS_CONSTEXPR_EXPECT( (std::equality_comparable<kumi::tuple<strange,kumi::tuple<strange>>>) );

  TTS_CONSTEXPR_EXPECT( (std::equality_comparable<kumi::tuple<strange,kumi::tuple<cmp>>>) );
};

TTS_CASE("Check product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT( kumi::product_type<int> );
  TTS_CONSTEXPR_EXPECT    (  kumi::product_type<kumi::tuple<strange>>                   );
  TTS_CONSTEXPR_EXPECT    ( (kumi::product_type<kumi::tuple<strange,kumi::tuple<cmp>>>) );
};

TTS_CASE("Check sized_product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<int, 0>)                  );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type<kumi::tuple<>, 0>)        );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<kumi::tuple<strange>,0>)  );

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<int, 1>)                                    );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type<kumi::tuple<strange>,1>)                    );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<kumi::tuple<strange,kumi::tuple<cmp>>, 1>)  );

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<int, 2>)                                    );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type<kumi::tuple<strange>,2>)                    );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type<kumi::tuple<strange,kumi::tuple<cmp>>, 2>)  );
};

TTS_CASE("Check sized_product_type_or_more for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<int, 0>)                          );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<>, 0>)                );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange>,0>)          );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,int, cmp>, 0>));

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<int, 1>)                                  );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange>,1>)                  );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,kumi::tuple<cmp>>, 1>));
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,int, cmp>, 1>)        );

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<int, 2>)                                  );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange>,2>)                  );
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,kumi::tuple<cmp>>, 2>));
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,int, cmp>, 2>)        );

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<int, 3>)                                  );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange>,3>)                  );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange,kumi::tuple<cmp>>, 3>));
  TTS_CONSTEXPR_EXPECT    ( (kumi::sized_product_type_or_more<kumi::tuple<strange,int, cmp>, 3>)        );

  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<int, 4>)                                  );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange>,4>)                  );
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange,kumi::tuple<cmp>>, 4>));
  TTS_CONSTEXPR_EXPECT_NOT( (kumi::sized_product_type_or_more<kumi::tuple<strange,int, cmp>, 4>)        );
};

/*
  template<typename T>
  concept product_type = std_tuple_compatible<T> && is_product_type<std::remove_cvref_t<T>>::value;

  template<typename T, std::size_t N>
  concept sized_product_type = product_type<T> && (size<T>::value == N);

  template<typename T, std::size_t N>
  concept sized_product_type_or_more = product_type<T> && (size<T>::value >= N);
*/
