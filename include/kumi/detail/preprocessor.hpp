//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

//================================================================================================
// We optimize layout for tuple of size 1->10
// This macro registers the number of optimized inner representations to generate
//================================================================================================
#define FOR_LIST_OF_STRUCTS(DO)                                                                                        \
  DO(1)                                                                                                                \
  DO(2)                                                                                                                \
  DO(3)                                                                                                                \
  DO(4)                                                                                                                \
  DO(5)                                                                                                                \
  DO(6)                                                                                                                \
  DO(7)                                                                                                                \
  DO(8)                                                                                                                \
  DO(9)                                                                                                                \
  DO(10)

//================================================================================================
// Macro to generate m copies of a token separated by spaces
//================================================================================================
#define KUMI_REPEAT_0(m, d)
#define KUMI_REPEAT_1(m, d) m(0, d)
#define KUMI_REPEAT_2(m, d) KUMI_REPEAT_1(m, d) m(1, d)
#define KUMI_REPEAT_3(m, d) KUMI_REPEAT_2(m, d) m(2, d)
#define KUMI_REPEAT_4(m, d) KUMI_REPEAT_3(m, d) m(3, d)
#define KUMI_REPEAT_5(m, d) KUMI_REPEAT_4(m, d) m(4, d)
#define KUMI_REPEAT_6(m, d) KUMI_REPEAT_5(m, d) m(5, d)
#define KUMI_REPEAT_7(m, d) KUMI_REPEAT_6(m, d) m(6, d)
#define KUMI_REPEAT_8(m, d) KUMI_REPEAT_7(m, d) m(7, d)
#define KUMI_REPEAT_9(m, d) KUMI_REPEAT_8(m, d) m(8, d)
#define KUMI_REPEAT_10(m, d) KUMI_REPEAT_9(m, d) m(9, d)

#define KUMI_PP_REPEAT(N, m, d) KUMI_REPEAT_##N(m, d)

//================================================================================================
// Macro to generate m copies of a token separated by commas
//================================================================================================
#define KUMI_ENUM_0(m, d)
#define KUMI_ENUM_1(m, d) m(0, d)
#define KUMI_ENUM_2(m, d) KUMI_ENUM_1(m, d), m(1, d)
#define KUMI_ENUM_3(m, d) KUMI_ENUM_2(m, d), m(2, d)
#define KUMI_ENUM_4(m, d) KUMI_ENUM_3(m, d), m(3, d)
#define KUMI_ENUM_5(m, d) KUMI_ENUM_4(m, d), m(4, d)
#define KUMI_ENUM_6(m, d) KUMI_ENUM_5(m, d), m(5, d)
#define KUMI_ENUM_7(m, d) KUMI_ENUM_6(m, d), m(6, d)
#define KUMI_ENUM_8(m, d) KUMI_ENUM_7(m, d), m(7, d)
#define KUMI_ENUM_9(m, d) KUMI_ENUM_8(m, d), m(8, d)
#define KUMI_ENUM_10(m, d) KUMI_ENUM_9(m, d), m(9, d)

#define KUMI_PP_ENUM(N, m, d) KUMI_ENUM_##N(m, d)

//================================================================================================
// Macros to generate tokens
//================================================================================================
#define KUMI_PP_CAT(P, S) P##S
#define KUMI_PP_TAC(P, S) S##P
#define KUMI_PP_IDENTITY(I, ...) I

