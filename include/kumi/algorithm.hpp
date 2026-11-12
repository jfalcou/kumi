//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  /**
    @defgroup kumi_algorithm Algorithms
    @brief    Algorithms for manipulating Product types

    @{
      @defgroup kumi_transforms Transformations
      @brief Algorithms applying transformation to product types
      @{
        @defgroup kumi_generic_transforms Element-wise Transformations
        @brief Algorithms applying a callable to the elements of any product type

        @defgroup kumi_tuple_transforms Index-wise Transformations
        @brief Algorithms passing the index of each element to the callable, on product types other than records

        @defgroup kumi_record_transforms Field-wise Transformations
        @brief Algorithms passing the name of each field to the callable, on record types
      @}

      @defgroup kumi_projections Projections
      @brief    Algorithms returning components of a product type, selected, repeated, or reordered
      @{
        @defgroup kumi_index_projections Index-wise Projections
        @brief Algorithms selecting components by their position

        @defgroup kumi_type_projections Type-wise Projections
        @brief Algorithms selecting components by their type, through a predicate or their uniqueness
      @}

      @defgroup kumi_restructurings Restructurings
      @brief    Algorithms regrouping the components of product types across levels

      @defgroup kumi_queries Queries
      @brief    Algorithms querying properties from product types

      @defgroup kumi_reductions Generalized Reductions
      @brief    Algorithms performing reductions over product types

      @defgroup kumi_generators Generators
      @brief    Algorithms building product types from values that no input product type holds
    @}
  **/
  //====================================================================================================================
}

#include <kumi/functional.hpp>

#include <kumi/algorithm/apply.hpp>
#include <kumi/algorithm/back_front.hpp>
#include <kumi/algorithm/cartesian_product.hpp>
#include <kumi/algorithm/cast.hpp>
#include <kumi/algorithm/cat.hpp>
#include <kumi/algorithm/contains.hpp>
#include <kumi/algorithm/extract.hpp>
#include <kumi/algorithm/for_each.hpp>
#include <kumi/algorithm/find.hpp>
#include <kumi/algorithm/flatten.hpp>
#include <kumi/algorithm/generate.hpp>
#include <kumi/algorithm/inner_product.hpp>
#include <kumi/algorithm/map.hpp>
#include <kumi/algorithm/push_pop.hpp>
#include <kumi/algorithm/fold.hpp>
#include <kumi/algorithm/minmax.hpp>
#include <kumi/algorithm/partition.hpp>
#include <kumi/algorithm/predicates.hpp>
#include <kumi/algorithm/reorder.hpp>
#include <kumi/algorithm/reduce.hpp>
#include <kumi/algorithm/reverse.hpp>
#include <kumi/algorithm/rotate.hpp>
#include <kumi/algorithm/scan.hpp>
#include <kumi/algorithm/tiler.hpp>
#include <kumi/algorithm/transpose.hpp>
#include <kumi/algorithm/unique.hpp>
#include <kumi/algorithm/zip.hpp>
