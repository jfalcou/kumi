//======================================================================================================================
//! @file
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kumi/product_types/tuple.hpp>

namespace kumi
{
  //====================================================================================================================
  /**
    @class record
    @ingroup record_related
    @brief Fixed-size collection of heterogeneous tagged fields, tags are unique.

    kumi::record provides an aggregate based implementation of a record. It provides algorithms and
    functions designed to facilitate record's handling and transformations.

    kumi::record is also compatible with standard tuple operations and structured bindings to some
    extent.

    @tparam Ts Sequence of fields stored inside kumi::record.

    @see @ref record_type

    ## Example:
    @include doc/record/api/introduction.cpp
  **/
  //====================================================================================================================
  template<typename... Ts> struct record
  {
    using is_record_type = void;
    using set_t = kumi::_::make_set_t<Ts...>;

    static constexpr bool is_homogeneous = false;

    set_t impl;

    //==================================================================================================================
    /**
      @name Accessors
      @{
    **/
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief Extracts the Ith field from a kumi::record

      @note   Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
      @param i Compile-time index of the field to access
      @return A reference to the selected field of current record.

      ## Example:
      @include doc/record/api/subscript.cpp
    **/
    //==================================================================================================================
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::index_t<I> i) & noexcept
    requires(I < sizeof...(Ts))
    {
      using T = kumi::element_t<I, tuple<Ts...>>;
      return static_cast<T&>(impl);
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) && noexcept
    requires(I < sizeof...(Ts))
    {
      using T = kumi::element_t<I, tuple<Ts...>>;
      return static_cast<T&&>(static_cast<decltype(impl)&&>(impl));
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const&& noexcept
    requires(I < sizeof...(Ts))
    {
      using T = kumi::element_t<I, tuple<Ts...>>;
      return static_cast<T const&&>(static_cast<decltype(impl) const&&>(impl));
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const& noexcept
    requires(I < sizeof...(Ts))
    {
      using T = kumi::element_t<I, tuple<Ts...>>;
      return static_cast<T const&>(impl);
    }

    //==================================================================================================================
    /**
      @brief Extracts the element with type T from a kumi::record

      @note Does not participate in overload resolution if `T` is not present in the record or if
            the record contains duplicate types

      @param type The type to access in the record
      @return A reference to the selected element of current record.

      ## Example:
      @include doc/record/api/typed_subscript.cpp
    **/
    //==================================================================================================================
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::as<T> type) & noexcept
    requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
             kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
    {
      return impl(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) && noexcept
    requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
             kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
    {
      return static_cast<decltype(impl)&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) const&& noexcept
    requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
             kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
    {
      return static_cast<decltype(impl) const&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) const& noexcept
    requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
             kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
    {
      return impl(std::type_identity<T>{});
    }

    //==================================================================================================================
    /**
      @brief Extracts the element of the field labeled L from a kumi::record

      @note Does not participate in overload resolution if the label is not present in the record

      @param  l label of the field to access
      @return A reference to the element of the selected field of current record.

      ## Example:
      @include doc/record/api/labeled_subscript.cpp
    **/
    //==================================================================================================================

    template<kumi::str Name>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::label_t<Name> l) & noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<Name>, Ts...>)
    {
      return impl(std::integral_constant<kumi::str, Name>{});
    }

