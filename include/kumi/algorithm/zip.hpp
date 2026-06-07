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
  struct zip_t : private kumi::function::builder_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::sized_product_type<kumi::size_v<T0>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      if constexpr (kumi::concepts::sized_product_type<T0, 0>) return kumi::tuple{};
      else
      {
        constexpr auto c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<kumi::size_v<T0>>);
        return this->zip_(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }

    template<typename T, std::size_t... I, std::size_t... J>
    KUMI_ABI constexpr auto zip_(T&& t, std::index_sequence<I...>, std::index_sequence<J...> is) const
    {
      return kumi::make_tuple(
        this->builder_t::operator()(KUMI_FWD(t), std::integral_constant<std::size_t, I>{}, is)...);
    }
  };

  struct zip_min_t : private kumi::zip_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      constexpr std::size_t m = kumi::_::min(kumi::size_v<T0>, kumi::size_v<Ts>...);
      if constexpr (m == 0) return kumi::tuple{};
      else
      {
        constexpr std::size_t c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<m>);
        return this->zip_(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }
  };

  struct zip_max_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      constexpr std::size_t m = kumi::_::max(kumi::size_v<T0>, kumi::size_v<Ts>...);
      if constexpr (m == 0) return kumi::tuple{};
      else
      {
        constexpr std::size_t c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<m>);
        return this->zip_(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }

    template<typename T, std::size_t... I, std::size_t... J>
    constexpr auto zip_(T&& t, std::index_sequence<I...>, std::index_sequence<J...> is) const
    {
      return kumi::make_tuple(this->zip_intern_(KUMI_FWD(t), kumi::index<I>, is)...);
    }

    template<typename T, std::size_t N, std::size_t... I>
    constexpr auto zip_intern_(T&& t, kumi::index_t<N>, std::index_sequence<I...>) const
    {
      using U = kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>;
      return kumi::builder<U>::make(kumi::function::get_or<N>(get<I>(KUMI_FWD(t)), kumi::none)...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var zip
    @brief Callable object constructing a tuple where the ith element is the product type of all ith elements of
  `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @see zip_min
    @see zip_max

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/zip.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, product_type... Ts>
      constexpr auto zip(T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to convert
      - `ts`: Product types to convert

    @subgroupheader{Return value}

      * The tuple of all combination of elements from `t0`, `ts`...

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T> struct zip;

      template<product_type T>
      using zip_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/zip.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/zip.cpp}
  **/
  //====================================================================================================================
  inline constexpr zip_t zip{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var zip_min
    @brief Callable object constructing a tuple where the ith element is the product type of all ith elements of
  `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @note `zip_min` truncates product types based on the smallest size.

    @see zip
    @see zip_max

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/zip.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, product_type... Ts>
      constexpr auto zip_min(T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to convert
      - `ts`: Product types to convert

    @subgroupheader{Return value}

      * The tuple of all combination of elements from `t0`, `ts`...

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T> struct zip_min;

      template<product_type T>
      using zip_min_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip_min

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/zip_min.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/zip_min.cpp}
  **/
  //====================================================================================================================
  inline constexpr zip_min_t zip_min{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var zip_min
    @brief Callable object constructing a tuple where the ith element is the product type of all ith elements of
  `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @note `zip_max` fills missing elements to reach the biggest product type size.

    @see zip
    @see zip_min

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/zip.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, product_type... Ts>
      constexpr auto zip_max(T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to convert
      - `ts`: Product types to convert

    @subgroupheader{Return value}

      * The tuple of all combination of elements from `t0`, `ts`...

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T> struct zip_max;

      template<product_type T>
      using zip_max_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip_max

    @groupheader{Example}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/zip_max.cpp}
  **/
  //====================================================================================================================
  inline constexpr zip_max_t zip_max{};

  namespace result
  {
    template<kumi::concepts::product_type T0, kumi::concepts::sized_product_type<kumi::size_v<T0>>... Ts> struct zip
    {
      using type = decltype(kumi::zip(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts> struct zip_min
    {
      using type = decltype(kumi::zip_min(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts> struct zip_max
    {
      using type = decltype(kumi::zip_max(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_t = typename kumi::result::zip<T0, Ts...>::type;

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_min_t = typename kumi::result::zip_min<T0, Ts...>::type;

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_max_t = typename kumi::result::zip_max<T0, Ts...>::type;
  }
}
