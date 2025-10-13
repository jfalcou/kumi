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
    struct numeric_add 
    {
        static constexpr auto identity{0};

        template<typename T1, typename T2>
        [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
        noexcept (noexcept(KUMI_FWD(a) + KUMI_FWD(b)) )
        requires requires(T1 && x, T2 && y) { KUMI_FWD(x) + KUMI_FWD(y); }
        {
            return KUMI_FWD(a) + KUMI_FWD(b);
        };
    };
    
    struct numeric_prod
    {
        static constexpr auto identity{1};

        template<typename T1, typename T2>
        [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
        noexcept (noexcept(KUMI_FWD(a) * KUMI_FWD(b)) )
        requires requires(T1 && x, T2 && y) { KUMI_FWD(x) * KUMI_FWD(y); }
        {
            return KUMI_FWD(a) * KUMI_FWD(b);
        };
    };
    
    struct boolean_and 
    {
        static constexpr bool identity{true};

        template<typename T1, typename T2>
        [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
        noexcept (noexcept(KUMI_FWD(a) & KUMI_FWD(b)) )
        requires requires(T1 && x, T2 && y) { KUMI_FWD(x) & KUMI_FWD(y); }
        {
            return KUMI_FWD(a) & KUMI_FWD(b);
        };
    };

    struct boolean_or 
    {
        static constexpr bool identity{false};

        template<typename T1, typename T2>
        [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
        noexcept (noexcept(KUMI_FWD(a) | KUMI_FWD(b)) )
        requires requires(T1 && x, T2 && y) { KUMI_FWD(x) | KUMI_FWD(y); }
        {
            return KUMI_FWD(a) | KUMI_FWD(b);
        };
    };

    struct boolean_xor
    {
        static constexpr bool identity{false};

        template<typename T1, typename T2>
        [[nodiscard]] KUMI_ABI constexpr auto operator()( T1 && a, T2 && b ) const
        noexcept (noexcept(KUMI_FWD(a) ^ KUMI_FWD(b)) )
        requires requires(T1 && x, T2 && y) { KUMI_FWD(x) ^ KUMI_FWD(y); }
        {
            return KUMI_FWD(a) ^ KUMI_FWD(b);
        };
    };

    namespace function
    {
        inline constexpr numeric_add    plus{};
        inline constexpr numeric_prod   multiplies{};
        inline constexpr boolean_and    bit_and{};
        inline constexpr boolean_or     bit_or{};
        inline constexpr boolean_xor    bit_xor{};
    }
}
 
