//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

//======================================================================================================================
/**
  @namespace kumi
  @brief Main KUMI namespace
**/
//======================================================================================================================
namespace kumi
{
  //====================================================================================================================
  /**
    @defgroup kumi_utility   Helper Types and Functions
    @brief    Helpers to adapt, build and introspect kumi::product_type

    @defgroup kumi_concepts     Product Type Related Concepts
    @brief    Concepts refining product type properties

    @defgroup kumi_traits     Product Type Related Traits
    @brief    Traits and extension points for product types

    @defgroup kumi_tuple_traits  Tuple Related Traits
    @ingroup  kumi_traits
    @brief    Traits and extension points for kumi::tuple

    @defgroup kumi_record_traits Record Related Traits
    @ingroup  kumi_traits
    @brief    Traits and extension points for kumi::record
  **/
  //====================================================================================================================
}

#include <kumi/detail/detail.hpp>
#include <kumi/utils/as.hpp>
#include <kumi/utils/builder.hpp>
#include <kumi/utils/traits.hpp>
#include <kumi/utils/concepts.hpp>
#include <kumi/utils/unit_type.hpp>
#include <kumi/utils/identifier.hpp>
#include <kumi/utils/ct_helpers.hpp>
#include <kumi/utils/projections.hpp>
#include <kumi/utils/std.hpp>
