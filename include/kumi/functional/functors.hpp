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
  struct identity_t
  {
    template<typename T> KUMI_ABI constexpr T&& operator()(T&& t) const noexcept { return KUMI_FWD(t); }
  };

  inline constexpr identity_t identity{};

  struct builder_t
  {
    template<typename T, std::size_t... I> KUMI_ABI static consteval auto type(T&&, std::index_sequence<I...>)
    {
      return kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>{};
    }

    template<typename T>
    using type_t =
      decltype(kumi::function::builder_t::type(std::declval<T>(), std::make_index_sequence<kumi::size_v<T>>{}));

    template<kumi::concepts::product_type T, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      using res_t = kumi::builder_make_t<T, kumi::element_t<I, T>...>;
      return res_t{get<I>(KUMI_FWD(t))...};
    }

    template<typename T, std::size_t N, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, std::integral_constant<std::size_t, N>, std::index_sequence<I...>) const
    {
      using U = type_t<T>;
      using res_t = kumi::builder_make_t<U, kumi::element_t<N, kumi::element_t<I, T>>...>;
      return res_t{get<N>(get<I>(KUMI_FWD(t)))...};
    }

    template<typename T, std::size_t... E, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<E...>, std::index_sequence<I...>) const
    {
      using U = type_t<T>;
      using res_t = kumi::builder_make_t<U, kumi::element_t<E, kumi::element_t<I, T>>...>;
      return res_t{get<E>(get<I>(KUMI_FWD(t)))...};
    }
  };

  inline constexpr builder_t builder{};
}
