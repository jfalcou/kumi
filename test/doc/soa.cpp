#include <iostream>
#include <kumi/kumi.hpp>

#include <algorithm>
#include <ranges>
#include <vector>

template <class... Ts>
struct soa
{
  kumi::tuple<std::vector<Ts>...> fields;

  struct iterator 
  {
    using value_type = kumi::tuple<Ts...>;

    soa* s;
    std::size_t i;

    auto operator==(iterator b)   const -> bool { return i ==  b.i; }
    auto operator<=>(iterator b)  const         { return i <=> b.i; }

    auto operator++() ->iterator& { ++i; return *this; }
    auto operator--() ->iterator& { --i; return *this; }
    auto operator++(int) ->iterator { auto copy = *this; ++*this; return copy; }
    auto operator--(int) ->iterator { auto copy = *this; --*this; return copy; }

    friend auto operator+(iterator a, std::size_t b) -> iterator{ return {.s = a.s, .i = a.i + b}; }
    friend auto operator+(std::size_t a, iterator b) -> iterator{ return {.s = b.s, .i = a + b.i}; }
    friend auto operator-(iterator a, std::size_t b) -> iterator{ return {.s = a.s, .i = a.i - b}; }
    friend auto operator-(std::size_t a, iterator b) -> iterator{ return {.s = b.s, .i = a - b.i}; }

    auto operator+=(std::size_t b) -> iterator& { i += b; return *this; }
    auto operator-=(std::size_t b) -> iterator& { i -= b; return *this; }
    
    auto operator-(iterator b) const -> std::ptrdiff_t { return i - b.i; }

    auto operator*() const 
    {
      return kumi::apply([&](auto&... vs) { return kumi::tie(vs[i]...); }, s->fields);
    }
    
    auto operator[](std::ptrdiff_t b) const 
    { 
      return kumi::apply([&](auto&... vs) { return kumi::tie(vs[i + b]...); }, s->fields);
    }
  };

    auto begin()  -> iterator { return {.s = this, .i = 0                           }; }
    auto end()    -> iterator { return {.s = this, .i = kumi::get<0>(fields).size() }; }
};

static_assert(std::random_access_iterator<soa<int>::iterator>);

int main()
{
  soa<float,int> s;
  get<0>(s.fields) = {1.2,2.3,3.4,4.5};
  get<1>(s.fields) = {10,20,30,40};

  for(auto e : s)
    std::cout << e << "\n";
}

