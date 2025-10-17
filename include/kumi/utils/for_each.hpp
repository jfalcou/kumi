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
  //! @ingroup transforms
  //! @brief Applies the Callable object f on each element of a kumi::product_type. f is applied on the
  //!        values if the given product_type is a kumi::record 
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and/or `ts`.
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    kumi::product_type whose elements to be used as arguments to f
  //! @param ts   Other kumi::product_type whose elements to be used as arguments to f
  //!
  //! @see kumi::for_each_index
  //!
  //! ## Example
  //! @include doc/for_each.cpp
  //! @include doc/record/for_each.cpp
  //================================================================================================
  template<typename Function, product_type T, product_type... Ts>
  KUMI_ABI constexpr void for_each(Function f, T&& t, Ts&&... ts)
  requires( (compatible_product_types<T, Ts...>) 
          && (_::supports_call<Function&, T, Ts...>))
  {
         if constexpr(sized_product_type<T,0>) return;
    else if constexpr( record_type<T> )
    {
      [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        // clang needs this for some reason
        using std::get;
        auto const fields = t.names();
        [[maybe_unused]] auto call = [&]<typename M>(M)
                                        { 
                                          auto const field = get<M::value>(fields); 
                                          f ( get<field>(KUMI_FWD(t))
                                            , get<field>(KUMI_FWD(ts))...
                                          );
                                        };

          ( call(std::integral_constant<std::size_t, I>{}), ... );
        }
        (std::make_index_sequence<size_v<T>>{});
    }
    else
    {
      [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        // clang needs this for some reason
        using std::get;
        [[maybe_unused]] auto call = [&]<typename M>(M)
                                        { f ( get<M::value>(KUMI_FWD(t))
                                            , get<M::value>(KUMI_FWD(ts))...
                                            );
                                        };

        ( call(std::integral_constant<std::size_t, I>{}), ... );
      }
      (std::make_index_sequence<size<T>::value>());
    }
  }

  //================================================================================================
  //! @ingroup tuple_transforms
  //! @brief Applies the Callable object f on each element of a kumi::product_type and its index.
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and/or `ts` and an integral constant. This function cannot be applied
  //!       on kumi::records.
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    kumi::product_type whose elements to be used as arguments to f
  //! @param ts   Other kumi::product_type whose elements to be used as arguments to f
  //!
  //! @see kumi::for_each
  //!
  //! ## Example
  //! @include doc/for_each_index.cpp
  //================================================================================================
  template<typename Function, product_type T, product_type... Ts>
  requires( !record_type<T> && (!record_type<Ts> && ...) )
  KUMI_ABI constexpr void for_each_index(Function f, T&& t, Ts&&... ts)
  {
    if constexpr(sized_product_type<T,0>) return;
    else
    {
      auto const invoker{[&, f](auto const i)
      {
          f
          (
            i,
            get<i.value>(KUMI_FWD(t)),
            get<i.value>(KUMI_FWD(ts))...
          );
      }};

      [=]<std::size_t... I>(std::index_sequence<I...>)
      {
        (invoker( std::integral_constant<unsigned, I>{} ), ...);
      }(std::make_index_sequence<size<T>::value>());
    }
  }
 
  //================================================================================================
  //! @ingroup record_transforms
  //! @brief Applies the Callable object f on each element of a kumi::record_type and its field.
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and those of `ts`. This function cannot be applied to `kumi::tuple`
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    kumi::record_type whose elements to be used as arguments to f
  //! @param ts   Other kumi::record_type whose elements to be used as arguments to f
  //!
  //! @see kumi::for_each
  //!
  //! ## Example
  //! @include doc/record/for_each_field.cpp
  //================================================================================================
  template<typename Function, record_type T, record_type... Ts>
  requires ( compatible_product_types<std::remove_cvref_t<T>, std::remove_cvref_t<Ts>...> )
  KUMI_ABI constexpr void for_each_field(Function f, T&& t, Ts&&... ts)
  {
    if constexpr(sized_product_type<T,0>) return;
    else
    {
      auto const invoker = [&]<std::size_t I>(std::integral_constant<std::size_t, I>)
      {
          auto const field = get<I>(t.names());
          f
          (
            field.to_string(),
            get<field>(KUMI_FWD(t)),
            get<field>(KUMI_FWD(ts))...
          );
      };

      [=]<std::size_t... I>(std::index_sequence<I...>)
      {
        (invoker( std::integral_constant<std::size_t, I>{} ), ...);
      }(std::make_index_sequence<size<T>::value>());
    }
  }
}
