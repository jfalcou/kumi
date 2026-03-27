//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include "test.hpp"
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

namespace udt
{
  struct particle
  {
    using is_record_type = void;
    char name;
    short identifier;
    double momentum;
    float kinetic;

    template<std::size_t I> friend constexpr auto get(particle const& p)
    {
      if constexpr (I == 0) return p.name;
      if constexpr (I == 1) return p.identifier;
      if constexpr (I == 2) return p.momentum;
      if constexpr (I == 3) return p.kinetic;
    }

    template<kumi::concepts::identifier Id> friend constexpr auto get(particle const& p)
    {
      constexpr auto idx = kumi::get_index_of_field<Id, particle>();
      return get<idx>(p);
    }

    template<kumi::str L> friend constexpr auto get(particle const& p)
    {
      constexpr auto idx = kumi::get_index_of_label<L, particle>();
      return get<idx>(p);
    }

    template<typename T> friend constexpr auto get(particle const& p)
    {
      constexpr auto idx = kumi::get_index_of_type<T, particle>();
      return get<idx>(p);
    }
  };
}

namespace std
{
  template<> struct tuple_size<udt::particle> : std::integral_constant<std::size_t, 4>
  {
  };

  template<> struct tuple_element<0, udt::particle>
  {
    using type = kumi::field<kumi::name<"name">, char>;
  };

  template<> struct tuple_element<1, udt::particle>
  {
    using type = kumi::field<kumi::name<"identifier">, short>;
  };

  template<> struct tuple_element<2, udt::particle>
  {
    using type = kumi::field<kumi::name<"momentum">, double>;
  };

  template<> struct tuple_element<3, udt::particle>
  {
    using type = kumi::field<kumi::name<"kinetic">, float>;
  };
}

TTS_CASE("Check synthetized gets on User Defined Type")
{
  auto p = udt::particle{'x', 12, 2., 12.f};

  TTS_EQUAL(get<0>(p), 'x');
  TTS_EQUAL(get<1>(p), 12);
  TTS_EQUAL(get<2>(p), 2.);
  TTS_EQUAL(get<3>(p), 12.f);

  TTS_EQUAL(get<"name">(p), 'x');
  TTS_EQUAL(get<"identifier">(p), 12);
  TTS_EQUAL(get<"momentum">(p), 2.);
  TTS_EQUAL(get<"kinetic">(p), 12.f);

  TTS_EQUAL(get<kumi::name<"name">>(p), 'x');
  TTS_EQUAL(get<kumi::name<"identifier">>(p), 12);
  TTS_EQUAL(get<kumi::name<"momentum">>(p), 2.);
  TTS_EQUAL(get<kumi::name<"kinetic">>(p), 12.f);

  TTS_EQUAL(get<char>(p), 'x');
  TTS_EQUAL(get<short>(p), 12);
  TTS_EQUAL(get<double>(p), 2.);
  TTS_EQUAL(get<float>(p), 12.f);
};
