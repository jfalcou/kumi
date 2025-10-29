//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#ifndef KUMI_TUPLE_HPP_INCLUDED
#define KUMI_TUPLE_HPP_INCLUDED

#include <kumi/detail/concepts.hpp>
#include <kumi/detail/abi.hpp>
#include <kumi/detail/stdfix.hpp>
#include <kumi/detail/binder.hpp>
#include <kumi/detail/field_capture.hpp>
#include <kumi/utils.hpp>

#include <iosfwd>
#include <type_traits>

namespace kumi
{
  //================================================================================================
  //! @ingroup tuple
  //! @class tuple
  //! @brief Fixed-size collection of heterogeneous values.
  //!
  //! kumi::tuple provides an aggregate based implementation of a tuple. It provides algorithms and
  //! functions designed to facilitate tuple's handling and transformations.
  //!
  //! kumi::tuple is also compatible with standard tuple operations and structured bindings.
  //!
  //! @tparam Ts Sequence of types stored inside kumi::tuple.
  //================================================================================================
  template<typename... Ts> struct tuple
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
    //! @brief Extracts the Ith element from a kumi::tuple
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @param  i Compile-time index of the element to access
    //! @return A reference to the selected element of current tuple.
    //!
    //! ## Example:
    //! @include doc/subscript.cpp
    //==============================================================================================
    template<std::size_t I>
    requires( I < sizeof...(Ts) )
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] index_t<I> i) &noexcept
    {
      return _::get_leaf<I>(impl);
    }

    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(Ts) )
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) &&noexcept
    {
      return _::get_leaf<I>(static_cast<decltype(impl) &&>(impl));
    }

    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(Ts) )
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const &&noexcept
    {
      return _::get_leaf<I>(static_cast<decltype(impl) const &&>(impl));
    }

    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(Ts) )
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const &noexcept
    {
      return _::get_leaf<I>(impl);
    }

    //==============================================================================================
    //! @brief Extracts the Ith element from a kumi::tuple
    //!
    //! @note Does not participate in overload resolution if `T` is not present in the tuple or if
    //!       the tuple contains duplicate types
    //! @tparam T the type to access in the tuple
    //! @return A reference to the selected element of current tuple.
    //!
    //! ## Example:
    //! @include doc/typed_subscript.cpp
    //==============================================================================================
    template<typename T>
    requires( contains_type<T, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) &noexcept
    {
      return _::get_leaf<T>(impl);
    }

    /// @overload
    template<typename T>
    requires ( contains_type<T, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) &&noexcept
    {
      return _::get_leaf<T>(static_cast<decltype(impl) &&>(impl));
    }

    /// @overload
    template<typename T>
    requires ( contains_type<T, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const &&noexcept
    {
      return _::get_leaf<T>(static_cast<decltype(impl) const &&>(impl));
    }

    /// @overload
    template<typename T>
    requires (contains_type<T, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const &noexcept
    {
      return _::get_leaf<T>(impl);
    }

    //==============================================================================================
    //! @brief Extracts the element labeled Name from a kumi::tuple
    //!
    //! @note Does not participate in overload resolution if Name is not present in the tuple or if
    //!       the tuple contains duplicate names.
    //! @tparam Name Non type template parameter name of the element to access
    //! @return A reference to the selected element of current tuple.
    //!
    //! ## Example:
    //! @include doc/named_subscript.cpp
    //==============================================================================================
    template<str Name>
    requires( uniquely_named<Ts...> && contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) &noexcept
    {
      return _::get_leaf<Name>(impl);
    }

    /// @overload
    template<str Name>
    requires( uniquely_named<Ts...> && contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) &&noexcept
    {
      return _::get_leaf<Name>(static_cast<decltype(impl) &&>(impl));
    }

    /// @overload
    template<str Name>
    requires( uniquely_named<Ts...> && contains_field<Name, Ts...> )
    KUMI_ABI constexpr decltype(auto) operator[](field_name<Name>) const &&noexcept
    {
      return _::get_leaf<Name>(static_cast<decltype(impl) const &&>(impl));
    }

    /// @overload
    template<str Name>
    requires( uniquely_named<Ts...> && contains_field<Name, Ts...> )
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
    /// Returns the number of elements in a kumi::tuple
    [[nodiscard]] KUMI_ABI static constexpr  auto size() noexcept { return sizeof...(Ts); }

    /// Returns `true` if a kumi::tuple contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr  bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// Returns the names of the elements of a kumi::tuple
    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept
    -> tuple<decltype(name_of(as<Ts>{}))...>
    {
      return { name_of(as<Ts>{})... };
    };
    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @name Conversions
    //! @{
    //==============================================================================================

    //==============================================================================================
    //! @brief  Converts a tuple<Ts...> to a tuple<Us...>.
    //! @tparam Us Types composing the destination tuple
    //==============================================================================================
    template<typename... Us>
    requires(   _::piecewise_convertible<tuple, tuple<Us...>>
            &&  (sizeof...(Us) == sizeof...(Ts))
            &&  (!std::same_as<Ts, Us> && ...)
            )
    [[deprecated("Will be replaced by free functions")]][[nodiscard]] inline constexpr auto cast() const
    {
      return apply([](auto &&...elems) { return tuple<Us...> {static_cast<Us>(elems)...}; }, *this);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @brief Replaces the contents of the tuple with the contents of another tuple.
    //! @param other kumi::tuple to copy or move from
    //! @return `*this`
    //==============================================================================================
    template<typename... Us>
    requires(_::piecewise_convertible<tuple, tuple<Us...>>) KUMI_ABI constexpr tuple &
    operator=(tuple<Us...> const &other)
    {
      [&]<std::size_t... I>(std::index_sequence<I...>) { ((get<I>(*this) = get<I>(other)), ...); }
      (std::make_index_sequence<sizeof...(Ts)>());

      return *this;
    }

    /// @overload
    template<typename... Us>
    requires(_::piecewise_convertible<tuple, tuple<Us...>>) KUMI_ABI constexpr tuple &
    operator=(tuple<Us...> &&other)
    {
      [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        ((get<I>(*this) = get<I>(KUMI_FWD(other))), ...);
      }
      (std::make_index_sequence<sizeof...(Ts)>());

      return *this;
    }

    //==============================================================================================
    //! @name Comparison operators
    //! @{
    //==============================================================================================

    /// @ingroup tuple
    /// @related kumi::tuple
    /// @brief Compares a tuple with an other for equality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(tuple const &self, tuple<Us...> const &other) noexcept
    requires( equality_comparable<tuple,tuple<Us...>> )
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return ((get<I>(self) == get<I>(other)) && ...);
      }
      (std::make_index_sequence<sizeof...(Ts)>());
    }

    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(tuple const &self, tuple<Us...> const &other) noexcept
    requires( equality_comparable<tuple,tuple<Us...>> )
    {
      return !(self == other);
    }

    /// @ingroup tuple
    /// @related kumi::tuple
    /// @brief Compares tuples for lexicographical is less relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<(tuple const &lhs, tuple<Us...> const &rhs) noexcept
    requires(sizeof...(Ts) == sizeof...(Us) && _::piecewise_ordered<tuple, tuple<Us...>>)
    {
      // lexicographical order is defined as
      // (v0 < w0) || ... andnot(wi < vi, vi+1 < wi+1) ... || andnot(wn-1 < vn-1, vn < wn);
      auto res = get<0>(lhs) < get<0>(rhs);

      auto const order = [&]<typename Index>(Index i)
      {
        auto y_less_x_prev  = rhs[i] < lhs[i];
        auto x_less_y       = lhs[index_t<Index::value+1>{}] < rhs[index_t<Index::value+1>{}];
        return x_less_y && !y_less_x_prev;
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (res || ... || order(index_t<I>{}));
      }
      (std::make_index_sequence<sizeof...(Ts)-1>());
    }

    /// @ingroup tuple
    /// @related kumi::tuple
    /// @brief Compares tuples for lexicographical is less or equal relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<=(tuple const &lhs, tuple<Us...> const &rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return !(rhs < lhs);
    }

    /// @ingroup tuple
    /// @related kumi::tuple
    /// @brief Compares tuples for lexicographical is greater relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>(tuple const &lhs, tuple<Us...> const &rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return rhs < lhs;
    }

    /// @ingroup tuple
    /// @related kumi::tuple
    /// @brief Compares tuples for lexicographical is greater relation relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>=(tuple const &lhs, tuple<Us...> const &rhs) noexcept
    requires requires { lhs < rhs; }
    {
      return !(lhs < rhs);
    }

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @brief Invoke the Callable object f on each element of the current tuple.
    //!
    //! @param f	Callable object to be invoked
    //! @return The value returned by f.
    //!
    //==============================================================================================
    template<typename Function>
    [[deprecated("Use apply() instead")]]KUMI_ABI constexpr auto operator()(Function &&f) const&
    noexcept(noexcept(kumi::apply(KUMI_FWD(f), *this)))
    -> decltype(kumi::apply(KUMI_FWD(f), *this))
    { return kumi::apply(KUMI_FWD(f), *this); }

