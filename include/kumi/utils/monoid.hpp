//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <cstddef>

namespace kumi
{
  //================================================================================================
  //! @ingroup utility 
  //! @class numeric_add
  //! @brief A type representing the addition monoid with it's associated identity. The identity of 
  //!        the addition is `0`.
  //!
  //! kumi::numeric_add provides a monoid representing the addition. 
  //================================================================================================
  struct numeric_add 
  {
    /// Identity/neutral element of the monoid
    static constexpr auto identity{0};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
    noexcept (noexcept(KUMI_FWD(a) + KUMI_FWD(b)) )
    requires requires { KUMI_FWD(a) + KUMI_FWD(b); }
    {
      return KUMI_FWD(a) + KUMI_FWD(b);
    };
  };
    
  //================================================================================================
  //! @ingroup utility 
  //! @class numeric_prod
  //! @brief A type representing the multiplication monoid with it's associated identity. 
  //!        The identity of the multiplication is `1`.
  //!
  //! kumi::numeric_prod provides a monoid representing the multiplication. 
  //================================================================================================
  struct numeric_prod
  {
    /// Identity/neutral element of the monoid
    static constexpr auto identity{1};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
    noexcept (noexcept(KUMI_FWD(a) * KUMI_FWD(b)) )
    requires requires { KUMI_FWD(a) * KUMI_FWD(b); }
    {
      return KUMI_FWD(a) * KUMI_FWD(b);
    };
  };
    
  //================================================================================================
  //! @ingroup utility 
  //! @class boolean_and 
  //! @brief A type representing the `logical and` monoid and it's associated identity. The identity
  //!        of the `boolean_and` is `true`.
  //!
  //! kumi::boolean_and provides a monoid representing the  `logical and` operation. 
  //================================================================================================
  struct boolean_and 
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{true};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
    noexcept (noexcept(KUMI_FWD(a) & KUMI_FWD(b)) )
    requires requires { KUMI_FWD(a) & KUMI_FWD(b); }
    {
      return KUMI_FWD(a) & KUMI_FWD(b);
    };
  };

  //================================================================================================
  //! @ingroup utility 
  //! @class boolean_or 
  //! @brief A type representing the `logical or` monoid and it's associated identity. The identity
  //!        of `boolean_or` is `false`.
  //!
  //! kumi::boolean_or provides a monoid representing the `logical or` operation. 
  //================================================================================================
  struct boolean_or 
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{false};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
    noexcept (noexcept(KUMI_FWD(a) | KUMI_FWD(b)) )
    requires requires { KUMI_FWD(a) | KUMI_FWD(b); }
    {
      return KUMI_FWD(a) | KUMI_FWD(b);
    };
  };

  //================================================================================================
  //! @ingroup utility 
  //! @class boolean_xor 
  //! @brief A type representing the `logical xor` monoid and it's associated identity. The identity
  //!        of `boolean_xor` is `false`.
  //!
  //! kumi::boolean_xor provides a monoid representing the `logical xor` operation. 
  //================================================================================================
  struct boolean_xor
  {
    /// Identity/neutral element of the monoid
    static constexpr bool identity{false};

    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
    noexcept (noexcept(KUMI_FWD(a) ^ KUMI_FWD(b)) )
    requires requires { KUMI_FWD(a) ^ KUMI_FWD(b); }
    {
      return KUMI_FWD(a) ^ KUMI_FWD(b);
    };
  };

  namespace function
  {
    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a binary monoid callable that can be used in kumi::algoritm. It represents the 
    //!        addition.
    //==============================================================================================
    inline constexpr numeric_add plus{};
    
    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a binary monoid callable that can be used in kumi::algoritm. It represents the 
    //!        multiplication.
    //==============================================================================================
    inline constexpr numeric_prod multiplies{};
    
    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a binary monoid callable that can be used in kumi::algoritm. It represents the 
    //!        logical and operation.
    //==============================================================================================
    inline constexpr boolean_and bit_and{};

    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a binary monoid callable that can be used in kumi::algoritm. It represents the 
    //!        logical or operation.
    //==============================================================================================
    inline constexpr boolean_or bit_or{};

    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a binary monoid callable that can be used in kumi::algoritm. It represents the 
    //!        logical xor operation.
    //==============================================================================================
    inline constexpr boolean_xor bit_xor{};
  }
}
 
