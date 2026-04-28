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
  KUMI_ABI consteval std::size_t min(std::same_as<std::size_t> auto... sizes)
  {
    std::size_t result = std::size_t(-1);
    return ((result = (result < sizes ? result : sizes)), ...);
  }

  KUMI_ABI consteval std::size_t max(std::same_as<std::size_t> auto... sizes)
  {
    std::size_t result{};
    return ((result = (result > sizes ? result : sizes)), ...);
  }

  //====================================================================================================================
  struct container_of_index_t
  {
    KUMI_ABI consteval std::size_t operator()(std::size_t i, std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t t{}, sum{};
      ((t += (i >= (sum += sizes))), ...);
      return t;
    }
  };

  //====================================================================================================================
  struct element_of_index_t
  {
    KUMI_ABI consteval std::size_t operator()(std::size_t i, std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t sum{}, offset{};
      ((offset = (i >= (sum += sizes) ? sum : offset)), ...);
      return i - offset;
    }
  };

  //====================================================================================================================
  struct unflatten_index_t
  {
    KUMI_ABI consteval std::size_t operator()(std::size_t dim,
                                              std::size_t v,
                                              std::same_as<std::size_t> auto... sizes) const noexcept
    {
      std::size_t div = 1, curr_dim = 0, result = 0;
      (((curr_dim == dim ? (result = (v / div) % sizes) : 0), div *= sizes, curr_dim++), ...);
      return result;
    }
  };

  //====================================================================================================================
  KUMI_ABI consteval std::size_t block_size(std::size_t I, std::size_t Stride, std::size_t Extent, std::size_t Size)
  {
    std::size_t s = I * Stride;
    return (s < Size) ? ((s + Extent > Size) ? (Size - s) : Extent) : 0;
  }

  //====================================================================================================================
  struct digits_
  {
    template<typename F, std::size_t Base, std::size_t... Is>
    KUMI_ABI consteval auto operator()(F func,
                                       std::integral_constant<std::size_t, Base>,
                                       std::index_sequence<Is...>) const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return std::index_sequence<func(I, Is...)...>{};
      }(std::make_index_sequence<Base>{});
    }
  };

  //====================================================================================================================
  template<typename T, auto> struct repeat
  {
    using type = T;
  };

  template<typename T, auto I> using repeat_t = typename kumi::_::repeat<T, I>::type;

  template<typename T, auto N> struct as_homogeneous
  {
    template<std::size_t... I>
    static consteval auto homogeneify(std::index_sequence<I...>) -> tuple<kumi::_::repeat_t<T, I>...>;

    using type = std::remove_cvref_t<decltype(homogeneify(std::make_index_sequence<N>{}))>;
  };

  template<typename T, auto N> using as_homogeneous_t = typename kumi::_::as_homogeneous<T, N>::type;

  inline constexpr kumi::_::container_of_index_t container_of_index{};
  inline constexpr kumi::_::element_of_index_t element_of_index{};
  inline constexpr kumi::_::unflatten_index_t unflatten_index{};
  inline constexpr kumi::_::digits_ digits{};
}
