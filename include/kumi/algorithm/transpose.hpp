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
    @brief    Transpose a product type of product types by shifting elements in their transposed position always
              returning a tuple as the external product type.

    @param t Product type to transpose
    @return  A product type containing the transposed elements of `t`.

    @note This function will issue a compile time error if the each element of the input product type are not
          themselves product types or if their size are not equal.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct transpose;

      template<product_type T>
      using transpose_t = typename transpose<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::transpose

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/transpose.cpp
    ### Record:
    @include doc/record/algo/transpose.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto transpose(T&& t)
  {
    static_assert(_::supports_transpose<T>, "[KUMI] - Cannot transpose given product type");
    if constexpr (concepts::empty_product_type<T>) return tuple{};
    else if constexpr (concepts::record_type<T>) return transpose(values_of(KUMI_FWD(t)));
    else
    {
      constexpr std::size_t count = size_v<T>;
      constexpr std::size_t size = size_v<element_t<0, T>>;
      constexpr auto pos = function::zipper(index<count>, index<size>);

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        using type = builder_make_t<element_t<0, T>, element_t<k, std::remove_cvref_t<element_t<I, T>>>...>;
        return type{get<k>(get<I>(KUMI_FWD(t)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        return kumi::make_tuple(maps(index<N>, pos.tpl)...);
      }(pos.elt);
    }
  }

  namespace result
  {
    template<concepts::product_type T> struct transpose
    {
      using type = decltype(kumi::transpose(std::declval<T>()));
    };

    template<concepts::product_type T> using transpose_t = typename transpose<T>::type;
  }
}
