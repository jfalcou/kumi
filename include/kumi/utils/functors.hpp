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
  template<typename F, typename... Ts> KUMI_ABI constexpr auto bind_front(F&& f, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) {
      return invoke(KUMI_FWD(f), KUMI_FWD(ts)..., KUMI_FWD(call_args)...);
    };
  }

  template<typename F, typename... Ts> KUMI_ABI constexpr auto bind_back(F&& f, Ts&&... ts)
  {
    return [&]<typename... Args>(Args&&... call_args) {
      return invoke(KUMI_FWD(f), KUMI_FWD(call_args)..., KUMI_FWD(ts)...);
    };
  }

  //==============================================================================================
  // Fold helpers
  //==============================================================================================
  template<typename T> struct foldable
  {
    T value;

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(foldable&& x, C&& c)
    {
      return _::foldable{invoke(c, x.value)};
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, foldable&& x)
    {
      return _::foldable{invoke(c, x.value)};
    }
  };

  template<class T> foldable(T&&) -> foldable<T>;

  //==============================================================================================
  // Scan helpers
  //==============================================================================================
  template<typename L, typename R> struct scannable
  {
    L left;
    R right;

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(scannable&& x, C&& c)
    {
      return _::scannable{
        x,
        invoke(c, x.right),
      };
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>=(C&& c, scannable const& x)
    {
      if constexpr (std::is_null_pointer_v<std::remove_cvref_t<L>>) return invoke(KUMI_FWD(c), x.right);
      else return bind_back(KUMI_FWD(c), x.right) >>= x.left;
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, scannable&& x)
    {
      return _::scannable{invoke(c, x.left), x};
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<=(scannable const& x, C&& c)
    {
      if constexpr (std::is_null_pointer_v<std::remove_cvref_t<R>>) return invoke(KUMI_FWD(c), x.left);
      else return x.right <<= bind_front(KUMI_FWD(c), x.left);
    }
  };

  template<class L, class R> scannable(L&&, R&&) -> scannable<L, R>;

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
    KUMI_ABI consteval auto operator()() const noexcept
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

  template<std::size_t W, std::size_t H, std::size_t... S>
  inline constexpr cartesian_prod<W, H, S...> cartesian_producer{};

  //====================================================================================================================
  template<std::size_t Sz, std::size_t Extent, std::size_t Stride> struct tiler_t
  {
    static constexpr std::size_t nb_blocks = (Sz <= Extent) ? 1 : (Sz - Extent + Stride - 1) / Stride + 1;

    static constexpr std::size_t block_size(std::size_t I)
    {
      std::size_t s = I * Stride;
      return (s < Sz) ? ((s + Extent > Sz) ? (Sz - s) : Extent) : 0;
    }

    KUMI_ABI consteval auto operator()() const noexcept
    {
      struct
      {
        std::size_t t[nb_blocks], s[nb_blocks], count = nb_blocks;
      } that = {};

      auto idxs = [&]<std::size_t... I>(std::index_sequence<I...>) {
        return ((that.t[I] = block_size(I), that.s[I] = I * Stride), ...);
      };
      idxs(std::make_index_sequence<nb_blocks>{});
      return that;
    }
  };

  template<std::size_t Size, std::size_t Extent, std::size_t Stride>
  inline constexpr tiler_t<Size, Extent, Stride> tiler{};

  //====================================================================================================================
  template<std::size_t Count, std::size_t... Sizes> struct concatenater_t
  {
    KUMI_ABI consteval auto operator()() const noexcept
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

  //====================================================================================================================
  template<template<typename> typename Pred, concepts::product_type T> struct selector_t
  {
    KUMI_ABI consteval auto operator()() const noexcept
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
    KUMI_ABI consteval auto operator()() const noexcept
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
    KUMI_ABI consteval auto operator()() const noexcept
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
  template<std::size_t Count, std::size_t Size> struct zipper_t
  {
    KUMI_ABI consteval auto operator()() const noexcept
    {
      struct
      {
        std::size_t t[Count * Size], e[Count * Size];
      } that = {};

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

  template<std::size_t Count, std::size_t Size> inline constexpr zipper_t<Count, Size> zipper{};

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
}
