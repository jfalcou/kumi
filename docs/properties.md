# Informations about Tuples

## Standard library integration
`kumi::tuple` is compatible with the standard traits pertaining to tuple manipulation, namely
`std::tuple_size` and `std::tuple_element`

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  using type = decltype(t);

  std::cout << std::tuple_size<type>::value << "\n";
  std::cout << std::boolalpha
            << std::is_same_v<std::tuple_element_t<1,type>,double>
            << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4
true
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Operators

### Comparison operators

**Synopsis:**
```c++
namespace kumi
{
  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator==(tuple const &lhs, Other const &rhs) noexcept;

  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator!=(tuple const &lhs, Other const &rhs) noexcept;

  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator<(tuple const &lhs, Other const &rhs) noexcept;

  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator<=(tuple const &lhs, Other const &rhs) noexcept;

  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator>(tuple const &lhs, Other const &rhs) noexcept;

  template<sized_product_type<sizeof...(Ts)> Other>
  constexpr auto operator>=(tuple const &lhs, Other const &rhs) noexcept;
}
```

1-2. Compares every element of the tuple `lhs` with the corresponding element of the tuple `rhs`.
3-6. Compares the contents of `lhs` and `rhs` lexicographically.

### Streaming operators

**Synopsis:**
```c++
namespace kumi
{
  template<typename Stream> Stream& operator<<(Stream& os, tuple const &t);
}
```

Insert the content of a given `kumi::tuple` in a standard output stream.

## Helper Functions

### `tuple::size`

**Synopsis:**
```c++
namespace kumi
{
  [[nodiscard]] static constexpr auto tuple::size() noexcept;
}
```

Returns the number of elements in a `kumi::tuple`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  kumi::tuple e = {};

  std::cout << t.size() << "\n";
  std::cout << e.size() << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4
0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `tuple::empty`

**Synopsis:**
```c++
namespace tuple
{
  [[nodiscard]] static constexpr bool tuple::empty() noexcept;
}
```

Returns `true` if the number of elements in a `kumi::tuple`is equal to 0 and `false` otherwise.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  kumi::tuple e = {};

  std::cout << std::boolalpha << t.empty() << "\n";
  std::cout << std::boolalpha << e.empty() << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
false
true
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
