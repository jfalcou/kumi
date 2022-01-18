# Conversion

## `tuple::cast`

**Synopsis:**
```c++
namespace kumi
{
  template<typename... Us>
  [[nodiscard]] constexpr auto tuple::cast();
}
```

Converts a `kumi::tuple<Ts...>` to a `kumi::tuple<Us...>`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 65, 2.3, 4.5f};
  auto b = a.cast<char,int,double>();

  std::cout << a << "\n";
  std::cout << b << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
(65 2.3 4.5)
(A 2 4.5)
true
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## `from_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Type, typename... Ts>
  requires( !kumi::product_type<Type> &&  kumi::detail::implicit_constructible<Type, Ts...> )
  [[nodiscard]] constexpr Type from_tuple(tuple<Ts...> const& t);
}
```

Converts a `kumi::tuple<Ts...>` to an instance of a non-product type `Type` constructed by passing each element of the tuple to `Type` constructor.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>
#include <string>

struct my_struct
{
  int         i;
  float       f;
  std::string name;
};

int main()
{
  kumi::tuple a = { 1337, 2.3475f, "John"};
  auto b = from_tuple<my_struct>(a);

  std::cout << a << "\n";
  std::cout << b.i << "\n";
  std::cout << b.f << "\n";
  std::cout << b.name << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1337 2.3475 John )
1337
2.3475
John
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## `to_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Type>
  [[nodiscard]] inline constexpr auto to_tuple(Type&& that);
}
```

Converts a `kumi::product_type` instance to an instance of the equivalent `kumi::tuple` type containing a copy of each element of `t`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>
#include <array>

template<typename T, std::size_t N>
struct  kumi::is_product_type<std::array<T,N>>
      : std::true_type
{};

int main()
{
  std::array<int,3> a = { 37, 15, 27};
  auto b = kumi::to_tuple(a);

  std::cout << b << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 37 15 27 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
