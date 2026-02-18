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
  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the prduct type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @note Every inner product type should be of the same sizes, otherwise see `zip_min` or `zip_max`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip;
  //!
  //!   template<product_type T>
  //!   using zip_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip.cpp
  //================================================================================================
  template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (concepts::sized_product_type<T0, 0>) return tuple{};
    else
    {
      constexpr auto count = 1 + sizeof...(Ts);
      constexpr auto pos = _::zipper<count, size_v<T0>>();
      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        constexpr auto offset = k * count;
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);
        using type = builder_make_t<
          res_type, element_t<pos.e[offset + I], std::remove_cvref_t<element_t<pos.t[offset + I], decltype(tps)>>>...>;
        return type{get<pos.e[offset + I]>(get<pos.t[offset + I]>(KUMI_FWD(tps)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<count> ids;
        return kumi::make_tuple(maps(index<N>, ids)...);
      }(std::make_index_sequence<size_v<T0>>{});
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the prudct type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @ note `zip_min` truncates product types based on the smallest size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip_min;
  //!
  //!   template<product_type T>
  //!   using zip_min_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_min
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip_min.cpp
  //================================================================================================
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_min(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t min = _::min_size_v<T0, Ts...>();
    if constexpr (min == 0) return tuple{};
    else
    {
      constexpr std::size_t count = 1 + sizeof...(Ts);
      constexpr auto pos = _::zipper<count, min>();

      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        constexpr auto offset = k * count;
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);
        using type = builder_make_t<
          res_type, element_t<pos.e[offset + I], std::remove_cvref_t<element_t<pos.t[offset + I], decltype(tps)>>>...>;
        return type{get<pos.e[offset + I]>(get<pos.t[offset + I]>(KUMI_FWD(tps)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<count> ids;
        return kumi::make_tuple(maps(index<N>, ids)...);
      }(std::make_index_sequence<min>{});
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the product type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @note `zip_max` fills missing elements to reach the biggest product type size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip_max;
  //!
  //!   template<product_type T>
  //!   using zip_max_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_max
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip_max.cpp
  //================================================================================================
  template<std::size_t I, typename T, typename U> struct element_or
  {
    using type = element_t<I, T>;
  };

  template<std::size_t I, typename T, typename U>
  requires(I >= size_v<T>)
  struct element_or<I, T, U>
  {
    using type = U;
  };

  template<std::size_t I, typename T, typename U> using element_or_t = typename element_or<I, T, U>::type;

  template<std::size_t I, typename T, typename V> constexpr auto get_or(T&& t, V&& v)
  {
    if constexpr (I < size_v<T>) return get<I>(KUMI_FWD(t));
    else return KUMI_FWD(v);
  }

  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_max(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t max = _::max_size_v<T0, Ts...>();
    if constexpr (max == 0) return tuple{};
    else
    {
      constexpr std::size_t count = 1 + sizeof...(Ts);
      constexpr auto pos = _::zipper<count, max>();
      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        constexpr auto offset = k * count;
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);

        using type =
          builder_make_t<res_type,
                         element_or_t<pos.e[offset + I],
                                      std::remove_cvref_t<element_t<pos.t[offset + I], decltype(tps)>>, kumi::unit>...>;

        return type{get_or<pos.e[offset + I]>(get<pos.t[offset + I]>(KUMI_FWD(tps)), kumi::none)...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<count> ids;
        return kumi::make_tuple(maps(index<N>, ids)...);
      }(std::make_index_sequence<max>{});
    }
  }

  namespace result
  {
    template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts> struct zip
    {
      using type = decltype(kumi::zip(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_min
    {
      using type = decltype(kumi::zip_min(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_max
    {
      using type = decltype(kumi::zip_max(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> using zip_t = typename zip<T0, Ts...>::type;

    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_min_t = typename zip_min<T0, Ts...>::type;

    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_max_t = typename zip_max<T0, Ts...>::type;
  }
}
