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
    @brief    Creates a tuple of product types, each containing `N` consecutive elements from `t`. Tiles starts at
              0 and advance by `O` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @tparam N Size of the tile to generate
    @tparam O Offset from the begening of the previous tile
    @param  t the product type from which to extract the tiles 
    @return A tuple of product types, each containing `N` consecutive elements of `t` offset by O

    @note Tiles is the most general form of tiling each inner product_type is a tile over `t`
          starting at index `tile_size * tile_number + 1`. The last tile will be smaller if the
          size of the product type is not a multiple of the tile size.
    
    ## Helper type
    @code
    namespace kumi::result
    {
      template<std::size_t N, std::size_t O, product_type T> struct tiles;

      template<std::size_t N, std::size_t O, product_type T>
      using tiles_t = typename tiles<N, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::tiles

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/tiles.cpp
    ### Record:
    @include doc/record/algo/tiles.cpp
  **/
  //====================================================================================================================
  template<std::size_t N, std::size_t O, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto tiles(T&& t)
  {
    static_assert(N > 0 && N <= size_v<T>, "[KUMI] - Invalid tile size");

    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
    {
      constexpr auto proj = _::tiler(index<size_v<T>>, index<N>, index<O>);
      auto const build = [&]<std::size_t... J>(auto Off, std::index_sequence<J...>) {
        using type = builder_make_t<T, element_t<Off + J, T>...>;
        return type{get<Off + J>(KUMI_FWD(t))...};
      };

      return [&]<std::size_t... B, std::size_t... E>(std::index_sequence<B...>, std::index_sequence<E...>) {
        return tuple{build(index<E>, std::make_index_sequence<B>{})...};
      }(proj.blocks, proj.offset);
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Creates a tuple of product types, each containing `N` consecutive elements from `t`. Windows starts at
              0 and advance by `1` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @tparam N Size of the window to generate
    @param  t the product type from which to extract the windows
    @return A tuple of product types, each containing `N` consecutive elements of `t`

    @note Windows behaves like overlapping tiles: each inner product_type is a tile over `t`
          starting at index `tile_number`. All the windows are of the same size.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<std::size_t N, product_type T> struct windows;

      template<std::size_t N, product_type T>
      using windows_t = typename windows<N, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::windows

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/windows.cpp
    ### Record:
    @include doc/record/algo/windows.cpp
  **/
  //====================================================================================================================
  template<std::size_t N, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto windows(T&& t)
  {
    static_assert(N > 0 && N <= size_v<T>, "[KUMI] - Invalid tile size");
    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
    {
      constexpr auto proj = _::tiler(index<size_v<T>>, index<N>, index<1>);
      auto const build = [&]<std::size_t... J>(auto O, std::index_sequence<J...>) {
        using type = builder_make_t<T, element_t<O + J, T>...>;
        return type{get<O + J>(KUMI_FWD(t))...};
      };

      return [&]<std::size_t... B, std::size_t... E>(std::index_sequence<B...>, std::index_sequence<E...>) {
        return tuple{build(index<E>, std::make_index_sequence<B>{})...};
      }(proj.blocks, proj.offset);
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Creates a tuple of product types, each containing `N` consecutive elements from `t`. Chunks starts at
              0 and advance by `N` element each time.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @tparam N Size of the chunks to generate
    @param  t the product type from which to extract the chunks
    @return A tuple of product types, each containing `N` consecutive elements of `t`

    @note Chunks behaves like paving tiles: each inner product_type is a tile over `t`
          starting at index `chunk_size * tile_number + 1`. The last chunk will be smaller if the
          size of the product_type is not a multiple of the chunk size.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<std::size_t N, product_type T> struct chunks;

      template<std::size_t N, product_type T>
      using chunks_t = typename chunks<N, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::chunks

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/chunks.cpp
    ### Record:
    @include doc/record/algo/chunks.cpp
  **/
  //====================================================================================================================
  template<std::size_t N, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto chunks(T&& t)
  {
    static_assert(N > 0 && N <= size_v<T>, "[KUMI] - Invalid tile size");

    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
    {
      constexpr auto proj = _::tiler(index<size_v<T>>, index<N>, index<N>);
      auto const build = [&]<std::size_t... J>(auto O, std::index_sequence<J...>) {
        using type = builder_make_t<T, element_t<O + J, T>...>;
        return type{get<O + J>(KUMI_FWD(t))...};
      };

      return [&]<std::size_t... B, std::size_t... E>(std::index_sequence<B...>, std::index_sequence<E...>) {
        return tuple{build(index<E>, std::make_index_sequence<B>{})...};
      }(proj.blocks, proj.offset);
    }
  }

  namespace result
  {
    template<std::size_t N, std::size_t O, kumi::concepts::product_type T> struct tiles
    {
      using type = decltype(kumi::tiles<N, O>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T> struct windows
    {
      using type = decltype(kumi::windows<N>(std::declval<T>()));
    };

    template<std::size_t N, kumi::concepts::product_type T> struct chunks
    {
      using type = decltype(kumi::chunks<N>(std::declval<T>()));
    };

    template<std::size_t N, std::size_t O, kumi::concepts::product_type T>
    using tiles_t = typename tiles<N, O, T>::type;

    template<std::size_t N, kumi::concepts::product_type T> using windows_t = typename windows<N, T>::type;

    template<std::size_t N, kumi::concepts::product_type T> using chunks_t = typename chunks<N, T>::type;
  }
}
