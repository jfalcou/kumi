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
  namespace function
  {
    struct identity_t
    {
      template<typename T> KUMI_ABI constexpr T&& operator()(T&& t) const noexcept { return KUMI_FWD(t); }
    };

    KUMI_VARIABLE_ABI constexpr identity_t identity;

    struct max_t
    {
      template<typename T, typename U>
      KUMI_ABI constexpr decltype(auto) operator()(T&& t, U&& u) const noexcept(noexcept(KUMI_FWD(t) > KUMI_FWD(u)))
      requires requires { KUMI_FWD(t) > KUMI_FWD(u); }
      {
        return KUMI_FWD(t) > KUMI_FWD(u) ? KUMI_FWD(t) : KUMI_FWD(u);
      }
    };

    KUMI_VARIABLE_ABI constexpr max_t max;

    struct min_t
    {
      template<typename T, typename U>
      KUMI_ABI constexpr decltype(auto) operator()(T&& t, U&& u) const noexcept(noexcept(KUMI_FWD(t) < KUMI_FWD(u)))
      requires requires { KUMI_FWD(t) < KUMI_FWD(u); }
      {
        return KUMI_FWD(t) < KUMI_FWD(u) ? KUMI_FWD(t) : KUMI_FWD(u);
      }
    };

    KUMI_VARIABLE_ABI constexpr min_t min;

    struct adressof_t
    {
      template<typename T>
      requires(std::is_object_v<T>)
      KUMI_ABI constexpr T* operator()(T& t) const noexcept(noexcept(&t))
      {
        // This is invalid for overloaded operator&
        return &t;
      }

      template<typename T> constexpr T const* operator()(T const&&) = delete;
    };

    KUMI_VARIABLE_ABI constexpr adressof_t adressof;
  }

  namespace _
  {
    template<typename T, typename> extern T common_product_type;

    template<typename T, std::size_t... I>
    extern kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>
      common_product_type<T, std::index_sequence<I...>>;

    template<typename T> using common_product_type_t = decltype(common_product_type<T, kumi::function::indexes_for<T>>);

    struct builder_t
    {
      template<kumi::concepts::product_type T, std::size_t... I>
      KUMI_HIDDEN_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
      {
        using res_t = kumi::builder_make_t<T, kumi::element_t<I, T>...>;
        return res_t{get<I>(KUMI_FWD(t))...};
      }

      template<typename T, std::size_t N, std::size_t... I>
      KUMI_HIDDEN_ABI constexpr auto operator()(T&& t,
                                                std::integral_constant<std::size_t, N>,
                                                std::index_sequence<I...>) const
      {
        using U = kumi::_::common_product_type_t<T>;
        using res_t = kumi::builder_make_t<U, kumi::element_t<N, kumi::element_t<I, T>>...>;
        return res_t{get<N>(get<I>(KUMI_FWD(t)))...};
      }

      template<typename T, std::size_t... E, std::size_t... I>
      KUMI_HIDDEN_ABI constexpr auto operator()(T&& t, std::index_sequence<E...>, std::index_sequence<I...>) const
      {
        using U = kumi::_::common_product_type_t<T>;
        using res_t = kumi::builder_make_t<U, kumi::element_t<E, kumi::element_t<I, T>>...>;
        return res_t{get<E>(get<I>(KUMI_FWD(t)))...};
      }
    };

    KUMI_VARIABLE_ABI constexpr builder_t builder{};
  }
}
