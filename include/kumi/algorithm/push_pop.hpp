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
  //! @ingroup  generators
  //! @brief    Constructs a product type by adding a value `v` at the beginning of `t`.
  //!
  //! @param t  Base product type
  //! @param v  Value to insert in front of `t`
  //! @return   A product type composed of `v` followed by all elements of `t` in order.
  //!
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename V> struct push_front;
  //!
  //!   template<product_type T, typename V>
  //!   using push_front_t = typename push_front<T,V>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::push_front
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/push_front.cpp
  //! ### Record:
  //! @include doc/record/algo/push_front.cpp
  //====================================================================================================================
  template<concepts::product_type T, typename V> [[nodiscard]] KUMI_ABI constexpr auto push_front(T&& t, V&& v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return builder<T>::make(KUMI_FWD(v), get<I>(KUMI_FWD(t))...);
    }(std::make_index_sequence<size_v<T>>());
  }

  //====================================================================================================================
  //! @ingroup  generators
  //! @brief    Remove the first (if any) element of `t`.
  //!
  //! @param t  Base product type
  //! @return   A product type composed of all elements of `t` except its first. Has no effect on empty product types.
  //!
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct pop_front;
  //!
  //!   template<product_type T>
  //!   using pop_front_t = typename pop_front<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::pop_front
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/pop_front.cpp
  //! ### Record:
  //! @include doc/record/algo/pop_front.cpp
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto pop_front(T&& t)
  {
    if constexpr (concepts::sized_product_type_or_more<T, 1>) return extract(KUMI_FWD(t), index<1>);
    else return builder<T>::make();
  }

  //====================================================================================================================
  //! @ingroup  generators
  //! @brief    Constructs a product type by adding a value `v` at the end of `t`.
  //!
  //! @param t  Base product type
  //! @param v  Value to insert in front of `t`
  //! @return   A product type composed of all elements of `t` in order followed by `v`.
  //!
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename V> struct push_back;
  //!
  //!   template<product_type T, typename V>
  //!   using push_back_t = typename push_back<T,V>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::push_back
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/push_back.cpp
  //! ### Record:
  //! @include doc/record/algo/push_back.cpp
  //====================================================================================================================
  template<concepts::product_type T, typename V> [[nodiscard]] KUMI_ABI constexpr auto push_back(T&& t, V&& v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return builder<T>::make(get<I>(KUMI_FWD(t))..., KUMI_FWD(v));
    }(std::make_index_sequence<size_v<T>>());
  }

  //====================================================================================================================
  //! @ingroup  generators
  //! @brief    Remove the last (if any) element of a kumi::product_type.
  //!
  //! @param t  Base product type
  //! @return   A product type composed of all elements of `t` except its last. Has no effect on empty product types.
  //!
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct pop_back;
  //!
  //!   template<product_type T>
  //!   using pop_back_t = typename pop_back<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::pop_back
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/pop_back.cpp
  //! ### Record:
  //! @include doc/record/algo/pop_back.cpp
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto pop_back(T&& t)
  {
    if constexpr (concepts::sized_product_type_or_more<T, 1>)
      return extract(KUMI_FWD(t), index<0>, index<size_v<T> - 1>);
    else return builder<T>::make();
  }

  namespace result
  {
    template<concepts::product_type T, typename V> struct push_front
    {
      using type = decltype(kumi::push_front(std::declval<T>(), std::declval<V>()));
    };

    template<concepts::product_type T> struct pop_front
    {
      using type = decltype(kumi::pop_front(std::declval<T>()));
    };

    template<concepts::product_type T, typename V> struct push_back
    {
      using type = decltype(kumi::push_back(std::declval<T>(), std::declval<V>()));
    };

    template<concepts::product_type T> struct pop_back
    {
      using type = decltype(kumi::pop_back(std::declval<T>()));
    };

    template<concepts::product_type T, typename V> using push_front_t = typename push_front<T, V>::type;

    template<concepts::product_type T> using pop_front_t = typename pop_front<T>::type;

    template<concepts::product_type T, typename V> using push_back_t = typename push_back<T, V>::type;

    template<concepts::product_type T> using pop_back_t = typename pop_back<T>::type;
  }
}
