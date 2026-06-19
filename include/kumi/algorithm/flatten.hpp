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
  namespace _
  {
    struct flatten_all_case_t
    {
      template<typename T, typename V, typename F, typename Self>
      KUMI_ABI constexpr auto operator()(T&&, V&& v, F f, Self s) const
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

    inline constexpr flatten_all_case_t flatten_all_case{};

    struct flatten_case_t
    {
      template<typename T, typename V> KUMI_ABI constexpr auto operator()(T&&, V&& v, auto J) const
      {
        using FV = kumi::result::field_value_of_t<V>;
        if constexpr (kumi::concepts::record_type<FV> && kumi::concepts::record_type<T>)
        {
          constexpr auto new_name = kumi::label_of<V>() + kumi::label_of<kumi::element_t<J, FV>>();
          return (
            kumi::capture_field<name<new_name>{}>(kumi::field_value_of(get<J>(kumi::field_value_of(KUMI_FWD(v))))));
        }
        else if constexpr (kumi::concepts::follows_same_semantic<T, V>) return get<J>(KUMI_FWD(v));
        else return KUMI_FWD(v);
      }
    };

    inline constexpr flatten_case_t flatten_case{};

    template<typename T, typename V, std::size_t... J, std::size_t... I>
    KUMI_ABI constexpr auto flatten_(
      kumi::_::adl_tag_t, T&& t, V visitor, std::index_sequence<J...>, std::index_sequence<I...>)
    {
      if constexpr (sizeof...(I) == 0) return kumi::builder<T>::make();
      else return kumi::builder<T>::make(visitor(KUMI_FWD(t), get<I>(KUMI_FWD(t)), kumi::index<J>)...);
    }

    template<typename T, typename V, typename F, typename S, std::size_t... I>
    KUMI_ABI constexpr auto flatten_all_(kumi::_::adl_tag_t, T&& t, V visitor, F f, S self, std::index_sequence<I...>)
    {
      return kumi::builder<T>::make(visitor(KUMI_FWD(t), get<I>(KUMI_FWD(t)), f, self)...);
    }
  }

  struct flatten_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else
      {
        constexpr auto proj = []<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::function::concatenater(
            std::index_sequence<kumi::function::size_or_v<kumi::stored_element_t<I, T>, 1>...>{});
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return flatten_(kumi::_::adl_tag, KUMI_FWD(t), kumi::_::flatten_case, get<1>(proj), get<0>(proj));
      }
    }
  };

  struct flatten_all_t : private kumi::flatten_t
  {
    template<kumi::concepts::product_type T, typename Func>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Func f) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else
      {
        return this->flatten_t::operator()(flatten_all_(kumi::_::adl_tag, KUMI_FWD(t), kumi::_::flatten_all_case, f,
                                                        (*this), std::make_index_sequence<kumi::size_v<T>>{}));
      }
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else return (*this)(KUMI_FWD(t), kumi::function::identity);
    }
  };

  struct as_flat_ptr_t : private kumi::flatten_all_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI auto operator()(T&& t) const noexcept
    {
      return this->flatten_all_t::operator()(KUMI_FWD(t), [](auto& m) { return &m; });
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var flatten
    @brief Callable object converting a product type of product types into a product type of all elements.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/flatten.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto flatten(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to process

    @subgroupheader{Return value}

      - A product type composed of all elements of `t` flattened non-recursively

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/flatten.hpp flatten_t

    Computes the return type of a call to kumi::flatten

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/flatten.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/flatten.cpp}
  **/
  //====================================================================================================================
  inline constexpr flatten_t flatten{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var flatten_all
    @brief Callable object converting recursively a product type of product types into a product type of all elements.

    Recursively converts a product type of product types `t` into a product type of all elements of
    said product types.

    If the Callable object f is provided, non-product type elements are processed by `f` before
    being inserted.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/flatten.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Function>
      constexpr auto flatten(T && t, Function && f) noexcept;   // 1
    @endcode

    @code
      template<product_type T>
      constexpr auto flatten(T && t) noexcept;                  // 2
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to process
      - `f`: Optional Callable object to apply when a sub-tuple is flattened

    @subgroupheader{Return value}

      - A product type composed of all elements of `t` flattened recursively

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/flatten.hpp flatten_all_t

    Computes the return type of a call to kumi::flatten_all

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/flatten_all.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/flatten_all.cpp}
  **/
  //====================================================================================================================
  inline constexpr flatten_all_t flatten_all{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var as_flat_ptr
    @brief Callable object converting recursively a product type of product types into a flat product type of pointers
  to each of its components.

    On record types, the names of the outer record are concatenated to the inner ones ultimately constructing names
    such as "outer.inner". If the input is a product type containing record types or vice versa only the inner types
    matching the outer semantic will be flattened. Thus a record inside a tuple will not be flattened.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/flatten.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto as_flat_ptr(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product type to process

    @subgroupheader{Return value}

      - A flat product type composed of pointers to each elements of `t`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/flatten.hpp as_flat_ptr_t

    Computes the return type of a call to kumi::as_flat_ptr

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/as_flat_ptr.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/as_flat_ptr.cpp}
  **/
  //====================================================================================================================
  inline constexpr as_flat_ptr_t as_flat_ptr{};

  namespace result
  {
    //! [flatten_t]
    template<kumi::concepts::product_type T> struct flatten
    {
      using type = decltype(kumi::flatten(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using flatten_t = typename kumi::result::flatten<T>::type;

    //! [flatten_t]

    //! [flatten_all_t]
    template<kumi::concepts::product_type T, typename Func = void> struct flatten_all
    {
      using type = decltype(kumi::flatten_all(std::declval<T>(), std::declval<Func>()));
    };

    template<kumi::concepts::product_type T> struct flatten_all<T>
    {
      using type = decltype(kumi::flatten_all(std::declval<T>()));
    };

    template<kumi::concepts::product_type T, typename Func = void>
    using flatten_all_t = typename kumi::result::flatten_all<T, Func>::type;

    //! [flatten_all_t]

    //! [as_flat_ptr_t]
    template<kumi::concepts::product_type T> struct as_flat_ptr
    {
      using type = decltype(kumi::as_flat_ptr(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using as_flat_ptr_t = typename kumi::result::as_flat_ptr<T>::type;
    //! [as_flat_ptr_t]
  }
}
