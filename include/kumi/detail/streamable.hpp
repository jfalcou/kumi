//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <concepts>
#include <kumi/detail/stdfix.hpp>

namespace kumi::_
{
  template<typename Ret, typename Origin>
  concept chainable = std::is_lvalue_reference_v<Ret> && kumi::convertible_to<Origin, Ret>;

  // Checks if T behaves like a standard output stream.
  template<typename T>
  concept stream = requires(T& os, typename T::char_type c, typename T::char_type const* buff, char const* str) {
    typename T::traits_type;

    { os.put(c) } -> chainable<T&>;
    { os.write(buff, 0LL) } -> chainable<T&>;
    { os.flush() } -> chainable<T&>;
    { os << str } -> chainable<T&>;
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief Provides an extension point `as_streamable` in order to output types with no stream
  //!        operator defined.
  //!
  //! @note This function is an implementation detail and only documented to show how to use
  //!       the `as_streamable` extension point.
  //!
  //! @tparam   T Type of the element to output.
  //! @tparam   Os The type of the stream in which to insert.
  //! @param    e The value of the element to output.
  //! @param    os The stream in which to insert the value.
  //! @return   A value that can be passed to an output stream.
  //!
  //! ## Example:
  //! @include doc/as_streamable.cpp
  //================================================================================================
  template<typename T, typename Os>
  requires(stream<Os>)
  auto make_streamable(T const& e, Os& os)
  {
    if constexpr (requires { os << e; }) return e;
    else if constexpr (requires { as_streamable(e); }) return as_streamable(e);
    else return "(unknown)";
  }
}
