//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================

template<typename T, typename Enable = void> struct is_moveonly_i : std::false_type {};
template<typename T> struct is_moveonly_i<T, typename T::is_moveonly_i> : std::true_type {};

template<typename T> struct is_not_moveonly_i : std::bool_constant<!is_moveonly_i<T>::value>{};

template<typename T> using is_moveonly_type     = is_moveonly_i<std::remove_cvref_t<T>>;
template<typename T> using is_not_moveonly_type = is_not_moveonly_i<std::remove_cvref_t<T>>;

struct moveonly{
    using is_moveonly                       = void;
    moveonly()                              = default;
    moveonly(const moveonly &)              = delete;
    moveonly(moveonly &&)                   = default;
    moveonly &operator=(const moveonly &)   = delete;
    moveonly &operator=(moveonly &&)        = default;
};
