/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  auto status = kumi::record{"a"_id = true, "b"_id = false};
  auto id     = kumi::record{"aa"_id = 'a', "bb"_id = 'b', "cc"_id = 'c'};
  auto value  = kumi::record{"aaa"_id = 1.0,"bbb"_id = 2.1, "ccc"_id = 4.2, "d"_id = 8.4};

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
