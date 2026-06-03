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
  /**
    @ingroup  generators
    @brief    Extracts a sub product type from a product type

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `I0` and `I1` do not verify that
          `0 <= I0 <= I1 <= size_v<T>`.

    @param  t  Product Type to extract from
    @param  i0 Compile-time index of the first element to extract.
    @param  i1 Compile-time index past the last element to extract. By default, `i1` is equal to
            `size_v<T>`.
    @return A new product type containing the selected elements of `t`.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, std::size_t I0, std::size_t I1=-1> struct extract;

      template<product_type T, std::size_t I0, std::size_t I1=-1>
      using extract_t = typename extract<T,I0,I1>::type;
    }
    @endcode

    Computes the type returned by a call to extract.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/extract.cpp
    ### Record:
    @include doc/record/algo/extract.cpp
  **/
  //====================================================================================================================
  struct extract_t
  {
    template<std::size_t I0, std::size_t I1, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t,
                                                     [[maybe_unused]] kumi::index_t<I0> i0,
                                                     [[maybe_unused]] kumi::index_t<I1> i1) const noexcept
    {
      static_assert((I0 <= kumi::size_v<T>) && (I1 <= kumi::size_v<T>), "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), i0, std::make_index_sequence<I1 - I0>{});
    }

    //! @overload
    template<std::size_t I0, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<I0> i0) const noexcept
    {
      static_assert(I0 <= kumi::size_v<T>, "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), i0, kumi::index<size_v<T>>);
    }

  protected:
    template<typename T, std::size_t N, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<N>, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(get<N + I>(KUMI_FWD(t))...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Split a product type into two

    Split a product type in two product_type containing all the elements before and after a given index.
    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `I0` is not in `[0, sizeof...(Ts)[`.

    @param  t Product Type to split.
    @param  i0 Compile-time index of the split pivot.
    @return A new tuple containing the two sub parts of `t` cut at index I.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, std::size_t I0> struct split;

      template<product_type T, std::size_t I0>
      using split_t = typename split<T,I0>::type;
    }
    @endcode

    Computes the type returned by a call to split.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/split.cpp
    ### Record:
    @include doc/record/algo/split.cpp
  **/
  //====================================================================================================================
  struct split_t : private extract_t
  {
    template<std::size_t I0, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, [[maybe_unused]] kumi::index_t<I0> i0) const noexcept
    {
      static_assert(I0 <= kumi::size_v<T>, "[KUMI] - Invalid index");
      constexpr auto proj = kumi::function::splitter(kumi::index<I0>, std::make_index_sequence<kumi::size_v<T> - I0>{});

      return kumi::tuple{this->extract_t::operator()(KUMI_FWD(t), kumi::index<0>, get<0>(proj)),
                         this->extract_t::operator()(KUMI_FWD(t), kumi::index<0>, get<1>(proj))};
    }
  };

  inline constexpr extract_t extract{};
  inline constexpr split_t split{};

  namespace result
  {
    template<kumi::concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)> struct extract
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}, kumi::index_t<I1>{}));
    };

    template<kumi::concepts::product_type T, std::size_t I0> struct extract<T, I0>
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}));
    };

    template<kumi::concepts::product_type T, std::size_t I0> struct split
    {
      using type = decltype(kumi::split(std::declval<T>(), kumi::index_t<I0>{}));
    };

    template<kumi::concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)>
    using extract_t = typename kumi::result::extract<T, I0, I1>::type;

    template<kumi::concepts::product_type T, std::size_t I0> using split_t = typename kumi::result::split<T, I0>::type;
  }
}
