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

  template<typename T, std::size_t... B, std::size_t... E>
  KUMI_ABI constexpr auto tiles_(kumi::adl_tag_t, T&& t, std::index_sequence<B...>, std::index_sequence<E...>)
  {
    return kumi::tuple{
      kumi::function::builder(KUMI_FWD(t), kumi::function::shifter(std::integral_constant<std::size_t, E>{},
                                                                   std::make_index_sequence<B>{}))...};
  }

  template<std::size_t N, std::size_t O> struct tiles_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      static_assert(N > 0 && N <= kumi::size_v<T>, "[KUMI] - Invalid tile size");

      if constexpr (N == kumi::size_v<T>) return kumi::make_tuple(t);
      else
      {
        constexpr auto bs = std::integral_constant<std::size_t, kumi::_::nb_blocks(kumi::size_v<T>, O, N)>{};
        constexpr auto proj = kumi::function::tiler(kumi::index<kumi::size_v<T>>, kumi::index<N>, kumi::index<O>,
                                                    std::make_index_sequence<bs>{});

        return tiles_(kumi::adl_tag, KUMI_FWD(t), get<0>(proj), get<1>(proj));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var tiles
    @brief Callable object creating a tuple of product types, each containing `N` consecutive elements from `t`.
            Tiles starts at 0 and advance by `O` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Tiles is the most general form of tiling each inner product_type is a tile over `t`
          starting at index `tile_size * tile_number + 1`. The last tile will be smaller if the
          size of the product type is not a multiple of the tile size.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/apply.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t N, std::size_t O, product_type T>
      constexpr auto tiles<N,O>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Size of the tile to generate
      - `O`: Offset from the begening of the previous tile

    @subgroupheader{Parameters}

      - `t`: Product Type from which to extract the tiles

    @subgroupheader{Return value}

      - A tuple of product types, each containing `N` consecutive elements of `t` offset by O

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/tiler.hpp tiles_t

    Computes the return type of a call to kumi::tiles

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/tiles.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/tiles.cpp}
  **/
  //====================================================================================================================
  template<std::size_t N, std::size_t O> inline constexpr tiles_t<N, O> tiles{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var windows
    @brief Callable object creating a tuple of product types, each containing `N` consecutive elements from `t`.
           Windows starts at 0 and advance by `1` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Windows behaves like overlapping tiles: each inner product_type is a tile over `t`
          starting at index `tile_number`. All the windows are of the same size.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/apply.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t N, product_type T>
      constexpr auto windows<N>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Size of the window to generate

    @subgroupheader{Parameters}

      - `t`: Product Type from which to extract the windows

    @subgroupheader{Return value}

      - A tuple of product types, each containing `N` consecutive elements of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/tiler.hpp windows_t

    Computes the return type of a call to kumi::windows

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/windows.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/windows.cpp}
  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr tiles_t<N, 1> windows{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var chunks
    @brief Callable object creating a tuple of product types, each containing `N` consecutive elements from `t`.
            Chunks starts at 0 and advance by `N` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Chunks behaves like paving tiles: each inner product_type is a tile over `t`
          starting at index `chunk_size * tile_number + 1`. The last chunk will be smaller if the
          size of the product_type is not a multiple of the chunk size.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/apply.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t N, product_type T>
      constexpr auto windows<N>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `N`: Size of the chunks to generate

    @subgroupheader{Parameters}

      - `t`: Product Type from which to extract the chunks

    @subgroupheader{Return value}

      - A tuple of product types, each containing `N` consecutive elements of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/tiler.hpp chunks_t

    Computes the return type of a call to kumi::chunks

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/chunks.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/chunks.cpp}
  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr tiles_t<N, N> chunks{};

  namespace result
  {
    //! [tiles_t]
    template<std::size_t N, std::size_t O, kumi::concepts::product_type T> struct tiles
    {
      using type = decltype(kumi::tiles<N, O>(std::declval<T>()));
    };

    template<std::size_t N, std::size_t O, kumi::concepts::product_type T>
    using tiles_t = typename kumi::result::tiles<N, O, T>::type;

    //! [tiles_t]

    //! [windows_t]
    template<std::size_t N, kumi::concepts::product_type T> struct windows
    {
      using type = decltype(kumi::windows<N>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T>
    using windows_t = typename kumi::result::windows<N, T>::type;

    //! [windows_t]

    //! [chunks_t]
    template<std::size_t N, kumi::concepts::product_type T> struct chunks
    {
      using type = decltype(kumi::chunks<N>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T> using chunks_t = typename kumi::result::chunks<N, T>::type;
    //! [chunks_t]
  }
}
