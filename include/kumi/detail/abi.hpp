//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#if defined(KUMI_DOXYGEN_INVOKED)
#   define KUMI_TRIVIAL inline
#   define KUMI_TRIVIAL_NODISCARD [[nodiscard]] inline
#elif defined(__GNUC__)
#   define KUMI_TRIVIAL [[gnu::always_inline, gnu::flatten, gnu::artificial]] inline
#   define KUMI_TRIVIAL_NODISCARD [[nodiscard, gnu::always_inline, gnu::flatten, gnu::artificial]] inline
#elif defined(_MSC_VER)
#   define KUMI_TRIVIAL __forceinline
#   define KUMI_TRIVIAL_NODISCARD [[nodiscard]]
#endif
