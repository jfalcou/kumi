//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/abi.hpp>
#include <kumi/detail/str.hpp>
#include <kumi/detail/unit_type.hpp>

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
  template<str ID, typename T>
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
  //! @note If the unqualified type of T is not a field_capture returns kumi::none.
  //! @tparam   T The name to extract name from. 
  //! @return   The name of the field_capture or kumi::none.
  //! @related kumi::field_capture
  //================================================================================================
  template<typename T>
  [[nodiscard]] KUMI_ABI constexpr auto name_of( as<T> ) noexcept
  {
    using U = std::remove_cvref_t<T>;
    if constexpr ( requires{U::is_field_capture;} ) return U::name;
    else                                            return kumi::none;
  }
  
  //================================================================================================
  //! @ingroup product_types 
  //! @brief Extracts the value from a kumi::field_capture or returns the parameter 
  //!
  //! @note If the unqualified type of T is not a field_capture, simply forwards the parameter
  //! @tparam   T The type to unwrap 
  //! @param    t A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //! @related kumi::field_capture
  //================================================================================================
  template<typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of( T && t ) noexcept
  {
    using U = std::remove_cvref_t<T>;
    if constexpr ( requires {U::is_field_capture;} )  return _::get_field(KUMI_FWD(t));
    else                                              return KUMI_FWD(t);
  }

  namespace result
  {
    template<typename T> struct name_of
    {
      using type = decltype( kumi::name_of( as<T>{} ));
    };

    template<typename T> struct field_value_of
    {
      using type = decltype( kumi::field_value_of( std::declval<T>() ));
    };

    template<typename T> using name_of_t = typename name_of<T>::type;

    template<typename T> using field_value_of_t = typename field_value_of<T>::type;
  }

}
