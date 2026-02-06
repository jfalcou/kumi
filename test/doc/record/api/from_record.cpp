/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

struct my_struct
{
  int         i;
  float       f;
  std::string name;
};

template<std::size_t I>
decltype(auto) get(my_struct const & m) noexcept
{
  if constexpr (I==0) return kumi::capture_field<"i">(m.i);
  if constexpr (I==1) return kumi::capture_field<"f">(m.f);
  if constexpr (I==2) return kumi::capture_field<"name">(m.name);
}

template<std::size_t I>
decltype(auto) get(my_struct & m) noexcept
{
  if constexpr (I==0) return kumi::capture_field<"i">(m.i);
  if constexpr (I==1) return kumi::capture_field<"f">(m.f);
  if constexpr (I==2) return kumi::capture_field<"name">(m.name);
}

// Opt-in for Record Type semantic
template<>
struct kumi::is_record_type<my_struct> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<my_struct> : std::integral_constant<std::size_t,3> 
{};

template<> struct std::tuple_element<0,my_struct> { using type = kumi::field_capture<"i"   , int        >; };
template<> struct std::tuple_element<1,my_struct> { using type = kumi::field_capture<"f"   , float      >; };
template<> struct std::tuple_element<2,my_struct> { using type = kumi::field_capture<"name", std::string>; };

int main()
{
  using namespace kumi::literals;

  auto a = kumi::make_record("f"_f=2.3475f, "name"_f="John", "i"_f=1337);
  auto b = from_record<my_struct>( a );

  std::cout << a << "\n";
  std::cout << b.i << ' ' << b.f << ' ' << b.name << "\n";
}
