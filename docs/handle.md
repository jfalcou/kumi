# Modifying Elements

## Element insertion

### `kumi::push_front`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple, typename T>
  [[nodiscard]] constexpr auto push_front(Tuple const& t, T&& v);
}
```

Return the `kumi::tuple` constructed from the concatenation of `v` and `t`.

**Helper Type:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
namespace kumi::result
{
  template<product_type Tuple, typename T> struct push_front;
  template<product_type Tuple, typename T> using push_front_t = typename push_front<Tuple,T>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`kumi::result::push_front<Tuple,T>` computes the type resulting of the call to `push_front` on a
tuple `Tuple`and a value of type `T`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  std::cout << kumi::push_front( kumi::tuple{}, 63.21)  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                          << "\n";
  std::cout << kumi::push_front(t, 'Z')   << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 63.21 )
( 1 2 3.4 )
( Z 1 2 3.4 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `kumi::push_back`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple, typename T>
  [[nodiscard]] constexpr auto push_back(Tuple const& t, T&& v);
}
```

Return the `kumi::tuple` constructed from the concatenation of `t` and `v`.

**Helper Type:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
namespace kumi::result
{
  template<product_type Tuple, typename T> struct push_back;
  template<product_type Tuple, typename T> using push_back_t = typename push_back<Tuple,T>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`kumi::result::push_back<Tuple,T>` computes the type resulting of the call to `push_back` on a
tuple `Tuple`and a value of type `T`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  std::cout << kumi::push_back( kumi::tuple{}, 63.21)  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                          << "\n";
  std::cout << kumi::push_back(t, 'Z')   << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 63.21 )
( 1 2 3.4 )
( 1 2 3.4 Z )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Element removal

### `kumi::pop_front`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple>
  [[nodiscard]] constexpr auto pop_front(Tuple const& t);
}
```

Return the `kumi::tuple` constructed from the removal of the first (if any) element of `t`.

**Helper Type:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
namespace kumi::result
{
  template<product_type Tuple> struct pop_front;
  template<product_type Tuple> using pop_front_t = typename pop_front<Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`kumi::result::pop_front<Tuple>` computes the type resulting of the call to `pop_front` on a
tuple of type `Tuple`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  std::cout << kumi::pop_front( kumi::tuple{} )  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                    << "\n";
  std::cout << kumi::pop_front(t)   << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( )
( 1 2 3.4 )
( 2 3.4 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `kumi::pop_back`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple>
  [[nodiscard]] constexpr auto pop_back(Tuple const& t);
}
```

Return the `kumi::tuple` constructed from the removal of the last (if any) element of `t`.

**Helper Type:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
namespace kumi::result
{
  template<product_type Tuple> struct pop_back;
  template<product_type Tuple> using  pop_back_t = typename pop_back<Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`kumi::result::pop_back<Tuple>` computes the type resulting of the call to `pop_back` on a
tuple of type `Tuple`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  std::cout << kumi::pop_back( kumi::tuple{} )  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                    << "\n";
  std::cout << kumi::pop_back(t)   << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( )
( 1 2 3.4 )
( 1 2 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Layout Management

### `tuple::as_flat_ptr`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple>
  [[nodiscard]] auto as_flat_ptr(Tuple&& t) noexcept;
}
```

Convert a `kumi::product_type` to a flat tuple containing a pointer to each of the tuple passed as
an argument.

`tuple::as_flat_ptr` is useful when one needs to access all element of a tuple without having to
take care of its internal structure and potential nesting.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 1, kumi::tuple{ 2.3, 4.5f }, short{89} };

  auto ptr = kumi::as_flat_ptr(a);

  std::cout << a << "\n";
  std::cout << ptr << "\n";

  kumi::for_each([](auto ptr) { *ptr += 5; }, ptr );

  std::cout << a << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 ( 2.3 4.5 ) 89 )
( 0x7fffc7c341a0 0x7fffc7c341a8 0x7fffc7c341b0 0x7fffc7c341b8 )
( 6 ( 7.3 9.5 ) 94 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
#include <kumi/tuple.hpp>
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
#include <kumi/tuple.hpp>
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

**Helper Type:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
namespace kumi::result
{
  template<product_type T, std::size_t I0> struct split;
  template<product_type T, std::size_t I0> using split_t = typename split<T,I0>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`kumi::result::split<T,I0>` computes the type resulting of the call to `split(index<I0>)` on a
type of type T.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
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
