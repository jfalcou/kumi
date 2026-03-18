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
  KUMI_ABI consteval std::size_t min(auto... sizes)
  {
    std::size_t result{};
    return ((result = result < sizes ? result : sizes), ...);
  };

  KUMI_ABI consteval std::size_t max(auto... sizes)
  {
    std::size_t result{};
    return ((result = result > sizes ? result : sizes), ...);
  };

  //====================================================================================================================
  KUMI_ABI consteval std::size_t get_t(std::size_t i, auto... sizes)
  {
    std::size_t t{}, sum{};
    ((t += (i >= (sum += sizes))), ...);
    return t;
  };

  KUMI_ABI consteval std::size_t get_e(std::size_t i, auto... sizes)
  {
    std::size_t sum{}, offset{};
    ((offset = (i >= (sum += sizes) ? sum : offset)), ...);
    return i - offset;
  }

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
    template<std::size_t... Sizes> KUMI_ABI consteval auto operator()(std::index_sequence<Sizes...>) const noexcept
    {
      constexpr auto N = (Sizes + ... + 0ULL);

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        struct
        {
          using t = std::index_sequence<(get_t(I, Sizes...))...>;
          using e = std::index_sequence<(get_e(I, Sizes...))...>;
          t tpl{};
          e elt{};
        } that{};
        return that;
      }(std::make_index_sequence<N>{});
    }
  };

  struct flatten_ : cat_
  {
    using parent = cat_;
    using parent::operator();
  };

  //====================================================================================================================
  struct zip_
  {
    template<std::size_t Count, std::size_t Size>
    KUMI_ABI consteval auto operator()(index_t<Count>, index_t<Size>) const noexcept
    {
      struct
      {
        using t = decltype(std::make_index_sequence<Count>{});
        using e = decltype(std::make_index_sequence<Size>{});
        t tpl{};
        e elt{};
      } that{};

      return that;
    }
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

  inline constexpr cartesian_product_ cartesian_producer{};
  inline constexpr cat_ concatenater{};
  inline constexpr flatten_ flattener{};

  inline constexpr uniquable uniqued{};
  inline constexpr zip_ zipper{};
}
