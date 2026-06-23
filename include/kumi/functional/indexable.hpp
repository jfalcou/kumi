//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <utility>
#include <type_traits>

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup functional

    @var cartesian_producer
    @brief Callable object computing the index map associated to the cartesian product operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename... Shapes>
      consteval auto cartesian_producer(Shapes... shapes) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `shapes...`: Compile-time sizes representing the dimensions of the inputs to build a product from

    @subgroupheader{Return value}
      A `kumi::projection_map` handling cartesian index unflattening transformations.
  **/
  //====================================================================================================================
  struct cartesian_product_t
  {
  private:
    template<std::size_t... H, std::size_t... S>
    consteval auto impl(std::index_sequence<H...>, kumi::index_t<S>...) const noexcept
    {
      return kumi::projection_map{kumi::_::digits(kumi::_::unflatten_index, std::make_index_sequence<sizeof...(S)>{},
                                                  std::index_sequence<H, S...>{})...};
    }

  public:
    template<std::size_t... S> consteval auto operator()(kumi::index_t<S>...) const noexcept
    {
      constexpr std::size_t N = (S * ... * 1ULL);
      return impl(std::make_index_sequence<N>{}, kumi::index<S>...);
    }
  } inline constexpr cartesian_producer;

  //====================================================================================================================
  /**
    @ingroup functional

    @var concatenater
    @brief Callable object computing the index map associated to the concatenation operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename... Sizes>
      consteval auto concatenater(Sizes... sizes) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `sizes...`: Compile-time sizes of all inputs tuples

    @subgroupheader{Return value}
      A `kumi::projection_map` mapping indices over combined tuple domains.
  **/
  //====================================================================================================================
  struct cat_t
  {
  private:
    template<std::size_t... S> consteval auto impl(std::index_sequence<S...>) const noexcept
    {
      constexpr auto N = (S + ... + 0ULL);
      return kumi::projection_map{
        kumi::_::digits(kumi::_::container_of_index, std::make_index_sequence<N>{}, std::index_sequence<S...>{}),
        kumi::_::digits(kumi::_::element_of_index, std::make_index_sequence<N>{}, std::index_sequence<S...>{})};
    }

  public:
    template<std::size_t... S> consteval auto operator()(kumi::index_t<S>...) const noexcept
    {
      return impl(std::index_sequence<S...>{});
    }
  } inline constexpr concatenater;

  //====================================================================================================================
  /**
    @ingroup functional

    @var extractor
    @brief Callable object computing the index map associated to the extraction operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Begin, typename End, typename Size, typename Step>
      consteval auto extractor(Begin b, End e, Size s, Step st) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `b`: Compile-time index marking the beginning of the excluded window
      - `e`: Compile-time index marking the end of the excluded window
      - `s`: Total compile-time width limit of the original tuple frame
      - `st`: Offset between consecutive elements to extract.

    @subgroupheader{Return value}
      A `std::index_sequence` mapping original layout indices while skipping the extracted block window.
  **/
  //====================================================================================================================
  struct extract_t
  {
  private:
    template<std::size_t B, std::size_t E, std::size_t S, std::size_t R, std::size_t... I>
    consteval auto impl(
      kumi::index_t<B>, kumi::index_t<E>, kumi::index_t<S>, kumi::index_t<R>, std::index_sequence<I...>) const noexcept
    {
      constexpr std::size_t K = (E > B) ? (E - B) - R : 0;
      constexpr std::size_t S_1 = (S > 1) ? (S - 1) : 1;

      return std::index_sequence<(I < B ? I : (I < B + K ? B + (I - B) + (I - B) / S_1 + 1 : I + R))...>{};
    }

  public:
    template<std::size_t B, std::size_t E, std::size_t S, std::size_t St = 1>
    consteval auto operator()(kumi::index_t<B> b,
                              kumi::index_t<E> e,
                              kumi::index_t<S>,
                              kumi::index_t<St> s = {}) const noexcept
    {
      constexpr std::size_t T = (E > B) ? (E - B + St - 1) / St : 0;
      constexpr std::size_t N = S - T;
      return impl(b, e, s, kumi::index<T>, std::make_index_sequence<N>{});
    }
  } inline constexpr extractor;

  //====================================================================================================================
  /**
    @ingroup functional

    @var rotater
    @brief Callable object computing the index map associated to the rotation operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Size, typename Rotation>
      consteval auto rotater(Size s, Rotation r) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `s`: Compile-time length of the input domain
      - `r`: Rotation factor

    @subgroupheader{Return value}
      A `std::index_sequence` mapping circularly rotated values.
  **/
  //====================================================================================================================
  struct rotate_t
  {
  private:
    template<std::size_t R, std::size_t... S>
    consteval auto impl(kumi::index_t<R>, std::index_sequence<S...>) const noexcept
    {
      return std::index_sequence<((S + R) % sizeof...(S))...>{};
    }

  public:
    template<std::size_t S, std::size_t R>
    consteval auto operator()(kumi::index_t<S>, kumi::index_t<R> r) const noexcept
    {
      return impl(r, std::make_index_sequence<S>{});
    }
  } inline constexpr rotater;

  //====================================================================================================================
  /**
    @ingroup functional

    @var reducer
    @brief Callable object computing the index map associated to the reduction operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Count, typename N>
      consteval auto reducer(Count c, N n) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `c`: Total reduced pairs processing for the current step
      - `n`: Remainder if the number of values is odd

    @subgroupheader{Return value}
      A `kumi::projection_map` segmenting the input domain in chunks of two consecutive elements plus the reminder.
  **/
  //====================================================================================================================
  struct reduce_t
  {
  private:
    template<std::size_t N, std::size_t... I>
    consteval auto impl(kumi::index_t<N>, std::index_sequence<I...>) const noexcept
    {
      return kumi::projection_map{std::index_sequence<(2 * I)...>{}, std::index_sequence<(2 * I + 1)...>{},
                                  kumi::index<N>};
    }

  public:
    template<std::size_t C, std::size_t N>
    consteval auto operator()(kumi::index_t<C>, kumi::index_t<N> n) const noexcept
    {
      return impl(n, std::make_index_sequence<C>{});
    }
  } inline constexpr reducer;

  //====================================================================================================================
  /**
    @ingroup functional

    @var repeater
    @brief Callable object generating an index sequence repeating a constant index.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Element, typename Count>
      consteval auto repeater(Element e, Count c) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `e`: Compile-time value to replicate
      - `c`: Number of repetitions to generate

    @subgroupheader{Return value}
      A `std::index_sequence` filled completely with `e`.
  **/
  //====================================================================================================================
  struct repeat_t
  {
  private:
    template<std::size_t E, std::size_t... I>
    consteval auto impl(kumi::index_t<E>, std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<((void)I, E)...>{};
    }

  public:
    template<std::size_t E, std::size_t C>
    consteval auto operator()(kumi::index_t<E> e, kumi::index_t<C>) const noexcept
    {
      return impl(e, std::make_index_sequence<C>{});
    }
  } inline constexpr repeater;

  //====================================================================================================================
  /**
    @ingroup functional

    @var reverser
    @brief Callable object computing the reversed index sequence.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Size>
      consteval auto reverser(Size s) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `s`: Length of the index sequence to generate

    @subgroupheader{Return value}
      An index sequence equivalent to std::make_index_sequence<N> but filled from the end.
  **/
  //====================================================================================================================
  struct reverse_t
  {
  private:
    template<std::size_t... I> consteval auto impl(std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<(sizeof...(I) - 1 - I)...>{};
    }

  public:
    template<std::size_t S> consteval auto operator()(kumi::index_t<S>) const noexcept
    {
      return impl(std::make_index_sequence<S>{});
    }
  } inline constexpr reverser;

  //====================================================================================================================
  /**
    @ingroup functional

    @var shifter
    @brief Callable object computing linear indexing translations.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Offset, typename Size>
      consteval auto shifter(Offset o, Size s) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `o`: Offset to add to each element in the input domain
      - `s`: Size of the input domain

    @subgroupheader{Return value}
      A `std::index_sequence` shifted uniformly forward by `o`.
  **/
  //====================================================================================================================
  struct shift_t
  {
  private:
    template<std::size_t O, std::size_t... I>
    consteval auto impl(kumi::index_t<O>, std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<I + O...>{};
    }

  public:
    template<std::size_t O, std::size_t S>
    consteval auto operator()(kumi::index_t<O> o, kumi::index_t<S>) const noexcept
    {
      return impl(o, std::make_index_sequence<S>{});
    }
  } inline constexpr shifter;

  //====================================================================================================================
  /**
    @ingroup functional

    @var splitter
    @brief Callable object computing underlying index sequences of the input domain divided in two parts.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename N, typename Size>
      consteval auto splitter(N n, Size s) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `n`: Midpoint split pivot
      - `s`: Size of the input domain to split

    @subgroupheader{Return value}
      A `kumi::projection_map` tracking partitioned left and right index segments.
  **/
  //====================================================================================================================
  struct split_t
  {
  private:
    template<std::size_t N, std::size_t... S>
    consteval auto impl(kumi::index_t<N>, std::index_sequence<S...>) const noexcept
    {
      return kumi::projection_map{std::make_index_sequence<N>{}, std::index_sequence<(S + N)...>{}};
    }

  public:
    template<std::size_t N, std::size_t S>
    consteval auto operator()(kumi::index_t<N> n, kumi::index_t<S>) const noexcept
    {
      constexpr std::size_t R = S - N;
      return impl(n, std::make_index_sequence<R>{});
    }
  } inline constexpr splitter;

  //====================================================================================================================
  /**
    @ingroup functional

    @var tiler
    @brief Callable object computing multi-dimensional window block layout configurations.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Sz, typename Extent, typename Stride, typename NumBlocks>
      consteval auto tiler(Sz sz, Extent ext, Stride str, NumBlocks nb) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `sz`: Size of the tiles to generate
      - `ext`: Size of the input domain
      - `str`: Dimensional stride representing elements to skip
      - `nb`: Total number of tiles to generate

    @subgroupheader{Return value}
      A `kumi::projection_map` handling tile patterns and structural grid offset mappings.
  **/
  //====================================================================================================================
  struct tile_t
  {
  private:
    template<std::size_t Sz, std::size_t E, std::size_t Sd, std::size_t... Bs>
    consteval auto impl(kumi::index_t<Sz>,
                        kumi::index_t<E>,
                        kumi::index_t<Sd>,
                        std::index_sequence<Bs...>) const noexcept
    {
      using blocks = std::index_sequence<kumi::_::block_size(Bs, Sd, E, Sz)...>;
      using offsets = std::index_sequence<(Bs * Sd)...>;
      return kumi::projection_map{blocks{}, offsets{}};
    }

  public:
    template<std::size_t Sz, std::size_t E, std::size_t Sd, std::size_t Bs>
    consteval auto operator()(kumi::index_t<Sz> sz,
                              kumi::index_t<E> e,
                              kumi::index_t<Sd> sd,
                              kumi::index_t<Bs>) const noexcept
    {
      return impl(sz, e, sd, std::make_index_sequence<Bs>{});
    }
  } inline constexpr tiler;

  //====================================================================================================================
  /**
    @ingroup functional

    @var zipper
    @brief Callable object creating the index sequence corresponding to the zip operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Count, typename Size>
      consteval auto zipper(Count c, Size s) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `c`: Number of values per zip slice
      - `s`: Size of the input domain

    @subgroupheader{Return value}
      A kumi::projection_map storing offsets from the input paired with the number of elements to generate per zip
      element
  **/
  //====================================================================================================================
  struct zip_t
  {
    template<std::size_t C, std::size_t S> consteval auto operator()(kumi::index_t<C>, kumi::index_t<S>) const noexcept
    {
      return kumi::projection_map{std::make_index_sequence<C>{}, std::make_index_sequence<S>{}};
    }
  } inline constexpr zipper;

  //====================================================================================================================
  /**
    @ingroup functional

    @var slicer
    @brief Callable object computing the index map associated to a slicing (begin, end, step) operation.

    @qualifier consteval
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/indexable.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<typename Begin, typename End, typename Step>
      consteval auto slicer(Begin b, End e, Step s) noexcept;
    @endcode

    @subgroupheader{Parameters}
      - `b`: Compile-time index marking the beginning of the slice range
      - `e`: Compile-time index marking the end boundary of the slice range (exclusive)
      - `s`: Compile-time stride step hopping increment factor

    @subgroupheader{Return value}
      A `std::index_sequence` tracking linear jumps matching `Begin + I * Step`.
  **/
  //====================================================================================================================
  struct slice_t
  {
  private:
    template<std::size_t B, std::size_t S, std::size_t... I>
    consteval auto impl(kumi::index_t<B>, kumi::index_t<S>, std::index_sequence<I...>) const noexcept
    {
      return std::index_sequence<(B + I * S)...>{};
    }

  public:
    template<std::size_t B, std::size_t E, std::size_t S = 1>
    consteval auto operator()(kumi::index_t<B> b, kumi::index_t<E>, kumi::index_t<S> s = {}) const noexcept
    {
      constexpr std::size_t N = (E > B) ? ((E - B + S - 1) / S) : 0;
      return impl(b, s, std::make_index_sequence<N>{});
    }
  } inline constexpr slicer;
}
