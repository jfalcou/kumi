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
  //! @class   projection_map
  //! @brief   A stateless, compile-time schema for product type transformation.
  //!
  //! kumi::projection_map reifies the act of indexing or member access into a first-class
  //! type-level entity. It defines a sequence of accessors (projections) that can be applied
  //! to any kumi::product_type to extract, reorder, or reshape its components.
  //!
  //! Because it is a "Meta-Product Type" (a product of accessors), it allows for complex
  //! data manipulations (like zipping or partitioning) to be expressed as a single
  //! Non-Type Template Parameter (NTTP).
  //!
  //! @note This type is stateless and carries zero runtime data.
  //! @tparam V A pack of elements modeling kumi::concepts::projection.
  //================================================================================================
  template<typename... V> struct projection_map
  {
    static constexpr bool is_projection_map = true;

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
    template<std::size_t I>
    requires(I < sizeof...(V))
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] index_t<I> i) const noexcept
    {
      return element_t<I, projection_map>{};
    }

    //==============================================================================================
    //! @brief Extracts the Ith element from a kumi::projection_map
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @tparam  I Compile-time index of the element to access
    //! @return A copy of the value of the selected element of current indexes_t.
    //==============================================================================================
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(projection_map const& pm) noexcept
    {
      return pm[index<I>];
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
  //! @brief Creates a kumi::projection_map object, deducing the target type from the types of arguments.
  //!
  //! @note The arguments should model kumi::index
  //!
  //! @param ts	Zero or more indexes to construct the indexes from.
  //! @return A kumi::projection_map constructed from the ts
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
  //! @return A kumi::projection_map constructed from the ts
  //================================================================================================
  template<concepts::identifier... Ts>
  requires(all_uniques_v<Ts...>)
  [[nodiscard]] KUMI_ABI consteval auto identifiers(Ts... ts) noexcept
  {
    return projection_map{ts...};
  }

  //================================================================================================
  // Specialisation to clearly signal errors due invalid projections
  //================================================================================================
  template<typename... Ts>
  requires(!concepts::projection<Ts> && ...)
  struct projection_map<Ts...>
  {
    static_assert((concepts::projection<Ts> && ...), "Invalid projections in projection_map definition");
    projection_map(Ts&&...) = delete;
  };
}
