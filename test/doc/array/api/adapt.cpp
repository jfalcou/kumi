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
  template<std::size_t N>
  struct span 
  {
    using value_type = int;
    using reference = int&;
    using const_reference = int const&;
    
    int *p; 
  };

  template<std::size_t I, std::size_t N>
  decltype(auto) get(span<N> const& s) noexcept
  {
    return s.p[I];
  }

  template<std::size_t I, std::size_t N>
  decltype(auto) get(span<N>& s) noexcept
  {
    return s.p[I];
  }
}

// Adapt as structured bindable type
template<std::size_t N>
struct  std::tuple_size<ns::span<N>>
      : std::integral_constant<std::size_t,N> {};

template<std::size_t I, std::size_t N> 
struct std::tuple_element<I,ns::span<N>> { using type = typename ns::span<N>::value_type;  };

int main()
{
  int array[10] = {1,2,3,4,5,6,7,8,9,10};
  ns::span<10> view{array};
  kumi::for_each_index( [](auto i, auto e)
                        {
                          std::cout << "# " << i
                                    << " : " << e
                                    << "\n";
                        }
                      ,view 
                      );
}
