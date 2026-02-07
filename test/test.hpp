//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>
#include <string>
#include <kumi/kumi.hpp>

using namespace kumi::literals;

//==============================================================================================
//! Custom Keywords for record/tuple construction
//==============================================================================================

template<typename T> struct small_type : std::bool_constant<(sizeof(T) < 4)>
{
};

inline constexpr auto custom_ = ::kumi::identifier("custom"_n);
inline constexpr auto coord_ = "coord"_id;

inline constexpr auto value_ = ::kumi::identifier("value_"_n, kumi::only<float>);
inline constexpr auto name_ = ::kumi::identifier("name_"_n, kumi::only<std::string>);

inline constexpr auto factor_ = ::kumi::identifier("factor"_n, kumi::if_<small_type>);

inline constexpr auto is_transparent_ = "is_transparent_"_id = std::bool_constant<true>{};
inline constexpr auto is_modal_ = "is_modal_"_id = std::bool_constant<true>{};

struct unrolling : kumi::identifier<unrolling>
{
  template<int N> constexpr auto operator=(std::integral_constant<int, N> const&) const noexcept
  {
    return kumi::field<unrolling, std::integral_constant<int, N>>{};
  }

  // std::ostream& display(std::ostream& os, auto v) const { return os << "Unroll Factor: " << v; }
};

template<int N> inline constexpr auto unroll = (unrolling{} = std::integral_constant<int, N>{});

//==============================================================================================
//! Derived types from tuple/record
//==============================================================================================
template<typename T, bool isHomogeneous> struct trivial_product_type : kumi::tuple<T, T, T, T, T>
{
};

template<typename T> struct trivial_product_type<T, false> : kumi::tuple<T, T, T, T, void*>
{
};

template<typename T, bool B> struct std::tuple_size<trivial_product_type<T, B>> : std::integral_constant<std::size_t, 5>
{
};

template<std::size_t N, typename T, bool B> struct std::tuple_element<N, trivial_product_type<T, B>>
{
  using type = T;
};

template<typename T> struct std::tuple_element<4, trivial_product_type<T, false>>
{
  using type = void*;
};

/// Records are never homogeneous in the sens of kumi but we need to test
template<typename T, bool isHomogeneous>
struct trivial_record_type : kumi::record<kumi::field<kumi::name<"a">, T>,
                                          kumi::field<kumi::name<"b">, T>,
                                          kumi::field<kumi::name<"c">, T>,
                                          kumi::field<kumi::name<"d">, T>,
                                          kumi::field<kumi::name<"e">, T>>
{
};

template<typename T>
struct trivial_record_type<T, false> : kumi::record<kumi::field<kumi::name<"a">, T>,
                                                    kumi::field<kumi::name<"b">, T>,
                                                    kumi::field<kumi::name<"c">, T>,
                                                    kumi::field<kumi::name<"d">, T>,
                                                    kumi::field<kumi::name<"e">, void*>>
{
};

template<typename T, bool B> struct std::tuple_size<trivial_record_type<T, B>> : std::integral_constant<std::size_t, 5>
{
};

template<typename T, bool B> struct std::tuple_element<0, trivial_record_type<T, B>>
{
  using type = kumi::field<kumi::name<"a">, T>;
};

template<typename T, bool B> struct std::tuple_element<1, trivial_record_type<T, B>>
{
  using type = kumi::field<kumi::name<"b">, T>;
};

template<typename T, bool B> struct std::tuple_element<2, trivial_record_type<T, B>>
{
  using type = kumi::field<kumi::name<"c">, T>;
};

template<typename T, bool B> struct std::tuple_element<3, trivial_record_type<T, B>>
{
  using type = kumi::field<kumi::name<"d">, T>;
};

template<typename T> struct std::tuple_element<4, trivial_record_type<T, true>>
{
  using type = kumi::field<kumi::name<"e">, T>;
};

template<typename T> struct std::tuple_element<4, trivial_record_type<T, false>>
{
  using type = kumi::field<kumi::name<"e">, void*>;
};

//==============================================================================================
//! Adapted types for tuple/record type semantic
//==============================================================================================
struct tuple_box
{
  int i;
  float f;
  char c;

  template<std::size_t I>
  friend constexpr auto const& get(tuple_box const& s) noexcept
  requires(I < 3)
  {
    if constexpr (I == 0) return s.i;
    if constexpr (I == 1) return s.f;
    if constexpr (I == 2) return s.c;
  }

  template<std::size_t I>
  friend constexpr auto& get(tuple_box& s) noexcept
  requires(I < 3)
  {
    if constexpr (I == 0) return s.i;
    if constexpr (I == 1) return s.f;
    if constexpr (I == 2) return s.c;
  }
};

template<> struct std::tuple_size<tuple_box> : std::integral_constant<std::size_t, 3>
{
};

