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

  namespace _
  {
    template<typename T> struct box { using type = T; };
  }

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if parameter pack containes a kumi::field_capture.
  //================================================================================================
  template<typename... Ts>
  concept has_named_fields = ( ... || is_field_capture_v<Ts> );

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique types.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_typed = has_named_fields<Ts...> && all_uniques_v<_::box<Ts>...>;

  //================================================================================================
  //! @ingroup concepts
  //! @brief Concept specifying if a parameter pack only holds unique kumi::field_capture names.
  //================================================================================================
  template<typename... Ts>
  concept uniquely_named = !has_named_fields<Ts...> && all_unique_names_v<_::box<Ts>...>;

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

}
