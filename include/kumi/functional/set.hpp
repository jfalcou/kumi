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

    // Specializable multiset type constructor
    template<typename... Ts> struct make_multiset
    {
      using type = multiset<Ts...>;
    };

    template<typename... Ts> using make_multiset_t = typename make_multiset<Ts...>::type;
  }

  namespace function
  {
    //====================================================================================================================
    struct unique_
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
      };
    };

    //====================================================================================================================
    struct select_
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

    //====================================================================================================================
    struct uniquable
    {
      template<concepts::product_type T> [[nodiscard]] KUMI_ABI consteval auto operator()(as<T>) const noexcept
      {
        struct
        {
          std::size_t count{1}, t[size_v<T>];
        } that{};

        that.t[0] = 0;

        [&]<std::size_t... I>(std::index_sequence<I...>) {
          (((std::is_same_v<raw_element_t<I, T>, raw_element_t<I + 1, T>>) ? I : (that.t[that.count++] = I + 1)), ...);
        }(std::make_index_sequence<size_v<T> - 1>{});

        return that;
      }
    };

    inline constexpr uniquable uniqued{};
    inline constexpr unique_ uniquer{};
    inline constexpr select_ selector{};
  }
}
