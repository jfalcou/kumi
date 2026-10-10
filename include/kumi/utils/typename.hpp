//======================================================================================================================
/*
  KUMI - Containers Well Made
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  // Type -> String converter
  template<typename T> [[nodiscard]] consteval auto typer() noexcept
  {
#if defined(__clang__)
    constexpr auto pfx = kumi::str{"auto kumi::typer() [T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__}
                             .remove_prefix(std::integral_constant<std::size_t, pfx>{})
                             .remove_suffix(std::integral_constant<std::size_t, sfx>{});
#elif defined(__GNUC__)
    constexpr auto pfx = kumi::str{"constexpr auto kumi::typer() [with T = "}.size();
    constexpr auto sfx = kumi::str{"]"}.size();
    constexpr auto value = kumi::str{__PRETTY_FUNCTION__}
                             .remove_prefix(std::integral_constant<std::size_t, pfx>{})
                             .remove_suffix(std::integral_constant<std::size_t, sfx>{});
#elif defined(_MSC_VER)
    constexpr auto pfx = kumi::str{"auto __cdecl kumi::typer<"}.size();
    constexpr auto sfx = kumi::str{">(void)"}.size();
    constexpr auto value = kumi::str{__FUNCSIG__}
                             .remove_prefix(std::integral_constant<std::size_t, pfx>{})
                             .remove_suffix(std::integral_constant<std::size_t, sfx>{});
#endif
    return value;
  }
}
