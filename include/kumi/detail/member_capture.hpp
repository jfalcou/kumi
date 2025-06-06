//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/pp_helpers.hpp>
#include <kumi/detail/field.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup member_capture
  //! @class member_capture
  //! @brief Named wrapper over a type.
  //!
  //! kumi::member_capture provides a way to define named fields in a kumi::tuple.
  //!
  //! @tparam ID a compile time string that is used to retrieve the field.
  //! @tparam T the type of the value that is wrapped.
  //================================================================================================
  template<kumi::str ID, typename T>
  struct member_capture
  {
    using type = T;
    T value;

    static constexpr auto name = ID;
    static constexpr bool is_member_capture = true;
    //==============================================================================================
    //! @name Conversions
    //! @{
    //==============================================================================================
    
    //==============================================================================================
    //! @brief  Converts the member_capture<ID, T> to it's underlying type T.
    //! @tparam Us Types composing the destination tuple
    //!
    //==============================================================================================
    constexpr operator T () const noexcept 
    {
      if constexpr (std::is_rvalue_reference_v<T>)
        return std::move(value);
      else
        return value; 
    };

    constexpr operator T& () noexcept { return value; };
    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    /// @ingroup member_capture
    //! @related kumi::member_capture
    //! @brief Inserts a kumi::member_capture in an output stream
    //==============================================================================================
    friend std::ostream& operator<<(std::ostream& os, member_capture const& w)
    {
      return os << ID << " : " << w.value;
    }
  };

  //================================================================================================
  //! @ingroup member_capture
  //! @class member_name
  //! @brief Named wrapper used to instantiate a kumi::member_capture.
  //!
  //! kumi::member_name provides a way to instantiate a kumi::member_capture using
  //! a user defined literal prefix.
  //!
  //! @tparam ID a compile time string that is used to name the field.
  //================================================================================================
  template<kumi::str ID>
  struct member_name
  {
    static constexpr auto name = ID;
    
    //==============================================================================================
    //! @brief Builds a member_capture from the given value.
    //! @tparam ID the compile time name to associate to the value.
    //! @param  v the value to capture. 
    //! @return A kumi::member_capture containing the value.
    //==============================================================================================
    template<typename T>
    constexpr member_capture<ID, typename std::unwrap_ref_decay<T>::type> operator=(T&& v)
    {
      return { KUMI_FWD(v) };
    }

    //==============================================================================================
    /// @ingroup member_capture
    //! @related kumi::member_name
    //! @brief Inserts a kumi::member_name in an output stream
    //==============================================================================================
    friend std::ostream& operator<<(std::ostream& os, member_name const&)
    {
      return os << ID;
    }
  };

  namespace literals
  {
    //==============================================================================================
    //! @ingroup member_capture
    //! @brief Forms a constant kumi::member_name of the desired ID.
    //! @tparam ID the compile time name to build.
    //! @return An instance of kumi::member_name for the specified string
    //==============================================================================================
    template<kumi::str ID>
    inline constexpr auto member = kumi::member_name<ID>{};
    
    //==============================================================================================
    //! @ingroup member_capture
    //! @brief Forms a constant string literal of the desired value.
    //! @return An instance of kumi::member_name for the specified string
    //==============================================================================================
    template<kumi::str ID> constexpr auto operator""_m() noexcept { return member<ID>; }
  }
}

