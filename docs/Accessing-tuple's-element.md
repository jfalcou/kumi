# `get`

**Synopsis:**
```c++
template<std::size_t I, typename... Ts> requires( I<sizeof...(Ts) )
[[nodiscard]] constexpr decltype(auto) get(tuple<Ts...>& arg) noexcept;

template<std::size_t I, typename... Ts> requires(I<sizeof...(Ts))
[[nodiscard]] constexpr decltype(auto) get(tuple<Ts...> const& arg) noexcept;
```

Extracts the `I`th element from a `kumi::tuple`. Note that `get` will only participate
in overload resolution if its parameter is a valid index within [0, `t.size()`[.

[**Example:**](https://godbolt.org/z/nY3EeMM1b)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  std::cout << get<0>(t) << "\n";
  std::cout << get<1>(t) << "\n";
  std::cout << get<2>(t) << "\n";
  std::cout << get<3>(t) << "\n";
}
```

**Expected output:**
```bash
1
2.3
4.5
6
```

# `tuple::operator[]`

**Synopsis:**
```c++
template<std::size_t I> requires(I<sizeof...(Ts))
constexpr decltype(auto) tuple::operator[](index_t<I>) noexcept;

template<std::size_t I> requires(I<sizeof...(Ts))
constexpr decltype(auto) tuple::operator[](index_t<I>) const noexcept;
```

As a shortcut, you can also use `operator[]` directly on a `kumi::tuple` using the user-defined
literal constant indexing or the `kumi::index<N>` template variable.

`operator[]` will only participate in overload resolution if its parameter is a valid index within
[0, `t.size()`[.

[**Example:**](https://godbolt.org/z/hTW1cvcTM)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  std::cout << t[0_c] << "\n";
  std::cout << t[1_c] << "\n";
  std::cout << t[2_c] << "\n";
  std::cout << t[kumi::index<3>] << "\n";
}
```

**Expected output:**
```bash
1
2.3
4.5
6
```

# Structured bindinds
One can also use structured binding to access all elements at once.

[**Example:**](https://godbolt.org/z/nbvGech35)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };

  auto [a,b,c,d] = t;
  std::cout << a << "\n";
  std::cout << b << "\n";
  std::cout << c << "\n";
  std::cout << d << "\n";
}
```

**Expected output:**
```bash
1
2.3
4.5
6
```

