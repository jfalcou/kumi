//==================================================================================================
//! @file
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#ifndef KUMI_RECORD_HPP_INCLUDED
#define KUMI_RECORD_HPP_INCLUDED

#include <kumi/product_types/tuple.hpp>

namespace kumi
{
  //================================================================================================
  //! @class record
  //! @ingroup record
  //! @brief Fixed-size collection of heterogeneous tagged fields, tags are unique.
  //!
  //! kumi::record provides an aggregate based implementation of a record. It provides algorithms and
  //! functions designed to facilitate record's handling and transformations.
  //!
  //! kumi::record is also compatible with standard tuple operations and structured bindings to some
  //! extent.
  //!
  //! @tparam Ts Sequence of fields stored inside kumi::record.
  //================================================================================================
  template<typename... Ts> struct record
  {
    using is_record_type = void;
    using set_t = _::make_set_t<Ts...>;

    static constexpr bool is_homogeneous = false;

    set_t impl;

    //==============================================================================================
    //! @name Accessors
    //! @{
    //==============================================================================================

    //==============================================================================================
    //! @brief Extracts the Ith field from a kumi::record
    //!
    //! @note   Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @tparam I Compile-time index of the field to access
    //! @return A reference to the selected field of current record.
    //!
    //! ## Example:
    //! @include doc/record/api/subscript.cpp
    //==============================================================================================
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) & noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T&>(impl);
    }

    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) && noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T&&>(static_cast<decltype(impl)&&>(impl));
    }

    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const&& noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T const&&>(static_cast<decltype(impl) const&&>(impl));
    }

    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const& noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T const&>(impl);
    }

    //==============================================================================================
    //! @brief Extracts the Ith element from a kumi::record
    //!
    //! @note Does not participate in overload resolution if `T` is not present in the record or if
    //!       the record contains duplicate types
    //! @tparam T the type to access in the record
    //! @return A reference to the selected element of current record.
    //!
    //! ## Example:
    //! @include doc/record/api/typed_subscript.cpp
    //==============================================================================================
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) & noexcept
    {
      return impl(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const& noexcept
    {
      return impl(std::type_identity<T>{});
    }

    //==============================================================================================
    //! @brief Extracts the element of the field labeled Name from a kumi::record
    //!
    //! @note Does not participate in overload resolution if the name is not present in the record
    //!
    //! @tparam Name Non type template parameter name of the field to access
    //! @return A reference to the element of the selected field of current record.
    //!
    //! ## Example:
    //! @include doc/record/api/named_subscript.cpp
    //==============================================================================================
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) & noexcept
    {
      return impl(n);
    }

    /// @overload
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(n);
    }

    /// @overload
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(n);
    }

    /// @overload
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const& noexcept
    {
      return impl(n);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @name Properties
    //! @{
    //==============================================================================================

    /// @return Returns the number of elements in a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(Ts); }

    /// @return Returns `true` if a kumi::record contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// @return Returns the names of the elements in a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept { return tuple{name_of(as<Ts>{})...}; };

    /// @return Return references to the values of the elements of a kumi::record as a kumi::tuple
    [[nodiscard]] KUMI_ABI constexpr auto values() noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<raw_member_t<I, decltype(*this)>...>{field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    };

    /// @overload
    [[nodiscard]] KUMI_ABI constexpr auto values() const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<raw_member_t<I, decltype(*this)>...>{field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    };

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @brief Replaces the content of the record with the content of another record.
    //! @param other kumi::record to copy or move from
    //! @return `*this`
    //==============================================================================================
    template<typename... Us>
    requires(concepts::equivalent<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>>)
    KUMI_ABI constexpr record& operator=(record<Us...> const& other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }

    /// @overload
    template<typename... Us>
    requires(concepts::equivalent<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>>)
    KUMI_ABI constexpr record& operator=(record<Us...>&& other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }

    //==============================================================================================
    //! @name Comparison operators
    //! @{
    //==============================================================================================

    /// @brief Compares a record with an other for equality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(record const& self, record<Us...> const& other) noexcept
    requires(concepts::named_equality_comparable<record, record<Us...>>)
    {
      return ((get<name_of(as<Ts>{})>(self) == get<name_of(as<Ts>{})>(other)) && ...);
    }

    /// @brief Compares a record with an other for inequality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(record const& self, record<Us...> const& other) noexcept
    requires(concepts::named_equality_comparable<record, record<Us...>>)
    {
      return !(self == other);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @related kumi::record
    //! @brief Inserts a kumi::record in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         record const& t) noexcept
    {
      os << "( ";
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((os << t[index<I>] << " "), ...);
      }(std::make_index_sequence<size_v<decltype(t)>>{});
      os << ')';

      return os;
    }
  };

  template<> struct record<>
  {
    using is_record_type = void;
    static constexpr bool is_homogeneous = false;

    static constexpr auto size() noexcept { return std::size_t{0}; }

    static constexpr auto empty() noexcept { return true; }

    static constexpr auto names() noexcept { return tuple{}; }

    static constexpr auto values() noexcept { return tuple{}; }

    KUMI_ABI friend constexpr auto operator<=>(record<>, record<>) noexcept = default;

    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    {
      return {};
    };

    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    {
      return {};
    };

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, record<>) noexcept
    {
      return os << "()";
    }
  };

  //================================================================================================
  // Specialisation to clearly signal errors due to duplicate fields
  //================================================================================================
  template<typename... Ts>
  requires(!concepts::entirely_uniquely_named<Ts...> || !concepts::unique_display_name<Ts...>)
  struct record<Ts...>
  {
    static_assert(concepts::entirely_uniquely_named<Ts...>, "Duplicate fields in record definition");
    static_assert(concepts::unique_display_name<Ts...>, "Duplicate identifier representation in record definition");
    record(Ts&&...) = delete;
  };

  //================================================================================================
  //! @name Record Deduction Guides
  //! @{
  //================================================================================================

  //================================================================================================
  //! @related kumi::record
  //! @brief kumi::record deduction guide
  //! @tparam Ts  Type lists to build the record with.
  //================================================================================================
  template<typename... Ts> KUMI_CUDA record(Ts&&...) -> record<std::unwrap_ref_decay_t<Ts>...>;

  //================================================================================================
  //! @}
  //================================================================================================

  //================================================================================================
  //! @name Record construction
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @brief Creates a kumi::record of lvalue references to its arguments.
  //!
  //! @tparam Fields Non type template parameters names to associate to the each element.
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record object containing lvalue references.
  //! ## Example:
  //! @include doc/record/api/tie.cpp
  //================================================================================================
  template<concepts::identifier auto... Fields, typename... Ts>
  requires(sizeof...(Fields) == sizeof...(Ts))
  KUMI_ABI constexpr auto tie(Ts&... ts) -> record<field<decltype(Fields), Ts&>...>
  {
    return {ts...};
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Creates a kumi::record of forwarding references to its arguments.
  //!
  //! Constructs a record of references to the arguments in args suitable for forwarding as an
  //! argument to a function. The record has rvalue reference data members when rvalues are used as
  //! arguments, and otherwise has lvalue reference data members.
  //!
  //! @note If the arguments are temporaries, `forward_as_record` does not extend their lifetime;
  //!       they have to be used before the end of the full expression.
  //!
  //! @tparam Fields Non type template parameters names to associate to the each element.
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record constructed as `kumi::record<Ts&&...>(std::forward<Ts>(args)...)`
  //! ## Example:
  //! @include doc/record/api/forward_as_record.cpp
  //================================================================================================
  template<concepts::identifier auto... Fields, typename... Ts>
  requires(sizeof...(Fields) == sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr auto forward_as_record(Ts&&... ts) -> record<field<decltype(Fields), Ts&&>...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Creates a record object, deducing the target type from the types of arguments.
  //!
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record constructed from the ts or their inner references when ts is an instance
  //!         of `std::reference_wrapper`.
  //! ## Example:
  //! @include doc/record/api/make_record.cpp
  //================================================================================================
  template<typename... Ts>
  requires(concepts::entirely_uniquely_named<Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto make_record(Ts&&... ts) -> record<std::unwrap_ref_decay_t<Ts>...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Creates a kumi::record of references given a reference to a kumi::record_type.
  //!
  //! @param    r Record whose elements are to be referenced.
  //! @return   A record equivalent to the result of `kumi::apply([]<typename... T>(T&&... e)
  //!           { return kumi::forward_as_record<name_of(as<T>{})...>(std::forward<T>(e)...); }, t)`
  //!
  //! ## Example:
  //! @include doc/record/api/to_ref.cpp
  //================================================================================================
  template<concepts::record_type R> [[nodiscard]] KUMI_ABI constexpr auto to_ref(R&& r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::forward_as_record<name_of(as<element_t<I, R>>{})...>(field_value_of(get<I>(KUMI_FWD(r)))...);
    }(std::make_index_sequence<size_v<R>>{});
  }

  //================================================================================================
  //! @}
  //================================================================================================

  //================================================================================================
  //! @name Record conversion
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @brief Converts a kumi::record to an instance of a type that models kumi::record_type
  //!
  //! Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.
  //!
  //! @tparam Type Type to generate
  //! @param  r    kumi::record to convert
  //! @return An instance of `Type` constructed from each element of `t` in order.
  //!
  //! ## Example
  //! @include doc/record/api/from_record.cpp
  //================================================================================================
  template<concepts::record_type Type, typename... Ts>
  requires(concepts::equivalent<typename _::as_tuple<Type, std::make_index_sequence<size_v<Type>>>::type, tuple<Ts...>>)
  [[nodiscard]] KUMI_ABI constexpr auto from_record(record<Ts...> const& r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return Type{get<name_of(as<element_t<I, Type>>{})>(r)...};
    }(std::make_index_sequence<size_v<Type>>());
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Converts a kumi::record_type to an instance kumi::record
  //!
  //! Constructs an instance kumi::record from the elements of the kumi::product_type parameters
  //!
  //! @param  r    kumi::product_type to convert
  //! @return An instance of kumi::record constructed from each elements of `t` in order.
  //!
  //! ## Example
  //! @include doc/record/api/to_record.cpp
  //================================================================================================
  template<concepts::record_type Type> [[nodiscard]] KUMI_ABI constexpr auto to_record(Type&& r)
  {
    if constexpr (concepts::sized_product_type<Type, 0>) return kumi::record{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return record{
          capture_field<name_of(as<element_t<I, Type>>{})>(get<name_of(as<element_t<I, Type>>{})>(KUMI_FWD(r)))...};
      }(std::make_index_sequence<size_v<Type>>{});
  }

  //================================================================================================
  //! @}
  //================================================================================================

  //================================================================================================
  //! @name Record accessors
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the Ith field from a kumi::record
  //!
  //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
  //! @tparam   I Compile-time index of the field to access
  //! @param    r Record to index
  //! @return   A reference to the selected field of t.
  //!
  //! ## Example:
  //! @include doc/record/api/get.cpp
  //================================================================================================
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[index<I>];
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the element of the field labeled Name from a kumi::record if it exists
  //!
  //! @note Does not participate in overload resolution if the names are not unique
  //! @tparam   Name Non type template parameter name of the field to access
  //! @param    r Record to index
  //! @return   A reference to the element of the selected field of t.
  //!
  //! ## Example:
  //! @include doc/record/api/named_get.cpp
  //================================================================================================
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[name<Name>{}];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[name<Name>{}];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[name<Name>{}];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[name<Name>{}];
  }

  /// @overload
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[Name];
  }

  /// @overload
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[Name];
  }

  /// @overload
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[Name];
  }

  /// @overload
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[Name];
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the field which underlying type is T from a kumi::record if it exist
  //!
  //! @note     Does not participate in overload resolution if the types are not unique
  //! @tparam   T Type of the element to access
  //! @param    r Record to index
  //! @return   A reference to the selected element of t.
  //!
  //! ## Example:
  //! @include doc/record/api/typed_get.cpp
  //================================================================================================
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[as<T>{}];
  }

  //================================================================================================
  //! @}
  //================================================================================================

  /// Improves diagnostic for out of bounds index
  template<std::integral auto I, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && ((I >= size_v<R>) || (I < 0)))
  constexpr auto get(R&& r) = delete;

  /// Improves diagnostic for non present name
  template<str S, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !_::contains_field<S, R>())
  constexpr auto get(R&& r) = delete;

  /// Improves diagnostic for non present name
  template<concepts::identifier auto S, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !concepts::contains_field<decltype(S), R>)
  constexpr auto get(R&& r) = delete;

  /// No get<type> on records
  template<typename U, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !concepts::contains_type<U, R>)
  constexpr auto get(R&& r) = delete;

  // Builder protocole
  template<concepts::record_type R> struct builder<R>
  {
    using type = R;

    template<typename... Us> using to = kumi::record<Us...>;

    template<typename... Args> static constexpr auto make(Args&&... args)
    {
      return kumi::make_record(KUMI_FWD(args)...);
    }

    template<typename... Args> static constexpr auto build(Args&&... args) { return kumi::record{KUMI_FWD(args)...}; }
  };

  // As we are lacking a proper mechanism to find the least restrictive subtype, we fallback to a specializable trait
  template<concepts::record_type... Ts> struct common_product_type<Ts...>
  {
    using type = kumi::record<>;
  };
}

#endif
