#error This file is for documentation only - DO NOT INCLUDE
//! @page kumi_identity Identity Elements
//!
//! An [identity element](https://en.wikipedia.org/wiki/Identity_element), or neutral element, of a binary operation
//! \f$ \ast \f$ on a set is an element \f$ e \f$ such that \f$ e \ast a = a \ast e = a \f$ for every element \f$ a \f$,
//! as 0 is for the addition of the natural numbers and 1 for their multiplication.
//!
//! The sum and the product of types have identity elements as well, the empty type 0 and the unit type 1, for which the
//! laws hold up to isomorphism rather than equality, \f$ A + 0 \cong A \f$ and \f$ A \times 1 \cong A \f$.
//!
//! ---
//!
//! @section kumi_empty Empty Type
//!
//! The **empty type** 0 has no value. It is the identity element of the sum, \f$ A + 0 \cong A \f$, since a choice
//! between a value of \f$ A \f$ and a value that cannot exist amounts to a value of \f$ A \f$, and it absorbs the
//! product, \f$ A \times 0 \cong 0 \f$, since a pair whose second component cannot exist cannot exist either.
//!
//! - **Cardinality**: 0, so that no value of the type can be constructed.
//! - **Logic**: the empty type reads as falsity, \f$ \bot \f$, and the function type \f$ A \to 0 \f$ as the negation
//!   \f$ \neg A \f$.
//! - **Computation**: in a total calculus, a term of type \f$ A \to 0 \f$ exists only when \f$ A \f$ is empty itself.
//!   In a language with general recursion or effects, a function whose return type is empty never returns, since it
//!   loops, throws, or terminates the program, which makes the code after its call unreachable.
//!
//! C++ has no complete object type without values. The type `void` has an empty set of values, but it is an incomplete
//! type that no object has, and a function returning `void` returns normally. A class whose default constructor is
//! deleted keeps its copy and move constructors, so that a value of it can still be produced, by `std::bit_cast` among
//! others.
//!
//! The attribute `[[noreturn]]` marks a function that never returns, the runtime counterpart of a function to the empty
//! type, although the attribute lies outside the type of the function:
//!
//! @godbolt{doc/glossary/identity_empty.cpp}
//!
//! The empty type has no counterpart in **KUMI**, since the library provides no sum type and C++ provides no empty
//! type.
//!
//! ---
//!
//! @section kumi_unit Unit Type
//!
//! The **unit type** 1 has exactly one value, often written \f$ () \f$. It is the identity element of the product,
//! \f$ A \times 1 \cong A \f$, since the second component of a pair whose second type has a single value carries no
//! information, and it is the product of no type, the empty tuple.
//!
//! - **Cardinality**: 1, so that every object of the type holds the same value.
//! - **Logic**: the unit type reads as truth, \f$ \top \f$, whose proof is its single value.
//! - **Information**: an object of the unit type carries no information, \f$ \log_2 1 = 0 \f$ bits.
//!
//! The unit type of **KUMI** is kumi::unit, with the constant [kumi::none](@ref kumi_none), and the library recognizes
//! a unit type through the concept kumi::concepts::unit_type, which accepts a product type of size 0, `kumi::tuple<>`
//! among them, and `std::nullptr_t`:
//!
//! @godbolt{doc/glossary/identity_unit.cpp}
//!
//! An empty class such as `struct unit {};` has a single value as well, yet it models no product-type concept of the
//! library, since neither `std::tuple_size` nor `std::tuple_element` is specialized for it:
//!
//! @godbolt{doc/glossary/identity_not_unit.cpp}
//!
//! <div class="section_buttons">
//!
//! | Previous                                |                              Next   |
//! |:----------------------------------------|------------------------------------:|
//! | [Introduction](@ref kumi_introduction)  | [Product Types](@ref kumi_product)  |
//!
//! </div>
