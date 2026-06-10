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
  struct reverse_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
      {
        constexpr auto idx = kumi::function::reverser(std::make_index_sequence<kumi::size_v<T>>{});
        return kumi::function::builder(KUMI_FWD(t), idx);
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var apply
    @brief Callable object reversing elements of a product type

    On record types, this function operates on elements as if they were ordered. The considered order is the order
    of declaration.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reverse.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto reverse(T && t) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to reverse

    @subgroupheader{Return value}

      - A product type with the type of `t` and elements equal to (get<index<size_v<T> - 1 - Idx>>(t)...);

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/reverse.hpp reverse_t

    Computes the return type of a call to kumi::reverse

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/reverse.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/reverse.cpp}
  **/
  //====================================================================================================================
  inline constexpr reverse_t reverse{};

  namespace result
  {
    //! [reverse_t]
    template<kumi::concepts::product_type T> struct reverse
    {
      using type = decltype(kumi::reverse(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using reverse_t = typename kumi::result::reverse<T>::type;
    //! [reverse_t]
  }
}
