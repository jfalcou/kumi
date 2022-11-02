//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include "kumi/tuple.hpp"
namespace kumi
{
  namespace detail
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
  requires(!product_type<Type> && detail::implicit_constructible<Type, Ts...>)
  [[nodiscard]] constexpr auto from_tuple(tuple<Ts...> const &t)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) { return Type {get<I>(t)...}; }
    (std::make_index_sequence<sizeof...(Ts)>());
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
  //! ## Example
  //! @include doc/to_tuple.cpp
  //================================================================================================
  template<product_type Type>
  [[nodiscard]] inline constexpr auto to_tuple(Type&& t)
  {
    return apply([](auto &&...elems) { return tuple{elems...}; }, KUMI_FWD(t));
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
  struct as_tuple<T, Meta> : detail::as_tuple < T
                                              , std::make_index_sequence<size_v<T>>
                                              , Meta
                                              >
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
