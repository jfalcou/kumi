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
  //! @ingroup algorithm
  //! @brief Extracts the names of the fields of a kumi::product_type.
  //!
  //! @note If some fields are unnamed, the associated name is kumi::unit.
  //!
  //! @tparam   T the type of the prodcut_type from which to extract names.
  //! @return   A tuple of the names of a kumi::product_type.
  //!
  //! ## Example:
  //! @include doc/members_of.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto members_of(as<T>) noexcept
  {
    if constexpr (sized_product_type<T, 0>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple{name_of(as<element_t<I, T>>{})...};
      }(std::make_index_sequence<size_v<T>>{});
  }

  //================================================================================================
  //! @ingroup algorithm
  //! @brief Extracts the values of the fields of a kumi::product_type.
  //!
  //! @tparam   T the type of the product_type from which to extract names.
  //! @param    t the product_type from which to extract names.
  //! @return   A tuple of references to the values of a kumi::product_type.
  //!
  //! ## Example:
  //! @include doc/values_of.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto values_of(T&& t) noexcept
  {
    if constexpr (sized_product_type<T, 0>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<result::field_value_of_t<member_t<I, T>>...>{field_value_of(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<size_v<T>>{});
  }

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
      return _::get_index_by_name_v<field_name<Name>, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    return field_value_of(get<Idx>(KUMI_FWD(t)));
  }

  namespace result
  {
    template<product_type T> struct members_of
    {
      using type = decltype(kumi::members_of(as<T>{}));
    };

    template<product_type T> struct values_of
    {
      using type = decltype(kumi::values_of(std::declval<T>()));
    };

    template<product_type T> using members_of_t = typename members_of<T>::type;

    template<product_type T> using values_of_t = typename values_of<T>::type;
  }
}
