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
    struct zipper_t
    {
      template<std::size_t Size, product_type Tuple>
      KUMI_ABI constexpr auto operator()(index_t<Size> const&, Tuple&& t) const noexcept
      {
        if constexpr(sized_product_type<Tuple,0>) return t;
        else
        {
          constexpr auto uz = []<typename N>(N const &, auto &&u)
          {
            return apply([](auto &&...m)
            {
              auto zip_ = [&]<product_type V>(V&& v)
              {
                if constexpr ( size_v<V> <= N::value ) return none;
                else                                  return get<N::value>(KUMI_FWD(v));
              };
              return _::builder<Tuple>::make(zip_(KUMI_FWD(m))...);
            }, KUMI_FWD(u));
          };

          return [&]<std::size_t... I>(std::index_sequence<I...>)
          {
             return _::builder<Tuple>::make(uz(index_t<I> {}, KUMI_FWD(t))...);
          }(std::make_index_sequence<Size>());
        }
      }
    };

    inline constexpr zipper_t zipper{};

    template<typename T0, typename... Ts>
    consteval std::size_t min_size_v() 
    {
        std::size_t result = size_v<T0>;
        if constexpr(sizeof...(Ts) == 0) return result;
        else return ((result = result < size_v<Ts> ? result : size_v<Ts>), ...);
    };

    template<typename T0, typename... Ts>
    consteval std::size_t max_size_v() 
    {
        std::size_t result = size_v<T0>;
        if constexpr(sizeof...(Ts) == 0) return result;
        else return ((result = result > size_v<Ts> ? result : size_v<Ts>), ...);
    };
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the tuple of all ith elements of ts...
  //!
  //! @param t0 Tuple to convert
  //! @param ts Tuples to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @ note Every inner tuple should be of the same sizes, otherwise see `zip_min` or `zip_max`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct zip;
  //!
  //!   template<product_type Tuple>
  //!   using zip_t = typename zip<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip
  //!
  //! ## Example
  //! @include doc/zip.cpp
  //================================================================================================
  template<product_type T0, sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0 && t0, Ts &&... ts)
  requires ( compatible_product_types<T0, Ts...> )
  {
    return _::zipper(index<size_v<T0>>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the tuple of all ith elements of ts...
  //!
  //! @param t0 Tuple to convert
  //! @param ts Tuples to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @ note `zip_min` truncates tuples based on the smallest size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct zip_min;
  //!
  //!   template<product_type Tuple>
  //!   using zip_min_t = typename zip<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_min
  //!
  //! ## Example
  //! @include doc/zip_min.cpp
  //================================================================================================
  template<product_type T0, product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_min(T0 && t0, Ts &&...ts)
  requires ( compatible_product_types<T0, Ts...> )
  {
    constexpr std::size_t min = _::min_size_v<T0, Ts...>(); 
    return _::zipper(index<min>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple where the ith element is the tuple of all ith elements of ts...
  //!
  //! @param t0 Tuple to convert
  //! @param ts Tuples to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! @ note `zip_max` fills missing elements to reach the biggest tuple size.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct zip_max;
  //!
  //!   template<product_type Tuple>
  //!   using zip_max_t = typename zip<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip_max
  //!
  //! ## Example
  //! @include doc/zip_max.cpp
  //================================================================================================
  template<product_type T0, product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_max(T0 &&t0, Ts &&...ts)
  requires ( compatible_product_types<T0, Ts...> )
  {
    constexpr std::size_t max = _::max_size_v<T0, Ts...>();
    return _::zipper(index<max>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }

  namespace result
  {
    template<product_type T0, sized_product_type<size_v<T0>>... Ts>
    struct zip
    {
      using type = decltype( kumi::zip( std::declval<T0>(), std::declval<Ts>()... ) );
    };
    
    template<product_type T0, product_type... Ts>
    struct zip_min
    {
      using type = decltype( kumi::zip_min( std::declval<T0>(), std::declval<Ts>()... ) );
    };
    
    template<product_type T0, product_type... Ts>
    struct zip_max
    {
      using type = decltype( kumi::zip_max( std::declval<T0>(), std::declval<Ts>()... ) );
    };

    template<product_type T0, product_type... Ts>
    using zip_t = typename zip<T0,Ts...>::type;
    
    template<product_type T0, product_type... Ts>
    using zip_min_t = typename zip_min<T0,Ts...>::type;
    
    template<product_type T0, product_type... Ts>
    using zip_max_t = typename zip_max<T0,Ts...>::type;
  }
}
