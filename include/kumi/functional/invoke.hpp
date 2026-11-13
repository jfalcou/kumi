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

    template<typename C, typename T> KUMI_HIDDEN_ABI constexpr decltype(auto) unwrap_memptr(T&& obj)
    {
      using U = std::remove_cvref_t<T>;

      if constexpr (std::is_base_of_v<C, U>) return KUMI_FWD(obj);
      else if constexpr (is_reference_wrapper_v<U>) return KUMI_FWD(obj).get();
      else return *KUMI_FWD(obj);
    }

    template<typename C, typename P, typename O, typename... Ts>
    KUMI_HIDDEN_ABI constexpr decltype(auto) invoke_memptr(P C::* member, O&& o, Ts&&... ts)
    {
      using callable_t = P C::*;

      if constexpr (std::is_member_object_pointer_v<callable_t>) return unwrap_memptr<C>(KUMI_FWD(o)).*member;
      else return (unwrap_memptr<C>(KUMI_FWD(o)).*member)(KUMI_FWD(ts)...);
    }
  }

  //====================================================================================================================
  //! @defgroup kumi_invoke kumi::invoke
  //! @ingroup kumi_functional
  //! @brief Invoke the Callable object c with a pack of arguments.
  //====================================================================================================================
  /**
    @ingroup kumi_invoke

    @var invoke
    @brief Callable object invoking the Callable object `c` with a pack of arguments.

    `kumi::invoke` is a replacement for `std::invoke` that avoids depending on `<functional>`.
    It supports free functions, member function pointers, member object pointers, and callable
    objects. When a member is invoked, the object can be a plain object, a smart pointer, or a
    `std::reference_wrapper`, which are transparently unwrapped.

    @note This function does not take part in overload resolution if `c` can't be invoked
          with the given arguments.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/invoke.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename C, typename... Ts>
      constexpr decltype(auto) invoke(C && c, Ts && ... ts) noexcept
    @endcode

    @subgroupheader{Parameters}

      - `c`: Callable object to be invoked
      - `ts`: Arguments to be passed to `c`

    @subgroupheader{Return value}

      - The value returned by `c`.

    @groupheader{Helper type}

    @snippet include/kumi/functional/invoke.hpp invoke_t

    Computes the return type of a call to kumi::invoke

    @groupheader{Examples}

    @godbolt{doc/functional/invoke.cpp}
  **/
  //====================================================================================================================
  struct invoke_t
  {
    template<typename C, typename... Ts>
    KUMI_ABI constexpr decltype(auto) operator()(C&& c, Ts&&... ts) const
      noexcept(std::is_nothrow_invocable_v<C, Ts...>)
    requires(std::is_invocable_v<C, Ts...>)
    {
      if constexpr (std::is_member_pointer_v<std::decay_t<C>>) return kumi::_::invoke_memptr(c, KUMI_FWD(ts)...);
      else return KUMI_FWD(c)(KUMI_FWD(ts)...);
    }
  };

  KUMI_VARIABLE_ABI constexpr invoke_t invoke{};

  //====================================================================================================================
  //! @defgroup kumi_invoke_r kumi::invoke_r
  //! @ingroup kumi_functional
  //! @brief Invoke the Callable object c with a pack of arguments with return type R.
  //====================================================================================================================
  /**
    @ingroup kumi_invoke_r

    @var invoke_r
    @brief Callable object invoking the Callable object `c` with a pack of arguments and returning a value of type `R`.

    `kumi::invoke_r` is a replacement for `std::invoke_r` that avoids depending on `<functional>`.
    It invokes `c` but returns a value of type `R` rather than the actual return type of `c`.
    If `R` is `void`, the return value of `c` is discarded.

    @note This function does not take part in overload resolution if `c` can't be invoked
          with the given arguments or if the result can't be converted to `R`.

    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/functional/invoke.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename R, typename C, typename... Ts>
      constexpr R invoke_r(C && c, Ts && ... ts) noexcept
    @endcode

    @subgroupheader{Parameters}

      - `R`: The type of the returned value
      - `c`: Callable object to be invoked
      - `ts`: Arguments to be passed to `c`

    @subgroupheader{Return value}

      - The value returned by `c`, converted to type `R`.

    @groupheader{Helper type}

    @snippet include/kumi/functional/invoke.hpp invoke_r_t

    Computes the return type of a call to kumi::invoke_r

    @groupheader{Example}

    @godbolt{doc/functional/invoke.cpp}
  **/
  //====================================================================================================================
  template<typename R> struct invoke_r_t
  {
    template<typename C, typename... Ts>
    KUMI_ABI constexpr R operator()(C&& c, Ts&&... ts) const noexcept(std::is_nothrow_invocable_r_v<R, C, Ts...>)
    requires(std::is_invocable_r_v<R, C, Ts...>)
    {
      if constexpr (std::is_void_v<R>) kumi::invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
      else return kumi::invoke(KUMI_FWD(c), KUMI_FWD(ts)...);
    }
  };

  template<typename R> KUMI_VARIABLE_ABI constexpr invoke_r_t<R> invoke_r{};

  namespace result
  {
    //! [invoke_t]
    template<typename C, typename... Ts>
    using invoke_t = decltype(kumi::invoke(kumi::declval<C>(), kumi::declval<Ts>()...));

    template<typename C, typename... Ts> struct invoke
    {
      using type = kumi::result::invoke_t<C, Ts...>;
    };

    //! [invoke_t]

    //! [invoke_r_t]
    template<typename R, typename C, typename... Ts>
    using invoke_r_t = decltype(kumi::invoke_r<R>(kumi::declval<C>(), kumi::declval<Ts>()...));

    template<typename R, typename C, typename... Ts> struct invoke_r
    {
      using type = kumi::result::invoke_r_t<R, C, Ts...>;
    };

    //! [invoke_r_t]
  }
}
