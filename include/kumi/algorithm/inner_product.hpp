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
    //==================================================================================================================
    // Fold helpers
    //==================================================================================================================
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
  }

  //====================================================================================================================
  //! @ingroup  reductions
  //! @brief    Computes inner product (i.e. sum of products)
  //!
  //! Computes the generalized sum of products of the elements of two product types. By default,
  //! `+` and `*` is used.
  //!
  //! On record types, operates by pair of fields sharing the same label.
  //!
  //! @note Does not participate in overload resolution if product types' size are not equal or if any of
  //!       the binary operations can't be applied on the product types' elements. Similarily, doesn't participate
  //!       in overload resolution if the two inputs do not model concepts::compatible_product_types.
  //!
  //! @param s1         First product type to operate on
  //! @param s2         Second product type to operate on
  //! @param init       Initial value
  //! @param sum        Binary callable function to use as the sum operations
  //! @param prod       Binary callable function to use as the product operations
  //! @return The inner product of `s1` and `s2` using the provided binary operations.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type S1, sized_product_type<size_v<S1>> S2, typename T>
  //!   struct inner_product;
  //!
  //!   template<product_type S1, sized_product_type<size_v<S1>> S2, typename T
  //!           , typename Sum, typename Prod
  //!           >
  //!   struct inner_product;
  //!
  //!   template<product_type S1, sized_product_type<size_v<T1>> S2, typename T>
  //!   using inner_product_t = typename inner_product<S1,S2,T>::type;
  //!
  //!   template< product_type S1, sized_product_type<size_v<T1>> S2, typename T
  //!           , typename Sum, typename Prod
  //!           >
  //!   using inner_product_t = typename inner_product<S1,S2,T,Sum,Prod>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::inner_product
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/inner_product.cpp
  //! @include doc/record/algo/inner_product.cpp
  //====================================================================================================================
  template<concepts::product_type S1,
           concepts::sized_product_type<size_v<S1>> S2,
           typename T,
           typename Sum,
           typename Prod>
  requires(concepts::compatible_product_types<S1, S2>)
  [[nodiscard]] KUMI_ABI constexpr auto inner_product(S1&& s1, S2&& s2, T init, Sum sum, Prod prod) noexcept
  {
    if constexpr (concepts::sized_product_type<S1, 0>) return init;
    else if constexpr (concepts::record_type<S1>)
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{sum, invoke(prod, get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s1)),
                                        get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s2)))} >>
                ... >> _::foldable{sum, init})
          .value;
      }(std::make_index_sequence<size<S1>::value>());
    }
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{sum, invoke(prod, get<I>(KUMI_FWD(s1)), get<I>(KUMI_FWD(s2)))} >> ... >>
                _::foldable{sum, init})
          .value;
      }(std::make_index_sequence<size<S1>::value>());
    }
  }

  //! @overload
  template<concepts::product_type S1, concepts::sized_product_type<size_v<S1>> S2, typename T>
  requires(concepts::compatible_product_types<S1, S2>)
  [[nodiscard]] KUMI_ABI constexpr auto inner_product(S1&& s1, S2&& s2, T init) noexcept
  {
    if constexpr (concepts::sized_product_type<S1, 0>) return init;
    else if constexpr (concepts::record_type<S1>)
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (
          init + ... +
          (get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s1)) * get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s2))));
      }(std::make_index_sequence<size<S1>::value>());
    }
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (init + ... + (get<I>(KUMI_FWD(s1)) * get<I>(KUMI_FWD(s2))));
      }(std::make_index_sequence<size<S1>::value>());
    }
  }

  namespace result
  {
    template<concepts::product_type S1,
             concepts::sized_product_type<S1::size()> S2,
             typename T,
             typename Sum,
             typename Prod>
    struct inner_product
    {
      using type = decltype(kumi::inner_product(
        std::declval<S1>(), std::declval<S2>(), std::declval<T>(), std::declval<Sum>(), std::declval<Prod>()));
    };

    template<concepts::product_type S1, concepts::sized_product_type<S1::size()> S2, typename T>
    struct inner_product<S1, S2, T, void, void>
    {
      using type = decltype(kumi::inner_product(std::declval<S1>(), std::declval<S2>(), std::declval<T>()));
    };

    template<concepts::product_type S1,
             concepts::sized_product_type<S1::size()> S2,
             typename T,
             typename Sum = void,
             typename Prod = void>
    using inner_product_t = typename inner_product<S1, S2, T, Sum, Prod>::type;
  }
}
