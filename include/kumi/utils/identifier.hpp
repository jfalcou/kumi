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
  template<typename T> struct only_t
  {
    template<typename U> static constexpr bool value = std::same_as<T, U>;
  };

  template<template<class> typename Traits> struct traits_check
  {
    template<typename U> static constexpr bool value = Traits<U>::value;
  };

  //====================================================================================================================
  //! @ingroup utility
  //! @brief  Option specifying the single type a identifier will accept.
  //! @tparam T Type that the parametrized identifier will accept.
  //!
  //! @include doc/infra/only.cpp
  //====================================================================================================================
  template<typename T> inline constexpr only_t<T> only = {};

  //====================================================================================================================
  //! @ingroup utility
  //! @brief  Option specifying a traits that type should verify for being used as a identifier value.
  //! @tparam Traits Traits that the parametrized identifier will use to validate its value.
  //!
  //! @include doc/infra/checked.cpp
  //====================================================================================================================
  template<template<class> typename Traits> inline constexpr traits_check<Traits> if_ = {};

  template<typename ID, typename Check = void> struct identifier;

  template<typename ID> struct identifier<ID, void>
  {
    using tag_type = identifier<ID>;

    constexpr identifier() noexcept {};
    constexpr identifier(ID const&) noexcept {};

    KUMI_ABI friend constexpr auto operator<=>(identifier const&, identifier const&) noexcept = default;

    template<typename T> constexpr field<tag_type, std::unwrap_ref_decay_t<T>> operator=(T&& v) const noexcept
    {
      return {KUMI_FWD(v)};
    }

    static constexpr auto to_str()
    {
      using S = std::remove_cvref_t<ID>;
      if constexpr (requires { S::to_str(); }) return S::to_str();
      else return _::typer<ID>();
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         identifier const& f) noexcept
    {
      return os << f.to_str();
    }
  };

  //====================================================================================================================
  //! @ingroup utility
  //! @brief identifier definition class
  //!
  //! kumi::identifier defines a identifier, i.e an entity that can receive values and can be stored as part of a
  //! product type. It is defined by a unique type ID which can be an actual type or generated from kumi::name and an
  //! optional checking operations that will validate the value passed to the identifier is acceptable.
  //!
  //! kumi::identifier can also be used to define custom identifier type with specific behavior.
  //!
  //! @tparam ID    identifier type being defined
  //! @tparam Checker Potential type checker meta-function. By default, this is `void` to notify no check is performed.
  //!
  //! @include doc/infra/regular.cpp
  //====================================================================================================================
  template<typename ID, typename Checker> struct identifier
  {
    /// Derived identifier type
    using tag_type = identifier<ID, Checker>;

    //! Default constructor
    constexpr identifier() noexcept {};

    //==================================================================================================================
    //! @brief Constructs a identifier from an ID and a checker type.
    //!
    //! @param id   Identifier of the identifier.
    //! @param chk  Object performing the compile-time verification of the identifier's value.
    //!
    //! @include doc/infra/only.cpp
    //==================================================================================================================
    constexpr identifier([[maybe_unused]] ID const& id, [[maybe_unused]] Checker const& chk) noexcept {};

    //! identifier comparison
    KUMI_ABI friend constexpr auto operator<=>(identifier const&, identifier const&) noexcept = default;

    //==================================================================================================================
    //! @brief Assignment of a value to a identifier
    //!
    //! Bind a value to current kumi::identifier and returns an instance of a field.
    //!
    //! @param v Bound value
    //! @return An kumi::field binding the identifier to `v`.
    //!
    //! @code
    //! #include <kumi/kumi.hpp>
    //! #include <iostream>
    //!
    //! int main()
    //! {
    //!   using namespace kumi::literals;
    //!   std::cout << ("value"_id = 42.1337) << "\n";
    //! }
    //! @endcode
    //==================================================================================================================
    template<typename T>
    requires(Checker::template value<T>)
    constexpr field<tag_type, std::unwrap_ref_decay_t<T>> operator=(T&& v) const noexcept
    {
      return {KUMI_FWD(v)};
    }

    template<typename T>
    requires(!Checker::template value<T>)
    constexpr field<tag_type, std::unwrap_ref_decay_t<T>> operator=(T&& v) const = delete;

    static constexpr auto to_str()
    {
      using S = std::remove_cvref_t<ID>;
      if constexpr (requires { S::to_str(); }) return S::to_str();
      else return _::typer<ID>();
    }

    //! @related kumi::identifier
    //! @brief Output stream insertion
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         identifier const& f) noexcept
    {
      return os << f.to_str();
    }
  };

  template<typename ID> identifier(ID const&) -> identifier<ID, void>;
  template<typename ID, typename Checker> identifier(ID const&, Checker const&) -> identifier<ID, Checker>;

  //====================================================================================================================
  //! @ingroup utility
  //! @brief Compile-time text based ID
  //! @tparam ID Compile-time string for the ID
  //====================================================================================================================
  template<str ID> struct name : identifier<name<ID>>
  {
    using tag_type = name<ID>;

    static constexpr auto to_str() { return ID; }

    //==================================================================================================================
    //! @brief Assignment of a value to a identifier
    //!
    //! Bind a value to current name and returns an instance of a kumi::field.
    //!
    //! @param v Bound value
    //! @return A kumi::field binding the identifier to `v`.
    //==================================================================================================================
    template<typename T> constexpr field<tag_type, std::unwrap_ref_decay_t<T>> operator=(T&& v) const noexcept
    {
      return {KUMI_FWD(v)};
    }

    //! @related kumi::name
    //! @brief Output stream insertion
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, name const& f) noexcept
    {
      return os << f.to_str();
    }
  };

  namespace _
  {
    // MSVC workaround for get<>
    // MSVC evaluates a requires clause before checking the type of an NTTP
    template<auto N, typename... Ts> KUMI_ABI constexpr auto contains_field()
    {
      if constexpr (!std::integral<std::remove_cvref_t<decltype(N)>>) return can_get_field_by_value<name<N>, Ts...>;
      else return false;
    };
  }
}
