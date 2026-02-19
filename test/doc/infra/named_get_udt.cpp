/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

namespace ns
{
  using namespace kumi::literals;

  struct people
  {
    std::string name;
    int         age;
  };

  template<kumi::concepts::identifier auto ID>
  decltype(auto) get(people const& s) noexcept
  {
    if constexpr(ID == "name"_id) return s.name;
    if constexpr(ID == "age"_id) return s.age;
  }

  template<kumi::concepts::identifier auto ID>
  decltype(auto) get(people& s) noexcept
  {
    if constexpr(ID=="name"_id) return s.name;
    if constexpr(ID=="age"_id) return s.age;
  }
}

// Opt-in for Record Type semantic
template<>
struct kumi::is_record_type<ns::people> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<ns::people>
      : std::integral_constant<std::size_t,2> {};

template<> struct std::tuple_element<0,ns::people> { using type = kumi::field<kumi::name<"name">,std::string>;  };
template<> struct std::tuple_element<1,ns::people> { using type = kumi::field<kumi::name<"age"> ,int        >;  };

int main()
{
  using namespace kumi::literals;
  ns::people peter{"Peter Parker", 24};
    
  std::cout << get<"name"_id>(peter) << "\n";
  std::cout << get<"age"_id> (peter) << "\n";
}
