//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kumi/utils/concepts.hpp>

namespace kumi
{  
  //================================================================================================
  //! @ingroup tuple
  //! @class builder 
  //! @brief Helper structure to build the correct output `product_type`. Defaults to kumi::tuple if 
  //!        the given type is not a kumi::product_type
  //!
  //! builder provides a way to instantiate a kumi::product_type depending on the template type 
  //! given, if the type is not a template template parameter, the output type will be a instance
  //! of kumi::tuple
  //!
  //! @tparam T the template template type to be built. 
  //================================================================================================
  template<typename T> 
  struct builder
  {
    //==============================================================================================
    //! @brief Rebinds the current product_type type to wrap the new elements type.
    //! @tparam Ts The types to wrap.
    //!
    //!## Helper type
    //! @code
    //! namespace kumi
    //! {
    //!   template<typename T, typename... Args> builder_t 
    //!       = typename builder<T>::template to<Args...>;
    //! }
    //! @endcode
    //==============================================================================================

    //==============================================================================================
    template<typename... Ts>
    using to = kumi::tuple<Ts...>;

    //==============================================================================================
    //! @brief Builds a instance of the current product_type from the given arguments. 
    //! @tparam Args The type to wrap in the product_type.
    //! @param  args The values to wrap. 
    //! @return The current product_type containing the value.
    //==============================================================================================
    template<typename...Args>
    static constexpr auto make(Args&&... args)
    {
      return kumi::tuple{ KUMI_FWD(args)... };
    }
  };

  template<template<class...> class Box, typename... Ts>
  requires( product_type<Box<Ts...>> )
  struct builder<Box<Ts...>>
  {
    template<typename... Us>
    using to = Box<Us...>;

    template<typename... Args>
    static constexpr auto make(Args&&... args)
    {
      return Box{ KUMI_FWD(args)... };
    } 
  };

  template <typename T, typename... Args>
  using builder_t = typename builder<T>::template to<Args...>;
}
