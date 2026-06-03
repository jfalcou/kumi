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
  namespace _
  {
    template<typename T, typename... Ts>
    inline constexpr bool contains = ((kumi::concepts::field<T> && std::invocable<T, kumi::_::tag_of_t<Ts>>) || ...);
  }

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a product type contains a given identifier

    @param t  the product type to inspect.
    @param id Identifier to check
    @return   `std::true_type` if the `t` contains a field labeled with the `id` identifier, `std::false_type`
  otherwise.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, concepts::identifier ID> struct contains;

      template<product_type T, concepts::identifier ID>
      using contains_t = typename contains<T,ID>::type;
    }
    @endcode

    Computes the type returned by a call to contains.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/contains.cpp
    ### Record:
    @include doc/record/algo/contains.cpp
  **/
  //====================================================================================================================
  struct contains_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier ID>
    [[nodiscard]] KUMI_ABI constexpr auto operator()([[maybe_unused]] T&& t,
                                                     [[maybe_unused]] ID const& id) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else return (*this)(KUMI_FWD(t), id, std::make_index_sequence<kumi::size_v<T>>{});
    }

  protected:
    template<typename T, typename ID, std::size_t... I>
    constexpr auto operator()(T&&, ID const&, std::index_sequence<I...>) const
    {
      return std::bool_constant<kumi::_::can_get_field_by_value<std::remove_cvref_t<ID>, kumi::element_t<I, T>...>>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a product type contains at least one of many identifiers

    @param t    the product type to inspect.
    @param ids  Identifiers to check
    @return     `std::true_type` if `t` contains a field labeld by one of the `ids`, and `std::false_type` otherwise.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, concepts::identifier... ID> struct contains_any;

      template<product_type T, concepts::identifier... ID>
      using contains_any_t = typename contains_any<T,ID...>::type;
    }
    @endcode

    Computes the type returned by a call to contains_any.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/contains_any.cpp
    ### Record:
    @include doc/record/algo/contains_any.cpp
  **/
  //====================================================================================================================
  struct contains_any_t : private contains_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()([[maybe_unused]] T&& t, Is const&... ids) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else if constexpr (sizeof...(Is) == 0) return std::false_type{};
      else
        return std::bool_constant<(
          decltype(contains_t::operator()(std::declval<T>(), ids, std::make_index_sequence<kumi::size_v<T>>{})){} ||
          ...)>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a product type contains fields based only on selected identifiers

    @param t    the product type to inspect.
    @param ids  Identifiers to check
    @return     `std::true_type` if `t` contains a field labeled by any of the `ids`, and `std::false_type` otherwise.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, concepts::identifier... ID> struct contains_only;

      template<product_type T, concepts::identifier... ID>
      using contains_only_t = typename contains_only<T,ID...>::type;
    }
    @endcode

    Computes the type returned by a call to contains_only.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/contains_only.cpp
    ### Record:
    @include doc/record/algo/contains_only.cpp
  **/
  //====================================================================================================================
  struct contains_only_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()([[maybe_unused]] T&& t,
                                                     [[maybe_unused]] Is const&... ids) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else if constexpr (sizeof...(Is) == 0) return std::false_type{};
      else if constexpr (sizeof...(Is) < kumi::size_v<T>) return std::false_type{};
      else return (*this)(KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{}, ids...);
    }

  protected:
    template<typename T, std::size_t... I, typename... Is>
    constexpr auto operator()(T&&, std::index_sequence<I...>, Is const&...) const
    {
      return std::bool_constant<(kumi::_::contains<kumi::element_t<I, T>, Is...> && ...)>{};
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a product type contains no fields based on any of the selected identifiers

    @param t    the product type to inspect.
    @param ids  Identifiers to check
    @return     `std::true_type` if `t` contains no field labeled by any of the `ids`, and `std::false_type` otherwise.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, concepts::identifier... ID> struct contains_none;

      template<product_type T, concepts::identifier... ID>
      using contains_none_t = typename contains_none<T,ID...>::type;
    }
    @endcode

    Computes the type returned by a call to contains_none.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/contains_none.cpp
    ### Record:
    @include doc/record/algo/contains_none.cpp
  **/
  //====================================================================================================================
  struct contains_none_t : private contains_any_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()([[maybe_unused]] T&& t, Is const&... ids) const noexcept
    {
      using R = decltype(contains_any_t::operator()(std::declval<T>(), ids...));
      return std::bool_constant<!R{}>{};
    }
  };

  inline constexpr contains_t contains{};
  inline constexpr contains_any_t contains_any{};
  inline constexpr contains_only_t contains_only{};
  inline constexpr contains_none_t contains_none{};

  namespace result
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier ID> struct contains
    {
      using type = decltype(kumi::contains(std::declval<T>(), std::declval<ID>()));
    };

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_any
    {
      using type = decltype(kumi::contains_any(std::declval<T>(), std::declval<IDs>()...));
    };

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_only
    {
      using type = decltype(kumi::contains_only(std::declval<T>(), std::declval<IDs>()...));
    };

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_none
    {
      using type = decltype(kumi::contains_none(std::declval<T>(), std::declval<IDs>()...));
    };

    template<kumi::concepts::product_type T, kumi::concepts::identifier ID>
    using contains_t = typename kumi::result::contains<T, ID>::type;

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_any_t = typename kumi::result::contains_any<T, IDs...>::type;

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_only_t = typename kumi::result::contains_only<T, IDs...>::type;

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_none_t = typename kumi::result::contains_none<T, IDs...>::type;

  }
}
