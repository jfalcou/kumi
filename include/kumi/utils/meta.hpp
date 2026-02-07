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
  //! @include doc/infra/typed_get_udt.cpp
  //================================================================================================
  template<typename Target, concepts::product_type T>
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
  //! @include doc/infra/named_get_udt.cpp
  //================================================================================================
  template<concepts::identifier auto Name, concepts::product_type T>
  requires(_::named_get_compliant<decltype(Name), T>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(T&& t) noexcept
  {
    constexpr std::size_t Idx = [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_value_v<decltype(Name), element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    return field_value_of(get<Idx>(KUMI_FWD(t)));
  }

  template<str Name, concepts::product_type T>
  requires(_::named_get_compliant<name<Name>, T>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(T&& t) noexcept
  {
    constexpr std::size_t Idx = [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_value_v<name<Name>, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    return field_value_of(get<Idx>(KUMI_FWD(t)));
  }
}
