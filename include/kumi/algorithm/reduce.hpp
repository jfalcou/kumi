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
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Product Type to operate on.
  //! @param init   Optional initial value of the sum.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t) + init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct sum;
  //!
  //!   template<product_type T, typename Value>
  //!   using sum_t = typename sum_t<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t, Value init)
  {
    if constexpr( sized_product_type<T,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m + ... + init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Product Type to operate on.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct sum;
  //!
  //!   template<product_type T>
  //!   using sum_t = typename sum_t<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t)
  {
    auto&& [head,tail] = kumi::split(KUMI_FWD(t), index<1>);
    return sum(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) * ... * get<N-1>(t) * init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct prod;
  //!
  //!   template<product_type T, typename Value>
  //!   using prod_t = typename prod_t<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t, Value init)
  {
    if constexpr(sized_product_type<T,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m * ... * init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @return The value of `get<0>(t) * ... * get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct prod;
  //!
  //!   template<product_type T>
  //!   using prod_t = typename prod_t<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return prod(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) & ... & get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct bit_and;
  //!
  //!   template<product_type T, typename Value>
  //!   using prod_t = typename bit_and_t<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t, Value init)
  {
    if constexpr(sized_product_type<T,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m & ... & init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @return The value of `get<0>(t) & ... & get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct bit_and;
  //!
  //!   template<product_type T>
  //!   using prod_t = typename bit_and_t<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return bit_and(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) | ... | get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct bit_or;
  //!
  //!   template<product_type T, typename Value>
  //!   using prod_t = typename bit_or_t<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t, Value init)
  {
    if constexpr(sized_product_type<T,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m | ... | init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Product Type to operate on
  //! @return The value of `get<0>(t) | ... | get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct bit_or;
  //!
  //!   template<product_type T>
  //!   using prod_t = typename bit_or_t<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return bit_or(tail, get<0>(head));
  }

  namespace result
  {
    template<product_type T, typename Value = void>
    struct sum
    {
      using type = decltype(kumi::sum(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct sum<T>
    {
      using type = decltype(kumi::sum(std::declval<T>()));
    };

    template<product_type T, typename Value = void>
    struct prod
    {
      using type = decltype(kumi::prod(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T>
    struct prod<T>
    {
      using type = decltype(kumi::prod(std::declval<T>()));
    };

    template<product_type T, typename Value = void>
    struct bit_and
    {
      using type = decltype(kumi::bit_and(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T>
    struct bit_and<T>
    {
      using type = decltype(kumi::bit_and(std::declval<T>()));
    };

    template<product_type T, typename Value = void>
    struct bit_or
    {
      using type = decltype(kumi::bit_or(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T>
    struct bit_or<T>
    {
      using type = decltype(kumi::bit_or(std::declval<T>()));
    };

    template<product_type T, typename Value = void>
    using sum_t = typename sum<T,Value>::type;

    template<product_type T, typename Value = void>
    using prod_t = typename prod<T,Value>::type;

    template<product_type T, typename Value = void>
    using bit_and_t = typename bit_and<T,Value>::type;

    template<product_type T, typename Value = void>
    using bit_or_t = typename bit_or<T,Value>::type;
  }
}
