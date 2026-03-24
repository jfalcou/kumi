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
  struct cartesian_product_t
  {
    template<std::size_t H, std::size_t... S>
    KUMI_ABI consteval auto operator()(index_t<H>, index_t<S>...) const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using t =
          kumi::tuple<decltype(_::digits(_::unflatten_index, index<sizeof...(S)>, std::index_sequence<I, S...>{}))...>;
        return t{};
      }(std::make_index_sequence<H>{});
    }
  };

  struct cat_t
  {
    template<std::size_t... Sizes> KUMI_ABI consteval auto operator()(std::index_sequence<Sizes...>) const noexcept
    {
      constexpr auto N = (Sizes + ... + 0ULL);
      using t = decltype(_::digits(_::container_of_index, index<N>, std::index_sequence<Sizes...>{}));
      using e = decltype(_::digits(_::element_of_index, index<N>, std::index_sequence<Sizes...>{}));

      struct
      {
        t tpl{};
        e elt{};
      } that{};

      return that;
    }
  };

  struct flatten_t : cat_t
  {
    using parent = cat_t;
    using parent::operator();
  };

  struct rotate_t
  {
    template<std::size_t S, std::size_t R> KUMI_ABI consteval auto operator()(index_t<S>, index_t<R>) const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return std::index_sequence<(I + R) % S...>{};
      }(std::make_index_sequence<S>{});
    }
  };

  struct reduce_t
  {
    template<std::size_t N> KUMI_ABI consteval auto operator()(index_t<N>) const noexcept
    {
      constexpr std::size_t half = N / 2;
      constexpr std::size_t remainder = N % 2;

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using f = std::index_sequence<(2 * I)...>;
        using s = std::index_sequence<(2 * I + 1)...>;
        struct
        {
          f first{};
          s second{};
          index_t<remainder> rest;
        } that{};
        return that;
      }(std::make_index_sequence<half>{});
    }
  };

  struct split_t
  {
    template<std::size_t N, std::size_t Sz> KUMI_ABI consteval auto operator()(index_t<N>, index_t<Sz>) const noexcept
    {
      using t1 = decltype(std::make_index_sequence<N>{});
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using t2 = std::index_sequence<(I + N)...>;
        struct
        {
          t1 first{};
          t2 second{};
        } that{};
        return that;
      }(std::make_index_sequence<Sz - N>{});
    }
  };

  struct tile_t
  {
    template<std::size_t Sz, std::size_t Extent, std::size_t Stride>
    KUMI_ABI consteval auto operator()(index_t<Sz>, index_t<Extent>, index_t<Stride>) const noexcept
    {
      constexpr std::size_t nb_blocks = (Sz <= Extent) ? 1 : (Sz - Extent + Stride - 1) / Stride + 1;

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using b = std::index_sequence<_::block_size(I, Stride, Extent, Sz)...>;
        using o = std::index_sequence<(I * Stride)...>;
        struct
        {
          b blocks{};
          o offset{};
        } that{};
        return that;
      }(std::make_index_sequence<nb_blocks>{});
    }
  };

  struct zip_t
  {
    template<std::size_t Count, std::size_t Size>
    KUMI_ABI consteval auto operator()(index_t<Count>, index_t<Size>) const noexcept
    {
      using t = decltype(std::make_index_sequence<Count>{});
      using e = decltype(std::make_index_sequence<Size>{});

      struct
      {
        t tpl{};
        e elt{};
      } that{};

      return that;
    }
  };

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the cartesian product operation.
  **/
  //====================================================================================================================
  inline constexpr cartesian_product_t cartesian_producer{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the concatenation operation.
  **/
  //====================================================================================================================
  inline constexpr cat_t concatenater{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the flattening operation.
  **/
  //====================================================================================================================
  inline constexpr flatten_t flattener{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the rotation operation.
  **/
  //====================================================================================================================
  inline constexpr rotate_t rotater{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the reduction operation.
  **/
  //====================================================================================================================
  inline constexpr reduce_t reducer{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the split operation.
  **/
  //====================================================================================================================
  inline constexpr split_t splitter{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the tiling operation.
  **/
  //====================================================================================================================
  inline constexpr tile_t tiler{};

  //====================================================================================================================
  /**
    @ingroup functional
    @brief  Callable object computing the index map associated to the zip operation.
  **/
  //====================================================================================================================
  inline constexpr zip_t zipper{};
}
