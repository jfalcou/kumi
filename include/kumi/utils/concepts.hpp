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
    //================================================================================================
    // Concept machinery to make our algorithms SFINAE friendly
    //================================================================================================
    template<typename F, typename T>
    concept supports_apply = []<std::size_t... N>(std::index_sequence<N...>) {
      return std::invocable<F, raw_member_t<N, T>...>;
    }(std::make_index_sequence<size_v<T>>{});

    template<typename F, typename T>
    concept supports_nothrow_apply = []<std::size_t... N>(std::index_sequence<N...>) {
      return std::is_nothrow_invocable<F, raw_member_t<N, T>...>::value;
    }(std::make_index_sequence<size_v<T>>{});

    template<typename F, typename... Ts>
    concept supports_call = []<std::size_t... I>(std::index_sequence<I...>) {
      return ([]<std::size_t J>(std::integral_constant<std::size_t, J>) {
        return std::invocable<F, raw_member_t<J, Ts>...>;
      }(std::integral_constant<std::size_t, I>{}) &&
              ...);
    }(std::make_index_sequence<(size_v<Ts>, ...)>{});

    template<typename T>
    concept supports_transpose = (size_v<T> <= 1) || ([]<std::size_t... N>(std::index_sequence<N...>) {
                                   return ((size_v<raw_member_t<0, T>> == size_v<raw_member_t<N + 1, T>>) && ...);
                                 }(std::make_index_sequence<size_v<T> - 1>{}));

    template<typename Ints, typename... Ts> struct matches;

    template<> struct matches<std::index_sequence<>>
    {
      using type = std::true_type;
    };

    template<std::size_t... Is, template<class...> class Box, typename... Ts, typename... Us>
    struct matches<std::index_sequence<Is...>, Box<Ts...>, Box<Us...>>
    {
      struct match : _::unique_name<Is, Us>...
      {
      };

      template<typename... Key>
      static consteval auto is_present(Key...) -> decltype(_::true_fn(static_cast<Key>(match())...));
      static consteval std::false_type is_present(...);

      using type = decltype(is_present(_::get_key<Is, Ts>()...));
    };

    template<std::size_t S, typename T, typename U>
    using matches_t = typename matches<std::make_index_sequence<S>, T, U>::type;

    template<typename T, typename U> inline constexpr auto matches_v = matches_t<size_v<T>, T, U>::value;
  }

  namespace concepts
  {
    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Product Type semantic
    //!
    //! A type `T` models `kumi::product_type` if it opts in for the Product Type semantic and
    //! provides supports for structured bindings.
    //================================================================================================
    template<typename T>
    concept product_type = is_product_type<std::remove_cvref_t<T>>::value;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Record Type semantic
    //!
    //! A type `T` models `kumi::record_type` if it opts in for the Record Type semantic.
    //! A `kumi::record_type` also models `kumi::product_type`
    //================================================================================================
    template<typename T>
    concept record_type = product_type<T> && is_record_type<std::remove_cvref_t<T>>::value;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Container Type semantic
    //!
    //! A type `T` models `kumi::static_container` if it is an homogeneous container of fixed size.
    //================================================================================================
    template<typename T>
    concept static_container = is_static_container_v<std::remove_cvref_t<T>>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type represent a Unit Type
    //!
    //! A type `T` models `kumi::unit_type` if it models std::is_empty or is nullptr_t.
    //================================================================================================
    template<typename T>
    concept unit_type = (product_type<T> && (size_v<T> == 0)) || std::is_same_v<std::remove_cvref_t<T>, std::nullptr_t>;

    //====================================================================================================================
    //! @brief field concept
    //!
    //! A field type can be aggregated in a [record](@ref kumi::record) and be
    //! fetched later
    //====================================================================================================================
    template<typename T>
    concept field = kumi::_::field<T>;

    //====================================================================================================================
    //! @brief identifier concept
    //!
    //! An identifier type is able to be bound to a value as a [field](@ref kumi::field)
    //====================================================================================================================
    template<typename T>
    concept identifier = kumi::_::identifier<T>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Product Type semantic and has a known size
    //!
    //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
    //! exactly `N` elements.
    //================================================================================================
    template<typename T, std::size_t N>
    concept sized_product_type = product_type<T> && (size_v<T> == N);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Product Type semantic and has a size lower bound
    //!
    //! A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has
    //! at least `N` elements.
    //================================================================================================
    template<typename T, std::size_t N>
    concept sized_product_type_or_more = product_type<T> && (size_v<T> >= N);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Product Type semantic and is empty
    //!
    //! A type `T` models `kumi::empty_product_type ` if it models `kumi::product_type` and has
    //! no elements.
    //================================================================================================
    template<typename T>
    concept empty_product_type = product_type<T> && (size_v<T> == 0);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type follows the Product Type semantic and is non-empty
    //!
    //! A type `T` models `kumi::non_empty_product_type ` if it models `kumi::product_type` and has
    //! at least 1 element.
    //================================================================================================
    template<typename T>
    concept non_empty_product_type = product_type<T> && (size_v<T> != 0);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a type can be used as sequence of indexes in algorithms
    //!
    //! A type `T` models `kumi::index_map` if it models `kumi::product_type` and
    //! contains members which are themselves either integral types or others `index_map`
    //================================================================================================
    template<typename T>
    concept index_map = product_type<T> && is_index_map_v<std::remove_cvref_t<T>>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a type is suitable as an index
    //!
    //! A type `T` models `kumi::indexer` if it models `kumi::index_map` or `std::is_integral`
    //================================================================================================
    template<typename T>
    concept indexer = index_map<T> || std::integral<std::remove_cvref_t<T>>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying is Product Type which types are all the same
    //!
    //! A type `T` models `kumi::homogenous_product_type` if it models `kumi::product_type` and
    //! contains member of a single, unique type.
    //================================================================================================
    template<typename T>
    concept homogeneous_product_type = product_type<T> && is_homogeneous_v<std::remove_cvref_t<T>>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a type is comparable for each of its components
    //!
    //! A type `T` models `kumi::equality_comparable<T,U>`if it's a product type where each of its
    //! elements satisfies kumi::equality_comparable for all their respective elements.
    //================================================================================================
    template<typename T, typename U>
    concept equality_comparable = (size_v<T> == size_v<U>) && _::piecewise_comparable<T, U>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if parameter pack containes a kumi::field_capture.
    //================================================================================================
    template<typename... Ts>
    concept has_named_fields = (... || field<Ts>);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if parameter pack contains only kumi::field_captures.
    //================================================================================================
    template<typename... Ts>
    concept is_fully_named = (... && field<Ts>);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a parameter pack only holds unique types.
    //================================================================================================
    template<typename... Ts>
    concept uniquely_typed = (!has_named_fields<Ts...>) && all_uniques_v<std::remove_cvref_t<Ts>...>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a parameter pack only holds unique kumi::field_capture names.
    //================================================================================================
    template<typename... Ts>
    concept uniquely_named = (has_named_fields<Ts...>) && all_unique_names_v<std::remove_cvref_t<Ts>...>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief  Concept specifying if a parameter pack only holds unique kumi::str representation of the
    //!         field names.
    //================================================================================================
    template<typename... Ts>
    concept unique_display_name =
      (sizeof...(Ts) == 0) || (is_fully_named<Ts...> && (all_uniques_v<_::value<std::remove_cvref_t<Ts>::name()>...>));

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a parameter pack only holds kumi::field_captures each of their
    //!        each of their names are unique!
    //!
    //! @note  If there are no element in the parameter pack the concept returns true
    //================================================================================================
    template<typename... Ts>
    concept entirely_uniquely_named = (sizeof...(Ts) == 0) || (is_fully_named<Ts...> && uniquely_named<Ts...>);

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a Type is present in a parameter pack.
    //================================================================================================
    template<typename T, typename... Ts>
    concept contains_type = kumi::_::can_get_field_by_type<T, Ts...>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a kumi::field_capture with name Name is present in a parameter pack.
    //================================================================================================
    template<typename Name, typename... Ts>
    concept contains_field = identifier<Name> && kumi::_::can_get_field_by_value<Name, Ts...>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if two types have matching named fields
    //!
    //! A type `T` models `kumi::equivalent<T,U>` if it is a product type with the same number of
    //! members as `U`, and each of its fields has a corresponding field in `U` with the same name
    //================================================================================================
    template<typename T, typename U>
    concept equivalent = (size_v<T> == size_v<U>) && _::matches_v<std::remove_cvref_t<T>, std::remove_cvref_t<U>>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if two product types are comparable by matching name
    //!
    //! A type `T` models `kumi::named_equality_comparable<T,U>` if it's a product_type that satisfies
    //! kumi::equivalent<T,U> and if each of its fields satisfies kumi::equality_comparable with
    //! the corresponding field in `U`
    //================================================================================================
    template<typename T, typename U>
    concept named_equality_comparable = equivalent<T, U> && _::fieldwise_comparable<T, U>;

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a pack of types follows the same semantic.
    //!
    //! A pack of type `Ts` models `kumi::follows_same_semantic` if all of the types comply to the
    //! product type semantic and none comply to the record type semantic or if they all comply to
    //! the record type semantic.
    //================================================================================================
    template<typename... Ts>
    concept follows_same_semantic = ((product_type<Ts> && !record_type<Ts>) && ...) || ((record_type<Ts> && ...));

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if two product types are compatibles.
    //!
    //! A pack of types `Ts` models `kumi::compatible_product_types` if it models
    //! `kumi::follows_same_semantic` and if all types model `kumi::equivalent` if the types are
    //! `record types`
    //================================================================================================
    template<typename T, typename... Us>
    concept compatible_product_types =
      (follows_same_semantic<T, Us...> &&
       ((!record_type<T>) || (equivalent<std::remove_cvref_t<T>, std::remove_cvref_t<Us>> && ...)));

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying a type is a Monoid
    //!
    //! A type `T` models `kumi::monoid` if it's a binary associative callable equipped with an
    //! identity element acting as the neutral element for that operation.
    //!
    //! The identity is defined so that the following property holds for the operation.
    //! @code
    //!   monoid(x, indentity) = monoid(identity, x) = x
    //! @endcode
    //!
    //! @note The operation is not required to be commutative; that is monoid(x,y) and monoid(y,x)
    //!       may yield different results. (Ie : the monoid is not necessarily abelian)
    //================================================================================================
    template<typename M>
    concept monoid = requires {
      { std::remove_cvref_t<M>::identity };
      { std::remove_cvref_t<M>{}(std::remove_cvref_t<M>::identity, std::remove_cvref_t<M>::identity) };
    };

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a product type can be queried via a `get<type>`
    //!
    //! A product type `Ts` models `typed_get_compliant` if it's members are uniquely typed.
    //! For a `record_type` it inspects the underlying type of the fields.
    //================================================================================================
    template<typename Type, typename T>
    concept typed_get_compliant = product_type<T> && []<std::size_t... I>(std::index_sequence<I...>) {
      return _::can_get_field_by_type<Type, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});

    //================================================================================================
    //! @ingroup concepts
    //! @brief Concept specifying if a product type can be queried via a `get<identifier>`
    //!
    //! A product type `Ts` models `named_get_compliant` if it's members are uniquely named.
    //================================================================================================
    template<typename Name, typename T>
    concept named_get_compliant =
      identifier<Name> && product_type<T> && []<std::size_t... I>(std::index_sequence<I...>) {
        return _::can_get_field_by_value<Name, element_t<I, T>...>;
      }(std::make_index_sequence<size_v<T>>{});
  }
}
