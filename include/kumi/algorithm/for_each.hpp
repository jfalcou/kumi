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
    @ingroup  transforms
    @brief    Applies the Callable object f on each element of a product type. `f` is applied on the values if the
              given product_type is a record type.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and/or `ts`, or if the product type are not compatible. @see compatible_product_types.

    @param f	  Callable object to be invoked
    @param t    Product type whose elements are used as arguments to f
    @param ts   Other product types whose elements are used as arguments to f

    @see kumi::for_each_index
    @see kumi::for_each_field

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/for_each.cpp
    ### Record:
    @include doc/record/algo/for_each.cpp
  **/
  //====================================================================================================================
  struct for_each_t
  {
    template<typename Function, kumi::concepts::product_type T, kumi::concepts::product_type... Ts>
    KUMI_ABI constexpr void operator()(Function f, T&& t, Ts&&... ts) const
    requires(kumi::concepts::compatible_product_types<T, Ts...>)
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::supports_call<Function&, T, Ts...>)
#endif
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return;
      else
      {
        auto const invoker{[&](auto const I) {
          if constexpr (kumi::concepts::record_type<T>)
          {
            constexpr auto field = kumi::identifier_of<kumi::element_t<I, T>>();
            kumi::invoke(f, get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...);
          }
          else kumi::invoke(f, get<I>(KUMI_FWD(t)), get<I>(KUMI_FWD(ts))...);
        }};

        (*this)(invoker, std::make_index_sequence<kumi::size_v<T>>{});
      }
    }

  protected:
    template<typename F, std::size_t... I> KUMI_ABI constexpr auto operator()(F&& f, std::index_sequence<I...>) const
    {
      using result_t = std::invoke_result_t<F, kumi::index_t<0>>;
      if constexpr (std::is_void_v<result_t>) return ((kumi::invoke(KUMI_FWD(f), kumi::index<I>)), ...);
      else return ((kumi::invoke(KUMI_FWD(f), kumi::index<I>)) && ...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup  tuple_transforms
    @brief    Applies the Callable object `f` on each element of a product type and its index.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and/or `ts` and an integral constant. This function cannot be applied
          on record types.

    @param f	  Callable object to be invoked
    @param t    Product type whose elements are used as arguments to f
    @param ts   Other product types whose elements to be used as arguments to f

    @see kumi::for_each
    @see kumi::for_each_field

    ## Example:
    @include doc/tuple/algo/for_each_index.cpp
  **/
  //====================================================================================================================
  struct for_each_index_t : private for_each_t
  {
    template<typename Function, kumi::concepts::product_type T, kumi::concepts::product_type... Ts>
    KUMI_ABI constexpr void operator()(Function f, T&& t, Ts&&... ts) const
    requires(!kumi::concepts::record_type<T> && (!kumi::concepts::record_type<Ts> && ...))
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return;
      else
      {
        auto const invoker{[&](auto const I) { kumi::invoke(f, I, get<I>(KUMI_FWD(t)), get<I>(KUMI_FWD(ts))...); }};
        this->for_each_t::operator()(invoker, std::make_index_sequence<kumi::size_v<T>>{});
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup record_transforms
    @brief Applies the Callable object `f` on each element of a record type and its field.

    @note This function does not take part in overload resolution if `f` can't be applied to the
          elements of `t` and those of `ts`, or if the product types are not compatible.
          @see compatible_product_types

    This function can only be applied to record types.
    The function needs to be defined to handle types modeling kumi::concepts::field.

    @param f	  Callable object to be invoked
    @param r    Record type whose fields are used as arguments to f
    @param rs   Other record types whose elements are used as arguments to f

    @see kumi::for_each
    @see kumi::for_each_index

    ## Example:
    @include doc/record/algo/for_each_field.cpp
  **/
  //====================================================================================================================
  struct for_each_field_t : private kumi::for_each_t
  {
    template<typename Function, kumi::concepts::record_type R, kumi::concepts::record_type... Rs>
    KUMI_ABI constexpr void operator()(Function f, R&& r, Rs&&... rs) const
    requires(kumi::concepts::compatible_product_types<R, Rs...>)
    {
      if constexpr (kumi::concepts::empty_product_type<R>) return;
      else
      {
        constexpr auto fields = kumi::members_of(as<R>{});
        auto const invoker = [&](auto const I) {
          constexpr auto field = get<I>(fields);
          kumi::invoke(f, kumi::_::make_str(field), get<field>(KUMI_FWD(r)), get<field>(KUMI_FWD(rs))...);
        };
        this->for_each_t::operator()(invoker, std::make_index_sequence<kumi::size_v<R>>{});
      }
    }
  };

  inline constexpr for_each_t for_each{};
  inline constexpr for_each_index_t for_each_index{};
  inline constexpr for_each_field_t for_each_field{};
}
