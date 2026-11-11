//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @class numeric_add
    @brief Addition monoid whose identity element is `0`.
  **/
  //====================================================================================================================
  struct numeric_add
  {
    /// Identity/neutral element of the monoid
    static constexpr auto identity{0};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) + KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) + KUMI_FWD(b); }
    {
      return KUMI_FWD(a) + KUMI_FWD(b);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @class numeric_prod
    @brief Multiplication monoid whose identity element is `1`.
  **/
  //====================================================================================================================
  struct numeric_prod
  {
    /// Identity/neutral element of the monoid
    static constexpr auto identity{1};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) * KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) * KUMI_FWD(b); }
    {
      return KUMI_FWD(a) * KUMI_FWD(b);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @class boolean_and
    @brief `logical and` monoid whose identity element is `true`.
  **/
  //====================================================================================================================
  struct boolean_and
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{true};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) & KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) & KUMI_FWD(b); }
    {
      return KUMI_FWD(a) & KUMI_FWD(b);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @class boolean_or
    @brief `logical or` monoid whose identity element is `false`.
  **/
  //====================================================================================================================
  struct boolean_or
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{false};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) | KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) | KUMI_FWD(b); }
    {
      return KUMI_FWD(a) | KUMI_FWD(b);
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @class boolean_xor
    @brief `logical xor` monoid whose identity element is `false`.
  **/
  //====================================================================================================================
  struct boolean_xor
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{false};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) ^ KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) ^ KUMI_FWD(b); }
    {
      return KUMI_FWD(a) ^ KUMI_FWD(b);
    }
  };

  //====================================================================================================================
  //! @defgroup kumi_function_plus kumi::function::plus
  //! @ingroup kumi_functional
  //! @brief Callable object matching the `kumi::numeric_add` monoid, usable with kumi::algorithm.
  //====================================================================================================================
  //==================================================================================================================
  /**
    @ingroup kumi_function_plus
  **/
  //==================================================================================================================
  inline constexpr kumi::function::numeric_add plus{};

  //====================================================================================================================
  //! @defgroup kumi_function_multiplies kumi::function::multiplies
  //! @ingroup kumi_functional
  //! @brief Callable object matching the `kumi::numeric_prod` monoid, usable with kumi::algorithm.
  //====================================================================================================================
  //==================================================================================================================
  /**
    @ingroup kumi_function_multiplies
  **/
  //==================================================================================================================
  inline constexpr kumi::function::numeric_prod multiplies{};

  //====================================================================================================================
  //! @defgroup kumi_function_bit_and kumi::function::bit_and
  //! @ingroup kumi_functional
  //! @brief Callable object matching the `kumi::boolean_and` monoid, usable with kumi::algorithm.
  //====================================================================================================================
  //==================================================================================================================
  /**
    @ingroup kumi_function_bit_and
  **/
  //==================================================================================================================
  inline constexpr kumi::function::boolean_and bit_and{};

  //====================================================================================================================
  //! @defgroup kumi_function_bit_or kumi::function::bit_or
  //! @ingroup kumi_functional
  //! @brief Callable object matching the `kumi::boolean_or` monoid, usable with kumi::algorithm.
  //====================================================================================================================
  //==================================================================================================================
  /**
    @ingroup kumi_function_bit_or
  **/
  //==================================================================================================================
  inline constexpr kumi::function::boolean_or bit_or{};

  //====================================================================================================================
  //! @defgroup kumi_function_bit_xor kumi::function::bit_xor
  //! @ingroup kumi_functional
  //! @brief Callable object matching the `kumi::boolean_xor` monoid, usable with kumi::algorithm.
  //====================================================================================================================
  //==================================================================================================================
  /**
    @ingroup kumi_function_bit_xor
  **/
  //==================================================================================================================
  inline constexpr kumi::function::boolean_xor bit_xor{};
}
