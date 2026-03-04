//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @ingroup utility
  //! @class  projection_map
  //! @brief
  //!
  //! @note Can only contains integral constant, identifiers or other projection maps
  //================================================================================================
  template<concepts::projection... V> struct projection_map
  {
    static constexpr bool is_projection_map = true;
    using type = tuple<V...>;

    consteval projection_map() noexcept = default;

    consteval explicit projection_map(V...) noexcept {};

    //==============================================================================================
    //! @name Properties
    //! @{
    //==============================================================================================

    /// Returns the number of elements in a kumi::indexes_t
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(V); };

    /// Returns `true` if a kumi::indexes_t contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return sizeof...(V) == 0; };

    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @name Accessors
    //! @{
    //==============================================================================================

    //==============================================================================================
    //! @brief Extracts the Ith element from a kumi::indexes_t
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @tparam  I Compile-time index of the element to access
    //! @return A copy of the value of the selected element of current indexes_t.
    //==============================================================================================
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(projection_map&) noexcept
    {
      using ret_t = element_t<I, type>;
      return ret_t{};
    }

    /// @overload
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(projection_map const&) noexcept
    {
      using ret_t = element_t<I, type>;
      return ret_t{};
    }

    //==============================================================================================
    //! @}
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         projection_map const& i) noexcept
    {
      os << '[';
      [&]<std::size_t... I>(std::index_sequence<I...>) {
        ((os << get<I>(i) << ", "), ...);
      }(std::make_index_sequence<sizeof...(V) - 1>());
      os << get<sizeof...(V) - 1>(i) << ']';

      return os;
    }
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief kumi::indexes_t deduction guide
  //! @tparam Ts  Type lists to build the indexes with.
  //================================================================================================
  template<concepts::projection... Ts> KUMI_CUDA projection_map(Ts...) -> projection_map<Ts...>;

  //================================================================================================
  //! @ingroup utility
  //! @brief Creates a kumi::indexes object, deducing the target type from the types of arguments.
  //!
  //! @note The arguments should model kumi::indexer
  //!
  //! @param ts	Zero or more indexes to construct the indexes from.
  //! @return A kumi::indexes constructed from the ts
  //================================================================================================
  template<concepts::index... Ts> [[nodiscard]] KUMI_ABI consteval auto indexes(Ts... ts) noexcept
  {
    return projection_map{ts...};
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Creates a kumi::projection_map object, deducing the target type from the types of arguments.
  //!
  //! @note The arguments should model kumi::identifier
  //!
  //! @param ts	Zero or more indexes to construct the indexes from.
  //! @return A kumi::indexes constructed from the ts
  //================================================================================================
  template<concepts::identifier... Ts>
  requires(all_uniques_v<Ts...>)
  [[nodiscard]] KUMI_ABI consteval auto identifiers(Ts... ts) noexcept
  {
    return projection_map{ts...};
  }
}
