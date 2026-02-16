//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @ingroup product_types
  //! @class field
  //! @brief Named wrapper over a type.
  //!
  //! kumi::field provides a way to define named fields in a kumi::tuple.
  //!
  //! @tparam Id a compile time string that is used to retrieve the field.
  //! @tparam T the type of the value that is wrapped.
  //================================================================================================
  template<concepts::identifier Id, typename T> struct field
  {
    using type = T;
    using identifier_type = Id;

    T value;

    /// Name associated to the field
    static constexpr auto name() { return Id::to_str(); }

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(value); }

    //==============================================================================================
    /// @ingroup product_types
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << Id{} << " : " << _::make_streamable(w.value);
    }
  };

  // EBO
  template<concepts::identifier Id, typename T>
  requires(std::is_empty_v<T>)
  struct field<Id, T> : T
  {
    using type = T;
    using identifier_type = Id;

    /// Name associated to the field
    static constexpr auto name() { return Id::to_str(); }

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(*this); }

    //==============================================================================================
    /// @ingroup product_types
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << Id{} << " : " << _::make_streamable(w(_::key_of_t<decltype(w)>{}));
    }
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief Extracts the name from a kumi::field or returns the parameter.
  //!
  //! @note If the unqualified type of T is not a field returns kumi::unkown.
  //! @tparam   T The name to extract name from.
  //! @return   The name of the field or kumi::unknown.
  //================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr auto name_of(as<T>) noexcept
  {
    if constexpr (concepts::field<T>) return _::key_of_t<T>{};
    else return kumi::unknown{};
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief Extracts the value from a kumi::field or returns the parameter
  //!
  //! @note If the unqualified type of T is not a field, simply forwards the parameter
  //! @tparam   T The type to unwrap
  //! @param    t A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of(T&& t) noexcept
  {
    if constexpr (concepts::field<T>) return (KUMI_FWD(t)(_::key_of_t<T>{}));
    else return KUMI_FWD(t);
  };

  //================================================================================================
  //! @ingroup product_types
  //! @brief Creates a field from a given value keeping the qualifiers.
  //!
  //! @note If the unqualified type of T is not a field, simply forwards the parameter
  //! @tparam   Name The name to associate to the field.
  //! @param    t A forwarding reference to the input object.
  //! @return   A `field` that correctly keeps the qualified input type.
  //! @related kumi::field
  //================================================================================================
  template<concepts::identifier auto Name, typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) capture_field(T&& t) noexcept
  {
    return field<decltype(Name), T>{KUMI_FWD(t)};
  }

  //================================================================================================
  //! @ingroup product_types
  //! @brief Casts the provided value to the target type using `static_cast`.
  //!
  //! @note Even when passed in a field as the conversion type, this function does not
  //!       rename the input parameter.
  //!
  //! @tparam   U The type to convert the parameter to.
  //! @param    t A forwarding reference to the input object.
  //! @return   A value of type U.
  //! @related kumi::field
  //================================================================================================
  template<typename U, typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_cast(T&& t) noexcept
  {
    if constexpr (concepts::field<U>)
      return field<_::key_of_t<T>, _::type_of_t<U>>{static_cast<_::type_of_t<U>>(KUMI_FWD(t)(_::key_of_t<T>{}))};
    else if constexpr (!concepts::field<T>) return static_cast<_::type_of_t<U>>(KUMI_FWD(t));
    else return field<_::key_of_t<T>, U>{static_cast<U>(KUMI_FWD(t)(_::key_of_t<T>{}))};
  }

  namespace result
  {
    template<typename T> struct name_of
    {
      using type = decltype(kumi::name_of(as<T>{}));
    };

    template<typename T> struct field_value_of
    {
      using type = decltype(kumi::field_value_of(std::declval<T>()));
    };

    template<concepts::identifier auto Name, typename T> struct capture_field
    {
      using type = decltype(kumi::capture_field<Name>(std::declval<T>()));
    };

    template<typename U, typename T> struct field_cast
    {
      using type = decltype(kumi::field_cast<U, T>(std::declval<T>()));
    };

    template<typename T> using name_of_t = typename name_of<T>::type;

    template<typename T> using field_value_of_t = typename field_value_of<T>::type;

    template<concepts::identifier auto Name, typename T> using capture_field_t = typename capture_field<Name, T>::type;

    template<typename U, typename T> using field_cast_t = typename field_cast<U, T>::type;
  }
}
