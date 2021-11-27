# Algorithms

## Transformation
#### `for_each`

**Synopsis:**
```c++
template<typename Function, typename... Ts>
constexpr void for_each(Function f, tuple<Ts...>& t);

template<typename Function, typename... Ts>
constexpr void for_each(Function f, tuple<Ts...> const& t);
```

Invoke the `Function` object `f` on each elements of a given tuple.

[**Example:**](https://godbolt.org/z/o3Kh4PdT3)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.3,0.43f};
  kumi::for_each( [](auto& m) { m *= 10.f; }, t);
  std::cout << t << "\n";
}
```

**Expected output:**
```bash
( 10 23 4.3 )
```

#### `for_each_index`

**Synopsis:**
```c++
template<typename Function, typename... Ts>
constexpr void for_each_index(Function f, tuple<Ts...>& t);

template<typename Function, typename... Ts>
constexpr void for_each_index(Function f, tuple<Ts...> const& t);
```

Invoke the `Function` object `f` on each elements of a given tuple while passing the constexpr index
of said elements.

[**Example:**](https://godbolt.org/z/GzcP7Y89h)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.3,0.43f};
  kumi::for_each_index( [](auto i, auto& m) { m *= i*2; }, t);
  std::cout << t << "\n";
}
```

**Expected output:**
```bash
( 0 4.6 1.72 )
```

#### `map`

**Synopsis:**
```c++
template<typename... Ts, typename Function, sized_product_type<sizeof...(Ts)>... Tuples>
constexpr auto map(Function f, tuple<Ts...> const& t0, Tuples const&... others);
```

Applies the given function to all the tuples passed as arguments and stores the result in another
tuple, keeping the original elements order.

[**Example:**](https://godbolt.org/z/3G8P9shnh)
```c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{'a','b','c'};
  auto r = kumi::map( [](auto l, auto r) { return l+r; }, lhs, rhs);
  std::cout << r << "\n";
}
```

**Expected output:**
```bash
( 98 100 102 )
```

## Query

## Restructuration

### `cat`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type... Tuples> [[nodiscard]] constexpr auto cat(Tuples const&... ts );
}
```

Contructs a `kumi::tuple` containing all elements of each `ts` in succession.

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type... Tuples> struct cat
  {
    using type = decltype( kumi::cat( std::declval<Tuples>()... ) );
  };

  template<product_type... Tuples> using cat_t  = typename cat<Tuples...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the result type of a call to `kumi::cat(Tuples{}...)`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 1, 2.3, 4.5f};
  kumi::tuple b = {  '6' };
  kumi::tuple c = { "7", short{89} };

  auto abc = cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 ) ( 6 ) ( 7 89 )
( 1 2.3 4.5 6 7 89 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `flatten`

**Synopsis:**
```c++
namespace kumi
{
  template<typename... Ts> [[nodiscard]] constexpr auto flatten(tuple<Ts...> const& ts)
}
```

Converts a tuple of tuples into a tuple of all elements of said tuples. Non-tuple elements are
kept as-is.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto nbrs = kumi::tuple{1,2,3};
  auto more_nbrs = kumi::tuple{0,nbrs,4};
  auto ltrs = kumi::tuple{'a','b','c'};

  auto r = kumi::flatten( kumi::tuple{3.5,nbrs,'z',more_nbrs,5.35f,ltrs} );
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 3.5 1 2 3 z 0 ( 1 2 3 ) 4 5.35 a b c )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `flatten_all`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Func, typename... Ts>
  [[nodiscard]] constexpr auto flatten_all(tuple<Ts...> const& ts, Func&& f)

  template<typename... Ts>
  [[nodiscard]] constexpr auto flatten_all(tuple<Ts...> const& ts)
}
```

1. Recursively converts a tuple of tuples `t`into a tuple of all elements of said tuples. Non-tuple
elements processed by the callable object `f` before being inserted.

2. Recursively converts a tuple of tuples `t`into a tuple of all elements of said tuples. Non-tuple
elements are kept as-is unless a callable object

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type Tuple, typename Func = void> struct flatten_all
  {
    using type = decltype( kumi::flatten_all( std::declval<Tuple>(), std::declval<Func>() ) );
  };

  template<product_type Tuple> struct flatten_all<Tuple>
  {
    using type = decltype( kumi::flatten_all( std::declval<Tuple>() ) );
  };

  template<product_type Tuple, typename Func = void>
  using flatten_all_t  = typename flatten_all<Tuple, Func>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Computes the result of a call to `kumi::flatten_all(Tuple{},Func{})`
