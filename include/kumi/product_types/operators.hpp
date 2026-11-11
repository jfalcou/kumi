#pragma once

namespace kumi
{
  namespace arithmetic
  {
#define ARITHMETIC_BINOP_(op)

    template<typename T, typename U, std::size_t... I>
    constexpr auto(T&& t, U&& u, std::index_sequence<I...>)
    requires()
    noexcept()
    {
      using type = kumi::common_product_type_t<T, U>;
      return kumi::builder<type>((get<I>(KUMI_FWD(t)) op get<I>(KUMI_FWD(u)))...);
    }

#define ARITHMETIC_BINOP(op)

    template<kumi::concepts::product_type T, kumi::concepts::product_type U>
    requires(kumi::size_v<T> == kumi::size_v<U>)
    constexpr auto op(T&& t, U&& u)
    {
      return op_(kumi::__::adl_tag, KUMI_FWD(t), KUMI_FWD(y), kumi::indexes_for<T>{});
    }
  }
}
