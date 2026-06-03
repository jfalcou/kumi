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
    @brief    Constructs a product type by adding a value `v` at the beginning of `t`.

    @param t  Base product type
    @param v  Value to insert in front of `t`
    @return   A product type composed of `v` followed by all elements of `t` in order.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, typename V> struct push_front;

      template<product_type T, typename V>
      using push_front_t = typename push_front<T,V>::type;
    }
    @endcode

    Computes the return type of a call to kumi::push_front

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/push_front.cpp
    ### Record:
    @include doc/record/algo/push_front.cpp
  **/
  //====================================================================================================================
  struct push_front_t
  {
    template<kumi::concepts::product_type T, typename V>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, V&& v) const
    {
      return (*this)(KUMI_FWD(t), KUMI_FWD(v), std::make_index_sequence<kumi::size_v<T>>{});
    }

  private:
    template<typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, V&& v, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(KUMI_FWD(v), get<I>(KUMI_FWD(t))...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Remove the first (if any) element of `t`.

    @param t  Base product type
    @return   A product type composed of all elements of `t` except its first. Has no effect on empty product types.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct pop_front;

      template<product_type T>
      using pop_front_t = typename pop_front<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::pop_front

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/pop_front.cpp
    ### Record:
    @include doc/record/algo/pop_front.cpp
  **/
  //====================================================================================================================
  struct pop_front_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else return (*this)(KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T> - 1>{});
    }

  private:
    template<typename T, std::size_t... I> KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(get<I + 1>(KUMI_FWD(t))...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Constructs a product type by adding a value `v` at the end of `t`.

    @param t  Base product type
    @param v  Value to insert in front of `t`
    @return   A product type composed of all elements of `t` in order followed by `v`.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, typename V> struct push_back;

      template<product_type T, typename V>
      using push_back_t = typename push_back<T,V>::type;
    }
    @endcode

    Computes the return type of a call to kumi::push_back

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/push_back.cpp
    ### Record:
    @include doc/record/algo/push_back.cpp
  **/
  //====================================================================================================================
  struct push_back_t
  {
    template<kumi::concepts::product_type T, typename V>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, V&& v) const
    {
      return (*this)(KUMI_FWD(t), KUMI_FWD(v), std::make_index_sequence<kumi::size_v<T>>{});
    }

  private:
    template<typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, V&& v, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(get<I>(KUMI_FWD(t))..., KUMI_FWD(v));
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Remove the last (if any) element of a kumi::product_type.

    @param t  Base product type
    @return   A product type composed of all elements of `t` except its last. Has no effect on empty product types.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct pop_back;

      template<product_type T>
      using pop_back_t = typename pop_back<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::pop_back

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/pop_back.cpp
    ### Record:
    @include doc/record/algo/pop_back.cpp
  **/
  //====================================================================================================================
  struct pop_back_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else return (*this)(KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T> - 1>{});
    }

  private:
    template<typename T, std::size_t... I> KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(get<I>(KUMI_FWD(t))...);
    }
  };

  inline constexpr push_front_t push_front{};
  inline constexpr pop_front_t pop_front{};
  inline constexpr push_back_t push_back{};
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
