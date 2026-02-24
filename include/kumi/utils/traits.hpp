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
    //==============================================================================================
    // Helper concepts for tuple detection
    //==============================================================================================
    // Concept specifying a type is non-empty standard tuple-like type.
    template<typename T>
    concept non_empty_tuple = requires(T const& t) {
      typename std::tuple_element<0, std::remove_cvref_t<T>>::type;
      typename std::tuple_size<std::remove_cvref_t<T>>::type;
    };

    // Concept specifying a type is an empty standard tuple-like type.
    template<typename T>
    concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type is a standard tuple-like type.
    //! @note Exposition only
    //================================================================================================
    template<typename T>
    concept std_tuple_compatible = _::empty_tuple<T> || _::non_empty_tuple<T>;

    //==============================================================================================
    // Helper concepts for container detection
    //==============================================================================================
    // Concept specifying a type is standard container-like type.
    template<typename T>
    concept container_like = requires(T const& t) {
      typename T::value_type;
      typename T::size_type;

      { t.size() } -> kumi::convertible_to<std::size_t>;
      { t.begin() };
      { t.end() };
      { t.data() };
    };
  }

  //================================================================================================
  //! @ingroup traits
  //! @brief  Detects if a type follows the tuple protocol.
  //!
  //! To be treated like a product_type, a user defined type must follow the tuple protocol defined
  //! in the standard.
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto is_product_type_v = is_product_type<T>::value;
  //! @endcode
  //! ## Example:
  //! @include doc/tuple/api/adapt.cpp
  //==============================================================================================
  template<typename T> struct is_product_type : std::false_type
  {
  };

  template<typename T> inline constexpr auto is_product_type_v = is_product_type<T>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief Opt-in traits for types behaving like a kumi::product_type
  //!
  //! To be treated like a record, an user defined type must supports structured bindings opt-in to
  //! kumi::record_type Semantic as well as kumi::product_type Semantic.
  //!
  //! This can be done in two ways:
  //!   - exposing an internal `is_record_type` type that evaluates to `void`
  //!   - specializing the `kumi::is_record_type` traits so it exposes a static constant member
  //!     `value` that evaluates to `true`
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto is_record_type_v = is_record_type<T>::value;
  //! @endcode
  //! ## Example:
  //! @include doc/record/api/adapt.cpp
  //==============================================================================================
  template<typename T, typename Enable = void> struct is_record_type : std::false_type
  {
  };

  template<typename T> struct is_record_type<T, typename T::is_record_type> : std::true_type
  {
  };

  template<typename T> inline constexpr auto is_record_type_v = is_record_type<T>::value;

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
  template<typename T> struct size : std::tuple_size<std::remove_cvref_t<T>>
  {
  };

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
  template<std::size_t I, typename T> struct element : std::tuple_element<I, std::remove_cvref_t<T>>
  {
  };

  template<std::size_t I, typename T> using element_t = typename element<I, T>::type;

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
    using type = decltype(get<I>(std::declval<T&&>()));
  };

  template<std::size_t I, typename T> using member_t = typename member<I, T>::type;
}

namespace kumi
{
  //================================================================================================
  //! @ingroup traits
  //! @brief Traits detecting types behaving like a kumi::static_container.
  //!
  //! To be treated like a static_container, a user defined type must expose a type and a
  //! statically know size encoded in the type. It shall also provide general container utilities.
  //!
  //! @note The type shall be templated on the type and the size to be picked up.
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto is_static_container = is_static_container<T>::value;
  //! @endcode
  //! ## Example:
  //==============================================================================================
  template<typename T> struct is_static_container : std::false_type
  {
  };

  template<template<class, std::size_t> typename Container, typename T, std::size_t N>
  requires _::container_like<Container<T, N>> && (N != static_cast<std::size_t>(-1))
  struct is_static_container<Container<T, N>> : std::true_type
  {
    using value_type = T;
    using size = std::integral_constant<std::size_t, N>;
  };

  template<typename T> inline constexpr auto is_static_container_v = is_static_container<T>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief Returns the number of elements of a kumi::static_container
  //!
  //! @tparam T kumi::static_container to inspect
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto container_size_v = container_size<T>::value;
  //! @endcode
  //================================================================================================
  template<typename T> struct container_size : is_static_container<std::remove_cvref_t<T>>::size
  {
  };

  template<typename T> inline constexpr auto container_size_v = container_size<T>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief Provides access to the type of the elements of a kumi::static_container.
  //!
  //! @tparam T kumi::static_container to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> using container_type_t = typename container_type<T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<typename T> struct container_type : is_static_container<std::remove_cvref_t<T>>::value_type
  {
  };

  template<typename T> using container_type_t = typename container_type<T>::type;
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
  template<typename T> struct is_homogeneous : std::false_type
  {
  };

