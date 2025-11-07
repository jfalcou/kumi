/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <string_view>
#include <iostream>

int main()
{
  using namespace kumi::literals;
    
  auto t = kumi::record{"a"_f = 1, "b"_f = 2.3, "c"_f = 0.43f };

  kumi::for_each_field( [](auto name, auto& m) 
  {
    if(std::string_view{name.data(), name.size()}.ends_with("a"))
      m += 10;
    else if (name == "c")
      m = (m * 100) -1; 
    else
      m *= 10;
    }
    , t
  );

  std::cout << t << "\n";
}
