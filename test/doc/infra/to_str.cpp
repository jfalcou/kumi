/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>
#include <cstdint>

namespace ns
{
  struct tax_t : kumi::identifier<tax_t>
  {
    using kumi::identifier<tax_t>::operator=;

    friend constexpr auto to_str(tax_t const&)
    {
      return kumi::str{"Taxes Threshold"}; 
    }
  };
  inline constexpr tax_t tax{};

  struct deduction_t : kumi::identifier<deduction_t>
  {
    using kumi::identifier<deduction_t>::operator=;
  };
  inline constexpr deduction_t deduction{};

  
}

int main()
{
   
  kumi::record payment= {ns::tax = 12.80, ns::deduction = 10.8};
  std::cout << payment << "\n";
}
