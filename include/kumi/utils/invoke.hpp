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
    template<typename T>
    inline constexpr bool is_reference_wrapper_v =
      !std::is_same_v<std::decay_t<typename std::unwrap_reference<T&&>::type>,
                      typename std::unwrap_ref_decay<T&&>::type>;

    template<typename C, typename P, typename O, typename... Ts>
    KUMI_ABI constexpr decltype(auto) invoke_memptr(P C::* member, O&& o, Ts&&... ts)
    {
      using callable_t = P C::*;
      auto&& ptr = [](auto&& obj) -> decltype(auto) {
        using T = std::remove_cvref_t<decltype(obj)>;
        if constexpr (_::is_reference_wrapper_v<T>) return obj.get();
        else if constexpr (std::is_pointer_v<T>) return *KUMI_FWD(obj);
        else return KUMI_FWD(obj);
      }(KUMI_FWD(o));

      if constexpr (std::is_member_object_pointer_v<callable_t>) return KUMI_FWD(ptr).*member;
      else return (KUMI_FWD(ptr).*member)(KUMI_FWD(ts)...);
    };
  }

  //====================================================================================================================
  //! @ingroup utility
  //! @brief Invoke the Callable object c with a pack of arguments.
  //!
  //! @param c	Callable object to be invoked
  //! @param ts elements to be used as arguments to c
  //! @return The value returned by c.
  //!
  //! @note Replaces std::invoke to avoid depending on `functional`.
  //====================================================================================================================
  template<typename C, typename... Ts>
  KUMI_ABI constexpr decltype(auto) invoke(C&& c, Ts&&... ts) noexcept(std::is_nothrow_invocable<C, Ts...>::value)
  requires(std::is_invocable<C, Ts...>::value)
  {
    if constexpr (std::is_member_pointer_v<std::decay_t<C>>) return _::invoke_memptr(c, KUMI_FWD(ts)...);
    else return KUMI_FWD(c)(KUMI_FWD(ts)...);
  };

  //====================================================================================================================
  //! @ingroup utility
  //! @brief Invoke the Callable object c with a pack of arguments with return type R.
  //!
  //! @tparam R the return type of the callable
  //! @param  c	Callable object to be invoked
  //! @param  ts elements to be used as arguments to c
  //! @return The value returned by c with type R.
  //!
  //! @note Replaces std::invoke_r to avoid depending on `functional`.
  //====================================================================================================================
  template<typename R, typename C, typename... Ts>
  KUMI_ABI constexpr R invoke_r(C&& c, Ts&&... ts) noexcept(std::is_nothrow_invocable_r<R, C, Ts...>::value)
  requires(std::is_invocable_r<R, C, Ts...>::value)
  {
    if constexpr (std::is_void_v<R>) invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
    else return invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
  };
}
