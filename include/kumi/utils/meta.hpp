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
  //! @ingroup utility
  //! @brief Extracts the name from a kumi::field_capture or returns the parameter.
  //!
  //! @note If the unqualified type of T is not a field_capture returns kumi::none.
  //! @tparam   T The name to extract name from.
  //! @return   The name of the field_capture or kumi::none.
  //================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr auto name_of(as<T>) noexcept
  {
    if constexpr (is_field_capture_v<std::remove_cvref_t<T>>) return std::remove_cvref_t<T>::name;
    else return kumi::none;
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief Extracts the value from a kumi::field_capture or returns the parameter
  //!
  //! @note If the unqualified type of T is not a field_capture, simply forwards the parameter
  //! @tparam   T The type to unwrap
  //! @param    t A forwarding reference to the input object.
  //! @return   A forwarded value of the unwrapped object.
  //================================================================================================
  template<typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of(T&& t) noexcept
  {
    if constexpr (is_field_capture_v<std::remove_cvref_t<T>>) return _::get_field(KUMI_FWD(t));
    else return KUMI_FWD(t);
  };

  //================================================================================================
  //! @ingroup algorithm
  //! @brief Extracts the value with type Target of a kumi::product_type.
  //!
  //! @note This function is not callable on a product_type with duplicate types. It is provided
  //!       as an utility for User Defined Types, kumi types have their own overloads.
  //!
  //! @tparam   Target The type of the field to extract from the product type.
  //! @tparam   T the type of the product_type from which to the field.
  //! @param    t the product_type from which to the field.
  //! @return   A references to the values of a kumi::product_type.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/typed_get_udt.cpp
  //================================================================================================
  template<typename Target, product_type T>
  requires(_::typed_get_compliant<Target, T>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(T&& t) noexcept
  {
    constexpr std::size_t Idx = [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_type_v<Target, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    return get<Idx>(KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup algorithm
  //! @brief Extracts the values of the fields of a kumi::product_type.
  //!
  //! @tparam   T the type of the product_type from which to extract names.
  //! @param    t the product_type from which to extract names.
  //! @return   A tuple of references to the values of a kumi::product_type.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/named_get_udt.cpp
  //================================================================================================
  template<str Name, product_type T>
  requires(_::named_get_compliant<Name, T>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(T&& t) noexcept
  {
    constexpr std::size_t Idx = [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_value_v<Name, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    return field_value_of(get<Idx>(KUMI_FWD(t)));
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

    template<typename T> using name_of_t = typename name_of<T>::type;

    template<typename T> using field_value_of_t = typename field_value_of<T>::type;
  }
}
