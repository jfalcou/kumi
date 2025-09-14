//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @defgroup algorithm Product Type Algorithms
  //! @brief    Algorithms for manipulating Product types
  //!
  //! @addtogroup algorithm
  //! @{
  //!   @defgroup transforms Product Type Transformations
  //!   @brief Algorithms applying transformation to product types
  //! 
  //!   @addtogroup transforms
  //!   @{  
  //!     @defgroup tuple_transforms Tuple Type Specific Transformations
  //!     @brief Algorithms applying transformation to tuples
  //!   
  //!     @defgroup record_transforms Record Type Specific Transformations
  //!     @brief Algorithms applying transformation to records  
  //!   @}   
  //!
  //!   @defgroup queries Product Type Queries
  //!   @brief    Algorithms querying properties from product types
  //!
  //!   @defgroup reductions Product Type Generalized Reductions
  //!   @brief    Algorithms performing reductions over product types
  //!
  //!   @defgroup generators Product Type Generators
  //!   @brief    Algorithms generating product types
  //! @}
  //================================================================================================
}

#include <kumi/algorithm/meta.hpp>
#include <kumi/algorithm/apply.hpp>
#include <kumi/algorithm/back-front.hpp>
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
#include <kumi/algorithm/traits.hpp>
#include <kumi/algorithm/unique.hpp>
#include <kumi/algorithm/zip.hpp>
