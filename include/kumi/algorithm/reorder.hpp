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
    template<concepts::index_map auto idxs, concepts::product_type T> consteval auto in_bound_indexes()
    {
      using map_t = std::remove_cvref_t<decltype(idxs)>;
      if constexpr (concepts::sized_product_type<T, 0>) return false;
      else if constexpr (concepts::sized_product_type<map_t, 0>) return true;
      else
        return []<std::size_t... N>(std::index_sequence<N...>) {
          bool checks[] = {([]() {
            if constexpr (concepts::product_type<element_t<N, map_t>>) return in_bound_indexes<get<N>(idxs), T>();
            else if constexpr (static_cast<std::size_t>(get<N>(idxs)) < size_v<T>) return true;
            else return false;
          }())...};

          for (std::size_t i = 0; i < idxs.size(); ++i)
            if (!checks[i]) return false;

          return true;
        }(std::make_index_sequence<idxs.size()>{});
    };
  }

  //====================================================================================================================
  //! @ingroup generators
  //! @brief Reorder elements of a product type
  //!
  //! This function does not participate in overload resolution if any Idx is outside [0, size_v<T>[.
  //!
  //! @note Nothing prevent the number of reordered index to be lesser or greater than t size or
  //!       the fact they can appear multiple times.
  //!
  //! @note reorder(tuple) works and is equivalent to reorder<>(tuple)
  //!
  //! @tparam Idx     Reordered index of elements
  //! @param  t The product type to reorder
  //! @return A product type equivalent to product_type(t[index<Idx>]...);
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T,std::size_t... Idx> struct reorder;
  //!
  //!   template<product_type T,std::size_t... Idx>
  //!   using reorder_t = typename reorder<T,Idx...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reorder
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/reorder.cpp
  //! @include doc/record/algo/reorder.cpp
  //====================================================================================================================
  template<std::size_t... Idx, concepts::product_type T>
  requires((Idx < size_v<T>) && ...)
  [[nodiscard]] KUMI_ABI constexpr auto reorder(T&& t)
  {
    return builder<T>::make(get<Idx>(KUMI_FWD(t))...);
  }

  //====================================================================================================================
  //! @ingroup generators
  //! @brief Reorder elements of a kumi::record
  //!
  //! This function does not participate in overload resolution if the names are not in T
  //!
  //! @note Nothing prevent the number of reordered names to be lesser or greater than t size or
  //!       the fact they can appear multiple times if it is applied on a named tuple.
  //!
  //! @tparam Name     Reordered names of elements
  //! @param  t kumi::product_type to reorder
  //! @return A product type equivalent to product_type(t[index<Idx>]...);
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple,std::size_t... Idx> struct reorder_fields;
  //!
  //!   template<product_type Tuple,std::size_t... Idx>
  //!   using reorder_fields_t = typename reorder_fields<Tuple,Idx...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reorder_fields
  //!
  //! ## Example
  //! @include doc/record/algo/reorder_fields.cpp
  //====================================================================================================================
  template<concepts::identifier auto... Name, concepts::product_type Tuple>
  requires(requires { get<Name>(std::declval<Tuple>()); } && ...)
  KUMI_ABI constexpr auto reorder_fields(Tuple&& t)
  {
    return builder<Tuple>::make(Name = get<Name>(KUMI_FWD(t))...);
  }

  //====================================================================================================================
  //! @ingroup generators
  //! @brief Reindex elements of a kumi::product_type
  //!
  //! This function does not participate in overload resolution if any Idx is outside [0, size_v<T>[.
  //!
  //! @note Nothing prevent the number of reordered index to be lesser or greater than t size or
  //!       the fact they can appear multiple times.
  //!
  //! @tparam Indexes   A kumi::indexes representing the reindexed slot of the elements
  //! @param  t kumi::product_type to reindex
  //! @return A potentially nested tuple following the Indexes order
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, index_map auto Idxs> struct reindex;
  //!
  //!   template<product_type T, index_map auto Idxs>
  //!   using reindex_t= typename reindex<T,Idxs>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reindex
  //!
  //! ## Example
  //! @include doc/tuple/algo/reindex.cpp
  //! @include doc/record/algo/reindex.cpp
  //====================================================================================================================
  template<concepts::index_map auto Indexes, concepts::product_type T>
  requires(_::in_bound_indexes<Indexes, T>())
  [[nodiscard]] KUMI_ABI constexpr auto reindex(T&& t)
  {
    using idx_t = std::remove_cvref_t<decltype(Indexes)>;
    auto mk = [&]<auto Idx>() -> decltype(auto) {
      if constexpr (concepts::product_type<decltype(Idx)>) return reindex<Idx>(KUMI_FWD(t));
      else return get<Idx>(KUMI_FWD(t));
    };

    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else if constexpr (concepts::sized_product_type<idx_t, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(mk.template operator()<get<I>(Indexes)>()...);
      }(std::make_index_sequence<size_v<idx_t>>{});
  }

  namespace result
  {
    template<concepts::product_type T, std::size_t... Idx> struct reorder
    {
      using type = decltype(kumi::reorder<Idx...>(std::declval<T>()));
    };

    template<concepts::product_type Tuple, concepts::identifier auto... Name> struct reorder_fields
    {
      using type = decltype(kumi::reorder_fields<Name...>(std::declval<Tuple>()));
    };

    template<concepts::product_type T, concepts::index_map auto Indexes> struct reindex
    {
      using type = decltype(kumi::reindex<Indexes>(std::declval<T>()));
    };

    template<concepts::product_type T, std::size_t... Idx> using reorder_t = typename reorder<T, Idx...>::type;

    template<concepts::product_type Tuple, concepts::identifier auto... Name>
    using reorder_fields_t = typename reorder_fields<Tuple, Name...>::type;

    template<concepts::product_type T, concepts::index_map auto Indexes>
    using reindex_t = typename reindex<T, Indexes>::type;
  }
}
