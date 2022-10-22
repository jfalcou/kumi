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
  //! @ingroup generators
  //! @brief Extracts a sub-tuple from a product type
  //!
  //! @note Does not participate in overload resolution if `I0` and `I1` do not verify that
  //!       `0 <= I0 <= I1 <= size_v<T>`.
  //! @param  t  Tuple to extract from
  //! @param  i0 Compile-time index of the first element to extract.
  //! @param  i1 Compile-time index past the last element to extract. By default, `i1` is equal to
  //!         `size_v<T>`.
  //! @return A new kumi::tuple containing to the selected elements of the input tuple.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, std::size_t I0, std::size_t I1=-1> struct extract;
  //!
  //!   template<product_type Tuple, std::size_t I0, std::size_t I1=-1>
  //!   using extract_t = typename extract<Tuple,I0,I1>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to extract.
  //!
  //! ## Example:
  //! @include doc/extract.cpp
  //================================================================================================
  template<std::size_t I0, std::size_t I1, product_type Tuple>
  requires( (I0 <= size_v<Tuple>) && (I1 <= size_v<Tuple>) )
  [[nodiscard]] constexpr
  auto extract(Tuple const& t, index_t<I0> const &, index_t<I1> const &) noexcept
  {
    return [&]<std::size_t... N>(std::index_sequence<N...>)
    {
      return kumi::tuple<std::tuple_element_t<N + I0, Tuple>...> {get<N + I0>(t)...};
    }
    (std::make_index_sequence<I1 - I0>());
  }

  //! @overload
  template<std::size_t I0, product_type Tuple>
  requires(I0<= size_v<Tuple>)
  [[nodiscard]] constexpr
  auto extract(Tuple const& t, index_t<I0> const& i0) noexcept
  {
    return extract(t,i0, index<size_v<Tuple>>);
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Split a tuple into two
  //!
  //! Split a kumi::tuple in two kumi::tuple containing all the elements before and after
  //! a given index.
  //!
  //! @note Does not participate in overload resolution if `I0` is not in `[0, sizeof...(Ts)[`.
  //!
  //! @param  i0 Compile-time index of the first element to extract.
  //! @return A new kumi::tuple containing the two sub-tuple cut at index I.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, std::size_t I0> struct split;
  //!
  //!   template<product_type Tuple, std::size_t I0>
  //!   using split_t = typename split<Tuple,I0>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to split.
  //!
  //! ## Example:
  //! @include doc/split.cpp
  //================================================================================================
  template<std::size_t I0, product_type Tuple>
  requires(I0 <= size_v<Tuple>)
  [[nodiscard]] constexpr auto split(Tuple const& t, index_t<I0> const&) noexcept
  {
    return kumi::make_tuple(extract(t,index<0>, index<I0>), extract(t,index<I0>));
  }

  namespace result
  {
    template<product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)>
    struct extract
    {
      using type = decltype ( kumi::extract ( std::declval<T>()
                                            , kumi::index_t<I0>{},kumi::index_t<I1>{}
                                            )
                            );
    };

    template<product_type T, std::size_t I0>
    struct extract<T,I0>
    {
      using type = decltype(kumi::extract(std::declval<T>(),kumi::index_t<I0>{}) );
    };

    template<product_type T, std::size_t I0>
    struct split
    {
      using type = decltype(kumi::split(std::declval<T>(),kumi::index_t<I0>{}) );
    };

    template<product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)>
    using extract_t = typename extract<T,I0,I1>::type;

    template<product_type T, std::size_t I0>
    using split_t = typename split<T,I0>::type;
  }
}