    /// @overload
    template<kumi::str Name>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<Name>) && noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<Name>, Ts...>)
    {
      return static_cast<decltype(impl)&&>(impl)(std::integral_constant<kumi::str, Name>{});
    }

    /// @overload
    template<kumi::str Name>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<Name>) const&& noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<Name>, Ts...>)
    {
      return static_cast<decltype(impl) const&&>(impl)(std::integral_constant<kumi::str, Name>{});
    }

    /// @overload
    template<kumi::str Name>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<Name>) const& noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<Name>, Ts...>)
    {
      return impl(std::integral_constant<kumi::str, Name>{});
    }

    //==================================================================================================================
    /**
      @brief Extracts the element whose identifier matches Id from a kumi::record

      @note Does not participate in overload resolution if there are no field which identifier matches Id in
            the record.
      @tparam Id Identifier of the element to access
      @return A reference to the selected element of current record.

      ## Example:
      @include doc/record/api/named_subscript.cpp
    **/
    //==================================================================================================================
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) & noexcept
    requires(kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return impl(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) && noexcept
    requires(kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return static_cast<decltype(impl)&&>(impl)(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) const&& noexcept
    requires(kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return static_cast<decltype(impl) const&&>(impl)(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) const& noexcept
    requires(kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return impl(kumi::_::tag_of_t<Id>{});
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @name Properties
      @{
    **/
    //==================================================================================================================

    /// @return Returns the number of elements in a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(Ts); }

    /// @return Returns `true` if a kumi::record contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// Returns the identifiers associated to the elements of a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto identifiers() noexcept { return tuple{kumi::identifier_of<Ts>()...}; }

    /// Returns the labels associated to the elements of a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto labels() noexcept { return tuple{kumi::label_of<Ts>()...}; }

    /// Returns references to the values of the element in a kumi::record
    [[nodiscard]] KUMI_ABI constexpr auto values() noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<stored_member_t<I, decltype(*this)>...>{kumi::field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    }

    /// @overload
    [[nodiscard]] KUMI_ABI constexpr auto values() const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<stored_member_t<I, decltype(*this)>...>{kumi::field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief Replaces the content of the record with the content of another record.
      @param other kumi::record to copy or move from
      @return `*this`

      @note This function does not participate in overload resolutions if the fields in each record
            does not match or if the types between two matching fields do not match.
    **/
    //==================================================================================================================
    template<typename... Us>
    KUMI_ABI constexpr record& operator=(record<Us...> const& other)
    requires(kumi::concepts::equivalent<record, record<Us...>>)
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::fieldwise_convertible<record, record<Us...>>)
#endif
    {
      ((get<kumi::identifier_of<Ts>()>(*this) = get<kumi::identifier_of<Ts>()>(KUMI_FWD(other))), ...);
      return *this;
    }

    /// @overload
    template<typename... Us>
    KUMI_ABI constexpr record& operator=(record<Us...>&& other)
    requires(kumi::concepts::equivalent<record, record<Us...>>)
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::fieldwise_convertible<record, record<Us...>>)
#endif
    {
      ((get<kumi::identifier_of<Ts>()>(*this) = get<kumi::identifier_of<Ts>()>(KUMI_FWD(other))), ...);
      return *this;
    }

    //==================================================================================================================
    /**
      @name Comparison operators
      @{
    **/
    //==================================================================================================================

    /// @brief Compares a record with an other for equality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(record const& self, record<Us...> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::fieldwise_comparable<record, record<Us...>>)
#endif
    {
      return ((get<kumi::identifier_of<Ts>()>(self) == get<kumi::identifier_of<Ts>()>(other)) && ...);
    }

    /// @brief Compares a record with an other for inequality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(record const& self, record<Us...> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::fieldwise_comparable<record, record<Us...>>)
#endif
    {
      return !(self == other);
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @related kumi::record
      @brief Inserts a kumi::record in an output stream
    **/
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         record const& t) noexcept
    {
      os << "{ ";
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((os << t[index<I>] << ", "), ...);
      }(std::make_index_sequence<kumi::size_v<record> - 1>{});
      os << t[kumi::index<kumi::size_v<record> - 1>] << " }";

      return os;
    }
  };

  template<> struct record<>
  {
    using is_record_type = void;
    static constexpr bool is_homogeneous = false;

    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return std::size_t{0}; }

    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return true; }

    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept { return kumi::tuple{}; }

    [[nodiscard]] KUMI_ABI static constexpr auto values() noexcept { return kumi::tuple{}; }

    KUMI_ABI friend constexpr auto operator<=>(record<>, record<>) noexcept = default;

    template<typename T>
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    requires(kumi::concepts::unit_type<T>)
    {
      return {};
    }

    template<typename T>
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    requires(kumi::concepts::unit_type<T>)
    {
      return {};
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, record<>) noexcept
    {
      return os << "{}";
    }
  };

  //====================================================================================================================
  // Specialisation to clearly signal errors due to duplicate fields
  //====================================================================================================================
  template<typename... Ts>
  requires(!kumi::concepts::uniquely_named<Ts...> || !kumi::concepts::fully_named<Ts...> ||
           !kumi::concepts::uniquely_labeled<Ts...>)
  struct record<Ts...>
  {
    static_assert(kumi::concepts::uniquely_named<Ts...>, "Duplicate fields in record definition");
    static_assert(kumi::concepts::uniquely_labeled<Ts...>, "Duplicate identifier representation in record definition");
    static_assert(kumi::concepts::fully_named<Ts...>, "Anonymous field usage in record definition");
    record(Ts&&...) = delete;
  };

  //====================================================================================================================
  /**
    @name Record Deduction Guides
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related kumi::record
    @brief kumi::record deduction guide
    @tparam Ts  Type lists to build the record with.
  **/
  //====================================================================================================================
  template<typename... Ts> KUMI_CUDA record(Ts&&...) -> record<std::unwrap_ref_decay_t<Ts>...>;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Record construction
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Creates a kumi::record of lvalue references to its arguments.

    @tparam Fields Non type template parameters names to associate to the each element.
    @param ts	Zero or more lvalue arguments to construct the record from.
    @return A kumi::record object containing lvalue references.
    ## Example:
    @include doc/record/api/tie.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier auto... Fields, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto tie(Ts&... ts) -> kumi::record<kumi::field<decltype(Fields), Ts&>...>
  requires(sizeof...(Fields) == sizeof...(Ts))
  {
    return {ts...};
  }

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Creates a kumi::record of forwarding references to its arguments.

    Constructs a record of references to the arguments in args suitable for forwarding as an
    argument to a function. The record has rvalue reference data members when rvalues are used as
    arguments, and otherwise has lvalue reference data members.

    @note If the arguments are temporaries, `forward_as_record` does not extend their lifetime;
          they have to be used before the end of the full expression.

    @tparam Fields Non type template parameters names to associate to the each element.
    @param ts	Zero or more lvalue arguments to construct the record from.
    @return A kumi::record constructed as `kumi::record<Ts&&...>(std::forward<Ts>(args)...)`
    ## Example:
    @include doc/record/api/forward_as_record.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier auto... Fields, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto forward_as_record(Ts&&... ts)
    -> kumi::record<kumi::field<decltype(Fields), Ts&&>...>
  requires(sizeof...(Fields) == sizeof...(Ts))
  {
    return {KUMI_FWD(ts)...};
  }

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Creates a record object, deducing the target type from the types of arguments.

    @param ts	Zero or more lvalue arguments to construct the record from.
    @return A kumi::record constructed from the ts or their inner references when ts is an instance
            of `std::reference_wrapper`.
    ## Example:
    @include doc/record/api/make_record.cpp
  **/
  //====================================================================================================================
  template<typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto make_record(Ts&&... ts) -> kumi::record<std::unwrap_ref_decay_t<Ts>...>
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::fully_named<Ts...>)
  {
    return {KUMI_FWD(ts)...};
  }

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Creates a kumi::record of references given a reference to a kumi::record_type.

    @param    r Record whose elements are to be referenced.
    @return   A record equivalent to the result of `kumi::apply([]<typename... T>(T&&... e)
              { return kumi::forward_as_record<name_of(as<T>{})...>(std::forward<T>(e)...); }, t)`

    ## Example:
    @include doc/record/api/to_ref.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::record_type R> [[nodiscard]] KUMI_ABI constexpr auto to_ref(R&& r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::forward_as_record<kumi::identifier_of<kumi::element_t<I, R>>()...>(
        kumi::field_value_of(get<I>(KUMI_FWD(r)))...);
    }(std::make_index_sequence<kumi::size_v<R>>{});
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Record conversion
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Converts a kumi::record to an instance of a type that models kumi::record_type

    Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.

    @tparam Type Type to generate
    @param  r    kumi::record to convert
    @return An instance of `Type` constructed from each element of `t` in order.

    ## Example
    @include doc/record/api/from_record.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::record_type Type, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto from_record(record<Ts...> const& r)
  requires(
    kumi::concepts::equivalent<typename kumi::_::as_tuple<Type, std::make_index_sequence<kumi::size_v<Type>>>::type,
                               kumi::tuple<Ts...>>)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return Type{get<kumi::identifier_of<kumi::element_t<I, Type>>()>(r)...};
    }(std::make_index_sequence<kumi::size_v<Type>>());
  }

  //====================================================================================================================
  /**
    @ingroup record_related
    @brief Converts a kumi::record_type to an instance kumi::record

    Constructs an instance kumi::record from the elements of the kumi::product_type parameters

    @param  r    kumi::product_type to convert
    @return An instance of kumi::record constructed from each elements of `t` in order.

    ## Example
    @include doc/record/api/to_record.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::record_type Type> [[nodiscard]] KUMI_ABI constexpr auto to_record(Type&& r)
  {
    if constexpr (kumi::concepts::empty_product_type<Type>) return kumi::record{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return kumi::record{kumi::capture_field<kumi::identifier_of<kumi::element_t<I, Type>>()>(
          get<kumi::identifier_of<kumi::element_t<I, Type>>()>(KUMI_FWD(r)))...};
      }(std::make_index_sequence<kumi::size_v<Type>>{});
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Record accessors
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related record
    @brief Extracts the Ith field from a kumi::record

    @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    @tparam   I Compile-time index of the field to access
    @param    r Record to index
    @return   A reference to the selected field of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/record/api/get.cpp
  **/
  //====================================================================================================================
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  requires(I < sizeof...(Ts))
  {
    return r[kumi::index<I>];
  }

  /// @related record
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  requires(I < sizeof...(Ts))
  {
    return static_cast<record<Ts...>&&>(r)[kumi::index<I>];
  }

  /// @related record
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  requires(I < sizeof...(Ts))
  {
    return r[kumi::index<I>];
  }

  /// @related record
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  requires(I < sizeof...(Ts))
  {
    return static_cast<record<Ts...> const&&>(r)[kumi::index<I>];
  }

  //====================================================================================================================
  /**
    @related record
    @brief Extracts the element of the field labeled L from a kumi::record if it exists

    @note Does not participate in overload resolution if the names are not unique
    @tparam   L Non type template parameter label of the field to access
    @param    r Record to index
    @return   A reference to the element of the selected field of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/record/api/labeled_get.cpp
  **/
  //====================================================================================================================
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  requires(kumi::_::contains_label<L, Ts...>())
  {
    return r[kumi::label<L>];
  }

  /// @related record
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  requires(kumi::_::contains_label<L, Ts...>())
  {
    return static_cast<record<Ts...>&&>(r)[kumi::label<L>];
  }

  /// @related record
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  requires(kumi::_::contains_label<L, Ts...>())
  {
    return r[kumi::label<L>];
  }

  /// @related record
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  requires(kumi::_::contains_label<L, Ts...>())
  {
    return static_cast<record<Ts...> const&&>(r)[kumi::label<L>];
  }

  //====================================================================================================================
  /**
    @related record
    @brief Extracts the field identified by Id from a kumi::record if it exists

    @note     Does not participate in overload resolution if the names are not unique
    @tparam   Id Non type template parameter identifier of the element to access
    @param    r Record to index
    @return   A reference to the selected element of r.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/record/api/named_get.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  requires(kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return r[Id];
  }

  /// @related record
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  requires(kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return static_cast<record<Ts...>&&>(r)[Id];
  }

  /// @related record
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  requires(kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return r[Id];
  }

  /// @related record
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  requires(kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return static_cast<record<Ts...> const&&>(r)[Id];
  }

  //====================================================================================================================
  /**
    @related record
    @brief Extracts the field which underlying type is T from a kumi::record if it exist

    @note     Does not participate in overload resolution if the types are not unique
    @tparam   T Type of the element to access
    @param    r Record to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/record/api/typed_get.cpp
  **/
  //====================================================================================================================
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
           kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
  {
    return r[kumi::as<T>{}];
  }

  /// @related record
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
           kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
  {
    return static_cast<record<Ts...>&&>(r)[kumi::as<T>{}];
  }

  /// @related record
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
           kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
  {
    return r[kumi::as<T>{}];
  }

  /// @related record
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  requires(kumi::concepts::uniquely_typed<kumi::_::type_of_t<Ts>...> &&
           kumi::concepts::contains_type<T, kumi::_::type_of_t<Ts>...>)
  {
    return static_cast<record<Ts...> const&&>(r)[kumi::as<T>{}];
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
#ifndef KUMI_DOXYGEN_INVOKED
  /// Improves diagnostic for out of bounds index
  template<std::size_t I, typename R>
  requires(kumi::is_kumi_record_v<std::remove_cvref_t<R>> && ((I >= kumi::size_v<R>) || (I < 0)))
  constexpr auto get(R&& r) = delete;

  /// Improves diagnostic for non present label
  template<kumi::str S, typename R>
  requires(kumi::is_kumi_record_v<std::remove_cvref_t<R>> && !kumi::_::contains_identifier<S, R>())
  constexpr auto get(R&& r) = delete;

  /// Improves diagnostic for non present identifier
  template<kumi::concepts::identifier auto S, typename R>
  requires(kumi::is_kumi_record_v<std::remove_cvref_t<R>> && !kumi::concepts::contains_identifier<decltype(S), R>)
  constexpr auto get(R&& r) = delete;

  /// Improves diagnostic for non present type
  template<typename U, typename R>
  requires(kumi::is_kumi_record_v<std::remove_cvref_t<R>> && !kumi::concepts::contains_type<U, R>)
  constexpr auto get(R&& r) = delete;
#endif

  // Builder protocole
  template<kumi::concepts::record_type R> struct builder<R>
  {
    using type = R;

    template<typename... Us> using to = kumi::record<Us...>;

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto make(Args&&... args)
    {
      return kumi::make_record(KUMI_FWD(args)...);
    }

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto build(Args&&... args)
    {
      return kumi::record{KUMI_FWD(args)...};
    }
  };

  // As we are lacking a proper mechanism to find the least restrictive subtype, we fallback to a specializable trait
  template<kumi::concepts::record_type... Ts> struct common_product_type<Ts...>
  {
    using type = kumi::record<>;
  };
}
