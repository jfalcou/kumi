//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::_
{
  //====================================================================================================================
  struct tile_
  {
    template<std::size_t Sz, std::size_t Extent, std::size_t Stride>
    KUMI_ABI consteval auto operator()(index_t<Sz>, index_t<Extent>, index_t<Stride>) const noexcept
    {
      constexpr std::size_t nb_blocks = (Sz <= Extent) ? 1 : (Sz - Extent + Stride - 1) / Stride + 1;

      constexpr auto block_size = [](std::size_t I) {
        std::size_t s = I * Stride;
        return (s < Sz) ? ((s + Extent > Sz) ? (Sz - s) : Extent) : 0;
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        struct
        {
          using b = std::index_sequence<block_size(I)...>;
          using e = std::index_sequence<(I * Stride)...>;
          b blocks{};
          e offset{};
        } that{};
        return that;
      }(std::make_index_sequence<nb_blocks>{});
    }
  };

  //====================================================================================================================
  struct rotate_
  {
    template<std::size_t S, std::size_t R> KUMI_ABI consteval auto operator()(index_t<S>, index_t<R>) const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return std::index_sequence<(I + R) % S...>{};
      }(std::make_index_sequence<S>{});
    }
  };

  //====================================================================================================================
  struct reduce_
  {
    template<std::size_t N> KUMI_ABI consteval auto operator()(index_t<N>) const noexcept
    {
      constexpr std::size_t half = N / 2;
      constexpr std::size_t remainder = N % 2;

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return projection_map{indexes(index<2 * I>, index<2 * I + 1>)..., index<remainder>};
      }(std::make_index_sequence<half>{});
    }
  };

  inline constexpr rotate_ rotator{};
  inline constexpr reduce_ reducer{};
  inline constexpr tile_ tiler{};
}
