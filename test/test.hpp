//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================

template<typename T, typename Enable = void> struct is_moveonly_type : std::false_type {};
template<typename T> struct is_moveonly_type<T, typename T::is_moveonly_type> : std::true_type {};
template<typename T> struct is_not_moveonly_type : std::bool_constant<!is_moveonly_type<T>::value>{};

struct moveonly{
    using is_moveonly                       = void;
    moveonly()                              = default;
    moveonly(const moveonly &)              = delete;
    moveonly(moveonly &&)                   = default;
    moveonly &operator=(const moveonly &)   = delete;
    moveonly &operator=(moveonly &&)        = default;
};
