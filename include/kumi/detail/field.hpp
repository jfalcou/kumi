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
  /**
    @ingroup  types
    @class    field
    @brief    Named wrapper over a type.

    kumi::field provides a way to define named fields in a product type. Any type can be used as an identifier as long
    as it models kumi::concepts::identifier.

    @tparam Id a compile time string that is used to retrieve the field.
    @tparam T the type of the value that is wrapped.
  **/
  //====================================================================================================================
  template<typename Id, typename T> struct field
  {
    /// Name associated to the field
    static constexpr auto label() { return kumi::_::make_str(Id{}); }

    using type = T;
    using identifier_type = Id;
    using inner_type = std::type_identity<T>;
    using label_type = std::integral_constant<kumi::str, label()>;

    T value;

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(value); }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(value); }

    KUMI_ABI constexpr T& operator()(label_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(label_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const& operator()(label_type) const& noexcept { return value; }

    KUMI_ABI constexpr T const&& operator()(label_type) const&& noexcept { return static_cast<T const&&>(value); }

    //==================================================================================================================
    /// @ingroup utility
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << kumi::_::make_str(std::remove_cvref_t<Id>{}) << " : " << kumi::_::make_streamable(w.value);
    }
  };

  // EBO
  template<typename Id, typename T>
  requires(std::is_empty_v<T>)
  struct field<Id, T> : T
  {
    /// Name associated to the field
    static constexpr auto label() { return kumi::_::make_str(Id{}); }

    using type = T;
    using identifier_type = Id;
    using inner_type = std::type_identity<T>;
    using label_type = std::integral_constant<kumi::str, label()>;

    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T& operator()(label_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(label_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const& operator()(label_type) const& noexcept { return *this; }

    KUMI_ABI constexpr T const&& operator()(label_type) const&& noexcept { return static_cast<T const&&>(*this); }

    //==================================================================================================================
    /// @ingroup utility
    //! @related kumi::field
    //! @brief Inserts a kumi::field in an output stream
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << kumi::_::make_str(std::remove_cvref_t<Id>{}) << " : "
                << kumi::_::make_streamable(w(_::identifier_of_t<decltype(w)>{}));
    }
  };

  /// Specialisation to clearly indicate an error
  template<typename Id, typename T>
  requires(!kumi::_::valid_label<Id>)
  struct field<Id, T>
  {
    field(T&&) = delete;
    static_assert(kumi::_::valid_label<Id>, "User defined to_str(...) function is not constexpr");
  };

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Extracts the identifiers from a kumi::concepts::field or returns the parameter.

    @note     If the unqualified type of input does not model kumi::concepts::field, returns kumi::unkown.
    @tparam   T The type to extract the identifier from.
    @return   The identifier of the field or kumi::unknown.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Ts> struct identifier_of;

      template<typename T> using identifier_of_t = typename identifier_of<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::identifier_of

    ## Example:
    @include doc/infra/identifier_of.cpp
  **/
  //====================================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI consteval auto identifier_of() noexcept
  {
    if constexpr (kumi::_::field<T>) return kumi::_::identifier_of_t<T>{};
    else return kumi::unknown{};
  }

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Extracts the label from a kumi::concepts::field or returns the parameter.

    @note     If the unqualified type of input does not model kumi::concepts::field, returns kumi::unkown.
    @tparam   T The type to extract label from.
    @return   The label of the field as a kumi::str.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Ts> struct label_of;

      template<typename T> using label_of_t = typename name_of<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::label_of

    ## Example:
    @include doc/infra/label_of.cpp
  **/
  //====================================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI consteval str label_of() noexcept
  {
    if constexpr (kumi::_::field<T>) return kumi::_::label_of_t<T>{};
    else return kumi::unknown{};
  }

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Extracts the value from a kumi::concepts::field or returns the parameter

    @note     If the unqualified type of input does not model kumi::concepts::field, simply forwards the parameter
    @tparam   T The type to extract the value from<.
    @param    t A forwarding reference to the input object.
    @return   A forwarded value of the unwrapped object.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Ts> struct field_value_of;

      template<typename T> using field_value_of_t = typename field_value_of<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::field_value_of

    ## Example:
    @include doc/infra/field_value_of.cpp
  **/
  //====================================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of(T&& t) noexcept
  {
    if constexpr (kumi::_::field<T>) return (KUMI_FWD(t)(kumi::_::identifier_of_t<T>{}));
    else return KUMI_FWD(t);
  }

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Creates a field from a given value keeping the qualifiers.

    @tparam   Name The label to associate to the field.
    @param    t A forwarding reference to the input object.
    @return   A `field` that correctly keeps the qualified input type.
    @related  kumi::field

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Ts> struct capture_field;

      template<typename T> using capture_field_t = typename capture_field<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::capture_field

    ## Example:
    @include doc/infra/capture_field.cpp
  **/
  //====================================================================================================================
  template<_::identifier auto Name, typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) capture_field(T&& t) noexcept
  {
    return kumi::field<decltype(Name), T>{KUMI_FWD(t)};
  }

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Casts the provided value to the target type using `static_cast`.

    @note If the type to convert models kumi::concepts::field, the function does not rename the input parameter.

    @tparam   U The type to convert the parameter to.
    @param    t A forwarding reference to the input object.
    @return   A value of type U.
    @related  kumi::field

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Ts> struct field_cast;

      template<typename T> using field_cast_t = typename field_cast<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::field_cast

    ## Example:
    @include doc/infra/field_cast.cpp
  **/
  //====================================================================================================================
  template<typename U, typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_cast(T&& t) noexcept
  {
    if constexpr (kumi::_::field<U>)
      return kumi::field<kumi::_::identifier_of_t<T>, kumi::_::type_of_t<U>>{
        static_cast<kumi::_::type_of_t<U>>(KUMI_FWD(t)(kumi::_::identifier_of_t<T>{}))};
    else if constexpr (!kumi::_::field<T>) return static_cast<kumi::_::type_of_t<U>>(KUMI_FWD(t));
    else return kumi::field<kumi::_::identifier_of_t<T>, U>{static_cast<U>(KUMI_FWD(t)(kumi::_::identifier_of_t<T>{}))};
  }

  namespace result
  {
    template<typename T> struct identifier_of
    {
      using type = decltype(kumi::identifier_of<T>());
    };

    template<typename T> struct label_of
    {
      using type = decltype(kumi::label_of<T>());
    };

    template<typename T> struct field_value_of
    {
      using type = decltype(kumi::field_value_of(std::declval<T>()));
    };

    template<kumi::_::identifier auto Name, typename T> struct capture_field
    {
      using type = decltype(kumi::capture_field<Name>(std::declval<T>()));
    };

    template<typename U, typename T> struct field_cast
    {
      using type = decltype(kumi::field_cast<U, T>(std::declval<T>()));
    };

    template<typename T> using identifier_of_t = typename kumi::result::identifier_of<T>::type;

    template<typename T> using label_of_t = typename kumi::result::label_of<T>::type;

    template<typename T> using field_value_of_t = typename kumi::result::field_value_of<T>::type;

    template<_::identifier auto Name, typename T>
    using capture_field_t = typename kumi::result::capture_field<Name, T>::type;

    template<typename U, typename T> using field_cast_t = typename kumi::result::field_cast<U, T>::type;
  }
}
