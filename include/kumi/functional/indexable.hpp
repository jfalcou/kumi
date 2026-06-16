//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the cartesian product operation.

    ## Callable object
    @code
      inline constexpr cartesian_product_t cartesian_producer{};
    @endcode
  **/
  //====================================================================================================================
  struct cartesian_product_t
  {
    template<std::size_t... H, std::size_t... S>
    KUMI_ABI consteval auto operator()(std::index_sequence<H...>, kumi::index_t<S>...) const noexcept
    {
      return kumi::projection_map{kumi::_::digits(kumi::_::unflatten_index, std::make_index_sequence<sizeof...(S)>{},
                                                  std::index_sequence<H, S...>{})...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the concatenation operation.

    ## Callable object
    @code
      inline constexpr cat_t concatenater{};
    @endcode
  **/
  //====================================================================================================================
  struct cat_t
  {
    template<std::size_t... Sizes> KUMI_ABI consteval auto operator()(std::index_sequence<Sizes...>) const noexcept
    {
      constexpr auto N = (Sizes + ... + 0ULL);
      constexpr auto Ids = std::index_sequence<Sizes...>{};

      return kumi::projection_map{kumi::_::digits(kumi::_::container_of_index, std::make_index_sequence<N>{}, Ids),
                                  kumi::_::digits(kumi::_::element_of_index, std::make_index_sequence<N>{}, Ids)};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the extraction operation.

    ## Callable object
    @code
      inline constexpr extract_t extractor{};
    @endcode
  **/
  //====================================================================================================================
  struct extract_t
  {
    template<std::size_t B, std::size_t E, std::size_t... I>
    KUMI_ABI consteval auto operator()(std::integral_constant<std::size_t, B>,
                                       std::integral_constant<std::size_t, E>,
                                       std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<(I < B ? I : (I + (E - B)))...>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the rotation operation.

    ## Callable object
    @code
      inline constexpr rotate_t rotater{};
    @endcode
  **/
  //====================================================================================================================
  struct rotate_t
  {
    template<std::size_t... S, std::size_t R>
    KUMI_ABI consteval auto operator()(std::index_sequence<S...>, kumi::index_t<R>) const noexcept
    {
      return std::index_sequence<((S + R) % sizeof...(S))...>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the reduction operation.

    ## Callable object
    @code
      inline constexpr reduce_t reducer{};
    @endcode
  **/
  //====================================================================================================================
  struct reduce_t
  {
    template<std::size_t... I, std::size_t N>
    KUMI_ABI consteval auto operator()(std::index_sequence<I...>, kumi::index_t<N>) const noexcept
    {
      return kumi::projection_map{std::index_sequence<(2 * I)...>{}, std::index_sequence<(2 * I + 1)...>{},
                                  kumi::index<N>};
    }
  };

  struct repeat_t
  {
    template<std::size_t E, std::size_t... I>
    KUMI_ABI consteval auto operator()(kumi::index_t<E>, std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<(I - I + E)...>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the reverse operation.

    ## Callable object
    @code
      inline constexpr reverse_t reverser{};
    @endcode
  **/
  //====================================================================================================================
  struct reverse_t
  {
    template<std::size_t... I> KUMI_ABI consteval auto operator()(std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<(sizeof...(I) - 1 - I)...>{};
    }
  };

  struct shift_t
  {
    template<std::size_t N, std::size_t... I>
    KUMI_ABI consteval auto operator()(std::integral_constant<std::size_t, N>, std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<I + N...>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the split operation.

    ## Callable object
    @code
      inline constexpr split_t splitter{};
    @endcode
  **/
  //====================================================================================================================
  struct split_t
  {
    template<std::size_t N, std::size_t... S>
    KUMI_ABI consteval auto operator()(kumi::index_t<N>, std::index_sequence<S...>) const noexcept
    {
      return kumi::projection_map{std::make_index_sequence<N>{}, std::index_sequence<(S + N)...>{}};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the tiling operation.

    ## Callable object
    @code
      inline constexpr tile_t tiler{};
    @endcode
  **/
  //====================================================================================================================
  struct tile_t
  {
    template<std::size_t Sz, std::size_t Extent, std::size_t Stride, std::size_t... Blocks>
    KUMI_ABI consteval auto operator()(kumi::index_t<Sz>,
                                       kumi::index_t<Extent>,
                                       kumi::index_t<Stride>,
                                       std::index_sequence<Blocks...>) const noexcept
    {
      using blocks = std::index_sequence<kumi::_::block_size(Blocks, Stride, Extent, Sz)...>;
      using offsets = std::index_sequence<(Blocks * Stride)...>;
      return kumi::projection_map{blocks{}, offsets{}};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Logic provider to compute the index map associated to the zip operation.

    ## Callable object
    @code
      inline constexpr zip_t zipper{};
    @endcode
  **/
  //====================================================================================================================
  struct zip_t
  {
    template<std::size_t Count, std::size_t Size>
    KUMI_ABI consteval auto operator()(kumi::index_t<Count>, kumi::index_t<Size>) const noexcept
    {
      using tuples = std::make_index_sequence<Count>;
      using elements = std::make_index_sequence<Size>;
      return kumi::projection_map{tuples{}, elements{}};
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the cartesian product operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::cartesian_product_t cartesian_producer{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the concatenation operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::cat_t concatenater{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the extraction operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::extract_t extractor{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the rotation operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::rotate_t rotater{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the reduction operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::reduce_t reducer{};

  inline constexpr kumi::function::repeat_t repeater{};

  inline constexpr kumi::function::shift_t shifter{};
  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the split operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::split_t splitter{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the reverse operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::reverse_t reverser{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the tiling operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::tile_t tiler{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the zip operation.
  **/
  //====================================================================================================================
  inline constexpr kumi::function::zip_t zipper{};
}
