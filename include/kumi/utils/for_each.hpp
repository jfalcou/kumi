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
  template<typename Function, product_type Tuple, product_type... Tuples>
  constexpr void for_each(Function f, Tuple&& t, Tuples&&... ts)
  requires( (compatible_product_types<std::remove_cvref_t<Tuple>, std::remove_cvref_t<Tuples>...>) 
          && (_::supports_call<Function&, Tuple, Tuples...>))
  {
         if constexpr(sized_product_type<Tuple,0>) return;
    else if constexpr( record_type<Tuple> )
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
        (std::make_index_sequence<size_v<Tuple>>{});
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
      (std::make_index_sequence<size<Tuple>::value>());
    }
  }

  //================================================================================================
  //! @ingroup transforms
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
  template<typename Function, product_type Tuple, product_type... Tuples>
  requires( !record_type<Tuple> && (!record_type<Tuples> && ...) )
  constexpr void for_each_index(Function f, Tuple&& t, Tuples&&... ts)
  {
    if constexpr(sized_product_type<Tuple,0>) return;
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
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
 
  //================================================================================================
  //! @ingroup transforms
  //! @brief Applies the Callable object f on each element of a kumi::record_type and its field.
  //!
  //! @note This function does not take part in overload resolution if `f` can't be applied to the
  //!       elements of `t` and/or `ts` and a `kumi::field_capture`.
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
  template<typename Function, record_type Tuple, record_type... Tuples>
  requires ( compatible_product_types<std::remove_cvref_t<Tuple>, std::remove_cvref_t<Tuples>...> )
  constexpr void for_each_field(Function f, Tuple&& t, Tuples&&... ts)
  {
    if constexpr(sized_product_type<Tuple,0>) return;
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
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
}
