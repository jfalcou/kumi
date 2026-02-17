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

  template<std::size_t W, std::size_t H, std::size_t... S> struct cartesian_prod
  {
    KUMI_ABI consteval auto operator()() noexcept
    {
      _::digits<W, S...> dgt{};
      using t_t = decltype(dgt(0));

      struct
      {
        t_t data[sizeof...(Idxs)];
      } that{};

      []<std::size_t... I>(std::index_sequence<I...>) { ((that.data[I] = dgt(I))...); }(std::make_index_sequence<H>{});
      return that;
    }
  };

  //====================================================================================================================
  template<std::size_t Count, std::size_t... Sizes> struct concatenater_t
  {
    consteval auto operator()() const noexcept
    {
      struct
      {
        std::size_t t[Count], e[Count];
      } that{};

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

  template<std::size_t Count, std::size_t... Sizes> inline constexpr concatenater_t<Count, Sizes...> concatenater{};

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

  //==============================================================================================
  // Fold helpers
  //==============================================================================================
  template<typename F, typename T> struct foldable
  {
    F func;
    T value;

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator>>(foldable&& x, foldable<F, W>&& y)
    {
      return _::foldable{x.func, invoke(x.func, x.value, y.value)};
    }

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator<<(foldable&& x, foldable<F, W>&& y)
    {
      return _::foldable{x.func, invoke(x.func, x.value, y.value)};
    }
  };

  template<class F, class T> foldable(F const&, T&&) -> foldable<F, T>;

  //==============================================================================================
  // Scan helpers
  //==============================================================================================
  template<typename F, typename T> struct scannable
  {
    F func;
    T acc;

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator>>(scannable&& x, scannable<F, W>&& y)
    {
      constexpr auto size = kumi::size_v<T> - 1;
      return _::scannable{x.func, kumi::push_back(x.acc, invoke(x.func, kumi::get<size>(x.acc), y.acc))};
    }

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator<<(scannable&& x, scannable<F, W>&& y)
    {
      return _::scannable{x.func, kumi::push_front(x.acc, invoke(x.func, y.acc, kumi::get<0>(x.acc)))};
    }
  };

  template<class F, class T> scannable(F const&, T&&) -> scannable<F, T>;

  //====================================================================================================================
  template<template<typename> typename Pred, concepts::product_type T> struct selector_t
  {
    KUMI_ABI constexpr auto operator()() const noexcept
    {
      struct
      {
        std::size_t count = {}, cut = {}, t[1 + size_v<T>];
      } that{};

      auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
        that.cut = that.count;
        ((!Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
      };

      locate(std::make_index_sequence<size_v<T>>{});
      return that;
    }
  };

  template<template<typename> typename Pred, concepts::product_type T> inline constexpr selector_t<Pred, T> selector{};

  //====================================================================================================================
  template<std::size_t N> struct reducer_t
  {
    constexpr auto operator()() const noexcept
    {
      constexpr std::size_t half = N / 2;

      struct
      {
        std::size_t count = {}, remainder = {}, idx1[half], idx2[half];
      } that{};

      that.remainder = N % 2;

      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((that.idx1[that.count] = 2 * I, that.idx2[that.count++] = 2 * I + 1), ...);
      }(std::make_index_sequence<half>{});

      return that;
    }
  };

  template<std::size_t N> inline constexpr reducer_t<N> reducer{};

  //====================================================================================================================
  template<std::size_t S, std::size_t R> struct rotate_t
  {
    KUMI_ABI constexpr auto operator()() const noexcept
    {
      struct
      {
        std::size_t t[1 + S];
      } that{};

      auto idxs = [&]<std::size_t... I>(std::index_sequence<I...>) { ((that.t[I] = (I + R) % S), ...); };

      idxs(std::make_index_sequence<S>{});
      return that;
    }
  };

  template<std::size_t S, std::size_t R> inline constexpr rotate_t<S, R> rotator{};

  //====================================================================================================================
  template<typename T> struct make_unique
  {
    T acc;

    template<typename W> KUMI_ABI friend constexpr decltype(auto) operator|(make_unique&& x, make_unique<W>&& y)
    {
      constexpr auto value = []<std::size_t... I>(std::index_sequence<I...>) {
        return (all_uniques_v<W, raw_element_t<I, T>...>);
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

  inline constexpr uniquable uniqued{};

  //====================================================================================================================
  struct zipper_t
  {
    template<std::size_t Size, concepts::product_type T>
    KUMI_ABI constexpr auto operator()(index_t<Size> const&, T&& t) const noexcept
    {
      if constexpr (concepts::sized_product_type<T, 0>) return t;
      else
      {
        constexpr auto uz = []<typename N>(N const&, auto&& u) {
          return apply(
            [](auto&&... m) {
              auto zip_ = [&]<concepts::product_type V>(V&& v) {
                if constexpr (size_v<V> <= N::value) return none;
                else return get<N::value>(KUMI_FWD(v));
              };
              return builder<element_t<0, T>>::make(zip_(KUMI_FWD(m))...);
            },
            KUMI_FWD(u));
        };

        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::make_tuple(uz(index_t<I>{}, KUMI_FWD(t))...);
        }(std::make_index_sequence<Size>());
      }
    }
  };

  inline constexpr zipper_t zipper{};

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
}
