//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  //! @ingroup  utility
  //! @class    field
  //! @brief    Named wrapper over a type.
  //!
  //! kumi::field provides a way to define named fields in a product type. Any type can be used as an identifier as long
  //! as it models kumi::concepts::identifier.
  //!
  //! @tparam Id a type that serves as the label of the field.
  //! @tparam T the type of the value associated to the label.
  //====================================================================================================================
  template<concepts::identifier Id, typename T> struct field
  {
    using type = T;
    using identifier_type = Id;
    using inner_type = std::type_identity<T>;

    T value;

    /// Name associated to the field
    static constexpr auto name() { return Id::to_str(); }

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(value); }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(value); }

    //==================================================================================================================
    /// @ingroup utility
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==================================================================================================================
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
    using inner_type = std::type_identity<T>;

    /// Name associated to the field
    static constexpr auto name() { return Id::to_str(); }

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(*this); }

    //==================================================================================================================
    /// @ingroup utility
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << Id{} << " : " << _::make_streamable(w(_::key_of_t<decltype(w)>{}));
    }
  };

  //====================================================================================================================
  //! @ingroup  utility
  //! @brief    Extracts the name from a kumi::concepts::field or returns the parameter.
  //!
  //! @note     If the unqualified type of input does not model kumi::concepts::field, returns kumi::unkown.
  //! @tparam   T The name to extract name from.
  //! @return   The name of the field or kumi::unknown.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Ts> struct name_of;
  //!
  //!   template<typename T> using name_of_t = typename name_of<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::name_of
  //!
  //! ## Example:
  //! @include doc/infra/name_of.cpp
  //====================================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr auto name_of(as<T>) noexcept
  {
    if constexpr (concepts::field<T>) return _::key_of_t<T>{};
    else return kumi::unknown{};
  };

  //====================================================================================================================
  //! @ingroup  utility
  //! @brief    Extracts the value from a kumi::concepts::field or returns the parameter
  //!
  //! @note     If the unqualified type of input does not model kumi::concepts::field, simply forwards the parameter
  //! @tparam   T The type to extract the value from<.
  //! @param    t A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Ts> struct field_value_of;
  //!
  //!   template<typename T> using field_value_of_t = typename field_value_of<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::field_value_of
  //!
  //! ## Example:
  //! @include doc/infra/field_value_of.cpp
  //====================================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of(T&& t) noexcept
  {
    if constexpr (concepts::field<T>) return (KUMI_FWD(t)(_::key_of_t<T>{}));
    else return KUMI_FWD(t);
  };

  //====================================================================================================================
  //! @ingroup  utility
  //! @brief    Creates a field from a given value keeping the qualifiers.
  //!
  //! @tparam   Name The label to associate to the field.
  //! @param    t A forwarding reference to the input object.
  //! @return   A `field` that correctly keeps the qualified input type.
  //! @related  kumi::field
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Ts> struct capture_field;
  //!
  //!   template<typename T> using capture_field_t = typename capture_field<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::capture_field
  //!
  //! ## Example:
  //! @include doc/infra/capture_field.cpp
  //====================================================================================================================
  template<concepts::identifier auto Name, typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) capture_field(T&& t) noexcept
  {
    return field<decltype(Name), T>{KUMI_FWD(t)};
  }

  //====================================================================================================================
  //! @ingroup  utility
  //! @brief    Casts the provided value to the target type using `static_cast`.
  //!
  //! @note If the type to convert to models kumi::concepts::field, does not rename the input parameter.
  //!
  //! @tparam   U The type to convert the parameter to.
  //! @param    t A forwarding reference to the input object.
  //! @return   A value of type U.
  //! @related  kumi::field
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Ts> struct field_cast;
  //!
  //!   template<typename T> using field_cast_t = typename field_cast<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::field_cast
  //!
  //! ## Example:
  //! @include doc/infra/field_cast.cpp
  //====================================================================================================================
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
