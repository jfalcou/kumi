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
    struct map_t
    {
      template<typename F, typename T, typename... Ts>
      KUMI_ABI constexpr auto operator()(auto N, F f, T&& t, Ts&&... ts) const
      {
        if constexpr (kumi::concepts::record_type<T>)
        {
          constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
          return kumi::capture_field<field>(kumi::invoke(f, get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...));
        }
        else return kumi::invoke(f, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
      }
    };

    struct map_index_t
    {
      KUMI_ABI constexpr auto operator()(auto N, auto f, auto&&... args) const
      {
        return kumi::invoke(f, N, get<N>(KUMI_FWD(args))...);
      }
    };

    struct map_field_t
    {
      template<typename F, typename T, typename... Ts>
      KUMI_ABI constexpr auto operator()(auto N, F f, T&& t, Ts&&... ts) const
      {
        constexpr auto field = kumi::identifier_of<kumi::element_t<N, T>>();
        return kumi::capture_field<field>(
          kumi::invoke(f, kumi::_::make_str(field), get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...));
      }
    };

    inline constexpr map_t map_case{};
    inline constexpr map_index_t map_index_case{};
    inline constexpr map_field_t map_field_case{};

    template<typename T, typename F, std::size_t... I>
    KUMI_ABI constexpr decltype(auto) map_(kumi::_::adl_tag_t, T&&, F&& f, std::index_sequence<I...>)
    {
      if constexpr (sizeof...(I) == 0) return kumi::builder<T>::make();
      else return kumi::builder<T>::make(kumi::invoke(KUMI_FWD(f), kumi::index<I>)...);
    }
  }

  struct map_t
  {
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t0, Ts&&... others) const
    requires(kumi::concepts::compatible_product_types<T, Ts...>) && (kumi::_::supports_call<Function, T &&, Ts && ...>)
    {
      using binded_t = kumi::_::bind_t<kumi::_::Binding::back, kumi::_::map_t, Function, T, Ts...>;
      auto&& bound = binded_t{kumi::_::map_case, f, KUMI_FWD(t0), KUMI_FWD(others)...};
      return map_(kumi::_::adl_tag, KUMI_FWD(t0), KUMI_FWD(bound), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct map_index_t
  {
    template<kumi::concepts::product_type T,
             typename Function,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t0, Ts&&... others) const
    requires(!kumi::concepts::record_type<T> && (!kumi::concepts::record_type<Ts> && ...))
    {
      using binded_t = kumi::_::bind_t<kumi::_::Binding::back, kumi::_::map_index_t, Function, T, Ts...>;
      auto&& bound = binded_t{kumi::_::map_index_case, f, KUMI_FWD(t0), KUMI_FWD(others)...};
      return map_(kumi::_::adl_tag, KUMI_FWD(t0), KUMI_FWD(bound), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  struct map_field_t
  {
    template<kumi::concepts::record_type T,
             typename Function,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t0, Ts&&... others) const
    requires(kumi::concepts::compatible_product_types<T, Ts...>)
    {
      using binded_t = kumi::_::bind_t<kumi::_::Binding::back, kumi::_::map_field_t, Function, T, Ts...>;
      auto&& bound = binded_t{kumi::_::map_field_case, f, KUMI_FWD(t0), KUMI_FWD(others)...};
      return map_(kumi::_::adl_tag, KUMI_FWD(t0), KUMI_FWD(bound), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup transforms

    @var map
    @brief Callable object applying the Callable object `f` on each product types' elements

    Applies the given function to all the product types passed as arguments and stores the result in another product
    type, keeping the original elements order. On records, the order is determined via the order of definition of
    the fields.

    @note Does not participate in overload resolution if product types' size are not equal or if
          `f` can't be called on each product type's elements. All product type must either be
          record types or product types, mixing is not supported.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_t

    Computes the return type of a call to kumi::map

    @see kumi::map_index
    @see kumi::map_field

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/map.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/map.cpp}
  **/
  //====================================================================================================================
  inline constexpr map_t map{};

  //====================================================================================================================
  /**
    @ingroup tuple_transforms

    @var map_index
    @brief Callable object applying the Callable object `f` on each product types elements and their indexes

    Applies the given function to all the product types passed as arguments along with their indexes and stores the
  result in another product type, keeping the original elements order.

    @note Does not participate in overload resolution if tuples' size are not equal or if `f`
          can't be called on each tuple's elements and their indexes.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map_index(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_index_t

    Computes the return type of a call to kumi::map_index

    @see kumi::map
    @see kumi::map_field

    @groupheader{Example}

    @godbolt{doc/tuple/algo/map_index.cpp}
  **/
  //====================================================================================================================
  inline constexpr map_index_t map_index{};

  //====================================================================================================================
  /**
    @ingroup record_transforms

    @var map_field
    @brief Callable object applying the Callable object `f` on each product types elements and their associated labels.

    Applies the given function to all the records passed as arguments along with their names and
    stores the result in another records, keeping the original elements order.

    @note Does not participate in overload resolution if records' size are not equal or if `f`
          can't be called on each record's fields and their names.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/map.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, product_type... Ts>
      constexpr auto map_index(Function && f, T && t, Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Callable object to apply
      - `t`: Product Type to operate on
      - `ts`: Other Product Types to operate on

    @subgroupheader{Return value}

      - The product type matching the common_product_type of the input containing `f` calls results.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/map.hpp map_field_t

    Computes the return type of a call to kumi::map_field

    @see kumi::map
    @see kumi::map_index

    @groupheader{Example}

    @godbolt{doc/record/algo/map_field.cpp}
  **/
  //====================================================================================================================
  inline constexpr map_field_t map_field{};

  namespace result
  {
    //! [map_t]
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map
    {
      using type = decltype(kumi::map(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_t = typename kumi::result::map<Function, T, Ts...>::type;

    //! [map_t]

    //! [map_index_t]
    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map_index
    {
      using type = decltype(kumi::map_index(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function,
             kumi::concepts::product_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_index_t = typename kumi::result::map_index<Function, T, Ts...>::type;

    //! [map_index_t]

    //! [map_field_t]
    template<typename Function,
             kumi::concepts::record_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    struct map_field
    {
      using type = decltype(kumi::map_field(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };

    template<typename Function,
             kumi::concepts::record_type T,
             kumi::concepts::sized_product_type<kumi::size_v<T>>... Ts>
    using map_field_t = typename kumi::result::map_field<Function, T, Ts...>::type;
    //! [map_field_t]
  }
}
