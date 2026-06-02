//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  namespace _
  {
    enum class Binding
    {
      front,
      back
    };

    template<Binding D, typename F, typename... Bound>
    struct bind_t : leaf<static_cast<std::size_t>(-1), F>,
                    make_binder_t<std::make_index_sequence<sizeof...(Bound)>, Bound...>
    {
      static constexpr auto seq = std::make_index_sequence<sizeof...(Bound)>{};
      using base = make_binder_t<std::make_index_sequence<sizeof...(Bound)>, Bound...>;
      using callable = leaf<static_cast<std::size_t>(-1), F>;

      template<typename... Args> constexpr decltype(auto) operator()(Args&&... args) &
      {
        return impl(seq, KUMI_FWD(args)...);
      }

      template<typename... Args> constexpr decltype(auto) operator()(Args&&... args) const&
      {
        return impl(seq, KUMI_FWD(args)...);
      }

      template<std::size_t... Is, typename... Args>
      constexpr decltype(auto) impl(std::index_sequence<Is...>, Args&&... args) const&
      {
        if constexpr (D == Binding::front)
        {
          return kumi::invoke(
            static_cast<callable const&>(*this)(std::integral_constant<size_t, static_cast<std::size_t>(-1)>{}),
            static_cast<base const&>(*this)(std::integral_constant<std::size_t, Is>{})..., KUMI_FWD(args)...);
        }
        else
        {
          return kumi::invoke(
            static_cast<callable const&>(*this)(std::integral_constant<size_t, static_cast<std::size_t>(-1)>{}),
            KUMI_FWD(args)..., static_cast<base const&>(*this)(std::integral_constant<std::size_t, Is>{})...);
        }
      }

      template<std::size_t... Is, typename... Args>
      constexpr decltype(auto) impl(std::index_sequence<Is...>, Args&&... args) &
      {
        if constexpr (D == Binding::front)
        {
          return kumi::invoke(
            static_cast<callable&>(*this)(std::integral_constant<size_t, static_cast<std::size_t>(-1)>{}),
            static_cast<base&>(*this)(std::integral_constant<std::size_t, Is>{})..., KUMI_FWD(args)...);
        }
        else
        {
          return kumi::invoke(
            static_cast<callable&>(*this)(std::integral_constant<size_t, static_cast<std::size_t>(-1)>{}),
            KUMI_FWD(args)..., static_cast<base&>(*this)(std::integral_constant<std::size_t, Is>{})...);
        }
      }
    };
  }

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    Binds a certain amount of values into a callable reducing it's arity.

    @param c	Callable object to be bound.
    @param ts elements to be used as prefilled arguments to c
    @return   A new callable matching C with ts arguments prefilled by the front.

    @note Replaces std::bind_front to avoid depending on `functional`.
  **/
  //====================================================================================================================
  template<typename C, typename... Ts>
  KUMI_ABI constexpr auto bind_front(C&& c, Ts&&... ts)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<C>> &&
             (std::is_nothrow_move_constructible_v<std::decay_t<Ts>> && ...))
  requires(std::is_move_constructible_v<std::decay_t<C>> && (std::is_move_constructible_v<std::decay_t<Ts>> && ...))
  {
    return kumi::_::bind_t<kumi::_::Binding::front, std::decay_t<C>, std::decay_t<Ts>...>{KUMI_FWD(c), KUMI_FWD(ts)...};
  }

  //====================================================================================================================
  /**
    @ingroup  functional
    @brief    Binds a certain amount of values into a callable reducing it's arity.

    @param c	Callable object to be bound.
    @param ts elements to be used as prefilled arguments to c
    @return   A new callable matching C with ts arguments prefilled by the back.

    @note Replaces std::bind_front to avoid depending on `functional`.
  **/
  //====================================================================================================================
  template<typename C, typename... Ts>
  KUMI_ABI constexpr auto bind_back(C&& c, Ts&&... ts)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<C>> &&
             (std::is_nothrow_move_constructible_v<std::decay_t<Ts>> && ...))
  requires(std::is_move_constructible_v<std::decay_t<C>> && (std::is_move_constructible_v<std::decay_t<Ts>> && ...))
  {
    return kumi::_::bind_t<kumi::_::Binding::back, std::decay_t<C>, std::decay_t<Ts>...>{KUMI_FWD(c), KUMI_FWD(ts)...};
  }

  template<typename C, typename... Ts>
  KUMI_ABI constexpr auto bind(C&& c, Ts&&... ts)
    noexcept(std::is_nothrow_move_constructible_v<std::decay_t<C>> &&
             (std::is_nothrow_move_constructible_v<std::decay_t<Ts>> && ...))
  requires(std::is_move_constructible_v<std::decay_t<C>> && (std::is_move_constructible_v<std::decay_t<Ts>> && ...))
  {
    return kumi::_::bind_t<kumi::_::Binding::front, std::decay_t<C>, std::decay_t<Ts>...>{KUMI_FWD(c), KUMI_FWD(ts)...};
  }
}
