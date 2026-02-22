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
  auto nbrs  = kumi::record{"a"_id = 1,"b"_id = 2,"c"_id = 3,"d"_id = 4,"e"_id = 5,"f"_id = 6};
  auto ltrs  = kumi::record{"aa"_id = 'a',"bb"_id = 'b',"cc"_id = 'c'};
  auto ratio = kumi::record{"aaa"_id = 0.1,"bbb"_id = 0.01,"ccc"_id = 0.001,"ddd"_id = 0.0001};

  auto r = kumi::zip_min( nbrs, ltrs, ratio );
  std::cout << r << "\n";
}
