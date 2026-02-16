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
  namespace _
  {
    template<typename T, typename... Ts>
    constexpr bool contains = ((concepts::field<T> && std::invocable<T, Ts>) || ...);
  }

  //==================================================================================================================
  //! @ingroup algorithm
  //! @brief Checks if product type contains a given identifier
  //!
  //! @param t the product type to inspect.
  //! @param k Keyword to check
  //! @return `true` if current product_type contains a field based on the `kw`, and `false` otherwise.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/contains.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier K>
  KUMI_ABI constexpr bool contains([[maybe_unused]] T&& t, [[maybe_unused]] K const& k) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (concepts::record_type<T>)
      return []<std::size_t... I> {
        return _::can_get_field_by_value<std::remove_cvref_t<K>, element_t<I, T>...>;
      }(std::make_index_sequence<size_v<T>>{});
    else
      return []<std::size_t... I>(std::index_sequence<I...>) {
        if constexpr (((concepts::field<element_t<I, T>> && std::invocable<element_t<I, T>, std::remove_cvref_t<K>>) ||
                       ...))
          return true;
        else return false;
      }(std::make_index_sequence<size_v<T>>{});
  }

  //==================================================================================================================
  //! @ingroup algorithm
  //! @brief Checks if product type contains at least one of many identifier
  //!
  //! @param t the product type to inspect.
  //! @param ks Keywords to check
  //! @return `true` if current product_type contains a field based on the `kw`, and `false` otherwise.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/contains_any.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_any(T&& t, Ks const&... ks) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Ks) == 0) return false;
    else return (contains(KUMI_FWD(t), ks) || ...);
  }

  //==================================================================================================================
  //! @ingroup algorithm
  //! @brief Checks if product type contains fields based only on selected identifiers
  //!
  //! @param t the product type to inspect.
  //! @param ks Keywords to check
  //! @return `true` if current product_type contains a field based on any of the `ks`, and `false` otherwise.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/contains_only.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_only([[maybe_unused]] T&& t, [[maybe_unused]] Ks const&... ks) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Ks) == 0) return false;
    else if constexpr (sizeof...(Ks) < size_v<T>) return false;
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::contains<element_t<I, T>, Ks...> && ...);
      }(std::make_index_sequence<size_v<T>>{});
  }

  //==================================================================================================================
  //! @ingroup algorithm
  //! @brief Checks if product type contains no fields based on any of the selected identifiers
  //!
  //! @param t the product type to inspect.
  //! @param ks Keywords to check
  //! @return `true` if current product_type contains no field based on any of the `ks`, and `false` otherwise.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/contains_none.cpp
  //==================================================================================================================
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_none(T&& t, Ks const&... ks) noexcept
  {
    return !contains_any(KUMI_FWD(t), ks...);
  }
}
