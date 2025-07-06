/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;
    
  auto t = kumi::record{"a"_f = 1, "b"_f = 2.3, "c"_f = 0.43f };

  kumi::for_each_field( [](auto name, auto& m) { 
                        if(name.compare("a") == 0)
                            m += 10; 
                        else
                            m *=10;
                        }
                      , t
                      );

  std::cout << t << "\n";
}
