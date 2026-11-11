//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/functional/invoke.hpp>
#include <functional>
#include <memory>
#include <tts/tts.hpp>

struct free_fn
{
  static constexpr int add(int a, int b) { return a + b; }

  static constexpr void noop() {}
};

struct MemPtr
{
  int value = 10;

  constexpr int get() const { return value; }

  constexpr void set(int v) { value = v; }
};

struct NoDefaultCtor
{
  int v;

  constexpr int get() const { return v; }
};

struct Callable
{
  constexpr int operator()(int x, int y) const noexcept { return x + y; }
};

struct NonConvertible
{
  void operator()(int&&) const {}
};

TTS_CASE("invoke: SFINAE compliance")
{
  auto obj = MemPtr{};
  auto cal = Callable{};
  int i = 1;

  // member function pointer: an object of the matching type is required
  TTS_EXPECT_COMPILES(obj, { kumi::invoke(&MemPtr::get, obj); });
  TTS_EXPECT_COMPILES(obj, { kumi::invoke(&MemPtr::set, obj, 42); });
  TTS_EXPECT_NOT_COMPILES(cal, { kumi::invoke(&MemPtr::get, cal); });

  // callable: arity matters
  TTS_EXPECT_COMPILES(cal, { kumi::invoke(cal, 1, 2); });
  TTS_EXPECT_NOT_COMPILES(cal, { kumi::invoke(cal, 1); });
  TTS_EXPECT_NOT_COMPILES(i, { kumi::invoke(i); });
};

TTS_CASE("invoke_r: SFINAE compliance")
{
  auto obj = MemPtr{};
  auto cal = Callable{};

  // invoke_r participates when R is invocable and reachable
  TTS_EXPECT_COMPILES(obj, { kumi::invoke_r<int>(&MemPtr::get, obj); });
  TTS_EXPECT_COMPILES(obj, { kumi::invoke_r<void>(&MemPtr::get, obj); });
  TTS_EXPECT_COMPILES(cal, { kumi::invoke_r<int>(cal, 1, 2); });

  // invoke_r drops out when R can't be invoked/converted
  TTS_EXPECT_NOT_COMPILES(cal, { kumi::invoke_r<char const*>(cal, 1, 2); });

  // an lvalue where an rvalue is required does not compile
  NonConvertible nc{};
  int i = 1;
  TTS_EXPECT_COMPILES(nc, i, { kumi::invoke_r<void>(nc, std::move(i)); });
  TTS_EXPECT_NOT_COMPILES(nc, i, { kumi::invoke_r<void>(nc, i); });
};

TTS_CASE("invoke: free functions")
{
  TTS_EQUAL(kumi::invoke(&free_fn::add, 3, 4), 7);
  TTS_EQUAL(kumi::invoke(&free_fn::add, 1, 2), std::invoke(&free_fn::add, 1, 2));

  TTS_CONSTEXPR_EQUAL(kumi::invoke(&free_fn::add, 2, 3), 5);
};

TTS_CASE("invoke: callable objects")
{
  TTS_EQUAL(kumi::invoke(Callable{}, 3, 4), 7);
  TTS_CONSTEXPR_EQUAL(kumi::invoke(Callable{}, 10, 20), 30);
};

TTS_CASE("invoke: member object pointer")
{
  constexpr MemPtr obj{42};
  TTS_EQUAL(kumi::invoke(&MemPtr::value, obj), 42);
  TTS_EQUAL(kumi::invoke(&MemPtr::value, obj), std::invoke(&MemPtr::value, obj));
  TTS_CONSTEXPR_EQUAL(kumi::invoke(&MemPtr::value, obj), 42);
};

TTS_CASE("invoke: member function pointer")
{
  constexpr MemPtr obj{42};
  TTS_EQUAL(kumi::invoke(&MemPtr::get, obj), 42);
  TTS_EQUAL(kumi::invoke(&MemPtr::get, obj), std::invoke(&MemPtr::get, obj));
  TTS_CONSTEXPR_EQUAL(kumi::invoke(&MemPtr::get, obj), 42);
};

TTS_CASE("invoke: std::reference_wrapper")
{
  MemPtr obj{99};
  std::reference_wrapper<MemPtr> ref{obj};
  TTS_EQUAL(kumi::invoke(&MemPtr::get, ref), 99);
  TTS_EQUAL(kumi::invoke(&MemPtr::value, ref), 99);
};

TTS_CASE("invoke: smart pointers")
{
  auto up = std::make_unique<MemPtr>();
  auto sp = std::make_shared<MemPtr>();
  TTS_EQUAL(kumi::invoke(&MemPtr::get, up), 10);
  TTS_EQUAL(kumi::invoke(&MemPtr::get, sp), 10);
  TTS_EQUAL(kumi::invoke(&MemPtr::value, up), 10);

  kumi::invoke(&MemPtr::set, up, 7);
  kumi::invoke(&MemPtr::set, sp, 8);
  TTS_EQUAL(up->value, 7);
  TTS_EQUAL(sp->value, 8);
};

TTS_CASE("invoke_r: converts the result to R")
{
  TTS_EQUAL(kumi::invoke_r<int>(&free_fn::add, 1, 2), 3);
  TTS_EQUAL(kumi::invoke_r<double>(&free_fn::add, 1, 2), 3.0);

  constexpr MemPtr obj{42};
  TTS_CONSTEXPR_EQUAL(kumi::invoke_r<int>(&MemPtr::get, obj), 42);
};

TTS_CASE("invoke_r: void discards the result")
{
  kumi::invoke_r<void>(&free_fn::noop);
  kumi::invoke_r<void>(&MemPtr::get, MemPtr{1});
  kumi::invoke_r<void>(&MemPtr::set, MemPtr{1}, 2);
  TTS_PASS();
};

TTS_CASE("result::invoke_t and result::invoke_r_t behavior")
{
  TTS_TYPE_IS((kumi::result::invoke_t<Callable, int, int>), int);
  TTS_TYPE_IS((kumi::result::invoke_t<decltype(&MemPtr::get), MemPtr>), int);
  TTS_TYPE_IS((kumi::result::invoke_t<decltype(&MemPtr::value), MemPtr&>), int&);

  TTS_TYPE_IS((kumi::result::invoke_r_t<int, Callable, int, int>), int);
  TTS_TYPE_IS((kumi::result::invoke_r_t<void, decltype(&MemPtr::get), MemPtr>), void);
};
