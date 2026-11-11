//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include "test.hpp"
#include <type_traits>

struct Foo
{
  int bar();
  float bar(int);
  int bar() const;
  int val = 42;
};

struct NoDefaultCtor
{
  explicit NoDefaultCtor(int) {}

  NoDefaultCtor(NoDefaultCtor const&) = delete;
  NoDefaultCtor& operator=(NoDefaultCtor const&) = delete;

  int getValue() const { return 42; }
};

struct VoidReturn
{
  void doStuff() const {}
};

TTS_CASE("declval: basic type deduction")
{
  // deduce return type of member function
  using bar_type = decltype(kumi::declval<Foo>().bar());
  TTS_TYPE_IS(bar_type, int);

  // deduce return type of member function with parameter
  using bar_int_type = decltype(kumi::declval<Foo>().bar(0));
  TTS_TYPE_IS(bar_int_type, float);

  // deduce return type of const member function
  using bar_const_type = decltype(kumi::declval<Foo const>().bar());
  TTS_TYPE_IS(bar_const_type, int);

  // deduce return type of member access
  using val_type = decltype(kumi::declval<Foo>().val);
  TTS_TYPE_IS(val_type, int);
};

TTS_CASE("declval: rvalue reference and void specialization")
{
  // kumi::declval<T>() must return T&& for any type T
  TTS_TYPE_IS(decltype(kumi::declval<int>()), int&&);
  TTS_TYPE_IS(decltype(kumi::declval<Foo>()), Foo&&);
  TTS_TYPE_IS(decltype(kumi::declval<Foo const>()), Foo const&&);

  // Void specialization returns void
  TTS_TYPE_IS(decltype(kumi::declval<void>()), void);

  using void_func_type = decltype(kumi::declval<VoidReturn>().doStuff());
  TTS_TYPE_IS(void_func_type, void);
};

TTS_CASE("declval: works with types that have deleted/undefined constructors")
{
  using getValue_type = decltype(kumi::declval<NoDefaultCtor>().getValue());
  TTS_TYPE_IS(getValue_type, int);

  // Verify it also works for constructing the type itself
  TTS_TYPE_IS(decltype(kumi::declval<NoDefaultCtor>()), NoDefaultCtor&&);
};
