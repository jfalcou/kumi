//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::concepts
{
  //====================================================================================================================
  /**
    @ingroup kumi_concepts
    @brief Concept specifying a type is a pipeline stage: a callable class that is not a product type.

    A kumi algorithm, what kumi::bind_front, kumi::bind_back or `operator[]` make of one, and a pipeline built by
    `operator|` are all stages.
  **/
  //====================================================================================================================
  template<typename S>
  concept stage = std::is_class_v<std::remove_cvref_t<S>> && !kumi::concepts::product_type<std::remove_cvref_t<S>>;
}

namespace kumi::function
{
  //====================================================================================================================
  /**
    @ingroup kumi_functional
    @brief Pipeline of two stages, applied one after the other.

    `f | g` builds a `pipe<F, G>`; `a | b | c` builds `pipe<pipe<A, B>, C>` and applies as `c(b(a(t)))`. A pipeline is
    a value: built once, applied to any product type any number of times, and a stage itself.

    The stages live in kumi leaves, so an empty stage takes no room.

    @groupheader{Header file}
    @code
    #include <kumi/functional/pipe.hpp>
    @endcode

    @groupheader{Call Signature}
    @code
      template<stage F, stage G>
      constexpr auto operator|(F f, G g);
    @endcode

    @subgroupheader{Parameters}
      - `f`: First stage
      - `g`: Second stage, applied to what `f` returns

    @subgroupheader{Return value}
      A `pipe<F, G>` stage.

    @groupheader{Example}
    @godbolt{doc/infra/pipe.cpp}
  **/
  //====================================================================================================================
  template<typename F, typename G> struct pipe : kumi::_::leaf<0, F>, kumi::_::leaf<1, G>
  {
    using first = kumi::_::leaf<0, F>;
    using second = kumi::_::leaf<1, G>;

    template<typename T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      auto const& f = static_cast<first const&>(*this)(typename first::index{});
      auto const& g = static_cast<second const&>(*this)(typename second::index{});
      return g(f(KUMI_FWD(t)));
    }
  };

  template<kumi::concepts::stage F, kumi::concepts::stage G> [[nodiscard]] KUMI_ABI constexpr auto operator|(F f, G g)
  {
    return pipe<F, G>{{f}, {g}};
  }
}

namespace kumi
{
  // The operands are kumi algorithms and binders, whose namespaces do not reach kumi::function through ADL.
  using function::operator|;
}
