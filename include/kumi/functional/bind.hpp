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
      static constexpr auto function_index = static_cast<std::size_t>(-1);
      static constexpr auto seq = std::make_index_sequence<sizeof...(Bound)>{};

      using binder_t = make_binder_t<std::make_index_sequence<sizeof...(Bound)>, Bound...>;
      using func_t = leaf<function_index, F>;

      template<typename... Args> KUMI_HIDDEN_ABI constexpr decltype(auto) operator()(Args&&... args) &
      {
        return impl(seq, *this, KUMI_FWD(args)...);
      }

      template<typename... Args> KUMI_HIDDEN_ABI constexpr decltype(auto) operator()(Args&&... args) const&
      {
        return impl(seq, *this, KUMI_FWD(args)...);
      }

      template<typename... Args> KUMI_HIDDEN_ABI constexpr decltype(auto) operator()(Args&&... args) &&
      {
        return impl(seq, KUMI_MOVE(*this), KUMI_FWD(args)...);
      }

      template<typename... Args> KUMI_HIDDEN_ABI constexpr decltype(auto) operator()(Args&&... args) const&&
      {
        return impl(seq, KUMI_MOVE(*this), KUMI_FWD(args)...);
      }

      template<std::size_t... Is, typename Self, typename... Args>
      KUMI_HIDDEN_ABI static constexpr decltype(auto) impl(std::index_sequence<Is...>, Self&& s, Args&&... args)
      {
        if constexpr (D == Binding::front)
        {
          return kumi::invoke(KUMI_FWD(s).func_t::operator()(std::integral_constant<size_t, function_index>{}),
                              KUMI_FWD(s).binder_t::operator()(std::integral_constant<std::size_t, Is>{})...,
                              KUMI_FWD(args)...);
        }
        else
        {
          return kumi::invoke(KUMI_FWD(s).func_t::operator()(std::integral_constant<size_t, function_index>{}),
                              KUMI_FWD(args)...,
                              KUMI_FWD(s).binder_t::operator()(std::integral_constant<std::size_t, Is>{})...);
        }
      }
    };
  }

  //====================================================================================================================
  //! @defgroup kumi_bind_front kumi::bind_front
  //! @ingroup kumi_functional
  //! @brief Returns a callable object with `ts` bound as its leading arguments, reducing `c` arity.
  //====================================================================================================================
  /**
    @ingroup kumi_bind_front

    @param c	Callable object to be bound.
    @param ts Elements to be bound as the leading arguments of `c`.
    @return   A callable object of lower arity invoking `c` with `ts` prefilled at the front.

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
  //! @defgroup kumi_bind_back kumi::bind_back
  //! @ingroup kumi_functional
  //! @brief Returns a callable object with `ts` bound as its trailing arguments, reducing `c` arity.
  //====================================================================================================================
  /**
    @ingroup kumi_bind_back

    @param c	Callable object to be bound.
    @param ts Elements to be bound as the trailing arguments of `c`.
    @return   A callable object of lower arity invoking `c` with `ts` prefilled at the back.

    @note Replaces std::bind_back to avoid depending on `functional`.
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
