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
}
#if defined(_MSC_VER)
#if _MSVC_LANG < 202002L
#error "KUMI C++ version error"
#include "KUMI requires C++20 or higher. Use /std:c++20 or higher to enable C++20 features."
#endif
#else
#if __cplusplus < 202002L
#error "KUMI C++ version error"
#include "KUMI requires C++20 or higher. Use -std=c++20 or higher to enable C++20 features."
#endif
#endif
#define KUMI_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#if defined(__CUDACC__)
#define KUMI_CUDA __host__ __device__
#else
#define KUMI_CUDA
#endif
#if defined(KUMI_DEBUG)
#define KUMI_ABI
#elif defined(__GNUC__) ||                                                                                             \
  defined(__clang__)
#define KUMI_ABI [[using gnu: always_inline, flatten, artificial]] KUMI_CUDA inline
#elif defined(_MSC_VER)
#define KUMI_ABI [[using msvc: forceinline, flatten]] KUMI_CUDA inline
#endif
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif
#include <cstddef>
#include <concepts>
#include <iosfwd>
#include <type_traits>
#include <utility>
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
#define KUMI_PP_CAT(P, S) P##S
#define KUMI_PP_TAC(P, S) S##P
#define KUMI_PP_IDENTITY(I, ...) I
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
namespace kumi
{
  struct str
  {
    static constexpr std::size_t max_size = 64;
    char data_[max_size + 1];
    unsigned int size_;
    template<std::size_t N, std::size_t... Is>
    requires(N <= max_size)
    constexpr str(char const (&s)[N], std::index_sequence<Is...>) : data_{s[Is]...}, size_(N - 1)
    {
    }
    template<std::size_t N, std::size_t O, std::size_t... Is>
    requires(sizeof...(Is) <= max_size)
    constexpr str(char const (&s)[N], std::integral_constant<std::size_t, O>, std::index_sequence<Is...>)
      : data_{s[Is + O]...}, size_(sizeof...(Is) - 1)
    {
    }
    template<std::size_t N>
    requires(N <= max_size)
    constexpr str(char const (&s)[N]) : str{s, std::make_index_sequence<N>{}}
    {
    }
    template<std::size_t N, std::size_t P, std::size_t S>
    requires((N >= P + S) && ((N - P - S) <= max_size))
    constexpr str(char const (&s)[N],
                  std::integral_constant<std::size_t, P> prefix,
                  std::integral_constant<std::size_t, S>)
      : str{s, prefix, std::make_index_sequence<N - P - S>{}}
    {
    }
    KUMI_ABI constexpr std::size_t size() const noexcept { return size_; }
    KUMI_ABI constexpr auto data() const noexcept { return data_; }
    template<typename T>
    requires requires { T{data_, size_}; }
    KUMI_ABI constexpr auto as() const
    {
      return T{data_, size_};
    }
    KUMI_ABI friend constexpr auto operator<=>(str const&, str const&) noexcept = default;
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, str const& s) noexcept
    {
      os << '\'';
      for (std::size_t i = 0; i < s.size(); ++i) os << s.data_[i];
      return os << '\'';
    }
  };
  struct unknown
  {
    constexpr inline operator str() const noexcept { return str{"kumi::unknown"}; }
    KUMI_ABI friend constexpr auto operator<=>(unknown const&, unknown const&) noexcept = default;
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, unknown const&) noexcept
    {
      return os << "kumi::unknown";
    }
  };
  template<str... Strs>
  requires((Strs.size() + ... + sizeof...(Strs)) < str::max_size)
  [[nodiscard]] KUMI_ABI constexpr auto concatenate_str()
  {
    constexpr auto nb_strs = sizeof...(Strs);
    struct
    {
      unsigned int count = {};
      char t[(Strs.size() + ... + sizeof...(Strs))];
    } that;
    auto fill = [&]<std::size_t... N>(str current, std::index_sequence<N...>) {
      ((that.t[that.count++] = current.data_[N]), ...);
    };
    [&]<std::size_t... I>(std::index_sequence<I...>) {
      ((fill(Strs, std::make_index_sequence<Strs.size()>{}),
        (I + 1 < nb_strs ? (that.t[that.count++] = '.', 0) : (that.t[that.count++] = '\0', 0))),
       ...);
    }(std::make_index_sequence<nb_strs>{});
    return str{that.t};
  };
}
namespace kumi::_
{
  template<typename T> constexpr auto typer() noexcept
  {
#if defined(__clang__)
    constexpr auto pfx = kumi::str{"auto kumi::_::typer() [T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__, std::integral_constant<std::size_t, pfx>{},
                                     std::integral_constant<std::size_t, sfx>{}};
#elif defined(__GNUC__)
    constexpr auto pfx = kumi::str{"constexpr auto kumi::_::typer() [with T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__, std::integral_constant<std::size_t, pfx>{},
                                     std::integral_constant<std::size_t, sfx>{}};
#elif defined(_MSC_VER)
    constexpr auto pfx = kumi::str{"auto __cdecl kumi::_::typer<"}.size();
    constexpr auto sfx = kumi::str{">(void)"}.size();
    constexpr auto value =
      kumi::str{__FUNCSIG__, std::integral_constant<std::size_t, pfx>{}, std::integral_constant<std::size_t, sfx>{}};
#endif
    return value;
  }
}
namespace kumi::_
{
  template<typename T> auto make_streamable(T const& e)
  {
    if constexpr (requires(std::ostream& os) { os << e; }) return e;
    else if constexpr (requires { as_streamable(e); }) return as_streamable(e);
    else return kumi::unknown{};
  }
}
#if defined(__ANDROID__) || defined(__APPLE__)
namespace kumi
{
  template<typename From, typename To>
  concept convertible_to = std::is_convertible_v<From, To> && requires { static_cast<To>(std::declval<From>()); };
}
#else
namespace kumi
{
  using std::convertible_to;
}
#endif
namespace kumi::_
{
  template<typename... Ts> struct type_list
  {
  };
  template<auto ID> struct value
  {
  };
  using invalid = std::integral_constant<std::size_t, static_cast<std::size_t>(-1)>;
  template<typename From, typename To>
  concept ordered = requires(From const& a, To const& b) {
    { a < b };
  };
  template<typename T, typename U>
  concept comparable = requires(T t, U u) {
    { t == u };
  };
  template<typename T, typename... Args>
  concept implicit_constructible = requires(Args... args) { T{args...}; };
  template<typename T>
  concept identifier = requires(T const& t) {
    typename std::remove_cvref_t<T>::tag_type;
    { std::remove_cvref_t<T>::to_str() };
  };
  template<typename O>
  concept field = requires(O const& o) {
    typename std::remove_cvref_t<O>::type;
    typename std::remove_cvref_t<O>::identifier_type;
    { o(typename std::remove_cvref_t<O>::identifier_type{}) };
    { std::remove_cvref_t<O>::name() };
  };
  template<field T> struct key_of
  {
    using type = typename std::remove_cvref_t<T>::identifier_type;
  };
  template<field T> struct type_of
  {
    using type = typename std::remove_cvref_t<T>::type;
  };
  template<field T> using key_of_t = typename key_of<std::remove_cvref_t<T>>::type;
  template<field T> using type_of_t = typename type_of<std::remove_cvref_t<T>>::type;
  template<typename From, typename To> struct is_piecewise_constructible : std::false_type
  {
  };
  template<typename From, typename To> struct is_piecewise_convertible : std::false_type
  {
  };
  template<typename From, typename To> struct is_piecewise_ordered : std::false_type
  {
  };
  template<typename From, typename To> struct is_piecewise_comparable : std::false_type
  {
  };
  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_convertible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && kumi::convertible_to<From, To>);
  };
  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && std::is_constructible_v<To, From>);
  };
  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_ordered<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && ordered<From, To>);
  };
  template<template<class...> class Box, typename... Ts, typename... Us>
  requires(sizeof...(Ts) == sizeof...(Us))
  struct is_piecewise_comparable<Box<Ts...>, Box<Us...>>
  {
    static constexpr bool value = (... && _::comparable<Ts, Us>);
  };
  template<typename From, typename To>
  concept piecewise_convertible = is_piecewise_convertible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;
  template<typename From, typename To>
  concept piecewise_constructible =
    is_piecewise_constructible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;
  template<typename From, typename To>
  concept piecewise_ordered = is_piecewise_ordered<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;
  template<typename From, typename To>
  concept piecewise_comparable = is_piecewise_comparable<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;
  template<typename Field> struct check_value
  {
    static consteval std::false_type get(...);
  };
  template<field F> struct check_value<F>
  {
    template<field T>
    requires(std::is_same_v<key_of_t<F>, key_of_t<T>>)
    static consteval type_of_t<F> get(T);
  };
  template<typename... Ts> struct sort : std::true_type
  {
  };
  template<template<class...> class Box, typename... Ts, typename... Us>
  requires(sizeof...(Ts) == sizeof...(Us))
  struct sort<Box<Ts...>, Box<Us...>> : check_value<Ts>...
  {
    using check_value<Ts>::get...;
    using t_list = type_list<decltype(get(std::declval<Us>()))...>;
    using u_list = type_list<decltype(get(std::declval<Us>()))...>;
    using is_fieldwise_constructible = is_piecewise_constructible<t_list, u_list>;
    using is_fieldwise_convertible = is_piecewise_convertible<t_list, u_list>;
    using is_fieldwise_comparable = is_piecewise_comparable<t_list, u_list>;
  };
  template<typename From, typename To>
  concept fieldwise_convertible =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_convertible::value;
  template<typename From, typename To>
  concept fieldwise_constructible =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_constructible::value;
  template<typename From, typename To>
  concept fieldwise_comparable =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_comparable::value;
  template<typename Ref, typename Field> struct check_type
  {
    static consteval Field get(Ref)
    requires std::is_same_v<Field, Ref>;
    static consteval std::false_type get(...);
  };
  template<std::size_t I, typename Ref, typename Field> struct get_index
  {
    using constant = std::integral_constant<std::size_t, I>;
    static consteval constant get(Ref)
    requires std::is_same_v<Ref, Field>;
    static consteval invalid get(...);
  };
  template<typename Ref, typename... Fields> struct get_field_by_type : check_type<Ref, Fields>...
  {
    using check_type<Ref, Fields>::get...;
    using type = decltype(get(std::declval<Ref>()));
  };
  template<typename Ref, typename Seq, typename... Fields> struct get_index_by_type;
  template<typename Ref, std::size_t... I, typename... Fields>
  struct get_index_by_type<Ref, std::index_sequence<I...>, Fields...> : get_index<I, Ref, Fields>...
  {
    using get_index<I, Ref, Fields>::get...;
    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get(std::declval<Ref>()))::value;
  };
  template<typename Ref, typename... Fields>
  using get_field_by_type_t = typename get_field_by_type<Ref, Fields...>::type;
  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_type_v =
    get_index_by_type<Ref, std::index_sequence_for<Fields...>, Fields...>::value;
  template<typename Ref, typename... Fields>
  concept can_get_field_by_type = !std::is_same_v<get_field_by_type_t<Ref, Fields...>, std::false_type>;
  struct failed
  {
    static consteval std::false_type get(...);
    static consteval invalid get_index(...);
  };
  template<std::size_t I, typename Ref, typename Field> struct check_field
  {
    static consteval std::false_type get();
    static consteval invalid get_index();
  };
  template<std::size_t I, typename Ref, field Field>
  requires(std::is_same_v<Ref, key_of_t<Field>>)
  struct check_field<I, Ref, Field>
  {
    using constant = std::integral_constant<std::size_t, I>;
    static consteval Field get(Ref);
    static consteval constant get_index(Ref);
  };
  template<typename Ref, typename Seq, typename... Fields> struct get_field_by_value;
  template<typename Ref, std::size_t... I, typename... Fields>
  struct get_field_by_value<Ref, std::index_sequence<I...>, Fields...> : failed, check_field<I, Ref, Fields>...
  {
    using failed::get;
    using failed::get_index;
    using check_field<I, Ref, Fields>::get...;
    using check_field<I, Ref, Fields>::get_index...;
    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get_index(std::declval<Ref>()))::value;
  };
  template<typename Ref, typename... Fields>
  using get_field_by_value_t = typename get_field_by_value<Ref, std::index_sequence_for<Fields...>, Fields...>::type;
  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_value_v =
    get_field_by_value<Ref, std::index_sequence_for<Fields...>, Fields...>::value;
  template<typename Ref, typename... Fields>
  concept can_get_field_by_value = !std::is_same_v<get_field_by_value_t<Ref, Fields...>, std::false_type>;
}
namespace kumi::_
{
  template<std::size_t I, typename T> consteval auto get_key()
  {
    using type = std::remove_cvref_t<T>;
    if constexpr (_::field<T>) return typename type::identifier_type{};
    else return std::integral_constant<std::size_t, I>{};
  }
  template<std::size_t, typename T> struct unique
  {
    operator std::type_identity<T>();
  };
  template<std::size_t I, typename T> struct unique_name
  {
    operator std::integral_constant<std::size_t, I>();
  };
  template<std::size_t I, _::field T> struct unique_name<I, T>
  {
    operator typename std::remove_cvref_t<T>::identifier_type();
  };
  inline consteval std::true_type true_fn(...);
}
namespace kumi::_
{
  template<int N, typename T> struct leaf
  {
    T value;
    using index = std::integral_constant<std::size_t, N>;
    using inner_type = std::type_identity<T>;
    KUMI_ABI constexpr T& operator()(index) & noexcept { return value; }
    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(value); }
    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(value); }
    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return value; }
    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return value; }
    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(value); }
    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(value); }
    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return value; }
  };
  template<int N, typename T>
  requires(std::is_empty_v<T> && (!field<T>))
  struct leaf<N, T> : T
  {
    using index = std::integral_constant<std::size_t, N>;
    using inner_type = std::type_identity<T>;
    KUMI_ABI constexpr T& operator()(index) & noexcept { return *this; }
    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(*this); }
    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(*this); }
    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return *this; }
    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return *this; }
    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(*this); }
    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(*this); }
    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return *this; }
  };
  template<int N, field T> struct leaf<N, T> : T
  {
    using T::operator();
    using index = std::integral_constant<std::size_t, N>;
    using key = key_of_t<T>;
    using inner_type = type_of_t<T>;
    KUMI_ABI constexpr T& operator()(index) & noexcept { return *this; }
    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(*this); }
    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(*this); }
    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return *this; }
  };
  template<typename ISeq, typename... Ts> struct binder;
  template<int... Is, typename... Ts> struct binder<std::integer_sequence<int, Is...>, Ts...> : leaf<Is, Ts>...
  {
    static constexpr bool is_homogeneous = false;
    using leaf<Is, Ts>::operator()...;
  };
  template<typename ISeq, typename... Ts> struct make_binder
  {
    using type = binder<ISeq, Ts...>;
  };
  template<typename ISeq, typename... Ts> using make_binder_t = typename make_binder<ISeq, Ts...>::type;
  template<typename... Ts> struct set : Ts...
  {
    using Ts::operator()...;
  };
  template<typename... Ts> struct make_set
  {
    using type = set<Ts...>;
  };
  template<typename... Ts> using make_set_t = typename make_set<Ts...>::type;
}
namespace kumi::_
{
  template<typename... Ts> inline constexpr bool no_references = (true && ... && !std::is_reference_v<Ts>);
  template<typename... Ts> inline constexpr bool no_empty = (true && ... && !std::is_empty_v<Ts>);
  template<typename T0, typename... Ts> inline constexpr bool all_the_same = (true && ... && std::is_same_v<T0, Ts>);
  template<typename T0, int N> struct binder_n
  {
    static constexpr bool is_homogeneous = true;
    T0 members[N];
    template<std::size_t I> KUMI_ABI constexpr auto& operator()(std::integral_constant<std::size_t, I>) & noexcept
    {
      return members[I];
    }
    template<std::size_t I>
    KUMI_ABI constexpr auto const& operator()(std::integral_constant<std::size_t, I>) const& noexcept
    {
      return members[I];
    }
    template<std::size_t I> KUMI_ABI constexpr auto&& operator()(std::integral_constant<std::size_t, I>) && noexcept
    {
      return static_cast<T0&&>(members[I]);
    }
    template<std::size_t I>
    KUMI_ABI constexpr auto const&& operator()(std::integral_constant<std::size_t, I>) const&& noexcept
    {
      return static_cast<T0 const&&>(members[I]);
    }
  };
  template<int... Is, typename T0, typename T1, typename... Ts>
  requires(all_the_same<T0, T1, Ts...> && no_references<T0, T1, Ts...> && no_empty<T0, T1, Ts...>)
  struct make_binder<std::integer_sequence<int, Is...>, T0, T1, Ts...>
  {
    using type = binder_n<T0, 2 + sizeof...(Ts)>;
  };
  FOR_LIST_OF_STRUCTS(KUMI_BINDER)
}
namespace kumi
{
}
namespace kumi
{
  template<typename T> struct as
  {
    using type = T;
    constexpr as() noexcept {}
    explicit constexpr as(T const&) noexcept {}
  };
  template<> struct as<void>
  {
    using type = void;
    constexpr as() noexcept {}
  };
}
namespace kumi
{
  namespace _
  {
    template<typename T>
    inline constexpr bool is_reference_wrapper_v =
      !std::is_same_v<std::decay_t<typename std::unwrap_reference<T&&>::type>,
                      typename std::unwrap_ref_decay<T&&>::type>;
    template<typename C, typename P, typename O, typename... Ts>
    KUMI_ABI constexpr decltype(auto) invoke_memptr(P C::* member, O&& o, Ts&&... ts)
    {
      using callable_t = P C::*;
      auto&& ptr = [](auto&& obj) -> decltype(auto) {
        using T = std::remove_cvref_t<decltype(obj)>;
        if constexpr (_::is_reference_wrapper_v<T>) return obj.get();
        else if constexpr (std::is_pointer_v<T>) return *KUMI_FWD(obj);
        else return KUMI_FWD(obj);
      }(KUMI_FWD(o));
      if constexpr (std::is_member_object_pointer_v<callable_t>) return KUMI_FWD(ptr).*member;
      else return (KUMI_FWD(ptr).*member)(KUMI_FWD(ts)...);
    };
  }
  template<typename C, typename... Ts>
  KUMI_ABI constexpr decltype(auto) invoke(C&& c, Ts&&... ts) noexcept(std::is_nothrow_invocable<C, Ts...>::value)
  requires(std::is_invocable<C, Ts...>::value)
  {
    if constexpr (std::is_member_pointer_v<std::decay_t<C>>) return _::invoke_memptr(c, KUMI_FWD(ts)...);
    else return KUMI_FWD(c)(KUMI_FWD(ts)...);
  };
  template<typename R, typename C, typename... Ts>
  KUMI_ABI constexpr R invoke_r(C&& c, Ts&&... ts) noexcept(std::is_nothrow_invocable_r<R, C, Ts...>::value)
  requires(std::is_invocable_r<R, C, Ts...>::value)
  {
    if constexpr (std::is_void_v<R>) invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
    else return invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
  };
}
namespace kumi
{
  namespace _
  {
    template<typename T>
    concept non_empty_tuple = requires(T const& t) {
      typename std::tuple_element<0, std::remove_cvref_t<T>>::type;
      typename std::tuple_size<std::remove_cvref_t<T>>::type;
    };
    template<typename T>
    concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);
    template<typename T>
    concept std_tuple_compatible = _::empty_tuple<T> || _::non_empty_tuple<T>;
    template<typename T>
    concept container_like = requires(T const& t) {
      typename T::value_type;
      typename T::size_type;
      { t.size() } -> kumi::convertible_to<std::size_t>;
      { t.begin() };
      { t.end() };
      { t.data() };
    };
  }
  template<typename T> struct is_product_type : std::false_type
  {
  };
  template<typename T> inline constexpr auto is_product_type_v = is_product_type<T>::value;
  template<typename T, typename Enable = void> struct is_record_type : std::false_type
  {
  };
  template<typename T> struct is_record_type<T, typename T::is_record_type> : std::true_type
  {
  };
  template<typename T> inline constexpr auto is_record_type_v = is_record_type<T>::value;
  template<typename T> struct size : std::tuple_size<std::remove_cvref_t<T>>
  {
  };
  template<typename T> inline constexpr auto size_v = size<T>::value;
  template<std::size_t I, typename T> struct element : std::tuple_element<I, std::remove_cvref_t<T>>
  {
  };
  template<std::size_t I, typename T> using element_t = typename element<I, T>::type;
  template<std::size_t I, typename T> struct member
  {
    using type = decltype(get<I>(std::declval<T&&>()));
  };
  template<std::size_t I, typename T> using member_t = typename member<I, T>::type;
}
namespace kumi
{
  template<typename T> struct is_static_container : std::false_type
  {
  };
  template<template<class, std::size_t> typename Container, typename T, std::size_t N>
  requires _::container_like<Container<T, N>> && (N != static_cast<std::size_t>(-1))
  struct is_static_container<Container<T, N>> : std::true_type
  {
    using value_type = T;
    using size = std::integral_constant<std::size_t, N>;
  };
  template<typename T> inline constexpr auto is_static_container_v = is_static_container<T>::value;
  template<typename T> struct container_size : is_static_container<std::remove_cvref_t<T>>::size
  {
  };
  template<typename T> inline constexpr auto container_size_v = container_size<T>::value;
  template<typename T> struct container_type : is_static_container<std::remove_cvref_t<T>>::value_type
  {
  };
  template<typename T> using container_type_t = typename container_type<T>::type;
}
namespace kumi
{
  template<typename T> struct is_homogeneous : std::false_type
  {
  };
  template<typename T>
  requires(is_product_type_v<T>)
  struct is_homogeneous<T>
  {
    static consteval bool check()
    {
      if constexpr (requires { T::is_homogeneous; }) return T::is_homogeneous;
      else if constexpr (is_record_type_v<T>) return false;
      else if constexpr (is_static_container_v<T>) return true;
      else if constexpr (size_v<T> == 0) return false;
      else if constexpr (size_v<T> == 1) return true;
      else
        return []<std::size_t... I>(std::index_sequence<I...>) {
          return _::all_the_same<element_t<I, T>...>;
        }(std::make_index_sequence<size_v<T>>{});
    }
    static constexpr bool value = check();
  };
  template<typename T> inline constexpr auto is_homogeneous_v = is_homogeneous<T>::value;
  template<typename T> inline constexpr auto is_index_map_v = requires { T::is_index_map; };
  template<typename T> struct is_index_map : std::bool_constant<is_index_map_v<T>>
  {
  };
  template<std::size_t I, typename T> struct raw_member
  {
    using type = member_t<I, T>;
  };
  template<std::size_t I, typename T>
  requires(is_record_type<std::remove_cvref_t<T>>::value)
  struct raw_member<I, T>
  {
    using field_type = decltype(get<I>(std::declval<T&&>()));
    using type = decltype(std::declval<field_type&&>()(typename std::remove_cvref_t<field_type>::identifier_type{}));
  };
  template<std::size_t I, typename T> using raw_member_t = typename raw_member<I, T>::type;
  template<std::size_t I, typename T> struct raw_element
  {
    using type = element_t<I, T>;
  };
  template<std::size_t I, typename T>
  requires(is_record_type<std::remove_cvref_t<T>>::value)
  struct raw_element<I, T>
  {
    using type = typename element_t<I, T>::type;
  };
  template<std::size_t I, typename T> using raw_element_t = typename raw_element<I, T>::type;
  template<typename Ints, typename... Ts> struct all_uniques;
  template<> struct all_uniques<std::index_sequence<>>
  {
    using type = std::true_type;
  };
  template<std::size_t... Ints, typename... Ts> struct all_uniques<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique<Ints, Ts>...
    {
    };
    template<typename... Us> static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);
    using type = decltype(is_set(std::type_identity<Ts>{}...));
  };
  template<typename... Ts> using all_uniques_t = typename all_uniques<std::index_sequence_for<Ts...>, Ts...>::type;
  template<typename... Ts> inline constexpr auto all_uniques_v = all_uniques_t<Ts...>::value;
  template<typename Ints, typename... Ts> struct all_unique_names;
  template<> struct all_unique_names<std::index_sequence<>>
  {
    using type = std::true_type;
  };
  template<std::size_t... Ints, typename... Ts> struct all_unique_names<std::index_sequence<Ints...>, Ts...>
  {
    struct all_uniques_inner : _::unique_name<Ints, Ts>...
    {
    };
    template<typename... Us> static auto is_set(Us...) -> decltype(_::true_fn(static_cast<Us>(all_uniques_inner())...));
    static std::false_type is_set(...);
    using type = decltype(is_set(_::get_key<Ints, Ts>()...));
  };
  template<typename... Ts>
  using all_unique_names_t = typename all_unique_names<std::index_sequence_for<Ts...>, Ts...>::type;
  template<typename... Ts> inline constexpr auto all_unique_names_v = all_unique_names_t<Ts...>::value;
  template<typename... Ts> struct tuple;
  template<typename... Ts> struct record;
  template<typename T>
  requires(_::std_tuple_compatible<T>)
  struct is_product_type<T> : std::true_type
  {
  };
  template<typename T>
  requires(is_static_container_v<T> && _::std_tuple_compatible<T>)
  struct is_product_type<T> : std::true_type
  {
  };
  template<typename T> struct is_kumi_tuple : std::false_type
  {
  };
  template<typename... Ts> struct is_kumi_tuple<kumi::tuple<Ts...>> : std::true_type
  {
  };
  template<typename T> inline constexpr bool is_kumi_tuple_v = is_kumi_tuple<T>::value;
  template<typename T> struct is_kumi_record : std::false_type
  {
  };
  template<typename... Ts> struct is_kumi_record<kumi::record<Ts...>> : std::true_type
  {
  };
  template<typename T> inline constexpr bool is_kumi_record_v = is_kumi_record<T>::value;
}
namespace kumi
{
  template<typename... Ts> struct common_product_type
  {
  };
  template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;
  template<typename T> struct builder;
  template<typename T> struct builder<T&> : builder<T>
  {
  };
  template<typename T> struct builder<T&&> : builder<T>
  {
  };
  template<typename T> struct builder<T const&> : builder<T>
  {
  };
  template<typename T> struct builder<T const&&> : builder<T>
  {
  };
  template<typename T> using builder_t = typename builder<T>::type;
  template<typename T, typename... Args> using builder_make_t = typename builder<T>::template to<Args...>;
}
namespace kumi
{
  namespace _
  {
    template<typename F, typename T>
    concept supports_apply = []<std::size_t... N>(std::index_sequence<N...>) {
      return std::invocable<F, raw_member_t<N, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    template<typename F, typename T>
    concept supports_nothrow_apply = []<std::size_t... N>(std::index_sequence<N...>) {
      return std::is_nothrow_invocable<F, raw_member_t<N, T>...>::value;
    }(std::make_index_sequence<size_v<T>>{});
    template<typename F, typename... Ts>
    concept supports_call = []<std::size_t... I>(std::index_sequence<I...>) {
      return ([]<std::size_t J>(std::integral_constant<std::size_t, J>) {
        return std::invocable<F, raw_member_t<J, Ts>...>;
      }(std::integral_constant<std::size_t, I>{}) &&
              ...);
    }(std::make_index_sequence<(size_v<Ts>, ...)>{});
    template<typename T>
    concept supports_transpose = (size_v<T> <= 1) || ([]<std::size_t... N>(std::index_sequence<N...>) {
                                   return ((size_v<raw_member_t<0, T>> == size_v<raw_member_t<N + 1, T>>) && ...);
                                 }(std::make_index_sequence<size_v<T> - 1>{}));
    template<typename Ints, typename... Ts> struct matches;
    template<> struct matches<std::index_sequence<>>
    {
      using type = std::true_type;
    };
    template<std::size_t... Is, template<class...> class Box, typename... Ts, typename... Us>
    struct matches<std::index_sequence<Is...>, Box<Ts...>, Box<Us...>>
    {
      struct match : _::unique_name<Is, Us>...
      {
      };
      template<typename... Key>
      static consteval auto is_present(Key...) -> decltype(_::true_fn(static_cast<Key>(match())...));
      static consteval std::false_type is_present(...);
      using type = decltype(is_present(_::get_key<Is, Ts>()...));
    };
    template<std::size_t S, typename T, typename U>
    using matches_t = typename matches<std::make_index_sequence<S>, T, U>::type;
    template<typename T, typename U> inline constexpr auto matches_v = matches_t<size_v<T>, T, U>::value;
  }
  namespace concepts
  {
    template<typename T>
    concept product_type = is_product_type<std::remove_cvref_t<T>>::value;
    template<typename T>
    concept record_type = product_type<T> && is_record_type<std::remove_cvref_t<T>>::value;
    template<typename T>
    concept static_container = is_static_container_v<std::remove_cvref_t<T>>;
    template<typename T>
    concept unit_type = (product_type<T> && (size_v<T> == 0)) || std::is_same_v<std::remove_cvref_t<T>, std::nullptr_t>;
    template<typename T>
    concept field = kumi::_::field<T>;
    template<typename T>
    concept identifier = kumi::_::identifier<T>;
    template<typename T, std::size_t N>
    concept sized_product_type = product_type<T> && (size_v<T> == N);
    template<typename T, std::size_t N>
    concept sized_product_type_or_more = product_type<T> && (size_v<T> >= N);
    template<typename T>
    concept empty_product_type = product_type<T> && (size_v<T> == 0);
    template<typename T>
    concept non_empty_product_type = product_type<T> && (size_v<T> != 0);
    template<typename T>
    concept index_map = product_type<T> && is_index_map_v<std::remove_cvref_t<T>>;
    template<typename T>
    concept indexer = index_map<T> || std::integral<std::remove_cvref_t<T>>;
    template<typename T>
    concept homogeneous_product_type = product_type<T> && is_homogeneous_v<std::remove_cvref_t<T>>;
    template<typename T, typename U>
    concept equality_comparable = (size_v<T> == size_v<U>) && _::piecewise_comparable<T, U>;
    template<typename... Ts>
    concept has_named_fields = (... || field<Ts>);
    template<typename... Ts>
    concept is_fully_named = (... && field<Ts>);
    template<typename... Ts>
    concept uniquely_typed = (!has_named_fields<Ts...>) && all_uniques_v<std::remove_cvref_t<Ts>...>;
    template<typename... Ts>
    concept uniquely_named = (has_named_fields<Ts...>) && all_unique_names_v<std::remove_cvref_t<Ts>...>;
    template<typename... Ts>
    concept unique_display_name =
      (sizeof...(Ts) == 0) || (is_fully_named<Ts...> && (all_uniques_v<_::value<std::remove_cvref_t<Ts>::name()>...>));
    template<typename... Ts>
    concept entirely_uniquely_named = (sizeof...(Ts) == 0) || (is_fully_named<Ts...> && uniquely_named<Ts...>);
    template<typename T, typename... Ts>
    concept contains_type = kumi::_::can_get_field_by_type<T, Ts...>;
    template<typename Name, typename... Ts>
    concept contains_field = identifier<Name> && kumi::_::can_get_field_by_value<Name, Ts...>;
    template<typename T, typename U>
    concept equivalent = (size_v<T> == size_v<U>) && _::matches_v<std::remove_cvref_t<T>, std::remove_cvref_t<U>>;
    template<typename T, typename U>
    concept named_equality_comparable = equivalent<T, U> && _::fieldwise_comparable<T, U>;
    template<typename... Ts>
    concept follows_same_semantic = ((product_type<Ts> && !record_type<Ts>) && ...) || ((record_type<Ts> && ...));
    template<typename T, typename... Us>
    concept compatible_product_types =
      (follows_same_semantic<T, Us...> &&
       ((!record_type<T>) || (equivalent<std::remove_cvref_t<T>, std::remove_cvref_t<Us>> && ...)));
    template<typename M>
    concept monoid = requires {
      { std::remove_cvref_t<M>::identity };
      { std::remove_cvref_t<M>{}(std::remove_cvref_t<M>::identity, std::remove_cvref_t<M>::identity) };
    };
    template<typename Type, typename T>
    concept typed_get_compliant = product_type<T> && []<std::size_t... I>(std::index_sequence<I...>) {
      return _::can_get_field_by_type<Type, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
    template<typename Name, typename T>
    concept named_get_compliant =
      identifier<Name> && product_type<T> && []<std::size_t... I>(std::index_sequence<I...>) {
        return _::can_get_field_by_value<Name, element_t<I, T>...>;
      }(std::make_index_sequence<size_v<T>>{});
  }
}
namespace kumi
{
  struct unit
  {
    KUMI_ABI friend constexpr auto operator<=>(unit, unit) noexcept = default;
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    {
      return {};
    };
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    {
      return {};
    };
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, unit) noexcept
    {
      return os << '\'' << "none" << '\'';
    }
  };
  inline constexpr unit none = {};
}
namespace kumi
{
  template<concepts::identifier Id, typename T> struct field
  {
    using type = T;
    using identifier_type = Id;
    using inner_type = std::type_identity<T>;
    T value;
    static constexpr auto name() { return Id::to_str(); }
    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return value; }
    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(value); }
    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return value; }
    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(value); }
    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return value; }
    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(value); }
    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return value; }
    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(value); }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << Id{} << " : " << _::make_streamable(w.value);
    }
  };
  template<concepts::identifier Id, typename T>
  requires(std::is_empty_v<T>)
  struct field<Id, T> : T
  {
    using type = T;
    using identifier_type = Id;
    using inner_type = std::type_identity<T>;
    static constexpr auto name() { return Id::to_str(); }
    KUMI_ABI constexpr T& operator()(identifier_type) & noexcept { return *this; }
    KUMI_ABI constexpr T&& operator()(identifier_type) && noexcept { return static_cast<T&&>(*this); }
    KUMI_ABI constexpr T const& operator()(identifier_type) const& noexcept { return *this; }
    KUMI_ABI constexpr T const&& operator()(identifier_type) const&& noexcept { return static_cast<T const&&>(*this); }
    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return *this; }
    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(*this); }
    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return *this; }
    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(*this); }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, field const& w) noexcept
    {
      return os << Id{} << " : " << _::make_streamable(w(_::key_of_t<decltype(w)>{}));
    }
  };
  template<typename T> [[nodiscard]] KUMI_ABI constexpr auto name_of(as<T>) noexcept
  {
    if constexpr (concepts::field<T>) return _::key_of_t<T>{};
    else return kumi::unknown{};
  };
  template<typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_value_of(T&& t) noexcept
  {
    if constexpr (concepts::field<T>) return (KUMI_FWD(t)(_::key_of_t<T>{}));
    else return KUMI_FWD(t);
  };
  template<concepts::identifier auto Name, typename T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) capture_field(T&& t) noexcept
  {
    return field<decltype(Name), T>{KUMI_FWD(t)};
  }
  template<typename U, typename T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) field_cast(T&& t) noexcept
  {
    if constexpr (concepts::field<U>)
      return field<_::key_of_t<T>, _::type_of_t<U>>{static_cast<_::type_of_t<U>>(KUMI_FWD(t)(_::key_of_t<T>{}))};
    else if constexpr (!concepts::field<T>) return static_cast<_::type_of_t<U>>(KUMI_FWD(t));
    else return field<_::key_of_t<T>, U>{static_cast<U>(KUMI_FWD(t)(_::key_of_t<T>{}))};
  }
  namespace result
  {
    template<typename T> struct name_of
    {
      using type = decltype(kumi::name_of(as<T>{}));
    };
    template<typename T> struct field_value_of
    {
      using type = decltype(kumi::field_value_of(std::declval<T>()));
    };
    template<concepts::identifier auto Name, typename T> struct capture_field
    {
      using type = decltype(kumi::capture_field<Name>(std::declval<T>()));
    };
    template<typename U, typename T> struct field_cast
    {
      using type = decltype(kumi::field_cast<U, T>(std::declval<T>()));
    };
    template<typename T> using name_of_t = typename name_of<T>::type;
    template<typename T> using field_value_of_t = typename field_value_of<T>::type;
    template<concepts::identifier auto Name, typename T> using capture_field_t = typename capture_field<Name, T>::type;
    template<typename U, typename T> using field_cast_t = typename field_cast<U, T>::type;
  }
}
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
  template<typename T> inline constexpr only_t<T> only = {};
  template<template<class> typename Traits> inline constexpr traits_check<Traits> if_ = {};
  template<typename ID, typename Check = void> struct identifier;
  template<typename ID> struct identifier<ID, void>
  {
    using tag_type = identifier<ID>;
    constexpr identifier() noexcept {};
    constexpr identifier(ID const&) noexcept {};
    template<concepts::identifier I> KUMI_ABI friend constexpr auto operator==(identifier const&, I const&)
    {
      return std::same_as<std::remove_cvref_t<identifier>, std::remove_cvref_t<I>>;
    }
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
                                                         identifier const&) noexcept
    {
      return os << identifier::to_str();
    }
  };
  template<typename ID, typename Checker> struct identifier
  {
    using tag_type = identifier<ID, Checker>;
    constexpr identifier() noexcept {};
    constexpr identifier([[maybe_unused]] ID const& id, [[maybe_unused]] Checker const& chk) noexcept {};
    template<concepts::identifier I> KUMI_ABI friend constexpr auto operator==(identifier const&, I const&)
    {
      return std::same_as<std::remove_cvref_t<identifier>, std::remove_cvref_t<I>>;
    }
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
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         identifier const&) noexcept
    {
      return os << identifier::to_str();
    }
  };
  template<typename ID> identifier(ID const&) -> identifier<ID, void>;
  template<typename ID, typename Checker> identifier(ID const&, Checker const&) -> identifier<ID, Checker>;
  template<str ID> struct name
  {
    using tag_type = name<ID>;
    static constexpr auto to_str() { return ID; }
    template<kumi::concepts::identifier I> KUMI_ABI friend constexpr auto operator==(name const&, I const&)
    {
      return std::same_as<std::remove_cvref_t<tag_type>, std::remove_cvref_t<I>>;
    }
    template<typename T> constexpr field<tag_type, std::unwrap_ref_decay_t<T>> operator=(T&& v) const noexcept
    {
      return {KUMI_FWD(v)};
    }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, name const&) noexcept
    {
      return os << ID;
    }
  };
  namespace _
  {
    template<auto N, typename... Ts> KUMI_ABI constexpr auto contains_field()
    {
      if constexpr (std::integral<std::remove_cvref_t<decltype(N)>>) return false;
      else if constexpr (concepts::identifier<std::remove_cvref_t<decltype(N)>>) return false;
      else return can_get_field_by_value<name<N>, Ts...>;
    };
  }
}
namespace kumi
{
  struct numeric_add
  {
    static constexpr auto identity{0};
    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) + KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) + KUMI_FWD(b); }
    {
      return KUMI_FWD(a) + KUMI_FWD(b);
    };
  };
  struct numeric_prod
  {
    static constexpr auto identity{1};
    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) * KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) * KUMI_FWD(b); }
    {
      return KUMI_FWD(a) * KUMI_FWD(b);
    };
  };
  struct boolean_and
  {
    static constexpr bool identity{true};
    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) & KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) & KUMI_FWD(b); }
    {
      return KUMI_FWD(a) & KUMI_FWD(b);
    };
  };
  struct boolean_or
  {
    static constexpr bool identity{false};
    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) | KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) | KUMI_FWD(b); }
    {
      return KUMI_FWD(a) | KUMI_FWD(b);
    };
  };
  struct boolean_xor
  {
    static constexpr bool identity{false};
    template<typename T1, typename T2>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T1&& a, T2&& b) const noexcept(noexcept(KUMI_FWD(a) ^ KUMI_FWD(b)))
    requires requires { KUMI_FWD(a) ^ KUMI_FWD(b); }
    {
      return KUMI_FWD(a) ^ KUMI_FWD(b);
    };
  };
  namespace function
  {
    inline constexpr numeric_add plus{};
    inline constexpr numeric_prod multiplies{};
    inline constexpr boolean_and bit_and{};
    inline constexpr boolean_or bit_or{};
    inline constexpr boolean_xor bit_xor{};
  }
}
namespace kumi
{
  template<concepts::indexer... V> struct indexes_t
  {
    using binder_t = _::make_binder_t<std::make_integer_sequence<int, sizeof...(V)>, V...>;
    static constexpr bool is_index_map = true;
    binder_t impl;
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(V); };
    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return sizeof...(V) == 0; };
    template<std::size_t I>
    requires(I < sizeof...(V))
    KUMI_ABI constexpr decltype(auto) get_index() const noexcept
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(indexes_t& i) noexcept
    {
      return i.get_index<I>();
    }
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(indexes_t const& i) noexcept
    {
      return i.get_index<I>();
    }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         indexes_t const& i) noexcept
    {
      os << "( ";
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        using std::get;
        [[maybe_unused]] auto call = [&]<typename M>(M) { os << get<M::value>(i); };
        (call(std::integral_constant<std::size_t, I>{}), ...);
      }(std::make_index_sequence<sizeof...(V)>());
      os << ")";
      return os;
    }
  };
  template<concepts::indexer... Ts> KUMI_CUDA indexes_t(Ts...) -> indexes_t<Ts...>;
  template<concepts::indexer... Ts> [[nodiscard]] KUMI_ABI consteval auto indexes(Ts... ts) noexcept
  {
    return indexes_t{ts...};
  }
}
namespace kumi
{
  template<typename U, concepts::product_type T>
  requires(concepts::typed_get_compliant<U, T>)
  KUMI_ABI consteval auto get_index_of_type()
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_type_v<U, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
  }
  template<concepts::identifier Name, concepts::product_type T>
  requires(concepts::named_get_compliant<Name, T>)
  KUMI_ABI consteval auto get_index_of_field()
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_value_v<Name, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
  }
  template<std::size_t N> struct index_t
  {
    static constexpr auto value = N;
    constexpr inline operator std::size_t() const noexcept { return N; }
  };
  template<std::size_t N> inline constexpr index_t<N> const index = {};
  inline namespace literals
  {
    template<char... c> constexpr auto b10()
    {
      auto value = 0ULL;
      ((value = value * 10 + (c - '0')), ...);
      return value;
    }
    template<char... c> constexpr auto operator""_c() noexcept
    {
      return index<b10<c...>()>;
    }
    template<kumi::str ID> constexpr auto operator""_id() noexcept
    {
      return name<ID>{};
    }
  }
  template<template<class> class Pred> [[nodiscard]] constexpr auto predicate() noexcept
  {
    return []<typename T>(T const&) constexpr { return Pred<T>::value; };
  }
}
#if !defined(KUMI_DOXYGEN_INVOKED)
template<std::size_t I, typename Head, typename... Tail>
struct std::tuple_element<I, kumi::tuple<Head, Tail...>> : std::tuple_element<I - 1, kumi::tuple<Tail...>>
{
};
template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::tuple<Ts...> const>
{
  using type = typename tuple_element<I, kumi::tuple<Ts...>>::type const;
};
template<typename Head, typename... Tail> struct std::tuple_element<0, kumi::tuple<Head, Tail...>>
{
  using type = Head;
};
template<typename... Ts> struct std::tuple_size<kumi::tuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};
template<std::size_t I, typename Head, typename... Tail>
struct std::tuple_element<I, kumi::record<Head, Tail...>> : std::tuple_element<I - 1, kumi::record<Tail...>>
{
};
template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::record<Ts...> const>
{
  using type = typename tuple_element<I, kumi::record<Ts...>>::type const;
};
template<typename Head, typename... Tail> struct std::tuple_element<0, kumi::record<Head, Tail...>>
{
  using type = Head;
};
template<typename... Ts>
struct std::tuple_size<kumi::record<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};
template<typename... V>
struct std::tuple_size<kumi::indexes_t<V...>> : std::integral_constant<std::size_t, sizeof...(V)>
{
};
template<std::size_t I, typename... V>
struct std::tuple_element<I, kumi::indexes_t<V...>> : std::tuple_element<I, kumi::tuple<V...>>
{
};
template<> struct std::tuple_size<kumi::unit> : std::integral_constant<std::size_t, 0>
{
};
template<std::size_t I> struct std::tuple_element<I, kumi::unit> : std::tuple_element<I, kumi::tuple<>>
{
};
#if !defined(__ANDROID__)
template<typename... Ts, typename... Us, template<class> class TQual, template<class> class UQual>
requires(sizeof...(Ts) == sizeof...(Us))
struct std::basic_common_reference<kumi::tuple<Ts...>, kumi::tuple<Us...>, TQual, UQual>
{
  using type = kumi::tuple<std::common_reference_t<TQual<Ts>, UQual<Us>>...>;
};
#endif
#endif
namespace kumi
{
}
namespace kumi
{
  template<typename... Ts> struct tuple
  {
    using binder_t = _::make_binder_t<std::make_integer_sequence<int, sizeof...(Ts)>, Ts...>;
    static constexpr bool is_homogeneous = binder_t::is_homogeneous;
    binder_t impl;
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] index_t<I> i) & noexcept
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(std::integral_constant<std::size_t, I>{});
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(std::integral_constant<std::size_t, I>{});
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const& noexcept
    {
      return impl(std::integral_constant<std::size_t, I>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) & noexcept
    {
      return impl(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const& noexcept
    {
      return impl(std::type_identity<T>{});
    }
    template<concepts::identifier Name>
    requires(concepts::uniquely_named<Ts...> && concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) & noexcept
    {
      return impl(n);
    }
    template<concepts::identifier Name>
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) && noexcept
    requires(concepts::uniquely_named<Ts...> && concepts::contains_field<Name, Ts...>)
    {
      return static_cast<decltype(impl)&&>(impl)(n);
    }
    template<concepts::identifier Name>
    requires(concepts::uniquely_named<Ts...> && concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(n);
    }
    template<concepts::identifier Name>
    requires(concepts::uniquely_named<Ts...> && concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const& noexcept
    {
      return impl(n);
    }
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(Ts); }
    [[nodiscard]] KUMI_ABI static constexpr bool empty() noexcept { return sizeof...(Ts) == 0; }
    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept -> tuple<decltype(name_of(as<Ts>{}))...>
    {
      return {name_of(as<Ts>{})...};
    };
    template<typename... Us>
    requires(_::piecewise_convertible<tuple, tuple<Us...>> && (sizeof...(Us) == sizeof...(Ts)) &&
             (!std::same_as<Ts, Us> && ...))
    [[deprecated("Will be replaced by free functions")]] [[nodiscard]] inline constexpr auto cast() const
    {
      return apply([](auto&&... elems) { return tuple<Us...>{static_cast<Us>(elems)...}; }, *this);
    }
    template<typename... Us>
    requires((sizeof...(Us) == sizeof...(Ts)) && (!std::same_as<tuple<Ts...>, tuple<Us...>>) &&
             _::piecewise_constructible<tuple<Ts const&...>, tuple<Us...>>)
    [[nodiscard]] KUMI_ABI explicit(!_::piecewise_convertible<tuple<Ts const&...>, tuple<Us...>>) constexpr
    operator tuple<Us...>() const
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<Us...>{static_cast<Us>(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    }
    template<typename... Us>
    requires((sizeof...(Us) == sizeof...(Ts)) && (!std::same_as<tuple<Ts...>, tuple<Us...>>) &&
             _::piecewise_constructible<tuple<Ts&...>, tuple<Us...>>)
    [[nodiscard]] KUMI_ABI explicit(!_::piecewise_convertible<tuple<Ts&...>, tuple<Us...>>) constexpr operator tuple<
      Us...>()
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<Us...>{static_cast<Us>(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    }
    template<typename... Us>
    requires(_::piecewise_convertible<tuple, tuple<Us...>>)
    KUMI_ABI constexpr tuple& operator=(tuple<Us...> const& other)
    {
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((get<I>(*this) = get<I>(other)), ...);
      }(std::make_index_sequence<sizeof...(Ts)>());
      return *this;
    }
    template<typename... Us>
    requires(_::piecewise_convertible<tuple, tuple<Us...>>)
    KUMI_ABI constexpr tuple& operator=(tuple<Us...>&& other)
    {
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((get<I>(*this) = get<I>(KUMI_FWD(other))), ...);
      }(std::make_index_sequence<sizeof...(Ts)>());
      return *this;
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(tuple const& self, tuple<Us...> const& other) noexcept
    requires(concepts::equality_comparable<tuple, tuple<Us...>>)
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return ((get<I>(self) == get<I>(other)) && ...);
      }(std::make_index_sequence<sizeof...(Ts)>());
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(tuple const& self, tuple<Us...> const& other) noexcept
    requires(concepts::equality_comparable<tuple, tuple<Us...>>)
    {
      return !(self == other);
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires(sizeof...(Ts) == sizeof...(Us) && _::piecewise_ordered<tuple, tuple<Us...>>)
    {
      auto res = get<0>(lhs) < get<0>(rhs);
      auto const order = [&]<typename Index>(Index i) {
        auto y_less_x_prev = rhs[i] < lhs[i];
        auto x_less_y = lhs[index_t<Index::value + 1>{}] < rhs[index_t<Index::value + 1>{}];
        return x_less_y && !y_less_x_prev;
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (res || ... || order(index_t<I>{}));
      }(std::make_index_sequence<sizeof...(Ts) - 1>());
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator<=(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return !(rhs < lhs);
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { rhs < lhs; }
    {
      return rhs < lhs;
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator>=(tuple const& lhs, tuple<Us...> const& rhs) noexcept
    requires requires { lhs < rhs; }
    {
      return !(lhs < rhs);
    }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, tuple const& t) noexcept
    {
      os << "( ";
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((os << _::make_streamable(t[index<I>]) << " "), ...);
      }(std::make_index_sequence<size_v<decltype(t)>>{});
      os << ')';
      return os;
    }
  };
  template<> struct tuple<>
  {
    static constexpr bool is_homogeneous = false;
    static constexpr auto size() noexcept { return std::size_t{0}; }
    static constexpr auto empty() noexcept { return true; }
    static constexpr auto names() noexcept { return tuple{}; }
    KUMI_ABI friend constexpr auto operator<=>(tuple<>, tuple<>) noexcept = default;
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    {
      return {};
    };
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    {
      return {};
    };
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, tuple<>) noexcept
    {
      return os << "()";
    }
  };
  template<typename... Ts> KUMI_CUDA tuple(Ts&&...) -> tuple<std::unwrap_ref_decay_t<Ts>...>;
  template<typename... Ts> [[nodiscard]] KUMI_ABI constexpr auto tie(Ts&... ts) -> tuple<Ts&...>
  {
    return {ts...};
  }
  template<typename... Ts> [[nodiscard]] KUMI_ABI constexpr auto forward_as_tuple(Ts&&... ts) -> tuple<Ts&&...>
  {
    return {KUMI_FWD(ts)...};
  }
  template<typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto make_tuple(Ts&&... ts) -> tuple<std::unwrap_ref_decay_t<Ts>...>
  {
    return {KUMI_FWD(ts)...};
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto to_ref(T&& t)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::forward_as_tuple(get<I>(KUMI_FWD(t))...);
    }(std::make_index_sequence<size_v<T>>{});
  }
  template<typename Type, typename... Ts>
  requires(!concepts::product_type<Type> && _::implicit_constructible<Type, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto from_tuple(tuple<Ts...> const& t)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return Type{get<I>(t)...};
    }(std::make_index_sequence<sizeof...(Ts)>());
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto to_tuple(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple{get<I>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T>>{});
  }
  template<concepts::static_container S>
  [[nodiscard]] KUMI_ABI constexpr auto to_tuple(S&& s)
  requires(!concepts::product_type<S>)
  {
    constexpr auto N = container_size_v<S>;
    if constexpr (N == 0) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple{KUMI_FWD(s)[I]...};
      }(std::make_index_sequence<N>{});
  }
  namespace _
  {
    template<concepts::product_type T, typename IndexSequence, template<typename...> class Meta = std::type_identity>
    struct as_tuple;
    template<concepts::product_type T, std::size_t... I> struct as_tuple<T, std::index_sequence<I...>>
    {
      using type = tuple<element_t<I, T>...>;
    };
    template<concepts::product_type T, std::size_t... I, template<typename...> class Meta>
    struct as_tuple<T, std::index_sequence<I...>, Meta>
    {
      using type = tuple<typename Meta<element_t<I, T>>::type...>;
    };
  }
  template<typename T, template<typename...> class Meta = std::type_identity> struct as_tuple;
  template<typename T, template<typename...> class Meta>
  requires(concepts::product_type<T>)
  struct as_tuple<T, Meta> : _::as_tuple<T, std::make_index_sequence<size_v<T>>, Meta>
  {
  };
  template<typename T, template<typename...> class Meta>
  requires(!concepts::product_type<T>)
  struct as_tuple<T, Meta>
  {
    using type = tuple<typename Meta<T>::type>;
  };
  template<typename T, template<typename...> class Meta = std::type_identity>
  using as_tuple_t = typename as_tuple<T, Meta>::type;
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  {
    return t[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& arg) noexcept
  {
    return static_cast<tuple<Ts...>&&>(arg)[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& arg) noexcept
  {
    return arg[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& arg) noexcept
  {
    return static_cast<tuple<Ts...> const&&>(arg)[index<I>];
  }
  template<str S, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && _::contains_field<S, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  {
    return t[name<S>{}];
  }
  template<str S, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && _::contains_field<S, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  {
    return static_cast<tuple<Ts...>&&>(t)[name<S>{}];
  }
  template<str S, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && _::contains_field<S, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  {
    return t[name<S>{}];
  }
  template<str S, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && _::contains_field<S, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  {
    return static_cast<tuple<Ts...> const&&>(t)[name<S>{}];
  }
  template<concepts::identifier auto Id, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && concepts::contains_field<decltype(Id), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  {
    return t[Id];
  }
  template<concepts::identifier auto Id, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && concepts::contains_field<decltype(Id), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  {
    return static_cast<tuple<Ts...>&&>(t)[Id];
  }
  template<concepts::identifier auto Id, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && concepts::contains_field<decltype(Id), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  {
    return t[Id];
  }
  template<concepts::identifier auto Id, typename... Ts>
  requires(concepts::uniquely_named<Ts...> && concepts::contains_field<decltype(Id), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  {
    return static_cast<tuple<Ts...> const&&>(t)[Id];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>& t) noexcept
  {
    return t[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...>&& t) noexcept
  {
    return static_cast<tuple<Ts...>&&>(t)[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const& t) noexcept
  {
    return t[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<Ts...> && concepts::contains_type<T, Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(tuple<Ts...> const&& t) noexcept
  {
    return static_cast<tuple<Ts...> const&&>(t)[as<T>{}];
  }
  template<std::integral auto I, typename T>
  requires(is_kumi_tuple_v<std::remove_cvref_t<T>> && ((I >= size_v<T>) || (I < 0)))
  constexpr auto get(T&& r) = delete;
  template<str S, typename T>
  requires(is_kumi_tuple_v<std::remove_cvref_t<T>> && !_::contains_field<S, T>())
  constexpr auto get(T&& t) = delete;
  template<concepts::identifier auto S, typename T>
  requires(is_kumi_tuple_v<std::remove_cvref_t<T>> && !concepts::contains_field<decltype(S), T>)
  constexpr auto get(T&& t) = delete;
  template<typename U, typename T>
  requires(is_kumi_tuple_v<std::remove_cvref_t<T>> && !concepts::contains_type<U, T>)
  constexpr auto get(T&& t) = delete;
  template<concepts::product_type T>
  requires(!concepts::record_type<T>)
  struct builder<T>
  {
    using type = T;
    template<typename... Us> using to = kumi::tuple<Us...>;
    template<typename... Args> static constexpr auto make(Args&&... args)
    {
      return kumi::make_tuple(KUMI_FWD(args)...);
    }
    template<typename... Args> static constexpr auto build(Args&&... args) { return kumi::tuple{KUMI_FWD(args)...}; }
  };
  template<concepts::product_type... Ts>
  requires(!concepts::record_type<Ts> && ...)
  struct common_product_type<Ts...>
  {
    using type = kumi::tuple<>;
  };
}
namespace kumi
{
  template<typename... Ts>
  requires(concepts::entirely_uniquely_named<Ts...> && concepts::unique_display_name<Ts...>)
  struct record<Ts...>
  {
    using is_record_type = void;
    using set_t = _::make_set_t<Ts...>;
    static constexpr bool is_homogeneous = false;
    set_t impl;
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) & noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T&>(impl);
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) && noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T&&>(static_cast<decltype(impl)&&>(impl));
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const&& noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T const&&>(static_cast<decltype(impl) const&&>(impl));
    }
    template<std::size_t I>
    requires(I < sizeof...(Ts))
    KUMI_ABI constexpr decltype(auto) operator[](index_t<I>) const& noexcept
    {
      using T = element_t<I, tuple<Ts...>>;
      return static_cast<T const&>(impl);
    }
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) & noexcept
    {
      return impl(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(std::type_identity<T>{});
    }
    template<typename T>
    requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
    KUMI_ABI constexpr decltype(auto) operator[](as<T>) const& noexcept
    {
      return impl(std::type_identity<T>{});
    }
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) & noexcept
    {
      return impl(n);
    }
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) && noexcept
    {
      return static_cast<decltype(impl)&&>(impl)(n);
    }
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const&& noexcept
    {
      return static_cast<decltype(impl) const&&>(impl)(n);
    }
    template<concepts::identifier Name>
    requires(concepts::contains_field<Name, Ts...>)
    KUMI_ABI constexpr decltype(auto) operator[](Name const& n) const& noexcept
    {
      return impl(n);
    }
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(Ts); }
    [[nodiscard]] KUMI_ABI static constexpr bool empty() noexcept { return sizeof...(Ts) == 0; }
    [[nodiscard]] KUMI_ABI static constexpr auto names() noexcept { return tuple{name_of(as<Ts>{})...}; };
    [[nodiscard]] KUMI_ABI constexpr auto values() noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<raw_member_t<I, decltype(*this)>...>{field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    };
    [[nodiscard]] KUMI_ABI constexpr auto values() const noexcept
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<raw_member_t<I, decltype(*this)>...>{field_value_of(get<I>(*this))...};
      }(std::make_index_sequence<sizeof...(Ts)>{});
    };
    template<typename... Us>
    requires(concepts::equivalent<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>>)
    KUMI_ABI constexpr record& operator=(record<Us...> const& other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }
    template<typename... Us>
    requires(concepts::equivalent<record, record<Us...>> && _::fieldwise_convertible<record, record<Us...>>)
    KUMI_ABI constexpr record& operator=(record<Us...>&& other)
    {
      ((get<name_of(as<Ts>{})>(*this) = get<name_of(as<Ts>{})>(KUMI_FWD(other))), ...);
      return *this;
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator==(record const& self, record<Us...> const& other) noexcept
    requires(concepts::named_equality_comparable<record, record<Us...>>)
    {
      return ((get<name_of(as<Ts>{})>(self) == get<name_of(as<Ts>{})>(other)) && ...);
    }
    template<typename... Us>
    KUMI_ABI friend constexpr auto operator!=(record const& self, record<Us...> const& other) noexcept
    requires(concepts::named_equality_comparable<record, record<Us...>>)
    {
      return !(self == other);
    }
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         record const& t) noexcept
    {
      os << "( ";
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((os << t[index<I>] << " "), ...);
      }(std::make_index_sequence<size_v<decltype(t)>>{});
      os << ')';
      return os;
    }
  };
  template<> struct record<>
  {
    using is_record_type = void;
    static constexpr bool is_homogeneous = false;
    static constexpr auto size() noexcept { return std::size_t{0}; }
    static constexpr auto empty() noexcept { return true; }
    static constexpr auto names() noexcept { return tuple{}; }
    static constexpr auto values() noexcept { return tuple{}; }
    KUMI_ABI friend constexpr auto operator<=>(record<>, record<>) noexcept = default;
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    {
      return {};
    };
    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    {
      return {};
    };
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, record<>) noexcept
    {
      return os << "()";
    }
  };
  template<typename... Ts>
  requires(!concepts::entirely_uniquely_named<Ts...> || !concepts::unique_display_name<Ts...>)
  struct record<Ts...>
  {
    static_assert(concepts::entirely_uniquely_named<Ts...>, "Duplicate fields in record definition");
    static_assert(concepts::unique_display_name<Ts...>, "Duplicate identifier representation in record definition");
    record(Ts&&...) = delete;
  };
  template<typename... Ts> KUMI_CUDA record(Ts&&...) -> record<std::unwrap_ref_decay_t<Ts>...>;
  template<concepts::identifier auto... Fields, typename... Ts>
  requires(sizeof...(Fields) == sizeof...(Ts))
  KUMI_ABI constexpr auto tie(Ts&... ts) -> record<field<decltype(Fields), Ts&>...>
  {
    return {ts...};
  }
  template<concepts::identifier auto... Fields, typename... Ts>
  requires(sizeof...(Fields) == sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr auto forward_as_record(Ts&&... ts) -> record<field<decltype(Fields), Ts&&>...>
  {
    return {KUMI_FWD(ts)...};
  }
  template<typename... Ts>
  requires(concepts::entirely_uniquely_named<Ts...>)
  [[nodiscard]] KUMI_ABI constexpr auto make_record(Ts&&... ts) -> record<std::unwrap_ref_decay_t<Ts>...>
  {
    return {KUMI_FWD(ts)...};
  }
  template<concepts::record_type R> [[nodiscard]] KUMI_ABI constexpr auto to_ref(R&& r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::forward_as_record<name_of(as<element_t<I, R>>{})...>(field_value_of(get<I>(KUMI_FWD(r)))...);
    }(std::make_index_sequence<size_v<R>>{});
  }
  template<concepts::record_type Type, typename... Ts>
  requires(concepts::equivalent<typename _::as_tuple<Type, std::make_index_sequence<size_v<Type>>>::type, tuple<Ts...>>)
  [[nodiscard]] KUMI_ABI constexpr auto from_record(record<Ts...> const& r)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return Type{get<name_of(as<element_t<I, Type>>{})>(r)...};
    }(std::make_index_sequence<size_v<Type>>());
  }
  template<concepts::record_type Type> [[nodiscard]] KUMI_ABI constexpr auto to_record(Type&& r)
  {
    if constexpr (concepts::sized_product_type<Type, 0>) return kumi::record{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return record{
          capture_field<name_of(as<element_t<I, Type>>{})>(get<name_of(as<element_t<I, Type>>{})>(KUMI_FWD(r)))...};
      }(std::make_index_sequence<size_v<Type>>{});
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[index<I>];
  }
  template<std::size_t I, typename... Ts>
  requires(I < sizeof...(Ts))
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[index<I>];
  }
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[name<Name>{}];
  }
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[name<Name>{}];
  }
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[name<Name>{}];
  }
  template<str Name, typename... Ts>
  requires(_::contains_field<Name, Ts...>())
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[name<Name>{}];
  }
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[Name];
  }
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[Name];
  }
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[Name];
  }
  template<concepts::identifier auto Name, typename... Ts>
  requires(concepts::contains_field<decltype(Name), Ts...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[Name];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>& r) noexcept
  {
    return r[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...>&& r) noexcept
  {
    return static_cast<record<Ts...>&&>(r)[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const& r) noexcept
  {
    return r[as<T>{}];
  }
  template<typename T, typename... Ts>
  requires(concepts::uniquely_typed<_::type_of_t<Ts>...> && concepts::contains_type<T, _::type_of_t<Ts>...>)
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) get(record<Ts...> const&& r) noexcept
  {
    return static_cast<record<Ts...> const&&>(r)[as<T>{}];
  }
  template<std::integral auto I, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && ((I >= size_v<R>) || (I < 0)))
  constexpr auto get(R&& r) = delete;
  template<str S, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !_::contains_field<S, R>())
  constexpr auto get(R&& r) = delete;
  template<concepts::identifier auto S, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !concepts::contains_field<decltype(S), R>)
  constexpr auto get(R&& r) = delete;
  template<typename U, typename R>
  requires(is_kumi_record_v<std::remove_cvref_t<R>> && !concepts::contains_type<U, R>)
  constexpr auto get(R&& r) = delete;
  template<concepts::record_type R> struct builder<R>
  {
    using type = R;
    template<typename... Us> using to = kumi::record<Us...>;
    template<typename... Args> static constexpr auto make(Args&&... args)
    {
      return kumi::make_record(KUMI_FWD(args)...);
    }
    template<typename... Args> static constexpr auto build(Args&&... args) { return kumi::record{KUMI_FWD(args)...}; }
  };
  template<concepts::record_type... Ts> struct common_product_type<Ts...>
  {
    using type = kumi::record<>;
  };
}
namespace kumi
{
}
namespace kumi
{
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto members_of(as<T>) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple{name_of(as<element_t<I, T>>{})...};
      }(std::make_index_sequence<size_v<T>>{});
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto values_of(T&& t) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return tuple<result::field_value_of_t<member_t<I, T>>...>{field_value_of(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<size_v<T>>{});
  }
  namespace result
  {
    template<concepts::product_type T> struct members_of
    {
      using type = decltype(kumi::members_of(as<T>{}));
    };
    template<concepts::product_type T> struct values_of
    {
      using type = decltype(kumi::values_of(std::declval<T>()));
    };
    template<concepts::product_type T> using members_of_t = typename members_of<T>::type;
    template<concepts::product_type T> using values_of_t = typename values_of<T>::type;
  }
}
namespace kumi
{
  template<typename Function, concepts::product_type T>
  KUMI_ABI constexpr decltype(auto) apply(Function&& f, T&& t) noexcept(_::supports_nothrow_apply<Function&&, T&&>)
  requires _::supports_apply<Function, T>
  {
    if constexpr (concepts::sized_product_type<T, 0>) return invoke(KUMI_FWD(f));
    else if constexpr (concepts::record_type<T>) return apply(KUMI_FWD(f), values_of(KUMI_FWD(t)));
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto) {
        return invoke(KUMI_FWD(f), get<I>(KUMI_FWD(t))...);
      }(std::make_index_sequence<size_v<T>>{});
  }
  namespace result
  {
    template<typename Function, concepts::product_type T> struct apply
    {
      using type = decltype(kumi::apply(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T> using apply_t = typename apply<Function, T>::type;
  }
  namespace _
  {
    template<typename Function, concepts::record_type R>
    KUMI_ABI constexpr decltype(auto) apply_field(Function&& f, R&& t)
    {
      if constexpr (concepts::sized_product_type<R, 0>) return invoke(KUMI_FWD(f));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto) {
          return invoke(KUMI_FWD(f), get<I>(KUMI_FWD(t))...);
        }(std::make_index_sequence<size_v<R>>{});
      ;
    }
    namespace result
    {
      template<typename Function, concepts::record_type R> struct apply_field
      {
        using type = decltype(kumi::_::apply_field(std::declval<Function>(), std::declval<R>()));
      };
      template<typename Function, concepts::record_type R>
      using apply_field_t = typename apply_field<Function, R>::type;
    }
  }
}
namespace kumi
{
  template<concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) front(Tuple&& t)
  requires(size_v<Tuple> != 0)
  {
    if constexpr (concepts::record_type<Tuple>) return front(values_of(KUMI_FWD(t)));
    else return get<0>(KUMI_FWD(t));
  }
  template<concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) back(Tuple&& t)
  requires(size_v<Tuple> != 0)
  {
    if constexpr (concepts::record_type<Tuple>) return back(values_of(KUMI_FWD(t)));
    else return get<size_v<Tuple> - 1>(KUMI_FWD(t));
  }
  namespace result
  {
    template<concepts::product_type Tuple> struct front : raw_member<0, Tuple>
    {
    };
    template<concepts::product_type Tuple> struct back : raw_member<size_v<Tuple> - 1, Tuple>
    {
    };
    template<concepts::product_type Tuple> using front_t = typename front<Tuple>::type;
    template<concepts::product_type Tuple> using back_t = typename back<Tuple>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<std::size_t N, std::size_t... S> struct digits
    {
      KUMI_ABI constexpr auto operator()(std::size_t v) noexcept
      {
        struct
        {
          std::size_t data[N];
        } values = {};
        std::size_t shp[N] = {S...};
        std::size_t i = 0;
        while (v != 0)
        {
          values.data[i] = v % shp[i];
          v /= shp[i++];
        }
        return values;
      }
    };
  }
  template<concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto cartesian_product(Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (sizeof...(Ts) == 0) return tuple{};
    else
    {
      using res_type = common_product_type_t<std::remove_cvref_t<Ts>...>;
      constexpr auto idx = [&]<std::size_t... I>(std::index_sequence<I...>) {
        kumi::_::digits<sizeof...(Ts), kumi::size_v<Ts>...> dgt{};
        using t_t = decltype(dgt(0));
        struct
        {
          t_t data[sizeof...(I)];
        } that = {dgt(I)...};
        return that;
      }(std::make_index_sequence<(kumi::size_v<Ts> * ...)>{});
      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        auto tps = kumi::forward_as_tuple(ts...);
        using res_t =
          builder_make_t<res_type, element_t<idx.data[k].data[I], std::remove_cvref_t<element_t<I, decltype(tps)>>>...>;
        return res_t{get<idx.data[k].data[I]>(get<I>(tps))...};
      };
      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<sizeof...(Ts)> ids;
        return kumi::make_tuple(maps(index<N>, ids)...);
      }(std::make_index_sequence<(size_v<Ts> * ...)>{});
    }
  }
  namespace result
  {
    template<typename... T> struct cartesian_product
    {
      using type = decltype(kumi::cartesian_product(std::declval<T>()...));
    };
    template<typename... T> using cartesian_product_t = typename cartesian_product<T...>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<typename T, auto> struct repeat
    {
      using type = T;
    };
    template<typename T, auto I> using repeat_t = typename repeat<T, I>::type;
    template<typename T, auto N> struct as_homogeneous
    {
      template<std::size_t... I>
      static consteval auto homogeneify(std::index_sequence<I...>) -> tuple<repeat_t<T, I>...>;
      using type = std::remove_cvref_t<decltype(homogeneify(std::make_index_sequence<N>{}))>;
    };
    template<typename T, auto N> using as_homogeneous_t = typename as_homogeneous<T, N>::type;
  }
  template<typename Target, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto member_cast(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>)
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, result::field_cast_t<Target, element_t<I, T>>...>;
        return type{field_cast<Target>(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<size_v<T>>{});
    else
    {
      using type = _::as_homogeneous_t<Target, size_v<T>>;
      return static_cast<type>(KUMI_FWD(t));
    }
  }
  namespace result
  {
    template<typename Target, concepts::product_type T> struct member_cast
    {
      using type = decltype(kumi::member_cast<Target, T>(std::declval<T>()));
    };
    template<typename Target, concepts::product_type T> using member_cast_t = typename member_cast<Target, T>::type;
  }
}
namespace kumi
{
  template<concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto cat(Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (sizeof...(Ts) == 0) return tuple{};
    else
    {
      constexpr auto count = (1ULL + ... + size_v<Ts>);
      constexpr auto pos = [&]() {
        struct
        {
          std::size_t t[count], e[count];
        } that{};
        std::size_t k = 0, offset = 0;
        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
          (((that.t[I + offset] = k), (that.e[I + offset] = I)), ...);
          offset += sizeof...(I);
          k++;
        };
        (locate(std::make_index_sequence<size_v<Ts>>{}), ...);
        return that;
      }();
      using res_type = common_product_type_t<std::remove_cvref_t<Ts>...>;
      return [&]<std::size_t... N>(auto&& tuples, std::index_sequence<N...>) {
        using rts = std::remove_cvref_t<decltype(tuples)>;
        using type = builder_make_t<res_type, element_t<pos.e[N], std::remove_cvref_t<element_t<pos.t[N], rts>>>...>;
        return type{get<pos.e[N]>(get<pos.t[N]>(KUMI_FWD(tuples)))...};
      }(kumi::forward_as_tuple(KUMI_FWD(ts)...), std::make_index_sequence<count - 1>{});
    }
  }
  namespace result
  {
    template<concepts::product_type... Ts> struct cat
    {
      using type = decltype(kumi::cat(std::declval<Ts>()...));
    };
    template<concepts::product_type... Ts> using cat_t = typename cat<Ts...>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<typename T, typename... Ts>
    constexpr bool contains = ((concepts::field<T> && std::invocable<T, Ts>) || ...);
  }
  template<concepts::product_type T, concepts::identifier K>
  KUMI_ABI constexpr bool contains([[maybe_unused]] T&& t, [[maybe_unused]] K const& k) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (concepts::record_type<T>)
      return []<std::size_t... I>(std::index_sequence<I...>) {
        return _::can_get_field_by_value<std::remove_cvref_t<K>, element_t<I, T>...>;
      }(std::make_index_sequence<size_v<T>>{});
    else
      return []<std::size_t... I>(std::index_sequence<I...>) {
        if constexpr (((concepts::field<element_t<I, T>> && std::invocable<element_t<I, T>, std::remove_cvref_t<K>>) ||
                       ...))
          return true;
        else return false;
      }(std::make_index_sequence<size_v<T>>{});
  }
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_any(T&& t, Ks const&... ks) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Ks) == 0) return false;
    else return (contains(KUMI_FWD(t), ks) || ...);
  }
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_only([[maybe_unused]] T&& t, [[maybe_unused]] Ks const&... ks) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (sizeof...(Ks) == 0) return false;
    else if constexpr (sizeof...(Ks) < size_v<T>) return false;
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::contains<element_t<I, T>, Ks...> && ...);
      }(std::make_index_sequence<size_v<T>>{});
  }
  template<concepts::product_type T, concepts::identifier... Ks>
  KUMI_ABI constexpr bool contains_none(T&& t, Ks const&... ks) noexcept
  {
    return !contains_any(KUMI_FWD(t), ks...);
  }
}
namespace kumi
{
  template<std::size_t I0, std::size_t I1, concepts::product_type Tuple>
  requires((I0 <= size_v<Tuple>) && (I1 <= size_v<Tuple>))
  [[nodiscard]] KUMI_ABI constexpr auto extract(Tuple&& t,
                                                [[maybe_unused]] index_t<I0> i0,
                                                [[maybe_unused]] index_t<I1> i1) noexcept
  {
    return [&]<std::size_t... N>(std::index_sequence<N...>) {
      using final_t = builder_make_t<Tuple, element_t<N + I0, Tuple>...>;
      return final_t{get<N + I0>(KUMI_FWD(t))...};
    }(std::make_index_sequence<I1 - I0>());
  }
  template<std::size_t I0, concepts::product_type Tuple>
  requires(I0 <= size_v<Tuple>)
  [[nodiscard]] KUMI_ABI constexpr auto extract(Tuple&& t, index_t<I0> i0) noexcept
  {
    return extract(KUMI_FWD(t), i0, index<size_v<Tuple>>);
  }
  template<std::size_t I0, concepts::product_type Tuple>
  requires(I0 <= size_v<Tuple>)
  [[nodiscard]] KUMI_ABI constexpr auto split(Tuple&& t, [[maybe_unused]] index_t<I0> i0) noexcept
  {
    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>) {
      using type = builder_make_t<Tuple, element_t<O::value + I, Tuple>...>;
      return type{get<O::value + I>(KUMI_FWD(t))...};
    };
    return kumi::tuple{select(kumi::index<0>, std::make_index_sequence<I0>{}),
                       select(kumi::index<I0>, std::make_index_sequence<size_v<Tuple> - I0>{})};
  }
  namespace result
  {
    template<concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)> struct extract
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}, kumi::index_t<I1>{}));
    };
    template<concepts::product_type T, std::size_t I0> struct extract<T, I0>
    {
      using type = decltype(kumi::extract(std::declval<T>(), kumi::index_t<I0>{}));
    };
    template<concepts::product_type T, std::size_t I0> struct split
    {
      using type = decltype(kumi::split(std::declval<T>(), kumi::index_t<I0>{}));
    };
    template<concepts::product_type T, std::size_t I0, std::size_t I1 = std::size_t(-1)>
    using extract_t = typename extract<T, I0, I1>::type;
    template<concepts::product_type T, std::size_t I0> using split_t = typename split<T, I0>::type;
  }
}
namespace kumi
{
  template<typename Function, concepts::product_type Tuple, concepts::product_type... Tuples>
  KUMI_ABI constexpr void for_each(Function f, Tuple&& t, Tuples&&... ts)
  requires((concepts::compatible_product_types<Tuple, Tuples...>) && (_::supports_call<Function&, Tuple, Tuples...>))
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return;
    else if constexpr (concepts::record_type<Tuple>)
    {
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        constexpr auto fields = members_of(as<Tuple>{});
        [[maybe_unused]] auto call = [&]<typename M>(M) {
          constexpr auto field = get<M::value>(fields);
          invoke(f, get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...);
        };
        (call(std::integral_constant<std::size_t, I>{}), ...);
      }(std::make_index_sequence<size_v<Tuple>>{});
    }
    else
    {
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        [[maybe_unused]] auto call = [&]<typename M>(M) {
          invoke(f, get<M::value>(KUMI_FWD(t)), get<M::value>(KUMI_FWD(ts))...);
        };
        (call(std::integral_constant<std::size_t, I>{}), ...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
  template<typename Function, concepts::product_type Tuple, concepts::product_type... Tuples>
  requires(!concepts::record_type<Tuple> && (!concepts::record_type<Tuples> && ...))
  KUMI_ABI constexpr void for_each_index(Function f, Tuple&& t, Tuples&&... ts)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return;
    else
    {
      auto const invoker{[&, f](auto const i) { f(i, get<i.value>(KUMI_FWD(t)), get<i.value>(KUMI_FWD(ts))...); }};
      [=]<std::size_t... I>(std::index_sequence<I...>) {
        (invoker(std::integral_constant<unsigned, I>{}), ...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
  template<typename Function, concepts::record_type Tuple, concepts::record_type... Tuples>
  requires(concepts::compatible_product_types<std::remove_cvref_t<Tuple>, std::remove_cvref_t<Tuples>...>)
  KUMI_ABI constexpr void for_each_field(Function f, Tuple&& t, Tuples&&... ts)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return;
    else
    {
      constexpr auto fields = members_of(as<Tuple>{});
      auto const invoker = [&]<std::size_t I>(std::integral_constant<std::size_t, I>) {
        constexpr auto field = get<I>(fields);
        f(field.to_str(), get<field>(KUMI_FWD(t)), get<field>(KUMI_FWD(ts))...);
      };
      [=]<std::size_t... I>(std::index_sequence<I...>) {
        (invoker(std::integral_constant<std::size_t, I>{}), ...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
}
namespace kumi
{
  template<typename Pred, concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto locate(Tuple&& t, Pred p) noexcept
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return 0;
    else if constexpr (concepts::record_type<Tuple>) return locate(values_of(KUMI_FWD(t)), p);
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        bool checks[] = {invoke(p, get<I>(KUMI_FWD(t)))...};
        for (std::size_t i = 0; i < size_v<Tuple>; ++i)
          if (checks[i]) return i;
        return size_v<Tuple>;
      }(std::make_index_sequence<size_v<Tuple>>{});
  }
}
namespace kumi
{
  namespace _
  {
    template<typename T> KUMI_ABI constexpr auto flat_one(T&& t)
    {
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          auto v_or_r = [&]<typename V>(V&& v) {
            using FV = kumi::result::field_value_of_t<V>;
            constexpr auto curr_name = name_of(as<V>{}).to_str();
            if constexpr (concepts::record_type<FV>)
            {
              return [&]<std::size_t... J>(std::index_sequence<J...>) {
                return record{
                  (capture_field<name<concatenate_str<curr_name, name_of(as<element_t<J, FV>>{}).to_str()>()>{}>(
                    field_value_of(get<J>(field_value_of(KUMI_FWD(v))))))...};
              }(std::make_index_sequence<size_v<FV>>{});
            }
            else return record{KUMI_FWD(v)};
          };
          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }
    template<auto Prefix, typename T> KUMI_ABI constexpr auto flat(T&& t)
    {
      using Prefix_type = std::remove_cvref_t<decltype(Prefix)>;
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          auto v_or_r = [&]<typename V>(V&& v) {
            constexpr auto curr_name = [&] {
              if constexpr (std::is_same_v<Prefix_type, unit>) return name<name_of(as<V>{}).to_str()>{};
              else return name<concatenate_str<Prefix.to_str(), name_of(as<V>{}).to_str()>()>{};
            }();
            if constexpr (concepts::record_type<kumi::result::field_value_of_t<V>>)
              return flat<curr_name>(field_value_of(KUMI_FWD(v)));
            else return record{capture_field<curr_name>(field_value_of(KUMI_FWD(v)))};
          };
          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }
    template<auto Prefix, typename T, typename F> KUMI_ABI constexpr auto flat_map(T&& t, F f)
    {
      if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          using Prefix_type = std::remove_cvref_t<decltype(Prefix)>;
          auto v_or_r = [&]<typename V>(V&& v) {
            constexpr auto curr_name = [&] {
              if constexpr (std::is_same_v<Prefix_type, unit>) return name<name_of(as<V>{}).to_str()>{};
              else return name<concatenate_str<Prefix.to_str(), name_of(as<V>{}).to_str()>()>{};
            }();
            if constexpr (concepts::record_type<kumi::result::field_value_of_t<V>>)
              return flat_map<curr_name>(field_value_of(KUMI_FWD(v)), f);
            else return record{capture_field<curr_name>(invoke(f, field_value_of(v)))};
          };
          return cat(v_or_r(get<I>(KUMI_FWD(t)))...);
        }(std::make_index_sequence<size_v<T>>{});
    }
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat_one(KUMI_FWD(t));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = []<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return KUMI_FWD(v);
          else return kumi::tuple{KUMI_FWD(v)};
        };
        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
  }
  template<concepts::product_type T, typename Func> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t, Func f)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat_map<none>(KUMI_FWD(t), KUMI_FWD(f));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = [&]<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return flatten_all(KUMI_FWD(v), f);
          else return tuple{invoke(f, v)};
        };
        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto flatten_all(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else if constexpr (concepts::record_type<T>) return _::flat<none>(KUMI_FWD(t));
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        auto v_or_t = []<typename V>(V&& v) {
          if constexpr (concepts::product_type<V>) return flatten_all(KUMI_FWD(v));
          else return kumi::tuple{KUMI_FWD(v)};
        };
        return cat(v_or_t(get<I>(KUMI_FWD(t)))...);
      }(std::make_index_sequence<size_v<T>>{});
    }
  }
  namespace result
  {
    template<concepts::product_type T> struct flatten
    {
      using type = decltype(kumi::flatten(std::declval<T>()));
    };
    template<concepts::product_type T, typename Func = void> struct flatten_all
    {
      using type = decltype(kumi::flatten_all(std::declval<T>(), std::declval<Func>()));
    };
    template<concepts::product_type T> struct flatten_all<T>
    {
      using type = decltype(kumi::flatten_all(std::declval<T>()));
    };
    template<concepts::product_type T> using flatten_t = typename flatten<T>::type;
    template<concepts::product_type T, typename Func = void> using flatten_all_t = typename flatten_all<T, Func>::type;
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI auto as_flat_ptr(T&& t) noexcept
  {
    return kumi::flatten_all(KUMI_FWD(t), [](auto& m) { return &m; });
  }
  namespace result
  {
    template<concepts::product_type T> struct as_flat_ptr
    {
      using type = decltype(kumi::as_flat_ptr(std::declval<T>()));
    };
    template<concepts::product_type T> using as_flat_ptr_t = typename as_flat_ptr<T>::type;
  }
}
namespace kumi
{
  template<std::size_t N, typename T> [[nodiscard]] KUMI_ABI constexpr auto fill(T const& v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      auto eval = [](auto, auto const& vv) { return vv; };
      return kumi::tuple{eval(index<I>, v)...};
    }(std::make_index_sequence<N>{});
  }
  template<std::size_t N, typename Function> [[nodiscard]] KUMI_ABI constexpr auto generate(Function const& f) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::tuple{invoke(f, index<I>)...};
    }(std::make_index_sequence<N>{});
  }
  template<std::size_t N, typename T> [[nodiscard]] KUMI_ABI constexpr auto iota(T v) noexcept
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::tuple{static_cast<T>(v + I)...};
    }(std::make_index_sequence<N>{});
  }
  namespace result
  {
    template<std::size_t N, typename T> struct fill
    {
      using type = decltype(kumi::fill<N>(std::declval<T>()));
    };
    template<std::size_t N, typename Function> struct generate
    {
      using type = decltype(kumi::generate<N>(std::declval<Function>()));
    };
    template<std::size_t N, typename T> struct iota
    {
      using type = decltype(kumi::iota<N>(std::declval<T>()));
    };
    template<std::size_t N, typename T> using fill_t = typename fill<N, T>::type;
    template<std::size_t N, typename Function> using generate_t = typename generate<N, Function>::type;
    template<std::size_t N, typename T> using iota_t = typename iota<N, T>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<typename F, typename T> struct foldable
    {
      F func;
      T value;
      template<typename W> KUMI_ABI friend constexpr decltype(auto) operator>>(foldable&& x, foldable<F, W>&& y)
      {
        return _::foldable{x.func, invoke(x.func, x.value, y.value)};
      }
      template<typename W> KUMI_ABI friend constexpr decltype(auto) operator<<(foldable&& x, foldable<F, W>&& y)
      {
        return _::foldable{x.func, invoke(x.func, x.value, y.value)};
      }
    };
    template<class F, class T> foldable(F const&, T&&) -> foldable<F, T>;
  }
  template<concepts::product_type S1,
           concepts::sized_product_type<size_v<S1>> S2,
           typename T,
           typename Sum,
           typename Prod>
  requires(concepts::compatible_product_types<S1, S2>)
  [[nodiscard]] KUMI_ABI constexpr auto inner_product(S1&& s1, S2&& s2, T init, Sum sum, Prod prod) noexcept
  {
    if constexpr (concepts::sized_product_type<S1, 0>) return init;
    else if constexpr (concepts::record_type<S1>)
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{sum, invoke(prod, get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s1)),
                                        get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s2)))} >>
                ... >> _::foldable{sum, init})
          .value;
      }(std::make_index_sequence<size<S1>::value>());
    }
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{sum, invoke(prod, get<I>(KUMI_FWD(s1)), get<I>(KUMI_FWD(s2)))} >> ... >>
                _::foldable{sum, init})
          .value;
      }(std::make_index_sequence<size<S1>::value>());
    }
  }
  template<concepts::product_type S1, concepts::sized_product_type<size_v<S1>> S2, typename T>
  requires(concepts::compatible_product_types<S1, S2>)
  [[nodiscard]] KUMI_ABI constexpr auto inner_product(S1&& s1, S2&& s2, T init) noexcept
  {
    if constexpr (concepts::sized_product_type<S1, 0>) return init;
    else if constexpr (concepts::record_type<S1>)
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (
          init + ... +
          (get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s1)) * get<name_of(as<element_t<I, S1>>{})>(KUMI_FWD(s2))));
      }(std::make_index_sequence<size<S1>::value>());
    }
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (init + ... + (get<I>(KUMI_FWD(s1)) * get<I>(KUMI_FWD(s2))));
      }(std::make_index_sequence<size<S1>::value>());
    }
  }
  namespace result
  {
    template<concepts::product_type S1,
             concepts::sized_product_type<S1::size()> S2,
             typename T,
             typename Sum,
             typename Prod>
    struct inner_product
    {
      using type = decltype(kumi::inner_product(
        std::declval<S1>(), std::declval<S2>(), std::declval<T>(), std::declval<Sum>(), std::declval<Prod>()));
    };
    template<concepts::product_type S1, concepts::sized_product_type<S1::size()> S2, typename T>
    struct inner_product<S1, S2, T, void, void>
    {
      using type = decltype(kumi::inner_product(std::declval<S1>(), std::declval<S2>(), std::declval<T>()));
    };
    template<concepts::product_type S1,
             concepts::sized_product_type<S1::size()> S2,
             typename T,
             typename Sum = void,
             typename Prod = void>
    using inner_product_t = typename inner_product<S1, S2, T, Sum, Prod>::type;
  }
}
namespace kumi
{
  template<concepts::product_type Tuple, typename Function, concepts::sized_product_type<size_v<Tuple>>... Tuples>
  [[nodiscard]] KUMI_ABI constexpr auto map(Function f, Tuple&& t0, Tuples&&... others)
  requires(concepts::compatible_product_types<Tuple, Tuples...> && _::supports_call<Function, Tuple &&, Tuples && ...>)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return builder<Tuple>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Ts>(index_t<N>, Ts&&... args) {
        if constexpr (concepts::record_type<Tuple>)
        {
          constexpr auto field = name_of(as<element_t<N, Tuple>>{});
          return capture_field<field>(invoke(f, get<field>(args)...));
        }
        else return invoke(f, get<N>(KUMI_FWD(args))...);
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<Tuple>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<Tuple>>());
    }
  }
  namespace result
  {
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts> struct map
    {
      using type = decltype(kumi::map(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_t = typename map<Function, T, Ts...>::type;
  }
  template<concepts::product_type Tuple, typename Function, concepts::sized_product_type<size_v<Tuple>>... Tuples>
  [[nodiscard]] KUMI_ABI constexpr auto map_index(Function f, Tuple&& t0, Tuples&&... others)
  requires(!concepts::record_type<Tuple> && (!concepts::record_type<Tuples> && ...))
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return builder<Tuple>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Ts>(index_t<N> idx, Ts&&... args) {
        return invoke(f, idx, get<N>(KUMI_FWD(args))...);
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<Tuple>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<Tuple>>());
    }
  }
  namespace result
  {
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    struct map_index
    {
      using type = decltype(kumi::map_index(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };
    template<typename Function, concepts::product_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_index_t = typename map_index<Function, T, Ts...>::type;
  }
  template<concepts::record_type Tuple, typename Function, concepts::sized_product_type<size<Tuple>::value>... Tuples>
  requires(concepts::compatible_product_types<Tuple, Tuples...>)
  constexpr auto map_field(Function f, Tuple&& t0, Tuples&&... others)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return builder<Tuple>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Ts>(index_t<N>, Ts&&... args) {
        constexpr auto field = name_of(as<element_t<N, Tuple>>{});
        return capture_field<field>(invoke(f, field.to_str(), (get<field>(args))...));
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<Tuple>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
  namespace result
  {
    template<typename Function, concepts::record_type T, concepts::sized_product_type<size<T>::value>... Ts>
    struct map_field
    {
      using type = decltype(kumi::map_field(std::declval<Function>(), std::declval<T>(), std::declval<Ts>()...));
    };
    template<typename Function, concepts::record_type T, concepts::sized_product_type<size<T>::value>... Ts>
    using map_field_t = typename map_field<Function, T, Ts...>::type;
  }
}
namespace kumi
{
  template<concepts::product_type Tuple, typename T> [[nodiscard]] KUMI_ABI constexpr auto push_front(Tuple&& t, T&& v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return builder<Tuple>::make(KUMI_FWD(v), get<I>(KUMI_FWD(t))...);
    }(std::make_index_sequence<size_v<Tuple>>());
  }
  template<concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto pop_front(Tuple&& t)
  {
    if constexpr (concepts::sized_product_type_or_more<Tuple, 1>) return extract(KUMI_FWD(t), index<1>);
    else return builder<Tuple>::make();
  }
  template<concepts::product_type Tuple, typename T> [[nodiscard]] KUMI_ABI constexpr auto push_back(Tuple&& t, T&& v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return builder<Tuple>::make(get<I>(KUMI_FWD(t))..., KUMI_FWD(v));
    }(std::make_index_sequence<size_v<Tuple>>());
  }
  template<concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto pop_back(Tuple&& t)
  {
    if constexpr (concepts::sized_product_type_or_more<Tuple, 1>)
      return extract(KUMI_FWD(t), index<0>, index<size_v<Tuple> - 1>);
    else return builder<Tuple>::make();
  }
  namespace result
  {
    template<concepts::product_type Tuple, typename T> struct push_front
    {
      using type = decltype(kumi::push_front(std::declval<Tuple>(), std::declval<T>()));
    };
    template<concepts::product_type Tuple> struct pop_front
    {
      using type = decltype(kumi::pop_front(std::declval<Tuple>()));
    };
    template<concepts::product_type Tuple, typename T> struct push_back
    {
      using type = decltype(kumi::push_back(std::declval<Tuple>(), std::declval<T>()));
    };
    template<concepts::product_type Tuple> struct pop_back
    {
      using type = decltype(kumi::pop_back(std::declval<Tuple>()));
    };
    template<concepts::product_type Tuple, typename T> using push_front_t = typename push_front<Tuple, T>::type;
    template<concepts::product_type Tuple> using pop_front_t = typename pop_front<Tuple>::type;
    template<concepts::product_type Tuple, typename T> using push_back_t = typename push_back<Tuple, T>::type;
    template<concepts::product_type Tuple> using pop_back_t = typename pop_back<Tuple>::type;
  }
}
namespace kumi
{
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return fold_left(f, values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{f, init} >> ... >> _::foldable{f, get<I>(KUMI_FWD(t))}).value;
      }(std::make_index_sequence<size_v<T>>());
    }
  }
  template<typename Function, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T&& t)
  {
    if constexpr (concepts::record_type<T>) return fold_left(f, values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto&& [heads, tail] = split(KUMI_FWD(t), index<2>);
      return fold_left(f, tail, kumi::apply(f, heads));
    }
  }
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return fold_right(f, values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::foldable{f, get<I>(KUMI_FWD(t))} << ... << _::foldable{f, init}).value;
      }(std::make_index_sequence<size_v<T>>());
    }
  }
  template<typename Function, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t)
  {
    if constexpr (concepts::record_type<T>) return fold_right(f, values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto&& [head, tails] = split(KUMI_FWD(t), index<size_v<T> - 2>);
      return fold_right(f, head, kumi::apply(f, tails));
    }
  }
  namespace result
  {
    template<typename Function, concepts::product_type T, typename Value = void> struct fold_right
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct fold_right<Function, T>
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void> struct fold_left
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct fold_left<Function, T>
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void>
    using fold_right_t = typename fold_right<Function, T, Value>::type;
    template<typename Function, concepts::product_type T, typename Value = void>
    using fold_left_t = typename fold_left<Function, T, Value>::type;
  }
}
namespace kumi
{
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t) noexcept
  {
    if constexpr (concepts::record_type<T>) return max(values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto base = get<0>(KUMI_FWD(t));
      return kumi::fold_left([]<typename U>(auto cur, U u) { return cur > u ? cur : u; }, KUMI_FWD(t), base);
    }
  }
  template<concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t, F f) noexcept
  {
    if constexpr (concepts::record_type<T>) return max(values_of(KUMI_FWD(t)), f);
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto base = f(get<0>(KUMI_FWD(t)));
      return kumi::fold_left([f]<typename U>(auto cur, U const& u) { return cur > invoke(f, u) ? cur : invoke(f, u); },
                             KUMI_FWD(t), base);
    }
  }
  template<concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto max_flat(T&& t, F f) noexcept
  {
    auto flat_t = kumi::flatten_all(KUMI_FWD(t));
    return max(flat_t, f);
  }
  namespace result
  {
    template<typename T, typename F = void> struct max
    {
      using type = decltype(kumi::max(std::declval<T>(), std::declval<F>()));
    };
    template<typename T> struct max<T, void>
    {
      using type = decltype(kumi::max(std::declval<T>()));
    };
    template<typename T, typename F> struct max_flat
    {
      using type = decltype(kumi::max_flat(std::declval<T>(), std::declval<F>()));
    };
    template<typename T, typename F = void> using max_t = typename max<T, F>::type;
    template<typename T, typename F> using max_flat_t = typename max_flat<T, F>::type;
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t) noexcept
  {
    if constexpr (concepts::record_type<T>) return min(values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto base = get<0>(KUMI_FWD(t));
      return kumi::fold_left([]<typename U>(auto cur, U u) { return cur < u ? cur : u; }, KUMI_FWD(t), base);
    }
  }
  template<concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t, F f) noexcept
  {
    if constexpr (concepts::record_type<T>) return min(values_of(KUMI_FWD(t)), f);
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto base = f(get<0>(KUMI_FWD(t)));
      return kumi::fold_left([f]<typename U>(auto cur, U const& u) { return cur < invoke(f, u) ? cur : invoke(f, u); },
                             KUMI_FWD(t), base);
    }
  }
  template<concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto min_flat(T&& t, F f) noexcept
  {
    auto flat_t = kumi::flatten_all(KUMI_FWD(t));
    return min(flat_t, f);
  }
  namespace result
  {
    template<typename T, typename F = void> struct min
    {
      using type = decltype(kumi::min(std::declval<T>(), std::declval<F>()));
    };
    template<typename T> struct min<T, void>
    {
      using type = decltype(kumi::min(std::declval<T>()));
    };
    template<typename T, typename F> struct min_flat
    {
      using type = decltype(kumi::min_flat(std::declval<T>(), std::declval<F>()));
    };
    template<typename T, typename F = void> using min_t = typename min<T, F>::type;
    template<typename T, typename F> using min_flat_t = typename min_flat<T, F>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<template<typename> typename Pred, concepts::product_type T> struct selector_t
    {
      KUMI_ABI constexpr auto operator()() const noexcept
      {
        struct
        {
          std::size_t count = {}, cut = {}, t[1 + size_v<T>];
        } that{};
        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
          that.cut = that.count;
          ((!Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
        };
        locate(std::make_index_sequence<size_v<T>>{});
        return that;
      }
    };
    template<template<typename> typename Pred, concepts::product_type T>
    inline constexpr selector_t<Pred, T> selector{};
  }
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto partition(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();
    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>) {
      using type = builder_make_t<T, element_t<pos.t[O::value + I], T>...>;
      return type{get<pos.t[O::value + I]>(KUMI_FWD(t))...};
    };
    return kumi::tuple{select(kumi::index<0>, std::make_index_sequence<pos.cut>{}),
                       select(kumi::index<pos.cut>, std::make_index_sequence<size_v<T> - pos.cut>{})};
  }
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<pos.t[I], T>...>;
        return type{get<pos.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<pos.cut>{});
  }
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter_not(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<pos.t[pos.cut + I], T>...>;
        return type{get<pos.t[pos.cut + I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T> - pos.cut>{});
  }
  namespace result
  {
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct partition
    {
      using type = decltype(kumi::partition<Pred>(std::declval<T>()));
    };
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter
    {
      using type = decltype(kumi::filter<Pred>(std::declval<T>()));
    };
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter_not
    {
      using type = decltype(kumi::filter_not<Pred>(std::declval<T>()));
    };
    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using partition_t = typename partition<Pred, T>::type;
    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_t = typename filter<Pred, T>::type;
    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_not_t = typename filter_not<Pred, T>::type;
  }
}
namespace kumi
{
  template<typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& ts, Pred p) noexcept
  {
    if constexpr (concepts::record_type<T>) return all_of(values_of(KUMI_FWD(ts)), p);
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(p, get<0>(KUMI_FWD(ts)));
    else return kumi::apply([&](auto&&... m) { return (invoke(p, m) && ...); }, KUMI_FWD(ts));
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& ts) noexcept
  {
    if constexpr (concepts::record_type<T>) return all_of(values_of(KUMI_FWD(ts)));
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(ts));
    else return kumi::apply([&](auto&&... m) { return (m && ...); }, KUMI_FWD(ts));
  }
  template<typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& ts, Pred p) noexcept
  {
    if constexpr (concepts::record_type<T>) return any_of(values_of(KUMI_FWD(ts)), p);
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(p, get<0>(KUMI_FWD(ts)));
    else return kumi::apply([&](auto&&... m) { return (invoke(p, m) || ...); }, KUMI_FWD(ts));
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& ts) noexcept
  {
    if constexpr (concepts::record_type<T>) return any_of(values_of(KUMI_FWD(ts)));
    else if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(ts));
    else return kumi::apply([&](auto&&... m) { return (m || ...); }, KUMI_FWD(ts));
  }
  template<typename Pred, concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr bool none_of(Tuple&& ts, Pred p) noexcept
  {
    return !any_of(KUMI_FWD(ts), p);
  }
  template<concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr bool none_of(Tuple&& ts) noexcept
  {
    return !any_of(KUMI_FWD(ts));
  }
  template<typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr std::size_t count_if(T&& ts, Pred p) noexcept
  {
    constexpr std::size_t o = 1ULL;
    constexpr std::size_t z = 0ULL;
    if constexpr (concepts::sized_product_type<T, 0>) return z;
    else return kumi::apply([&](auto&&... m) { return ((invoke(p, m) ? o : z) + ... + z); }, KUMI_FWD(ts));
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr std::size_t count(T&& ts) noexcept
  {
    return count_if(KUMI_FWD(ts), [](auto const& m) { return static_cast<bool>(m); });
  }
}
namespace kumi
{
  namespace _
  {
    template<concepts::index_map auto idxs, concepts::product_type T> consteval auto in_bound_indexes()
    {
      using map_t = std::remove_cvref_t<decltype(idxs)>;
      if constexpr (concepts::sized_product_type<T, 0>) return false;
      else if constexpr (concepts::sized_product_type<map_t, 0>) return true;
      else
        return []<std::size_t... N>(std::index_sequence<N...>) {
          bool checks[] = {([]() {
            if constexpr (concepts::product_type<element_t<N, map_t>>) return in_bound_indexes<get<N>(idxs), T>();
            else if constexpr (static_cast<std::size_t>(get<N>(idxs)) < size_v<T>) return true;
            else return false;
          }())...};
          for (std::size_t i = 0; i < idxs.size(); ++i)
            if (!checks[i]) return false;
          return true;
        }(std::make_index_sequence<idxs.size()>{});
    };
  }
  template<std::size_t... Idx, concepts::product_type T>
  requires((Idx < size_v<T>) && ...)
  [[nodiscard]] KUMI_ABI constexpr auto reorder(T&& t)
  {
    return builder<T>::make(get<Idx>(KUMI_FWD(t))...);
  }
  template<concepts::identifier auto... Name, concepts::product_type Tuple>
  requires(requires { get<Name>(std::declval<Tuple>()); } && ...)
  KUMI_ABI constexpr auto reorder_fields(Tuple&& t)
  {
    return builder<Tuple>::make(Name = get<Name>(KUMI_FWD(t))...);
  }
  template<concepts::index_map auto Indexes, concepts::product_type T>
  requires(_::in_bound_indexes<Indexes, T>())
  [[nodiscard]] KUMI_ABI constexpr auto reindex(T&& t)
  {
    using idx_t = std::remove_cvref_t<decltype(Indexes)>;
    auto mk = [&]<auto Idx>() -> decltype(auto) {
      if constexpr (concepts::product_type<decltype(Idx)>) return reindex<Idx>(KUMI_FWD(t));
      else return get<Idx>(KUMI_FWD(t));
    };
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else if constexpr (concepts::sized_product_type<idx_t, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(mk.template operator()<get<I>(Indexes)>()...);
      }(std::make_index_sequence<size_v<idx_t>>{});
  }
  namespace result
  {
    template<concepts::product_type T, std::size_t... Idx> struct reorder
    {
      using type = decltype(kumi::reorder<Idx...>(std::declval<T>()));
    };
    template<concepts::product_type Tuple, concepts::identifier auto... Name> struct reorder_fields
    {
      using type = decltype(kumi::reorder_fields<Name...>(std::declval<Tuple>()));
    };
    template<concepts::product_type T, concepts::index_map auto Indexes> struct reindex
    {
      using type = decltype(kumi::reindex<Indexes>(std::declval<T>()));
    };
    template<concepts::product_type T, std::size_t... Idx> using reorder_t = typename reorder<T, Idx...>::type;
    template<concepts::product_type Tuple, concepts::identifier auto... Name>
    using reorder_fields_t = typename reorder_fields<Tuple, Name...>::type;
    template<concepts::product_type T, concepts::index_map auto Indexes>
    using reindex_t = typename reindex<T, Indexes>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<std::size_t N> struct reducer_t
    {
      constexpr auto operator()() const noexcept
      {
        constexpr std::size_t half = N / 2;
        struct
        {
          std::size_t count = {}, remainder = {}, idx1[half], idx2[half];
        } that{};
        that.remainder = N % 2;
        [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((that.idx1[that.count] = 2 * I, that.idx2[that.count++] = 2 * I + 1), ...);
        }(std::make_index_sequence<half>{});
        return that;
      }
    };
    template<std::size_t N> inline constexpr reducer_t<N> reducer{};
  }
  template<concepts::monoid M, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto reduce(M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return reduce(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 0>) return m.identity;
    else if constexpr (concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      constexpr auto pos = _::reducer<size_v<T>>();
      auto process = [&]<std::size_t I>(index_t<I>) {
        if constexpr (I < pos.count) return KUMI_FWD(m)(get<pos.idx1[I]>(KUMI_FWD(t)), get<pos.idx2[I]>(KUMI_FWD(t)));
        else return get<size_v<T> - 1>(KUMI_FWD(t));
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return reduce(KUMI_FWD(m), tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }
  template<concepts::monoid M, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto reduce(M&& m, T&& t, Value init)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return init;
    else return KUMI_FWD(m)(init, reduce(KUMI_FWD(m), KUMI_FWD(t)));
  }
  template<concepts::product_type T, concepts::monoid M, typename Function>
  [[nodiscard]] KUMI_ABI constexpr auto map_reduce(Function f, M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return map_reduce(f, KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 0>) return m.identity;
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      constexpr auto pos = _::reducer<size_v<T>>();
      auto process = [&]<std::size_t I>(index_t<I>) {
        if constexpr (I < pos.count)
          return KUMI_FWD(m)(invoke(f, get<pos.idx1[I]>(KUMI_FWD(t))), invoke(f, get<pos.idx2[I]>(KUMI_FWD(t))));
        else return invoke(f, get<size_v<T> - 1>(KUMI_FWD(t)));
      };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return reduce(KUMI_FWD(m), tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }
  template<concepts::monoid M, concepts::product_type T, typename Function, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto map_reduce(Function f, M&& m, T&& t, Value init)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return invoke(f, init);
    else return KUMI_FWD(m)(invoke(f, init), map_reduce(f, KUMI_FWD(m), KUMI_FWD(t)));
  }
  template<concepts::product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t, Value init)
  {
    return reduce(function::plus, KUMI_FWD(t), init);
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t)
  {
    return reduce(function::plus, KUMI_FWD(t));
  }
  template<concepts::product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t, Value init)
  {
    return reduce(function::multiplies, KUMI_FWD(t), init);
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t)
  {
    return reduce(function::multiplies, KUMI_FWD(t));
  }
  template<concepts::product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t, Value init)
  {
    return reduce(function::bit_and, KUMI_FWD(t), init);
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t)
  {
    return reduce(function::bit_and, KUMI_FWD(t));
  }
  template<concepts::product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t, Value init)
  {
    return reduce(function::bit_or, KUMI_FWD(t), init);
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t)
  {
    return reduce(function::bit_or, KUMI_FWD(t));
  }
  template<concepts::product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_xor(T&& t, Value init)
  {
    return reduce(function::bit_xor, KUMI_FWD(t), init);
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_xor(T&& t)
  {
    return reduce(function::bit_xor, KUMI_FWD(t));
  }
  namespace result
  {
    template<concepts::monoid M, concepts::product_type T, typename Value = void> struct reduce
    {
      using type = decltype(kumi::reduce(std::declval<M>(), std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::monoid M, concepts::product_type T> struct reduce<M, T>
    {
      using type = decltype(kumi::reduce(std::declval<M>(), std::declval<T>()));
    };
    template<typename F, concepts::monoid M, concepts::product_type T, typename Value = void> struct map_reduce
    {
      using type =
        decltype(kumi::map_reduce(std::declval<F>(), std::declval<M>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename F, concepts::monoid M, concepts::product_type T> struct map_reduce<F, M, T>
    {
      using type = decltype(kumi::map_reduce(std::declval<F>(), std::declval<M>(), std::declval<T>()));
    };
    template<concepts::product_type T, typename Value = void> struct sum
    {
      using type = decltype(kumi::sum(std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::product_type T> struct sum<T>
    {
      using type = decltype(kumi::sum(std::declval<T>()));
    };
    template<concepts::product_type T, typename Value = void> struct prod
    {
      using type = decltype(kumi::prod(std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::product_type T> struct prod<T>
    {
      using type = decltype(kumi::prod(std::declval<T>()));
    };
    template<concepts::product_type T, typename Value = void> struct bit_and
    {
      using type = decltype(kumi::bit_and(std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::product_type T> struct bit_and<T>
    {
      using type = decltype(kumi::bit_and(std::declval<T>()));
    };
    template<concepts::product_type T, typename Value = void> struct bit_or
    {
      using type = decltype(kumi::bit_or(std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::product_type T> struct bit_or<T>
    {
      using type = decltype(kumi::bit_or(std::declval<T>()));
    };
    template<concepts::product_type T, typename Value = void> struct bit_xor
    {
      using type = decltype(kumi::bit_xor(std::declval<T>(), std::declval<Value>()));
    };
    template<concepts::product_type T> struct bit_xor<T>
    {
      using type = decltype(kumi::bit_xor(std::declval<T>()));
    };
    template<concepts::monoid M, concepts::product_type T, typename Value = void>
    using reduce_t = typename reduce<M, T, Value>::type;
    template<typename F, concepts::monoid M, concepts::product_type T, typename Value = void>
    using map_reduce_t = typename map_reduce<F, M, T, Value>::type;
    template<concepts::product_type T, typename Value = void> using sum_t = typename sum<T, Value>::type;
    template<concepts::product_type T, typename Value = void> using prod_t = typename prod<T, Value>::type;
    template<concepts::product_type T, typename Value = void> using bit_and_t = typename bit_and<T, Value>::type;
    template<concepts::product_type T, typename Value = void> using bit_or_t = typename bit_or<T, Value>::type;
    template<concepts::product_type T, typename Value = void> using bit_xor_t = typename bit_xor<T, Value>::type;
  }
}
namespace kumi
{
  template<concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto reverse(Tuple&& t)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return builder<Tuple>::make();
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<Tuple>::make(get<(size_v<Tuple> - 1 - I)>(KUMI_FWD(t))...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }
  namespace result
  {
    template<concepts::product_type Tuple> struct reverse
    {
      using type = decltype(kumi::reverse(std::declval<Tuple>()));
    };
    template<concepts::product_type Tuple> using reverse_t = typename reverse<Tuple>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<std::size_t S, std::size_t R> struct rotate_t
    {
      KUMI_ABI constexpr auto operator()() const noexcept
      {
        struct
        {
          std::size_t t[1 + S];
        } that{};
        auto idxs = [&]<std::size_t... I>(std::index_sequence<I...>) { ((that.t[I] = (I + R) % S), ...); };
        idxs(std::make_index_sequence<S>{});
        return that;
      }
    };
    template<std::size_t S, std::size_t R> inline constexpr rotate_t<S, R> rotator{};
  }
  template<std::size_t R, concepts::product_type T> constexpr auto rotate_left(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else if constexpr ((R % size_v<T>) == 0) return KUMI_FWD(t);
    else
    {
      constexpr auto idxs = _::rotator<size_v<T>, R % size_v<T>>();
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<idxs.t[I], T>...>;
        return type{get<idxs.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T>>{});
    }
  }
  template<std::size_t R, concepts::product_type T> constexpr auto rotate_right(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else if constexpr ((R % size_v<T>) == 0) return KUMI_FWD(t);
    else
    {
      constexpr auto F = R % size_v<T>;
      constexpr auto idxs = _::rotator<size_v<T>, size_v<T> - F>();
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<idxs.t[I], T>...>;
        return type{get<idxs.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T>>{});
    }
  }
  namespace result
  {
    template<std::size_t R, concepts::product_type T> struct rotate_left
    {
      using type = decltype(kumi::rotate_left<R>(std::declval<T>()));
    };
    template<std::size_t R, concepts::product_type T> struct rotate_right
    {
      using type = decltype(kumi::rotate_right<R>(std::declval<T>()));
    };
    template<std::size_t R, concepts::product_type T> using rotate_left_t = typename rotate_left<R, T>::type;
    template<std::size_t R, concepts::product_type T> using rotate_right_t = typename rotate_right<R, T>::type;
  }
}
namespace kumi
{
  namespace _
  {
    template<typename F, typename T> struct scannable
    {
      F func;
      T acc;
      template<typename W> KUMI_ABI friend constexpr decltype(auto) operator>>(scannable&& x, scannable<F, W>&& y)
      {
        constexpr auto size = kumi::size_v<T> - 1;
        return _::scannable{x.func, kumi::push_back(x.acc, invoke(x.func, kumi::get<size>(x.acc), y.acc))};
      }
      template<typename W> KUMI_ABI friend constexpr decltype(auto) operator<<(scannable&& x, scannable<F, W>&& y)
      {
        return _::scannable{x.func, kumi::push_front(x.acc, invoke(x.func, y.acc, kumi::get<0>(x.acc)))};
      }
    };
    template<class F, class T> scannable(F const&, T&&) -> scannable<F, T>;
  }
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return inclusive_scan_left(f, values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::scannable{f, tuple{invoke(f, init, get<0>(KUMI_FWD(t)))}} >> ... >>
                _::scannable{f, get<I + 1>(KUMI_FWD(t))})
          .acc;
      }(std::make_index_sequence<size_v<T> - 1>());
    }
  }
  template<concepts::monoid M, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return inclusive_scan_left(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
    else return inclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return exclusive_scan_left(f, values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return tuple{init};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::scannable{f, tuple{init}} >> ... >> _::scannable{f, get<I>(KUMI_FWD(t))}).acc;
      }(std::make_index_sequence<size_v<T> - 1>());
    }
  }
  template<concepts::monoid M, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return exclusive_scan_left(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return tuple(m.identity, get<0>(KUMI_FWD(t)));
    else return exclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return inclusive_scan_right(KUMI_FWD(f), values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::scannable{f, tuple{invoke(f, get<size_v<T> - 1>(KUMI_FWD(t)), init)}}
                << ... << _::scannable{f, get<size_v<T> - 2 - I>(KUMI_FWD(t))})
          .acc;
      }(std::make_index_sequence<size_v<T> - 1>());
    }
  }
  template<concepts::monoid M, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return inclusive_scan_right(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
    else return inclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }
  template<typename Function, concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(Function f, T&& t, Value init)
  {
    if constexpr (concepts::record_type<T>) return exclusive_scan_right(KUMI_FWD(f), values_of(KUMI_FWD(t)), init);
    else if constexpr (concepts::sized_product_type<T, 0>) return tuple{init};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::scannable{f, tuple{init}} << ... << _::scannable{f, get<size_v<T> - 1 - I>(KUMI_FWD(t))}).acc;
      }(std::make_index_sequence<size_v<T> - 1>());
    }
  }
  template<concepts::monoid M, concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(M&& m, T&& t)
  {
    if constexpr (concepts::record_type<T>) return exclusive_scan_right(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 1>) return tuple{get<0>(KUMI_FWD(t)), m.identity};
    else return kumi::exclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }
  namespace result
  {
    template<typename Function, concepts::product_type T, typename Value = void> struct inclusive_scan_right
    {
      using type =
        decltype(kumi::inclusive_scan_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct inclusive_scan_right<Function, T>
    {
      using type = decltype(kumi::inclusive_scan_right(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void> struct exclusive_scan_right
    {
      using type =
        decltype(kumi::exclusive_scan_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct exclusive_scan_right<Function, T>
    {
      using type = decltype(kumi::exclusive_scan_right(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void> struct inclusive_scan_left
    {
      using type =
        decltype(kumi::inclusive_scan_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct inclusive_scan_left<Function, T>
    {
      using type = decltype(kumi::inclusive_scan_left(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void> struct exclusive_scan_left
    {
      using type =
        decltype(kumi::exclusive_scan_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };
    template<typename Function, concepts::product_type T> struct exclusive_scan_left<Function, T>
    {
      using type = decltype(kumi::exclusive_scan_left(std::declval<Function>(), std::declval<T>()));
    };
    template<typename Function, concepts::product_type T, typename Value = void>
    using inclusive_scan_right_t = typename inclusive_scan_right<Function, T, Value>::type;
    template<typename Function, concepts::product_type T, typename Value = void>
    using exclusive_scan_right_t = typename exclusive_scan_right<Function, T, Value>::type;
    template<typename Function, concepts::product_type T, typename Value = void>
    using inclusive_scan_left_t = typename inclusive_scan_left<Function, T, Value>::type;
    template<typename Function, concepts::product_type T, typename Value = void>
    using exclusive_scan_left_t = typename exclusive_scan_left<Function, T, Value>::type;
  }
}
namespace kumi
{
  template<std::size_t N, concepts::product_type T>
  requires(N > 0 && N <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto windows(T&& t)
  {
    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
      return kumi::generate<size_v<T> - N + 1>(
        [&](auto idx) { return kumi::extract(KUMI_FWD(t), kumi::index<idx>, kumi::index<idx + N>); });
  }
  template<std::size_t N, concepts::product_type T>
  requires(N > 0 && N <= size_v<T>)
  [[nodiscard]] KUMI_ABI constexpr auto chunks(T&& t)
  {
    constexpr auto nb = (size_v<T> + N - 1) / N;
    constexpr auto sz = size_v<T>;
    if constexpr (N == size_v<T>) return kumi::make_tuple(t);
    else
      return kumi::generate<nb>([&](auto idx) {
        constexpr auto chk_sz = (idx + 1) * N > sz ? sz - idx * N : N;
        constexpr auto chk_id = idx * N;
        return kumi::extract(KUMI_FWD(t), kumi::index<chk_id>, kumi::index<chk_id + chk_sz>);
      });
  }
  namespace result
  {
    template<std::size_t N, kumi::concepts::product_type T> struct windows
    {
      using type = decltype(kumi::windows<N>(std::declval<T>()));
    };
    template<std::size_t N, kumi::concepts::product_type T> struct chunks
    {
      using type = decltype(kumi::chunks<N>(std::declval<T>()));
    };
    template<std::size_t N, kumi::concepts::product_type T> using windows_t = typename windows<N, T>::type;
    template<std::size_t N, kumi::concepts::product_type T> using chunks_t = typename chunks<N, T>::type;
  }
}
namespace kumi
{
  template<concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto transpose(T&& t)
  requires(_::supports_transpose<T>)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        constexpr auto uz = []<typename N>(N const&, auto&& u) {
          return apply([](auto&&... m) { return builder<T>::make(get<N::value>(KUMI_FWD(m))...); }, KUMI_FWD(u));
        };
        return kumi::make_tuple(uz(index<I>, KUMI_FWD(t))...);
      }(std::make_index_sequence<size_v<raw_element_t<0, T>>>());
    }
  }
  namespace result
  {
    template<concepts::product_type T> struct transpose
    {
      using type = decltype(kumi::transpose(std::declval<T>()));
    };
    template<concepts::product_type T> using transpose_t = typename transpose<T>::type;
  }
}
namespace kumi
{
  template<template<typename...> typename Traits,
           concepts::product_type Tuple,
           typename Seq = std::make_index_sequence<size<Tuple>::value>>
  struct apply_traits;
  template<template<typename...> typename Traits, concepts::product_type Tuple, std::size_t... Is>
  requires(requires { typename Traits<element_t<Is, Tuple>...>::type; })
  struct apply_traits<Traits, Tuple, std::index_sequence<Is...>>
  {
    using type = typename Traits<element_t<Is, Tuple>...>::type;
  };
  template<template<typename...> typename Traits, concepts::product_type Tuple>
  using apply_traits_t = typename apply_traits<Traits, Tuple>::type;
  template<template<typename...> typename Traits,
           concepts::product_type Tuple,
           typename Seq = std::make_index_sequence<size<Tuple>::value>>
  struct map_traits;
  template<template<typename...> typename Traits, concepts::product_type Tuple, std::size_t... Is>
  requires(requires { typename Traits<element_t<Is, Tuple>>::type; } && ...)
  struct map_traits<Traits, Tuple, std::index_sequence<Is...>>
  {
    using type = tuple<typename Traits<element_t<Is, Tuple>>::type...>;
  };
  template<template<typename...> typename Traits, concepts::product_type Tuple>
  using map_traits_t = typename map_traits<Traits, Tuple>::type;
}
namespace kumi
{
  namespace _
  {
    template<typename T> struct make_unique
    {
      T acc;
      template<typename W> KUMI_ABI friend constexpr decltype(auto) operator|(make_unique&& x, make_unique<W>&& y)
      {
        constexpr auto value = []<std::size_t... I>(std::index_sequence<I...>) {
          if constexpr (concepts::record_type<T>) return (all_uniques_v<_::type_of_t<W>, raw_element_t<I, T>...>);
          else return (all_uniques_v<W, element_t<I, T>...>);
        }(std::make_index_sequence<size_v<T>>{});
        if constexpr (value)
          return [&]<std::size_t... I>(std::index_sequence<I...>) {
            using res_t = builder_make_t<T, element_t<I, T>..., W>;
            return _::make_unique{res_t{get<I>(KUMI_FWD(x.acc))..., KUMI_FWD(y.acc)}};
          }(std::make_index_sequence<size_v<T>>{});
        else return KUMI_FWD(x);
      }
    };
    template<typename W> make_unique(W&& w) -> make_unique<W>;
    struct uniquable
    {
      template<concepts::product_type T> [[nodiscard]] KUMI_ABI consteval auto operator()(as<T>) const noexcept
      {
        struct
        {
          std::size_t count{1}, t[size_v<T>];
        } that{};
        that.t[0] = 0;
        [&]<std::size_t... I>(std::index_sequence<I...>) {
          (
            [&] {
              constexpr auto L = I;
              constexpr auto R = I + 1;
              if constexpr (!std::is_same_v<raw_element_t<L, T>, raw_element_t<R, T>>) that.t[that.count++] = R;
            }(),
            ...);
        }(std::make_index_sequence<size_v<T> - 1>{});
        return that;
      }
    };
    inline constexpr uniquable uniqued{};
  }
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto unique(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else
    {
      constexpr auto pos = _::uniqued(as<T>{});
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using ret_t = builder_make_t<T, element_t<pos.t[I], T>...>;
        return ret_t{get<pos.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<pos.count>{});
    }
  };
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_unique(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return t;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (_::make_unique{builder_make_t<T, element_t<0, T>>{get<0>(KUMI_FWD(t))}} | ... |
                _::make_unique<element_t<I + 1, T>>{get<I + 1>(KUMI_FWD(t))})
          .acc;
      }(std::make_index_sequence<size_v<T> - 1>{});
    }
  }
  namespace result
  {
    template<concepts::product_type T> struct unique
    {
      using type = decltype(kumi::unique(std::declval<T>()));
    };
    template<concepts::product_type T> struct all_unique
    {
      using type = decltype(kumi::all_unique(std::declval<T>()));
    };
    template<concepts::product_type T> using unique_t = typename unique<T>::type;
    template<concepts::product_type T> using all_unique_t = typename all_unique<T>::type;
  }
}
namespace kumi
{
  namespace _
  {
    struct zipper_t
    {
      template<std::size_t Size, concepts::product_type T>
      KUMI_ABI constexpr auto operator()(index_t<Size> const&, T&& t) const noexcept
      {
        if constexpr (concepts::sized_product_type<T, 0>) return t;
        else
        {
          constexpr auto uz = []<typename N>(N const&, auto&& u) {
            return apply(
              [](auto&&... m) {
                auto zip_ = [&]<concepts::product_type V>(V&& v) {
                  if constexpr (size_v<V> <= N::value) return none;
                  else return get<N::value>(KUMI_FWD(v));
                };
                return builder<element_t<0, T>>::make(zip_(KUMI_FWD(m))...);
              },
              KUMI_FWD(u));
          };
          return [&]<std::size_t... I>(std::index_sequence<I...>) {
            return kumi::make_tuple(uz(index_t<I>{}, KUMI_FWD(t))...);
          }(std::make_index_sequence<Size>());
        }
      }
    };
    inline constexpr zipper_t zipper{};
    template<typename T0, typename... Ts> consteval std::size_t min_size_v()
    {
      std::size_t result = size_v<T0>;
      if constexpr (sizeof...(Ts) == 0) return result;
      else return ((result = result < size_v<Ts> ? result : size_v<Ts>), ...);
    };
    template<typename T0, typename... Ts> consteval std::size_t max_size_v()
    {
      std::size_t result = size_v<T0>;
      if constexpr (sizeof...(Ts) == 0) return result;
      else return ((result = result > size_v<Ts> ? result : size_v<Ts>), ...);
    };
  }
  template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    return _::zipper(index<size_v<T0>>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_min(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t min = _::min_size_v<T0, Ts...>();
    return _::zipper(index<min>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }
  template<concepts::product_type T0, concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip_max(T0&& t0, Ts&&... ts)
  requires(concepts::follows_same_semantic<T0, Ts...>)
  {
    constexpr std::size_t max = _::max_size_v<T0, Ts...>();
    return _::zipper(index<max>, kumi::forward_as_tuple(KUMI_FWD(t0), KUMI_FWD(ts)...));
  }
  namespace result
  {
    template<concepts::product_type T0, concepts::sized_product_type<size_v<T0>>... Ts> struct zip
    {
      using type = decltype(kumi::zip(std::declval<T0>(), std::declval<Ts>()...));
    };
    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_min
    {
      using type = decltype(kumi::zip_min(std::declval<T0>(), std::declval<Ts>()...));
    };
    template<concepts::product_type T0, concepts::product_type... Ts> struct zip_max
    {
      using type = decltype(kumi::zip_max(std::declval<T0>(), std::declval<Ts>()...));
    };
    template<concepts::product_type T0, concepts::product_type... Ts> using zip_t = typename zip<T0, Ts...>::type;
    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_min_t = typename zip_min<T0, Ts...>::type;
    template<concepts::product_type T0, concepts::product_type... Ts>
    using zip_max_t = typename zip_max<T0, Ts...>::type;
  }
}
