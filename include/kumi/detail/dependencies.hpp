//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <cstddef>
#include <concepts>
#include <iosfwd>
#include <type_traits>
#include <utility>

// Faster std::forward and std::move, avoid function calls.
#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#define KUMI_MOVE(...) static_cast<std::remove_reference_t<decltype(__VA_ARGS__)>&&>(__VA_ARGS__)

// Faster std::declval
namespace kumi
{
  //====================================================================================================================
  /**
    @ingroup kumi_utility

    @fn declval
    @brief Converts a type `T` to an rvalue reference type for use in unevaluated contexts.

    @groupheader{Call Signature}

    @code
    template<class T>
    constexpr std::add_rvalue_reference_t<T> declval() noexcept;
    @endcode

    @groupheader{Examples}

    @code
    #include <kumi/kumi.hpp>

    struct Foo { int bar(); };

    // Determine the return type without constructing Foo
    using bar_type = decltype(kumi::declval<Foo>().bar()); // bar_type is int
    @endcode

    @note The function has no defined body because it is only used in unevaluated contexts.
    Attempting to call it results in a linker error (or a compile-time error in the
    documentation generation context).
  **/
  //====================================================================================================================
  template<typename T> extern T && (*declval)() noexcept;

  template<typename T>
  requires(std::is_void_v<T>)
  extern void (*declval<T>)() noexcept;
}
