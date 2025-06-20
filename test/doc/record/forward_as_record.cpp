/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/record.hpp>
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
  auto v = build( kumi::forward_as_record(4,std::string{"the text !"}));

  for(auto const& s : v)
    std::cout << s << "\n";
}
