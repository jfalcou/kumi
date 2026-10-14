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
    @class array
    @ingroup kumi_array_related
    @brief Fixed-size collection of homogeneous values.

    kumi::array provides an aggregate based implementation of an array. It provides algorithms and
    functions designed to facilitate array's handling and transformations.

    kumi::array is also compatible with standard tuple operations and structured bindings.

    @tparam T Type stored inside kumi::array.
    @tparam N Size of the sequence

    @see @ref kumi_array_type

    ## Example:
    @include doc/array/api/introduction.cpp
  **/
  //====================================================================================================================
  template<typename T = void, std::size_t N = 0> struct array
  {
    using binder_t = kumi::_::make_binder_t<std::make_index_sequence<N>, T>;
    using value_type = std::remove_cvref_t<T>;

    binder_t impl;

    //==================================================================================================================
    /**
      @brief Extracts the Ith element from a kumi::array

      @note Does not participate in overload resolution if `I` is not in [0, N).
      @param  i Compile-time index of the element to access
      @return A reference to the selected element of current array.

      ## Example:
      @include doc/array/api/subscript.cpp
    **/
    //==================================================================================================================
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] kumi::index_t<I> i) & noexcept
    requires(I < N)
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) && noexcept
    requires(I < N)
    {
      return static_cast<binder_t&&>(impl)(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const&& noexcept
    requires(I < N)
    {
      return static_cast<binder_t const&&>(impl)(std::integral_constant<std::size_t, I>{});
    }

    /// @overload
    template<std::size_t I>
    KUMI_ABI constexpr decltype(auto) operator[](kumi::index_t<I>) const& noexcept
    requires(I < N)
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }

    //==================================================================================================================
    /**
      @name Properties
      @{
    **/
    //==================================================================================================================
    static constexpr bool is_homogeneous = true;

    static constexpr auto size() noexcept { return N; }

    static constexpr auto empty() noexcept { return false; }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief  Enables static casting a array<T,N> to an array<U,N>, the conversions is explicit
              if the casting requires internal explicit conversions.
      @tparam U Type of the elements of the destination array

      @note This function does not participate in overload resolution if the target array cannot be constructed
            from the values of the source, if their size does not match or if they are the same type.
            The conversion is explicit if the conversion of some member to the target needs to be explicit.

      @qualifier explicit

      This permits the conversion from an array<T>& to an array<T&> which makes it suitable
            for some zip-like cases such as building a structure of arrays iterator.

      ## Example :
      @include doc/array/api/cast.cpp
      @include doc/array/api/soa.cpp
    **/
    //==================================================================================================================
    template<typename U, std::size_t M>
    [[nodiscard]] KUMI_ABI
#ifndef KUMI_DOXYGEN_INVOKED
      explicit(!std::convertible_to<T const&, U>)
#endif
        constexpr operator array<U, M>() const
    requires(N == M) && (!std::same_as<array<T, N>, array<U, M>>) && (std::is_constructible_v<U, T const&>)
    {
      return kumi::_::static_cast_<array<U, M>>(*this, std::make_index_sequence<N>{});
    }

    /// @overload
    template<typename U, std::size_t M>
    [[nodiscard]] KUMI_ABI
#ifndef KUMI_DOXYGEN_INVOKED
      explicit(!std::convertible_to<T&, U>)
#endif
        constexpr operator array<U, M>()
    requires(N == M) && (!std::same_as<array<T, N>, array<U, M>>) && (std::is_constructible_v<U, T&>)
    {
      return kumi::_::static_cast_<array<U, M>>(*this, std::make_index_sequence<N>{});
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @brief Replaces the contents of the array with the contents of another array.
      @param other kumi::array to copy or move from
      @return `*this`

      @note This function does not participate in overload resolution if the members from the source array cannot
            be converted to the members of the current array.
    **/
    //==================================================================================================================
    template<typename U, std::size_t M>
    KUMI_ABI constexpr array& operator=(array<U, M> const& other)
#ifndef KUMI_DOXYGEN_INVOKED
    requires(std::convertible_to<T, U> && N == M)
#endif
    {
      kumi::_::assign(*this, other, std::make_index_sequence<N>{});
      return *this;
    }

    /// @overload
    template<typename U, std::size_t M>
    KUMI_ABI constexpr array& operator=(array<U, M>&& other)
#ifndef KUMI_DOXYGEN_INVOKED
    requires(std::convertible_to<T, U> && N == M)
#endif
    {
      kumi::_::assign(*this, other, std::make_index_sequence<N>{});
      return *this;
    }

    //==================================================================================================================
    /**
      @name Comparison operators
      @{
    **/
    //==================================================================================================================

    /// @brief Compares a array with an other for equality
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator==(array const& self, array<U, M> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::comparable<T, U> && N == M)
#endif
    {
      return kumi::_::compare(self, other, std::make_index_sequence<N>{});
    }

    /// @brief Compares a array with an other for inequality
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator!=(array const& self, array<U, M> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::comparable<T, U> && N == M)
#endif
    {
      return !(self == other);
    }

    /// @brief Compares arrays for lexicographical is less relation
    /// @note This function does not participate in overload resolution if the array are not lexicographically ordered
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator<(array const& lhs, array<U, M> const& rhs) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
    requires(kumi::_::comparable<T, U> && N == M)
#endif
    {
      return kumi::_::lexicographic_compare(lhs, rhs, std::make_index_sequence<N>{});
    }

    /// @brief Compares arrays for lexicographical is less or equal relation
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator<=(array const& lhs, array<U, M> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return !(rhs < lhs);
    }

    /// @brief Compares arrays for lexicographical is greater relation
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator>(array const& lhs, array<U, M> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return rhs < lhs;
    }

    /// @brief Compares arrays for lexicographical is greater or equal relation
    template<typename U, std::size_t M>
    KUMI_ABI friend constexpr auto operator>=(array const& lhs, array<U, M> const& rhs) noexcept
    requires requires { lhs < rhs; }
    {
      return !(lhs < rhs);
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @related kumi::array
      @brief Inserts a kumi::array in an output stream
    **/
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, array const& a) noexcept
    {
      return kumi::_::print(os, a, '[', ',', ']', std::make_index_sequence<N - 1>{});
    }
  };

  //====================================================================================================================
  // Empty power type: array<T, 0> — a power type of a known element type with arity zero (τ⁰ of T).
  // The canonical empty power type array<> == array<void, 0> is specialised further below and is the
  // unit/void power type.
  //====================================================================================================================
  template<typename T> struct array<T, 0>
  {
    using value_type = std::remove_cvref_t<T>;

    static constexpr bool is_homogeneous = true;

    static constexpr auto size() noexcept { return 0; }

    static constexpr auto empty() noexcept { return true; }

    friend constexpr auto operator<=>(array<T, 0>, array<T, 0>) noexcept = default;

    template<typename U>
    [[nodiscard]] KUMI_ABI constexpr operator U() const noexcept
    requires(kumi::concepts::unit_type<U>)
    {
      return {};
    }

    template<typename U>
    [[nodiscard]] KUMI_ABI constexpr operator U() noexcept
    requires(kumi::concepts::unit_type<U>)
    {
      return {};
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, array<T, 0>) noexcept
    {
      return os << "[]";
    }
  };

  //====================================================================================================================
  // The canonical empty power type: array<> == array<void, 0>.
  // In power-type algebra τ⁰ collapses to the unit type, isomorphic to void: an array you create with
  // `kumi::array{}` "ends up being void" — it is the unit power type, interconvertible with
  // kumi::unit / std::nullptr_t / tuple<>. This full specialization takes precedence over array<T,0>.
  //====================================================================================================================
  template<> struct array<void, 0>
  {
    using value_type = void;

    static constexpr bool is_homogeneous = true;

    static constexpr auto size() noexcept { return 0; }

    static constexpr auto empty() noexcept { return true; }

    friend constexpr auto operator<=>(array<void, 0>, array<void, 0>) noexcept = default;

    template<typename U>
    [[nodiscard]] KUMI_ABI constexpr operator U() const noexcept
    requires(kumi::concepts::unit_type<U>)
    {
      return {};
    }

    template<typename U>
    [[nodiscard]] KUMI_ABI constexpr operator U() noexcept
    requires(kumi::concepts::unit_type<U>)
    {
      return {};
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, array<void, 0>) noexcept
    {
      return os << "[]";
    }
  };

  //====================================================================================================================
  /**
    @name Array deduction guides
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related kumi::array
    @brief kumi::array deduction guide
    @tparam Ts  Type lists to build the array with.
  **/
  //====================================================================================================================
  template<typename T, typename... Ts>
  requires(kumi::_::all_the_same<T, Ts...>)
  array(T&&, Ts&&...) -> array<T, sizeof...(Ts) + 1>;

  /// @brief Deduction guide for the empty power type: `kumi::array{}` -> `kumi::array<>` (== array<void, 0>)
  array() -> array<>;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name array construction
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup kumi_array_related
    @brief Creates a kumi::array of forwarding references to its arguments.

    Constructs a array of references to the arguments in args suitable for forwarding as an
    argument to a function. The array has rvalue reference data members when rvalues are used as
    arguments, and otherwise has lvalue reference data members.

    @note If the arguments are temporaries, `forward_as_array` does not extend their lifetime;
          they have to be used before the end of the full expression.

    @param ts	Zero or more lvalue arguments to construct the array from.
    @return A kumi::array constructed as `kumi::array<Ts&&...>(std::forward<Ts>(args)...)`
    ## Example:
    @include doc/array/api/forward_as_array.cpp
  **/
  //====================================================================================================================
  template<typename T, typename... Ts>
  requires(kumi::_::all_the_same<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto forward_as_array(T&& t, Ts&&... ts)
    -> kumi::array<decltype(KUMI_FWD(t)), sizeof...(Ts) + 1>
  {
    return {KUMI_FWD(t), KUMI_FWD(ts)...};
  }

  //====================================================================================================================
  /**
    @ingroup array_related
    @brief Creates a array object, deducing the target type from the types of arguments.

    @param ts	Zero or more lvalue arguments to construct the array from.
    @return A kumi::array constructed from the ts or their inner references when ts is an instance
            of `std::reference_wrapper`.
    ## Example:
    @include doc/array/api/make_array.cpp
  **/
  //====================================================================================================================
  template<typename T, typename... Ts>
  requires(kumi::_::all_the_same<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto make_array(T&& t, Ts&&... ts)
    -> kumi::array<std::unwrap_ref_decay_t<T>, sizeof...(Ts) + 1>
  {
    return {KUMI_FWD(t), KUMI_FWD(ts)...};
  }

  namespace _
  {
    template<kumi::concepts::power_type T, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto to_ref_(kumi::_::adl_tag_t, T&& t, std::index_sequence<I...>)
      -> kumi::array<kumi::element_t<0, T>, sizeof...(I)>
    {
      return {get<I>(KUMI_FWD(t))...};
    }
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name array conversions
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup array_related
    @brief Converts a kumi::array to an instance of an arbitrary type

    Constructs an instance of `Type` by passing elements of `a` to the appropriate constructor.

    @tparam Type Type to generate
    @param  a    kumi::array to convert
    @return An instance of `Type` constructed from each element of `a` in order.

    ## Example
    @include doc/array/api/from_array.cpp
  **/
  //====================================================================================================================
  template<typename Type, typename T, std::size_t N>
  [[nodiscard]] KUMI_ABI constexpr auto from_array(kumi::array<T, N> const& a)
  requires(!kumi::concepts::product_type<Type>) //&& kumi::_::implicit_constructible<Type, Ts...>)
  {
    return
      [&]<std::size_t... I>(std::index_sequence<I...>) { return Type{get<I>(a)...}; }(std::make_index_sequence<N>{});
  }

  //====================================================================================================================
  /**
    @ingroup array_related
    @brief Converts a kumi::product_type to an instance kumi::array

    Constructs an instance kumi::array from the elements of the kumi::product_type parameters

    @param  t    kumi::product_type to convert
    @return An instance of kumi::array constructed from each elements of `t` in order.

    @note An overload is provided for kumi::static_container.

    ## Example
    @include doc/array/api/to_array.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::homogeneous_product_type T>
  requires(!kumi::concepts::empty_product_type<T>)
  [[nodiscard]] KUMI_ABI constexpr auto to_array(T&& t)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::array{get<I>(KUMI_FWD(t))...};
    }(std::make_index_sequence<kumi::size_v<T>>{});
  }

  /// @overload
  template<kumi::concepts::empty_product_type T> [[nodiscard]] KUMI_ABI constexpr auto to_array(T&&)
  {
    return kumi::array<>{};
  }

  /// @overload
  template<kumi::concepts::static_container S>
  [[nodiscard]] KUMI_ABI constexpr auto to_array(S&& s)
  requires(!kumi::concepts::product_type<S>)
  {
    constexpr std::size_t N = kumi::container_size_v<S>;
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::array{KUMI_FWD(s)[I]...};
    }(std::make_index_sequence<N>{});
  }

  //====================================================================================================================
  /**
    @ingroup array_related
    @brief Generate a kumi::array type from a type

    If `T` is a @ref kumi::concepts::product_type, returns the kumi::array type containing the same element
    as `T`. Otherwise, it returns `kumi::array<T>`.

    A template meta-function can be optionally passed to be applied to each of those types when
    types are computed.

    @tparam T     Type to transform
    @tparam Meta  Unary template meta-function to apply to each types.
                  Defaults to `std::type_identity`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, template<typename...> class Meta = std::type_identity>
      using as_array_t = typename as_array<T, Meta>::type;
    }
    @endcode

    ## Example:
    @include doc/array/api/as_array.cpp
  **/
  //====================================================================================================================
  template<typename T, template<typename...> class Meta = std::type_identity> struct as_array;

  template<typename T, template<typename...> class Meta>
  requires(kumi::concepts::power_type<T>)
  struct as_array<T, Meta>
  {
    using type = kumi::array<typename Meta<kumi::element_t<0, T>>::type, kumi::size_v<T>>;
  };

  template<typename T, template<typename...> class Meta>
  requires(!kumi::concepts::power_type<T>)
  struct as_array<T, Meta>
  {
    using type = kumi::array<typename Meta<T>::type, 0>;
  };

  template<typename T, template<typename...> class Meta = std::type_identity>
  using as_array_t = typename kumi::as_array<T, Meta>::type;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name array Accessors
    @{
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related array
    @brief Extracts the Ith element from a kumi::array

    @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    @tparam   I Compile-time index of the element to access
    @param    t array to index
    @return   A reference to the selected element of t.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    ## Example:
    @include doc/array/api/get.cpp
  **/
  //====================================================================================================================
  template<std::size_t I, typename T, std::size_t N>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(array<T, N>& t) noexcept
  requires(I < N)
  {
    return t[kumi::index<I>];
  }

  /// @related array
  /// @overload
  template<std::size_t I, typename T, std::size_t N>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(array<T, N>&& arg) noexcept
  requires(I < N)
  {
    return static_cast<array<T, N>&&>(arg)[kumi::index<I>];
  }

  /// @related array
  /// @overload
  template<std::size_t I, typename T, std::size_t N>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(array<T, N> const& arg) noexcept
  requires(I < N)
  {
    return arg[kumi::index<I>];
  }

  /// @related array
  /// @overload
  template<std::size_t I, typename T, std::size_t N>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(array<T, N> const&& arg) noexcept
  requires(I < N)
  {
    return static_cast<array<T, N> const&&>(arg)[kumi::index<I>];
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

#ifndef KUMI_DOXYGEN_INVOKED
  /// Improves diagnostic for out of bounds index
  template<std::size_t I, typename T>
  requires(kumi::is_kumi_array_v<std::remove_cvref_t<T>> && (I >= kumi::size_v<T>))
  constexpr auto get(T&& r) = delete;
#endif

  // Builder protocol
  template<kumi::concepts::power_type T> struct builder<T>
  {
    using type = T;

    // A kumi::array is homogeneous, so rebuild it with the element type and the element count.
    template<typename... Us>
    requires(kumi::_::all_the_same<Us...>)
    using to = kumi::array<kumi::element_t<0, kumi::tuple<Us...>>, sizeof...(Us)>;

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto make(Args&&... args)
    {
      return kumi::make_array(KUMI_FWD(args)...);
    }

    template<typename... Args> [[nodiscard]] KUMI_ABI static constexpr auto build(Args&&... args)
    {
      return kumi::array{KUMI_FWD(args)...};
    }
  };

  // As we are lacking a proper mechanism to find the least restrictive subtype, we fallback to a specializable trait
  // The power_type constraint subsumes the plain product_type one (power_type <: product_type), so this
  // specialization wins for arrays while heterogeneous tuples / records still fall back to the tuple<> one.
  template<kumi::concepts::power_type... Ts> struct common_product_type<Ts...>
  {
    using type = kumi::array<>;
  };
}
