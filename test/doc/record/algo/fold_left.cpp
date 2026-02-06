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

  auto t = kumi::record{"a"_f = 2.,"b"_f = 1,"c"_f = short{55},"d"_f = 'z'};

  auto output  = kumi::fold_left( [](auto a, auto m) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << " ";
  std::cout << "\n";

  auto u = kumi::record{"a"_f = 1,"b"_f = 3,"c"_f = 2,"d"_f = 4,"e"_f = 0,
                        "f"_f = 5,"g"_f = 9,"h"_f = 6,"i"_f = 7};

  std::cout << kumi::fold_left( [](auto acc, auto e)
                                {
                                    std::cout << '(' << acc << ',' << e << ")\n";
                                    return (e <acc) ? e : acc;
                                }
                              , u
                              )
            << "\n";
}