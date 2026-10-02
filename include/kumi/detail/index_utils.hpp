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

  //====================================================================================================================
  consteval std::size_t max(std::same_as<std::size_t> auto... sizes) noexcept
  {
    std::size_t result{};
    return ((result = (result > sizes ? result : sizes)), ...);
  }

  //====================================================================================================================
  consteval std::size_t nth_pos(std::size_t I, std::same_as<bool> auto... b) noexcept
  {
    std::size_t seen{}, i{}, idx{};
    ((b ? (seen++ == I ? (i = idx, idx++) : idx++) : idx++), ...);
    return i;
  }

  //====================================================================================================================
  // Pure fold: for the type at position J, stride is the product of the
  // sizes of everything before it (first tuple = fastest-varying).
  template<std::size_t... I, std::size_t... J>
  consteval std::size_t stride_at(std::size_t Pos, std::index_sequence<I...>, std::index_sequence<J...>) noexcept
  {
    return ((J < Pos ? I : std::size_t{1}) * ...);
  }
}
