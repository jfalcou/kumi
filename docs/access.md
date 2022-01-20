# Accessing a tuple's element

## Structured bindinds
`kumi::tuple` supports structured binding.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '@' };

  auto [a,b,c,d] = t;
  std::cout << a << "\n";
  std::cout << b << "\n";
  std::cout << c << "\n";
  std::cout << d << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1
2.3
4.5
@
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Single Element Access

### `get`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I, typename... Ts>
  requires( I<sizeof...(Ts) )
  [[nodiscard]] constexpr decltype(auto) get(tuple<Ts...>& arg) noexcept;

  template<std::size_t I, typename... Ts>
  requires(I<sizeof...(Ts))
  [[nodiscard]] constexpr decltype(auto) get(tuple<Ts...> const& arg) noexcept;
}
```

Extracts the `I`th element from a `kumi::tuple`. Note that `get` will only participate
in overload resolution if its parameter is a valid index within [0, `t.size()`[.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '@' };
  std::cout << get<0>(t) << "\n";
  std::cout << get<1>(t) << "\n";
  std::cout << get<2>(t) << "\n";
  std::cout << get<3>(t) << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1
2.3
4.5
@
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `tuple::operator[]`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I> requires(I<sizeof...(Ts))
  constexpr decltype(auto) tuple::operator[](index_t<I>) noexcept;

  template<std::size_t I> requires(I<sizeof...(Ts))
  constexpr decltype(auto) tuple::operator[](index_t<I>) const noexcept;
}
```

As a shortcut, you can also use `operator[]` directly on a `kumi::tuple` using the user-defined
literal constant indexing or the `kumi::index<N>` template variable.

`operator[]` will only participate in overload resolution if its parameter is a valid index within
[0, `t.size()`[.


**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple t = { 1, 2.3, 4.5f, '@' };
  std::cout << t[0_c] << "\n";
  std::cout << t[1_c] << "\n";
  std::cout << t[2_c] << "\n";
  std::cout << t[kumi::index<3>] << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1
2.3
4.5
@
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
