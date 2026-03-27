//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Constructs a tuple where the ith element is the product type of all ith elements of `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @param t0 Product type to convert
    @param ts Product types to convert
    @return   The tuple of all combination of elements from `t0`, `ts`...

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct zip;

      template<product_type T>
      using zip_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip

    @see zip_min
    @see zip_max

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/zip.cpp
    ### Record:
    @include doc/record/algo/zip.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (concepts::sized_product_type<T0, 0>) return tuple{};
    else
    {
      constexpr auto count = 1 + sizeof...(Ts);
      constexpr auto pos = function::zipper(index<count>, index<size_v<T0>>);
      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);
        using type = builder_make_t<res_type, element_t<k, element_t<I, decltype(tps)>>...>;
        return type{get<k>(get<I>(KUMI_FWD(tps)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        return kumi::make_tuple(maps(index<N>, get<0>(pos))...);
      }(get<1>(pos));
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Constructs a tuple where the ith element is the product type of all ith elements of `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @param t0 Product type to convert
    @param ts Product types to convert
    @return   The tuple of all combination of elements from `t0`, `ts`...

    @note `zip_min` truncates product types based on the smallest size.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct zip_min;

      template<product_type T>
      using zip_min_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip_min

    @see zip
    @see zip_max

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/zip_min.cpp
    ### Record:
    @include doc/record/algo/zip_min.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_min(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t min = _::min(size_v<T0>, size_v<Ts>...);
    if constexpr (min == 0) return tuple{};
    else
    {
      constexpr std::size_t count = 1 + sizeof...(Ts);
      constexpr auto pos = function::zipper(index<count>, index<min>);

      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto E, std::index_sequence<I...>) {
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);
        using type = builder_make_t<res_type, element_t<E, element_t<I, decltype(tps)>>...>;
        return type{get<E>(get<I>(KUMI_FWD(tps)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        return kumi::make_tuple(maps(index<N>, get<0>(pos))...);
      }(get<1>(pos));
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Constructs a tuple where the ith element is the product type of all ith elements of `t0`,`ts`...

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note This function does not take part in overload resolution if the product types do not follow the same
    semantic. @see follows_same_semantic

    @param t0 Product type to convert
    @param ts Product types to convert
    @return   The tuple of all combination of elements from `t0`,`ts`...

    @note `zip_max` fills missing elements to reach the biggest product type size.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct zip_max;

      template<product_type T>
      using zip_max_t = typename zip<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::zip_max

    @see zip
    @see zip_min

    ## Example:
    @include doc/tuple/algo/zip_max.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_max(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t max = _::max(size_v<T0>, size_v<Ts>...);
    if constexpr (max == 0) return tuple{};
    else
    {
      constexpr std::size_t count = 1 + sizeof...(Ts);
      constexpr auto pos = function::zipper(index<count>, index<max>);
      using res_type = common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        auto tps = kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...);

        using type = builder_make_t<res_type, function::element_or_t<k, element_t<I, decltype(tps)>, kumi::unit>...>;

        return type{function::get_or<k>(get<I>(KUMI_FWD(tps)), kumi::none)...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        return kumi::make_tuple(maps(index<N>, get<0>(pos))...);
      }(get<1>(pos));
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
