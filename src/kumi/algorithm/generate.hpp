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
  namespace _
  {
    template<std::size_t N, typename T>
    constexpr auto const& eval(T const& v) noexcept { return v; }
  }

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
  //!   template<std::size_t N, typename T> struct generate;
  //!
  //!   template<std::size_t N, typename T>
  //!   using generate_t = typename generate<N, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::generate
  //!
  //! ## Example
  //! @include doc/generate.cpp
  //================================================================================================
  template<std::size_t N, typename T> [[nodiscard]] constexpr auto generate(T const& v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return kumi::tuple{_::eval<I>(v)...};
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
  template<std::size_t N, typename T> [[nodiscard]] constexpr auto iota(T v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return kumi::tuple{T(v+I)...};
    }(std::make_index_sequence<N>{});
  }

  namespace result
  {
    template<std::size_t N, typename T> struct generate
    {
      using type = decltype( kumi::generate<N>( std::declval<T>() ) );
    };

    template<std::size_t N, typename T> struct iota
    {
      using type = decltype( kumi::iota<N>( std::declval<T>() ) );
    };

    template<std::size_t N, typename T>
    using generate_t = typename generate<N,T>::type;

    template<std::size_t N, typename T>
    using iota_t = typename iota<N,T>::type;
  }
}
