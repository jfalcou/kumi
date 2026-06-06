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
  template<std::size_t R> struct rotate_left_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else if constexpr ((R % kumi::size_v<T>) == 0) return KUMI_FWD(t);
      else
      {
        constexpr auto idxs =
          kumi::function::rotater(std::make_index_sequence<kumi::size_v<T>>{}, kumi::index<(R % kumi::size_v<T>)>);
        return (*this)(KUMI_FWD(t), idxs);
      }
    }

  private:
    template<typename T, std::size_t... N>
    KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<N...>) const noexcept
    {
      return kumi::builder<T>::make(get<N>(KUMI_FWD(t))...);
    }
  };

  template<std::size_t R> struct rotate_right_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else if constexpr ((R % kumi::size_v<T>) == 0) return KUMI_FWD(t);
      else
      {
        constexpr auto F = R % kumi::size_v<T>;
        constexpr auto idxs =
          kumi::function::rotater(std::make_index_sequence<kumi::size_v<T>>{}, kumi::index<(kumi::size_v<T> - F)>);
        return (*this)(KUMI_FWD(t), idxs);
      }
    }

  private:
    template<typename T, std::size_t... N>
    KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<N...>) const noexcept
    {
      return kumi::builder<T>::make(get<N>(KUMI_FWD(t))...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var rotate_left
    @brief Callable object

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/rotate.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t R, product_type T>
      constexpr auto rotate_left<R>(T && t) ;
    @endcode

    @subgroupheader{Template Parameters}
      - `R`:  Rotation factor

    @subgroupheader{Parameters}

      - `t`: Product Type to rotate

    @subgroupheader{Return value}

      * A product type equivalent to `t` with elements rotated R positions to the left.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<std::size_t R, product_type T> struct rotate_left;

      template<std::size_t R, product_type T>
      using rotate_left_t = typename rotate_left<R, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::rotate_left

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/rotate_left.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/rotate_left.cpp}
  **/
  //====================================================================================================================
  template<std::size_t R> inline constexpr rotate_left_t<R> rotate_left{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var rotate_right
    @brief Callable object

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/rotate.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t R, product_type T>
      constexpr auto rotate_right<R>(T && t) ;
    @endcode

    @subgroupheader{Template Parameters}
      - `R`:  Rotation factor

    @subgroupheader{Parameters}

      - `t`: Product Type to rotate

    @subgroupheader{Return value}

      * A product type equivalent to `t` with elements rotated R positions to the right.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<std::size_t R, product_type T> struct rotate_right;

      template<std::size_t R, product_type T>
      using rotate_right_t = typename rotate_right<R, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::rotate_right

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/rotate_right.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/rotate_right.cpp}
  **/
  //====================================================================================================================
  template<std::size_t R> inline constexpr rotate_right_t<R> rotate_right{};

  namespace result
  {
    template<std::size_t R, kumi::concepts::product_type T> struct rotate_left
    {
      using type = decltype(kumi::rotate_left<R>(std::declval<T>()));
    };

    template<std::size_t R, kumi::concepts::product_type T> struct rotate_right
    {
      using type = decltype(kumi::rotate_right<R>(std::declval<T>()));
    };

    template<std::size_t R, kumi::concepts::product_type T>
    using rotate_left_t = typename kumi::result::rotate_left<R, T>::type;

    template<std::size_t R, kumi::concepts::product_type T>
    using rotate_right_t = typename kumi::result::rotate_right<R, T>::type;
  }
}
