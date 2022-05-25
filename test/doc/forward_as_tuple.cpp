//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>
#include <vector>
#include <string>

template<typename Data>
std::vector<std::string> build(Data d)
{
  return std::vector<std::string> ( kumi::get<0>(d)
                                  , std::move(kumi::get<1>(d))
                                  );
}

int main()
{
  auto v = build( kumi::forward_as_tuple(4,std::string{"the text !"}));

  for(auto const& s : v)
    std::cout << s << "\n";
}
