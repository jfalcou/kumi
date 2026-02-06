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
  //================================================================================================
  //! @ingroup utility
  //! @brief Retrieves the front of a tuple
  //!
  //! @param t Base tuple
  //! @return A reference to the first element of the tuple `t`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct front;
  //!
  //!   template<product_type Tuple>
  //!   using front_t = typename front<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::front
  //!
  //! ## Example
  //! @include doc/tuple/algo/back-front.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) front(Tuple&& t)
  requires(size_v<Tuple> != 0)
  {
    if constexpr (record_type<Tuple>) return front(values_of(KUMI_FWD(t)));
    else return get<0>(KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Retrieves the back of a tuple
  //!
  //! @param t Base tuple
  //! @return A reference to the last element of the tuple `t`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct back;
  //!
  //!   template<product_type Tuple>
  //!   using back_t = typename back<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::back
  //!
  //! ## Example
  //! @include doc/tuple/algo/back-front.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) back(Tuple&& t)
  requires(size_v<Tuple> != 0)
  {
    if constexpr (record_type<Tuple>) return back(values_of(KUMI_FWD(t)));
    else return get<size_v<Tuple> - 1>(KUMI_FWD(t));
  }

  namespace result
  {
    template<product_type Tuple> struct front : raw_member<0, Tuple>
    {
    };

    template<product_type Tuple> struct back : raw_member<size_v<Tuple> - 1, Tuple>
    {
    };

    template<product_type Tuple> using front_t = typename front<Tuple>::type;
    template<product_type Tuple> using back_t = typename back<Tuple>::type;
  }
}
