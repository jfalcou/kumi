# Creating a Tuple

## Aggregate construction
The main way to construct a `kumi::tuple` is to construct it as an aggregate.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple<int,double,float> t = { 1, 2.3, 4.5f };
  std::cout << t << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Of course, you can also let the compiler deduce the proper type of the `kumi::tuple`:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '6' };
  std::cout << t << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1 2.3 4.5 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Factory function

### `kumi::make_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template <typename... Ts>
  [[nodiscard]] constexpr tuple<std::unwrap_ref_decay_t<Ts>...>  make_tuple(Ts&&... ts);
}
```

Creates a `kumi::tuple` object, deducing the target type from the types of arguments.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::make_tuple( 1, 2.3, 4.5f, '@');
  std::cout << t << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 1, 2.3, 4.5f, @)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `tie`

**Synopsis:**
```c++
namespace kumi
{
  template <typename... Ts> [[nodiscard]] constexpr tuple<Ts&...> tie(Ts&... ts);
}
```

Creates a `kumi::tuple` of lvalue references to its arguments.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

auto generate()
{
  return kumi::tuple{1,2.3,4.56f};
}

int main()
{
  int    i;
  double d;
  float  f;

  kumi::tie( i,d,f ) = generate();

  std::cout << i << " " << d << " " << f << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 2.3 4.56
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

### `forward_as_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template <typename... Ts> [[nodiscard]] constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... ts);
}
```

Constructs a `kumi::tuple` of references to the arguments in `ts`` suitable for forwarding as an
argument to a function. The `kumi::tuple` has rvalue reference data members when rvalues are used
as arguments, and otherwise has lvalue reference data members.

Note that, if the arguments are temporaries, `forward_as_tuple` does not extend their lifetime;
they have to be used before the end of the full expression.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>
#include <vector>
#include <string>

template<typename Data>
std::vector<std::string> build(Data d)
{
  return std::vector<std::string> ( kumi::get<0>(d)
                                  , std::move(kumi::get<1>(d))
                                  );
}

int main()
{
  auto v = build( kumi::forward_as_tuple(4,std::string{"the text !"}));

  for(auto const& s : v)
    std::cout << s << "\n";
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
the text !
the text !
the text !
the text !
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### `kumi::to_ref`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Type>
  [[nodiscard]] constexpr auto to_ref(Type&& that);
}
```

Creates a `kumi::tuple` of references given a reference to a `kuùi::product_type`.

Given an expression `e` so that `decltype((e))` models `kumi::product_type`, `kumi::to_ref(e)` is
an expression equivalent to

```c++
kumi::apply([](auto&&... elems){ return kumi::forward_as_tuple(KUMI_FWD(elems)...); }, e)
```

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto original = kumi::make_tuple(0,'0',0.f);
  auto ref = kumi::to_ref( original );

  std::cout << original << "\n";

  kumi::get<0>(ref) = 9;
  kumi::get<1>(ref) = 'z';
  kumi::get<2>(ref) = 3.14159f;

  std::cout << original << "\n";
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
( 0 0 0 )
( 9 z 3.14159 )
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


## Traits

### `as_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template<product_type Tuple, template<typename...> class Meta = std::type_identity>
  struct as_tuple;

  template<product_type Tuple, template<typename...> class Meta = std::type_identity>
  using as_tuple_t =  typename as_tuple<Tuple, Meta>::type;
}
```

Compute the exact `kumi::tuple` type containing the same element as `Tuple`, an arbitrary type
modeling `kumi::product_type`. A template meta-function can be optionnaly passed to be applied
to each of those types at type computation.

**Example:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <kumi/tuple.hpp>
#include <type_traits>
#include <array>

template<typename T, std::size_t N>
struct  kumi::is_product_type<std::array<T,N>>
      : std::true_type
{};

using three_floats = kumi::as_tuple_t<std::array<float,3>>;
using three_pointers = kumi::as_tuple_t<std::array<float,3>, std::add_pointer>;

static_assert( std::same_as<three_floats, kumi::tuple<float,float,float> >);
static_assert( std::same_as<three_pointers, kumi::tuple<float*,float*,float*> >);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
