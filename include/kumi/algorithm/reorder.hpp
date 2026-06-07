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
  template<std::size_t... Idx> struct reorder_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      static_assert(((Idx < kumi::size_v<T>) && ...), "[KUMI] - Index out of bounds");
      return builder<T>::make(get<Idx>(KUMI_FWD(t))...);
    }
  };

  template<kumi::concepts::identifier auto... Name> struct reorder_fields_t
  {
    template<kumi::concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto operator()(Tuple&& t) const
    {
      static_assert((requires { get<Name>(std::declval<Tuple>()); } && ...),
                    "[KUMI] - Identifier not present in input type");
      return builder<Tuple>::make(Name = get<Name>(KUMI_FWD(t))...);
    }
  };

  template<kumi::concepts::projection_map auto Projections> struct reindex_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      using proj_t = std::remove_cvref_t<decltype(Projections)>;
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else if constexpr (proj_t::size() == 0) return builder<T>::make();
      else return this->reindex_(KUMI_FWD(t), Projections);
    }

    template<typename T, auto... E> KUMI_ABI constexpr auto reindex_(T&& t, kumi::projection_map<E...>) const
    {
      return kumi::builder<T>::make(visit<E, reindex_t>(KUMI_FWD(t))...);
    }

    template<kumi::concepts::projection auto P, template<auto> class C, typename T>
    KUMI_ABI static constexpr auto visit(T&& t)
    {
      if constexpr (kumi::concepts::projection_map<decltype(P)>) return C<P>{}(KUMI_FWD(t));
      else
      {
        static_assert(requires { get<P>(std::declval<T>()); }, "[KUMI] - Invalid projection for input type");
        return get<P>(KUMI_FWD(t));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var reorder
    @brief Callable object reordering elements of a product type

    This function will issue a compile time error if any Idx is outside [0, size_v<T>[.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered index to be lesser or greater than t size or
          the fact they can appear multiple times.

    @note reorder(tuple) works and is equivalent to reorder<>(tuple)

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reorder.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<std::size_t...Idx, product_type T>
      constexpr auto reorder<Idx...>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `Idx` Index of elements to reorder

    @subgroupheader{Parameters}

      - `t`: Product Type to reorder

    @subgroupheader{Return value}

      * A product type with the type of `t` with elements equal to get<Idx>(t) for each given index.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T,std::size_t... Idx> struct reorder;

      template<product_type T,std::size_t... Idx>
      using reorder_t = typename reorder<T,Idx...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reorder

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/reorder.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/reorder.cpp}
  **/
  //====================================================================================================================
  template<std::size_t... I> inline constexpr reorder_t<I...> reorder{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var reorder_fields
    @brief Callable object reordering elements of a Record Type

    This function will issue a compile time error if the identifiers are not in `t`

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered names to be lesser or greater than t size or
          the fact they can appear multiple times if it is applied on a named tuple.

    @note reorder(tuple) works and is equivalent to reorder<>(tuple)

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reorder.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<identifier auto...Ids, product_type T>
      constexpr auto reorder_fields<Ids...>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `Ids` Identifiers of the elements to reorder

    @subgroupheader{Parameters}

      - `t`: Product Type to reorder

    @subgroupheader{Return value}

      * A product type with the type of `t` with elements equal to get<Ids>(t) for each given identifer.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type Tuple, identifier auto... Ids> struct reorder_fields;

      template<product_type Tuple, identifier auto... Idx>
      using reorder_fields_t = typename reorder_fields<Tuple,Idx...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reorder_fields

    @groupheader{Example}

    @godbolt{doc/record/algo/reorder_fields.cpp}
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier auto... Name> inline constexpr reorder_fields_t<Name...> reorder_fields{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var reindex
    @brief Callable object reindex elements of a Product Type

    This function will issue a compile time error if one of the identifiers is not in `t` or
    if any index is outside [0, size_v<T>[ at any given level of the input type.

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @note Nothing prevent the number of reordered names to be lesser or greater than t size or
          the fact they can appear multiple times if it is applied on a named tuple.

    @note reorder(tuple) works and is equivalent to reorder<>(tuple)

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reorder.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<identifier auto...Ids, product_type T>
      constexpr auto reindex<Ids...>(T && t);
    @endcode

    @subgroupheader{Template Parameters}

      - `Ids` Identifiers of the elements to reorder

    @subgroupheader{Parameters}

      - `t`: Product Type to reorder

    @subgroupheader{Return value}

      * A potentially nested tuple corresponding to recursive applications of reorder

    @groupheader{Helper type}

   @code
    namespace kumi::result
    {
      template<product_type T, index_map auto Idxs> struct reindex;

      template<product_type T, index_map auto Idxs>
      using reindex_t= typename reindex<T,Idxs>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reindex

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/reindex.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/reindex.cpp}
  **/
  //====================================================================================================================
  template<kumi::concepts::projection_map auto Projections> inline constexpr reindex_t<Projections> reindex{};

  namespace result
  {
    template<kumi::concepts::product_type T, std::size_t... Idx> struct reorder
    {
      using type = decltype(kumi::reorder<Idx...>(std::declval<T>()));
    };

    template<kumi::concepts::product_type Tuple, kumi::concepts::identifier auto... Name> struct reorder_fields
    {
      using type = decltype(kumi::reorder_fields<Name...>(std::declval<Tuple>()));
    };

    template<kumi::concepts::product_type T, kumi::concepts::projection_map auto Indexes> struct reindex
    {
      using type = decltype(kumi::reindex<Indexes>(std::declval<T>()));
    };

    template<kumi::concepts::product_type T, std::size_t... Idx>
    using reorder_t = typename kumi::result::reorder<T, Idx...>::type;

    template<kumi::concepts::product_type Tuple, kumi::concepts::identifier auto... Name>
    using reorder_fields_t = typename kumi::result::reorder_fields<Tuple, Name...>::type;

    template<kumi::concepts::product_type T, kumi::concepts::projection_map auto Indexes>
    using reindex_t = typename kumi::result::reindex<T, Indexes>::type;
  }
}
