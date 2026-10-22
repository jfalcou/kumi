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

    @note kumi::array is different from std::array in several aspects. It can hold reference type and it's possible
    to create an empty kumi::array<> that deduces to kumi::array<void,0>. This is the proper type representation
    of the identity of power types.

    kumi::array provides an aggregate based implementation of an array. It provides algorithms and
    functions designed to facilitate array's handling and transformations.

    kumi::array is also compatible with standard tuple operations and structured bindings.

    @tparam T Type stored inside kumi::array.
    @tparam N Size of the sequence

    ## Example:
    @include doc/array/api/introduction.cpp
  **/
  //====================================================================================================================
  template<typename T, std::size_t N> struct array
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
      @name Conversions
      @{
    **/
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
  };

  //====================================================================================================================
  /**
    @name Comparison operators
    @related kumi::array
    @{
  **/
  //====================================================================================================================

  /// @brief Compares an array with another for equality
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator==(array<T, N> const& self, array<U, M> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
  requires(N == 0 || M == 0) || (N == M && kumi::_::comparable<T, U>)
#endif
  {
    if constexpr (N == 0 || M == 0) return N == M;
    else return kumi::_::compare(self, other, std::make_index_sequence<N>{});
  }

  /// @brief Compares an array with another for inequality
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator!=(array<T, N> const& self, array<U, M> const& other) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
  requires(N == 0 || M == 0) || (N == M && kumi::_::comparable<T, U>)
#endif
  {
    return !(self == other);
  }

  /// @brief Compares arrays for the lexicographical less-than relation
  /// @note This function does not participate in overload resolution if the arrays are not lexicographically ordered
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator<(array<T, N> const& lhs, array<U, M> const& rhs) noexcept
#ifndef KUMI_DOXYGEN_INVOKED
  requires(N == 0 || M == 0) || (N == M && kumi::_::comparable<T, U>)
#endif
  {
    if constexpr (N == 0 || M == 0) return N < M;
    else return kumi::_::lexicographic_compare(lhs, rhs, std::make_index_sequence<N>{});
  }

  /// @brief Compares arrays for the lexicographical less-than-or-equal relation
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator<=(array<T, N> const& lhs, array<U, M> const& rhs) noexcept
  requires requires { rhs < lhs; }
  {
    return !(rhs < lhs);
  }

  /// @brief Compares arrays for the lexicographical greater-than relation
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator>(array<T, N> const& lhs, array<U, M> const& rhs) noexcept
  requires requires { rhs < lhs; }
  {
    return rhs < lhs;
  }

  /// @brief Compares arrays for the lexicographical greater-than-or-equal relation
  template<typename T, std::size_t N, typename U, std::size_t M>
  KUMI_ABI constexpr auto operator>=(array<T, N> const& lhs, array<U, M> const& rhs) noexcept
  requires requires { lhs < rhs; }
  {
    return !(lhs < rhs);
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @related kumi::array
    @brief Inserts a kumi::array in an output stream
  **/
  //====================================================================================================================
  template<typename CharT, typename Traits, typename T, std::size_t N>
  requires(N > 0)
  std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, array<T, N> const& a) noexcept
  {
    return kumi::_::print(os, a, '[', ',', ']', std::make_index_sequence<N - 1>{});
  }

  //====================================================================================================================
  // Empty power type: array<T, 0>
  // The canonical empty power type array<> is array<void, 0> which is isomorph to the unit type.
  //====================================================================================================================
  template<typename T> struct array<T, 0>
  {
    using value_type = std::remove_cvref_t<T>;

    static constexpr bool is_homogeneous = true;

    static constexpr auto size() noexcept { return 0; }

    static constexpr auto empty() noexcept { return true; }

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
  array(T&&, Ts&&...) -> array<std::unwrap_ref_decay_t<T>, sizeof...(Ts) + 1>;

  /// @brief Deduction guide for the empty power type: `kumi::array{}` -> `kumi::array<>` (== array<void, 0>)
  array() -> array<void, 0>;

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  /**
    @name array construction
    @{
  **/
  //====================================================================================================================

  struct forward_as_array_t
  {
    [[nodiscard]] KUMI_ABI constexpr auto operator()() const -> kumi::array<> { return {}; }

    template<typename T, typename... Ts>
    requires(kumi::_::all_the_same<T, Ts...>)
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Ts&&... ts) const -> kumi::array<T&&, sizeof...(Ts) + 1>
    {
      return {KUMI_FWD(t), KUMI_FWD(ts)...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_array_related

    @var forward_as_array
    @brief Creates a kumi::array of forwarding references to its arguments.

    Constructs an array of references to the arguments in ts suitable for forwarding as an
    argument to a function. The tuple has rvalue reference data members when rvalues are used as
    arguments, and otherwise has lvalue reference data members.

    @note If the arguments are temporaries, `forward_as_array` does not extend their lifetime;
          they have to be used before the end of the full expression.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/array.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename... Ts>
      constexpr auto forward_as_array(Ts&&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Zero or more arguments to construct the array from.

    @subgroupheader{Return value}

      - A kumi::array constructed as `kumi::array<Implementation defined, sizeof...(Ts)>(std::forward<Ts>(ts)...)`

    @groupheader{Example}

    @godbolt{doc/array/api/forward_as_array.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr forward_as_array_t forward_as_array{};

  struct make_array_t
  {
    [[nodiscard]] KUMI_ABI constexpr auto operator()() const -> kumi::array<> { return {}; }

    template<typename T, typename... Ts>
    requires(kumi::_::all_the_same<T, Ts...>)
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Ts&&... ts) const
      -> kumi::array<std::unwrap_ref_decay_t<T>, sizeof...(Ts) + 1>
    {
      return {KUMI_FWD(t), KUMI_FWD(ts)...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_array_related

    @var make_array
    @brief Creates a array object, deducing the target type from the types of arguments.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/array.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename... Ts>
      constexpr auto make_array(Ts&&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Zero or more arguments to construct the array from.

    @subgroupheader{Return value}

      - A kumi::array constructed from the arguments or their inner references when an argument
            is an instance of `std::reference_wrapper`.

    @groupheader{Example}

    @godbolt{doc/array/api/make_array.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr make_array_t make_array{};

  namespace _
  {
    template<kumi::concepts::power_type T, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto to_ref_(kumi::_::adl_tag_t, T&& t, std::index_sequence<I...>)
      -> kumi::array<kumi::member_t<0, T>, sizeof...(I)>
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

  template<typename Type> struct from_array_t
  {
    template<typename T, std::size_t N>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(kumi::array<T, N> const& a) const
    requires(!kumi::concepts::product_type<Type>) //&& kumi::_::implicit_constructible<Type, Ts...>)
    {
      return
        [&]<std::size_t... I>(std::index_sequence<I...>) { return Type{get<I>(a)...}; }(std::make_index_sequence<N>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_array_related

    @var from_array
    @brief Converts a kumi::array to an instance of an arbitrary type

    Constructs an instance of `Type` by passing elements of `t` to the appropriate constructor.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/array.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Type, product_type T>
      constexpr auto from_array(T&& t);
    @endcode

    @subgroupheader{Parameters}

      - `Type` : Type to generate
      - `t`: kumi::array to convert.

    @subgroupheader{Return value}

      -  An instance of `Type` constructed from each element of `t` in order.

    @groupheader{Example}

    @godbolt{doc/array/api/from_array.cpp}
   **/
  //====================================================================================================================
  template<typename Type> KUMI_VARIABLE_ABI constexpr from_array_t<Type> from_array{};

  struct to_array_t
  {
    template<kumi::concepts::homogeneous_product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::array{};
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::array{get<I>(KUMI_FWD(t))...};
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    /// @overload
    template<kumi::concepts::static_container S>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(S&& s) const
    requires(!kumi::concepts::product_type<S>)
    {
      constexpr std::size_t N = kumi::container_size_v<S>;
      if constexpr (N == 0) return kumi::array{};
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::array{KUMI_FWD(s)[I]...};
        }(std::make_index_sequence<N>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_array_related

    @var to_array
    @brief Converts a kumi::concepts::product_type to an instance of kumi::array

    Constructs an instance of kumi::array from the elements of the kumi::concepts::product_type parameters

    @note An overload is provided for kumi::concepts::static_container.

    @qualifier inline
    @qualifier constexpr
    @qualifier nodiscard

    @groupheader{Header file}
    @code
    #include <kumi/product_types/array.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto to_array(T&& t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: kumi::concepts::product_type to convert

    @subgroupheader{Return value}

      -  An instance of kumi::array constructed from each element of `t` in order.

    @groupheader{Example}

    @godbolt{doc/array/api/to_array.cpp}
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr to_array_t to_array{};

  //====================================================================================================================
  /**
    @ingroup kumi_array_related
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

  template<kumi::concepts::power_type T> struct builder<T>
  {
    using type = T;

    // A kumi::array is homogeneous, so rebuild it with the element type and the element count.
    template<typename... Us>
    requires(sizeof...(Us) == 0 || kumi::_::all_the_same<Us...>)
    using to = kumi::array<kumi::_::first_t<Us...>, sizeof...(Us)>;

    [[nodiscard]] KUMI_ABI static constexpr auto make() { return kumi::make_array(); }

    [[nodiscard]] KUMI_ABI static constexpr auto build() { return kumi::array{}; }

    template<typename Arg, typename... Args>
    requires(kumi::_::all_the_same<Arg, Args...>)
    [[nodiscard]] KUMI_ABI static constexpr auto make(Arg&& arg, Args&&... args)
    {
      return kumi::make_array(KUMI_FWD(arg), KUMI_FWD(args)...);
    }

    template<typename Arg, typename... Args>
    requires(kumi::_::all_the_same<Arg, Args...>)
    [[nodiscard]] KUMI_ABI static constexpr auto build(Arg&& arg, Args&&... args)
    {
      return kumi::array{KUMI_FWD(arg), KUMI_FWD(args)...};
    }
  };
}
