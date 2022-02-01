# Algorithms

## Transformation

### `apply`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Function, product_type Tuple>
  constexpr decltype(auto) apply(Function f, Tuple&& t);
}
```

Invoke the `Function` object `f` with a tuple of arguments and returns the result of this invocation.

**Helper Trait:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename Function, product_type Tuple> struct apply;
  template<typename Function, product_type Tuple> using  apply_t = typename apply<Function,Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::map` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.,3.f};
  std::cout << kumi::apply( [](auto... m) { return (m + ...); }, t);
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `for_each`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Function, typename... Ts>
  constexpr void for_each(Function f, tuple<Ts...>& t);

  template<typename Function, typename... Ts>
  constexpr void for_each(Function f, tuple<Ts...> const& t);
}
```

Invoke the `Function` object `f` on each elements of a given tuple.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.3,0.43f};
  kumi::for_each( [](auto& m) { m *= 10.f; }, t);
  std::cout << t << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 10 23 4.3 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `for_each_index`

**Synopsis:**
```c++
namespace kumi
{
  template<typename Function, typename... Ts>
  constexpr void for_each_index(Function f, tuple<Ts...>& t);

  template<typename Function, typename... Ts>
  constexpr void for_each_index(Function f, tuple<Ts...> const& t);
}
```

Invoke the `Function` object `f` on each elements of a given tuple while passing the constexpr index
of said elements.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.3,0.43f};
  kumi::for_each_index( [](auto i, auto& m) { m *= i*2; }, t);
  std::cout << t << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 0 4.6 1.72 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `map`

**Synopsis:**
```c++
namespace kumi
{
  template<typename... Ts, typename Function, sized_product_type<sizeof...(Ts)>... Tuples>
  constexpr auto map(Function f, tuple<Ts...> const& t0, Tuples const&... others);
}
```

Applies the given function to all the tuples passed as arguments and stores the result in another
tuple, keeping the original elements order.

**Helper Trait:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
  struct map;

  template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
  using map_t = typename map<Function,T,Ts...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::map` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{'a','b','c'};
  auto r = kumi::map( [](auto l, auto r) { return l+r; }, lhs, rhs);
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 98 100 102 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~







### `map_index`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple, typename Function, sized_product_type<size<Tuple>::value>... Tuples>
  constexpr auto map_index(Function     f,Tuple  &&t0,Tuples &&...others)
}
```

Applies the given function to all the tuples passed as arguments with the associated index and
stores the result in another tuple, keeping the original elements order.

**Helper Trait:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
  struct map_index;

  template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
  using map_index_t = typename map_index<Function,T,Ts...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::map_index` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{'a','b','c'};
  auto r = kumi::map_index( [](auto i, auto l, auto r) { return 1000*(i+1)+(l*r); }, lhs, rhs);
  std::cout << r << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1097 2196 3297 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
  template<product_type... Tuples> struct cat;
  template<product_type... Tuples> using  cat_t  = typename cat<Tuples...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::cat` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type Tuple> struct flatten;
  template<product_type Tuple> using  flatten_t  = typename flatten<Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::flatten` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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
  template<product_type Tuple, typename Func = void> struct flatten_all;
  template<product_type Tuple, typename Func = void>
  using flatten_all_t  = typename flatten_all<Tuple, Func>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::flatten_all` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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

### `reorder`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t... Idx, product_type Tuple>
  requires((Idx < size<Tuple>::value) && ...) [[nodiscard]] constexpr auto reorder(Tuple &&t);
}
```

Return a tuple which values are taken from t and reordered following the `Idx...` indexes.

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<product_type Tuple, std::size_t... Is> struct reorder;
  template<product_type Tuple, std::size_t... Is> using  reorder_t = typename reorder<Tuple,Is...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::reorder` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple { 1, 'a', 0.1 };

  std::cout << values << "\n";
  std::cout << kumi::reorder<2,1,0>(values) << "\n";
  std::cout << kumi::reorder<2,1,0,1,2>(values) << "\n";
  std::cout << kumi::reorder<1,1>(values) << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 a 0.1 )
( 0.1 a 1 )
( 0.1 a 1 a 0.1 )
( a a )
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
  template<product_type Tuple> struct transpose;
  template<product_type Tuple> using  transpose_t = typename transpose<Tuple>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::transpose` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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
  template<product_type T0, product_type... Ts> struct zip;
  template<product_type T0, product_type... Ts> using  zip_t = typename zip<T0,Ts...>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::zip` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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
  template<typename Function, product_type Tuple, typename Value> struct fold_left;
  template<typename Function, product_type Tuple, typename Value>
  using fold_left_t = typename fold_left<Function,Tuple,Value>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::fold_left` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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
  template<typename Function, product_type Tuple, typename Value> struct fold_right;

  template<typename Function, product_type Tuple, typename Value>
  using fold_right_t = typename fold_right<Function,Tuple,Value>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::fold_rigth` on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
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


### `max`, `max_flat`

**Synopsis:**
```c++
namespace kumi
{
  template<typename T, typename F>
  [[nodiscard]] constexpr auto max(T const& data, F func) noexcept;

  template<typename T, typename F>
  [[nodiscard]] constexpr auto max_flat(T const& data, F func) noexcept;
}
```

`kumi::max` computes the maximum value of applications of `func` to all elements of the tuple `data`.
`kumi::max_flat` computes the maximum value of applications of `func` to all elements of the flattened
version of the tuple `data`

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename T, typename F> struct max;
  template<typename T, typename F> struct max_flat;
  template<typename T, typename F> using max_t = typename max<T,F>::type;
  template<typename T, typename F> using max_flat_t = typename max_flat<T,F>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::max` or `kumi::max_flat`on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto f0 = kumi::tuple {'e', 2., kumi::tuple {1., 'u', 3. }, 3.f, 'z'};

  std::cout << kumi::max(f0       , [](auto m) { return sizeof(m); }) << "\n";
  std::cout << kumi::max_flat (f0 , [](auto m) { return sizeof(m); }) << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
24
8
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `min`, `min_flat`

**Synopsis:**
```c++
namespace kumi
{
  template<typename T, typename F>
  [[nodiscard]] constexpr auto min(T const& data, F func) noexcept;

  template<typename T, typename F>
  [[nodiscard]] constexpr auto min_flat(T const& data, F func) noexcept;
}
```

`kumi::min` computes the minimum value of applications of `func` to all elements of the tuple `data`.
`kumi::min_flat` computes the minimum value of applications of `func` to all elements of the flattened
version of the tuple `data`

**Helper Traits:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
namespace kumi::result
{
  template<typename T, typename F> struct min;
  template<typename T, typename F> struct min_flat;
  template<typename T, typename F> using min_t = typename min<T,F>::type;
  template<typename T, typename F> using min_flat_t = typename min_flat<T,F>::type;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Computes the type returned by a call to `kumi::min` or `kumi::min_flat`on a given set of parameters.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto f0 = kumi::tuple {2., kumi::tuple {1., 'u', 3. }, 3.f };

  std::cout << kumi::min(f0       , [](auto m) { return sizeof(m); }) << "\n";
  std::cout << kumi::min_flat (f0 , [](auto m) { return sizeof(m); }) << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4
1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
