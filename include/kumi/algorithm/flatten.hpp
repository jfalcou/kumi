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
  template<typename T, std::size_t I> consteval auto size_or()
  {
    if constexpr (concepts::product_type<T>) return size_v<T>;
    else return I;
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Converts a product type of product types into a product type of all elements.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @param t  Product type to flatten
    @return   A product type composed of all elements of `t` flattened non-recursively

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct flatten;

      template<product_type T>
      using flatten_t = typename flatten<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::flatten

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/flatten.cpp
    ### Record:
    @include doc/record/algo/flatten.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten(T&& t)
  {
    if constexpr (concepts::empty_product_type<T>) return t;
    else
    {
      constexpr auto proj = [&]<std::size_t... I>(std::index_sequence<I...>) {
        return function::flattener(std::index_sequence<size_or<raw_element_t<I, T>, 1>()...>{});
      }(std::make_index_sequence<size_v<T>>{});

      auto process = [&]<typename V>(auto J, V&& v) {
        using FV = result::field_value_of_t<V>;
        if constexpr (concepts::record_type<FV> && concepts::record_type<T>)
        {
          constexpr auto curr_name = label_of<V>();
          constexpr auto new_name = concatenate_str<curr_name, label_of<element_t<J, FV>>()>();
          return (capture_field<name<new_name>{}>(field_value_of(get<J>(field_value_of(KUMI_FWD(v))))));
        }
        else if constexpr (concepts::follows_same_semantic<T, V>) return get<J>(KUMI_FWD(v));
        else return KUMI_FWD(v);
      };

      return [&]<std::size_t... J, std::size_t... I>(std::index_sequence<J...>, std::index_sequence<I...>) {
        return builder<T>::make(process(index<J>, get<I>(KUMI_FWD(t)))...);
      }(proj.elt, proj.tpl);
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Recursively converts a product type of product types into a product type of all elements.

    Recursively converts a product type of product types `t` into a product type of all elements of
    said product types.

    If the Callable object f is provided, non-product type elements are processed by `f` before
    being inserted.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @param t  Product type to flatten
    @param f  Optional Callable object to apply when a sub-tuple is flattened
    @return   A product type composed of all elements of `t` flattened recursively

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, typename Func = void> struct flatten_all;

      template<product_type T, typename Func = void>
      using flatten_all_t = typename flatten_all<T, Func>::type;
    }
    @endcode

    Computes the return type of a call to kumi::flatten_all

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/flatten_all.cpp
    ### Record:
    @include doc/record/algo/flatten_all.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T, typename Func> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t, Func f)
  {
    if constexpr (concepts::empty_product_type<T>) return t;
    else
    {
      auto process = [&]<typename V>(V&& v) {
        using FV = result::field_value_of_t<V>;
        if constexpr (concepts::record_type<FV> && concepts::record_type<T>)
          return capture_field<identifier_of<V>()>(flatten_all(field_value_of(KUMI_FWD(v)), f));
        else if constexpr (concepts::follows_same_semantic<T, V>) return flatten_all(KUMI_FWD(v), f);
        else if constexpr (concepts::record_type<T> && concepts::field<V>)
          return capture_field<identifier_of<V>()>(invoke(f, field_value_of(v)));
        else return invoke(f, v);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return flatten(builder<T>::make(process(get<I>(KUMI_FWD(t)))...));
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  /// @overload
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t)
  {
    if constexpr (concepts::empty_product_type<T>) return KUMI_FWD(t);
    else
    {
      auto process = [&]<typename V>(V&& v) {
        using FV = result::field_value_of_t<V>;
        if constexpr (concepts::record_type<FV> && concepts::record_type<T>)
          return capture_field<identifier_of<V>()>(flatten_all(field_value_of(KUMI_FWD(v))));
        else if constexpr (concepts::follows_same_semantic<T, V>) return flatten_all(KUMI_FWD(v));
        else return KUMI_FWD(v);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return flatten(builder<T>::make(process(get<I>(KUMI_FWD(t)))...));
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Convert a product type to a flat product type of pointers to each its components.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @param t  Product type to convert
    @return   A flat product type composed of pointers to each elements of `t`.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct as_flat_ptr;

      template<product_type T>
      using as_flat_ptr_t = typename as_flat_ptr<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::as_flat_ptr

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/as_flat_ptr.cpp
    ### Record:
    @include doc/record/algo/as_flat_ptr.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI auto as_flat_ptr(T&& t) noexcept
  {
    return kumi::flatten_all(KUMI_FWD(t), [](auto& m) { return &m; });
  }

  namespace result
  {
    template<concepts::product_type T> struct flatten
    {
      using type = decltype(kumi::flatten(std::declval<T>()));
    };

    template<concepts::product_type T, typename Func = void> struct flatten_all
    {
      using type = decltype(kumi::flatten_all(std::declval<T>(), std::declval<Func>()));
    };

    template<concepts::product_type T> struct flatten_all<T>
    {
      using type = decltype(kumi::flatten_all(std::declval<T>()));
    };

    template<concepts::product_type T> struct as_flat_ptr
    {
      using type = decltype(kumi::as_flat_ptr(std::declval<T>()));
    };

    template<concepts::product_type T> using flatten_t = typename flatten<T>::type;

    template<concepts::product_type T, typename Func = void> using flatten_all_t = typename flatten_all<T, Func>::type;

    template<concepts::product_type T> using as_flat_ptr_t = typename as_flat_ptr<T>::type;
  }
}
