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
  //! @ingroup generators
  //! @brief Creates a kumi::tuple containing `N` copies of `v`.
  //!
  //! @tparam N Number of replications
  //! @param  v Value to replicate
  //! @return A tuple containing `N` copy of `v`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t N, typename T> struct fill;
  //!
  //!   template<std::size_t N, typename T>
  //!   using fill_t = typename fill<N, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fill
  //!
  //! ## Example
  //! @include doc/fill.cpp
  //================================================================================================
  template<std::size_t N, typename T> [[nodiscard]] KUMI_ABI constexpr auto fill(T const& v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      auto eval = [](auto, auto const& vv) { return vv; };
      return kumi::tuple{eval(index<I>, v)...};
    }(std::make_index_sequence<N>{});
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Creates a kumi::tuple containing `N` applications of the `f` Callable.
  //!
  //! @tparam N Number of replications
  //! @param  f Callable to apply
  //! @return A tuple containing `N` applications of `f`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t N, typename Function> struct generate;
  //!
  //!   template<std::size_t N, typename Function>
  //!   using generate_t = typename generate<N, Function>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::generate
  //!
  //! ## Example
  //! @include doc/generate.cpp
  //================================================================================================
  template<std::size_t N, typename Function> 
  [[nodiscard]] KUMI_ABI constexpr auto generate(Function const& f) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return kumi::tuple{f(index<I>)...};
    }(std::make_index_sequence<N>{});
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Creates a kumi::tuple containing an increasing ramp of values.
  //!
  //! @tparam N Number of replications
  //! @param  v Seed value
  //! @return A tuple containing `{v, v + 1, ..., v + N-1}`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t N, typename T> struct iota;
  //!
  //!   template<std::size_t N, typename T>
  //!   using iota_t = typename iota<N, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::iota
  //!
  //! ## Example
  //! @include doc/iota.cpp
  //================================================================================================
  template<std::size_t N, typename T> [[nodiscard]] KUMI_ABI constexpr auto iota(T v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return kumi::tuple{static_cast<T>(v+I)...};
    }(std::make_index_sequence<N>{});
  }

  namespace result
  {

    template<std::size_t N, typename T> struct fill
    {
      using type = decltype( kumi::fill<N>( std::declval<T>() ) );
    };

    template<std::size_t N, typename Function> struct generate
    {
      using type = decltype( kumi::generate<N>( std::declval<Function>() ) );
    };

    template<std::size_t N, typename T> struct iota
    {
      using type = decltype( kumi::iota<N>( std::declval<T>() ) );
    };

    template<std::size_t N, typename T>
    using fill_t = typename fill<N,T>::type;

    template<std::size_t N, typename Function>
    using generate_t = typename generate<N,Function>::type;

    template<std::size_t N, typename T>
    using iota_t = typename iota<N,T>::type;
  }
}
