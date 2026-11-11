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
    template<kumi::concepts::product_type T, std::size_t B, std::size_t E, std::size_t S>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t,
                                                     kumi::index_t<B>,
                                                     kumi::index_t<E>,
                                                     kumi::index_t<S>) const noexcept
    {
      static_assert((B <= kumi::size_v<T>) && (E <= kumi::size_v<T>), "[KUMI] - Invalid index");
      return kumi::_::builder(KUMI_FWD(t), kumi::function::slice_index_sequence<B, E, S>{});
    }

    template<kumi::concepts::product_type T, std::size_t B, std::size_t E>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<B>, kumi::index_t<E>) const noexcept
    {
      static_assert((B <= kumi::size_v<T>) && (E <= kumi::size_v<T>), "[KUMI] - Invalid index");
      return kumi::_::builder(KUMI_FWD(t), kumi::function::slice_index_sequence<B, E>{});
    }

    template<kumi::concepts::product_type T, std::size_t B>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<B> b) const noexcept
    {
      static_assert(B <= kumi::size_v<T>, "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), b, kumi::index<size_v<T>>);
    }
  };

  struct remove_t
  {
    template<kumi::concepts::product_type T, std::size_t B, std::size_t E, std::size_t S>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t,
                                                     kumi::index_t<B>,
                                                     kumi::index_t<E>,
                                                     kumi::index_t<S>) const noexcept
    {
      static_assert((B <= kumi::size_v<T>) && (E <= kumi::size_v<T>), "[KUMI] - Invalid index");
      using kept = kumi::function::remove_index_sequence<kumi::size_v<T>, B, E, S>;
      return kumi::_::builder(KUMI_FWD(t), kept{});
    }

    template<kumi::concepts::product_type T, std::size_t B, std::size_t E>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<B> b, kumi::index_t<E> e) const noexcept
    {
      static_assert((B <= kumi::size_v<T>) && (E <= kumi::size_v<T>), "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), b, e, kumi::index<1>);
    }

    template<kumi::concepts::product_type T, std::size_t B>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<B> b) const noexcept
    {
      static_assert(B <= kumi::size_v<T>, "[KUMI] - Invalid index");
      return (*this)(KUMI_FWD(t), b, kumi::index<kumi::size_v<T>>);
    }
  };

  struct split_t
  {
    template<kumi::concepts::product_type T, std::size_t I>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, kumi::index_t<I>) const noexcept
    {
      static_assert(I <= kumi::size_v<T>, "[KUMI] - Invalid index");

      using first = std::make_index_sequence<I>;
      using last = kumi::function::shift_index_sequence<I, kumi::size_v<T> - I>;
      return kumi::tuple{kumi::_::builder(KUMI_FWD(t), first{}), kumi::_::builder(KUMI_FWD(t), last{})};
    }
  };

  //====================================================================================================================
  //! @defgroup kumi_extract kumi::extract
  //! @ingroup kumi_index_projections
  //! @brief Callable object extracting a sub product type from a product type
  //====================================================================================================================
  /**
    @ingroup kumi_extract

    @var extract

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `B` or `E` is greater than `kumi::size_v<T>`, or if `S` is 0.
          It returns an empty product type when `E` is not greater than `B`.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, std::size_t B, std::size_t E, std::size_t S>
        constexpr auto extract(T && t, kumi::index_t<B>, kumi::index_t<E>, kumi::index_t<S>) noexcept;  // 1

        template<concepts::product_type T, std::size_t B, std::size_t E>
        constexpr auto extract(T && t, kumi::index_t<B>, kumi::index_t<E>) noexcept;                    // 2

        template<concepts::product_type T, std::size_t B>
        constexpr auto extract(T && t, kumi::index_t<B>) noexcept;                                      // 3
      }
    @endcode

    @subgroupheader{Template Parameters}

      - `B`: Compile-time index of the first element to extract
      - `E`: Compile-time index past the last element to extract
      - `S`: Compile-time distance between two extracted elements

    @subgroupheader{Parameters}

      - `t`: Product Type to extract elements from

    @subgroupheader{Return value}

      - 1. A new product type containing the elements of `t` at the indexes `B`, `B + S`, `B + 2 * S`, and so on,
        lower than `E`.
      - 2. A new product type containing the elements of `t` from the index `B` to the index `E`, `E` excluded.
      - 3. A new product type containing the elements of `t` from the index `B` to the last one.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/extract.hpp extract_t

    Computes the return type of a call to kumi::extract

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/extract.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/extract.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr extract_t extract{};

  //====================================================================================================================
  //! @defgroup kumi_remove kumi::remove
  //! @ingroup kumi_index_projections
  //! @brief Callable object removing a sub product type from a product type
  //====================================================================================================================
  /**
    @ingroup kumi_remove

    @var remove

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `B` or `E` is greater than `kumi::size_v<T>`, or if `S` is 0.
          It returns every element of `t` when `E` is not greater than `B`.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, std::size_t B, std::size_t E, std::size_t S>
        constexpr auto remove(T && t, kumi::index_t<B>, kumi::index_t<E>, kumi::index_t<S>) noexcept;  // 1

        template<concepts::product_type T, std::size_t B, std::size_t E>
        constexpr auto remove(T && t, kumi::index_t<B>, kumi::index_t<E>) noexcept;                    // 2

        template<concepts::product_type T, std::size_t B>
        constexpr auto remove(T && t, kumi::index_t<B>) noexcept;                                      // 3
      }
    @endcode

    @subgroupheader{Template Parameters}

      - `B`: Compile-time index of the first element to remove
      - `E`: Compile-time index past the last element to remove
      - `S`: Compile-time distance between two removed elements

    @subgroupheader{Parameters}

      - `t`: Product Type to remove elements from

    @subgroupheader{Return value}

      - 1. A new product type containing the elements of `t` except those at the indexes `B`, `B + S`, `B + 2 * S`,
        and so on, lower than `E`.
      - 2. A new product type containing the elements of `t` except those from the index `B` to the index `E`, `E`
        excluded.
      - 3. A new product type containing the elements of `t` before the index `B`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/extract.hpp remove_t

    Computes the return type of a call to kumi::remove

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/remove.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/remove.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr remove_t remove{};

  //====================================================================================================================
  //! @defgroup kumi_split kumi::split
  //! @ingroup kumi_index_projections
  //! @brief Callable object splitting a product type into two
  //====================================================================================================================
  /**
    @ingroup kumi_split

    @var split

    Split a product type in two product_type containing all the elements before and after a given index.
    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function will issue a compile time error if `I0` is not in `[0, size_v<T>[`.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, std::size_t I0>
        constexpr auto split(T && t, kumi::index_t<I0>) noexcept;
      }
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to extract elements from
      - `i0`: Compile-time index of the split pivot

    @subgroupheader{Return value}

      - A new tuple containing the two sub parts of `t` cut at `i0`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/extract.hpp split_t

    Computes the return type of a call to kumi::split

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/split.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/split.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr split_t split{};

  namespace result
  {
    //! [extract_t]
    template<kumi::concepts::product_type T, std::size_t... I>
    requires((sizeof...(I) == 1) || (sizeof...(I) == 2))
    using extract_t = decltype(kumi::extract(kumi::declval<T>(), kumi::index_t<I>{}...));

    template<kumi::concepts::product_type T, std::size_t... I>
    requires((sizeof...(I) == 1) || (sizeof...(I) == 2))
    struct extract
    {
      using type = kumi::result::extract_t<T, I...>;
    };

    //! [extract_t]

    //! [remove_t]
    template<kumi::concepts::product_type T, std::size_t... I>
    requires((sizeof...(I) == 1) || (sizeof...(I) == 2))
    using remove_t = decltype(kumi::remove(kumi::declval<T>(), kumi::index_t<I>{}...));

    template<kumi::concepts::product_type T, std::size_t... I>
    requires((sizeof...(I) == 1) || (sizeof...(I) == 2))
    struct remove
    {
      using type = kumi::result::remove_t<T, I...>;
    };

    //! [remove_t]

    //! [split_t]
    template<kumi::concepts::product_type T, std::size_t I>
    using split_t = decltype(kumi::split(kumi::declval<T>(), kumi::index_t<I>{}));

    template<kumi::concepts::product_type T, std::size_t I> struct split
    {
      using type = kumi::result::split_t<T, I>;
    };

    //! [split_t]
  }
}
