//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>
#include <utility>

namespace kumi::_
{
  //================================================================================================
  // We optimize layout for tuple of size 1->10 and for homogeneous layout
  // This shaves a bit of compile time and it makes symbol length of tuple NTTP shorter
  //================================================================================================

  // We usually don't want to optimize tuple of references
  template<typename... Ts> inline constexpr bool no_references = (true && ... && !std::is_reference_v<Ts>);

  // [[no_unique_address]] is to unstable at the moment, will go through the standard path
  template<typename... Ts> inline constexpr bool no_empty = (true && ... && !std::is_empty_v<Ts>);

  // We care about homogeneous tuple
  template<typename T0, typename... Ts> inline constexpr bool all_the_same = (true && ... && std::is_same_v<T0, Ts>);

  //================================================================================================
  // Optimized binder for homogeneous layout if:
  //  - Size is greater than 1
  //  - All types are the same and non-reference
  //================================================================================================
  template<typename T0, int N> struct binder_n
  {
    T0 members[N];
  };

  template<int... Is, typename T0, typename T1, typename... Ts>
  requires(all_the_same<T0, T1, Ts...> && no_references<T0, T1, Ts...> && no_empty<T0, T1, Ts...>)
  struct make_binder<std::integer_sequence<int, Is...>, T0, T1, Ts...>
  {
    using type = binder_n<T0, 2 + sizeof...(Ts)>;
  };

  template<std::size_t I, typename T0, int N> KUMI_ABI constexpr auto& get_leaf(binder_n<T0, N>& arg) noexcept
  {
    return arg.members[I];
  }

  template<std::size_t I, typename T0, int N>
  KUMI_ABI constexpr auto const& get_leaf(binder_n<T0, N> const& arg) noexcept
  {
    return arg.members[I];
  }

  template<std::size_t I, typename T0, int N> KUMI_ABI constexpr auto&& get_leaf(binder_n<T0, N>&& arg) noexcept
  {
    return static_cast<T0&&>(arg.members[I]);
  }

  template<std::size_t I, typename T0, int N>
  KUMI_ABI constexpr auto const&& get_leaf(binder_n<T0, N> const&& arg) noexcept
  {
    return static_cast<T0 const&&>(arg.members[I]);
  }

  //================================================================================================
  // Optimized binder for 1->10 elements, none being reference
  //================================================================================================
  template<typename T>
  requires(no_references<T> && no_empty<T>)
  struct binder<std::integer_sequence<int, 0>, T>
  {
    using kumi_specific_layout = void;
    using member0_type = T;
    member0_type member0;
  };

