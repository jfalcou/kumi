//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::_
{
  //================================================================================================
  //! @ingroup utility
  //! @brief  Provides an extension point `as_streamable` in order to output values of types with
  //!         no stream operator defined.
  //!
  //! @note This function is an implementation detail and only documented to show how to use
  //!       the `as_streamable` extension point.
  //!
  //! @tparam   T Type of the element to output.
  //! @param    e The value of the element to output.
  //! @return   A value that can be passed to an output stream.
  //!
  //! ## Example:
  //! @include doc/infra/as_streamable.cpp
  //================================================================================================
  template<typename T> auto make_streamable(T const& e)
  {
    if constexpr (requires(std::ostream& os) { os << e; }) return e;
    else if constexpr (requires { as_streamable(e); }) return as_streamable(e);
    else return kumi::unknown{};
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Provides an extension point `to_str` in order to output types with no textual
  //!        representation defined.
  //!
  //! @note This function is an implementation detail and only documented to show how to use
  //!       the `to_str` extension point. It is used in order to handle identifiers/fields
  //!       display and manipulations.
  //!
  //! @tparam   T Type of the element to output.
  //! @param    t The value of the element to output.
  //! @return   A kumi::str representing the input type
  //!
  //! ## Example:
  //! @include doc/infra/to_str.cpp
  //================================================================================================
  template<typename T> constexpr str make_str(T const& t)
  {
    if constexpr (requires {
                    { to_str(t) } -> std::same_as<str>;
                  })
    {
      if constexpr (_::constant_evaluable<to_str(std::remove_cvref_t<T>{})>) return to_str(t);
      else static_assert(false, "Provided to_str(...) function is not callable in a constant evaluated context");
    }
    else return typer<std::remove_cvref_t<T>>();
  }
}
