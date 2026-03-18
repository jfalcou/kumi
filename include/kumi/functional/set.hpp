#pragma once

namespace kumi::_
{

  template<typename Seq, typename... Ts> struct set_;

  template<std::size_t I, typename T> struct set_<std::index_sequence<I>, T>
  {
    consteval std::integral_constant<std::size_t, I> operator()(std::type_identity<T>) const noexcept { return {}; }
  };

  template<std::size_t I, std::size_t... Is, typename T, typename... Ts>
  struct set_<std::index_sequence<I, Is...>, T, Ts...> : set_<std::index_sequence<Is...>, Ts...>
  {
    consteval std::integral_constant<std::size_t, I> operator()(std::type_identity<T>) const noexcept { return {}; }

    using set_<std::index_sequence<Is...>, Ts...>::operator();
  };

  // Specializable set type constructor
  template<typename... Ts> struct make_set_
  {
    using type = set_<Ts...>;
  };

  template<typename... Ts> using make_set__t = typename make_set_<Ts...>::type;

  //====================================================================================================================
  struct unique_
  {
    template<typename... Ts> KUMI_ABI consteval auto operator()(std::type_identity<Ts>...) const noexcept
    {
      using type = make_set__t<std::make_index_sequence<sizeof...(Ts)>, Ts...>;
      type set_representation;

      struct
      {
        std::size_t e[sizeof...(Ts)], count = {};
      } that{};

      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((set_representation(std::type_identity<Ts>{}) == I ? (that.e[that.count++] = I) : 0), ...);
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

  inline constexpr unique_ uniquer{};
  inline constexpr select_ selector{};
}
