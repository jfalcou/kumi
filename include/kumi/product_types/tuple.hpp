//======================================================================================================================
//! @file
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kumi/product_types/shared.hpp>

namespace kumi
{
  //====================================================================================================================
  /**
    @class tuple
    @ingroup kumi_tuple_related
    @brief Fixed-size collection of heterogeneous values.

    kumi::tuple provides an aggregate based implementation of a tuple. It provides algorithms and
    functions designed to facilitate tuple's handling and transformations.

    kumi::tuple is also compatible with standard tuple operations and structured bindings.

    @tparam Ts Sequence of types stored inside kumi::tuple.

    @see @ref kumi_product_type

    ## Example:
    @include doc/tuple/api/introduction.cpp
  **/
  //====================================================================================================================
  template<typename... Ts> struct tuple
  {
    using binder_t = kumi::_::make_binder_t<std::index_sequence_for<Ts...>, Ts...>;

    static constexpr bool is_homogeneous = binder_t::is_homogeneous;

    binder_t impl;

    //==================================================================================================================
    /**
      @name Accessors
      @{
    **/
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief Extracts the Ith element from a kumi::tuple

      @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
      @param  i Compile-time index of the element to access
      @return A reference to the selected element of current tuple.

      ## Example:
      @include doc/tuple/api/subscript.cpp
    **/
    //==================================================================================================================
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::index_t<I> i) & noexcept
    requires(I < sizeof...(Ts))
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) && noexcept
    requires(I < sizeof...(Ts))
    {
      return static_cast<binder_t&&>(impl)(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const&& noexcept
    requires(I < sizeof...(Ts))
    {
      return static_cast<binder_t const&&>(impl)(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const& noexcept
    requires(I < sizeof...(Ts))
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }

    //==================================================================================================================
    /**
      @brief Extracts the element with type T from a kumi::tuple

      @note Does not participate in overload resolution if `T` is not present in the tuple or if
            the tuple contains duplicate types

      @param  type The type to access in the tuple
      @return A reference to the selected element of the current tuple.

      ## Example:
      @include doc/tuple/api/typed_subscript.cpp
    **/
    //==================================================================================================================
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::as<T> type) & noexcept
    requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
    {
      return impl(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) && noexcept
    requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
    {
      return static_cast<binder_t&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) const&& noexcept
    requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
    {
      return static_cast<binder_t const&&>(impl)(std::type_identity<T>{});
    }

    /// @overload
    template<typename T>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::as<T>) const& noexcept
    requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
    {
      return impl(std::type_identity<T>{});
    }

    //==================================================================================================================
    /**
      @brief Extracts the element of the field labeled L from a kumi::tuple

      @note Does not participate in overload resolution if the label is not present in the tuple

      @param  s label of the field to access
      @return A reference to the element of the selected field of current tuple.

      ## Example:
      @include doc/tuple/api/labeled_subscript.cpp
    **/
    //==================================================================================================================
    template<kumi::str L>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::label_t<L> s) & noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<L>, Ts...>)
    {
      return impl(std::integral_constant<kumi::str, L>{});
    }

    /// @overload
    template<kumi::str L>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<L>) && noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<L>, Ts...>)
    {
      return static_cast<binder_t&&>(impl)(std::integral_constant<kumi::str, L>{});
    }

    /// @overload
    template<kumi::str L>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<L>) const&& noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<L>, Ts...>)
    {
      return static_cast<binder_t const&&>(impl)(std::integral_constant<kumi::str, L>{});
    }

    /// @overload
    template<kumi::str L>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::label_t<L>) const& noexcept
    requires(kumi::concepts::contains_label<kumi::label_t<L>, Ts...>)
    {
      return impl(std::integral_constant<kumi::str, L>{});
    }

    //==================================================================================================================
    /**
      @brief Extracts the element whose identifier matches Id from a kumi::tuple

      @note Does not participate in overload resolution if no field whose identifier matches Id is present in
            the tuple or if the tuple contains duplicate identifiers.
      @tparam Id Identifier of the element to access
      @return A reference to the selected element of current tuple.

      ## Example:
      @include doc/tuple/api/named_subscript.cpp
    **/
    //==================================================================================================================
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) & noexcept
    requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return impl(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) && noexcept
    requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return static_cast<binder_t&&>(impl)(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) const&& noexcept
    requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<Id, Ts...>)
    {
      return static_cast<binder_t const&&>(impl)(kumi::_::tag_of_t<Id>{});
    }

    /// @overload
    template<kumi::concepts::identifier Id>
    KUMI_ABI constexpr decltype(auto) operator[](Id const&) const& noexcept
    requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<Id, Ts...>)
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

    /// @return Returns the number of elements in a kumi::tuple
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(Ts); }

    /// @return Returns `true` if a kumi::tuple contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr bool empty() noexcept { return sizeof...(Ts) == 0; }

    /// Returns the identifiers associated to the elements of a kumi::tuple
    [[nodiscard]] KUMI_ABI static constexpr auto identifiers() noexcept
    {
      return kumi::tuple{kumi::identifier_of<Ts>()...};
    }

    /// Returns the labels associated to the elements of a kumi::tuple
    [[nodiscard]] KUMI_ABI static constexpr auto labels() noexcept { return kumi::tuple{kumi::label_of<Ts>()...}; }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @name Conversions
      @{
    **/
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief  Enables static casting a tuple<Ts...> to a tuple<Us...>, the conversion is explicit
              if the casting requires internal explicit conversions.
      @tparam Us Types composing the destination tuple

      @note This function does not participate in overload resolution if the target tuple cannot be constructed
            from the values of the source, if their size does not match or if they are the same type.
            The conversion is explicit if the conversion of some member to the target needs to be explicit.

      @qualifier explicit

      This permits the conversion from a tuple<T>& to a tuple<T&> which makes it suitable
            for some zip-like cases such as building a structure of arrays iterator.

      ## Example :
      @include doc/tuple/api/cast.cpp
      @include doc/tuple/api/soa.cpp
    **/
    //==================================================================================================================
    // nvcc with a clang host rejects [[nodiscard]] on a conversion operator once optimizing.
    template<typename... Us>
    KUMI_ABI
#ifndef KUMI_DOXYGEN_INVOKED
      explicit(!kumi::_::piecewise_convertible<tuple<Ts const&...>, tuple<Us...>>)
#endif
        constexpr operator tuple<Us...>() const
    requires(sizeof...(Us) == sizeof...(Ts)) && (!std::same_as<tuple<Ts...>, tuple<Us...>>)
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::piecewise_constructible<tuple<Ts const & ...>, tuple<Us...>>)
#endif
    {
      return kumi::_::static_cast_<tuple<Us...>>(*this, std::make_index_sequence<sizeof...(Ts)>{});
    }

    /// @overload
    template<typename... Us>
    KUMI_ABI