#if !defined(KUMI_DOXYGEN_INVOKED)
    template<typename Function>
    [[deprecated("Use apply() instead")]]KUMI_ABI constexpr auto operator()(Function &&f) &
    noexcept(noexcept(kumi::apply(KUMI_FWD(f), *this)))
    -> decltype(kumi::apply(KUMI_FWD(f), *this))
    {
      return kumi::apply(KUMI_FWD(f), *this);
    }

    template<typename Function>
    [[deprecated("Use apply() instead")]]KUMI_ABI constexpr auto operator()(Function &&f) const &&noexcept(
    noexcept(kumi::apply(KUMI_FWD(f), static_cast<tuple const &&>(*this))))
    -> decltype(kumi::apply(KUMI_FWD(f), static_cast<tuple const &&>(*this)))
    {
      return kumi::apply(KUMI_FWD(f), static_cast<tuple const &&>(*this));
    }

    template<typename Function>
    [[deprecated("Use apply() instead")]]KUMI_ABI constexpr auto operator()(Function &&f) &&noexcept(
    noexcept(kumi::apply(KUMI_FWD(f), static_cast<tuple &&>(*this))))
    -> decltype(kumi::apply(KUMI_FWD(f), static_cast<tuple &&>(*this)))
    {
      return kumi::apply(KUMI_FWD(f), static_cast<tuple &&>(*this));
    }
