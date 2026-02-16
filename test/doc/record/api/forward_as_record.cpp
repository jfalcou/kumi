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
  return std::vector<std::string> ( kumi::get<"a"_id>(d)
                                  , std::move(kumi::get<"b"_id>(d))
                                  );
}

int main()
{
  auto v = build( kumi::forward_as_record<"a"_id, "b"_id>(4,std::string{"the text !"}));

  for(auto const& s : v)
    std::cout << s << "\n";
}
