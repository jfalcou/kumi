//==================================================================================================
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
  //! @ingroup record
  //! @class record
  //! @brief Fixed-size collection of heterogeneous fields necessarily named, names are unique.
  //!
  //! kumi::record provides an aggregate based implementation of a record. It provides algorithms and
  //! functions designed to facilitate record's handling and transformations.
  //!
  //! kumi::record is also compatible with standard tuple operations and structured bindings to some
  //! extent.
  //!
  //! @tparam Ts Sequence of fields stored inside kumi::record.
  //================================================================================================
  template<typename... Ts>
  requires (( entirely_uniquely_named<Ts...> ))
  struct record<Ts...>
  {
    using is_product_type   = void;
    using is_record_type    = void;
    using binder_t = _::make_binder_t<std::make_integer_sequence<int,sizeof...(Ts)>, Ts...>;

    static constexpr bool is_homogeneous = false;

    binder_t impl;

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
    //! @include doc/record/subscript.cpp
    //==============================================================================================
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) &noexcept
    {
      return _::get_leaf<I>(impl);
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) &&noexcept
    {
      return _::get_leaf<I>(static_cast<decltype(impl) &&>(impl));
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const &&noexcept
    {
      return _::get_leaf<I>(static_cast<decltype(impl) const &&>(impl));
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const &noexcept
    {
      return _::get_leaf<I>(impl);
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
    //! @include doc/record/named_subscript.cpp
    //==============================================================================================
    template<str Name>
    requires( contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) &noexcept
    {
      return _::get_leaf<Name>(impl);
    }

    /// @overload
    template<str Name>
    requires( contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) &&noexcept
    {
      return _::get_leaf<Name>(static_cast<decltype(impl) &&>(impl));
    }

    /// @overload
    template<str Name>
    requires( contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) const &&noexcept
    {
      return _::get_leaf<Name>(static_cast<decltype(impl) const &&>(impl));
    }

    /// @overload
    template<str Name>
    requires( contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) const &noexcept
    {
      return _::get_leaf<Name>(impl);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @name Properties
    //! @{
    //==============================================================================================
    /// Returns the number of elements in a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr  auto size() noexcept { return sizeof...(Ts); }

    /// Returns `true` if a kumi::record contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr  bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// Returns the names of the elements in a kumi::record
    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept
    {
        return tuple{ name_of(as<Ts>{})... };
    };

    /// Returns references to the values of the element in a kumi::record
    [[nodiscard]] KUMI_ABI constexpr auto values() noexcept
    {
        return [&]<std::size_t...I>(std::index_sequence<I...>)
        {
            return tuple<raw_member_t<I, decltype(*this)>...>{field_value_of(get<I>(*this))...};
        }(std::make_index_sequence<sizeof...(Ts)>{});
    };

    /// @overload
    [[nodiscard]] KUMI_ABI constexpr auto values() const noexcept
    {
        return [&]<std::size_t...I>(std::index_sequence<I...>)
        {
            return tuple<raw_member_t<I,decltype(*this)>...>{field_value_of(get<I>(*this))...};
        }(std::make_index_sequence<sizeof...(Ts)>{});
    };

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @brief Replaces the contents of the record with the contents of another record.
    //! @param other kumi::record to copy or move from
    //! @return `*this`
    //==============================================================================================
    template<typename... Us>
    requires( equivalent<record, record<Us...>>  && _::fieldwise_convertible<record, record<Us...>> )
    KUMI_ABI constexpr record &operator=(record<Us...> const &other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }

    /// @overload
    template<typename... Us>
    requires( equivalent<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>> )
    KUMI_ABI constexpr record &operator=(record<Us...> &&other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }

    //==============================================================================================
    //! @name Comparison operators
    //! @{
    //==============================================================================================

    /// @ingroup record
    /// @related kumi::record
    /// @brief Compares a record with an other for equality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(record const &self, record<Us...> const &other) noexcept
    requires( named_equality_comparable<record,record<Us...>> )
    {
      return ((get<name_of(as<Ts>{})>(self) == get<name_of(as<Ts>{})>(other)) && ...);
    }

    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(record const &self, record<Us...> const &other) noexcept
    requires( named_equality_comparable<record,record<Us...>> )
    {
      return !(self == other);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    /// @ingroup record
    //! @related kumi::record
    //! @brief Inserts a kumi::record in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                                         record const &t) noexcept
    {
      os << "( ";
      kumi::for_each([&os](auto name, auto const &e)
      {
        os << name << " : " << e << " ";
      }, t.names(), t.values());
      os << ")";

      return os;
    }
  };

  template<> struct record<>  
  {
    using is_product_type   = void;
    using is_record_type    = void;
    static constexpr bool is_homogeneous = false;

    static constexpr auto size()    noexcept { return std::size_t{0}; }
    static constexpr auto empty()   noexcept { return true;           }
    static constexpr auto names()   noexcept { return tuple{};        }
    static constexpr auto values()  noexcept { return tuple{};        }
    
    KUMI_ABI friend constexpr auto operator<=>(record<>, record<>) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, record<>)
    {
      return os << "()";
    }
  };

  //================================================================================================
  //! @name Record Deduction Guides
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @brief kumi::record deduction guide
  //! @tparam Ts  Type lists to build the record with.
  //================================================================================================
  template<typename... Ts> KUMI_CUDA record(Ts &&...) -> record<std::unwrap_ref_decay_t<Ts>...>;

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
  //! @include doc/record/tie.cpp
  //================================================================================================
  template<str... Fields, typename... Ts>
  requires( sizeof...(Fields) == sizeof...(Ts) )
  KUMI_ABI constexpr auto tie(Ts &... ts) -> record<field_capture<Fields, Ts&>...>
  {
    return {ts...};
  }

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
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
  //! @include doc/record/forward_as_record.cpp
  //================================================================================================
  template<str... Fields, typename... Ts>
  requires (sizeof...(Fields) == sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr auto forward_as_record( Ts &&... ts ) -> 
  record<field_capture<Fields, Ts&&>...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
  //! @brief Creates a record object, deducing the target type from the types of arguments.
  //!
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record constructed from the ts or their inner references when ts is an instance
  //!         of `std::reference_wrapper`.
  //! ## Example:
  //! @include doc/record/make_record.cpp
  //================================================================================================
  template<typename... Ts>
  requires ( entirely_uniquely_named<Ts...> )
  [[nodiscard]] KUMI_ABI constexpr auto make_record(Ts &&...ts) ->
  record<std::unwrap_ref_decay_t<Ts>...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
  //! @brief Creates a kumi::record of references given a reference to a kumi::record_type.
  //!
  //! @param    r Record whose elements are to be referenced.  
  //! @return   A record equivalent to the result of `kumi::apply([]<typename... T>(T&&... e)
  //!           { return kumi::forward_as_record<name_of(as<T>{})...>(std::forward<T>(e)...); }, t)`
  //!
  //! ## Example:
  //! @include doc/record/to_ref.cpp
  //================================================================================================
  template<record_type Type>
  [[nodiscard]] KUMI_ABI constexpr auto to_ref(Type && r)
  {
    return _::apply_field( [](auto&&... elems)
              {
                return kumi::forward_as_record<name_of(as<decltype(elems)>{})...>(field_value_of(KUMI_FWD(elems))...);
              }
            , KUMI_FWD(r)
            );
  }

  //================================================================================================
  //! @}
  //================================================================================================

  //================================================================================================
  //! @name Accessors
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the Ith field from a kumi::record
  //!
  //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
  //! @tparam   I Compile-time index of the field to access
  //! @param    r Record to index
  //! @return   A reference to the selected field of r.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/record/get.cpp
  //================================================================================================
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> &r) noexcept
  {
    return r[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> &&r) noexcept
  {
    return static_cast<record<Ts...> &&>(r)[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> const &r) noexcept
  {
    return r[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> const &&r) noexcept
  {
    return static_cast<record<Ts...> const &&>(r)[index<I>];
  }

  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the element of the field labeled Name from a kumi::record if it exists
  //!
  //! @note Does not participate in overload resolution if the names are not unique
  //! @tparam   Name Non type template parameter name of the field to access
  //! @param    r Record to index
  //! @return   A reference to the element of the selected field of r.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/record/named_get.cpp
  //================================================================================================
  template<str Name, typename... Ts>
  requires ( contains_field<Name, Ts...> ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> &r) noexcept
  {
    return r[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( contains_field<Name, Ts...> ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> &&r) noexcept
  {
    return static_cast<record<Ts...> &&>(r)[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( contains_field<Name, Ts...> ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> const &r) noexcept
  {
    return r[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( contains_field<Name, Ts...> ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(record<Ts...> const &&r) noexcept
  {
    return static_cast<record<Ts...> const &&>(r)[field<Name>];
  }

  //================================================================================================
  //! @}
  //================================================================================================
}

#endif