#endif

    //==============================================================================================
    /// @ingroup tuple
    //! @related kumi::tuple
    //! @brief Inserts a kumi::tuple in an output stream
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                                         tuple const &t) noexcept
    {
      os << "( ";
      kumi::for_each([&os](auto const &e) { os << e << " "; }, t);
      os << ")";

      return os;
    }
  };

  template<> struct tuple<>  
  {
    using is_product_type = void;
    static constexpr bool is_homogeneous = false;

    static constexpr auto size()  noexcept { return std::size_t{0}; }
    static constexpr auto empty() noexcept { return true;           }
    static constexpr auto names() noexcept { return tuple{};        }
    
    KUMI_ABI friend constexpr auto operator<=>(tuple<>, tuple<>) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, tuple<>)
    {
      return os << "()";
    }
  };

  //================================================================================================
  //! @name Tuple Deduction Guides
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup tuple
  //! @brief kumi::tuple deduction guide
  //! @tparam Ts  Type lists to build the tuple with.
  //================================================================================================
  template<typename... Ts> KUMI_CUDA tuple(Ts &&...) -> tuple<std::unwrap_ref_decay_t<Ts>...>;

  //================================================================================================
  //! @}
  //================================================================================================

  //================================================================================================
  //! @name Tuple construction
  //! @{
  //================================================================================================

  //================================================================================================
  //! @ingroup tuple
  //! @brief Creates a kumi::tuple of lvalue references to its arguments.
  //! @param ts	Zero or more lvalue arguments to construct the tuple from.
  //! @return A kumi::tuple object containing lvalue references.
  //! ## Example:
  //! @include doc/tie.cpp
  //================================================================================================
  template<typename... Ts>
  [[nodiscard]] KUMI_ABI
  constexpr auto tie(Ts &...ts) -> tuple<Ts &...>
  {
    return {ts...};
  }

  //================================================================================================
  //! @ingroup tuple
  //! @related kumi::tuple
  //! @brief Creates a kumi::tuple of forwarding references to its arguments.
  //!
  //! Constructs a tuple of references to the arguments in args suitable for forwarding as an
  //! argument to a function. The tuple has rvalue reference data members when rvalues are used as
  //! arguments, and otherwise has lvalue reference data members.
  //!
  //! @note If the arguments are temporaries, `forward_as_tuple` does not extend their lifetime;
  //!       they have to be used before the end of the full expression.
  //!
  //! @param ts	Zero or more lvalue arguments to construct the tuple from.
  //! @return A kumi::tuple constructed as `kumi::tuple<Ts&&...>(std::forward<Ts>(args)...)`
  //! ## Example:
  //! @include doc/forward_as_tuple.cpp
  //================================================================================================
  template<typename... Ts>
  [[nodiscard]] KUMI_ABI
  constexpr auto forward_as_tuple(Ts &&...ts) -> tuple<Ts &&...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup tuple
  //! @brief Creates a tuple object, deducing the target type from the types of arguments.
  //!
  //! @param ts	Zero or more lvalue arguments to construct the tuple from.
  //! @return A kumi::tuple constructed from the ts or their inner references when ts is an instance
  //!         of `std::reference_wrapper`.
  //! ## Example:
  //! @include doc/make_tuple.cpp
  //================================================================================================
  template<typename... Ts>
  [[nodiscard]] KUMI_ABI
  constexpr auto make_tuple(Ts &&...ts) -> tuple<std::unwrap_ref_decay_t<Ts>...>
  {
    return {KUMI_FWD(ts)...};
  }

  //================================================================================================
  //! @ingroup tuple
  //! @related kumi::tuple
  //! @brief Creates a kumi::tuple of references given a reference to a kumi::product_type.
  //!
  //! @param    t Tuple whose elements are to be referenced.  
  //! @return   A tuple equivalent to the result of `kumi::apply([]<typename... T>(T&&... e)
  //!           { return kumi::forward_as_tuple(std::forward<T>(e)...); }, t)`
  //!
  //! ## Example:
  //! @include doc/to_ref.cpp
  //================================================================================================
  template<product_type Type>
  [[nodiscard]] KUMI_ABI constexpr auto to_ref(Type && t)
  {
    return apply( [](auto&&... elems)
                  {
                    return kumi::forward_as_tuple(KUMI_FWD(elems)...);
                  }
                , KUMI_FWD(t)
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
  //! @ingroup tuple
  //! @brief Extracts the Ith element from a kumi::tuple
  //!
  //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
  //! @tparam   I Compile-time index of the element to access
  //! @param    t Tuple to index
  //! @return   A reference to the selected element of t.
  //! @related kumi::tuple
  //!
  //! ## Example:
  //! @include doc/get.cpp
  //================================================================================================
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &t) noexcept
  {
    return t[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &&arg) noexcept
  {
    return static_cast<tuple<Ts...> &&>(arg)[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &arg) noexcept
  {
    return arg[index<I>];
  }

  /// @overload
  template<std::size_t I, typename... Ts>
  requires( I < sizeof...(Ts) ) [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &&arg) noexcept
  {
    return static_cast<tuple<Ts...> const &&>(arg)[index<I>];
  }

  //================================================================================================
  //! @ingroup tuple
  //! @brief Extracts the field labeled Name from a kumi::tuple if it exists
  //!
  //! @note     Does not participate in overload resolution if the names are not unique
  //! @tparam   Name Non type template parameter name of the element to access
  //! @param    t Tuple to index
  //! @return   A reference to the selected element of t.
  //! @related kumi::tuple
  //!
  //! ## Example:
  //! @include doc/named_get.cpp
  //================================================================================================
  template<str Name, typename... Ts>
  requires ( uniquely_named<Ts...> && contains_field<Name, Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &t) noexcept
  {
    return t[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( uniquely_named<Ts...> && contains_field<Name, Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &&t) noexcept
  {
    return static_cast<tuple<Ts...> &&>(t)[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( uniquely_named<Ts...> && contains_field<Name, Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &t) noexcept
  {
    return t[field<Name>];
  }

  /// @overload
  template<str Name, typename... Ts>
  requires ( uniquely_named<Ts...> && contains_field<Name, Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &&t) noexcept
  {
    return static_cast<tuple<Ts...> const &&>(t)[field<Name>];
  }

  //================================================================================================
  //! @ingroup tuple
  //! @brief Extracts the field which type is T from a kumi::tuple if it exist
  //!
  //! @note     Does not participate in overload resolution if the types are not unique
  //! @tparam   T Type of the element to access
  //! @param    t Tuple to index
  //! @return   A reference to the selected element of t.
  //! @related kumi::tuple
  //!
  //! ## Example:
  //! @include doc/typed_get.cpp
  //================================================================================================
  template<typename T, typename... Ts>
  requires ( uniquely_typed<Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &t) noexcept
  {
    return t[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires ( uniquely_typed<Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> &&t) noexcept
  {
    return static_cast<tuple<Ts...> &&>(t)[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires ( uniquely_typed<Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &t) noexcept
  {
    return t[as<T>{}];
  }

  /// @overload
  template<typename T, typename... Ts>
  requires ( uniquely_typed<Ts...> )
  [[nodiscard]] KUMI_ABI constexpr decltype(auto)
  get(tuple<Ts...> const &&t) noexcept
  {
    return static_cast<tuple<Ts...> const &&>(t)[as<T>{}];
  }

  //================================================================================================
  //! @}
  //================================================================================================
}

#endif