//================================================================================================
// Macro to define one member of a tuple with specific operators
//================================================================================================
#define KUMI_MEMBERS(N, _)                                                                                             \
  T##N member##N;                                                                                                      \
  using index##N = std::integral_constant<std::size_t, N>;                                                             \
  constexpr auto& operator()(index##N)& noexcept                                                                       \
  {                                                                                                                    \
    return member##N;                                                                                                  \
  }                                                                                                                    \
  constexpr auto&& operator()(index##N)&& noexcept                                                                     \
  {                                                                                                                    \
    return static_cast<T##N&&>(member##N);                                                                             \
  }                                                                                                                    \
  constexpr auto const&& operator()(index##N) const&& noexcept                                                         \
  {                                                                                                                    \
    return static_cast<T##N const&&>(member##N);                                                                       \
  }                                                                                                                    \
  constexpr auto const& operator()(index##N) const& noexcept                                                           \
  {                                                                                                                    \
    return member##N;                                                                                                  \
  }

//================================================================================================
// Macros for specific getter functions
//================================================================================================
#define KUMI_GET_TYPE_LVALUE(N, T)                                                                                     \
  if constexpr (std::same_as<T, T##N>) return member##N;

#define KUMI_GET_TYPE_RVALUE(N, T)                                                                                     \
  if constexpr (std::same_as<T, T##N>) return static_cast<T##N&&>(member##N);

#define KUMI_GET_TYPE_CONST_RVALUE(N, T)                                                                               \
  if constexpr (std::same_as<T, T##N>) return static_cast<T##N const&&>(member##N);

#define KUMI_GET_NAME_LVALUE(N, I)                                                                                     \
  if constexpr (field<T##N> && requires { member##N(I{}); }) return member##N(key_of_t<T##N>{});

#define KUMI_GET_NAME_RVALUE(N, I)                                                                                     \
  if constexpr (field<T##N> && requires { member##N(I{}); }) return static_cast<T##N&&>(member##N)(key_of_t<T##N>{});

#define KUMI_GET_NAME_CONST_RVALUE(N, I)                                                                               \
  if constexpr (field<T##N> && requires { member##N(I{}); })                                                           \
    return static_cast<T##N const&&>(member##N)(key_of_t<T##N>{});

//================================================================================================
// Macro used to define the optimized inner structure of a product type
//================================================================================================
#define KUMI_BINDER(N)                                                                                                 \
  template<KUMI_PP_ENUM(N, KUMI_PP_TAC, typename T)>                                                                   \
  requires(no_empty<KUMI_PP_ENUM(N, KUMI_PP_TAC, T)> && no_references<KUMI_PP_ENUM(N, KUMI_PP_TAC, T)>)                \
  struct binder<std::integer_sequence<int, KUMI_PP_ENUM(N, KUMI_PP_IDENTITY, _)>, KUMI_PP_ENUM(N, KUMI_PP_TAC, T)>     \
  {                                                                                                                    \
    static constexpr bool is_homogeneous = (N == 0);                                                                   \
    KUMI_PP_REPEAT(N, KUMI_MEMBERS, _)                                                                                 \
                                                                                                                       \
    template<typename T> constexpr auto& operator()(std::type_identity<T>) & noexcept                                  \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_TYPE_LVALUE, T)                                                                       \
    }                                                                                                                  \
    template<typename T> constexpr auto&& operator()(std::type_identity<T>) && noexcept                                \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_TYPE_RVALUE, T)                                                                       \
    }                                                                                                                  \
    template<typename T> constexpr auto const&& operator()(std::type_identity<T>) const&& noexcept                     \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_TYPE_CONST_RVALUE, T)                                                                 \
    }                                                                                                                  \
    template<typename T> constexpr auto const& operator()(std::type_identity<T>) const& noexcept                       \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_TYPE_LVALUE, T)                                                                       \
    }                                                                                                                  \
                                                                                                                       \
    template<identifier I> constexpr auto& operator()(I) & noexcept                                                    \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_NAME_LVALUE, I)                                                                       \
    }                                                                                                                  \
    template<identifier I> constexpr auto&& operator()(I) && noexcept                                                  \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_NAME_RVALUE, I)                                                                       \
    }                                                                                                                  \
    template<identifier I> constexpr auto const&& operator()(I) const&& noexcept                                       \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_NAME_CONST_RVALUE, I)                                                                 \
    }                                                                                                                  \
    template<identifier I> constexpr auto const& operator()(I) const& noexcept                                         \
    {                                                                                                                  \
      KUMI_PP_REPEAT(N, KUMI_GET_NAME_LVALUE, I)                                                                       \
    }                                                                                                                  \
  };
