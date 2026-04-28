//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    If T is a kumi::product_type, returns its number of elements otherwise returns V;

    @tparam T type to inspect
    @tparam V fallback value

    ## Helper value
    @code
      template<typename T, auto V> inline constexpr std::size_t size_or_v = size_or<T,V>::value;
    @endcode
  **/
  //====================================================================================================================
  template<typename T, auto V> struct size_or
  {
    static constexpr auto value = [] {
      if constexpr (kumi::concepts::product_type<T>) return kumi::size_v<T>;
      else return V;
    }();
  };

  template<typename T, auto V> inline constexpr auto size_or_v = kumi::function::size_or<T, V>::value;

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    If T is a kumi::product_type and I is within it's size, returns element_t<I,T>, returns U otherwise

    @tparam I Index of the type to retrieve
    @tparam T type to access
    @tparam U fallback type

    ## Helper type
    @code
    namespace kumi
    {
      template<std::size_t I, typename T, typename U> using element_or_t = typename element_or<I,T,U>::type;
    }
    @endcode
  **/
  //====================================================================================================================
  template<std::size_t I, typename T, typename U> struct element_or
  {
    using type = typename decltype([] {
      if constexpr (kumi::concepts::product_type<T> && I < kumi::size_v<T>) return kumi::element<I, T>{};
      else return std::type_identity<U>{};
    }())::type;
  };

  template<std::size_t I, typename T, typename U>
  using element_or_t = typename kumi::function::element_or<I, T, U>::type;

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    If T is a kumi::product_type, returns it's Ith element, returns an instance of V otherwise.

    @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    @tparam   I Compile-time index of the element to access
    @param    t type to inspect
    @param    v fallback value
    @return   A reference to the selected element of t if t is a kumi::product_type, the parameter v otherwise.
  **/
  //====================================================================================================================
  template<std::size_t I, typename T, typename V> [[nodiscard]] KUMI_ABI constexpr decltype(auto) get_or(T&& t, V&& v)
  {
    if constexpr (kumi::concepts::product_type<T> && I < kumi::size_v<T>) return get<I>(KUMI_FWD(t));
    else return KUMI_FWD(v);
  }

  //====================================================================================================================
  /**
    @class    foldable
    @ingroup  functional
    @brief    Functional wrapper for values to facilitate pipelined transformations.

    kumi::function::foldable provides a lightweight wrapper that enables functional-style chaining of operations
    using the `>>` and `<<` operators. It acts as an identity functor, allowing a value to be
    transformed through a sequence of callables without manual temporary variables.

    @tparam T Type of the value stored inside kumi::foldable.
  **/
  //====================================================================================================================
  template<typename T> struct foldable
  {
    T value;

    //==================================================================================================================
    /**
      @brief Pipelines the value contained in the foldable into a unary callable, chaining computation from left
             to right.

      @param f The foldable instance.
      @param c The unary callable
      @return A new kumi::foldable containing the result of the invocation.
    **/
    //==================================================================================================================
    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(foldable&& f, C&& c)
    {
      return kumi::function::foldable{kumi::invoke(c, f.value)};
    }

    //==================================================================================================================
    /**
      @brief Pipelines the value contained in the foldable into a unary callable, chaining computation from right
             to left.

      @param f The foldable instance.
      @param c The unary callable
      @return A new kumi::foldable containing the result of the invocation.
    **/
    //==================================================================================================================
    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, foldable&& f)
    {
      return kumi::function::foldable{kumi::invoke(c, f.value)};
    }

    //==================================================================================================================
    /**
      @brief Finalizes the fold.
      @return The value contained in a foldable, essentially marking the end of a computation.
    **/
    //==================================================================================================================
    KUMI_ABI constexpr auto operator()() const noexcept { return value; }
  };

  //====================================================================================================================
  /**
    @class    scannable
    @ingroup  functional
    @brief    Functional wrapper that accumulates state during a transformation chain.

    kumi::scannable tracks both a current value and a transformation history. As the value is
    piped through callables, the previous state is bound into the underlying function,
    effectively performing a "scan" or "prefix sum" at the type level.

    @tparam F The accumulated function state (partial applications).
    @tparam V The current result value.
  **/
  //====================================================================================================================
  template<typename F, typename V> struct scannable
  {
    F func;
    V value;

    //==================================================================================================================
    /**
      @brief  Pipelines the current value into a unary callable and accumulates the operation into the function state,
              chaining computations from left to right.

      @param s The scannable instance.
      @param c The callable to apply.
      @return A new kumi::scannable with updated value and bound function state.
    **/
    //==================================================================================================================
    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(scannable&& s, C&& c)
    {
      auto res = kumi::invoke(c, s.value);
      return kumi::function::scannable{kumi::bind_front(std::move(s.func), std::move(s.value)), res};
    }

    //==================================================================================================================
    /**
      @brief  Pipelines the current value into a unary callable and accumulates the operation into the function state,
              chaining computations from right to left.

      @param c The callable to apply.
      @param s The scannable instance.
      @return A new kumi::scannable with updated value and bound function state.
    **/
    //==================================================================================================================
    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, scannable&& s)
    {
      auto res = kumi::invoke(c, s.value);
      return kumi::function::scannable{kumi::bind_back(std::move(s.func), std::move(s.value)), res};
    }

    //==================================================================================================================
    /**
      @brief  Finalizes the scan.
      @return The invocation of the bounded function with the last value contained in a scannable.
              Essentially marking the end of a computation.
    **/
    //==================================================================================================================
    KUMI_ABI constexpr decltype(auto) operator()() const noexcept { return kumi::invoke(func, value); }
  };

  //====================================================================================================================
  /**
    @related    kumi::function::foldable
    @brief      kumi::function::foldable deduction guide
    @tparam T   Type to wrap into the foldable context.
  **/
  //====================================================================================================================
  template<typename T> foldable(T&& t) -> foldable<std::unwrap_ref_decay_t<T>>;

  //====================================================================================================================
  /**
    @related    kumi::function::scannable
    @brief      kumi::function::scannable deduction guide
    @tparam T   Type to wrap into the foldable context.
    @tparam F   Function to bind arguments to in order to build the history.
  **/
  //====================================================================================================================
  template<typename F, typename T> scannable(F&& f, T&& t) -> scannable<F, std::unwrap_ref_decay_t<T>>;
}
