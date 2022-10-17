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
  //! @ingroup tuple
  //! @brief Concept specifying a type is non-empty standard tuple-like type.
  //================================================================================================
  template<typename T> concept non_empty_tuple = requires( T const &t )
  {
    typename std::tuple_element<0,std::remove_cvref_t<T>>::type;
    typename std::tuple_size<std::remove_cvref_t<T>>::type;
  };

  //================================================================================================
  //! @ingroup tuple
  //! @brief Concept specifying a type is an empty standard tuple-like type.
  //================================================================================================
  template<typename T> concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

  //================================================================================================
  //! @ingroup tuple
  //! @brief Concept specifying a type is a standard tuple-like type.
  //================================================================================================
  template<typename T> concept std_tuple_compatible = empty_tuple<T> || non_empty_tuple<T>;

  //================================================================================================
  //! @ingroup tuple
  //! @brief Concept specifying a type follows the Product Type semantic
  //!
  //! A type `T` models `kumi::product_type` if it opts in for the Product Type semantic and
  //! provides supports for structured bindings.
  //================================================================================================
  template<typename T>
  concept product_type = std_tuple_compatible<T> && is_product_type<std::remove_cvref_t<T>>::value;

  //================================================================================================
  //! @ingroup tuple
  //! @brief Concept specifying a type follows the Product Type semantic and has a known size
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! exactly `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type = product_type<T> && (size<T>::value == N);

  //================================================================================================
  //! @ingroup tuple
  //! @brief Concept specifying a type follows the Product Type semantic and has a size lower bound
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! at least `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type_or_more = product_type<T> && (size<T>::value >= N);

  namespace detail
  {
    template<typename T, typename U> constexpr auto check_equality()
    {
      return detail::comparable<T,U>;
    }

    template<product_type T, product_type U>
    constexpr auto check_equality()
    {
      return []<std::size_t...I>(std::index_sequence<I...>)
      {
        return (check_equality<member_t<I,T>,member_t<I,U>>() && ...);
      }(std::make_index_sequence<size<T>::value>{});
    }
  }

  template<typename T, typename U>
  concept equality_comparable = detail::check_equality<T,U>();
}
