
# Standard library integration
`kumi::tuple` is compatible with the standard traits pertaining to tuple manipulation, namely
`std::tuple_size` and `std::tuple_element`

[**Example:**](https://godbolt.org/z/9x9PbxafT)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  using type = decltype(t);

  std::cout << std::tuple_size<type>::value << "\n";
  std::cout << std::boolalpha << std::is_same_v<std::tuple_element_t<1,type>,double> << "\n";
}
```

**Expected output:**
```bash
4
true
```

# `tuple::size`

**Synopsis:**
```c++
[[nodiscard]] static constexpr auto tuple::size() noexcept;
```

Returns the number of elements in a `kumi::tuple`.

[**Example:**](https://godbolt.org/z/9hqxjsbz5)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  kumi::tuple e = {};

  std::cout << t.size() << "\n";
  std::cout << e.size() << "\n";
}
```

**Expected output:**
```bash
4
0
```

# `tuple::empty`

**Synopsis:**
```c++
[[nodiscard]] static constexpr bool tuple::empty() noexcept;
```

Returns `true` if the number of elements in a `kumi::tuple`is equal to 0 and `false` otherwise.

[**Example:**](https://godbolt.org/z/qbhzjjPWd)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  kumi::tuple e = {};

  std::cout << std::boolalpha << t.empty() << "\n";
  std::cout << std::boolalpha << e.empty() << "\n";
}
```

**Expected output:**
```bash
false
true
```
