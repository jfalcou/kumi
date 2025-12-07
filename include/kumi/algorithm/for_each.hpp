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
  //! @brief Applies the Callable object f on each element of a product type. f is applied on the
  //!        values if the given product_type is a record type. 
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and/or `ts`.
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    Product type whose elements are to be used as arguments to f
  //! @param ts   Other product types whose elements are to be used as arguments to f
  //!
  //! @see kumi::for_each_index
  //! @see kumi::for_each_field
  //!
  //! ## Example
  //! @include doc/for_each.cpp
  //! @include doc/record/for_each.cpp
  //================================================================================================
  template<typename Function, product_type T, product_type... Ts>
  KUMI_ABI constexpr void for_each(Function f, T && t, Ts &&... ts)
  requires( (compatible_product_types<T, Ts...>) 
         && (_::supports_call<Function&, T, Ts...>))
  {
         if constexpr(sized_product_type<T,0>) return;
    else if constexpr( record_type<T> )
    {
      [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        constexpr auto fields = members_of( as<T>{} );
        [[maybe_unused]] auto call = [&]<typename M>(M)
                                        { 
                                          constexpr auto field = get<M::value>(fields); 
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
  //! @brief Applies the Callable object f on each element of a product type and its index.
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and/or `ts` and an integral constant. This function cannot be applied
  //!       on record types.
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    Product type whose elements to be used as arguments to f
  //! @param ts   Other product types whose elements to be used as arguments to f
  //!
  //! @see kumi::for_each
  //! @see kumi::for_each_field
  //!
  //! ## Example
  //! @include doc/for_each_index.cpp
  //================================================================================================
  template<typename Function, product_type T, product_type... Ts>
  requires(!record_type<T> && (!record_type<Ts> && ...))
  KUMI_ABI constexpr void for_each_index(Function f, T && t, Ts &&... ts)
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
      }(std::make_index_sequence<size_v<T>>());
    }
  }
 
  //================================================================================================
  //! @ingroup record_transforms
  //! @brief Applies the Callable object f on each element of a record type and its field.
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and those of `ts`. This function can only be applied to record types.
  //!
  //! @param f	  Callable object to be invoked
  //! @param t    Record type whose elements to be used as arguments to f
  //! @param ts   Other record types whose elements to be used as arguments to f
  //!
  //! @see kumi::for_each
  //! @see kumi::for_each_index
  //!
  //! ## Example
  //! @include doc/record/for_each_field.cpp
  //================================================================================================
  template<typename Function, record_type T, record_type... Ts>
  requires ( compatible_product_types<T, Ts...> )
  KUMI_ABI constexpr void for_each_field(Function f, T && t, Ts &&... ts)
  {
    if constexpr(sized_product_type<T,0>) return;
    else
    {
      constexpr auto fields = members_of( as<T>{} );
      auto const invoker = [&]<std::size_t I>(std::integral_constant<std::size_t, I>)
      {
          constexpr auto field = get<I>(fields);
          f
          (
            field,
            get<field>(KUMI_FWD(t)),
            get<field>(KUMI_FWD(ts))...
          );
      };

      [=]<std::size_t... I>(std::index_sequence<I...>)
      {
        (invoker( std::integral_constant<std::size_t, I>{} ), ...);
      }(std::make_index_sequence<size_v<T>>());
    }
  }
}