template<> struct std::tuple_element<0, tuple_box>
{
  using type = int;
};

template<> struct std::tuple_element<1, tuple_box>
{
  using type = float;
};

template<> struct std::tuple_element<2, tuple_box>
{
  using type = char;
};

struct record_box
{
  using is_record_type = void;

  int i;
  float f;
  char c;

  template<std::size_t I>
  friend constexpr decltype(auto) get(record_box const& s) noexcept
  requires(I < 3)
  {
    if constexpr (I == 0) return kumi::capture_field<"i"_n>(s.i);
    if constexpr (I == 1) return kumi::capture_field<"f"_n>(s.f);
    if constexpr (I == 2) return kumi::capture_field<"c"_n>(s.c);
  }

  template<std::size_t I>
  friend constexpr decltype(auto) get(record_box& s) noexcept
  requires(I < 3)
  {
    if constexpr (I == 0) return kumi::capture_field<"i"_n>(s.i);
    if constexpr (I == 1) return kumi::capture_field<"f"_n>(s.f);
    if constexpr (I == 2) return kumi::capture_field<"c"_n>(s.c);
  }
};

template<> struct std::tuple_size<record_box> : std::integral_constant<std::size_t, 3>
{
};

template<> struct std::tuple_element<0, record_box>
{
  using type = kumi::field<kumi::name<"i">, int>;
};

template<> struct std::tuple_element<1, record_box>
{
  using type = kumi::field<kumi::name<"f">, float>;
};

template<> struct std::tuple_element<2, record_box>
{
  using type = kumi::field<kumi::name<"c">, char>;
};

struct arbitrary_struct
{
  std::size_t n;
  double data;
  constexpr auto operator<=>(arbitrary_struct const&) const = default;
};

//==============================================================================================
//! Trackers for construction behavior
//==============================================================================================
enum class operations
{
  def_ctor,
  move_ctor,
  move_assign,
  copy_ctor,
  copy_assign
};

struct ctor_tracker
{
  operations value = operations::def_ctor;
  ctor_tracker() = default;

  ctor_tracker(ctor_tracker&&) : value(operations::move_ctor) {}

  ctor_tracker(ctor_tracker const&) : value(operations::copy_ctor) {}

  ctor_tracker& operator=(ctor_tracker&&)
  {
    value = operations::move_assign;
    return *this;
  }

  ctor_tracker& operator=(ctor_tracker const&)
  {
    value = operations::copy_assign;
    return *this;
  }
};

template<kumi::concepts::product_type T> operations move_ctor_fwd(T&& t)
{
  ctor_tracker local = std::forward<T>(t)[kumi::index<0>];
  return local.value;
}

template<kumi::concepts::product_type T> operations copy_ctor_fwd(T&& t)
{
  ctor_tracker local = t[kumi::index<0>];
  return local.value;
}

template<kumi::concepts::product_type T> operations move_assign_fwd(T&& t)
{
  ctor_tracker local;
  local = std::forward<T>(t)[kumi::index<0>];
  return local.value;
}

template<kumi::concepts::product_type T> operations copy_assign_fwd(T&& t)
{
  ctor_tracker local;
  local = t[kumi::index<0>];
  return local.value;
}

template<kumi::concepts::record_type R> operations move_ctor_fwd(R&& r)
{
  ctor_tracker local = std::forward<R>(r)["a"_n];
  return local.value;
}

template<kumi::concepts::record_type R> operations copy_ctor_fwd(R&& r)
{
  ctor_tracker local = r["b"_n];
  return local.value;
}

template<kumi::concepts::record_type R> operations move_assign_fwd(R&& r)
{
  ctor_tracker local;
  local = std::forward<R>(r)["c"_n];
  return local.value;
}

template<kumi::concepts::record_type R> operations copy_assign_fwd(R&& r)
{
  ctor_tracker local;
  local = r["d"_n];
  return local.value;
}

//==============================================================================================
//! Type to ensure the correctness of move semantic
//==============================================================================================
template<typename T, typename Enable = void> struct is_moveonly_i : std::false_type
{
};

template<typename T> struct is_moveonly_i<T, typename T::is_moveonly_i> : std::true_type
{
};

template<typename T> struct is_not_moveonly_i : std::bool_constant<!is_moveonly_i<T>::value>
{
};

template<typename T> using is_moveonly_type = is_moveonly_i<std::remove_cvref_t<T>>;
template<typename T> using is_not_moveonly_type = is_not_moveonly_i<std::remove_cvref_t<T>>;

struct moveonly
{
  using is_moveonly = void;
  moveonly() = default;
  moveonly(moveonly const&) = delete;
  moveonly(moveonly&&) = default;
  moveonly& operator=(moveonly const&) = delete;
  moveonly& operator=(moveonly&&) = default;
};

struct empty
{
};
