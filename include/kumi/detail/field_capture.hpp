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
    friend std::ostream& operator<<(std::ostream& os, field_capture const& w)
    {
      return os << ID << " : " << w.value;
    }
  };
    
  namespace _
  {
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T       &  get_field(field_capture<ID, T>       & a) noexcept { return a.value; }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T       && get_field(field_capture<ID, T>       &&a) noexcept { return static_cast<T&&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T const && get_field(field_capture<ID, T> const &&a) noexcept { return static_cast<T const &&>(a.value); }
    template<kumi::str ID, typename T>
    KUMI_TRIVIAL constexpr T const &  get_field(field_capture<ID, T> const & a) noexcept { return a.value; }
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
  KUMI_TRIVIAL constexpr decltype(auto) unwrap_field_value(U&& u) noexcept
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
  //! @ingroup tuple
  //! @brief Extracts the value from a kumi::field_capture if the given template type is a
  //!        kumi::record or returns the raw kumi::field_capture otherwise.
  //!
  //! @note If the unqualified type of T is not a record, simply forwards the parameter
  //! @tparam   T The type to check
  //! @tparam   U The type to unwrap
  //! @param    u A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //!
  //! ## Heloer type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename T, typename U> struct unwrap_if_record;
  //!
  //!   template<typename T, typename U>
  //!   using unwrap_if_record_t = typename unwrap_if_record<T,U>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::unwrap_if_record
  //!
  //! @related kumi::field_capture
  //================================================================================================
  template<typename T, typename U>
  KUMI_TRIVIAL constexpr decltype(auto) unwrap_if_record(U&& u) noexcept
  {
      if constexpr ( record_type<std::remove_cvref_t<T>> )
          return unwrap_field_value<U>(KUMI_FWD(u));
      else
          return KUMI_FWD(u);
  }

  namespace result
  {
    template<typename T, typename U>
    struct unwrap_if_record
    {
        using type = decltype(kumi::unwrap_if_record<T>(std::declval<U>()));
    };

    template<typename T, typename U>
    using unwrap_if_record_t = typename unwrap_if_record<T, U>::type;
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
    
    //==============================================================================================
    //! @brief Builds a field_capture from the given value.
    //! @tparam T The type to wrap.
    //! @param  v The value to capture. 
    //! @return A kumi::field_capture containing the value.
    //==============================================================================================
    template<typename T>
    constexpr field_capture<ID, std::unwrap_ref_decay_t<T>> operator=(T v)
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
