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
    @ingroup generators
    @brief Reorder elements of a product type

    This function will issue a compile time error if any Idx is outside [0, size_v<T>[.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered index to be lesser or greater than t size or
          the fact they can appear multiple times.

    @note reorder(tuple) works and is equivalent to reorder<>(tuple)

    @tparam Idx Reordered index of elements
    @param  t   The product type to reorder
    @return     A product type with the type of `t` with elements equal to get<Idx>(t).

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T,std::size_t... Idx> struct reorder;

      template<product_type T,std::size_t... Idx>
      using reorder_t = typename reorder<T,Idx...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reorder

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/reorder.cpp
    ### Record:
    @include doc/record/algo/reorder.cpp
  **/
  //====================================================================================================================
  template<std::size_t... Idx, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto reorder(T&& t)
  {
    static_assert(((Idx < size_v<T>) && ...), "[KUMI] - Index out of bounds");
    return builder<T>::make(get<Idx>(KUMI_FWD(t))...);
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Reorder elements of a kumi::record

    This function will issue a compile time error if the identifiers are not in `t`

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered names to be lesser or greater than t size or
          the fact they can appear multiple times if it is applied on a named tuple.

    @tparam Name  Reordered names of elements
    @param  t     Product type to reorder
    @return       A product type with the type of `t` with elements equal to get<Name>(t).

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type Tuple,std::size_t... Idx> struct reorder_fields;

      template<product_type Tuple,std::size_t... Idx>
      using reorder_fields_t = typename reorder_fields<Tuple,Idx...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reorder_fields

    ## Example:
    @include doc/record/algo/reorder_fields.cpp
  **/
  //====================================================================================================================
  template<concepts::identifier auto... Name, concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto reorder_fields(Tuple&& t)
  {
    static_assert((requires { get<Name>(std::declval<Tuple>()); } && ...),
                  "[KUMI] - Identifier not present in input type");
    return builder<Tuple>::make(Name = get<Name>(KUMI_FWD(t))...);
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Reindex elements of a kumi::product_type

    This will issue a compile time error if any Idx is outside [0, size_v<T>[.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered index to be lesser or greater than t size or
          the fact they can appear multiple times.

    @tparam Projections A kumi::projection_map representing the reindexed slot of the elements
    @param  t           kumi::product_type to reindex
    @return             A potentially nested tuple following the Indexes order

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T, index_map auto Idxs> struct reindex;

      template<product_type T, index_map auto Idxs>
      using reindex_t= typename reindex<T,Idxs>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reindex

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/reindex.cpp
    ### Record:
    @include doc/record/algo/reindex.cpp
  **/
  //====================================================================================================================
  template<concepts::projection_map auto Projections, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto reindex(T&& t)
  {
    using proj_t = std::remove_cvref_t<decltype(Projections)>;
    auto mk = [&]<concepts::projection auto proj>() -> decltype(auto) {
      if constexpr (concepts::projection_map<decltype(proj)>) return reindex<proj>(KUMI_FWD(t));
      else
      {
        static_assert(requires { get<proj>(std::declval<T>()); }, "[KUMI] - Invalid projection for input type");
        return get<proj>(KUMI_FWD(t));
      }
    };

    if constexpr (concepts::empty_product_type<T>) return builder<T>::make();
    else if constexpr (proj_t::size() == 0) return builder<T>::make();
    else
      return [&]<auto... E>(kumi::projection_map<E...>) {
        return builder<T>::make(mk.template operator()<E>()...);
      }(Projections);
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

    template<concepts::product_type T, concepts::projection_map auto Indexes> struct reindex
    {
      using type = decltype(kumi::reindex<Indexes>(std::declval<T>()));
    };

    template<concepts::product_type T, std::size_t... Idx> using reorder_t = typename reorder<T, Idx...>::type;

    template<concepts::product_type Tuple, concepts::identifier auto... Name>
    using reorder_fields_t = typename reorder_fields<Tuple, Name...>::type;

    template<concepts::product_type T, concepts::projection_map auto Indexes>
    using reindex_t = typename reindex<T, Indexes>::type;
  }
}
