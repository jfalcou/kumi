//======================================================================================================================
/*
  KIWAKU - Containers Well Made
  Copyright : KIWAKU Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::_
{
  // Type -> String converter
  template<typename T> constexpr auto typer() noexcept
  {
#if defined(__clang__)
    constexpr auto pfx = kumi::str{"auto kumi::_::typer() [T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__, std::integral_constant<std::size_t, pfx>{},
                                     std::integral_constant<std::size_t, sfx>{}};
#elif defined(__GNUC__)
    constexpr auto pfx = kumi::str{"constexpr auto kumi::_::typer() [with T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__, std::integral_constant<std::size_t, pfx>{},
                                     std::integral_constant<std::size_t, sfx>{}};
#elif defined(_MSC_VER)
    constexpr auto pfx = kumi::str{"auto __cdecl kumi::_::typer<"}.size();
    constexpr auto sfx = kumi::str{">(void)"}.size();
    constexpr auto value =
      kumi::str{__FUNCSIG__, std::integral_constant<std::size_t, pfx>{}, std::integral_constant<std::size_t, sfx>{}};
#endif
    return value;
  }
}
