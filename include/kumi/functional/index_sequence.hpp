//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::_
{
  template<typename T, typename...> extern T cat_index_sequence;

  template<std::size_t... I, std::size_t... J>
  extern std::index_sequence<I..., J...> cat_index_sequence<std::index_sequence<I...>, std::index_sequence<J...>>;

  template<typename T, typename... Ts> using cat_index_sequence_t = decltype(kumi::_::cat_index_sequence<T, Ts...>);

  template<std::size_t... I, std::size_t... J, typename... Ts>
  extern cat_index_sequence_t<std::index_sequence<I..., J...>, Ts...>
    cat_index_sequence<std::index_sequence<I...>, std::index_sequence<J...>, Ts...>;

  template<std::size_t, typename T> extern T fill_index_sequence;

  template<std::size_t E, std::size_t... I>
  extern std::index_sequence<((void)I, E)...> fill_index_sequence<E, std::index_sequence<I...>>;

  template<std::size_t B, std::size_t S, std::size_t n, typename T> extern T remove_index_sequence;

  template<std::size_t B, std::size_t S, std::size_t n, std::size_t... I>
  extern std::index_sequence<(I + (I < B ? 0 : (1 + (I - B) / (S - 1) < n ? 1 + (I - B) / (S - 1) : n)))...>
    remove_index_sequence<B, S, n, std::index_sequence<I...>>;

  template<std::size_t B, std::size_t n, std::size_t... I>
  extern std::index_sequence<(I < B ? I : I + n)...> remove_index_sequence<B, 1, n, std::index_sequence<I...>>;

  template<typename T> extern T reverse_index_sequence;

  template<std::size_t... I>
  extern std::index_sequence<(sizeof...(I) - 1 - I)...> reverse_index_sequence<std::index_sequence<I...>>;

  template<std::size_t, typename T> extern T rotate_index_sequence;

  template<std::size_t R, std::size_t... I>
  extern std::index_sequence<((I + R) % sizeof...(I))...> rotate_index_sequence<R, std::index_sequence<I...>>;

  template<std::size_t, typename T> extern T shift_index_sequence;

  template<std::size_t O, std::size_t... I>
  extern std::index_sequence<(I + O)...> shift_index_sequence<O, std::index_sequence<I...>>;

  template<std::size_t B, std::size_t S, typename T> extern T slice_index_sequence;

  template<std::size_t B, std::size_t S, std::size_t... I>
  extern std::index_sequence<(B + I * S)...> slice_index_sequence<B, S, std::index_sequence<I...>>;

  template<typename Sizes, typename Elts> extern Sizes strided_index_sequence;

  template<std::size_t... I, std::size_t... J>
  extern std::index_sequence<stride_at(J, std::index_sequence<I...>{}, std::index_sequence<J...>{})...>
    strided_index_sequence<std::index_sequence<I...>, std::index_sequence<J...>>;
}

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef cartesian_strides
    @brief A helper alias template computing the strides associated to the cartesian product operation.

    For a cartesian product of `M` tuples of sizes `N0, ..., N(M-1)`, the `K`-th element of the product
    selects, in the `i`-th input tuple, the element at index `(K / S_i) % N_i`. This alias computes the
    strides `S_i`, i.e. the number of consecutive product elements sharing the same index in tuple `i`.
    The last tuple varies fastest, so `S_i` is the product of the sizes of all tuples following tuple `i`
    and the last stride is always `1`.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
    template<typename Sizes, typename Elts>
    using cartesian_strides;
    @endcode

    @subgroupheader{Template Parameters}
      - `Sizes`: `std::index_sequence` containing the size of each input tuple
      - `Elts`: `std::index_sequence` containing the position `0, ..., M-1` of each input tuple
        (typically `std::index_sequence_for<Ts...>`)

    @subgroupheader{Return value}
      A `std::index_sequence` of `M` strides, one per input tuple, where `S_i` is the product of
      `Sizes` over positions strictly greater than `i`.

    @subgroupheader{Example}
      For `Sizes = std::index_sequence<2, 3>` and `Elts = std::index_sequence<0, 1>`, the result is
      `std::index_sequence<3, 1>`. The element `K` of the product then selects `((K / 3) % 2, (K / 1) % 3)`,
      which enumerates `(0,0) (0,1) (0,2) (1,0) (1,1) (1,2)`.
  **/
  //===================================================================================================================
  template<typename Sizes, typename Elts>
  using cartesian_strides = decltype(kumi::_::strided_index_sequence<Sizes, Elts>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef cat_index_sequence
    @brief A helper alias template computing the index map associated to the concatenation operation.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename... Ts>
      using cat_index_sequence;
    @endcode

    @subgroupheader{Parameters}
      - `Ts...`: List of `std::index_sequence` to concatenate.

    @subgroupheader{Return value}
      A `std::index_sequence` of all elements of the input index sequences.
  **/
  //====================================================================================================================
  template<typename... Ts> using cat_index_sequence = decltype(kumi::_::cat_index_sequence<Ts...>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef fill_index_sequence
    @brief A helper alias template generating an index sequence repeating a constant value.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<std::size_t Element, std::size_t Count>
      using fill_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `Element`: Compile-time value to replicate
      - `Count`: Number of repetitions to generate

    @subgroupheader{Return value}
      A `std::index_sequence` filled completely with `e`.
  **/
  //====================================================================================================================
  template<std::size_t E, std::size_t N>
  using fill_index_sequence = decltype(kumi::_::fill_index_sequence<E, std::make_index_sequence<N>>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef indexes_for
    @brief A helper alias template extracting the projection map associated to a given `kumi::concepts::product_type`.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename T>
      using indexes_for;
    @endcode

    @subgroupheader{Parameters}
      - `T`: `kumi::concepts::product_type` to extract the projection map from.

    @subgroupheader{Return value}
      A `std::index_sequence` equivalent to `std::make_index_sequence<kumi::size_v<T>>`.
  **/
  //====================================================================================================================
  template<typename T> using indexes_for = std::make_index_sequence<kumi::size_v<T>>;

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef remove_index_sequence
    @brief A helper alias template generating the index sequence associated to the remove operation.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
    template<std::size_t N, std::size_t B, std::size_t E, std::size_t S = 1>
    using remove_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `N`: Compile-time size of the input domain
      - `B`: Compile-time index of the beginning of the range to remove
      - `E`: Compile-time index of the end of the range to remove (excluded)
      - `S`: Compile-time stride to consider on the range to remove

    @subgroupheader{Return value}
      A `std::index_sequence` containing, in increasing order, the indexes of `[0, N)` that are
      not of the form `B + t * S < E`.
  **/
  //====================================================================================================================
  template<std::size_t N, std::size_t B, std::size_t E, std::size_t S = 1>
  using remove_index_sequence =
    decltype(kumi::_::remove_index_sequence<B,
                                            S,
                                            ((E > B) ? (E - B + S - 1) / S : 0),
                                            std::make_index_sequence<N - ((E > B) ? (E - B + S - 1) / S : 0)>>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef reverse_index_sequence
    @brief A helper alias template computing the reversed index sequence.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Size>
      using reverse_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `N`: Length of the index sequence to generate

    @subgroupheader{Return value}
      An index sequence equivalent to std::make_index_sequence<N> but filled from the end.
  **/
  //====================================================================================================================
  template<std::size_t N>
  using reverse_index_sequence = decltype(kumi::_::reverse_index_sequence<std::make_index_sequence<N>>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef rotate_index_sequence
    @brief A helper alias template computing the index_sequence associated to the rotation operation.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<std::size_t Rotation, std::size_t Size>
      using rotate_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `R`: Rotation factor
      - `N`: Compile-time length of the input domain

    @subgroupheader{Return value}
      A `std::index_sequence` mapping circularly rotated values.
  **/
  //====================================================================================================================
  template<std::size_t R, std::size_t N>
  using rotate_index_sequence = decltype(kumi::_::rotate_index_sequence<R, std::make_index_sequence<N>>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef shift_index_sequence
    @brief A helper alias template computing linear indexing translations.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<std::size_t Offset, std::size_t Size>
      using shift_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `Offset`: Offset to add to each element in the input domain
      - `Size`: Size of the input domain

    @subgroupheader{Return value}
      A `std::index_sequence` shifted uniformly forward by `o`.
  **/
  //====================================================================================================================
  template<std::size_t O, std::size_t N>
  using shift_index_sequence = decltype(kumi::_::shift_index_sequence<O, std::make_index_sequence<N>>);

  //====================================================================================================================
  /**
    @ingroup kumi_functional

    @typedef slice_index_sequence
    @brief A helper alias template computing the index map associated to the slicing (begin, end, step) operation.

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<std::size_t B Begin, std::size_t B End, std::size_t B Step>
      using slice_index_sequence;
    @endcode

    @subgroupheader{Template Parameters}
      - `B`: Compile-time index marking the beginning of the slice range
      - `E`: Compile-time index marking the end boundary of the slice range (exclusive)
      - `S`: Compile-time stride step hopping increment factor

    @subgroupheader{Return value}
      A `std::index_sequence` tracking linear jumps matching `Begin + I * Step`.
  **/
  //====================================================================================================================
  template<std::size_t B, std::size_t E, std::size_t S = 1>
  using slice_index_sequence =
    decltype(kumi::_::slice_index_sequence<B, S, std::make_index_sequence<((E > B) ? ((E - B + S - 1) / S) : 0)>>);
}
