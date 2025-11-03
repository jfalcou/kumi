//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/pp_helpers.hpp>
#include <kumi/utils/traits.hpp>
#include <kumi/utils/concepts.hpp>
#include <kumi/detail/abi.hpp>
#include <kumi/detail/str.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup product_types 
  //! @class field_capture
  //! @brief Named wrapper over a type.
  //!
  //! kumi::field_capture provides a way to define named fields in a kumi::tuple.
  //!
  //! @tparam ID a compile time string that is used to retrieve the field.
  //! @tparam T the type of the value that is wrapped.
  //================================================================================================
  template<kumi::str ID, typename T>
  struct field_capture
  {
    /// Underlying type of a field_capture
    using type = T;
    T value;

    /// Name associated to the field_capture 
    static constexpr auto name = ID;

    static constexpr bool is_field_capture = true;
    
    //==============================================================================================
    /// @ingroup product_types 
    //! @related kumi::field_capture
    //! @brief Inserts a kumi::field_capture in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT,Traits> &operator<<( std::basic_ostream<CharT, Traits> &os
                                                       , field_capture const& w) noexcept
    {
      return os << ID << " : " << w.value;
    }
  };
    
  namespace _
  {
    template<kumi::str ID, typename T>
    KUMI_ABI constexpr T       &  get_field(field_capture<ID, T>       & a) noexcept { return a.value; }
    template<kumi::str ID, typename T>
    KUMI_ABI constexpr T       && get_field(field_capture<ID, T>       &&a) noexcept { return static_cast<T&&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_ABI constexpr T const && get_field(field_capture<ID, T> const &&a) noexcept { return static_cast<T const &&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_ABI constexpr T const &  get_field(field_capture<ID, T> const & a) noexcept { return a.value; }
  }

  //================================================================================================
  //! @ingroup product_types 
  //! @brief Extracts the value from a kumi::field_capture or returns the parameter 
  //!
  //! @note If the unqualified type of U is not a field_capture, simply forwards the parameter
  //! @tparam   U The type to unwrap 
  //! @param    u A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //! @related kumi::field_capture
  //================================================================================================
  template<typename U>
  KUMI_ABI constexpr decltype(auto) unwrap_field_value(U&& u) noexcept
  {
    using T = std::remove_cvref_t<U>;
    if constexpr ( is_field_capture_v<T> )
      return _::get_field(KUMI_FWD(u));
    else 
      return KUMI_FWD(u);
  } 

  namespace result
  {
    template<typename T>
    struct unwrap_field_value
    {
        using type = decltype(kumi::unwrap_field_value(std::declval<T>()));
    };

    template<typename T>
    using unwrap_field_value_t = typename unwrap_field_value<T>::type;
  }
  
  //================================================================================================
  //! @ingroup product_types 
  //! @class field_name
  //! @brief Named wrapper used to instantiate a kumi::field_capture.
  //!
  //! kumi::field_name provides a way to instantiate a kumi::field_capture using
  //! a user defined literal prefix.
  //!
  //! @tparam ID a compile time string that is used to name the field.
  //================================================================================================
  template<kumi::str ID>
  struct field_name
  {
    /// Name associated to the field_name
    static constexpr auto name = ID;
    
    /// String view of the name of the field_capture
    static constexpr auto to_string() 
    {
      return ID.value();
    }
   
    //==============================================================================================
    //! @brief Builds a field_capture from the given value.
    //! @tparam T The type to wrap.
    //! @param  v The value to capture. 
    //! @return A kumi::field_capture containing the value.
    //==============================================================================================
    template<typename T>
    constexpr field_capture<ID, std::unwrap_ref_decay_t<T>> operator=(T v) const
    {
      return { std::move(v) };
    }

    //==============================================================================================
    /// @ingroup product_types 
    //! @related kumi::field_name
    //! @brief Inserts a kumi::field_name in an output stream
    //==============================================================================================
    friend std::ostream& operator<<(std::ostream& os, field_name const&)
    {
      return os << ID;
    }
  };
}
