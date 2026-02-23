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
  //! @ingroup transforms
  //! @brief Apply the Callable object f on each product types' elements
  //!
  //! Applies the given function to all the product types passed as arguments and stores the result
  //! in another product type, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if product types' size are not equal or if
  //!       `f` can't be called on each product type's elements. All product type must either be
  //!       record types or product types but mixing is not supported.
  //!
  //! @param f      Callable function to apply
  //! @param t0     Product Type  to operate on
  //! @param others Product Types to operate on
  //! @return The product type of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_t = typename map<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/map.cpp
  //! @include doc/record/algo/map.cpp
  //================================================================================================
  template<concepts::product_type T, typename Function, concepts::sized_product_type<size_v<T>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto map(Function f, T&& t0, Ts&&... others)
  requires(concepts::compatible_product_types<T, Ts...> && _::supports_call<Function, T &&, Ts && ...>)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
    {
      auto const call = [&]<std::size_t N>(index_t<N>, auto&&... args) {
        if constexpr (concepts::record_type<T>)
        {
          constexpr auto field = name_of(as<element_t<N, T>>{});
          return capture_field<field>(invoke(f, get<field>(args)...));
        }
        else return invoke(f, get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<T>>());
    }
  }

  namespace result
  {
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts> struct map
    {
      using type = decltype(kumi::map(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_t = typename map<Function, T, Ts...>::type;
  }

  //================================================================================================
  //! @ingroup tuple_transforms
  //! @brief Apply the Callable object f on each tuples' elements and their indexes
  //!
  //! Applies the given function to all the tuples passed as arguments along with their indexes  and
  //! stores the result in another tuple, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if tuples' size are not equal or if `f`
  //!       can't be called on each tuple's elements and their indexes.
  //!
  //! @param f      Callable function to apply
  //! @param t0     Product type  to operate on
  //! @param others Product types to operate on
  //! @return The tuple of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map_index;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_index_t = typename map_index<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_index
  //!
  //! @see kumi::map
  //! @see kumi::map_field
  //!
  //! ## Example
  //! @include doc/tuple/algo/map_index.cpp
  //================================================================================================
  template<concepts::product_type T, typename Function, concepts::sized_product_type<size_v<T>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto map_index(Function f, T&& t0, Ts&&... others)
  requires(!concepts::record_type<T> && (!concepts::record_type<Ts> && ...))
  {
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
    {
      auto const call = [&]<std::size_t N>(index_t<N> idx, auto&&... args) {
        return invoke(f, idx, get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<T>>());
    }
  }

  namespace result
  {
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    struct map_index
    {
      using type = decltype(kumi::map_index(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_index_t = typename map_index<Function, T, Ts...>::type;
  }

  //================================================================================================
  //! @ingroup record_transforms
  //! @brief Apply the Callable object f on each records' fields and their associated names.
  //!
  //! Applies the given function to all the records passed as arguments along with their names and
  //! stores the result in another records, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if records' size are not equal or if `f`
  //!       can't be called on each record's fields and their names.
  //!
  //! @param f      Callable function to apply
  //! @param t0     Record  to operate on
  //! @param others Records to operate on
  //! @return The record of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map_field;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_field_t = typename map_field<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_field
  //!
  //! @see kumi::map
  //! @see kumi::map_index
  //!
  //! ## Example
  //! @include doc/record/algo/map_field.cpp
  //================================================================================================
  template<concepts::record_type T, typename Function, concepts::sized_product_type<size<T>::value>... Ts>
  requires(concepts::compatible_product_types<T, Ts...>)
  constexpr auto map_field(Function f, T&& t0, Ts&&... others)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
    {
      auto const call = [&]<std::size_t N>(index_t<N>, auto&&... args) {
        constexpr auto field = name_of(as<element_t<N, T>>{});
        return capture_field<field>(invoke(f, field.to_str(), (get<field>(args))...));
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size<T>::value>());
    }
  }

  namespace result
  {
    template<typename Function, concepts::record_type T, concepts::sized_product_type<size<T>::value>... Ts>
    struct map_field
    {
      using type = decltype(kumi::map_field(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function, concepts::record_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_field_t = typename map_field<Function, T, Ts...>::type;
  }
}
