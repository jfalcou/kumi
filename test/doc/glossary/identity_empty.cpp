/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <iostream>
#include <stdexcept>

[[noreturn]] void fail() { throw std::runtime_error("never returns"); }

int main()
{
  // the call never yields a value, the exception leaves it
  try
  {
    fail();
  }
  catch (std::exception const& e)
  {
    std::cout << "fail: " << e.what() << '\n';
  }
}
