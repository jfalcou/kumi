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

  auto status = kumi::record{"a"_f = true, "b"_f = false};
  auto id     = kumi::record{"aa"_f = 'a', "bb"_f = 'b', "cc"_f = 'c'};
  auto value  = kumi::record{"aaa"_f = 1.0,"bbb"_f = 2.1, "ccc"_f = 4.2, "d"_f = 8.4};

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
