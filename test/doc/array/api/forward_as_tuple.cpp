/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <vector>
#include <string>

template<typename Data>
std::vector<std::string> build(Data d)
{
  return std::vector<int> ( kumi::get<0>(d)
                          , std::move(kumi::get<1>(d))
                          );
}

int main()
{
  auto v = build( kumi::forward_as_array(4, 5, 2, 3, 1));

  for(auto const& s : v)
    std::cout << s << "\n";
}
