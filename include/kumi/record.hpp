//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#ifndef KUMI_RECORD_HPP_INCLUDED
#define KUMI_RECORD_HPP_INCLUDED

#include <kumi/tuple.hpp>

#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__) &&>(__VA_ARGS__)

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
  requires ( is_fully_named<Ts...> && uniquely_named<Ts...> )
  struct record
  {
    using is_product_type = void;
    using binder_t = _::make_binder_t<std::make_integer_sequence<int,sizeof...(Ts)>, Ts...>;

    static constexpr bool is_homogeneous = binder_t::is_homogeneous;

    binder_t impl;
    
    //==============================================================================================
    //! @name Accessors
    //! @{
    //==============================================================================================

    //==============================================================================================
    //! @brief Extracts the Ith field from a kumi::record
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @param  i Compile-time index of the field to access
    //! @return A reference to the selected field of current record.
    //!
    //! ## Example:
    //! @include doc/record_subscript.cpp
    //==============================================================================================
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_TRIVIAL constexpr decltype(auto) operator[]([[maybe_unused]] index_t<I> i) &noexcept
    {
      return unwrap_field_value(_::get_leaf<I>(impl));
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_TRIVIAL constexpr decltype(auto) operator[](index_t<I>) &&noexcept
    {
      return unwrap_field_value(_::get_leaf<I>(static_cast<decltype(impl) &&>(impl)));
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_TRIVIAL constexpr decltype(auto) operator[](index_t<I>) const &&noexcept
    {
      return unwrap_field_value(_::get_leaf<I>(static_cast<decltype(impl) const &&>(impl)));
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_TRIVIAL constexpr decltype(auto) operator[](index_t<I>) const &noexcept
    {
      return unwrap_field_value(_::get_leaf<I>(impl));
    }
 
    //==============================================================================================
    //! @brief Extracts the element of the field labeled Name from a kumi::record
    //!
    //! @note Does not participate in overload resolution if `get_name_index<Name>` 
    //!       is not in [0, sizeof...(Ts)).
    //!
    //! @tparam Name Non type template parameter name of the field to access
    //! @return A reference to the element of the selected field of current record.
    //!
    //! ## Example:
    //! @include doc/record_named_subscript.cpp
    //==============================================================================================
    template<auto Name>
    requires( contains_field<Name, Ts...> )
    constexpr decltype(auto) operator[](field_name<Name> const&) &noexcept
    {
      constexpr auto idx = _::get_name_index<Name, Ts...>();
      return unwrap_field_value(_::get_leaf<idx>(impl));
    }

    /// @overload
    template<auto Name>
    requires( contains_field<Name, Ts...> )
    constexpr decltype(auto) operator[](field_name<Name> const&) &&noexcept
    {
      constexpr auto idx = _::get_name_index<Name, Ts...>();
      return unwrap_field_value(_::get_leaf<idx>(static_cast<decltype(impl) &&>(impl)));
    }

    /// @overload
    template<auto Name>
    requires( contains_field<Name, Ts...> )
    constexpr decltype(auto) operator[](field_name<Name> const&) const &&noexcept
    {
      constexpr auto idx = _::get_name_index<Name, Ts...>();
      return unwrap_field_value(_::get_leaf<idx>(static_cast<decltype(impl) const &&>(impl)));
    }

    /// @overload
    template<auto Name>
    requires( contains_field<Name, Ts...> )
    constexpr decltype(auto) operator[](field_name<Name> const&) const &noexcept
    {
      constexpr auto idx = _::get_name_index<Name, Ts...>();
      return unwrap_field_value(_::get_leaf<idx>(impl));
    }

    //==============================================================================================
    //! @}
    //==============================================================================================
    
    //==============================================================================================
    //! @name Properties
    //! @{
    //==============================================================================================
    /// Returns the number of elements in a kumi::record
    KUMI_TRIVIAL_NODISCARD static constexpr  auto size() noexcept { return sizeof...(Ts); }

    /// Returns `true` if a kumi::record contains 0 elements
    KUMI_TRIVIAL_NODISCARD static constexpr  bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// Returns the names of the elements in a kumi::record 
    KUMI_TRIVIAL_NODISCARD static constexpr auto names() noexcept 
    {   
        using tuple_type = tuple<unwrap_name_t<Ts>...>;
        return tuple_type{ unwrap_name_v<Ts>... };
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
    requires( equally_named<record, record<Us...>>  && _::fieldwise_convertible<record, record<Us...>> ) 
    constexpr record &operator=(record<Us...> const &other)
    { 
      (([&] {
        constexpr auto name = field_name<Ts::name>{};
        get<name>(*this)    = get<name>(other);
      } ()), ...);
      return *this;
    }

    /// @overload
    template<typename... Us>
    requires( equally_named<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>> ) 
    constexpr record &operator=(record<Us...> &&other)
    {
      (([&] {
        constexpr auto name = field_name<Ts::name>{};
        get<name>(*this)    = get<name>(other);
      } ()), ...);
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
    friend constexpr auto operator==(record const &self, record<Us...> const &other) noexcept
    requires( named_equality_comparable<record,record<Us...>> )
    {
      return (([&] {
        constexpr auto name = field_name<Ts::name>{};
        return get<name>(self) == get<name>(other);
      } ()) && ...);
    }

    template<typename... Us>
    KUMI_TRIVIAL friend constexpr auto operator!=(record const &self, record<Us...> const &other) noexcept
    requires( named_equality_comparable<record,record<Us...>> )
    {
      return !(self == other);
    }

    /// @ingroup record
    /// @related kumi::record
    /// @brief Compares records for lexicographical is less relation
    template<typename... Us>
    friend constexpr auto operator<(record const &lhs, record<Us...> const &rhs) noexcept
    requires(sizeof...(Ts) == sizeof...(Us)) // && _::piecewise_ordered<record, record<Us...>>)
    {
      // lexicographical order is defined as
      // (v0 < w0) || ... andnot(wi < vi, vi+1 < wi+1) ... || andnot(wn-1 < vn-1, vn < wn);
      // comparison order is based on lhs order, will see what to do here
      using lhs_type    = std::remove_cvref_t<decltype(lhs)>;
      auto lhs_names    = lhs_type::names();
      auto first        = get<0>(lhs_names);

      auto res = get<first>(lhs) < get<first>(rhs);

      auto const order = [&]<typename Index>(Index i)
      {
        auto name           = lhs_names[i];
        auto next           = lhs_names[index_t<Index::value+1>{}];

        auto y_less_x_prev  = rhs[name] < lhs[name];
        auto x_less_y       = lhs[next] < rhs[next];
        return x_less_y && !y_less_x_prev;
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (res || ... || order(index_t<I>{}));
      }
      (std::make_index_sequence<sizeof...(Ts)-1>());
    }

    /// @ingroup record
    /// @related kumi::record
    /// @brief Compares records for lexicographical is less or equal relation
    template<typename... Us>
    KUMI_TRIVIAL friend constexpr auto operator<=(record const &lhs, record<Us...> const &rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return !(rhs < lhs);
    }

    /// @ingroup record
    /// @related kumi::record
    /// @brief Compares records for lexicographical is greater relation
    template<typename... Us>
    KUMI_TRIVIAL friend constexpr auto operator>(record const &lhs, record<Us...> const &rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return rhs < lhs;
    }

    /// @ingroup record
    /// @related kumi::record
    /// @brief Compares records for lexicographical is greater relation relation
    template<typename... Us>
    KUMI_TRIVIAL friend constexpr auto operator>=(record const &lhs, record<Us...> const &rhs) noexcept
    requires requires { lhs < rhs; }
    {
      return !(lhs < rhs);
    }
 
    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @brief Invoke the Callable object f on each element of the current record.
    //!
    //! @param f	Callable object to be invoked
    //! @return The value returned by f.
    //!
    //==============================================================================================
    template<typename Function>
    KUMI_TRIVIAL constexpr decltype(auto) operator()(Function &&f) const&
    noexcept(noexcept(kumi::apply(KUMI_FWD(f), *this))) { return kumi::apply(KUMI_FWD(f), *this); }

#if !defined(KUMI_DOXYGEN_INVOKED)
    template<typename Function>
    KUMI_TRIVIAL constexpr decltype(auto) operator()(Function &&f) &
    noexcept(noexcept(kumi::apply(KUMI_FWD(f), *this)))
    {
      return kumi::apply(KUMI_FWD(f), *this);
    }

    template<typename Function>
    KUMI_TRIVIAL constexpr decltype(auto) operator()(Function &&f) const &&noexcept(
    noexcept(kumi::apply(KUMI_FWD(f), static_cast<record const &&>(*this))))
    {
      return kumi::apply(KUMI_FWD(f), static_cast<record const &&>(*this));
    }

    template<typename Function>
    KUMI_TRIVIAL constexpr decltype(auto) operator()(Function &&f) &&noexcept(
    noexcept(kumi::apply(KUMI_FWD(f), static_cast<record &&>(*this))))
    {
      return kumi::apply(KUMI_FWD(f), static_cast<record &&>(*this));
    }
#endif
 
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
      kumi::for_each([&os](auto const &e) { os << e << " "; }, t);
      os << ")";

      return os;
    }
  };

  //================================================================================================
  //! @name record construction
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
  //! @brief kumi::record deduction guide
  //! @tparam Ts  Type lists to build the record with.
  //================================================================================================
  template<typename... Ts> record(Ts &&...) -> record<std::unwrap_ref_decay_t<Ts>...>;

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
  //! @brief Creates a kumi::record of lvalue references to its arguments.
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record object containing lvalue references.
  //! ## Example:
  //! @include doc/record_tie.cpp
  //================================================================================================
  template<typename... Ts> KUMI_TRIVIAL_NODISCARD constexpr record<Ts &...> tie(Ts &...ts) { return {ts...}; }

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
  //! @param ts	Zero or more lvalue arguments to construct the record from.
  //! @return A kumi::record constructed as `kumi::record<Ts&&...>(std::forward<Ts>(args)...)`
  //! ## Example:
  //! @include doc/forward_as_record.cpp
  //================================================================================================
  template<typename... Ts> KUMI_TRIVIAL_NODISCARD constexpr record<Ts &&...> forward_as_record(Ts &&...ts)
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
  //! @include doc/make_record.cpp
  //================================================================================================
  template<typename... Ts>
  KUMI_TRIVIAL_NODISCARD constexpr record<std::unwrap_ref_decay_t<Ts>...> make_record(Ts &&...ts)
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup record
  //! @related kumi::record
  //! @brief Creates a kumi::record of references given a reference to a kumi::product_type.
  //!
  //! @param    t Compile-time index of the element to access
  //! @return   A record equivalent to the result of `kumi::apply([]<typename... T>(T&&... e)
  //!           { return kumi::forward_as_record(std::forward<T>(e)...); }, t)`
  //!
  //! ## Example:
  //! @include doc/to_ref.cpp
  //================================================================================================
  /*template<product_type Type>
  KUMI_TRIVIAL_NODISCARD constexpr auto to_ref(Type&& t)
  {
    return apply( [](auto&&... elems)
                  {
                    return kumi::forward_as_record(KUMI_FWD(elems)...);
                  }
                , KUMI_FWD(t)
                );
  }*/

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
  //! @param    t Record to index
  //! @return   A reference to the selected field of t.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/record_get.cpp
  //================================================================================================
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts)) KUMI_TRIVIAL_NODISCARD constexpr decltype(auto) 
  get(record<Ts...> &t) noexcept
  {
    return t[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts)) KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)
  get(record<Ts...> &&arg) noexcept
  {
    return static_cast<record<Ts...> &&>(arg)[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts)) KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)
  get(record<Ts...> const &arg) noexcept
  {
    return arg[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts)) KUMI_TRIVIAL_NODISCARD constexpr decltype(auto)
  get(record<Ts...> const &&arg) noexcept
  {
    return static_cast<record<Ts...> const &&>(arg)[index<I>];
  }
 
  //================================================================================================
  //! @ingroup record
  //! @brief Extracts the element of the field labeled Name from a kumi::record if it exists
  //!
  //! @note Does not participate in overload resolution if the names are not unique
  //! @tparam   Name Non type template parameter name of the field to access
  //! @param    t Record to index
  //! @return   A reference to the element of the selected field of t.
  //! @related kumi::record
  //!
  //! ## Example:
  //! @include doc/record_named_get.cpp
  //================================================================================================
  template<field_name Name, typename... Ts>
  requires ( uniquely_named<Ts...> )
  KUMI_TRIVIAL_NODISCARD constexpr decltype(auto) 
  get(record<Ts...> &t) noexcept
  {
    return t[Name];
  }

  /// @overload
  template<field_name Name, typename... Ts>
  requires ( uniquely_named<Ts...> )
  KUMI_TRIVIAL_NODISCARD constexpr decltype(auto) 
  get(record<Ts...> &&arg) noexcept
  {
    return static_cast<record<Ts...> &&>(arg)[Name];
  }

  /// @overload
  template<field_name Name, typename... Ts>
  requires ( uniquely_named<Ts...> )
  KUMI_TRIVIAL_NODISCARD constexpr decltype(auto) 
  get(record<Ts...> const &arg) noexcept
  {
    return arg[Name];
  }

  /// @overload
  template<field_name Name, typename... Ts>
  requires ( uniquely_named<Ts...> )
  KUMI_TRIVIAL_NODISCARD constexpr decltype(auto) 
  get(record<Ts...> const &&arg) noexcept
  {
    return static_cast<record<Ts...> const &&>(arg)[Name];
  }

  //================================================================================================
  //! @}
  //================================================================================================
}

#include <kumi/algorithm.hpp>

#undef KUMI_FWD
#endif
