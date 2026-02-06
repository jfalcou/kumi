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
  //! @brief Creates a kumi::tuple of product_types, each containing `N` consecutive elements from
  //!        `t`. Windows starts at 0 and advance by `1` element each time.
  //!
  //! @tparam N Size of the window to generate
  //! @param  t the tuple to from which to extract the windows
  //! @return A tuple of product_types, each containing `N` consecutive elements of `t`
  //!
  //! @note Windows behaves like overlapping tiles: each inner product_type is a tile over `t`
  //!       starting at index `tile_number`. All the windows are of the same size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t N, product_type> struct windows;
  //!
  //!   template<std::size_t N, product_type T>
  //!   using windows_t = typename windows<N, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::windows
  //!
  //! ## Example
  //! @include doc/tuple/algo/windows.cpp
  //================================================================================================
  template<std::size_t N, concepts::product_type T>
  requires(N > 0 && N <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto windows(T&& t)
  {
    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
      return kumi::generate<size_v<T> - N + 1>(
        [&](auto idx) { return kumi::extract(KUMI_FWD(t), kumi::index<idx>, kumi::index<idx + N>); });
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Creates a kumi::tuple of product_types, each containing `N` consecutive elements from
  //!        `t`. Chunks starts at 0 and advance by `N` element each time.
  //!
  //! @tparam N Size of the chunks to generate
  //! @param  t the tuple to from which to extract the chunks
  //! @return A tuple of product_types, each containing `N` consecutive elements of `t`
  //!
  //! @note Chunks behaves like paving tiles: each inner product_type is a tile over `t`
  //!       starting at index `chunk_size * tile_number + 1`. The last chunk will be smaller if the
  //!       size of the tuple is not a multiple of the chunk size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t N, product_type> struct chunks;
  //!
  //!   template<std::size_t N, product_type T>
  //!   using chunks_t = typename chunks<N, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::chunks
  //!
  //! ## Example
  //! @include doc/tuple/algo/chunks.cpp
  //================================================================================================
  template<std::size_t N, concepts::product_type T>
  requires(N > 0 && N <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto chunks(T&& t)
  {
    constexpr auto nb = (size_v<T> + N - 1) / N;
    constexpr auto sz = size_v<T>;

    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
      return kumi::generate<nb>([&](auto idx) {
        constexpr auto chk_sz = (idx + 1) * N > sz ? sz - idx * N : N;
        constexpr auto chk_id = idx * N;
        return kumi::extract(KUMI_FWD(t), kumi::index<chk_id>, kumi::index<chk_id + chk_sz>);
      });
  }

  namespace result
  {
    template<std::size_t N, kumi::concepts::product_type T> struct windows
    {
      using type = decltype(kumi::windows<N>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T> struct chunks
    {
      using type = decltype(kumi::chunks<N>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T> using windows_t = typename windows<N, T>::type;

    template<std::size_t N, kumi::concepts::product_type T> using chunks_t = typename chunks<N, T>::type;
  }
}