2. Computes the result of a call to `kumi::flatten_all(Tuple{},Func{})`

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto nbrs      = kumi::tuple{1,2,3};
  auto more_nbrs = kumi::tuple{0,nbrs,4};
  auto ltrs      = kumi::tuple{'a','b','c'};

  auto r = kumi::flatten_all( kumi::tuple{3.5,nbrs,'z',more_nbrs,5.35f,ltrs} );
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 3.5 1 2 3 z 0 1 2 3 4 5.35 a b c )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `transpose`

**Synopsis:**
```c++
namespace kumi
{
  template<typename... Ts> [[nodiscard]] constexpr auto transpose(tuple<Ts...> const& ts)
}
```

Transpose a tuple of tuples by shifting elements in their transposed position

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type Tuple>
  struct transpose
  {
    using type = decltype( kumi::transpose( std::declval<Tuple>() ) );
  };

  template<product_type Tuple>
  using transpose_t = typename transpose<Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the result type of a call to `kumi::transpose(Tuple{})`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple { kumi::tuple{ 1, 'a', 0.1   }
                            , kumi::tuple{ 2, 'b', 0.01  }
                            };

  auto r = kumi::transpose(values );
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( ( 1 2 ) ( a b ) ( 0.1 0.01 ) )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `zip`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type T0, product_type... Ts>
  requires((std::remove_cvref_t<T0>::size() == std::remove_cvref_t<Ts>::size()) && ...)
  [[nodiscard]] constexpr auto zip(T0 &&t0, Ts &&...tuples)
}
```

Constructs a tuple where the ith element contains the tuple of all ith elements of the input tuples.

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type T0, product_type... Ts>
  struct zip
  {
    using type = decltype( kumi::zip( std::declval<T0>(), std::declval<Ts>()... ) );
  };

  template<product_type T0, product_type... Ts>
  using zip_t = typename zip<T0,Ts...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compute the result type of a call to `kumi::zip(T0{},Ts{}...)`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>

int main()
{
  auto nbrs  = kumi::tuple{1,2,3};
  auto ltrs  = kumi::tuple{'a','b','c'};
  auto ratio = kumi::tuple{0.1,0.01,0.001};

  auto r = kumi::zip( nbrs, ltrs, ratio );
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( ( 1 a 0.1 ) ( 2 b 0.01 ) ( 3 c 0.001 ) )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Reduction

### `fold_left`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Function, product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto fold_left(Function f, Tuple const& t, Value init);
}
```

Computes the generalized sum of all elements of a tuple using a tail recursive scheme:

```
fold_left( f, (1 2 3), 0) = f( f( f(0, 1), 2), 3)
```

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename Function, product_type Tuple, typename Value>
  struct fold_left
  {
    using type = decltype ( kumi::fold_left( std::declval<Function>()
                                            , std::declval<Tuple>()
                                            , std::declval<Value>()
                                            )
                          );
  };

  template<typename Function, product_type Tuple, typename Value>
  using fold_left_t = typename fold_left<Function,Tuple,Value>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compute the return type of a call to `fold_left(Function{}, Tuple{}, Value{})`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>
#include <vector>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},'z'};

  auto output  = kumi::fold_left( [](auto a, auto m) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1
2
4
8
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `fold_right`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Function, product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto fold_right(Function f, Tuple const& t, Value init);
}
```

Computes the generalized sum of all elements of a tuple using a non-tail recursive scheme:

```
fold_right( f, (1 2 3), 0) = f(1, f(2 , f(3, 0))
```

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename Function, product_type Tuple, typename Value>
  struct fold_right
  {
    using type = decltype ( kumi::fold_right( std::declval<Function>()
                                            , std::declval<Tuple>()
                                            , std::declval<Value>()
                                            )
                          );
  };

  template<typename Function, product_type Tuple, typename Value>
  using fold_right_t = typename fold_right<Function,Tuple,Value>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compute the return type of a call to `fold_right(Function{}, Tuple{}, Value{})`.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi.hpp>
#include <iostream>
#include <vector>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},'z'};

  auto output  = kumi::fold_right( [](auto a, auto m) { a.push_back(sizeof(m)); return a; }
                                , t
                                , std::vector<std::size_t>{}
                                );

  for(auto s : output) std::cout << s << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
8
4
2
1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
