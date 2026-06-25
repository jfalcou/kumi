//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

//======================================================================================================================
// Check if the user has provided a custom configuration file in their include path
//======================================================================================================================
#if __has_include(<kumi_config.hpp>)
#include <kumi_config.hpp>
#else
//======================================================================================================================
// Default Library Configuration
//======================================================================================================================
namespace kumi::config
{
  /// @brief Default size type for KUMI str
  using default_size_type = unsigned int;

  /// @brief Maximum number of dimensions for KUMI str
  inline constexpr default_size_type max_size = 64;
}
#endif
