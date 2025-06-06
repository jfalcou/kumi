//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/pp_helpers.hpp>
#include <kumi/detail/str.hpp>

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
    /// @ingroup member_capture
    //! @related kumi::member_capture
    //! @brief Inserts a kumi::member_capture in an output stream
    //==============================================================================================
    friend std::ostream& operator<<(std::ostream& os, member_capture const& w)
    {
      return os << ID << " : " << w.value;
    }
  };
    
  namespace _
  {
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T       &  get_member(member_capture<ID, T>       & a) noexcept { return a.value; }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T       && get_member(member_capture<ID, T>       &&a) noexcept { return static_cast<T&&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T const && get_member(member_capture<ID, T> const &&a) noexcept { return static_cast<T const &&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T const &  get_member(member_capture<ID, T> const & a) noexcept { return a.value; }
  }

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
    //! @tparam T The type to wrap.
    //! @param  v The value to capture. 
    //! @return A kumi::member_capture containing the value.
    //==============================================================================================
    template<typename T>
    constexpr member_capture<ID, std::unwrap_ref_decay_t<T>> operator=(T v)
    {
      return { std::move(v) };
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
}
