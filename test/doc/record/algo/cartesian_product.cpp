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

  auto status = kumi::record{"a"_n = true, "b"_n = false};
  auto id     = kumi::record{"aa"_n = 'a', "bb"_n = 'b', "cc"_n = 'c'};
  auto value  = kumi::record{"aaa"_n = 1.0,"bbb"_n = 2.1, "ccc"_n = 4.2, "d"_n = 8.4};

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
