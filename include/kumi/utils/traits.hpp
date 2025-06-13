//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

#include <kumi/detail/unique.hpp>
#include <kumi/detail/unit_type.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup traits
  //! @brief Opt-in traits for types behaving like a kumi::product_type
  //!
  //! To be treated like a tuple, an user defined type must supports structured bindings opt-in to
  //! kumi::product_type Semantic.
  //!
  //! This can be done in two ways:
  //!   - exposing an internal `is_product_type` type that evaluates to `void`
  //!   - specializing the `kumi::is_product_type` traits so it exposes a static constant member
  //!     `value` that evaluates to `true`
  //!
  //! ## Example:
  //! @include doc/adapt.cpp
  //==============================================================================================
  template<typename T, typename Enable = void> struct is_product_type : std::false_type {};
  template<typename T> struct is_product_type<T, typename T::is_product_type> : std::true_type {};

  //================================================================================================
  //! @ingroup traits
  //! @brief Computes the number of elements of a kumi::product_type
  //!
  //! @tparam T kumi::product_type to inspect
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto size_v = size<T>::value;
  //! @endcode
  //================================================================================================
  template<typename T> struct size : std::tuple_size<T>   {};
  template<typename T> struct size<T &>         : size<T> {};
  template<typename T> struct size<T &&>        : size<T> {};
  template<typename T> struct size<T const>     : size<T> {};
  template<typename T> struct size<T const &>   : size<T> {};
  template<typename T> struct size<T const &&>  : size<T> {};

  template<typename T> inline constexpr auto size_v = size<T>::value;
  //================================================================================================
  //! @ingroup traits
  //! @brief Provides indexed access to the types of the elements of a kumi::product_type.
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T> using element_t = typename element<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct element              : std::tuple_element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T&>        : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T&&>       : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T const&>  : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T const&&> : element<I,T> {};

  template<std::size_t I, typename T> using  element_t = typename element<I,T>::type;

  //================================================================================================
  //! @ingroup traits
  //! @brief Computes the return type of a call to kumi::get
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T> using member_t = typename member<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct member
  {
    using type = decltype( get<I>(std::declval<T&>()));
  };

  template<std::size_t I, typename T> using  member_t = typename member<I,T>::type;
}

namespace kumi
{
  //================================================================================================
  //! @ingroup traits
  //! @brief Detects if a given kwk::product_type instance is homogeneous
  //!
  //! @tparam T kumi::product_type to inspect
  //!
  //! ## Helper variable
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T>
  //!   inline constexpr is_homogeneous_v = is_homogeneous<I,T>::value;
  //! }
  //! @endcode
  //================================================================================================
  template<typename T>
  struct is_homogeneous;

  template<typename T>
  requires( requires { T::is_homogeneous; } )
  struct is_homogeneous<T> : std::bool_constant<T::is_homogeneous>
  {};

  template<typename T>
  inline constexpr auto is_homogeneous_v = is_homogeneous<T>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief Checks if a type is a kumi::field_capture 
  //!
  //! @tparam T The type to inspect
  //!
  //! ## Helper value
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> inline constexpr bool is_field_capture_v = requires { T::is_field_capture; };
  //! }
  //! @endcode
  //================================================================================================
  template<typename T>
  inline constexpr bool is_field_capture_v = requires { T::is_field_capture; };

  template<typename T>
  struct is_field_capture : std::bool_constant<is_field_capture_v<T>>
  {};

  //================================================================================================
  //! @ingroup traits
  //! @brief Returns the underlying type of a kumi::field_capture if it is the type of T
  //! return T otherwise
  //!
  //! @tparam T The type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using unwrap_field_capture_t = typename unwrap_field_capture<T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<typename T>
  struct unwrap_field_capture { using type = T; };
    
  template<typename T> 
  requires (requires { T::is_field_capture; })
  struct unwrap_field_capture<T> { using type = T::type; };
    
  template<typename T>
  using unwrap_field_capture_t = typename unwrap_field_capture<T>::type;

  //================================================================================================
  //! @ingroup traits
  //! @brief Returns the underlying name of a kumi::field_capture if T is a field_capture
  //!        returns the unit type otherwise 
  //!
  //! @tparam T The type to access
  //!
  //! ## Helper value
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using unwrap_name_v = unwrap_name<T>::value;
  //! }
  //! @endcode
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using unwrap_name_t = unwrap_name<T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<typename T>
  struct unwrap_name
  {
    using type = unit;
    static constexpr auto value = unit{}; 
  };

  template<typename T>
  requires ( requires { T::is_field_capture; } )
  struct unwrap_name<T>
  {
    using type = std::remove_cvref_t<decltype(T::name)>;
    static constexpr auto value = T::name;
  };

  template<typename T>
  inline constexpr auto unwrap_name_v = unwrap_name<T>::value;
    
  template<typename T>
  using unwrap_name_t = typename unwrap_name<T>::type;

  //================================================================================================
  //! @ingroup traits
  //! @brief   Checks if a parameter pack only contains distinct types.
  //!
  //! @tparam Ints The Index of the types in the parameter pack
  //! @tparam Ts   The types to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> all_uniques_t 
  //!       = typename all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;
  //! }
  //! @endcode
  //!
  //! ## Helper value
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using all_uniques_v = all_uniques_t<Ts...>::value;
  //! }
  //! @endcode
  //================================================================================================
  template <typename Ints, typename... Ts>
  struct all_uniques;

  template <>
  struct all_uniques<std::index_sequence<>> { using type = std::true_type; };

  template <std::size_t... Ints, typename... Ts>
  struct all_uniques<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique<Ints, Ts>... {};

    template <typename... Us>
    static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);

    using type = decltype(is_set(Ts{}...));
  };

  template<typename... Ts>
  using all_uniques_t = typename all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts>
  inline constexpr auto all_uniques_v = all_uniques_t<Ts...>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief   Checks if a parameter pack only contains distinct kumi::field_member names. 
  //!          Evaluates to false if no type is a kumi::field_member.
  //!
  //! @tparam Ints The Index of the types in the parameter pack
  //! @tparam Ts The types to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> all_unique_names_t 
  //!       = typename all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;
  //! }
  //! @endcode
  //!
  //! ## Helper value
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using all_unique_names_v = all_unique_names_t<Ts...>::value;
  //! }
  //! @endcode
  //================================================================================================
  template <typename Ints, typename... Ts>
  struct all_unique_names;

  template <>
  struct all_unique_names<std::index_sequence<>> { using type = std::true_type; };

  template <std::size_t... Ints, typename... Ts>
  struct all_unique_names<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique_name<Ints, Ts>... {};

    template <typename... Us>
    static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);

    using type = decltype(is_set(Ts{}...));
  };

  template<typename... Ts>
  using all_unique_names_t = typename all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts>
  inline constexpr auto all_unique_names_v = all_unique_names_t<Ts...>::value;
   
  // Forward declaration
  template<typename... Ts> struct tuple;
}
