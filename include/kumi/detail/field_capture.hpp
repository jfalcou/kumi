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
#include <kumi/detail/streamable.hpp>

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
  template<str ID, typename T> struct field_capture
  {
    /// Underlying type of a field_capture
    using type = T;
    T value;

    KUMI_ABI constexpr type& get() & noexcept { return value; }

    KUMI_ABI constexpr type&& get() && noexcept { return static_cast<type&&>(value); }

    KUMI_ABI constexpr type const&& get() const&& noexcept { return static_cast<type const&&>(value); }

    KUMI_ABI constexpr type const& get() const& noexcept { return value; }

    /// Name associated to the field_capture
    static constexpr auto name = ID;

    static constexpr bool is_field_capture = true;

    //==============================================================================================
    /// @ingroup product_types
    //! @related kumi::field_capture
    //! @brief Inserts a kumi::field_capture in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         field_capture const& w) noexcept
    {
      return os << ID << " : " << _::make_streamable(w.value);
    }
  };

  // EBO
  template<str ID, typename T>
  requires(std::is_empty_v<T>)
  struct field_capture<ID, T> : T
  {
    using type = T;

    KUMI_ABI constexpr T& get() & noexcept { return static_cast<T&>(*this); }

    KUMI_ABI constexpr T&& get() && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const&& get() const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T const& get() const& noexcept { return static_cast<T const&>(*this); }

    static constexpr auto name = ID;

    static constexpr bool is_field_capture = true;
  };

  namespace _
  {
    template<kumi::str ID, typename T> KUMI_ABI constexpr T& get_field(field_capture<ID, T>& a) noexcept
    {
      return a.get();
    }

    template<kumi::str ID, typename T> KUMI_ABI constexpr T&& get_field(field_capture<ID, T>&& a) noexcept
    {
      return static_cast<T&&>(a.get());
    }

    template<kumi::str ID, typename T> KUMI_ABI constexpr T const&& get_field(field_capture<ID, T> const&& a) noexcept
    {
      return static_cast<T const&&>(a.get());
    }

    template<kumi::str ID, typename T> KUMI_ABI constexpr T const& get_field(field_capture<ID, T> const& a) noexcept
    {
      return a.get();
    }
  }

  //================================================================================================
  //! @ingroup product_types
  //! @brief Creates a field_capture from a given value keeping the qualifiers.
  //!
  //! @note If the unqualified type of T is not a field_capture, simply forwards the parameter
  //! @tparam   Name The name to associate to the field.
  //! @param    t A forwarding reference to the input object.
  //! @return   A `field_capture` that correctly keeps the qualified input type.
  //! @related kumi::field_capture
  //================================================================================================
  template<str Name, typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) capture_field(T&& t) noexcept
  {
    return field_capture<Name, T>{KUMI_FWD(t)};
  }

  //================================================================================================
  //! @ingroup product_types
  //! @brief Casts the provided value to the target type using `static_cast`.
  //!
  //! @note Even when passed in a field_capture as the conversion type, this function does not
  //!       rename the input parameter.
  //!
  //! @tparam   U The type to convert the parameter to.
  //! @param    t A forwarding reference to the input object.
  //! @return   A value of type U.
  //! @related kumi::field_capture
  //================================================================================================
  template<typename U, typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_cast(T&& t) noexcept
  {
    using W = std::remove_cvref_t<U>;
    if constexpr (requires { W::is_field_capture; })
      return field_capture<name_of(as<T>{}), typename W::type>{
        static_cast<typename W::type>(field_value_of(KUMI_FWD(t)))};
    else if constexpr (!requires { std::remove_cvref_t<T>::is_field_capture; })
      return static_cast<typename W::type>(KUMI_FWD(t));
    else return field_capture<name_of(as<T>{}), U>{static_cast<U>(field_value_of(KUMI_FWD(t)))};
  }

  namespace result
  {
    template<str Name, typename T> struct capture_field
    {
      using type = decltype(kumi::capture_field<Name>(std::declval<T>()));
    };

    template<typename U, typename T> struct field_cast
    {
      using type = decltype(kumi::field_cast<U, T>(std::declval<T>()));
    };

    template<str Name, typename T> using capture_field_t = typename capture_field<Name, T>::type;

    template<typename U, typename T> using field_cast_t = typename field_cast<U, T>::type;
  }
}
