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
  namespace _
  {
    //==================================================================================================================
    // Helper concepts for tuple detection
    //==================================================================================================================
    // Concept specifying a type is non-empty standard tuple-like type.
    template<typename T>
    concept non_empty_tuple = requires {
      typename std::tuple_element<0, std::remove_cvref_t<T>>::type;
      typename std::tuple_size<std::remove_cvref_t<T>>::type;
    };

    // Concept specifying a type is an empty standard tuple-like type.
    template<typename T>
    concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

    // Concept specifying a type is a standard tuple-like type.
    template<typename T>
    concept std_tuple_compatible = kumi::_::empty_tuple<T> || kumi::_::non_empty_tuple<T>;

    //==================================================================================================================
    // Helper concepts for container detection
    //==================================================================================================================
    // Concept specifying a type is standard container-like type.
    template<typename T>
    concept container_like = requires(T const& t) {
      typename T::value_type;
      typename T::size_type;

      { t.size() } -> std::convertible_to<std::size_t>;
      { t.begin() };
      { t.end() };
    };

    /// Concept for container types providing access to a contiguous block of data
    template<typename T>
    concept contiguous_container_like = kumi::_::container_like<T> && requires(T const& t) {
      { t.data() };
    };
  }

  //====================================================================================================================
  /**
    @ingroup traits
    @brief  Detects if a type follows the tuple protocol.

    To be treated like a product_type, a user defined type must follow the tuple protocol defined
    in the standard.

    ## Helper value
    @code
      template<typename T> inline constexpr auto is_product_type_v = is_product_type<T>::value;
    @endcode
    ## Example:
    @include doc/tuple/api/adapt.cpp
  **/
  //====================================================================================================================
  template<typename T> inline constexpr bool is_product_type_v = false;

  template<typename T> struct is_product_type
  {
    static constexpr bool value = kumi::is_product_type_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Opt-in traits for types behaving like a kumi::record_type

    To be treated like a record, an user defined type must supports structured bindings as well as
    the kumi::product_type Semantic.

    This can be done in two ways:
      - exposing an internal `is_record_type` type that evaluates to `void`
      - specializing the `kumi::is_record_type_v` inline variable so that it evaluates to `true` for ones type

    ## Helper value
    @code
      template<typename T> inline constexpr auto is_record_type_v = is_record_type<T>::value;
    @endcode
    ## Example:
    @include doc/record/api/adapt.cpp
  **/
  //====================================================================================================================
  template<typename T>
  inline constexpr bool is_record_type_v = requires { typename T::is_record_type; } && kumi::is_product_type_v<T>;

  template<typename T> struct is_record_type
  {
    static constexpr bool value = kumi::is_record_type_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Computes the number of elements of a kumi::product_type

    @tparam T kumi::product_type to inspect

    ## Helper value
    @code
      template<typename T> inline constexpr auto size_v = size<T>::value;
    @endcode
  **/
  //====================================================================================================================
  template<typename T> inline constexpr std::size_t size_v = std::tuple_size_v<std::remove_cvref_t<T>>;

  template<typename T> struct size
  {
    static constexpr std::size_t value = kumi::size_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Provides indexed access to the types of the elements of a kumi::product_type.

    @tparam I Index of the type to retrieve
    @tparam T kumi::product_type to access

    ## Helper type
    @code
    namespace kumi
    {
      template<std::size_t I, typename T> using element_t = typename element<I,T>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<std::size_t I, typename T> using element_t = std::tuple_element_t<I, std::remove_cvref_t<T>>;

  template<std::size_t I, typename T> struct element
  {
    using type = kumi::element_t<I, T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Computes the return type of a call to kumi::get

    @tparam I Index of the type to retrieve
    @tparam T kumi::product_type to access

    ## Helper type
    @code
    namespace kumi
    {
      template<std::size_t I, typename T> using member_t = typename member<I,T>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<std::size_t I, typename T> using member_t = decltype(get<I>(std::declval<T&&>()));

  template<std::size_t I, typename T> struct member
  {
    using type = kumi::member_t<I, T>;
  };

}

namespace kumi
{
  //====================================================================================================================
  /**
    @ingroup traits
    @brief Traits detecting types behaving like a kumi::container.

    To be treated like a container, a user defined type must expose a type and a
    statically know size encoded in the type. It shall also provide general container utilities.

    @note The type shall be templated on the type and the size to be picked up.

    ## Helper value
    @code
      template<typename T> inline constexpr auto is_container = is_container<T>::value;
    @endcode

    ## Example:
    @include doc/infra/containers.cpp
  **/
  //====================================================================================================================
  template<typename T> inline constexpr bool is_container_v = false;

  template<typename T>
  requires kumi::_::container_like<T>
  inline constexpr bool is_container_v<T> = true;

  template<template<class, std::size_t> typename Container, typename T, std::size_t N>
  requires kumi::_::container_like<Container<T, N>> && (N != static_cast<std::size_t>(-1))
  inline constexpr bool is_container_v<Container<T, N>> = true;

  template<typename T, std::size_t N> inline constexpr bool is_container_v<T[N]> = true;

  template<typename T> struct is_container
  {
    static constexpr bool value = kumi::is_container_v<T>;
  };

  namespace
  {
    template<typename T> inline constexpr std::size_t container_size_ = kumi::_::invalid{};

    template<template<class, std::size_t> typename Container, typename T, std::size_t N>
    requires kumi::_::container_like<Container<T, N>> && (N != static_cast<std::size_t>(-1))
    inline constexpr std::size_t container_size_<Container<T, N>> = N;

    template<typename T, std::size_t N> inline constexpr std::size_t container_size_<T[N]> = N;
  }

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Returns the number of elements of a kumi::static_container

    @tparam T kumi::static_container to inspect

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T> inline constexpr auto container_size_v = container_size<T>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T> inline constexpr std::size_t container_size_v = kumi::container_size_<std::remove_cvref_t<T>>;

  template<typename T> struct container_size
  {
    static constexpr std::size_t value = kumi::container_size_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Provides access to the type of the elements of a kumi::conceots::container.

    @tparam T kumi::concepts::container to access

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T> using container_type_t = typename container_type<T>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T>
  requires kumi::_::container_like<T>
  typename T::value_type container_type_(T const&);

  template<template<class, std::size_t> typename Container, typename T, std::size_t N>
  requires kumi::_::container_like<Container<T, N>> && (N != static_cast<std::size_t>(-1))
  T container_type_(Container<T, N> const&);

  template<typename T, std::size_t N> T container_type_(T const (&)[N]);

  template<typename T> using container_type_t = decltype(kumi::container_type_(std::declval<T>()));

  template<typename T> struct container_type
  {
    using type = kumi::container_type_t<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Detects if a given kumi::container instance size is static

    @tparam T kumi::container to inspect

    ## Helper variable
    @code
    namespace kumi
    {
      template<typename T>
      inline constexpr has_static_size_v = has_static_size<I,T>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T> inline constexpr bool has_static_size_v = false;

  template<typename T>
  requires(kumi::_::contiguous_container_like<T>)
  inline constexpr bool has_static_size_v<T> =
    (!std::same_as<std::integral_constant<std::size_t, kumi::container_size_v<T>>, kumi::_::invalid>);

  template<typename T, std::size_t N> inline constexpr bool has_static_size_v<T[N]> = true;

  template<typename T> struct has_static_size
  {
    static constexpr bool value = kumi::has_static_size_v<T>;
  };
}

namespace kumi
{
  namespace
  {
    template<typename T, std::size_t... I> consteval bool homogeneous_(std::index_sequence<I...>)
    {
      if constexpr (!kumi::is_product_type_v<T>) return false;
      else if constexpr (requires { T::is_homogeneous; }) return T::is_homogeneous;
      else if constexpr (kumi::is_record_type_v<T>) return false;
      else if constexpr (kumi::is_container_v<T>) return true;
      else if constexpr (sizeof...(I) == 0) return false;
      else if constexpr (sizeof...(I) == 1) return true;
      else return kumi::_::all_the_same<kumi::element_t<I, T>...>;
    }
  }

  //====================================================================================================================
  /**
    @ingroup tuple_traits
    @brief Detects if a given kumi::product_type instance is homogeneous

    @tparam T kumi::product_type to inspect

    ## Helper variable
    @code
    namespace kumi
    {
      template<typename T>
      inline constexpr is_homogeneous_v = is_homogeneous<I,T>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T>
  inline constexpr bool is_homogeneous_v = kumi::homogeneous_<T>(std::make_index_sequence<kumi::size_v<T>>{});

  // template<typename T>
  // requires ( kumi::is_product_type_v<T> )
  // inline constexpr bool is_homogeneous_v<T> = );

  template<typename T> struct is_homogeneous
  {
    static constexpr bool value = kumi::is_homogeneous_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Checks if a type can be used as a kumi::projection_map

    @tparam T The type to inspect

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T> inline constexpr bool is_projection_map_v = is_projection_map<T>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T> inline constexpr bool is_projection_map_v = requires { T::is_projection_map; };

  // An index sequence is a one dimensional projection map
  template<std::size_t... I> inline constexpr bool is_projection_map_v<std::index_sequence<I...>> = true;

  template<typename T> struct is_projection_map
  {
    static constexpr bool value = kumi::is_projection_map_v<T>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief Computes the return type of a call to kumi::get on a kumi::tuple and unwrap the
           field returned by kumi::get on a kumi::record

    @tparam I Index of the type to retrieve
    @tparam T kumi::product_type to access

    ## Helper type
    @code
    namespace kumi
    {
      template<std::size_t I, typename T> using stored_member_t = typename stored_member<I,T>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<std::size_t I, typename T> struct stored_member
  {
    using type = kumi::member_t<I, T>;
  };

  template<std::size_t I, typename T>
  requires(kumi::is_record_type_v<std::remove_cvref_t<T>>)
  struct stored_member<I, T>
  {
    using field_type = decltype(get<I>(std::declval<T&&>()));
    using type = decltype(std::declval<field_type&&>()(typename std::remove_cvref_t<field_type>::identifier_type{}));
  };

  template<std::size_t I, typename T> using stored_member_t = typename kumi::stored_member<I, T>::type;

  //====================================================================================================================
  /**
    @ingroup record_traits
    @brief  Provides indexed access to the types of the elements of a product type and
            unwraps the returned `field` for record type.

    @note Is equivalent to element_t on product types that are not record types.

    @tparam I Index of the type to retrieve
    @tparam T Product type to access

    ## Helper type
    @code
    namespace kumi
    {
      template<std::size_t I, typename T>
      using stored_element_t = typename stored_element_t<I,T>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<std::size_t I, typename T> struct stored_element
  {
    using type = kumi::element_t<I, T>;
  };

  template<std::size_t I, typename T>
  requires(kumi::is_record_type<std::remove_cvref_t<T>>::value)
  struct stored_element<I, T>
  {
    using type = typename kumi::element_t<I, T>::type;
  };

  template<std::size_t I, typename T> using stored_element_t = typename kumi::stored_element<I, T>::type;

  //====================================================================================================================
  /**
    @ingroup traits

    @brief Checks if a type is an instance of a specific template.

    @tparam T The type to inspect
    @tparam U the target template

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename U> using is_instance_of_t = typename is_instance_of_t<T,U>::type;
    }
    @endcode

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T, typename U> inline constexpr bool is_instance_of_v<T,U>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T, typename U> struct is_instance_of : std::false_type
  {
  };

  template<template<typename...> class T, typename... Args1, typename... Args2>
  struct is_instance_of<T<Args1...>, T<Args2...>> : std::true_type
  {
  };

  template<template<auto...> class T, auto... Args1, auto... Args2>
  struct is_instance_of<T<Args1...>, T<Args2...>> : std::true_type
  {
  };

  template<typename T, typename U> using is_instance_of_t = typename kumi::is_instance_of<T, U>::type;

  template<typename T, typename U> inline constexpr bool is_instance_of_v = kumi::is_instance_of<T, U>::value;

  //====================================================================================================================
  /**
    @ingroup  traits
    @brief    Extracts the common product_type of a parameter pack.

    If all the types are record types then it returns an empty record type, otherwise returns an empty product type.
    As we are unable to properly compute the Least Restrictive Subtype of a pack this trait is specialized
    in the following way.

    - If all input types are the same product_type, provide a type alias corresponding to it.
    - If all input types are instance of the same template itself beeing a product_type, expose the template.
    - If all types are kumi::concepts::product_type, use kumi::tuple as the alias.
    - If all types are kumi::concepts::record_type, use kumi::record as the alias.

    @note It is used in algorithm taking multiple product types as input in order to determine the correct output type.

    @tparam Ts The product types to access

    ## Helper type
    @code
    namespace kumi
    {
      template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename... Ts> struct common_product_type;

  template<typename T, typename... Ts>
  requires((kumi::is_product_type_v<Ts> && ...) &&
           ((std::same_as<T, Ts> && ...) || (kumi::is_instance_of_v<T, Ts> && ...)))
  struct common_product_type<T, Ts...>
  {
    using type = std::remove_cvref_t<T>;
  };

  template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Checks if a parameter pack only contains distinct types.

    @tparam Ints The Index of the types in the parameter pack
    @tparam Ts   The types to access

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T> all_uniques_t
          = typename all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;
    }
    @endcode

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T> using all_uniques_v = all_uniques_t<Ts...>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename Ints, typename... Ts> struct all_uniques;

  template<> struct all_uniques<std::index_sequence<>>
  {
    using type = std::true_type;
  };

  template<std::size_t... Ints, typename... Ts> struct all_uniques<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : kumi::_::unique<Ints, Ts>...
    {
    };

    template<typename... Us>
    static consteval auto is_set(Us...)
      -> decltype(kumi::_::true_fn(static_cast<Us>(std::declval<all_uniques_inner>())...));
    static consteval std::false_type is_set(...);

    using type = decltype(is_set(std::type_identity<Ts>{}...));
  };

  template<typename... Ts>
  using all_uniques_t = typename kumi::all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts> inline constexpr auto all_uniques_v = kumi::all_uniques_t<Ts...>::value;

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Checks if a parameter pack only contains distinct kumi::field names.
             Evaluates to false if no type is a kumi::field.

    @tparam Ints The Index of the types in the parameter pack
    @tparam Ts The types to access

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T> all_unique_names_t
          = typename all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;
    }
    @endcode

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T> using all_unique_names_v = all_unique_names_t<Ts...>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename Ints, typename... Ts> struct all_unique_names;

  template<> struct all_unique_names<std::index_sequence<>>
  {
    using type = std::true_type;
  };

  template<std::size_t... Ints, typename... Ts> struct all_unique_names<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : kumi::_::unique_name<Ints, Ts>...
    {
    };

    template<typename... Us>
    static consteval auto is_set(Us...) -> decltype(kumi::_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static consteval std::false_type is_set(...);

    using type = decltype(is_set(kumi::_::get_key<Ints, Ts>()...));
  };

  template<typename... Ts>
  using all_unique_names_t = typename kumi::all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;

  template<typename... Ts> inline constexpr auto all_unique_names_v = kumi::all_unique_names_t<Ts...>::value;

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Checks if a two product types are equivalent.

    Two product types are considered equivalent in the following case : if the two product types are
    concepts::record_type they need to both have the same fields, potentially in a different order. If one of the two or
    both are simply product_types, they are considered equivalent if their size match.

    @tparam Seq The Index sequence sized on the size of the input product types
    @tparam T The reference product type to access
    @tparam U the product type to check

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename U> is_equivalent_t
          = typename is_equivalent<std::make_index_sequence<size_v<T>>, T, U>::type;
    }
    @endcode

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T, typename U> using is_equivalent_v = is_equivalent_t<T,U>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename Seq, typename T, typename U> struct is_equivalent : std::false_type
  {
  };

  template<std::size_t... Is, typename T, typename U>
  requires(kumi::is_product_type_v<T> && kumi::is_product_type_v<U> && kumi::size_v<T> == kumi::size_v<U>)
  struct is_equivalent<std::index_sequence<Is...>, T, U>
  {
    struct match : kumi::_::unique_name<Is, kumi::element_t<Is, U>>...
    {
    };

    template<typename... Key>
    requires(sizeof...(Is) != 0)
    static consteval auto is_present(Key...) -> decltype(kumi::_::true_fn(static_cast<Key>(std::declval<match>())...));
    static consteval std::false_type is_present(...);
    static consteval std::true_type is_present(...)
    requires(sizeof...(Is) == 0);

    using type = decltype(is_present(kumi::_::get_key<Is, kumi::element_t<Is, T>>()...));
  };

  template<typename T, typename U>
  using is_equivalent_t = typename kumi::is_equivalent<std::make_index_sequence<kumi::size_v<T>>, T, U>::type;

  template<typename T, typename U> inline constexpr bool is_equivalent_v = kumi::is_equivalent_t<T, U>::value;

  namespace
  {
    template<typename T, typename U, typename Seq> inline constexpr bool is_equality_comparable_ = false;

    template<typename T, typename U, std::size_t... I>
    requires(kumi::is_record_type_v<T> && kumi::is_record_type_v<U>)
    inline constexpr bool is_equality_comparable_<T, U, std::index_sequence<I...>>{
      (kumi::_::comparable<decltype(std::declval<kumi::_::fieldmap<kumi::element_t<I, T>...>>()(
                             std::declval<kumi::_::identifier_of_t<kumi::element_t<I, U>>>())),
                           kumi::_::type_of_t<kumi::element_t<I, U>>> &&
       ...)};

    template<typename T, typename U, std::size_t... I>
    inline constexpr bool is_equality_comparable_<T, U, std::index_sequence<I...>>{
      (kumi::_::comparable<kumi::element_t<I, T>, kumi::element_t<I, U>> && ...)};
  }

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Checks if a two product types are comparable for equality.

    Two product types are comparable for equality uf eacg field in T have a corresponding field in U with each of their
    underlying types being comparable (the == operator can be used betewen them).

    @tparam T The reference product type to access
    @tparam U the product type to check

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename U> is_equality_comparable_t
          = typename is_equality_comparable<T, U>::type;
    }
    @endcode

    ## Helper value
    @code
    namespace kumi
    {
      template<typename T, typename U> using is_equality_comparable_v = is_equivalent_t<T,U>::value;
    }
    @endcode
  **/
  //====================================================================================================================
  template<typename T, typename U> inline constexpr bool is_equality_comparable_v = false;

  template<typename T, typename U>
  requires(kumi::is_product_type_v<T> && kumi::is_product_type_v<U> && kumi::size_v<T> == kumi::size_v<U>)
  inline constexpr bool is_equality_comparable_v<T, U> =
    (kumi::size_v<T> == 0) || kumi::is_equality_comparable_<T, U, std::make_index_sequence<kumi::size_v<T>>>;

  template<typename T, typename U> struct is_equality_comparable
  {
    static constexpr bool value = kumi::is_equality_comparable_v<T, U>;
  };

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Unpacks a product type and applies its element types as arguments to a meta-function.

    ` apply_traits` takes a template meta-function (a template template parameter) and a product type. It expands the
      types contained within the product type and passes them as a parameter pack to the provided `Traits`.

    @tparam Traits  Meta-function to be applied.
    @tparam T       The product type whose elements will be unpacked.

    ## Helper type
    @code
    namespace kumi
    {
      template<template<typename...> typename Traits, typename Tuple>
      using apply_traits_t = typename apply_traits<Traits, Tuple>::type;
    }
    @endcode

    ## Example
    @code
    using my_tuple = kumi::tuple<int, float, char>;

    // Equivalent to std::common_type<int, float, char>::type
    using common = kumi::apply_traits_t<std::common_type, my_tuple>;
    @endcode
  **/
  //====================================================================================================================
  template<template<typename...> typename Traits, typename T, typename Seq = std::make_index_sequence<kumi::size_v<T>>>
  requires is_product_type_v<std::remove_cvref_t<T>>
  struct apply_traits;

  template<template<typename...> typename Traits, typename T, std::size_t... Is>
  requires is_product_type_v<std::remove_cvref_t<T>> && (requires { typename Traits<kumi::element_t<Is, T>...>::type; })
  struct apply_traits<Traits, T, std::index_sequence<Is...>>
  {
    using type = typename Traits<kumi::element_t<Is, T>...>::type;
  };

  template<template<typename...> typename Traits, typename T>
  requires kumi::is_product_type_v<std::remove_cvref_t<T>>
  using apply_traits_t = typename kumi::apply_traits<Traits, T>::type;

  //====================================================================================================================
  /**
    @ingroup traits
    @brief   Applies a unary meta-function to each element of a product type.

    `map_traits` transforms a product type by applying a given meta-function `Traits` to every element type
    individually. The result is a new product type containing the transformed types.

    @tparam Traits  Unary meta-function to apply to each element.
    @tparam T       The product type to transform.

    ## Helper type
    @code
    namespace kumi
    {
      template<template<typename...> typename Traits, typename T>
      using map_traits_t = typename map_traits<Traits, T>::type;
    }
    @endcode

    ## Example
    @code
    using my_tuple = kumi::tuple<int, double, char>;

    // Result: kumi::tuple<int*, double*, char*>
    using ptr_tuple = kumi::map_traits_t<std::add_pointer, my_tuple>;
    @endcode
  **/
  //====================================================================================================================
  template<template<typename...> typename Traits, typename T, typename Seq = std::make_index_sequence<kumi::size_v<T>>>
  requires kumi::is_product_type_v<std::remove_cvref_t<T>>
  struct map_traits;

  template<template<typename...> typename Traits, typename T, std::size_t... Is>
  requires kumi::is_product_type_v<std::remove_cvref_t<T>> &&
           (requires { typename Traits<kumi::element_t<Is, T>>::type; } && ...)
  struct map_traits<Traits, T, std::index_sequence<Is...>>
  {
    using type = kumi::builder_make_t<T, typename Traits<kumi::element_t<Is, T>>::type...>;
  };

  template<template<typename...> typename Traits, typename T>
  requires kumi::is_product_type_v<std::remove_cvref_t<T>>
  using map_traits_t = typename kumi::map_traits<Traits, T>::type;
}

namespace kumi
{
#ifndef KUMI_DOXYGEN_INVOKED
  // A type with the tuple interface is automatically a product_type
  template<typename T>
  requires(kumi::_::std_tuple_compatible<T>)
  inline constexpr bool is_product_type_v<T> = true;

  // A static container with tuple interface is indeed a product_type
  template<typename T>
  requires(kumi::is_container_v<T> && kumi::has_static_size_v<T> && kumi::_::std_tuple_compatible<T>)
  inline constexpr bool is_product_type_v<T> = true;

  template<typename T> inline constexpr bool is_kumi_tuple_v = false;
  template<typename... Ts> inline constexpr bool is_kumi_tuple_v<kumi::tuple<Ts...>> = true;

  template<typename T> struct is_kumi_tuple
  {
    static constexpr bool value = kumi::is_kumi_tuple_v<T>;
  };

  template<typename T> inline constexpr bool is_kumi_record_v = false;
  template<typename... Ts> inline constexpr bool is_kumi_record_v<kumi::record<Ts...>> = true;

  template<typename T> struct is_kumi_record
  {
    static constexpr bool value = kumi::is_kumi_record_v<T>;
  };

#endif
}
