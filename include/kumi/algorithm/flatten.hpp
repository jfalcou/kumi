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
  //! @brief Converts a product type of product types into a product type of all elements.
  //!
  //! @param ts Product Type to flatten
  //! @return A product type composed of all elements of t flattened non-recursively
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct flatten;
  //!
  //!   template<product_type Tuple>
  //!   using flatten_t = typename flatten<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::flatten
  //!
  //! ## Example
  //! @include doc/flatten.cpp
  //================================================================================================
  template<product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto flatten(Tuple &&ts)
  {
    if constexpr(sized_product_type<Tuple,0>) return ts;
    else
    {
      return kumi::apply( [](auto&&... m)
                          {
                            auto v_or_t = []<typename V>(V&& v)
                            {
                              if constexpr(product_type<V>) return KUMI_FWD(v);
                              else                          return kumi::tuple{KUMI_FWD(v)};
                            };

                            return cat( v_or_t(KUMI_FWD(m))... );
                          }
                        , KUMI_FWD(ts)
                        );
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Recursively converts a product type of product types into a product type of all elements.
  //!
  //! Recursively converts a product type of product types `t` into a product type of all elements of said product types.
  //! If the Callable object f is provided, non-product type elements are processed by `f` before being
  //! inserted.
  //!
  //! @param ts Product Type to flatten
  //! @param f  Optional Callable object to apply when a sub-product type is flattened
  //! @return A product type composed of all elements of t flattened recursively
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Func = void> struct flatten_all;
  //!
  //!   template<product_type Tuple, typename Func = void>
  //!   using flatten_all_t = typename flatten_all<Tuple, Func>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::flatten_all
  //!
  //! ## Example
  //! @include doc/flatten_all.cpp
  //================================================================================================
  template<product_type Tuple, typename Func>
  [[nodiscard]] KUMI_ABI constexpr auto flatten_all(Tuple&& ts, Func&& f)
  {
    if constexpr(sized_product_type<Tuple,0>) return ts;
    else
    {
      return kumi::apply( [&](auto&&... m)
                          {
                            auto v_or_t = [&]<typename V>(V&& v)
                            {
                              if constexpr(product_type<V>)
                                return flatten_all(KUMI_FWD(v),KUMI_FWD(f));
                              else
                                return kumi::tuple{KUMI_FWD(f)(v)};
                            };

                            return cat( v_or_t(KUMI_FWD(m))... );
                          }
                        , KUMI_FWD(ts)
                        );
    }
  }

  /// @overload
  template<product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(Tuple&& ts)
  {
    if constexpr(sized_product_type<Tuple,0>) return ts;
    else
    {
      return kumi::apply( [](auto&&... m)
                          {
                            auto v_or_t = []<typename V>(V&& v)
                            {
                              if constexpr(product_type<V>) return flatten_all(KUMI_FWD(v));
                              else                          return kumi::tuple{KUMI_FWD(v)};
                            };

                            return cat( v_or_t(KUMI_FWD(m))... );
                          }
                        , KUMI_FWD(ts)
                        );
    }
  }


  namespace result
  {
    template<product_type Tuple> struct flatten
    {
      using type = decltype( kumi::flatten( std::declval<Tuple>() ) );
    };

    template<product_type Tuple, typename Func = void> struct flatten_all
    {
      using type = decltype( kumi::flatten_all( std::declval<Tuple>(), std::declval<Func>() ) );
    };

    template<product_type Tuple> struct flatten_all<Tuple>
    {
      using type = decltype( kumi::flatten_all( std::declval<Tuple>() ) );
    };

    template<product_type Tuple> using flatten_t      = typename flatten<Tuple>::type;

    template<product_type Tuple, typename Func = void>
    using flatten_all_t  = typename flatten_all<Tuple, Func>::type;
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Convert a kumi::product_type to a flat product type of pointers to each its components.
  //!
  //! @param ts Product Type to convert
  //! @return A flat product type composed of pointers to each elements of t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct as_flat_ptr;
  //!
  //!   template<product_type Tuple>
  //!   using as_flat_ptr_t = typename as_flat_ptr<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::as_flat_ptr
  //!
  //! ## Example
  //! @include doc/as_flat_ptr.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI auto as_flat_ptr(Tuple&& ts) noexcept
  {
    return kumi::flatten_all(KUMI_FWD(ts), [](auto& m) { return &m; });
  }

  namespace result
  {
    template<product_type T> struct as_flat_ptr
    {
      using type = decltype( kumi::as_flat_ptr( std::declval<T>() ) );
    };

    template<product_type T>
    using as_flat_ptr_t = typename as_flat_ptr<T>::type;
  }
}
