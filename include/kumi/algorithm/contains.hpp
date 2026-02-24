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
  namespace _
  {
    template<typename T, typename... Ts>
    constexpr bool contains = ((concepts::field<T> && std::invocable<T, Ts>) || ...);
  }

  //====================================================================================================================
  //! @ingroup queries
  //! @brief Checks if a product type contains a given identifier
  //!
  //! @param t the product type to inspect.
  //! @param id Identifier to check
  //! @return `true` if the current product_type contains a field named with the `id` identifier, and `false` otherwise.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/contains.cpp
  //! @include doc/record/algo/contains.cpp
  //====================================================================================================================
  template<concepts::product_type T, concepts::identifier ID>
  KUMI_ABI constexpr bool contains([[maybe_unused]] T&& t, [[maybe_unused]] ID const& id) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (concepts::record_type<T>)
      return []<std::size_t... I>(std::index_sequence<I...>) {
        return _::can_get_field_by_value<std::remove_cvref_t<ID>, element_t<I, T>...>;
      }(std::make_index_sequence<size_v<T>>{});
    else
      return []<std::size_t... I>(std::index_sequence<I...>) {
        if constexpr (((concepts::field<element_t<I, T>> && std::invocable<element_t<I, T>, std::remove_cvref_t<ID>>) ||
                       ...))
          return true;
        else return false;
      }(std::make_index_sequence<size_v<T>>{});
  }

  //====================================================================================================================
  //! @ingroup queries
  //! @brief Checks if a product type contains at least one of many identifiers
  //!
  //! @param t the product type to inspect.
  //! @param ids Identifiers to check
  //! @return `true` if current product_type contains a field based on the `ids`, and `false` otherwise.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/contains_any.cpp
  //! @include doc/record/algo/contains_any.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Is>
  KUMI_ABI constexpr bool contains_any(T&& t, Is const&... ids) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Is) == 0) return false;
    else return (contains(KUMI_FWD(t), ids) || ...);
  }

  //==================================================================================================================
  //! @ingroup queries
  //! @brief Checks if a product type contains fields based only on selected identifiers
  //!
  //! @param t the product type to inspect.
  //! @param ids Identifiers to check
  //! @return `true` if current the product_type contains a field based on any of the `ids`, and `false` otherwise.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/contains_only.cpp
  //! @include doc/record/algo/contains_only.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Is>
  KUMI_ABI constexpr bool contains_only([[maybe_unused]] T&& t, [[maybe_unused]] Is const&... ids) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Is) == 0) return false;
    else if constexpr (sizeof...(Is) < size_v<T>) return false;
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::contains<element_t<I, T>, Is...> && ...);
      }(std::make_index_sequence<size_v<T>>{});
  }

  //==================================================================================================================
  //! @ingroup queries
  //! @brief Checks if a product type contains no fields based on any of the selected identifiers
  //!
  //! @param t the product type to inspect.
  //! @param ids Identifiers to check
  //! @return `true` if the current product_type contains no field based on any of the `ids`, and `false` otherwise.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/contains_none.cpp
  //! @include doc/record/algo/contains_none.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Is>
  KUMI_ABI constexpr bool contains_none(T&& t, Is const&... ids) noexcept
  {
    return !contains_any(KUMI_FWD(t), ids...);
  }
}