  // Specific is_homogeneous overload
  template<typename T>
  requires(is_product_type_v<T>)
  struct is_homogeneous<T>
  {
    static consteval bool check()
    {
      if constexpr (requires { T::is_homogeneous; }) return T::is_homogeneous;
      else if constexpr (is_record_type_v<T>) return false;
      else if constexpr (is_static_container_v<T>) return true;
      else if constexpr (size_v<T> == 0) return false;
      else if constexpr (size_v<T> == 1) return true;
      else
        return []<std::size_t... I>(std::index_sequence<I...>) {
          return _::all_the_same<element_t<I, T>...>;
        }(std::make_index_sequence<size_v<T>>{});
    }

    static constexpr bool value = check();
  };

  template<typename T> inline constexpr auto is_homogeneous_v = is_homogeneous<T>::value;

  //================================================================================================
  //! @ingroup traits
  //! @brief Checks if a type can be used as a kumi::index_map
  //!
  //! @tparam T The type to inspect
  //!
  //! ## Helper value
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> inline constexpr bool is_index_map_v = is_index_map<T>::value;
  //! }
  //! @endcode
  //================================================================================================
  template<typename T> inline constexpr auto is_index_map_v = requires { T::is_index_map; };

  template<typename T> struct is_index_map : std::bool_constant<is_index_map_v<T>>
  {
  };

  //================================================================================================
  //! @ingroup traits
  //! @brief Computes the return type of a call to kumi::get on a kumi::tuple and unwrap the
  //!        field returned by kumi::get on a kumi::record
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T> using raw_member_t = typename raw_member<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct raw_member
  {
    using type = member_t<I, T>;
  };

  template<std::size_t I, typename T>
  requires(is_record_type<std::remove_cvref_t<T>>::value)
  struct raw_member<I, T>
  {
    using field_type = decltype(get<I>(std::declval<T&&>()));
    using type = decltype(std::declval<field_type&&>()(typename std::remove_cvref_t<field_type>::identifier_type{}));
  };

  template<std::size_t I, typename T> using raw_member_t = typename raw_member<I, T>::type;

  //================================================================================================
  //! @ingroup traits
  //! @brief Provides indexed access to the types of the elements of a kumi::product_type and
  //!                 unwraps the returned field for kumi::record_type.
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T>
  //!   using raw_element_t = typename raw_element_t<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct raw_element
  {
    using type = element_t<I, T>;
  };

  template<std::size_t I, typename T>
  requires(is_record_type<std::remove_cvref_t<T>>::value)
  struct raw_element<I, T>
  {
    using type = typename element_t<I, T>::type;
  };

  template<std::size_t I, typename T> using raw_element_t = typename raw_element<I, T>::type;

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
  template<typename Ints, typename... Ts> struct all_uniques;

  template<> struct all_uniques<std::index_sequence<>>
  {
    using type = std::true_type;
  };

  template<std::size_t... Ints, typename... Ts> struct all_uniques<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique<Ints, Ts>...
    {
    };

    template<typename... Us> static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);

    using type = decltype(is_set(std::type_identity<Ts>{}...));
  };

  template<typename... Ts> using all_uniques_t = typename all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts> inline constexpr auto all_uniques_v = all_uniques_t<Ts...>::value;

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
  template<typename Ints, typename... Ts> struct all_unique_names;

  template<> struct all_unique_names<std::index_sequence<>>
  {
    using type = std::true_type;
  };

  template<std::size_t... Ints, typename... Ts> struct all_unique_names<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique_name<Ints, Ts>...
    {
    };

    template<typename... Us> static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);

    using type = decltype(is_set(_::get_key<Ints, Ts>()...));
  };

  template<typename... Ts>
  using all_unique_names_t = typename all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts> inline constexpr auto all_unique_names_v = all_unique_names_t<Ts...>::value;

  // Forward declaration
  template<typename... Ts> struct tuple;
  template<typename... Ts> struct record;

  // A type with the tuple interface is automatically a product_type
  template<typename T>
  requires(_::std_tuple_compatible<T>)
  struct is_product_type<T> : std::true_type
  {
  };

  // A static container with tuple interface is indeed a product_type
  template<typename T>
  requires(is_static_container_v<T> && _::std_tuple_compatible<T>)
  struct is_product_type<T> : std::true_type
  {
  };

  // Internal helpers
  template<typename T> struct is_kumi_tuple : std::false_type
  {
  };

  template<typename... Ts> struct is_kumi_tuple<kumi::tuple<Ts...>> : std::true_type
  {
  };

  template<typename T> inline constexpr bool is_kumi_tuple_v = is_kumi_tuple<T>::value;

  template<typename T> struct is_kumi_record : std::false_type
  {
  };

  template<typename... Ts> struct is_kumi_record<kumi::record<Ts...>> : std::true_type
  {
  };

  template<typename T> inline constexpr bool is_kumi_record_v = is_kumi_record<T>::value;
}
