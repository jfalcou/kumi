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
  struct flatten_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else
      {
        constexpr auto proj = [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::function::concatenater(
            std::index_sequence<kumi::function::size_or_v<kumi::stored_element_t<I, T>, 1>...>{});
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return (*this)(KUMI_FWD(t), get<1>(proj), get<0>(proj));
      }
    }

    template<typename T, std::size_t... J, std::size_t... I>
    constexpr auto operator()(T&& t, std::index_sequence<J...>, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(visit<T>(KUMI_FWD(t), kumi::index<J>, get<I>(KUMI_FWD(t)))...);
    }

  private:
    template<typename T, typename V> KUMI_ABI static constexpr auto visit(T&&, auto J, V&& v)
    {
      using FV = kumi::result::field_value_of_t<V>;
      if constexpr (kumi::concepts::record_type<FV> && kumi::concepts::record_type<T>)
      {
        constexpr auto new_name = kumi::label_of<V>() +  kumi::label_of<kumi::element_t<J, FV>>();
        return (kumi::capture_field<name<new_name>{}>(kumi::field_value_of(get<J>(kumi::field_value_of(KUMI_FWD(v))))));
      }
      else if constexpr (kumi::concepts::follows_same_semantic<T, V>) return get<J>(KUMI_FWD(v));
      else return KUMI_FWD(v);
    }
  };

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
  struct flatten_all_t : private kumi::flatten_t
  {
    template<kumi::concepts::product_type T, typename Func>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Func f) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else return this->flatten_t::operator()((*this)(KUMI_FWD(t), f, std::make_index_sequence<kumi::size_v<T>>{}));
    }

    /// @overload
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else
      {
        auto f = [](auto&& e) -> decltype(auto) { return KUMI_FWD(e); };
        return this->flatten_t::operator()((*this)(KUMI_FWD(t), f, std::make_index_sequence<kumi::size_v<T>>{}));
      }
    }

    template<typename T, typename F, std::size_t... I>
    constexpr auto operator()(T&& t, F f, std::index_sequence<I...>) const
    {
      return kumi::builder<T>::make(visit(KUMI_FWD(t), get<I>(KUMI_FWD(t)), f, *this)...);
    }

  private:
    template<typename T, typename V, typename F, typename Self> static constexpr auto visit(T&&, V&& v, F f, Self s)
    {
      using FV = kumi::result::field_value_of_t<V>;
      if constexpr (kumi::concepts::record_type<FV> && kumi::concepts::record_type<T>)
        return kumi::capture_field<kumi::identifier_of<V>()>(s(kumi::field_value_of(KUMI_FWD(v)), f));
      else if constexpr (kumi::concepts::follows_same_semantic<T, V>) return s(KUMI_FWD(v), f);
      else if constexpr (kumi::concepts::record_type<T> && kumi::concepts::field<V>)
        return kumi::capture_field<kumi::identifier_of<V>()>(kumi::invoke(f, kumi::field_value_of(KUMI_FWD(v))));
      else return kumi::invoke(f, KUMI_FWD(v));
    }
  };

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
  struct as_flat_ptr_t : private kumi::flatten_all_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI auto operator()(T&& t) const noexcept
    {
      return this->flatten_all_t::operator()(KUMI_FWD(t), [](auto& m) { return &m; });
    }
  };

  inline constexpr flatten_t flatten{};
  inline constexpr flatten_all_t flatten_all{};
  inline constexpr as_flat_ptr_t as_flat_ptr{};

  namespace result
  {
    template<kumi::concepts::product_type T> struct flatten
    {
      using type = decltype(kumi::flatten(std::declval<T>()));
    };

    template<kumi::concepts::product_type T, typename Func = void> struct flatten_all
    {
      using type = decltype(kumi::flatten_all(std::declval<T>(), std::declval<Func>()));
    };

    template<kumi::concepts::product_type T> struct flatten_all<T>
    {
      using type = decltype(kumi::flatten_all(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> struct as_flat_ptr
    {
      using type = decltype(kumi::as_flat_ptr(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using flatten_t = typename kumi::result::flatten<T>::type;

    template<kumi::concepts::product_type T, typename Func = void>
    using flatten_all_t = typename kumi::result::flatten_all<T, Func>::type;

    template<kumi::concepts::product_type T> using as_flat_ptr_t = typename kumi::result::as_flat_ptr<T>::type;
  }
}
