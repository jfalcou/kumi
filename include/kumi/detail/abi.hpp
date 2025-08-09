//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#if defined(KUMI_DEBUG)
#   define KUMI_ABI
#elif defined(__GNUC__)
#   define KUMI_ABI [[gnu::always_inline, gnu::flatten, gnu::artificial]] inline
#elif defined(_MSC_VER)
#   define KUMI_ABI __forceinline
#endif
