//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/concepts.hpp>
#include <kumi/detail/str.hpp>
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

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if parameter pack containes a kumi::field_capture.
  //================================================================================================
  template<typename... Ts>
  concept has_named_fields = ( ... || is_field_capture_v<Ts> );

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if parameter pack contains only kumi::field_captures.
  //================================================================================================
  template<typename... Ts>
  concept is_fully_named = ( ... && is_field_capture_v<Ts> );

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique types.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_typed = ( !has_named_fields<Ts...> ) && all_uniques_v<_::box<Ts>...>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique kumi::field_capture names.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_named = ( has_named_fields<Ts...> ) && all_unique_names_v<_::box<Ts>...>;

  namespace _
  {
    template<auto Name, typename... Ts>
    requires( uniquely_named<Ts...> )
    constexpr decltype(auto) get_name_index() noexcept
    {
      return []<std::size_t... N>(std::index_sequence<N...>)
      {
        bool checks[] = {( []()
        {
          if constexpr( is_field_capture_v<Ts> ) return Name == Ts::name;
          else return false;
        }
        ())...};

        for(std::size_t i=0;i<sizeof...(Ts);++i) 
          if(checks[i]) return i;

        return sizeof...(Ts); 
      }( std::index_sequence_for<Ts...>{} );
    };

    template<typename T, typename... Ts>
    requires ( uniquely_typed<Ts...> )
    constexpr decltype(auto) get_type_index() noexcept
    {
      return []<std::size_t... N>( std::index_sequence<N...> )
      {
        bool checks[] = {( []()
        {
          if constexpr( std::is_same_v<T, Ts> ) return true;
          else return false;
        }
        ())...};
        
        for(std::size_t i=0;i<sizeof...(Ts);++i) 
          if(checks[i]) return i;
            
        return sizeof...(Ts); 
      }( std::index_sequence_for<Ts...>{} );
    }
  }

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a kumi::field_capture with name Name is present in a parameter pack.
  //================================================================================================
  template<auto Name, typename... Ts>
  concept contains_field = (_::get_name_index<Name, Ts...>() < sizeof...(Ts));

  namespace _
  {

    template<typename T, typename U> struct has_same_field_names;
    template<typename T, typename U> struct check_named_equality;

    template<template<class...> class Box, typename... T, typename...U>
    struct has_same_field_names<Box<T...>, Box<U...>>
    {
      static constexpr bool value = ( []()
      {
        using T_field = std::remove_cvref_t<T>;
        using U_field = std::remove_cvref_t<get_field_by_name_t<T_field, U...>>;
        return !std::is_same_v<U_field, kumi::unit>;
      }() && ...);
    };

    template<typename T, typename U>
    inline constexpr bool has_same_field_names_v = has_same_field_names<T, U>::value;

    template<template<class...> class Box, typename... T, typename... U>
    struct check_named_equality<Box<T...>, Box<U...>>
    {
      static constexpr bool value = ( []()
      {
        using T_field = std::remove_cvref_t<T>;
        using U_field = std::remove_cvref_t<get_field_by_name_t<T_field, U...>>;
        return _::comparable<unwrap_field_capture_t<T_field>, unwrap_field_capture_t<U_field>>;
      }() && ...);
    };

    template<typename T, typename U>
    inline constexpr bool check_named_equality_v = check_named_equality<T,U>::value;
  }

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if two types have matching named fields
  //!
  //! A type `T` models `kumi::equally_named<T,U>` if it is a product type with the same number of 
  //! members as `U`, and each of its fields has a corresponding field in `U` with the same name
  //================================================================================================
  template<typename T, typename U>
  concept equally_named = (size_v<T> == size_v<U>) && _::has_same_field_names_v<T,U>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if two product types are comparable by matching name 
  //!
  //! A type `T` models `kumi::named_equality_comparable<T,U>` if it's a product_type that satisfies 
  //! kumi::equally_named<T,U> and if each of its fields satisfies kumi::equality_comparable with
  //! the corresponding field in `U` 
  //================================================================================================
  template<typename T, typename U>
  concept named_equality_comparable = equally_named<T,U> && _::check_named_equality_v<T,U>;

  // Forward declaration
  template<typename... Ts> 
  requires ( is_fully_named<Ts...> && uniquely_named<Ts...> ) struct record;
}