#ifndef KUMI_DOXYGEN_INVOKED
      explicit(!kumi::_::piecewise_convertible<tuple<Ts&...>, tuple<Us...>>)
#endif
        constexpr operator tuple<Us...>()
    requires(sizeof...(Us) == sizeof...(Ts)) && (!std::same_as<tuple<Ts...>, tuple<Us...>>)
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::piecewise_constructible<tuple<Ts & ...>, tuple<Us...>>)
#endif
    {
      return kumi::_::static_cast_<tuple<Us...>>(*this, std::make_index_sequence<sizeof...(Ts)>{});
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief Replaces the contents of the tuple with the contents of another tuple.
      @param other kumi::tuple to copy or move from
      @return `*this`

      @note This function does not participate in overload resolution if the members from the source tuple cannot
            be converted to the members of the current tuple.
    **/
    //==================================================================================================================
    template<typename... Us>
    KUMI_ABI constexpr tuple& operator=(tuple<Us...> const& other)
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::piecewise_convertible<tuple, tuple<Us...>>)
#endif
    {
      kumi::_::assign(*this, other, std::make_index_sequence<sizeof...(Ts)>{});
      return *this;
    }

    /// @overload
    template<typename... Us>
    KUMI_ABI constexpr tuple& operator=(tuple<Us...>&& other)
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::piecewise_convertible<tuple, tuple<Us...>>)
#endif
    {
      kumi::_::assign(*this, other, std::make_index_sequence<sizeof...(Ts)>{});
      return *this;
    }

    //==================================================================================================================
    /**
      @name Comparison operators
      @{
    **/
    //==================================================================================================================

    /// @brief Compares a tuple with another for equality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(tuple const& self, tuple<Us...> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::piecewise_comparable<tuple, tuple<Us...>>)
