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
  namespace _
  {
    template<typename Seq, typename... Ts> struct multiset;

    template<std::size_t I, typename T> struct multiset<std::index_sequence<I>, T>
    {
      consteval auto operator()(std::type_identity<T>) const noexcept
      {
        return std::integral_constant<std::size_t, I>{};
      }
    };

    template<std::size_t I, std::size_t... Is, typename T, typename... Ts>
    struct multiset<std::index_sequence<I, Is...>, T, Ts...> : kumi::_::multiset<std::index_sequence<Is...>, Ts...>
    {
      consteval auto operator()(std::type_identity<T>) const noexcept
      {
        return std::integral_constant<std::size_t, I>{};
      }

      using kumi::_::multiset<std::index_sequence<Is...>, Ts...>::operator();
    };

    template<typename... Ts> using make_multiset_t = typename kumi::_::multiset<Ts...>;

    template<typename T, bool... Bs> extern T unique_index_sequence;

    template<std::size_t... I, bool... Bs>
    extern std::index_sequence<kumi::_::nth_pos_v<I, Bs...>...> unique_index_sequence<std::index_sequence<I...>, Bs...>;

    template<typename T, bool... Bs> extern T select_index_sequence;

    template<std::size_t... I, bool... Bs>
    extern std::index_sequence<kumi::_::nth_pos_v<I, Bs...>...> select_index_sequence<std::index_sequence<I...>, Bs...>;

    template<typename T, bool... Bs> extern T adjacent_index_sequence;

    template<std::size_t... I, bool... Bs>
    extern std::index_sequence<0, (kumi::_::nth_pos_v<I, Bs...> + 1)...>
      adjacent_index_sequence<std::index_sequence<I...>, Bs...>;
  }

  namespace function
  {
    //==================================================================================================================
    /**
      @ingroup kumi_functional

      @typedef unique_index_sequence
      @brief A helper alias template generating the index map associated to the unique operations.

      @groupheader{Header file}
      @code
      #include <kumi/functional/set.hpp>
      @endcode

      @groupheader{Call Signature}
      @code
        template<bool... Bs>
        using unique_index_sequence;
      @endcode

      @subgroupheader{Template Parameters}
        - `Bs`: Compile-time flags, one per input element, set to `true` when the element is kept

      @subgroupheader{Return value}
        A `std::index_sequence` containing, in increasing order, the positions of the `true` flags in `Bs`.
        For `Bs = <true, false, true, true>`, the result is `std::index_sequence<0, 2, 3>`.
    **/
    //==================================================================================================================
    template<bool... Bs>
    using unique_index_sequence =
      decltype(kumi::_::unique_index_sequence<std::make_index_sequence<(Bs + ... + 0)>, Bs...>);

    //==================================================================================================================
    /**
      @ingroup kumi_functional

      @typedef select_index_sequence
      @brief A helper alias template generating the positions of the `true` flags in a pack of booleans.

      @groupheader{Header file}
      @code
      #include <kumi/functional/set.hpp>
      @endcode

      @groupheader{Call Signature}
      @code
        template<bool... Bs>
        using select_index_sequence;
      @endcode

      @subgroupheader{Template Parameters}
        - `Bs`: Compile-time flags, one per input element, set to `true` when the element is selected

      @subgroupheader{Return value}
        A `std::index_sequence` containing, in increasing order, the positions of the `true` flags.
        For `Bs = <true, false, true, true>`, the result is `std::index_sequence<0, 2, 3>`.
    **/
    //==================================================================================================================
    template<bool... Bs>
    using select_index_sequence =
      decltype(kumi::_::select_index_sequence<std::make_index_sequence<(Bs + ... + 0)>, Bs...>);

    //==================================================================================================================
    /**
      @ingroup kumi_functional

      @typedef adjacent_index_sequence
      @brief A helper alias template generating the index map associated to the adjacent unicity operation.

      @groupheader{Header file}
      @code
      #include <kumi/functional/set.hpp>
      @endcode

      @groupheader{Call Signature}
      @code
        template<bool... Bs>
        using adjacent_index_sequence;
      @endcode

      @subgroupheader{Template Parameters}
        - `Bs`: Compile-time flags, one per adjacent pair, set to `true` when the pair differs

      @subgroupheader{Return value}
        A `std::index_sequence` made of `0` followed by the position of each `true` flag shifted by one,
        i.e. the index of each element that differs from its predecessor.
        For `Bs = <false, true, true>`, the result is `std::index_sequence<0, 2, 3>`.
    **/
    //==================================================================================================================
    template<bool... Bs>
    using adjacent_index_sequence =
      decltype(kumi::_::adjacent_index_sequence<std::make_index_sequence<(Bs + ... + 0)>, Bs...>);
  }
}
