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
  struct extract_t
  {
    template<std::size_t I0, std::size_t I1, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<I0> i0, kumi::index_t<I1>) const noexcept
    {
      static_assert((I0 <= kumi::size_v<T>) && (I1 <= kumi::size_v<T>), "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), i0, std::make_index_sequence<I1 - I0>{});
    }

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

  //====================================================================================================================
  /**
    @ingroup generators

    @var extract
    @brief Callable object extracting a sub product type from a product type

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `I0` and `I1` do not verify that
          `0 <= I0 <= I1 <= size_v<T>`.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/extract.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, std::size_t I0, std::size_t I1>
      constexpr auto extract(T && t, kumi::index_t<I0>, kumi::index_t<I1>) noexcept;  // 1
    @endcode

    @code
      template<product_type T, std::size_t I0>
      constexpr auto extract(T && t, kumi::index_t<I0>) noexcept;                      // 2
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to extract elements from
      - `i0`: Compile-time index of the first element to extract
      - `i1`: Compile-time index past the last element to extract

    @subgroupheader{Return value}

      1. A new product type containing the selected range of elements of `t`.
      2. A new product type containing the selected elements of `t` using `size_v<T>` as the last index.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, std::size_t I0, std::size_t I1=-1> struct extract;

      template<product_type T, std::size_t I0, std::size_t I1=-1>
      using extract_t = typename extract<T,I0,I1>::type;
    }
    @endcode

    Computes the return type of a call to kumi::extract

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/extract.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/extract.cpp}
  **/
  //====================================================================================================================
  inline constexpr extract_t extract{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var split
    @brief Callable object splitting a product type into two

    Split a product type in two product_type containing all the elements before and after a given index.
    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `I0` is not in `[0, sizeof...(Ts)[`.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/extract.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, std::size_t I0>
      constexpr auto split(T && t, kumi::index_t<I0>, kumi::index_t<I1>) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to extract elements from
      - `i0`: Compile-time index of the split pivot

    @subgroupheader{Return value}

      * A new tuple containing the two sub parts of `t` cut at `i0`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, std::size_t I0> struct split;

      template<product_type T, std::size_t I0>
      using split_t = typename split<T,I0>::type;
    }
    @endcode

    Computes the return type of a call to kumi::split

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/split.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/split.cpp}
  **/
  //====================================================================================================================
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