#endif
    {
      return kumi::_::compare(self, other, std::make_index_sequence<sizeof...(Ts)>{});
    }

    /// @brief Compares a tuple with another for inequality
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(tuple const& self, tuple<Us...> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::piecewise_comparable<tuple, tuple<Us...>>)
#endif
    {
      return !(self == other);
    }

    /// @brief Compares tuples for the lexicographical less-than relation
    /// @note This function does not participate in overload resolution if the tuples are not lexicographically ordered
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires(sizeof...(Ts) == sizeof...(Us))
#ifndef KUMI_DOXYGEN_INVOKED
            && (kumi::_::piecewise_ordered<tuple, tuple<Us...>>)
#endif
    {
      // lexicographical order is defined as
      // (v0 < w0) || ... andnot(wi < vi, vi+1 < wi+1) ... || andnot(wn-1 < vn-1, vn < wn);
      return kumi::_::lexicographic_compare(lhs, rhs, std::make_index_sequence<sizeof...(Ts)>{});
    }

    /// @brief Compares tuples for the lexicographical less-than-or-equal relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<=(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return !(rhs < lhs);
    }

    /// @brief Compares tuples for the lexicographical greater-than relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return rhs < lhs;
    }

    /// @brief Compares tuples for the lexicographical greater-than-or-equal relation
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>=(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { lhs < rhs; }
    {
      return !(lhs < rhs);
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @related kumi::tuple
      @brief Inserts a kumi::tuple in an output stream
    **/
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, tuple const& t) noexcept
    {
      return kumi::_::print(os, t, '(', ',', ')', std::make_index_sequence<sizeof...(Ts) - 1>{});
    }
  };

  template<> struct tuple<>
  {
    static constexpr bool is_homogeneous = false;

    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return std::size_t{0}; }

    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return true; }

    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept { return kumi::tuple{}; }

    KUMI_ABI friend constexpr auto operator<=>(tuple<>, tuple<>) noexcept = default;

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
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, tuple<>) noexcept
    {
      return os << "()";
    }
  };

  //====================================================================================================================
  /**
    @name Tuple deduction guides
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related kumi::tuple
    @brief kumi::tuple deduction guide
    @tparam Ts  Type lists to build the tuple with.
  **/
  //====================================================================================================================
  template<typename... Ts> tuple(Ts&&...) -> tuple<std::unwrap_ref_decay_t<Ts>...>;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Tuple construction
    @{
  **/
  //====================================================================================================================

  struct tie_t
  {
    template<typename... Ts> [[nodiscard]] KUMI_ABI constexpr kumi::tuple<Ts&...> operator()(Ts&... ts) const
    {
      return {ts...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related

    @var tie
    @brief Creates a kumi::tuple of lvalue references to its arguments.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename... Ts>
      constexpr auto tie(Ts&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Zero or more lvalue arguments to construct the tuple from.

    @subgroupheader{Return value}

      - A kumi::tuple object containing lvalue references.

    @groupheader{Example}

    @godbolt{doc/tuple/api/tie.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr tie_t tie{};

  struct forward_as_tuple_t
  {
    template<typename... Ts> [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const -> kumi::tuple<Ts&&...>
    {
      return {KUMI_FWD(ts)...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related

    @var forward_as_tuple
    @brief Creates a kumi::tuple of forwarding references to its arguments.

    Constructs a tuple of references to the arguments in ts suitable for forwarding as an
    argument to a function. The tuple has rvalue reference data members when rvalues are used as
    arguments, and otherwise has lvalue reference data members.

    @note If the arguments are temporaries, `forward_as_tuple` does not extend their lifetime;
          they have to be used before the end of the full expression.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename... Ts>
      constexpr auto forward_as_tuple(Ts&&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Zero or more arguments to construct the tuple from.

    @subgroupheader{Return value}

      - A kumi::tuple constructed as `kumi::tuple<Ts&&...>(std::forward<Ts>(ts)...)`

    @groupheader{Example}

    @godbolt{doc/tuple/api/forward_as_tuple.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr forward_as_tuple_t forward_as_tuple{};

  struct make_tuple_t
  {
    template<typename... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const -> kumi::tuple<std::unwrap_ref_decay_t<Ts>...>
    {
      return {KUMI_FWD(ts)...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related

    @var make_tuple
    @brief Creates a tuple object, deducing the target type from the types of arguments.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename... Ts>
      constexpr auto make_tuple(Ts&&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Zero or more arguments to construct the tuple from.

    @subgroupheader{Return value}

      - A kumi::tuple constructed from the arguments or their inner references when an argument
            is an instance of `std::reference_wrapper`.

    @groupheader{Example}

    @godbolt{doc/tuple/api/make_tuple.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr make_tuple_t make_tuple{};

  namespace _
  {
    template<kumi::concepts::product_type T, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto to_ref_(kumi::_::adl_tag_t, T&& t, std::index_sequence<I...>)
      -> kumi::tuple<kumi::member_t<I, T>&&...>
    {
      return {get<I>(KUMI_FWD(t))...};
    }
  }

  struct to_ref_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return to_ref_(kumi::_::adl_tag, KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_transforms

    @var to_ref
    @brief Callable object creating a kumi::concepts::product_type of references given a reference to a
    kumi::concepts::product_type.

    If the input type matches the kumi::concepts::record_type protocol, return a kumi::record, returns a kumi::tuple
    otherwise.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr decltype(auto) to_ref(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type whose elements are to be referenced.

    @subgroupheader{Return value}

      - A kumi::concepts::product_type with each element being a reference to the corresponding element in the input.

    @groupheader{Examples}

    @godbolt{doc/tuple/api/to_ref.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr to_ref_t to_ref{};

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Tuple conversions
    @{
  **/
  //====================================================================================================================

  template<typename Type> struct from_tuple_t
  {
  private:
    template<typename T, std::size_t... I> KUMI_HIDDEN_ABI constexpr Type impl(T&& t, std::index_sequence<I...>) const
    {
      return {get<I>(KUMI_FWD(t))...};
    }

  public:
    template<typename... Ts>
    [[nodiscard]] KUMI_ABI constexpr Type operator()(tuple<Ts...> const& t) const
    requires(!kumi::concepts::product_type<Type> && kumi::_::implicit_constructible<Type, Ts...>)
    {
      return impl(t, std::make_index_sequence<sizeof...(Ts)>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related

    @var from_tuple
    @brief Converts a kumi::tuple to an instance of an arbitrary type

    Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Type, product_type T>
      constexpr auto from_tuple(T&& t);
    @endcode

    @subgroupheader{Parameters}

      - `Type` : Type to generate
      - `t`: kumi::tuple to convert.

    @subgroupheader{Return value}

      -  An instance of `Type` constructed from each element of `t` in order.

    @groupheader{Example}

    @godbolt{doc/tuple/api/from_tuple.cpp}

  **/
  //====================================================================================================================
  template<typename Type> KUMI_VARIABLE_ABI constexpr from_tuple_t<Type> from_tuple{};

  struct to_tuple_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{};
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::tuple{get<I>(KUMI_FWD(t))...};
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    /// @overload
    template<kumi::concepts::static_container S>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(S&& s) const
    requires(!kumi::concepts::product_type<S>)
    {
      constexpr std::size_t N = kumi::container_size_v<S>;
      if constexpr (N == 0) return kumi::tuple{};
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::tuple{KUMI_FWD(s)[I]...};
        }(std::make_index_sequence<N>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related

    @var to_tuple
    @brief Converts a kumi::concepts::product_type to an instance of kumi::tuple

    Constructs an instance of kumi::tuple from the elements of the kumi::concepts::product_type parameters

    @note An overload is provided for kumi::concepts::static_container.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto to_tuple(T&& t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: kumi::concepts::product_type to convert

    @subgroupheader{Return value}

      -  An instance of kumi::tuple constructed from each element of `t` in order.

    @groupheader{Example}

    @godbolt{doc/tuple/api/to_tuple.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr to_tuple_t to_tuple{};

  namespace _
  {
    template<typename T, typename IndexSequence, template<typename...> class Meta = std::type_identity> struct as_tuple;

    template<typename T, std::size_t... I> struct as_tuple<T, std::index_sequence<I...>>
    {
      using type = kumi::tuple<kumi::element_t<I, T>...>;
    };

    template<typename T, std::size_t... I, template<typename...> class Meta>
    struct as_tuple<T, std::index_sequence<I...>, Meta>
    {
      using type = tuple<typename Meta<kumi::element_t<I, T>>::type...>;
    };
  }

  //====================================================================================================================
  /**
    @ingroup kumi_tuple_related
    @brief Generate a kumi::tuple type from a type

    If `T` is a @ref kumi::concepts::product_type, returns the kumi::tuple type containing the same element
    as `T`. Otherwise, it returns `kumi::tuple<T>`.

    A template meta-function can be optionally passed to be applied to each of those types when
    types are computed.

    @tparam T     Type to transform
    @tparam Meta  Unary template meta-function to apply to each type.
                  Defaults to `std::type_identity`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, template<typename...> class Meta = std::type_identity>
      using as_tuple_t = typename as_tuple<T, Meta>::type;
    }
    @endcode

    ## Example:
    @include doc/tuple/api/as_tuple.cpp
  **/
  //====================================================================================================================
  template<typename T, template<typename...> class Meta = std::type_identity> struct as_tuple;

  template<typename T, template<typename...> class Meta>
  requires(kumi::concepts::product_type<T>)
  struct as_tuple<T, Meta> : kumi::_::as_tuple<T, std::make_index_sequence<kumi::size_v<T>>, Meta>
  {
  };

  template<typename T, template<typename...> class Meta>
  requires(!kumi::concepts::product_type<T>)
  struct as_tuple<T, Meta>
  {
    using type = kumi::tuple<typename Meta<T>::type>;
  };

  template<typename T, template<typename...> class Meta = std::type_identity>
  using as_tuple_t = typename kumi::as_tuple<T, Meta>::type;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  //! @name Tuple properties
  //! @{
  //====================================================================================================================

  struct members_of_t
  {
  private:
    template<typename T, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto impl(as<T>, std::index_sequence<I...>) const noexcept
    {
      if constexpr (sizeof...(I) == 0) return kumi::tuple{};
      else return kumi::tuple{kumi::identifier_of<kumi::element_t<I, T>>()...};
    }

  public:
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(as<T> type) const noexcept
    {
      return impl(type, std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_utility

    @var members_of
    @brief Extracts the names of the fields of a kumi::product_type.

    @note If some fields are unnamed, the associated name is kumi::unit.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto members_of(kumi::as<T> type);
    @endcode

    @subgroupheader{Parameters}
      - `type`: the type of the kumi::concepts::product_type from which to extract names.

    @subgroupheader{Return value}

      - A tuple of the names of a kumi::product_type.

    @groupheader{Example}

    @godbolt{doc/infra/members_of.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr members_of_t members_of{};

  struct values_of_t
  {
    template<typename T, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto impl(T&& t, std::index_sequence<I...>) const noexcept
    {
      if constexpr (sizeof...(I) == 0) return kumi::tuple{};
      else
        return kumi::tuple<kumi::result::field_value_of_t<kumi::member_t<I, T>>...>{
          kumi::field_value_of(get<I>(KUMI_FWD(t)))...};
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      return impl(KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_utility

    @var values_of
    @brief Extracts the values of the fields of a kumi::product_type.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/tuple.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto values_of(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `t`: the product_type from which to extract values.

    @subgroupheader{Return value}

      - A tuple of references to the values of a kumi::product_type.

    @groupheader{Example}

    @godbolt{doc/infra/values_of.cpp}

  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr values_of_t values_of{};

  namespace result
  {
    template<kumi::concepts::product_type T> using members_of_t = decltype(kumi::members_of(as<T>{}));

    template<kumi::concepts::product_type T> struct members_of
    {
      using type = kumi::result::members_of_t<T>;
    };

    template<kumi::concepts::product_type T> using values_of_t = decltype(kumi::values_of(std::declval<T>()));

    template<kumi::concepts::product_type T> struct values_of
    {
      using type = kumi::result::values_of_t<T>;
    };
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name Tuple Accessors
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related tuple
    @brief Extracts the Ith element from a kumi::tuple

    @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    @tparam   I Compile-time index of the element to access
    @param    t Tuple to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/tuple/api/get.cpp
  **/
  //====================================================================================================================
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  requires(I < sizeof...(Ts))
  {
    return t[kumi::index<I>];
  }

  /// @related tuple
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& arg) noexcept
  requires(I < sizeof...(Ts))
  {
    return static_cast<tuple<Ts...>&&>(arg)[kumi::index<I>];
  }

  /// @related tuple
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& arg) noexcept
  requires(I < sizeof...(Ts))
  {
    return arg[kumi::index<I>];
  }

  /// @related tuple
  /// @overload
  template<std::size_t I, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& arg) noexcept
  requires(I < sizeof...(Ts))
  {
    return static_cast<tuple<Ts...> const&&>(arg)[kumi::index<I>];
  }

  //====================================================================================================================
  /**
    @related tuple
    @brief Extracts the field labeled L from a kumi::tuple if it exists

    @note     Does not participate in overload resolution if the names are not unique
    @tparam   L Non type template parameter label of the element to access
    @param    t Tuple to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/tuple/api/labeled_get.cpp
  **/
  //====================================================================================================================
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::_::contains_label<L, Ts...>())
  {
    return t[kumi::label<L>];
  }

  /// @related tuple
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::_::contains_label<L, Ts...>())
  {
    return static_cast<tuple<Ts...>&&>(t)[kumi::label<L>];
  }

  /// @related tuple
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::_::contains_label<L, Ts...>())
  {
    return t[kumi::label<L>];
  }

  /// @related tuple
  /// @overload
  template<kumi::str L, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::_::contains_label<L, Ts...>())
  {
    return static_cast<tuple<Ts...> const&&>(t)[kumi::label<L>];
  }

  //====================================================================================================================
  /**
    @related tuple
    @brief Extracts the field identified by Id from a kumi::tuple if it exists

    @note     Does not participate in overload resolution if the names are not unique
    @tparam   Id Non type template parameter identifier of the element to access
    @param    t Tuple to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/tuple/api/named_get.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return t[Id];
  }

  /// @related tuple
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return static_cast<tuple<Ts...>&&>(t)[Id];
  }

  /// @related tuple
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return t[Id];
  }

  /// @related tuple
  /// @overload
  template<kumi::concepts::identifier auto Id, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  requires(kumi::concepts::uniquely_named<Ts...> && kumi::concepts::contains_identifier<decltype(Id), Ts...>)
  {
    return static_cast<tuple<Ts...> const&&>(t)[Id];
  }

  //====================================================================================================================
  /**
    @related tuple
    @brief Extracts the field whose type is T from a kumi::tuple if it exists

    @note     Does not participate in overload resolution if the types are not unique
    @tparam   T Type of the element to access
    @param    t Tuple to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard inline constexpr noexcept

    ## Example:
    @include doc/tuple/api/typed_get.cpp
  **/
  //====================================================================================================================
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
  {
    return t[kumi::as<T>{}];
  }

  /// @related tuple
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
  {
    return static_cast<tuple<Ts...>&&>(t)[kumi::as<T>{}];
  }

  /// @related tuple
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
  {
    return t[kumi::as<T>{}];
  }

  /// @related tuple
  /// @overload
  template<typename T, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  requires(kumi::concepts::uniquely_typed<Ts...> && kumi::concepts::contains_type<T, Ts...>)
  {
    return static_cast<tuple<Ts...> const&&>(t)[kumi::as<T>{}];
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

#ifndef KUMI_DOXYGEN_INVOKED
  /// Improves diagnostic for out of bounds index
  template<std::size_t I, typename T>
  requires(kumi::is_kumi_tuple_v<std::remove_cvref_t<T>> && (I >= kumi::size_v<T>))
  constexpr auto get(T&& r) = delete;

  /// Improves diagnostic for non present label
  template<str S, typename T>
  requires(kumi::is_kumi_tuple_v<std::remove_cvref_t<T>> && !kumi::_::contains_identifier<S, T>())
  constexpr auto get(T&& t) = delete;

  /// Improves diagnostic for non present identifier
  template<kumi::concepts::identifier auto S, typename T>
  requires(kumi::is_kumi_tuple_v<std::remove_cvref_t<T>> && !kumi::concepts::contains_identifier<decltype(S), T>)
  constexpr auto get(T&& t) = delete;

  /// Improves diagnostic for non present type
  template<typename U, typename T>
  requires(kumi::is_kumi_tuple_v<std::remove_cvref_t<T>> && !kumi::concepts::contains_type<U, T>)
  constexpr auto get(T&& t) = delete;
#endif

  // Builder protocol
  template<kumi::concepts::product_type T> struct builder<T>
  {
    using type = T;

    template<typename... Us> using to = kumi::tuple<Us...>;

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto make(Args&&... args)
    {
      return kumi::make_tuple(KUMI_FWD(args)...);
    }

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto build(Args&&... args)
    {
      return kumi::tuple{KUMI_FWD(args)...};
    }
  };

  // As we are lacking a proper mechanism to find the least restrictive subtype, we fallback to a specializable trait
  template<kumi::concepts::product_type... Ts> struct common_product_type<Ts...>
  {
    using type = kumi::tuple<>;
  };
}
