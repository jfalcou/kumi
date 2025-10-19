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
  //! @defgroup algorithm Tuple Algorithms
  //! @brief    Algorithms for manipulating kumi::tuple
  //!
  //! @addtogroup algorithm
  //! @{
  //!   @defgroup transforms Tuple Transformations
  //!   @brief    Algorithms applying transformation to tuple
  //!
  //!   @defgroup queries Tuple Queries
  //!   @brief    Algorithms querying properties from tuples
  //!
  //!   @defgroup reductions Tuple Generalized Reductions
  //!   @brief    Algorithms performing reductions over tuples
  //!
  //!   @defgroup generators Tuple Generators
  //!   @brief    Algorithms generating tuples
  //! @}
  //================================================================================================
}

#include <kumi/algorithm/back-front.hpp>
#include <kumi/algorithm/cartesian_product.hpp>
#include <kumi/algorithm/cat.hpp>
#include <kumi/algorithm/convert.hpp>
#include <kumi/algorithm/extract.hpp>
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
#include <kumi/algorithm/tiler.hpp>
#include <kumi/algorithm/transpose.hpp>
#include <kumi/algorithm/traits.hpp>
#include <kumi/algorithm/unique.hpp>
#include <kumi/algorithm/zip.hpp>
