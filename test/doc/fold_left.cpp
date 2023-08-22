/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>
#include <vector>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},'z'};

  auto output  = kumi::fold_left( [](auto a, auto m) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << " ";
  std::cout << "\n";

  auto u = kumi::tuple{1,3,2,4,0,5,9,6,7};

  std::cout << kumi::fold_left( [](auto acc, auto e)
                                {
                                    std::cout << '(' << acc << ',' << e << ")\n";
                                    return (e <acc) ? e : acc;
                                }
                              , u
                              )
            << "\n";
}
