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
    @ingroup  utility
    @brief    Extracts the identifiers of the fields of a product type.

    @note If some fields are unnamed, the associated identifier is kumi::unit.

    @tparam   T the type of the product type from which to extract identifierss.
    @return   A tuple of the identifierss of a product type if there are any.

    @see kumi::tuple
    @see kumi::record

    ## Example:
    @include doc/infra/members_of.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto members_of(as<T>) noexcept
  {
    if constexpr (concepts::empty_product_type<T>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple{identifier_of<element_t<I, T>>()...};
      }(std::make_index_sequence<size_v<T>>{});
  }

  //====================================================================================================================
  /**
    @ingroup  utility
    @brief    Extracts the values of the fields of a product type.

    @tparam   T the type of the product type from which to extract values.
    @param    t the product_type from which to extract values.
    @return   A tuple of references to the values of a kumi::product_type.

    @see kumi::tuple
    @see kumi::record

    ## Example:
    @include doc/infra/values_of.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto values_of(T&& t) noexcept
  {
    if constexpr (concepts::empty_product_type<T>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<result::field_value_of_t<member_t<I, T>>...>{field_value_of(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<size_v<T>>{});
  }

  namespace result
  {
    template<concepts::product_type T> struct members_of
    {
      using type = decltype(kumi::members_of(as<T>{}));
    };

    template<concepts::product_type T> struct values_of
    {
      using type = decltype(kumi::values_of(std::declval<T>()));
    };

    template<concepts::product_type T> using members_of_t = typename members_of<T>::type;

    template<concepts::product_type T> using values_of_t = typename values_of<T>::type;
  }
}
