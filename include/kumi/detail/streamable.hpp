//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>

namespace kumi::_
{
  //================================================================================================
  //! @ingroup utility 
  //! @brief Provides an extension point `as_streamable` in order to output types with no stream
  //!        operator defined. 
  //!
  //! @note This function is an implementation detail and only documented to show how to use
  //!       the `as_streamable` extension point.
  //!
  //! @tparam   T Type of the element to output. 
  //! @param    e The value of the element to output.
  //! @return   A value that can be passed to an output stream. 
  //!
  //! ## Example:
  //! @include doc/as_streamable.cpp
  //================================================================================================
  template<typename T>
  auto make_streamable(T const& e)
  {
         if constexpr( requires(std::ostream& os){ os << e;}) return e;
    else if constexpr( requires{ as_streamable(e); }        ) return as_streamable(e);
    else                                                      return "(unknown)";
  }
}
