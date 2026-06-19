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

    template<typename... Ts> struct make_multiset
    {
      using type = kumi::_::multiset<Ts...>;
    };

    template<typename... Ts> using make_multiset_t = typename kumi::_::make_multiset<Ts...>::type;
  }

  namespace function
  {
    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Logic provider to compute the index map associated to the all_unique operation.

      ## Callable object
      @code
        inline constexpr unique_t uniquer{};
      @endcode
    **/
    //==================================================================================================================
    struct unique_t
    {
      template<typename... Ts> KUMI_ABI consteval auto operator()(std::type_identity<Ts>...) const noexcept
      {
        using type = kumi::_::make_multiset_t<std::make_index_sequence<sizeof...(Ts)>, Ts...>;
        return this->unique_(type{}, std::make_index_sequence<sizeof...(Ts)>{}, std::type_identity<Ts>{}...);
      }

      template<typename T, std::size_t... I, typename... Ts>
      consteval auto unique_(T&&, std::index_sequence<I...>, std::type_identity<Ts>...) const noexcept
      {
        return this->expand_(std::integer_sequence<bool, (T{}(std::type_identity<Ts>{}) == I)...>{});
      }

      template<bool... b> consteval auto expand_(std::integer_sequence<bool, b...> bs) const noexcept
      {
        return this->build_(bs, std::make_index_sequence<(b + ... + 0)>{});
      }

      template<bool... b, std::size_t... I>
      consteval auto build_(std::integer_sequence<bool, b...>, std::index_sequence<I...>) const noexcept
      {
        return std::index_sequence<(kumi::_::nth_pos(I, b...))...>{};
      }
    };

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Logic provider to compute the index map associated to the partition operation.

      ## Callable object
      @code
        inline constexpr select_t selector{};
      @endcode
    **/
    //==================================================================================================================
    struct select_t
    {
      template<bool... Bs> KUMI_ABI consteval auto operator()(std::bool_constant<Bs>...) const noexcept
      {
        return this->select_(std::integer_sequence<bool, Bs...>{}, std::make_index_sequence<(Bs + ... + 0)>{},
                             std::make_index_sequence<(sizeof...(Bs) - (Bs + ... + 0))>{});
      }

      template<bool... b, std::size_t... I, std::size_t... J>
      consteval auto select_(std::integer_sequence<bool, b...>,
                             std::index_sequence<I...>,
                             std::index_sequence<J...>) const noexcept
      {
        return kumi::projection_map{std::index_sequence<(kumi::_::nth_pos(I, b...))...>{},
                                    std::index_sequence<(kumi::_::nth_pos(J, !b...))...>{}};
      }
    };

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Logic provider to compute the index map associated to the adjacent unicity operation.

      ## Callable object
      @code
        inline constexpr adjacent_unicity_t uniqued{};
      @endcode
    **/
    //==================================================================================================================
    struct adjacent_unicity_t
    {
      template<kumi::concepts::product_type T> KUMI_ABI consteval auto operator()(kumi::as<T>) const noexcept
      {
        return this->adjacent_unicity_(kumi::as<T>{}, std::make_index_sequence<kumi::size_v<T> - 1>{});
      }

      template<typename T, std::size_t... I>
      consteval auto adjacent_unicity_(kumi::as<T>, std::index_sequence<I...>) const noexcept
      {
        constexpr auto proj =
          std::integer_sequence<bool,
                                !std::is_same_v<kumi::stored_element_t<I, T>, kumi::stored_element_t<I + 1, T>>...>{};
        return this->expand_(proj);
      }

      template<bool... b> consteval auto expand_(std::integer_sequence<bool, b...> bs) const noexcept
      {
        return this->build_(bs, std::make_index_sequence<(b + ... + 0)>{});
      }

      template<bool... b, std::size_t... I>
      consteval auto build_(std::integer_sequence<bool, b...>, std::index_sequence<I...>) const noexcept
      {
        return std::index_sequence<0, (kumi::_::nth_pos(I, b...) + 1)...>{};
      }
    };

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the adjactent unicity operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::adjacent_unicity_t uniqued{};

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the deduplication operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::unique_t uniquer{};

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the selection operation.
    **/
    //==================================================================================================================
    inline constexpr kumi::function::select_t selector{};
  }
}
