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
    @brief    Tools for interacting with kumi::product_type

    @defgroup kumi_concepts     Product Type Related Concepts
    @brief    Definition for product types related Concepts

    @defgroup kumi_traits     Product Type Related Traits
    @brief    Definition for product types traits and extension points

    @defgroup kumi_tuple_traits  Tuple Related Traits
    @ingroup  kumi_traits
    @brief    Definition for kumi::tuple traits and extension points

    @defgroup kumi_record_traits Record Related Traits
    @ingroup  kumi_traits
    @brief    Definition for kumi::record traits and extension points
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
