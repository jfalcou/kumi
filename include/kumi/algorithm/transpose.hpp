//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{

  template<typename T, std::size_t... I, std::size_t... J>
  KUMI_ABI constexpr decltype(auto) transpose_extern_(kumi::adl_tag_t,
                                                      T&& t,
                                                      std::index_sequence<I...>,
                                                      std::index_sequence<J...> is)
  {
    return kumi::make_tuple(kumi::function::builder(KUMI_FWD(t), std::integral_constant<std::size_t, I>{}, is)...);
  }

  struct transpose_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      static_assert(kumi::_::supports_transpose<T>, "[KUMI] - Cannot transpose given product type");
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{};
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else
      {
        constexpr std::size_t c = kumi::size_v<T>;
        constexpr std::size_t s = kumi::size_v<kumi::element_t<0, T>>;
        constexpr auto pos = kumi::function::zipper(kumi::index<c>, kumi::index<s>);
        return transpose_extern_(kumi::adl_tag, KUMI_FWD(t), get<1>(pos), get<0>(pos));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var transpose
    @brief Callable object transposing a product type of product types by shifting elements in their
            transposed position always returning a tuple as the external product type.

    @note This function will issue a compile time error if the each element of the input product type are not
          themselves product types or if their size are not equal.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/transpose.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto transpose(T && t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to transpose

    @subgroupheader{Return value}

      - A product type containing the transposed elements of `t`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/transpose.hpp transpose_t

    Computes the return type of a call to kumi::transpose

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/transpose.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/transpose.cpp}
  **/
  //====================================================================================================================
  inline constexpr transpose_t transpose{};

  namespace result
  {
    //! [transpose_t]
    template<kumi::concepts::product_type T> struct transpose
    {
      using type = decltype(kumi::transpose(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using transpose_t = typename kumi::result::transpose<T>::type;
    //! [transpose_t]
  }
}
