//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

//==================================================================================================
//! @namespace kumi
//! @brief Main KUMI namespace
//==================================================================================================
namespace kumi
{
  //================================================================================================
  //! @defgroup details Helper Types and Functions
  //! @brief    Tools for interacting with kumi::tuple
  //!
  //! @defgroup concepts     Tuple Related Concepts
  //! @brief    Definition for product types related Concepts
  //!
  //! @defgroup traits     Tuple Related Traits
  //! @brief    Definition for kumi::tuple traits and extension points
  //================================================================================================
}

// Building blocks
#include <kumi/detail/abi.hpp>
#include <kumi/detail/streamable.hpp>
#include <kumi/detail/stdfix.hpp>
#include <kumi/detail/concepts.hpp>

// Types
#include <kumi/detail/str.hpp>
#include <kumi/detail/typename.hpp>

// Functionnalities
#include <kumi/detail/meta_helpers.hpp>
#include <kumi/detail/binder.hpp>
#include <kumi/detail/optimized.hpp>
