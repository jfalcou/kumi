# Accessing a tuple's element

## Structured bindinds
`kumi::tuple` supports structured binding.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
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
#include <kumi.hpp>
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
#include <kumi.hpp>
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

## Tuple Slicing

### `tuple::extract`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I0, std::size_t I1> requires((I1-I0) <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::extract( index_t<I0> const&, index_t<I1> const&) const noexcept;

  template<std::size_t I0, std::size_t I1> requires((I1-I0) <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::extract( index_t<I0> const&, index_t<I1> const&) noexcept;

  template<std::size_t I0> requires(I0 <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::extract( index_t<I0> const&) const noexcept;

  template<std::size_t I0> requires(I0 <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::extract( index_t<I0> const&) noexcept ;
}
```

Extract a `kumi::tuple` from the current object.

`tuple::extract` takes two parameters `i0` and `i1` and will return the tuple containing all
the elements of the original tuple between index `i0` and `i1` excluded. As for `operator[]`,
indexes can be passed via the index user-defined literal or the `kumi::index<N>` template variable.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto part = a.extract(1_c,4_c);

  std::cout << a << "\n";
  std::cout << part << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 6 7 89 )
( 2.3 4.5 6 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If `i1` is omitted, all elements between `i0` and the end of the tuple are extracted.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto part = a.extract(2_c);

  std::cout << a << "\n";
  std::cout << part << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 6 7 89 )
( 4.5 6 7 89 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `tuple::split`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I0> requires(I0 <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::split( index_t<I0> const&) const noexcept;

  template<std::size_t I0> requires(I0 <= sizeof...(Ts))
  [[nodiscard]] constexpr auto tuple::split( index_t<I0> const&)  noexcept;
}
```

Split a `kumi::tuple` in two new `kumi::tuple` containing all the elements before and after
a given index. As for `tuple::extract`, indexes can be passed via the index user-defined literal
or the `kumi::index<N>` template variable.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto[first, second] = a.split(3_c);

  std::cout << a      << "\n";
  std::cout << first  << "\n";
  std::cout << second << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 6 7 89 )
( 1 2.3 4.5 )
( 6 7 89 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~