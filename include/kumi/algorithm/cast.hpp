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
    template<typename T, auto> struct repeat
    {
      using type = T;
    };

    template<typename T, auto I> using repeat_t = typename repeat<T, I>::type;

    template<typename T, auto N> struct as_homogeneous
    {
      template<std::size_t... I>
      static consteval auto homogeneify(std::index_sequence<I...>) -> tuple<repeat_t<T, I>...>;

      using type = std::remove_cvref_t<decltype(homogeneify(std::make_index_sequence<N>{}))>;
    };

    template<typename T, auto N> using as_homogeneous_t = typename as_homogeneous<T, N>::type;
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a product_type<Ts...> to an instance of a product_type<Target...>
  //!
  //! @tparam Target destination type to associate to each member of the product type
  //! @param  t Product type to convert
  //! @return A Product type containing the values of b where each member is of type Target
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Target, product_type T> struct member_cast;
  //!
  //!   template<typename Target, Product_type T>
  //!   using member_cast_t = typename member_cast<Target, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::member_cast
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/member_cast.cpp
  //! @include doc/record/algo/member_cast.cpp
  //================================================================================================
  template<typename Target, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto member_cast(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>)
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, result::field_cast_t<Target, element_t<I, T>>...>;
        return type{field_cast<Target>(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<size_v<T>>{});
    else
    {
      using type = _::as_homogeneous_t<Target, size_v<T>>;
      return static_cast<type>(KUMI_FWD(t));
    }
  }

  namespace result
  {
    template<typename Target, concepts::product_type T> struct member_cast
    {
      using type = decltype(kumi::member_cast<Target, T>(std::declval<T>()));
    };

    template<typename Target, concepts::product_type T> using member_cast_t = typename member_cast<Target, T>::type;
  }
}
