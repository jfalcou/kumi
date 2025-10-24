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
    friend std::ostream& operator<<(std::ostream& os, field_capture const& w)
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
  //template<typename U>
  //KUMI_ABI constexpr decltype(auto) unwrap_field_value(U&& u) noexcept
  //{
  //  using T = std::remove_cvref_t<U>;
  //  if constexpr ( is_field_capture_v<T> )
  //    return _::get_field(KUMI_FWD(u));
  //  else 
  //    return KUMI_FWD(u);
  //} 

  //namespace result
  //{
  //  template<typename T>
  //  struct unwrap_field_value
  //  {
  //      using type = decltype(kumi::unwrap_field_value(std::declval<T>()));
  //  };

  //  template<typename T>
  //  using unwrap_field_value_t = typename unwrap_field_value<T>::type;
  //}

  template<typename T>
  [[nodiscard]] KUMI_ABI constexpr auto name_of( as<T> ) noexcept
  {
    using U = std::remove_cvref_t<T>;
    if constexpr ( is_field_capture_v<U> )  return U::name;
    else                                    return kumi::none;
  }
  
  template<typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of( T && t ) noexcept
  {
    using U = std::remove_cvref_t<T>;
    if constexpr ( is_field_capture_v<U> )  return _::get_field(KUMI_FWD(t));
    else                                    return KUMI_FWD(t);
  }
}
