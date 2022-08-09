//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
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
    if constexpr(I==0) return s.name;
    if constexpr(I==1) return s.age;
  }

  template<std::size_t I>
  decltype(auto) get(people& s) noexcept
  {
    if constexpr(I==0) return s.name;
    if constexpr(I==1) return s.age;
  }
}

// Opt-in for Product Type semantic
template<>
struct kumi::is_product_type<ns::people> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<ns::people>
      : std::integral_constant<std::size_t,2> {};

template<> struct std::tuple_element<0,ns::people> { using type = std::string;  };
template<> struct std::tuple_element<1,ns::people> { using type = int;          };

int main()
{
  ns::people peter{"Peter Parker", 24};
  kumi::for_each_index( [](int i, auto e)
                        {
                          std::cout << "# " << i
                                    << " : " << e
                                    << "\n";
                        }
                      , peter
                      );
}
