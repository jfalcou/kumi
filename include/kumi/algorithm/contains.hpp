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

    template<typename T, typename ID, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto contains_(kumi::_::adl_tag_t, T&&, ID const&, std::index_sequence<I...>)
    {
      return std::bool_constant<
        kumi::concepts::contains_identifier<std::remove_cvref_t<ID>, kumi::element_t<I, T>...>>{};
    }

    template<typename T, std::size_t... I, typename... Is>
    KUMI_HIDDEN_ABI constexpr auto contains_only_(kumi::_::adl_tag_t, T&&, std::index_sequence<I...>, Is const&...)
    {
      return std::bool_constant<(kumi::_::contains<kumi::element_t<I, T>, Is...> && ...)>{};
    }
  }

  struct contains_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier ID>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, ID const& id) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else return contains_(kumi::_::adl_tag, KUMI_FWD(t), id, kumi::function::indexes_for<T>{});
    }
  };

  struct contains_any_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&&, Is const&... ids) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else if constexpr (sizeof...(Is) == 0) return std::false_type{};
      else
        return std::bool_constant<(
          decltype(contains_(kumi::_::adl_tag, std::declval<T>(), ids, kumi::function::indexes_for<T>{})){} || ...)>{};
    }
  };

  struct contains_only_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Is const&... ids) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return std::false_type{};
      else if constexpr (sizeof...(Is) == 0) return std::false_type{};
      else if constexpr (sizeof...(Is) < kumi::size_v<T>) return std::false_type{};
      else return contains_only_(kumi::_::adl_tag, KUMI_FWD(t), kumi::function::indexes_for<T>{}, ids...);
    }
  };

  struct contains_none_t : private contains_any_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::identifier... Is>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&&, Is const&... ids) const noexcept
    {
      using R = decltype(contains_any_t::operator()(std::declval<T>(), ids...));
      return std::bool_constant<!R{}>{};
    }
  };

  //====================================================================================================================
  //! @defgroup kumi_contains kumi::contains
  //! @ingroup kumi_queries
  //! @brief Callable object checking if a product type contains a given identifier
  //====================================================================================================================
  /**
    @ingroup kumi_contains

    @var contains

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, concepts::identifier ID>
        constexpr auto contains(T && t, ID const& id) noexcept;
      }
    @endcode

    @subgroupheader{Parameters}

      - `t`: The product type to inspect
      - `id`: The identifier to check for

    @subgroupheader{Return value}

      - `std::true_type` if `t` contains a field labeled with the `id` identifier, `std::false_type` otherwise.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/contains.hpp contains_t

    Computes the return type of a call to kumi::contains

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/contains.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/contains.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr contains_t contains{};

  //====================================================================================================================
  //! @defgroup kumi_contains_any kumi::contains_any
  //! @ingroup kumi_queries
  //! @brief Callable object checking if a product type contains at least one of many identifier
  //====================================================================================================================
  /**
    @ingroup kumi_contains_any

    @var contains_any

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, concepts::identifier... IDs>
        constexpr auto contains_any(T && t, IDs const&... ids) noexcept;
      }
    @endcode

    @subgroupheader{Parameters}

      - `t`: The product type to inspect
      - `ids`: The identifiers to check for

    @subgroupheader{Return value}

      - `std::true_type` if `t` contains a field labeled with one of the `ids`, `std::false_type` otherwise.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/contains.hpp contains_any_t

    Computes the return type of a call to kumi::contains_any

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/contains_any.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/contains_any.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr contains_any_t contains_any{};

  //====================================================================================================================
  //! @defgroup kumi_contains_only kumi::contains_only
  //! @ingroup kumi_queries
  //! @brief Callable object checking if a product type contains fields based on a selected identifier
  //====================================================================================================================
  /**
    @ingroup kumi_contains_only

    @var contains_only

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, concepts::identifier... IDs>
        constexpr auto contains_only(T && t, IDs const&... ids) noexcept;
      }
    @endcode

    @subgroupheader{Parameters}

      - `t`: The product type to inspect
      - `ids`: The identifiers to check for

    @subgroupheader{Return value}

      - `std::true_type` if `t` contains a field labeled with any of the `ids`, `std::false_type` otherwise.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/contains.hpp contains_only_t

    Computes the return type of a call to kumi::contains_only

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/contains_only.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/contains_only.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr contains_only_t contains_only{};

  //====================================================================================================================
  //! @defgroup kumi_contains_none kumi::contains_none
  //! @ingroup kumi_queries
  //! @brief Callable object checking if a product type contains no fields based on any of the selected identifiers
  //====================================================================================================================
  /**
    @ingroup kumi_contains_none

    @var contains_none

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/kumi.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      namespace kumi
      {
        template<concepts::product_type T, concepts::identifier... IDs>
        constexpr auto contains_none(T && t, IDs const&... ids) noexcept;
      }
    @endcode

    @subgroupheader{Parameters}

      - `t`: The product type to inspect
      - `ids`: The identifiers to check for

    @subgroupheader{Return value}

      - `std::true_type` if `t` contains no field labeled with any of the `ids`, `std::false_type` otherwise.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/contains.hpp contains_none_t

    Computes the return type of a call to kumi::contains_none

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/contains_none.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/contains_none.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr contains_none_t contains_none{};

  namespace result
  {
    //! [contains_t]
    template<kumi::concepts::product_type T, kumi::concepts::identifier ID>
    using contains_t = decltype(kumi::contains(std::declval<T>(), std::declval<ID>()));

    template<kumi::concepts::product_type T, kumi::concepts::identifier ID> struct contains
    {
      using type = kumi::result::contains_t<T, ID>;
    };

    //! [contains_t]

    //! [contains_any_t]
    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_any_t = decltype(kumi::contains_any(std::declval<T>(), std::declval<IDs>()...));

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_any
    {
      using type = kumi::result::contains_any_t<T, IDs...>;
    };

    //! [contains_any_t]

    //! [contains_only_t]
    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_only_t = decltype(kumi::contains_only(std::declval<T>(), std::declval<IDs>()...));

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_only
    {
      using type = kumi::result::contains_only_t<T, IDs...>;
    };

    //! [contains_only_t]

    //! [contains_none_t]
    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs>
    using contains_none_t = decltype(kumi::contains_none(std::declval<T>(), std::declval<IDs>()...));

    template<kumi::concepts::product_type T, kumi::concepts::identifier... IDs> struct contains_none
    {
      using type = kumi::result::contains_none_t<T, IDs...>;
    };

    //! [contains_none_t]
  }
}
