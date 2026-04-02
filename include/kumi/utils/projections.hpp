//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  namespace _
  {
    template<std::size_t I, typename T> struct value_at
    {
    };

    template<std::size_t I, auto Head, auto... Tail>
    struct value_at<I, kumi::projection_map<Head, Tail...>> : value_at<I - 1, kumi::projection_map<Tail...>>
    {
    };

    template<std::size_t I, auto... Vs> struct value_at<I, kumi::projection_map<Vs...> const>
    {
      static constexpr auto value = value_at<I, kumi::projection_map<Vs...>>::value;
    };

    template<auto Head, auto... Tail> struct value_at<0, kumi::projection_map<Head, Tail...>>
    {
      static constexpr auto value = Head;
    };
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @class   projection_map
    @brief   A stateless, compile-time schema for product type transformation.

    kumi::projection_map reifies the act of indexing or member access into a first-class
    type-level entity. It defines a sequence of accessors (projections) that can be applied
    to any kumi::product_type to extract, reorder, or reshape its components.

    Because it is a "Meta-Product Type" (a product of accessors), it allows for complex
    data manipulations (like zipping or partitioning) to be expressed as a single
    Non-Type Template Parameter (NTTP).

    @note This type is stateless and carries zero runtime data.
    @tparam V A pack of elements modeling kumi::concepts::projection.

    ## Examples:
    @include doc/infra/projections.cpp
  **/
  //====================================================================================================================
  template<auto... V> struct projection_map
  {
    static constexpr bool is_projection_map = true;

    consteval projection_map() noexcept = default;

    consteval explicit projection_map(auto...) noexcept {}

    //==================================================================================================================
    /**
      @name Properties
      @{
    **/
    //==================================================================================================================

    /// Returns the number of elements in a kumi::projection_map
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept { return sizeof...(V); }

    /// Returns `true` if a kumi::projection_map contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return sizeof...(V) == 0; }

    //==================================================================================================================
    //! @}
    //==================================================================================================================

    //==================================================================================================================
    /**
      @name Accessors
      @{
    **/
    //==================================================================================================================
    template<std::size_t I>
    requires(I < sizeof...(V))
    KUMI_ABI constexpr decltype(auto) operator[]([[maybe_unused]] index_t<I> i) const noexcept
    {
      return _::value_at<I, projection_map>::value;
    }

    //==================================================================================================================
    /**
      @brief Extracts the Ith element from a kumi::projection_map

      @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
      @tparam  I Compile-time index of the element to access
      @return A copy of the value of the selected element of current projection_map.
    **/
    //==================================================================================================================
    template<std::size_t I>
    requires(I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(projection_map const& pm) noexcept
    {
      return pm[index<I>];
    }

    //==================================================================================================================
    //! @}
    //==================================================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         projection_map const&) noexcept
    {
      std::size_t p = 0;
      os << '[';
      ((os << V << (++p < sizeof...(V) ? ", " : "")), ...);
      os << ']';
      return os;
    }
  };

  //====================================================================================================================
  /**
    @ingroup utility
    @brief kumi::projection_map deduction guide
    @tparam Ts  Type lists to build the projections with.
  **/
  //====================================================================================================================
  template<concepts::projection... Ts> KUMI_CUDA projection_map(Ts...) -> projection_map<Ts{}...>;

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Creates a kumi::projection_map object, deducing the target type from the types of arguments.

    @note The arguments should model kumi::index

    @tparam Ts	Zero or more indexes to construct the projection from.
    @return A kumi::projection_map constructed from the ts

    ## Examples:
    @include doc/infra/projections.cpp
  **/
  //====================================================================================================================
  template<concepts::index... Ts> [[nodiscard]] KUMI_ABI consteval auto indexes(Ts...) noexcept
  {
    return projection_map<Ts{}...>{};
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Creates a kumi::projection_map object, deducing the target type from the types of arguments.

    @note The arguments should model kumi::index

    @tparam vs	Zero or more values convertible to size_t to construct the projection from.
    @return A kumi::projection_map constructed from the vs

    ## Examples:
    @include doc/infra/projections.cpp
  **/
  //====================================================================================================================
  template<std::convertible_to<std::size_t> auto... vs> [[nodiscard]] KUMI_ABI consteval auto make_indexes() noexcept
  {
    return projection_map<index<vs>...>{};
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Creates a kumi::projection_map object, deducing the target type from the types of arguments.

    @note The arguments should model kumi::identifier

    @tparam Ts	Zero or more indexes to construct the projection from.
    @return A kumi::projection_map constructed from the ts

    ## Examples:
    @include doc/infra/projections.cpp
  **/
  //====================================================================================================================
  template<concepts::identifier... Ts>
  requires(all_uniques_v<Ts...>)
  [[nodiscard]] KUMI_ABI consteval auto identifiers(Ts...) noexcept
  {
    return projection_map<Ts{}...>{};
  }

  //====================================================================================================================
  // Specialisation to clearly signal errors due invalid projections
  //====================================================================================================================
  template<auto... Vs>
  requires(!concepts::projection<decltype(Vs)> && ...)
  struct projection_map<Vs...>
  {
    static_assert((concepts::projection<decltype(Vs)> && ...), "Invalid projections in projection_map definition");
    projection_map(decltype(Vs)...) = delete;
  };
}
