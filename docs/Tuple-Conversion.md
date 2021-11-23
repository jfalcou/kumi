
# `tuple::cast`

**Synopsis:**
```c++
template<typename... Us> [[nodiscard]] constexpr auto tuple::cast();
```

Converts a `kumi::tuple<Ts...>` to a `kumi::tuple<Us...>`.

[**Example:**](https://godbolt.org/z/5bzdM4Ma5)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 65, 2.3, 4.5f};
  auto b = a.cast<char,int,double>();

  std::cout << a << "\n";
  std::cout << b << "\n";
}
```

**Expected output:**
```bash
(65 2.3 4.5)
(A 2 4.5)
true
```

# `tuple_cast`

**Synopsis:**
```c++
template<typename Type, typename... Ts>
requires( !kumi::product_type<Type> && kumi::detail::implicit_constructible<Type, Ts...> )
[[nodiscard]] constexpr Type tuple_cast(tuple<Ts...> const& t);
```

Converts a `kumi::tuple<Ts...>` to an instance of a non-product type `Type` constructed by
passing each element of the tuple to `Type` constructor.

[**Example:**](https://godbolt.org/z/cqjbn7MYd)
```c++
#include <kumi.hpp>
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
  auto b = tuple_cast<my_struct>(a);

  std::cout << a << "\n";
  std::cout << b.i << "\n";
  std::cout << b.f << "\n";
  std::cout << b.name << "\n";
}
```

**Expected output:**
```bash
( 1337 2.3475 John )
1337
2.3475
John
```

# `to_tuple`

**Synopsis:**
```c++
template<kumi::product_type Type>
[[nodiscard]] constexpr auto tuple_cast(Type const& t);
```

Converts a `kumi::product_type` instance to an instance of the equivalent `kumi::tuple` type
containing a copy of each element of `t`.

[**Example:**]()
```c++
#include <kumi.hpp>
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
  auto b = tuple_cast<my_struct>(a);

  std::cout << a << "\n";
  std::cout << b.i << "\n";
  std::cout << b.f << "\n";
  std::cout << b.name << "\n";
}
```

**Expected output:**
```bash
( 1337 2.3475 John )
1337
2.3475
John
```
