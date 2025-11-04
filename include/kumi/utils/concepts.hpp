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
  //! @brief Concept specifying a type follows the Record Type semantic
  //!
  //! A type `T` models `kumi::record_type` if it opts in for the Record Type semantic. 
  //! A `kumi::record_type` also models `kumi::product_type`
  //================================================================================================
  template<typename T>
  concept record_type = product_type<T> && is_record_type<std::remove_cvref_t<T>>::value;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and has a known size
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! exactly `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type = product_type<T> && (size_v<std::remove_cvref_t<T>> == N);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and has a size lower bound
  //!
  //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
  //! at least `N` elements.
  //================================================================================================
  template<typename T, std::size_t N>
  concept sized_product_type_or_more = product_type<T> && (size_v<std::remove_cvref_t<T>> >= N);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and is empty
  //!
  //! A type `T` models `kumi::empty_product_type ` if it models `kumi::product_type` and has 
  //! no elements.
  //================================================================================================
  template<typename T>
  concept empty_product_type = product_type<T> && (size_v<std::remove_cvref_t<T>> == 0);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying a type follows the Product Type semantic and is non-empty
  //!
  //! A type `T` models `kumi::non_empty_product_type ` if it models `kumi::product_type` and has
  //! at least 1 element.
  //================================================================================================
  template<typename T>
  concept non_empty_product_type = product_type<T> && (size_v<std::remove_cvref_t<T>> != 0);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a type can be used as sequence of indexes in algorithms 
  //!
  //! A type `T` models `kumi::index_map` if it models `kumi::product_type` and
  //! contains members which are themselves either integral types or others `index_map` 
  //================================================================================================
  template<typename T>
  concept index_map = product_type<T> && is_index_map_v<std::remove_cvref_t<T>>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a type is suitable as an index 
  //!
  //! A type `T` models `kumi::indexer` if it models `kumi::index_map` or `std::is_integral` 
  //================================================================================================
  template<typename T>
  concept indexer = index_map<T> || std::integral<std::remove_cvref_t<T>>;
                   

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
    KUMI_ABI constexpr auto check_equality()
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
  //! A type `T` models `kumi::equality_comparable<T,U>`if it's a product type where each of its 
  //! elements satisfies kumi::equality_comparable for all their respective elements.
  //================================================================================================
  template<typename T, typename U>
  concept equality_comparable = ( size_v<std::remove_cvref_t<T>> == size_v<std::remove_cvref_t<U>>) 
                                && _::check_equality<std::remove_cvref_t<T>,std::remove_cvref_t<U>>();

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if parameter pack containes a kumi::field_capture.
  //================================================================================================
  template<typename... Ts>
  concept has_named_fields = ( ... || is_field_capture_v<std::remove_cvref_t<Ts>> );

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if parameter pack contains only kumi::field_captures.
  //================================================================================================
  template<typename... Ts>
  concept is_fully_named = ( ... && is_field_capture_v<std::remove_cvref_t<Ts>> );

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique types.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_typed = ( !has_named_fields<Ts...> ) 
                        && all_uniques_v<std::remove_cvref_t<Ts>...>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique kumi::field_capture names.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_named = ( has_named_fields<Ts...> )
                        && all_unique_names_v<std::remove_cvref_t<Ts>...>;

   //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds kumi::field_captures each of their   
  //!        each of their names are unique!
  //!
  //! @note  If there are no element in the parameter pack the concept returns true
  //================================================================================================
  template<typename... Ts>
  concept entirely_uniquely_named = (sizeof...(Ts)==0) 
  || (is_fully_named<Ts...> && uniquely_named<Ts...>);

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a Type is present in a parameter pack.
  //================================================================================================
  template<typename T, typename... Ts>
  concept contains_type = (!std::is_same_v<_::get_field_by_type_t<T, Ts...>, kumi::unit>);

  // MSVC workaround for get<>
  // MSVC doesnt SFINAE properly based on NTTP types before requires evaluation
  // so we need this weird consteval mechanism for it to pickt the correct version.
  namespace _
  {
    template<auto Name, typename... Ts> consteval auto contains_field_impl()
    {
      if constexpr( !indexer<std::remove_cvref_t<decltype(Name)>> )
        return !std::is_same_v<_::get_field_by_name_t<field_capture<Name, unit>, Ts...>, kumi::unit>;
      else return false;
    };
  }
  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a kumi::field_capture with name Name is present in a parameter pack.
  //================================================================================================
  template<auto Name, typename... Ts>
  concept contains_field = _::contains_field_impl<Name, Ts...>(); 

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

    template<template<class...> class Box, typename... T, typename... U>
    struct check_named_equality<Box<T...>, Box<U...>>
    {
      static constexpr bool value = ( []()
      {
        using T_field = std::remove_cvref_t<T>;
        using U_field = std::remove_cvref_t<get_field_by_name_t<T_field, U...>>;
        return _::comparable<typename T_field::type, typename U_field::type>;
      }() && ...);
    };

    template<typename T, typename U>
    inline constexpr bool has_same_field_names_v = has_same_field_names<T, U>::value;

    template<typename T, typename U>
    inline constexpr bool check_named_equality_v = check_named_equality<T,U>::value;
  }

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if two types have matching named fields
  //!
  //! A type `T` models `kumi::equivalent<T,U>` if it is a product type with the same number of 
  //! members as `U`, and each of its fields has a corresponding field in `U` with the same name
  //================================================================================================
  template<typename T, typename U>
  concept equivalent = ( size_v<std::remove_cvref_t<T>> == size_v<std::remove_cvref_t<U>>) 
                       && _::has_same_field_names_v<std::remove_cvref_t<T>,std::remove_cvref_t<U>>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if two product types are comparable by matching name 
  //!
  //! A type `T` models `kumi::named_equality_comparable<T,U>` if it's a product_type that satisfies 
  //! kumi::equivalent<T,U> and if each of its fields satisfies kumi::equality_comparable with
  //! the corresponding field in `U` 
  //================================================================================================
  template<typename T, typename U>
  concept named_equality_comparable = equivalent<T,U> 
  && _::check_named_equality_v<std::remove_cvref_t<T>,std::remove_cvref_t<U>>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if two product types are comparable by matching name
  //!
  //! A type `T` models `kumi::named_equality_comparable<T,U>` if it's a product_type that satisfies
  //! kumi::equivalent<T,U> and if each of its fields satisfies kumi::equality_comparable with
  //! the corresponding field in `U`
  //================================================================================================
  template<typename T, typename... Us>
  concept compatible_product_types = (product_type<T> && ( product_type<Us> && ...))  &&
    ((!record_type<T> && (!record_type<Us> && ...))
    || (record_type<T> && (record_type<Us> && ...) 
    && (equivalent<std::remove_cvref_t<T>, std::remove_cvref_t<Us>> && ...))
  );
}
