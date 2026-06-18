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
  namespace _
  {
    template<typename Target, typename T, std::size_t... I>
    KUMI_ABI constexpr decltype(auto) member_cast_(kumi::_::adl_tag_t, T&& t, std::index_sequence<I...>)
    {
      return kumi::builder<T>::make(kumi::field_cast<Target>(get<I>(KUMI_FWD(t)))...);
    }
  }

  template<typename Target> struct member_cast_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else if constexpr (kumi::concepts::record_type<T>)
        return member_cast_<Target>(kumi::_::adl_tag, KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{});
      else
      {
        using type = kumi::_::as_homogeneous_t<Target, kumi::size_v<T>>;
        return static_cast<type>(KUMI_FWD(t));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var member_cast
    @brief Callable object converting a product_type<Ts...> to an instance of a product_type<Target...>

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/member_cast.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Target, product_type T>
      constexpr auto member_cast<Target>(T && t) noexcept;
    @endcode

    @subgroupheader{Template Parameters}
      - `Target`: destination type to associate to each member of the product type `t`

    @subgroupheader{Parameters}
      - `t`: Product Type to convert

    @subgroupheader{Return value}
      - A Product type containing the values of `t` where each member is of type Target

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/cast.hpp member_cast_t

    Computes the return type of a call to kumi::member_cast

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/member_cast.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/member_cast.cpp}
  **/
  //====================================================================================================================
  template<typename T> inline constexpr member_cast_t<T> member_cast{};

  namespace result
  {
    //! [member_cast_t]
    template<typename Target, kumi::concepts::product_type T> struct member_cast
    {
      using type = decltype(kumi::member_cast<Target>(std::declval<T>()));
    };

    template<typename Target, kumi::concepts::product_type T>
    using member_cast_t = typename kumi::result::member_cast<Target, T>::type;
    //! [member_cast_t]
  }
}
