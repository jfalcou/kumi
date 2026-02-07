/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

using namespace kumi::literals;

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
    if constexpr(I==0) return kumi::capture_field<"name"_n>( s.name );
    if constexpr(I==1) return kumi::capture_field<"age"_n >( s.age  );
  }

  template<std::size_t I>
  decltype(auto) get(people& s) noexcept
  {
    if constexpr(I==0) return kumi::capture_field<"name"_n>( s.name );
    if constexpr(I==1) return kumi::capture_field<"age"_n>( s.age  );
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

template<> struct std::tuple_element<0,ns::people> { using type = kumi::field<kumi::name<"name">,std::string>;  };
template<> struct std::tuple_element<1,ns::people> { using type = kumi::field<kumi::name<"age"> ,int        >;  };

int main()
{
  ns::people peter{"Peter Parker", 24};
  
  kumi::for_each_field( [](auto n, auto e)
                        {
                          std::cout << "# "  << n
                                    << " : " << e
                                    << "\n";
                        }
                      , peter
                      );    
}
