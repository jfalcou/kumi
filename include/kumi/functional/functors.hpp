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
  template<std::size_t N, std::size_t... S> struct digits
  {
    KUMI_ABI consteval auto operator()(std::size_t v) noexcept
    {
      struct
      {
        std::size_t data[N];
      } values = {};

      std::size_t shp[N] = {S...};
      std::size_t i = 0;

      while (v != 0)
      {
        values.data[i] = v % shp[i];
        v /= shp[i++];
      }

      return values;
    }
  };

  struct cartesian_product_
  {
    template<std::size_t W, std::size_t H, std::size_t... S>
    KUMI_ABI consteval auto operator()(index_t<W>, index_t<H>, index_t<S>...) const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        _::digits<W, S...> dgt{};
        using t_t = decltype(dgt(0));
        struct
        {
          t_t data[sizeof...(I)];
        } that = {dgt(I)...};

        return that;
      }(std::make_index_sequence<H>{});
    }
  };

  //====================================================================================================================
  struct cat_
  {
    template<std::size_t Count, std::size_t... Sizes>
    KUMI_ABI consteval auto operator()(index_t<Count>, std::index_sequence<Sizes...>) const noexcept
    {
      struct
      {
        std::size_t t[Count], e[Count], count = {};
      } that{};

      that.count = Count;
      std::size_t k = 0, offset = 0;

      auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
        (((that.t[I + offset] = k), (that.e[I + offset] = I)), ...);
        offset += sizeof...(I);
        k++;
      };

      (locate(std::make_index_sequence<Sizes>{}), ...);
      return that;
    }
  };

  struct flatten_ : cat_
  {
    using parent = cat_;

    template<std::size_t... Sizes> KUMI_ABI consteval auto operator()(std::index_sequence<Sizes...> sz) const noexcept
    {
      return parent::operator()(index<(Sizes + ... + 1ULL)>, sz);
    }
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
  struct zip_
  {
    template<std::size_t Count, std::size_t Size>
    KUMI_ABI consteval auto operator()(index_t<Count>, index_t<Size>) const noexcept
    {
      struct
      {
        std::size_t t[Count * Size], e[Count * Size];
      } that{};

      std::size_t offset = 0;

      auto locate = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        (((that.t[I + offset] = I), (that.e[I + offset] = k)), ...);
        offset += Count;
      };

      [&]<std::size_t... I>(std::index_sequence<I...>) {
        (locate(index<I>, std::make_index_sequence<Count>{}), ...);
      }(std::make_index_sequence<Size>{});

      return that;
    }
  };

  //====================================================================================================================
  template<typename T0, typename... Ts> consteval std::size_t min_size_v()
  {
    std::size_t result = size_v<T0>;
    if constexpr (sizeof...(Ts) == 0) return result;
    else return ((result = result < size_v<Ts> ? result : size_v<Ts>), ...);
  };

  template<typename T0, typename... Ts> consteval std::size_t max_size_v()
  {
    std::size_t result = size_v<T0>;
    if constexpr (sizeof...(Ts) == 0) return result;
    else return ((result = result > size_v<Ts> ? result : size_v<Ts>), ...);
  };

  //====================================================================================================================
  template<typename T, auto> struct repeat
  {
    using type = T;
  };

  template<typename T, auto I> using repeat_t = typename repeat<T, I>::type;

  template<typename T, auto N> struct as_homogeneous
  {
    template<std::size_t... I> static consteval auto homogeneify(std::index_sequence<I...>) -> tuple<repeat_t<T, I>...>;

    using type = std::remove_cvref_t<decltype(homogeneify(std::make_index_sequence<N>{}))>;
  };

  template<typename T, auto N> using as_homogeneous_t = typename as_homogeneous<T, N>::type;

  //====================================================================================================================
  template<typename T> struct make_unique
  {
    T acc;

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator|(make_unique&& x, make_unique<W>&& y)
    {
      constexpr auto value = []<std::size_t... I>(std::index_sequence<I...>) {
        if constexpr (concepts::record_type<T>) return (all_uniques_v<_::type_of_t<W>, raw_element_t<I, T>...>);
        else return (all_uniques_v<W, raw_element_t<I, T>...>);
      }(std::make_index_sequence<size_v<T>>{});

      if constexpr (value)
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          using res_t = builder_make_t<T, element_t<I, T>..., W>;
          return _::make_unique{res_t{get<I>(KUMI_FWD(x.acc))..., KUMI_FWD(y.acc)}};
        }(std::make_index_sequence<size_v<T>>{});
      else return KUMI_FWD(x);
    }
  };

  template<typename W> make_unique(W&& w) -> make_unique<W>;

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
        (
          [&] {
            constexpr auto L = I;
            constexpr auto R = I + 1;
            if constexpr (!std::is_same_v<raw_element_t<L, T>, raw_element_t<R, T>>) that.t[that.count++] = R;
          }(),
          ...);
      }(std::make_index_sequence<size_v<T> - 1>{});

      return that;
    }
  };

  inline constexpr cartesian_product_ cartesian_producer{};
  inline constexpr cat_ concatenater{};
  inline constexpr flatten_ flattener{};

  inline constexpr select_ selector{};
  inline constexpr uniquable uniqued{};
  inline constexpr zip_ zipper{};
}
