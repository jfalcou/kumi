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
    template<typename Seq, typename... Ts> struct multiset;

    template<std::size_t I, typename T> struct multiset<std::index_sequence<I>, T>
    {
      consteval auto operator()(std::type_identity<T>) const noexcept
      {
        return std::integral_constant<std::size_t, I>{};
      }
    };

    template<std::size_t I, std::size_t... Is, typename T, typename... Ts>
    struct multiset<std::index_sequence<I, Is...>, T, Ts...> : kumi::_::multiset<std::index_sequence<Is...>, Ts...>
    {
      consteval auto operator()(std::type_identity<T>) const noexcept
      {
        return std::integral_constant<std::size_t, I>{};
      }

      using kumi::_::multiset<std::index_sequence<Is...>, Ts...>::operator();
    };

    template<typename... Ts> using make_multiset_t = typename kumi::_::multiset<Ts...>;
  }

  namespace function
  {
    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Logic provider to compute the index map associated to the all_unique operation.

      ## Callable object
      @code
        KUMI_ENTRY_POINT unique_t uniquer{};
      @endcode
    **/
    //==================================================================================================================
    struct unique_t
    {
    private:
      template<std::size_t... I, bool... Bs>
      consteval auto impl(std::index_sequence<I...>, std::bool_constant<Bs>...) const noexcept
      {
        return std::index_sequence<(kumi::_::nth_pos(I, Bs...))...>{};
      }

    public:
      template<bool... Bs> consteval auto operator()(std::bool_constant<Bs>... bs) const noexcept
      {
        return impl(std::make_index_sequence<(Bs + ... + 0)>{}, bs...);
      }
    };

    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Logic provider to compute the index map associated to the partition operation.

      ## Callable object
      @code
        KUMI_ENTRY_POINT select_t selector{};
      @endcode
    **/
    //==================================================================================================================
    struct select_t
    {
    private:
      template<bool... b, std::size_t... I, std::size_t... J>
      consteval auto impl(std::integer_sequence<bool, b...>,
                          std::index_sequence<I...>,
                          std::index_sequence<J...>) const noexcept
      {
        return kumi::projection_map{std::index_sequence<(kumi::_::nth_pos(I, b...))...>{},
                                    std::index_sequence<(kumi::_::nth_pos(J, !b...))...>{}};
      }

    public:
      template<bool... Bs> consteval auto operator()(std::bool_constant<Bs>...) const noexcept
      {
        return impl(std::integer_sequence<bool, Bs...>{}, std::make_index_sequence<(Bs + ... + 0)>{},
                    std::make_index_sequence<(sizeof...(Bs) - (Bs + ... + 0))>{});
      }
    };

    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Logic provider to compute the index map associated to the adjacent unicity operation.

      ## Callable object
      @code
        KUMI_ENTRY_POINT adjacent_unicity_t uniqued{};
      @endcode
    **/
    //==================================================================================================================
    struct adjacent_unicity_t
    {
    private:
      template<std::size_t... I, bool... Bs>
      consteval auto impl(std::index_sequence<I...>, std::bool_constant<Bs>...) const noexcept
      {
        return std::index_sequence<0, (kumi::_::nth_pos(I, Bs...) + 1)...>{};
      }

    public:
      template<bool... Bs> consteval auto operator()(std::bool_constant<Bs>... bs) const noexcept
      {
        return impl(std::make_index_sequence<(Bs + ... + 0)>{}, bs...);
      }
    };

    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Callable object computing the index map associated to the adjactent unicity operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::adjacent_unicity_t uniqued{};

    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Callable object computing the index map associated to the deduplication operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::unique_t uniquer{};

    //==================================================================================================================
    /**
      @ingroup kumi_functional
      @brief    Callable object computing the index map associated to the selection operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::select_t selector{};
  }
}
