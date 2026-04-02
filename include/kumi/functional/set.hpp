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
    struct multiset<std::index_sequence<I, Is...>, T, Ts...> : multiset<std::index_sequence<Is...>, Ts...>
    {
      consteval auto operator()(std::type_identity<T>) const noexcept
      {
        return std::integral_constant<std::size_t, I>{};
      }

      using multiset<std::index_sequence<Is...>, Ts...>::operator();
    };

    template<typename... Ts> struct make_multiset
    {
      using type = multiset<Ts...>;
    };

    template<typename... Ts> using make_multiset_t = typename make_multiset<Ts...>::type;
  }

  namespace function
  {
    struct unique_t
    {
      template<typename... Ts> KUMI_ABI consteval auto operator()(std::type_identity<Ts>...) const noexcept
      {
        using type = _::make_multiset_t<std::make_index_sequence<sizeof...(Ts)>, Ts...>;
        constexpr type impl{};

        struct
        {
          std::size_t e[sizeof...(Ts)], count = {};
        } that{};

        [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((impl(std::type_identity<Ts>{}) == I ? (that.e[that.count++] = I) : 0), ...);
        }(std::make_index_sequence<sizeof...(Ts)>{});
        return that;
      }
    };

    struct select_t
    {
      template<bool... Bs> KUMI_ABI consteval auto operator()(std::bool_constant<Bs>...) const noexcept
      {
        struct
        {
          std::size_t count = {}, cut = {}, t[sizeof...(Bs)];
        } that{};

        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((Bs ? (that.t[that.count++] = I) : 0), ...);
          that.cut = that.count;
          ((!Bs ? (that.t[that.count++] = I) : 0), ...);
        };

        locate(std::make_index_sequence<sizeof...(Bs)>{});
        return that;
      }
    };

    struct adjacent_unicity_t
    {
      template<concepts::product_type T> [[nodiscard]] KUMI_ABI consteval auto operator()(as<T>) const noexcept
      {
        struct
        {
          std::size_t count{1}, t[size_v<T>];
        } that{};

        that.t[0] = 0;

        [&]<std::size_t... I>(std::index_sequence<I...>) {
          (((std::is_same_v<stored_element_t<I, T>, stored_element_t<I + 1, T>>) ? I : (that.t[that.count++] = I + 1)),
           ...);
        }(std::make_index_sequence<size_v<T> - 1>{});

        return that;
      }
    };

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the adjactent unicity operation.
    **/
    //==================================================================================================================
    inline constexpr adjacent_unicity_t uniqued{};

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the deduplication operation.
    **/
    //==================================================================================================================
    inline constexpr unique_t uniquer{};

    //==================================================================================================================
    /**
      @ingroup  functional
      @brief    Callable object computing the index map associated to the selection operation.
    **/
    //==================================================================================================================
    inline constexpr select_t selector{};
  }
}
