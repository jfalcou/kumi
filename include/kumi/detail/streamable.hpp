//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#ifdef KUMI_DOXYGEN_INVOKED
//======================================================================================================================
/**
  @ingroup  utility
  @brief    Provides an extension point `as_streamable` in order to output types with no stream
            operator defined.

  This function does not exist in the kumi namespace, it is supposed to be found via Argument Dependant Lookup for
  user defined types.

  @param    e The value of the element to output.
  @return   A value that can be passed to an output stream.

  ## Example:
  @include doc/infra/as_streamable.cpp
**/
//======================================================================================================================
auto as_streamable(auto e);

//======================================================================================================================
/**
  @ingroup utility
  @brief Provides an extension point `to_str` in order to output types with no textual
         representation defined.

  This function does not exist in the kumi namespace, it is supposed to be found via Argument Dependant Lookup for
  user defined types. It is used in order to handle identifiers/fields display and manipulations.
   to_str needs to be constexpr callable, if not some concepts might fail unexpectedly.

  @param    e The value of the element to output.
  @return   A kumi::str representing the input type

  ## Example:
  @include doc/infra/to_str.cpp
**/
//======================================================================================================================
kumi::str constexpr to_str(auto e);
#endif

namespace kumi::_
{
  template<typename T> auto make_streamable(T const& e)
  {
    if constexpr (requires(std::ostream& os) { os << e; }) return e;
    else if constexpr (requires { as_streamable(e); }) return as_streamable(e);
    else return kumi::unknown{};
  }

  template<valid_label T> consteval str make_str(T const& t)
  {
    if constexpr (requires { to_str(t); }) return to_str(t);
    else return typer<std::remove_cvref_t<T>>();
  }
}
