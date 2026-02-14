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

  auto t = kumi::record{"a"_id = 2.,"b"_id = 1,"c"_id = short{55},"d"_id = 'z'};

  auto output  = kumi::fold_left( [](auto a, auto m) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << " ";
  std::cout << "\n";

  auto u = kumi::record{"a"_id = 1,"b"_id = 3,"c"_id = 2,"d"_id = 4,"e"_id = 0,
                        "f"_id = 5,"g"_id = 9,"h"_id = 6,"i"_id = 7};

  std::cout << kumi::fold_left( [](auto acc, auto e)
                                {
                                    std::cout << '(' << acc << ',' << e << ")\n";
                                    return (e <acc) ? e : acc;
                                }
                              , u
                              )
            << "\n";
}