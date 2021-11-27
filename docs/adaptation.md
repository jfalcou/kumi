# Adapting existing type as tuple

If `kumi::tuple` is the readily available tuple type that **KUMI** can handle,
you can adapt other types to be compatible with **KUMI** operations.

## General Principles
To be able to be used by **KUMI**, you need to adapt your type so it is usable with structured
bindings. This invloves providing specialisation for `std::tuple_size`, `std::tuple_element` and
to provide an ADL-reachable `get<I>` function. Note that the specialisation for the tuple traits
does not require the inclusion of `tuple` header but only `utility`.

Being able to support structured bindings is not enough as some structured bindign compatible
type may not be suitable as a product type. In order to be usable with **KUMI**, your type needs
to opt-in for the so called Product Type concept.

This can be done in two ways:
  - exposing an internal `is_product_type` type that evaluates to `void`
  - specialising the `kumi::is_product_type` template class so it exposes a static constant member `value` that evaluates to `true`

Once done, the type is now usable directly in any kind of **KUMI** operation

## Examples

### Existing type
Let's adapt `std::array`. As `std::array`is already compatible with structured bindings, we only need to opt-in to the Product Type concept.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <iostream>
#include <kumi.hpp>
#include <array>

template<typename T, std::size_t N>
struct  kumi::is_product_type<std::array<T,N>>
      : std::true_type
{};

int main()
{
  std::array<float,5> vs{0.1f,1.2f,2.3f,3.4f,4.5f};
  kumi::for_each_index( [](int i, auto e)
                        {
                          std::cout << "#" << i << " : " << e << "\n";
                        }
                      , vs
                      );
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#0 : 0.1
#1 : 1.2
#2 : 2.3
#3 : 3.4
#4 : 4.5
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


### Adapting an User-Defined type
For user-defined type, you must first adapt it to support structured bindings, then opt-in. The opt-in can be done from inside the type directly in this case.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ c++
#include <iostream>
#include <kumi.hpp>

namespace ns
{
  struct box
  {
    using is_product_type = void;
    int i;
    float f;
    char c;
  };

  template<std::size_t I> decltype(auto)
  get(box const& s) noexcept
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }

  template<std::size_t I>  decltype(auto)
  get(box& s) noexcept
  {
    if constexpr(I==0) return s.i;
    if constexpr(I==1) return s.f;
    if constexpr(I==2) return s.c;
  }
}

template<>
struct  std::tuple_size<ns::box>
      : std::integral_constant<std::size_t,3> {};

template<> struct std::tuple_element<0,ns::box> { using type = int;   };
template<> struct std::tuple_element<1,ns::box> { using type = float; };
template<> struct std::tuple_element<2,ns::box> { using type = char;  };

int main()
{
  ns::box bx{1,2.3f,'Z'};
  kumi::for_each_index( [](int i, auto e)
                        {
                          std::cout << "#" << i
                                    << " : " << e
                                    << "\n";
                        }
                      , bx
                      );
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Expected output:**
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#0 : 1
#1 : 2.3
#2 : Z
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
