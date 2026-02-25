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
  //! @defgroup utility   Helper Types and Functions
  //! @brief    Tools for interacting with kumi::product_type
  //!
  //! @defgroup concepts     Product Type Related Concepts
  //! @brief    Definition for product types related Concepts
  //!
  //! @defgroup tuple_concepts  Tuple Related Concepts
  //! @ingroup  concepts
  //! @brief    Definition for kumi::tuple related concepts
  //!
  //! @defgroup record_concepts Record Related Concepts
  //! @ingroup  concepts
  //! @brief    Definition for kumi::record related concepts
  //!
  //! @defgroup traits     Product Type Related Traits
  //! @brief    Definition for product types traits and extension points
  //!
  //! @defgroup tuple_traits  Tuple Related Traits
  //! @ingroup  traits
  //! @brief    Definition for kumi::tuple traits and extension points
  //!
  //! @defgroup record_traits Record Related Traits
  //! @ingroup  traits
  //! @brief    Definition for kumi::record traits and extension points
  //================================================================================================
}

#include <kumi/utils/as.hpp>
#include <kumi/utils/invoke.hpp>

#include <kumi/utils/traits.hpp>
#include <kumi/utils/builder.hpp>
#include <kumi/utils/concepts.hpp>

#include <kumi/utils/unit_type.hpp>
#include <kumi/utils/field.hpp>
#include <kumi/utils/identifier.hpp>
#include <kumi/utils/monoid.hpp>

#include <kumi/utils/indexes.hpp>
#include <kumi/utils/ct_helpers.hpp>

#include <kumi/utils/std.hpp>
