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
  //! @brief    Extracts a sub product type from a product type
  //!
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! @note Does not participate in overload resolution if `I0` and `I1` do not verify that
  //!       `0 <= I0 <= I1 <= size_v<T>`.
  //! @param  t  Product Type to extract from
  //! @param  i0 Compile-time index of the first element to extract.
  //! @param  i1 Compile-time index past the last element to extract. By default, `i1` is equal to
  //!         `size_v<T>`.
  //! @return A new product type containing the selected elements of `t`.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, std::size_t I0, std::size_t I1=-1> struct extract;
  //!
  //!   template<product_type T, std::size_t I0, std::size_t I1=-1>
  //!   using extract_t = typename extract<T,I0,I1>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to extract.
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/extract.cpp
  //! ### Record:
  //! @include doc/record/algo/extract.cpp
  //====================================================================================================================
  template<std::size_t I0, std::size_t I1, concepts::product_type T>
  requires((I0 <= size_v<T>) && (I1 <= size_v<T>))
  [[nodiscard]] KUMI_ABI constexpr auto extract(T&& t,
                                                [[maybe_unused]] index_t<I0> i0,
                                                [[maybe_unused]] index_t<I1> i1) noexcept
  {
    return [&]<std::size_t... N>(std::index_sequence<N...>) {
      using final_t = builder_make_t<T, element_t<N + I0, T>...>;
      return final_t{get<N + I0>(KUMI_FWD(t))...};
    }(std::make_index_sequence<I1 - I0>());
  }

  //! @overload
  template<std::size_t I0, concepts::product_type T>
  requires(I0 <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto extract(T&& t, index_t<I0> i0) noexcept
  {
    return extract(KUMI_FWD(t), i0, index<size_v<T>>);
  }

  //====================================================================================================================
  //! @ingroup  generators
  //! @brief    Split a product type into two
  //!
  //! Split a product type in two product_type containing all the elements before and after a given index.
  //! On record types, this function operates on elements as if they were ordered. The considered order is the order
  //! of declaration.
  //!
  //! @note Does not participate in overload resolution if `I0` is not in `[0, sizeof...(Ts)[`.
  //!
  //! @param  t Product Type to split.
  //! @param  i0 Compile-time index of the split pivot.
  //! @return A new tuple containing the two sub parts of `t` cut at index I.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, std::size_t I0> struct split;
  //!
  //!   template<product_type T, std::size_t I0>
  //!   using split_t = typename split<T,I0>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to split.
  //!
  //! ## Examples:
  //! ### Tuple:
  //! @include doc/tuple/algo/split.cpp
  //! ### Record:
  //! @include doc/record/algo/split.cpp
  //====================================================================================================================
  template<std::size_t I0, concepts::product_type T>
  requires(I0 <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto split(T&& t, [[maybe_unused]] index_t<I0> i0) noexcept
  {
    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>) {
      using type = builder_make_t<T, element_t<O::value + I, T>...>;
      return type{get<O::value + I>(KUMI_FWD(t))...};
    };

    return kumi::tuple{select(index<0>, std::make_index_sequence<I0>{}),
                       select(index<I0>, std::make_index_sequence<size_v<T> - I0>{})};
  }

  namespace result
  {
    template<concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)> struct extract
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}, kumi::index_t<I1>{}));
    };

    template<concepts::product_type T, std::size_t I0> struct extract<T, I0>
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}));
    };

    template<concepts::product_type T, std::size_t I0> struct split
    {
      using type = decltype(kumi::split(std::declval<T>(), kumi::index_t<I0>{}));
    };

    template<concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)>
    using extract_t = typename extract<T, I0, I1>::type;

    template<concepts::product_type T, std::size_t I0> using split_t = typename split<T, I0>::type;
  }
}
