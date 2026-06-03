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
  struct zip_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::sized_product_type<kumi::size_v<T0>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      if constexpr (kumi::concepts::sized_product_type<T0, 0>) return kumi::tuple{};
      else
      {
        constexpr auto c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<kumi::size_v<T0>>);
        return (*this)(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }

  protected:
    template<typename T, std::size_t... I, std::size_t... J>
    constexpr auto operator()(T&& t, std::index_sequence<I...>, std::index_sequence<J...> is) const
    {
      return kumi::make_tuple((*this)(KUMI_FWD(t), kumi::index<I>, is)...);
    }

    template<typename T, std::size_t N, std::size_t... I>
    constexpr auto operator()(T&& t, kumi::index_t<N>, std::index_sequence<I...>) const
    {
      using U = kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>;
      return kumi::builder<U>::make(get<N>(get<I>(KUMI_FWD(t)))...);
    }
  };

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
  struct zip_min_t : private kumi::zip_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      constexpr std::size_t m = kumi::_::min(kumi::size_v<T0>, kumi::size_v<Ts>...);
      if constexpr (m == 0) return kumi::tuple{};
      else
      {
        constexpr std::size_t c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<m>);
        return this->zip_t::operator()(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }
  };

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
  struct zip_max_t
  {
    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T0&& t0, Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<T0, Ts...>)
    {
      constexpr std::size_t m = kumi::_::max(kumi::size_v<T0>, kumi::size_v<Ts>...);
      if constexpr (m == 0) return kumi::tuple{};
      else
      {
        constexpr std::size_t c = 1 + sizeof...(Ts);
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<m>);
        return (*this)(kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }

  private:
    template<typename T, std::size_t... I, std::size_t... J>
    constexpr auto operator()(T&& t, std::index_sequence<I...>, std::index_sequence<J...> is) const
    {
      return kumi::make_tuple((*this)(KUMI_FWD(t), kumi::index<I>, is)...);
    }

    template<typename T, std::size_t N, std::size_t... I>
    constexpr auto operator()(T&& t, kumi::index_t<N>, std::index_sequence<I...>) const
    {
      using U = kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>;
      return kumi::builder<U>::make(kumi::function::get_or<N>(get<I>(KUMI_FWD(t)), kumi::none)...);
    }
  };

  inline constexpr zip_t zip{};
  inline constexpr zip_min_t zip_min{};
  inline constexpr zip_max_t zip_max{};

  namespace result
  {
    template<kumi::concepts::product_type T0, kumi::concepts::sized_product_type<kumi::size_v<T0>>... Ts> struct zip
    {
      using type = decltype(kumi::zip(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts> struct zip_min
    {
      using type = decltype(kumi::zip_min(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts> struct zip_max
    {
      using type = decltype(kumi::zip_max(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_t = typename kumi::result::zip<T0, Ts...>::type;

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_min_t = typename kumi::result::zip_min<T0, Ts...>::type;

    template<kumi::concepts::product_type T0, kumi::concepts::product_type... Ts>
    using zip_max_t = typename kumi::result::zip_max<T0, Ts...>::type;
  }
}
