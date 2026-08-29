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
  consteval std::size_t min(std::same_as<std::size_t> auto... sizes) noexcept
  {
    std::size_t result = std::size_t(-1);
    return ((result = (result < sizes ? result : sizes)), ...);
  }

  consteval std::size_t max(std::same_as<std::size_t> auto... sizes) noexcept
  {
    std::size_t result{};
    return ((result = (result > sizes ? result : sizes)), ...);
  }

  consteval std::size_t nth_pos(std::size_t I, std::same_as<bool> auto... b) noexcept
  {
    std::size_t seen{}, i{}, idx{};
    ((b ? (seen++ == I ? (i = idx, idx++) : idx++) : idx++), ...);
    return i;
  }

  //====================================================================================================================
  struct container_of_index_t
  {
    consteval std::size_t operator()(std::size_t i, std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t t{}, sum{};
      ((t += (i >= (sum += sizes))), ...);
      return t;
    }
  } inline constexpr container_of_index{};

  //====================================================================================================================
  struct element_of_index_t
  {
    consteval std::size_t operator()(std::size_t i, std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t sum{}, offset{};
      ((offset = (i >= (sum += sizes) ? sum : offset)), ...);
      return i - offset;
    }
  } inline constexpr element_of_index{};

  //====================================================================================================================
  struct unflatten_index_t
  {
    consteval std::size_t operator()(std::size_t dim,
                                     std::size_t v,
                                     std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t div = 1, curr_dim = 0, result = 0;
      (((curr_dim == dim ? (result = (v / div) % sizes) : 0), div *= sizes, curr_dim++), ...);
      return result;
    }
  } inline constexpr unflatten_index{};

  //====================================================================================================================
  consteval std::size_t nb_blocks(std::size_t Sz, std::size_t Stride, std::size_t Extent) noexcept
  {
    return (Sz <= Extent) ? 1 : (Sz - Extent + Stride - 1) / Stride + 1;
  }

  //====================================================================================================================
  consteval std::size_t block_size(std::size_t I, std::size_t Stride, std::size_t Extent, std::size_t Size) noexcept
  {
    std::size_t s = I * Stride;
    return (s < Size) ? ((s + Extent > Size) ? (Size - s) : Extent) : 0;
  }

  //====================================================================================================================
  template<typename F, std::size_t... Base, std::size_t... Is>
  consteval auto make_digits(F func, std::index_sequence<Base...>, std::index_sequence<Is...>) noexcept
  {
    if constexpr (sizeof...(Base) == 0) return std::make_index_sequence<0>{};
    else return std::index_sequence<func(Base, Is...)...>{};
  }

  //====================================================================================================================
  template<typename T, auto> using repeat_t = T;

  template<typename T, std::size_t... I>
  kumi::tuple<kumi::_::repeat_t<T, I>...> make_homogeneous(std::index_sequence<I...>);

  template<typename T, std::size_t N>
  using as_homogeneous_t = decltype(make_homogeneous<T>(std::make_index_sequence<N>{}));
}
