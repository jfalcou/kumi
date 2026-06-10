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
  struct inner_product_t
  {
    template<kumi::concepts::product_type S1,
             kumi::concepts::sized_product_type<kumi::size_v<S1>> S2,
             typename T,
             typename Sum,
             typename Prod>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(S1&& s1, S2&& s2, T init, Sum sum, Prod prod) const noexcept
    requires(kumi::concepts::compatible_product_types<S1, S2>)
    {
      if constexpr (kumi::concepts::empty_product_type<S1>) return init;
      else
        return this->inner_product_(KUMI_FWD(s1), KUMI_FWD(s2), init, sum, prod,
                                    std::make_index_sequence<kumi::size_v<S1>>{});
    }

    template<kumi::concepts::product_type S1, kumi::concepts::sized_product_type<kumi::size_v<S1>> S2, typename T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(S1&& s1, S2&& s2, T init) const noexcept
    requires(kumi::concepts::compatible_product_types<S1, S2>)
    {
      if constexpr (kumi::concepts::empty_product_type<S1>) return init;
      else
        return this->inner_product_fast_(KUMI_FWD(s1), KUMI_FWD(s2), init,
                                         std::make_index_sequence<kumi::size_v<S1>>{});
    }

    template<typename T, typename U, typename V, typename Sum, typename Prod, std::size_t... I>
    KUMI_ABI constexpr auto inner_product_(
      T&& t, U&& u, V init, Sum sum, Prod prod, std::index_sequence<I...>) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>)
        return (kumi::function::foldable{init} >> ... >>
                kumi::bind_back(sum, kumi::invoke(prod, get<kumi::identifier_of<kumi::element_t<I, T>>()>(KUMI_FWD(t)),
                                                  get<kumi::identifier_of<kumi::element_t<I, U>>()>(KUMI_FWD(u)))))();
      else
        return (kumi::function::foldable{init} >> ... >>
                kumi::bind_back(sum, kumi::invoke(prod, get<I>(KUMI_FWD(t)), get<I>(KUMI_FWD(u)))))();
    }

    template<typename T, typename U, typename V, std::size_t... I>
    KUMI_ABI constexpr auto inner_product_fast_(T&& t, U&& u, V init, std::index_sequence<I...>) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>)
        return (init + ... +
                (get<kumi::identifier_of<kumi::element_t<I, T>>()>(KUMI_FWD(t)) *
                 get<kumi::identifier_of<kumi::element_t<I, U>>()>(KUMI_FWD(u))));

      else return (init + ... + (get<I>(KUMI_FWD(t)) * get<I>(KUMI_FWD(u))));
    }
  };

  //====================================================================================================================
  /**
    @ingroup reductions

    @var apply
    @brief Callable object computing the inner product (i.e. sum of products)

    Computes the generalized sum of products of the elements of two product types. By default,
    `+` and `*` is used.

    On record types, operates by pair of fields sharing the same label.

    @note Does not participate in overload resolution if product types' size are not equal or if any of
          the binary operations can't be applied on the product types' elements. Similarily, doesn't participate
          in overload resolution if the two inputs are not compatible. @see concepts::compatible_product_types.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/inner_product.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type S1, product_type S2, typename T, typename Sum, typename Prod>
      constexpr auto inner_product(S1 && s1, S2 && s2, T init, Sum sum, Prod prod) noexcept;
    @endcode

    @code
      template<product_type S1, product_type S2, typename T>
      constexpr auto inner_product(S1 && s1, S2 && s2, T init) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `s1`: First product type to operate on
      - `s2`:         Second product type to operate on
      - `init`:       Initial value
      - `sum`:        Binary callable function to use as the sum operations
      - `prod`:       Binary callable function to use as the product operations

    @subgroupheader{Return value}

      - The inner product of `s1` and `s2` using the provided binary operations.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/inner_product.hpp  inner_product_t

    Computes the return type of a call to kumi::inner_product

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/inner_product.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/inner_product.cpp}
  **/
  //====================================================================================================================
  inline constexpr inner_product_t inner_product{};

  namespace result
  {
    //! [inner_product_t]
    template<kumi::concepts::product_type S1,
             kumi::concepts::sized_product_type<kumi::size_v<S1>> S2,
             typename T,
             typename Sum,
             typename Prod>
    struct inner_product
    {
      using type = decltype(kumi::inner_product(
        std::declval<S1>(), std::declval<S2>(), std::declval<T>(), std::declval<Sum>(), std::declval<Prod>()));
    };

    template<kumi::concepts::product_type S1, kumi::concepts::sized_product_type<kumi::size_v<S1>> S2, typename T>
    struct inner_product<S1, S2, T, void, void>
    {
      using type = decltype(kumi::inner_product(std::declval<S1>(), std::declval<S2>(), std::declval<T>()));
    };

    template<kumi::concepts::product_type S1,
             kumi::concepts::sized_product_type<kumi::size_v<S1>> S2,
             typename T,
             typename Sum = void,
             typename Prod = void>
    using inner_product_t = typename kumi::result::inner_product<S1, S2, T, Sum, Prod>::type;
    //! [inner_product_t]
  }
}
