/**
  KUMI - Compact C++20 Tuple Toolbox
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <memory>
#include <functional>
#include <string>

// --- Free function ---
int add(int a, int b) { return a + b; }

// --- Callable objects ---
struct Adder
{
  int operator()(int a, int b) const { return a + b; }
};

struct Multiplier
{
  int operator()(int a, int b) const { return a * b; }
};

struct Greeter
{
  std::string operator()(std::string const& name) const { return "Hello, " + name + "!"; }
};

struct VoidCallable
{
  void operator()(int x) const { std::cout << "Value: " << x << "\n"; }
};

// --- Member types ---
struct MyClass
{
  int value = 42;
  int get() const { return value; }
  void set(int v) { value = v; }
};

// --- invoke_r helpers ---
struct FloatGetter
{
  constexpr float get() const noexcept { return 42.0; }
};

struct VoidGetter
{
  constexpr void get() const noexcept {}
};

void void_func() { std::cout << "void_func called\n"; }

int main()
{
  std::cout << "===== invoke free function =====\n";
  std::cout << "invoke(add, 3, 4) = " << kumi::invoke(add, 3, 4) << "\n\n";

  std::cout << "===== invoke callable objects =====\n";
  std::cout << "Adder(3, 4): " << kumi::invoke(Adder{}, 3, 4) << "\n";
  std::cout << "Multiplier(3, 4): " << kumi::invoke(Multiplier{}, 3, 4) << "\n";
  std::cout << "Greeter(\"World\"): " << kumi::invoke(Greeter{}, "World") << "\n";
  std::cout << "VoidCallable(42): ";
  kumi::invoke(VoidCallable{}, 42);

  std::cout << "\n===== invoke member function pointer =====\n";
  MyClass obj{100};
  std::cout << "obj.get() via invoke: " << kumi::invoke(&MyClass::get, obj) << "\n";

  std::cout << "\n===== invoke member object pointer =====\n";
  std::cout << "obj.value via invoke: " << kumi::invoke(&MyClass::value, obj) << "\n";

  std::cout << "\n===== invoke with unique_ptr =====\n";
  auto ptr = std::make_unique<MyClass>(200);
  std::cout << "ptr->value via invoke: " << kumi::invoke(&MyClass::value, ptr) << "\n";

  std::cout << "\n===== invoke with shared_ptr =====\n";
  auto shared = std::make_shared<MyClass>(300);
  std::cout << "shared->value via invoke: " << kumi::invoke(&MyClass::value, shared) << "\n";

  std::cout << "\n===== invoke with reference_wrapper =====\n";
  MyClass obj3{42};
  std::reference_wrapper<MyClass> ref{obj3};
  std::cout << "ref.get() via invoke: " << kumi::invoke(&MyClass::get, ref) << "\n";

  std::cout << "\n===== invoke_r with type conversion =====\n";
  constexpr auto getter = FloatGetter{};
  std::cout << "invoke_r<int>(3.14f) = " << kumi::invoke_r<double>(&FloatGetter::get, getter) << "\n";

  std::cout << "invoke_r<double>(42) = " << kumi::invoke_r<std::size_t>(&add, 1, 2) << "\n";

  std::cout << "\n===== invoke_r<void> =====\n";
  kumi::invoke_r<void>(&void_func);
  kumi::invoke_r<void>(&VoidGetter::get, VoidGetter{});
  std::cout << "invoke_r<void> works correctly\n";

  return 0;
}
