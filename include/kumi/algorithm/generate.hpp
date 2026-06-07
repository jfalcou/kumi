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
  template<std::size_t N> struct generate_t
  {
    template<typename Function> [[nodiscard]] KUMI_ABI constexpr auto operator()(Function const& f) const noexcept
    {
      if constexpr (N == 0) return kumi::tuple{};
      else return this->generate_(f, std::make_index_sequence<N>{});
    }

    template<typename F, std::size_t... I>
    KUMI_ABI constexpr decltype(auto) generate_(F&& f, std::index_sequence<I...>) const noexcept
    {
      if constexpr (N == 0) return kumi::tuple{};
      else return kumi::tuple{kumi::invoke(KUMI_FWD(f), kumi::index<I>)...};
    }
  };

  template<std::size_t N> struct fill_t : private kumi::generate_t<N>
  {
    template<typename T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T const& v) const noexcept
    {
      return this->generate_([&](auto) { return v; }, std::make_index_sequence<N>{});
    }
  };

  template<std::size_t N> struct iota_t : private kumi::generate_t<N>
  {
    template<typename T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T v) const noexcept
    {
      return this->generate_([&](auto I) { return static_cast<T>(v + I); }, std::make_index_sequence<N>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var generate
    @brief Callable object creating a kumi::tuple containing `N` applications of the `f` Callable.

    @qualifier nodiscard inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/generate.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function>
      constexpr auto generate<N>(Function && f) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Number of replications

    @subgroupheader{Parameters}

      - `f`: Callable object to apply

    @subgroupheader{Return value}

      * A tuple containing `N` applications of `f`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<std::size_t N, typename Function> struct generate;

      template<std::size_t N, typename Function>
      using generate_t = typename generate<N, Function>::type;
    }
    @endcode

    Computes the return type of a call to kumi::generate

    @groupheader{Example}

    @godbolt{doc/tuple/algo/generate.cpp}

  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr generate_t<N> generate{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var fill
    @brief Callable object creating a kumi::tuple containing `N` copies of `v`.

    @qualifier nodiscard inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/generate.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename V>
      constexpr auto fill<N>(V const& v) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Number of replications

    @subgroupheader{Parameters}

      - `v`: Value to replicate

    @subgroupheader{Return value}

      * A tuple containing `N` copies of `v`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<std::size_t N, typename T> struct fill;

      template<std::size_t N, typename T>
      using fill_t = typename fill<N, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::fill

    @groupheader{Example}

    @godbolt{doc/tuple/algo/fill.cpp}

  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr fill_t<N> fill{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var iota
    @brief Callable object creating a kumi::tuple containing an increasing ramp of values.

    @qualifier nodiscard inline constexpr noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/generate.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename V>
      constexpr auto iota<N>(V v) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Number of replications

    @subgroupheader{Parameters}

      - `v`: Seed value

    @subgroupheader{Return value}

      * A tuple containing `N` copies of `{v, v + 1, ..., v + N-1}`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<std::size_t N, typename T> struct iota;

      template<std::size_t N, typename T>
      using iota_t = typename iota<N, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::iota

    @groupheader{Example}

    @godbolt{doc/tuple/algo/iota.cpp}

  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr iota_t<N> iota{};

  namespace result
  {

    template<std::size_t N, typename T> struct fill
    {
      using type = decltype(kumi::fill<N>(std::declval<T>()));
    };

    template<std::size_t N, typename Function> struct generate
    {
      using type = decltype(kumi::generate<N>(std::declval<Function>()));
    };

    template<std::size_t N, typename T> struct iota
    {
      using type = decltype(kumi::iota<N>(std::declval<T>()));
    };

    template<std::size_t N, typename T> using fill_t = typename kumi::result::fill<N, T>::type;

    template<std::size_t N, typename Function> using generate_t = typename kumi::result::generate<N, Function>::type;

    template<std::size_t N, typename T> using iota_t = typename kumi::result::iota<N, T>::type;
  }
}
