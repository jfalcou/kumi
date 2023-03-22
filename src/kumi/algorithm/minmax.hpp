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
  //! @brief Computes the maximum value all elements of t.
  //! @param t Tuple to inspect
  //! @return The maximum value of  all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> struct max;
  //!
  //!   template<typename T>
  //!   using max_t = typename max<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max.
  //!
  //! ## Example:
  //! @include doc/max.cpp
  //================================================================================================
  template<typename T>
  [[nodiscard]] constexpr auto max(T const& t) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return t;
    else if constexpr( T::size() == 1 )     return get<0>(t);
    else
    {
      auto base = get<0>(t);
      return kumi::fold_left( []<typename U>(auto cur, U u)
                              {
                                return cur > u ? cur : u;
                              }
                            , t, base
                            );
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the maximum value of applications of f to all elements of t.
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The maximum value of f over all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct max;
  //!
  //!   template<typename T, typename F>
  //!   using max_t = typename max<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max.
  //!
  //! ## Example:
  //! @include doc/max.cpp
  //================================================================================================
  template<typename T, typename F>
  [[nodiscard]] constexpr auto max(T const& t, F f) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return f(t);
    else if constexpr( T::size() == 1 )     return f( get<0>(t) );
    else
    {
      auto base = f( get<0>(t) );
      return kumi::fold_left( [f]<typename U>(auto cur, U const& u)
                              {
                                return cur > f(u) ? cur : f(u);
                              }
                            , t, base
                            );
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the maximum value of applications of f to all elements of kumi::flatten_all(t).
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The maximum value of f over all elements of a flattened version of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct max_flat;
  //!
  //!   template<typename T, typename F>
  //!   using max_flat_t = typename max_flat<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max_flat.
  //!
  //! ## Example:
  //! @include doc/max_flat.cpp
  //================================================================================================
  template<typename T, typename F>
  [[nodiscard]] constexpr auto max_flat(T const& t, F f) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return f(t);
    else
    {
      auto flat_t = kumi::flatten_all(t);
      return max(flat_t, f);
    }
  }

  namespace result
  {
    template<typename T, typename F = void> struct max
    {
      using type = decltype( kumi::max( std::declval<T>(), std::declval<F>() ) );
    };

    template<typename T> struct max<T,void>
    {
      using type = decltype( kumi::max( std::declval<T>() ) );
    };

    template<typename T, typename F> struct max_flat
    {
      using type = decltype( kumi::max_flat( std::declval<T>(), std::declval<F>() ) );
    };

    template<typename T, typename F = void> using max_t      = typename max<T,F>::type;
    template<typename T, typename F>        using max_flat_t = typename max_flat<T,F>::type;
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value all elements of t.
  //! @param t Tuple to inspect
  //! @return The minimum value of  all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> struct min;
  //!
  //!   template<typename T>
  //!   using min_t = typename min<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min.
  //!
  //! ## Example:
  //! @include doc/min.cpp
  //================================================================================================
  template<typename T>
  [[nodiscard]] constexpr auto min(T const& t) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return t;
    else if constexpr( T::size() == 1 )     return get<0>(t);
    else
    {
      auto base = get<0>(t);
      return kumi::fold_left( []<typename U>(auto cur, U u)
                              {
                                return cur < u ? cur : u;
                              }
                            , t, base
                            );
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value of applications of f to all elements of t.
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The minimum value of f over all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct min;
  //!
  //!   template<typename T, typename F>
  //!   using min_t = typename min<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min.
  //!
  //! ## Example:
  //! @include doc/min.cpp
  //================================================================================================
  template<typename T, typename F>
  [[nodiscard]] constexpr auto min(T const& t, F f) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return f(t);
    else if constexpr( T::size() == 1 )     return f( get<0>(t) );
    else
    {
      auto base = f( get<0>(t) );
      return kumi::fold_left( [f]<typename U>(auto cur, U const& u)
                              {
                                return cur < f(u) ? cur : f(u);
                              }
                            , t, base
                            );
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value of applications of f to all elements of kumi::flatten_all(t).
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The minimum value of f over all elements of a flattened version of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct min_flat;
  //!
  //!   template<typename T, typename F>
  //!   using min_flat_t = typename min_flat<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min_flat.
  //!
  //! ## Example:
  //! @include doc/min_flat.cpp
  //================================================================================================
  template<typename T, typename F>
  [[nodiscard]] constexpr auto min_flat(T const& t, F f) noexcept
  {
    if constexpr ( !kumi::product_type<T> ) return f(t);
    else
    {
      auto flat_t = kumi::flatten_all(t);
      return min(flat_t, f);
    }
  }

  namespace result
  {
    template<typename T, typename F = void> struct min
    {
      using type = decltype( kumi::min( std::declval<T>(), std::declval<F>() ) );
    };

    template<typename T> struct min<T,void>
    {
      using type = decltype( kumi::min( std::declval<T>() ) );
    };

    template<typename T, typename F> struct min_flat
    {
      using type = decltype( kumi::min_flat( std::declval<T>(), std::declval<F>() ) );
    };

    template<typename T, typename F = void> using min_t      = typename min<T,F>::type;
    template<typename T, typename F>        using min_flat_t = typename min_flat<T,F>::type;
  }
}
