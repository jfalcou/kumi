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
  //====================================================================================================================
  /**
    @ingroup  traits
    @brief    Extracts the common product_type of a parameter pack.

    If all the types are record types then it returns
    an empty record type, otherwise returns an empty product type. As we are unable to compute the
    Least Restrictive Subtype of a pack, this trait should be specialized for each case one would want to
    write. In the library, it is specialized for kumi::concepts::product_type and kumi::concepts::record_type.
    It is used in algorithm taking multiple product types as input in order to determine the correct output type.


    @tparam Ts The product types to access

    ## Helper type
    @code
    namespace kumi
    {
      template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;
    }
    @endcode

    ## Example
    @code
    struct cplx{ float re, im; };

    template<typename... Ts> requires (std::is_same_v<Ts, cplx>)
    struct kumi::common_product_type<Ts...>
    {
      using type = cplx;
    };

    @endcode
  **/
  //====================================================================================================================
  template<typename... Ts> struct common_product_type
  {
  };

  template<typename... Ts> using common_product_type_t = typename common_product_type<Ts...>::type;

  //====================================================================================================================
  /**
    @ingroup  utility
    @class    builder
    @brief    kumi::builder provides a generic way of defining a product type.

    Helper structure to build the correct output product type based on the given template parameter. If the
    provided product type is a not a record_type the builder will output a kumi::tuple otherwise a kumi::record.
    One can specialize the builder for it's own type matching the product type semantic.

    A type for which the builder has been specialized is then suitable to be used as the return type from any
    algorithm.

    ## Example
    @code
    struct cplx { float re, im; };

    template<typename T>
    concept is_cplx = std::is_same_v<std::remove_cvref_t<T>,cplx>;

    // Builder protocole
    template<is_cplx T>
    struct builder<T>
    {
      using type = T;

      template<std::floating_point... Us> requires (sizeof...(Us) == 2) using to = cplx;

      static constexpr auto make(float r, float i)
      {
        returni cplx{r,i};
      }

      static constexpr auto build(float r, float i) { return cplx{r,i}; }
    };

    @endcode

    @tparam T the template type to be built.
  **/
  //====================================================================================================================
  template<typename T> struct builder;

  template<typename T> struct builder<T&> : builder<T>
  {
  };

  template<typename T> struct builder<T&&> : builder<T>
  {
  };

  template<typename T> struct builder<T const&> : builder<T>
  {
  };

  template<typename T> struct builder<T const&&> : builder<T>
  {
  };

  template<typename T> using builder_t = typename builder<T>::type;

  template<typename T, typename... Args> using builder_make_t = typename builder<T>::template to<Args...>;
}
