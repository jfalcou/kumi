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
  //! @brief  Returns a product type with consecutive duplicate types removed (pairwise uniqueness).
  //! @param  t Product type to process
  //! @return A product type containing elements from t with consecutive duplicates removed.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<product_type T> struct unique;
  //!
  //!   template<product_type T>
  //!   using unique_t = typename unique<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::unique.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/unique.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto unique(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else
    {
      constexpr auto pos = _::uniqued(as<T>{});
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using ret_t = builder_make_t<T, raw_element_t<pos.t[I], T>...>;
        return ret_t{get<pos.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<pos.count>{});
    }
  };

  //================================================================================================
  //! @ingroup generators
  //! @brief  Return the product type containing the values of the first occurence of each type
  //!         in the input product type.
  //! @param  t Product type to process
  //! @return A product type built by keeping the first occurrence of every distinct element type
  //!         in the input product type.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<product_type T> struct all_unique;
  //!
  //!   template<product_type T>
  //!   using all_unique_t = typename all_unique<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::all_unique.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/all_unique.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_unique(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::make_unique{builder_make_t<T, raw_element_t<0, T>>{get<0>(KUMI_FWD(t))}} | ... |
                _::make_unique<raw_element_t<I + 1, T>>{get<I + 1>(KUMI_FWD(t))})
          .acc;
      }(std::make_index_sequence<size_v<T> - 1>{});
    }
  }

  namespace result
  {
    template<concepts::product_type T> struct unique
    {
      using type = decltype(kumi::unique(std::declval<T>()));
    };

    template<concepts::product_type T> struct all_unique
    {
      using type = decltype(kumi::all_unique(std::declval<T>()));
    };

    template<concepts::product_type T> using unique_t = typename unique<T>::type;

    template<concepts::product_type T> using all_unique_t = typename all_unique<T>::type;
  }
}
