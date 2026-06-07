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
  struct push_front_t
  {
    template<kumi::concepts::product_type T, typename V>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, V&& v) const
    {
      return this->push_front_(KUMI_FWD(t), KUMI_FWD(v), std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto push_front_(T&& t, V&& v, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(KUMI_FWD(v), get<I>(KUMI_FWD(t))...);
    }
  };

  struct pop_front_t : private kumi::function::builder_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
        return this->builder_t::operator()(KUMI_FWD(t),
                                           kumi::function::shifter(std::integral_constant<std::size_t, 1>{},
                                                                   std::make_index_sequence<kumi::size_v<T> - 1>{}));
    }
  };

  struct push_back_t
  {
    template<kumi::concepts::product_type T, typename V>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, V&& v) const
    {
      return this->push_back_(KUMI_FWD(t), KUMI_FWD(v), std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto push_back_(T&& t, V&& v, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(get<I>(KUMI_FWD(t))..., KUMI_FWD(v));
    }
  };

  struct pop_back_t : private kumi::function::builder_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else return this->builder_t::operator()(KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var push_front
    @brief Callable object constructing a product type by adding a value `v` at the beginning of `t`.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/push_pop.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename V>
      constexpr auto push_front(T && t, V && v);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Base product type
      - `v`: Value to insert in front of `t`

    @subgroupheader{Return value}

      * A product type composed of `v` followed by all elements of `t` in order.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename V> struct push_front;

      template<product_type T, typename V>
      using push_front_t = typename push_front<T,V>::type;
    }
    @endcode

    Computes the return type of a call to kumi:push_front

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/push_front.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/push_front.cpp}
  **/
  //====================================================================================================================
  inline constexpr push_front_t push_front{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var pop_front
    @brief Callable object removing the first (if any) element of `t`.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/push_pop.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto pop_front(T && t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Base product type

    @subgroupheader{Return value}

      * A product type composed of all elements of `t` except its first. Has no effect on empty product types.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T> struct pop_front;

      template<product_type T>
      using pop_front_t = typename pop_front<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi:pop_front

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/pop_front.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/pop_front.cpp}
  **/
  //====================================================================================================================
  inline constexpr pop_front_t pop_front{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var push_front
    @brief Callable object constructing a product type by adding a value `v` at the end of `t`.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/push_pop.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename V>
      constexpr auto push_back(T && t, V && v);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Base product type
      - `v`: Value to insert at the end of `t`

    @subgroupheader{Return value}

      * A product type composed of all elements of `t` in order followed by `v`.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename V> struct push_back;

      template<product_type T, typename V>
      using push_back_t = typename push_back<T,V>::type;
    }
    @endcode

    Computes the return type of a call to kumi:push_back

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/push_back.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/push_back.cpp}
  **/
  //====================================================================================================================
  inline constexpr push_back_t push_back{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var pop_front
    @brief Callable object removing the last(if any) element of `t`.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/push_pop.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename V>
      constexpr auto pop_back(T && t, V && v);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Base product type

    @subgroupheader{Return value}

      * A product type composed of all elements of `t` except its last. Has no effect on empty product types.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T> struct pop_back;

      template<product_type T>
      using pop_back_t = typename pop_back<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi:pop_back

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/pop_back.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/pop_back.cpp}
  **/
  //====================================================================================================================
  inline constexpr pop_back_t pop_back{};

  namespace result
  {
    template<kumi::concepts::product_type T, typename V> struct push_front
    {
      using type = decltype(kumi::push_front(std::declval<T>(), std::declval<V>()));
    };

    template<kumi::concepts::product_type T> struct pop_front
    {
      using type = decltype(kumi::pop_front(std::declval<T>()));
    };

    template<kumi::concepts::product_type T, typename V> struct push_back
    {
      using type = decltype(kumi::push_back(std::declval<T>(), std::declval<V>()));
    };

    template<kumi::concepts::product_type T> struct pop_back
    {
      using type = decltype(kumi::pop_back(std::declval<T>()));
    };

    template<kumi::concepts::product_type T, typename V>
    using push_front_t = typename kumi::result::push_front<T, V>::type;

    template<kumi::concepts::product_type T> using pop_front_t = typename kumi::result::pop_front<T>::type;

    template<kumi::concepts::product_type T, typename V>
    using push_back_t = typename kumi::result::push_back<T, V>::type;

    template<kumi::concepts::product_type T> using pop_back_t = typename kumi::result::pop_back<T>::type;
  }
}
