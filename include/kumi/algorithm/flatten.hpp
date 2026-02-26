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
    //==============================================================================================
    // Flatten helpers used to handle prefix name concatenation for records without altering API
    //==============================================================================================
    template<typename T> KUMI_ABI constexpr auto flat_one(T&& t)
    {
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          auto v_or_r = [&]<typename V>(V&& v) {
            using FV = kumi::result::field_value_of_t<V>;
            constexpr auto curr_name = _::make_str(name_of<V>());

            if constexpr (concepts::record_type<FV>)
            {
              return [&]<std::size_t... J>(std::index_sequence<J...>) {
                return record{
                  (capture_field<name<concatenate_str<curr_name, _::make_str(name_of<element_t<J, FV>>())>()>{}>(
                    field_value_of(get<J>(field_value_of(KUMI_FWD(v))))))...};
              }(std::make_index_sequence<size_v<FV>>{});
            }
            else return record{KUMI_FWD(v)};
          };

          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }

    template<auto Prefix, typename T> KUMI_ABI constexpr auto flat(T&& t)
    {
      using Prefix_type = std::remove_cvref_t<decltype(Prefix)>;
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          auto v_or_r = [&]<typename V>(V&& v) {
            constexpr auto curr_name = [&] {
              if constexpr (std::is_same_v<Prefix_type, unit>) return name<_::make_str(name_of<V>())>{};
              else return name<concatenate_str<_::make_str(Prefix), _::make_str(name_of<V>())>()>{};
            }();

            if constexpr (concepts::record_type<kumi::result::field_value_of_t<V>>)
              return flat<curr_name>(field_value_of(KUMI_FWD(v)));
            else return record{capture_field<curr_name>(field_value_of(KUMI_FWD(v)))};
          };

          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }

    template<auto Prefix, typename T, typename F> KUMI_ABI constexpr auto flat_map(T&& t, F f)
    {
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          using Prefix_type = std::remove_cvref_t<decltype(Prefix)>;
          auto v_or_r = [&]<typename V>(V&& v) {
            constexpr auto curr_name = [&] {
              if constexpr (std::is_same_v<Prefix_type, unit>) return name<_::make_str(name_of<V>())>{};
              else return name<concatenate_str<_::make_str(Prefix), _::make_str(name_of<V>())>()>{};
            }();

            if constexpr (concepts::record_type<kumi::result::field_value_of_t<V>>)
              return flat_map<curr_name>(field_value_of(KUMI_FWD(v)), f);
            else return record{capture_field<curr_name>(invoke(f, field_value_of(v)))};
          };

          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Converts a product type of product types into a product type of all elements.
  //!
  //! @param t  Product type to flatten
  //! @return   A product type composed of all elements of t flattened non-recursively
  //!
  //! @note There is a semantic difference between record and tuples flattening.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct flatten;
  //!
  //!   template<product_type T>
  //!   using flatten_t = typename flatten<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::flatten
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/flatten.cpp
  //! @include doc/record/algo/flatten.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat_one(KUMI_FWD(t));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = []<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return KUMI_FWD(v);
          else return kumi::tuple{KUMI_FWD(v)};
        };

        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Recursively converts a product type of product types into a product type of all elements.
  //!
  //! Recursively converts a product type of product types `t` into a product type of all elements of
  //! said product types.
  //!
  //! If the Callable object f is provided, non-product type elements are processed by `f` before
  //! being inserted.
  //!
  //! @note There is a semantic difference between record and tuples flattening.
  //!
  //! @param t  Product type to flatten
  //! @param f  Optional Callable object to apply when a sub-tuple is flattened
  //! @return   A tuple composed of all elements of t flattened recursively
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Func = void> struct flatten_all;
  //!
  //!   template<product_type T, typename Func = void>
  //!   using flatten_all_t = typename flatten_all<T, Func>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::flatten_all
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/flatten_all.cpp
  //! @include doc/record/algo/flatten_all.cpp
  //================================================================================================
  template<concepts::product_type T, typename Func> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t, Func f)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat_map<none>(KUMI_FWD(t), KUMI_FWD(f));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = [&]<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return flatten_all(KUMI_FWD(v), f);
          else return tuple{invoke(f, v)};
        };
        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  /// @overload
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat<none>(KUMI_FWD(t));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = []<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return flatten_all(KUMI_FWD(v));
          else return kumi::tuple{KUMI_FWD(v)};
        };

        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
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

    template<concepts::product_type T> using flatten_t = typename flatten<T>::type;

    template<concepts::product_type T, typename Func = void> using flatten_all_t = typename flatten_all<T, Func>::type;
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Convert a kumi::product_type to a flat product type of pointers to each its components.
  //!
  //! @param t  Product type to convert
  //! @return   A flat product_type composed of pointers to each elements of t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct as_flat_ptr;
  //!
  //!   template<product_type T>
  //!   using as_flat_ptr_t = typename as_flat_ptr<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::as_flat_ptr
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/as_flat_ptr.cpp
  //! @include doc/record/algo/as_flat_ptr.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI auto as_flat_ptr(T&& t) noexcept
  {
    return kumi::flatten_all(KUMI_FWD(t), [](auto& m) { return &m; });
  }

  namespace result
  {
    template<concepts::product_type T> struct as_flat_ptr
    {
      using type = decltype(kumi::as_flat_ptr(std::declval<T>()));
    };

    template<concepts::product_type T> using as_flat_ptr_t = typename as_flat_ptr<T>::type;
  }
}
