//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <span>

namespace kumi
{
  namespace _
  {
    // Workaround as span has no tuple_element/tuple_size defined even if it's static
    // as opposed to ranges::subrange for some reason
    template<typename T> struct is_static_span : std::false_type{}; 

    template<typename T, std::size_t N>
    struct is_static_span<std::span<T,N>> : std::bool_constant<(N != std::dynamic_extent)>{};

    template<typename T> concept static_span = is_static_span<std::remove_cvref_t<T>>::value; 
  }
  
  namespace _
  {
    template< product_type Tuple
            , typename IndexSequence
            , template<typename...> class Meta = std::type_identity
            >
    struct as_tuple;

    template< product_type Tuple
            , std::size_t... I
            >
    struct as_tuple<Tuple, std::index_sequence<I...>>
    {
      using type = kumi::tuple< element_t<I,Tuple>... >;
    };

    template< product_type Tuple
            , std::size_t... I
            , template<typename...> class Meta
            >
    struct as_tuple<Tuple, std::index_sequence<I...>, Meta>
    {
      using type = kumi::tuple< typename Meta<element_t<I,Tuple>>::type... >;
    };
  }

  // Specific is_homogeneous overload
  template<typename T>
  requires( !requires { T::is_homogeneous; } )
  struct is_homogeneous<T> : is_homogeneous<typename _::as_tuple<T,std::make_index_sequence<size_v<T>>>::type>
  {};

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a kumi::tuple to an instance of an arbitrary type
  //!
  //! Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.
  //!
  //! @tparam Type Type to generate
  //! @param  t    kumi::tuple to convert
  //! @return An instance of `Type` constructed from each element of `t` in order.
  //!
  //! ## Example
  //! @include doc/from_tuple.cpp
  //================================================================================================
  template<typename Type, typename... Ts>
  requires(!product_type<Type> && _::implicit_constructible<Type, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto from_tuple(tuple<Ts...> const &t)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) { return Type {get<I>(t)...}; }
    (std::make_index_sequence<sizeof...(Ts)>());
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a kumi::record to an instance of a type that models kumi::record_type
  //!
  //! Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.
  //!
  //! @tparam Type Type to generate
  //! @param  r    kumi::record to convert
  //! @return An instance of `Type` constructed from each element of `t` in order.
  //!
  //! ## Example
  //! @include doc/record/from_record.cpp
  //================================================================================================
  template<record_type Type, typename... Ts>
  requires ( equivalent<Type, record<Ts...>> )
  [[nodiscard]] KUMI_ABI constexpr auto from_record(record<Ts...> const &r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) 
    { 
      return Type{ get<name_of(as<element_t<I,Type>>{})>(r)... };
    }(std::make_index_sequence<size_v<Type>>());
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a kumi::product_type to an instance kumi::tuple
  //!
  //! Constructs an instance kumi::tuple from the elements of the kumi::product_type parameters
  //!
  //! @param  t    kumi::product_type to convert
  //! @return An instance of kumi::tuple constructed from each elements of `t` in order.
  //!
  //! @note An overload is provided for static std::span. 
  //!
  //! ## Example
  //! @include doc/to_tuple.cpp
  //================================================================================================
  template<product_type Type>
  [[nodiscard]] KUMI_ABI constexpr auto to_tuple(Type && t)
  {
    return apply([](auto &&...elems) { return tuple{elems...}; }, KUMI_FWD(t));
  }

  template<_::static_span S>
  [[nodiscard]] KUMI_ABI constexpr auto to_tuple( S && s )
  {
    constexpr auto N = std::remove_cvref_t<S>::extent;
    if constexpr ( N == 0 ) return tuple{};
    else return [&]<std::size_t...I>( std::index_sequence<I...> )
    {
      return tuple{ KUMI_FWD(s)[I]... };
    }(std::make_index_sequence<N>{});
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a kumi::record_type to an instance kumi::record
  //!
  //! Constructs an instance kumi::record from the elements of the kumi::product_type parameters
  //!
  //! @param  r    kumi::product_type to convert
  //! @return An instance of kumi::record constructed from each elements of `t` in order.
  //!
  //! ## Example
  //! @include doc/record/to_record.cpp
  //================================================================================================
  template<record_type Type>
  [[nodiscard]] KUMI_ABI constexpr auto to_record(Type && r)
  {
    if constexpr ( sized_product_type<Type, 0> ) return kumi::record{};
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      return record{field<name_of(as<element_t<I,Type>>{})> = 
                      get<name_of(as<element_t<I,Type>>{})>(KUMI_FWD(r))... };
    }(std::make_index_sequence<size_v<Type>>{});
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Generate a kumi::tuple type from a type
  //!
  //! If `T` is a @ref kumi::product_type, returns the kumi::tuple type containing the same element
  //! as `T`. Otherwise, it returns `kumi::tuple<T>`.
  //!
  //! A template meta-function can be optionally passed to be applied to each of those types when
  //! types are computed.
  //!
  //! @tparam T     Type to transform
  //! @tparam Meta  Unary template meta-function to apply to each types.
  //!               Defaults to `std::type_identity`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, template<typename...> class Meta = std::type_identity>
  //!   using as_tuple_t = typename as_tuple<T, Meta>::type;
  //! }
  //! @endcode
  //!
  //! ## Example:
  //! @include doc/as_tuple.cpp
  //================================================================================================
  template<typename T, template<typename...> class Meta = std::type_identity>
  struct as_tuple;

  template<typename T, template<typename...> class Meta>
  requires( product_type<T> )
  struct as_tuple<T, Meta> : _::as_tuple <T,std::make_index_sequence<size_v<T>>, Meta>
  {};

  template<typename T, template<typename...> class Meta>
  requires( !product_type<T> )
  struct as_tuple<T, Meta>
  {
    using type = kumi::tuple< typename Meta<T>::type >;
  };

  template<typename T, template<typename...> class Meta = std::type_identity>
  using as_tuple_t =  typename as_tuple<T, Meta>::type;
}
