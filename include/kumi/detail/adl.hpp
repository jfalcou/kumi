//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::_
{
  inline namespace cxx20
  {
    struct adl_tag_t
    {
    };

    // @brief Tag for kumi algorithms to be routed to the right namespace via ADL
    KUMI_VARIABLE_ABI constexpr adl_tag_t adl_tag;
  }
}
