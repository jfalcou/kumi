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

  namespace _{
    template<typename T>
    inline constexpr bool is_reference_wrapper_v =
      !std::is_same_v<std::decay_t<typename std::unwrap_reference<T &&>::type>,
                      typename std::unwrap_ref_decay<T &&>::type>;

    template<typename T>
    struct apply_object_unwrap{
      using type = T &&;
    };
    template<typename T>
    requires is_reference_wrapper_v<T>
    struct apply_object_unwrap<T>{
      using type = typename std::remove_cvref_t<T>::type &;
    };
    template<typename T>
    requires std::is_pointer_v<std::remove_cvref_t<T>>
    struct apply_object_unwrap<T>{
      using type = std::remove_pointer_t<std::remove_cvref_t<T>> &;
    };
    template<typename T>
    using apply_object_unwrap_t = typename apply_object_unwrap<T>::type;

  }

  //================================================================================================
  //! @ingroup transforms
  //! @brief Invoke the Callable object f with a tuple of arguments.
  //!
  //! @param f	Callable object to be invoked
  //! @param t  kumi::product_type whose elements to be used as arguments to f
  //! @return The value returned by f.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct apply;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using apply_t = typename apply<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::apply
  //!
  //! ## Example
  //! @include doc/apply.cpp
  //================================================================================================
  template<typename Function, product_type Tuple>
  constexpr decltype(auto) apply(Function &&f, Tuple &&t) noexcept(_::supports_nothrow_apply<Function &&, Tuple &&>)
  requires _::supports_apply<Function&&, Tuple&&>
  {
    if constexpr(sized_product_type<Tuple,0>) return KUMI_FWD(f)();
    else if constexpr (std::is_member_pointer_v<std::decay_t<Function>>)
      return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto){
        auto &&w = [](auto &&y) -> decltype(auto){
          if constexpr(_::is_reference_wrapper_v<decltype(y)>)
            return y.get();
          else if constexpr(std::is_pointer_v<std::remove_cvref_t<decltype(y)>>)
            return *y;
          else
            return KUMI_FWD(y);
        }(get<0>(KUMI_FWD(t)));
        if constexpr(std::is_member_object_pointer_v<std::remove_cvref_t<decltype(f)>>)
          return KUMI_FWD(w).*f;
        else
          return (KUMI_FWD(w).*f)(get<I + 1>(KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size<Tuple>::value - 1>());
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) -> decltype(auto)
      {
        return KUMI_FWD(f)(get<I>(KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size<Tuple>::value>());
  }

  namespace result
  {
    template<typename Function, product_type Tuple>
    struct apply
    {
      using type = decltype(kumi::apply(std::declval<Function>(), std::declval<Tuple>()));
    };

    template<typename Function, product_type Tuple>
    using apply_t = typename apply<Function,Tuple>::type;
  }
}
