/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <vector>

int main()
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_n = 2.,"b"_n = 1,"c"_n = short{55},"d"_n = 'z'};

  auto output  = kumi::fold_right( [](auto m, auto a) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << " ";
  std::cout << "\n";

  auto u = kumi::record{"a"_n = 1,"b"_n = 3,"c"_n = 2,"d"_n = 4,"e"_n = 0,
                        "f"_n = 5,"g"_n = 9,"h"_n = 6,"i"_n = 7};

  std::cout << kumi::fold_right(  [](auto e, auto acc)
                                  {
                                      std::cout << '(' << acc << ',' << e << ")\n";
                                      return (e <acc) ? e : acc;
                                  }
                                , u
                                )
            << "\n";
}
