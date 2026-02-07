/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace kumi::literals;

template<typename Data>
std::vector<std::string> build(Data d)
{
  return std::vector<std::string> ( kumi::get<"a"_n>(d)
                                  , std::move(kumi::get<"b"_n>(d))
                                  );
}

int main()
{
  auto v = build( kumi::forward_as_record<"a"_n, "b"_n>(4,std::string{"the text !"}));

  for(auto const& s : v)
    std::cout << s << "\n";
}
