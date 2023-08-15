//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/concepts.hpp>
#include <concepts>
#include <cstddef>
#include <type_traits>
#include <utility>

namespace kumi
{
  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type is a standard tuple-like type.
  //================================================================================================
  template<typename T>
  concept std_tuple_compatible = _::empty_tuple<T> || _::non_empty_tuple<T>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic
  //!
  //! A type `T` models `kumi::product_type` if it opts in for the Product Type semantic and
  //! provides supports for structured bindings.
  //================================================================================================
  template<typename T>
  concept product_type = std_tuple_compatible<T> && is_product_type<std::remove_cvref_t<T>>::value;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and has a known size
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! exactly `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type = product_type<T> && (size<T>::value == N);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and has a size lower bound
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! at least `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type_or_more = product_type<T> && (size<T>::value >= N);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and is non-empty
  //!
  //! A type `T` models `kumi::non_empty_product_type ` if it models `kumi::product_type` and has
  //! at least 1 element.
  //================================================================================================
  template<typename T>
  concept non_empty_product_type = product_type<T> && (size<T>::value != 0);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying is Product Type which types are all the same
  //!
  //! A type `T` models `kumi::homogenous_product_type` if it models `kumi::product_type` and
  //! contains member of a single, unique type.
  //================================================================================================
  template<typename T>
  concept homogeneous_product_type = product_type<T> && is_homogeneous_v<std::remove_cvref_t<T>>;

  namespace _
  {
    template<typename T, typename U>
    constexpr auto check_equality()
    {
      return []<std::size_t...I>(std::index_sequence<I...>)
      {
        return (_::comparable<member_t<I,T>,member_t<I,U>> && ...);
      }(std::make_index_sequence<size<T>::value>{});
    }
  }

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a type is comparable for each of its components
  //!
  //! A type `T` models `kumi::equality_comparable<T,U>` if it is a non-product type which satisfies
  //! `std::equality_comparable_with<T,U>` or if it's a product type where each of its elements
  //! satisfies kumi::equality_comparable for all their respective elements.
  //================================================================================================
  template<typename T, typename U>
  concept equality_comparable = (size_v<T> == size_v<U>) && _::check_equality<T,U>();
}
