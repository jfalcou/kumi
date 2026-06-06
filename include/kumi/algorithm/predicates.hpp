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
  struct all_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Pred p) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), p);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(p, get<0>(KUMI_FWD(t)));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (kumi::invoke(p, get<I>(KUMI_FWD(t))) && ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (get<I>(KUMI_FWD(t)) && ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct any_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Pred p) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), p);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(p, get<0>(KUMI_FWD(t)));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (kumi::invoke(p, get<I>(KUMI_FWD(t))) || ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return false;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (get<I>(KUMI_FWD(t)) || ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct none_of_t : private kumi::any_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr bool operator()(T&& t, Pred p) const noexcept
    {
      return !kumi::any_of_t::operator()(KUMI_FWD(t), p);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr bool operator()(T&& t) const noexcept
    {
      return !kumi::any_of_t::operator()(KUMI_FWD(t));
    }
  };

  struct count_if_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr std::size_t operator()(T&& t, Pred p) const noexcept
    {
      constexpr std::size_t o = 1ULL;
      constexpr std::size_t z = 0ULL;
      if constexpr (kumi::concepts::empty_product_type<T>) return z;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(values_of(KUMI_FWD(t)), p);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return ((kumi::invoke(p, get<I>(KUMI_FWD(t))) ? o : z) + ... + z);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct count_t : private kumi::count_if_t
  {
    template<kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr std::size_t operator()(T&& t) const noexcept
    {
      return kumi::count_if_t::operator()(KUMI_FWD(t), [](auto const& m) { return static_cast<bool>(m); });
    }
  };

  //====================================================================================================================
  /**
    @ingroup queries

    @var all_of
    @brief Callable object checking if a unary predicate p returns true for every element of t.

    On a record type, the function operates on the underlying elements of the fields.

    @qualifier inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/predicates.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Pred>
      constexpr auto all_of(T && t, Pred p) noexcept;
    @endcode

    @code
      template<product_type T, typename Pred>
      constexpr auto all_of(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process
      - `p`: Unary predicate

    @subgroupheader{Return value}

      * The evaluation of `p(get<0>(t)) && ... && p(get<N-1>(t))` where `N` is the size of `t`.

    @groupheader{Helper type}

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/all_of.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/all_of.cpp}
  **/
  //====================================================================================================================
  inline constexpr all_of_t all_of{};

  //====================================================================================================================
  /**
    @ingroup queries

    @var any_of
    @brief Callable object checking if a unary predicate p returns true for any element of t.

    On a record type, the function operates on the underlying elements of the fields.

    @qualifier inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/predicates.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Pred>
      constexpr auto any_of(T && t, Pred p) noexcept;
    @endcode

    @code
      template<product_type T, typename Pred>
      constexpr auto any_of(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process
      - `p`: Unary predicate

    @subgroupheader{Return value}

      * The evaluation of `p(get<0>(t)) || ... || p(get<N-1>(t))` where `N` is the size of `t`.

    @groupheader{Helper type}

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/any_of.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/any_of.cpp}
  **/
  //====================================================================================================================
  inline constexpr any_of_t any_of{};

  //====================================================================================================================
  /**
    @ingroup queries

    @var none_of
    @brief Callable object checking if a unary predicate p does not returns true for any element in t.

    On a record type, the function operates on the underlying elements of the fields.

    @qualifier inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/predicates.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Pred>
      constexpr auto none_of(T && t, Pred p) noexcept;
    @endcode

    @code
      template<product_type T, typename Pred>
      constexpr auto none_of(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process
      - `p`: Unary predicate

    @subgroupheader{Return value}

      * The evaluation of `!any_of(t,p)`.

    @groupheader{Helper type}

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/none_of.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/none_of.cpp}
  **/
  //====================================================================================================================
  inline constexpr none_of_t none_of{};

  //====================================================================================================================
  /**
    @ingroup queries

    @var count_if
    @brief Callable object counting the number of elements of t satisfying predicates p.

    On a record type, the function operates on the underlying elements of the fields.

    @qualifier inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/predicates.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Pred>
      constexpr auto count_if(T && t, Pred p) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process
      - `p`: Unary predicate

    @subgroupheader{Return value}

      * Number of elements satisfying the condition.

    @groupheader{Helper type}

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/count_if.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/count_if.cpp}
  **/
  //====================================================================================================================
  inline constexpr count_if_t count_if{};

  //====================================================================================================================
  /**
    @ingroup queries

    @var count
    @brief Callable object counting the number of elements of t not equivalent to false.

    On a record type, the function operates on the underlying elements of the fields.

    @qualifier inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/predicates.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto count(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      * Number of elements not equivalent to `false`.

    @groupheader{Helper type}

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/count.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/count.cpp}
  **/
  //====================================================================================================================
  inline constexpr count_t count{};
}
