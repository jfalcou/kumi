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
  namespace _
  {
    //==============================================================================================
    // Fold helpers
    //==============================================================================================
    template<typename F, typename T> struct foldable
    {
      F func;
      T value;

      template<typename W>
      KUMI_ABI friend constexpr decltype(auto) operator>>(foldable &&x, foldable<F, W> &&y)
      {
        return _::foldable {x.func, x.func(y.value, x.value)};
      }

      template<typename W>
      KUMI_ABI friend constexpr decltype(auto) operator<<(foldable &&x, foldable<F, W> &&y)
      {
        return _::foldable {x.func, x.func(x.value, y.value)};
      }
    };

    template<class F, class T> foldable(const F &, T &&) -> foldable<F, T>;
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes inner product (i.e. sum of products)
  //!
  //! Computes the generalized sum of products of the elements of two product types. By default,
  //! `+` and `*` is used.
  //!
  //! @note Does not participate in overload resolution if tuples' size are not equal or if any of
  //!       the binary operations can't be applied on the tuples' elements.
  //!
  //! @param s1         First tuple to operate on
  //! @param s2         Second tuple to operate on
  //! @param init       Initial value
  //! @param sum        Binary callable function to use as the sum operations
  //! @param prod       Binary callable function to use as the product operations
  //! @return The inner product of `s1` and `s2` using the provided binary operations.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type S1, sized_product_type<S1::size()> S2, typename T>
  //!   struct inner_product;
  //!
  //!   template<product_type S1, sized_product_type<S1::size()> S2, typename T
  //!           , typename Sum, typename Prod
  //!           >
  //!   struct inner_product;
  //!
  //!   template<product_type S1, sized_product_type<S1::size()> S2, typename T>
  //!   using inner_product_t = typename inner_product<S1,S2,T>::type;
  //!
  //!   template< product_type S1, sized_product_type<S1::size()> S2, typename T
  //!           , typename Sum, typename Prod
  //!           >
  //!   using inner_product_t = typename inner_product<S1,S2,T,Sum,Prod>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map
  //!
  //! ## Example
  //! @include doc/inner_product.cpp
  //================================================================================================
  template< product_type S1, sized_product_type<S1::size()> S2, typename T
          , typename Sum, typename Prod
          >
  [[nodiscard]] KUMI_ABI constexpr auto inner_product( S1 const& s1, S2 const& s2, T init
                                            , Sum sum, Prod prod
                                            ) noexcept
  {
    if constexpr(sized_product_type<S1,0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return  (  _::foldable {sum, prod(get<I>(KUMI_FWD(s1)),get<I>(KUMI_FWD(s2)))}
                >> ...
                >> _::foldable {sum, init}
                ).value;
      }
      (std::make_index_sequence<size<S1>::value>());
    }
  }

  //! @overload
  template<product_type S1, sized_product_type<S1::size()> S2, typename T>
  [[nodiscard]] KUMI_ABI constexpr auto inner_product(S1 const& s1, S2 const& s2, T init) noexcept
  {
    if constexpr(sized_product_type<S1,0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (init + ... + (get<I>(s1) * get<I>(s2)));
      }(std::make_index_sequence<size<S1>::value>());
    }
  }


  namespace result
  {
    template< product_type S1, sized_product_type<S1::size()> S2, typename T
            , typename Sum, typename Prod
            >
    struct inner_product
    {
      using type = decltype ( kumi::inner_product ( std::declval<S1>(), std::declval<S2>()
                                                  , std::declval<T>()
                                                  , std::declval<Sum>(), std::declval<Prod>()
                                                  )
                            );
    };

    template< product_type S1, sized_product_type<S1::size()> S2, typename T>
    struct inner_product<S1,S2,T,void,void>
    {
      using type = decltype ( kumi::inner_product ( std::declval<S1>(), std::declval<S2>()
                                                  , std::declval<T>()
                                                  )
                            );
    };

    template< product_type S1, sized_product_type<S1::size()> S2, typename T
            , typename Sum = void, typename Prod = void
            >
    using inner_product_t  = typename inner_product<S1,S2,T,Sum,Prod>::type;
  }
}
