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
  //! @param t      Tuple to operate on.
  //! @param init   Optional initial value of the sum.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t) + init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct sum;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using sum_t = typename sum_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto sum(Tuple&& t, Value init)
  {
    if constexpr(_::empty_tuple<Tuple>) return init;
    else return kumi::apply( [init](auto const&... m) { return (m + ... + init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Tuple to operate on.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct sum;
  //!
  //!   template<product_type Tuple>
  //!   using sum_t = typename sum_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] constexpr auto sum(Tuple&& t)
  {
    return sum(kumi::extract(t,index<1>),get<0>(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) * ... * get<N-1>(t) * init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct prod;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename prod_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto prod(Tuple&& t, Value init)
  {
    if constexpr(_::empty_tuple<Tuple>) return init;
    else return kumi::apply( [init](auto const&... m) { return (m * ... * init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) * ... * get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct prod;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename prod_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] constexpr auto prod(Tuple&& t)
  {
    return prod(kumi::extract(t,index<1>),get<0>(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) & ... & get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct bit_and;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename bit_and_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto bit_and(Tuple&& t, Value init)
  {
    if constexpr(_::empty_tuple<Tuple>) return init;
    else return kumi::apply( [init](auto const&... m) { return (m & ... & init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) & ... & get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct bit_and;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename bit_and_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] constexpr auto bit_and(Tuple&& t)
  {
    return bit_and(kumi::extract(t,index<1>),get<0>(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) | ... | get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct bit_or;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename bit_or_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto bit_or(Tuple&& t, Value init)
  {
    if constexpr(_::empty_tuple<Tuple>) return init;
    else return kumi::apply( [init](auto const&... m) { return (m | ... | init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) | ... | get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct bit_or;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename bit_or_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] constexpr auto bit_or(Tuple&& t)
  {
    return bit_or(kumi::extract(t,index<1>),get<0>(t));
  }

  namespace result
  {
    template<product_type Tuple, typename Value = void>
    struct sum
    {
      using type = decltype(kumi::sum(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple> struct sum<Tuple>
    {
      using type = decltype(kumi::sum(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct prod
    {
      using type = decltype(kumi::prod(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct prod<Tuple>
    {
      using type = decltype(kumi::prod(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct bit_and
    {
      using type = decltype(kumi::bit_and(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct bit_and<Tuple>
    {
      using type = decltype(kumi::bit_and(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct bit_or
    {
      using type = decltype(kumi::bit_or(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct bit_or<Tuple>
    {
      using type = decltype(kumi::bit_or(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    using sum_t = typename sum<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using prod_t = typename prod<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using bit_and_t = typename bit_and<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using bit_or_t = typename bit_or<Tuple,Value>::type;
  }
}