  template<typename T0, typename T1>
  requires(no_references<T0, T1> && no_empty<T0, T1>)
  struct binder<std::integer_sequence<int, 0, 1>, T0, T1>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    member0_type member0;
    member1_type member1;
  };

  template<typename T0, typename T1, typename T2>
  requires(no_references<T0, T1, T2> && no_empty<T0, T1, T2>)
  struct binder<std::integer_sequence<int, 0, 1, 2>, T0, T1, T2>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    member0_type member0;
    member1_type member1;
    member2_type member2;
  };

  template<typename T0, typename T1, typename T2, typename T3>
  requires(no_references<T0, T1, T2, T3> && no_empty<T0, T1, T2, T3>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3>, T0, T1, T2, T3>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
  };

  template<typename T0, typename T1, typename T2, typename T3, typename T4>
  requires(no_references<T0, T1, T2, T3, T4> && no_empty<T0, T1, T2, T3, T4>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4>, T0, T1, T2, T3, T4>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
  };

  template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
  requires(no_references<T0, T1, T2, T3, T4, T5> && no_empty<T0, T1, T2, T3, T4, T5>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4, 5>, T0, T1, T2, T3, T4, T5>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    using member5_type = T5;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
    member5_type member5;
  };

  template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
  requires(no_references<T0, T1, T2, T3, T4, T5, T6> && no_empty<T0, T1, T2, T3, T4, T5, T6>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6>, T0, T1, T2, T3, T4, T5, T6>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    using member5_type = T5;
    using member6_type = T6;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
    member5_type member5;
    member6_type member6;
  };

  template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
  requires(no_references<T0, T1, T2, T3, T4, T5, T6, T7> && no_empty<T0, T1, T2, T3, T4, T5, T6, T7>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7>, T0, T1, T2, T3, T4, T5, T6, T7>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    using member5_type = T5;
    using member6_type = T6;
    using member7_type = T7;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
    member5_type member5;
    member6_type member6;
    member7_type member7;
  };

  template<typename T0,
           typename T1,
           typename T2,
           typename T3,
           typename T4,
           typename T5,
           typename T6,
           typename T7,
           typename T8>
  requires(no_references<T0, T1, T2, T3, T4, T5, T6, T7, T8> && no_empty<T0, T1, T2, T3, T4, T5, T6, T7, T8>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8>, T0, T1, T2, T3, T4, T5, T6, T7, T8>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    using member5_type = T5;
    using member6_type = T6;
    using member7_type = T7;
    using member8_type = T8;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
    member5_type member5;
    member6_type member6;
    member7_type member7;
    member8_type member8;
  };

  template<typename T0,
           typename T1,
           typename T2,
           typename T3,
           typename T4,
           typename T5,
           typename T6,
           typename T7,
           typename T8,
           typename T9>
  requires(no_references<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> && no_empty<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>)
  struct binder<std::integer_sequence<int, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9>, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>
  {
    using kumi_specific_layout = void;
    using member0_type = T0;
    using member1_type = T1;
    using member2_type = T2;
    using member3_type = T3;
    using member4_type = T4;
    using member5_type = T5;
    using member6_type = T6;
    using member7_type = T7;
    using member8_type = T8;
    using member9_type = T9;
    member0_type member0;
    member1_type member1;
    member2_type member2;
    member3_type member3;
    member4_type member4;
    member5_type member5;
    member6_type member6;
    member7_type member7;
    member8_type member8;
    member9_type member9;
  };

  //================================================================================================
  // Optimized get_leaf<index> for all binders of 1->10 elements
  //================================================================================================
  template<std::size_t I, typename Binder>
  requires requires(Binder) { typename Binder::kumi_specific_layout; }
  KUMI_ABI constexpr auto& get_leaf(Binder& arg) noexcept
  {
    if constexpr (I == 0) return arg.member0;
    if constexpr (I == 1) return arg.member1;
    if constexpr (I == 2) return arg.member2;
    if constexpr (I == 3) return arg.member3;
    if constexpr (I == 4) return arg.member4;
    if constexpr (I == 5) return arg.member5;
    if constexpr (I == 6) return arg.member6;
    if constexpr (I == 7) return arg.member7;
    if constexpr (I == 8) return arg.member8;
    if constexpr (I == 9) return arg.member9;
  }

  template<std::size_t I, typename Binder>
  requires requires(Binder) { typename Binder::kumi_specific_layout; }
  KUMI_ABI constexpr auto&& get_leaf(Binder&& arg) noexcept
  {
    if constexpr (I == 0) return static_cast<typename Binder::member0_type&&>(arg.member0);
    if constexpr (I == 1) return static_cast<typename Binder::member1_type&&>(arg.member1);
    if constexpr (I == 2) return static_cast<typename Binder::member2_type&&>(arg.member2);
    if constexpr (I == 3) return static_cast<typename Binder::member3_type&&>(arg.member3);
    if constexpr (I == 4) return static_cast<typename Binder::member4_type&&>(arg.member4);
    if constexpr (I == 5) return static_cast<typename Binder::member5_type&&>(arg.member5);
    if constexpr (I == 6) return static_cast<typename Binder::member6_type&&>(arg.member6);
    if constexpr (I == 7) return static_cast<typename Binder::member7_type&&>(arg.member7);
    if constexpr (I == 8) return static_cast<typename Binder::member8_type&&>(arg.member8);
    if constexpr (I == 9) return static_cast<typename Binder::member9_type&&>(arg.member9);
  }

  template<std::size_t I, typename Binder>
  requires requires(Binder) { typename Binder::kumi_specific_layout; }
  KUMI_ABI constexpr auto const&& get_leaf(Binder const&& arg) noexcept
  {
    if constexpr (I == 0) return static_cast<typename Binder::member0_type const&&>(arg.member0);
    if constexpr (I == 1) return static_cast<typename Binder::member1_type const&&>(arg.member1);
    if constexpr (I == 2) return static_cast<typename Binder::member2_type const&&>(arg.member2);
    if constexpr (I == 3) return static_cast<typename Binder::member3_type const&&>(arg.member3);
    if constexpr (I == 4) return static_cast<typename Binder::member4_type const&&>(arg.member4);
    if constexpr (I == 5) return static_cast<typename Binder::member5_type const&&>(arg.member5);
    if constexpr (I == 6) return static_cast<typename Binder::member6_type const&&>(arg.member6);
    if constexpr (I == 7) return static_cast<typename Binder::member7_type const&&>(arg.member7);
    if constexpr (I == 8) return static_cast<typename Binder::member8_type const&&>(arg.member8);
    if constexpr (I == 9) return static_cast<typename Binder::member9_type const&&>(arg.member9);
  }

  template<std::size_t I, typename Binder>
  requires requires(Binder) { typename Binder::kumi_specific_layout; }
  KUMI_ABI constexpr auto const& get_leaf(Binder const& arg) noexcept
  {
    if constexpr (I == 0) return arg.member0;
    if constexpr (I == 1) return arg.member1;
    if constexpr (I == 2) return arg.member2;
    if constexpr (I == 3) return arg.member3;
    if constexpr (I == 4) return arg.member4;
    if constexpr (I == 5) return arg.member5;
    if constexpr (I == 6) return arg.member6;
    if constexpr (I == 7) return arg.member7;
    if constexpr (I == 8) return arg.member8;
    if constexpr (I == 9) return arg.member9;
  }

  //================================================================================================
  // Optimized get_leaf<type> for all binders of 1->10 elements
  //================================================================================================
  template<typename T, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && can_get_field_by_type<T, Ts...> &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto& get_leaf(binder<ISeq, Ts...>& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_type_v<T, Ts...>;
    return get_leaf<idx>(KUMI_FWD(arg));
  }

  template<typename T, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && can_get_field_by_type<T, Ts...> &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto&& get_leaf(binder<ISeq, Ts...>&& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_type_v<T, Ts...>;
    return get_leaf<idx>(KUMI_FWD(arg));
  }

  template<typename T, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && can_get_field_by_type<T, Ts...> &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto const&& get_leaf(binder<ISeq, Ts...> const&& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_type_v<T, Ts...>;
    return get_leaf<idx>(KUMI_FWD(arg));
  }

  template<typename T, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && can_get_field_by_type<T, Ts...> &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto const& get_leaf(binder<ISeq, Ts...> const& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_type_v<T, Ts...>;
    return get_leaf<idx>(KUMI_FWD(arg));
  }

  //================================================================================================
  // Optimized get_leaf<name> for all binders of 1->10 elements
  //================================================================================================
  template<kumi::str Name, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && (contains_field<Name, Ts...>()) &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto& get_leaf(binder<ISeq, Ts...>& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_value_v<Name, Ts...>;
    if constexpr (idx == 0) return arg.member0.value;
    if constexpr (idx == 1) return arg.member1.value;
    if constexpr (idx == 2) return arg.member2.value;
    if constexpr (idx == 3) return arg.member3.value;
    if constexpr (idx == 4) return arg.member4.value;
    if constexpr (idx == 5) return arg.member5.value;
    if constexpr (idx == 6) return arg.member6.value;
    if constexpr (idx == 7) return arg.member7.value;
    if constexpr (idx == 8) return arg.member8.value;
    if constexpr (idx == 9) return arg.member9.value;
  }

  template<kumi::str Name, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && (contains_field<Name, Ts...>()) &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto&& get_leaf(binder<ISeq, Ts...>&& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_value_v<Name, Ts...>;
    if constexpr (idx == 0) return static_cast<typename binder<ISeq, Ts...>::member0_type::type&&>(arg.member0.value);
    if constexpr (idx == 1) return static_cast<typename binder<ISeq, Ts...>::member1_type::type&&>(arg.member1.value);
    if constexpr (idx == 2) return static_cast<typename binder<ISeq, Ts...>::member2_type::type&&>(arg.member2.value);
    if constexpr (idx == 3) return static_cast<typename binder<ISeq, Ts...>::member3_type::type&&>(arg.member3.value);
    if constexpr (idx == 4) return static_cast<typename binder<ISeq, Ts...>::member4_type::type&&>(arg.member4.value);
    if constexpr (idx == 5) return static_cast<typename binder<ISeq, Ts...>::member5_type::type&&>(arg.member5.value);
    if constexpr (idx == 6) return static_cast<typename binder<ISeq, Ts...>::member6_type::type&&>(arg.member6.value);
    if constexpr (idx == 7) return static_cast<typename binder<ISeq, Ts...>::member7_type::type&&>(arg.member7.value);
    if constexpr (idx == 8) return static_cast<typename binder<ISeq, Ts...>::member8_type::type&&>(arg.member8.value);
    if constexpr (idx == 9) return static_cast<typename binder<ISeq, Ts...>::member9_type::type&&>(arg.member9.value);
  }

  template<kumi::str Name, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && (contains_field<Name, Ts...>()) &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto const&& get_leaf(binder<ISeq, Ts...> const&& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_value_v<Name, Ts...>;
    if constexpr (idx == 0)
      return static_cast<typename binder<ISeq, Ts...>::member0_type::type const&&>(arg.member0.value);
    if constexpr (idx == 1)
      return static_cast<typename binder<ISeq, Ts...>::member1_type::type const&&>(arg.member1.value);
    if constexpr (idx == 2)
      return static_cast<typename binder<ISeq, Ts...>::member2_type::type const&&>(arg.member2.value);
    if constexpr (idx == 3)
      return static_cast<typename binder<ISeq, Ts...>::member3_type::type const&&>(arg.member3.value);
    if constexpr (idx == 4)
      return static_cast<typename binder<ISeq, Ts...>::member4_type::type const&&>(arg.member4.value);
    if constexpr (idx == 5)
      return static_cast<typename binder<ISeq, Ts...>::member5_type::type const&&>(arg.member5.value);
    if constexpr (idx == 6)
      return static_cast<typename binder<ISeq, Ts...>::member6_type::type const&&>(arg.member6.value);
    if constexpr (idx == 7)
      return static_cast<typename binder<ISeq, Ts...>::member7_type::type const&&>(arg.member7.value);
    if constexpr (idx == 8)
      return static_cast<typename binder<ISeq, Ts...>::member8_type::type const&&>(arg.member8.value);
    if constexpr (idx == 9)
      return static_cast<typename binder<ISeq, Ts...>::member9_type::type const&&>(arg.member9.value);
  }

  template<kumi::str Name, typename ISeq, typename... Ts>
  requires(sizeof...(Ts) <= 10) && (contains_field<Name, Ts...>()) &&
          requires(binder<ISeq, Ts...>) { typename binder<ISeq, Ts...>::kumi_specific_layout; }
  KUMI_ABI constexpr auto const& get_leaf(binder<ISeq, Ts...> const& arg) noexcept
  {
    constexpr std::size_t idx = get_index_by_value_v<Name, Ts...>;
    if constexpr (idx == 0) return arg.member0.value;
    if constexpr (idx == 1) return arg.member1.value;
    if constexpr (idx == 2) return arg.member2.value;
    if constexpr (idx == 3) return arg.member3.value;
    if constexpr (idx == 4) return arg.member4.value;
    if constexpr (idx == 5) return arg.member5.value;
    if constexpr (idx == 6) return arg.member6.value;
    if constexpr (idx == 7) return arg.member7.value;
    if constexpr (idx == 8) return arg.member8.value;
    if constexpr (idx == 9) return arg.member9.value;
  }
}
