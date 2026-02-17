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
  //! @brief Constructs a tuple where the ith element is the prduct type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @note Every inner product type should be of the same sizes, otherwise see `zip_min` or `zip_max`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip;
  //!
  //!   template<product_type T>
  //!   using zip_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip.cpp
  //================================================================================================
  template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    return _::zipper(index<size_v<T0>>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the prudct type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @ note `zip_min` truncates product types based on the smallest size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip_min;
  //!
  //!   template<product_type T>
  //!   using zip_min_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_min
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip_min.cpp
  //================================================================================================
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_min(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t min = _::min_size_v<T0, Ts...>();
    return _::zipper(index<min>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the product type of all ith elements of ts...
  //!
  //! @param t0 Product type to convert
  //! @param ts Product types to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @note `zip_max` fills missing elements to reach the biggest product type size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct zip_max;
  //!
  //!   template<product_type T>
  //!   using zip_max_t = typename zip<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_max
  //!
  //! ## Example
  //! @include doc/tuple/algo/zip_max.cpp
  //================================================================================================
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_max(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t max = _::max_size_v<T0, Ts...>();
    return _::zipper(index<max>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  namespace result
  {
    template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts> struct zip
    {
      using type = decltype(kumi::zip(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_min
    {
      using type = decltype(kumi::zip_min(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_max
    {
      using type = decltype(kumi::zip_max(std::declval<T0>(), std::declval<Ts>()...));
    };

    template<concepts::product_type T0, concepts::product_type... Ts> using zip_t = typename zip<T0, Ts...>::type;

    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_min_t = typename zip_min<T0, Ts...>::type;

    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_max_t = typename zip_max<T0, Ts...>::type;
  }
}
