/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

namespace ns
{
  struct people
  {
    std::string name;
    int         age;
  };

  template<std::size_t I>
  decltype(auto) get(people const& s) noexcept
  {
    if constexpr(I==0) return kumi::capture_field<"name">( s.name );
    if constexpr(I==1) return kumi::capture_field<"age" >( s.age  );
  }

  template<std::size_t I>
  decltype(auto) get(people& s) noexcept
  {
    if constexpr(I==0) return kumi::capture_field<"name">( s.name );
    if constexpr(I==1) return kumi::capture_field<"age" >( s.age  );
  }
}

// Opt-in for Record Type semantic
template<>
struct kumi::is_record_type<ns::people> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<ns::people>
      : std::integral_constant<std::size_t,2> {};

template<> struct std::tuple_element<0,ns::people> { using type = kumi::field_capture<"name",std::string>;  };
template<> struct std::tuple_element<1,ns::people> { using type = kumi::field_capture<"age" ,int        >;  };

int main()
{
  ns::people peter{"Peter Parker", 24};
    
  std::cout << kumi::get<"name">(peter) << "\n";
  std::cout << kumi::get<"age"> (peter) << "\n";
}
