//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto status = kumi::tuple{true, false};
  auto id     = kumi::tuple{'a','b','c'};
  auto value  = kumi::tuple{1.0,2.1,4.2,8.4};

  auto r = kumi::cartesian_product( status, id, value );

  kumi::for_each_index( [](auto i, auto e)
                        {
                          std::cout << "# "  << i
                                    << ":"  << std::boolalpha
                                    << e    << "\n";
                        }
                      , r
                      );
}
