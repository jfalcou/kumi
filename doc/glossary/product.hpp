#error This file is for documentation only - DO NOT INCLUDE
//! @page kumi_product Product Types
//!
//! @section product_construction Product Constructions
//!
//! A product combines several types into one, whose values hold a value of each combined type at once. Read as a
//! proposition, the product \f$ A \times B \f$ is the conjunction \f$ A \land B \f$, whose proof is a proof of
//! \f$ A \f$ together with a proof of \f$ B \f$. The product comes in two forms, which differ by the way that they
//! designate their components: by position in a tuple, and by label in a record.
//!
//! ---
//!
//! @section kumi_product_type Product Type
//!
//! A **product type** \f$ T_1 \times \dots \times T_n \f$ has as values the
//! [tuples](https://en.wikipedia.org/wiki/Tuple) \f$ (x_1, \dots, x_n) \f$ whose component \f$ x_i \f$ has the type
//! \f$ T_i \f$, for a length \f$ n \f$ and component types fixed by the type:
//!
//! \f[ (x_1, x_2, \dots, x_n) : T_1 \times T_2 \times \dots \times T_n \f]
//!
//! The tuple is the single introduction form of the product, which takes exactly \f$ n \f$ components, and the
//! projections are its elimination forms: for \f$ 1 \le i \le n \f$, the projection \f$ \pi_i \f$ maps a value
//! \f$ x \f$ of the product to its \f$ i \f$-th component,
//!
//! \f[ \pi_i : T_1 \times \dots \times T_n \to T_i, \qquad \pi_i(x) : T_i. \f]
//!
//! Two equations relate the two forms, the computation rule, by which a projection of a tuple yields its component, and
//! the uniqueness rule, by which a value of the product is the tuple of its projections:
//!
//! \f[ \pi_i(x_1, \dots, x_n) = x_i, \qquad (\pi_1(x), \dots, \pi_n(x)) = x. \f]
//!
//! For a sequence of indices \f$ i_1, \dots, i_k \f$ between 1 and \f$ n \f$, with \f$ k \ge 0 \f$, the projection onto
//! several indices maps a value of the product to the tuple of its components at these indices:
//!
//! \f[ \pi_{i_1, \dots, i_k} : T_1 \times \dots \times T_n \to T_{i_1} \times \dots \times T_{i_k}, \qquad
//!     \pi_{i_1, \dots, i_k}(x) = (\pi_{i_1}(x), \dots, \pi_{i_k}(x)). \f]
//!
//! Its codomain is the unit type 1 when \f$ k = 0 \f$, and the product of the single type \f$ T_{i_1} \f$, isomorphic
//! to \f$ T_{i_1} \f$, when \f$ k = 1 \f$. **KUMI** keeps these two types distinct, `kumi::tuple<T>` and `T`, so that
//! the projection onto the single index \f$ i \f$ is \f$ \pi_i \f$ followed by the isomorphism. The map deletes
//! components when the indices omit some, permutes them when the indices change their order, and duplicates a component
//! when its index repeats.
//!
//! The [projection](https://en.wikipedia.org/wiki/Projection_(relational_algebra)) of relational algebra is the image
//! of a relation under this map: it applies the map to every tuple of the relation and returns the set of the results,
//! in which two tuples equal at the chosen indices become one. In the unnamed perspective of
//! [Abiteboul, Hull, and Vianu](@ref references_texts), section 4.4, whose tuples take their components in a single
//! domain of values, its indices form any sequence, repetitions included. In their named perspective, where a tuple
//! maps attributes to values (section 3.2), the projection of section 4.4 takes a set of attributes, without repetition
//! and without order.
//!
//! The product has two further properties:
//!
//! - **Order**: the types \f$ A \times B \f$ and \f$ B \times A \f$ are distinct when \f$ A \ne B \f$, and isomorphic
//!   through the swap of the two components. The position of a component designates it, which also tells apart the
//!   two components of \f$ A \times A \f$.
//! - **Cardinality**: the number of values of the product is the product of the numbers of values of its components,
//!   \f$ \mathrm{Card}(A \times B) = \mathrm{Card}(A) \times \mathrm{Card}(B) \f$.
//!
//! The positional product of **KUMI** is kumi::tuple (see @ref kumi_tuple_related), an aggregate initialized from a
//! braced list, whose template arguments its deduction guide deduces, or built by kumi::make_tuple, kumi::tie, and
//! kumi::forward_as_tuple. A kumi::tuple may also hold fields, which give its components a name besides their position,
//! and it applies the empty-base optimization to its empty, non-final element types.
//!
//! The projections are the functions `get` and the subscript by a compile-time index, which the literal `_c` of the
//! namespace kumi::literals builds. They return a reference to the component and count from 0 where \f$ \pi_i \f$
//! counts from 1, so that the index 0 computes \f$ \pi_1 \f$:
//!
//! @godbolt{doc/glossary/product_tuple.cpp}
//!
//! The algorithms of the group [Projections](@ref kumi_projections) count the indices from 0 and compute three kinds of
//! maps:
//!
//! - **Projection onto one index**: kumi::front and kumi::back return a reference to the first and the last
//!   component of a non-empty kumi::tuple, \f$ \pi_1 \f$ and \f$ \pi_n \f$. On a kumi::record, they return the value of
//!   the first and the last field, where `get` by index returns the field.
//! - **Projection onto several indices**:
//!   - kumi::reorder computes \f$ \pi_{i_1, \dots, i_k} \f$ for any sequence of indices,
//!     `reorder<i - 1>` returning a product of one component. On a kumi::tuple, it stores copies of the components,
//!     without their reference or `const` qualifier.
//!   - kumi::extract takes the indices in increasing order, from `B` to `E` by steps of `S`, and kumi::filter the
//!     indices of the components whose stored type, a reference included, satisfies a predicate. Both keep the
//!     element types of their argument, references and `const` included.
//!   - kumi::pop_front, kumi::pop_back, kumi::remove, kumi::reverse, kumi::rotate_left, kumi::rotate_right,
//!     kumi::filter_not, kumi::unique, and kumi::all_unique compute such projections as well.
//! - **Pair of projections**: kumi::split and kumi::partition return the pair \f$ (f(x), g(x)) \f$ of two
//!   projections \f$ f \f$ and \f$ g \f$ onto several indices.
//!
//! @godbolt{doc/glossary/product_projections.cpp}
//!
//! On a kumi::record, kumi::reorder and kumi::reorder_fields, which selects the fields by label, reject a repeated
//! index or label, since a record holds each label once.
//!
//! ---
//!
//! @section kumi_power_type Power Type
//!
//! A **power type** \f$ T^n \f$ is the product of \f$ n \f$ copies of one type \f$ T \f$, isomorphic to the homogeneous
//! product \f$ T \times \dots \times T \f$ and to the function type \f$ \{0, \dots, n - 1\} \to T \f$ from the indices
//! to the components, the array of \f$ n \f$ values of type \f$ T \f$.
//!
//! Its cardinality is \f$ \mathrm{Card}(T)^n \f$, and \f$ T^0 \f$, the array without components, is isomorphic to the
//! unit type 1, the identity element of the product.
//!
//! Since every component of a power type has the type \f$ T \f$, an index known only at run time selects a value of
//! type \f$ T \f$. In a type system without dependent types, the same index into a heterogeneous product yields at most
//! a value of the sum of the component types, a `std::variant` in C++, and only a compile-time index yields the
//! component at its own type.
//!
//! The library keeps the two notions apart:
//!
//! - kumi::array of a cv-unqualified, non-reference element type models the concept kumi::concepts::power_type.
//! - kumi::array of references or of `const` elements, like kumi::tuple of equal element types, models
//!   kumi::concepts::homogeneous_product_type without being a power type.
//!
//! kumi::array (see @ref kumi_array_related) is indexed at compile time only, through `operator[]` with a
//! kumi::index_t, as `a[1_c]`. The empty `kumi::array{}` deduces to `kumi::array<void, 0>`, the identity of the power
//! types.
//!
//! An algorithm returns a power type when its results share one type, as kumi::map does with a function that returns
//! one type, and a kumi::tuple once they differ, as kumi::push_back of a `double` onto an array of `int` does.
//!
//! kumi::tuple stores the elements of a homogeneous tuple of size greater than 1 as an array, when they are neither
//! references nor empty types.
//!
//! The tuple types of the C++ standard library model kumi::concepts::product_type as they are, which lets every
//! algorithm of **KUMI** accept them without conversion, and each of them has a counterpart in the library:
//!
//! <center>
//!
//! | Standard library type   | **KUMI** counterpart     |
//! |:------------------------|:-------------------------|
//! | `std::pair<T1, T2>`     | `kumi::tuple<T1, T2>`    |
//! | `std::tuple<Ts...>`     | `kumi::tuple<Ts...>`     |
//! | `std::array<T, N>`      | `kumi::array<T, N>`      |
//!
//! </center>
//!
//! A kumi::array prints its components between brackets, and a kumi::tuple between parentheses:
//!
//! @godbolt{doc/glossary/power.cpp}
//!
//! ---
//!
//! @section kumi_record_type Record Type
//!
//! A **record type** \f$ \{l_1 : T_1, \dots, l_n : T_n\} \f$ designates its components by labels, distinct from each
//! other, instead of positions, and it is the product \f$ \prod_{l \in L} T_l \f$ indexed by a finite set \f$ L \f$ of
//! labels. Its values are the [records](https://en.wikipedia.org/wiki/Record_(computer_science))
//! \f$ \{l_1 = x_1, \dots, l_n = x_n\} \f$, in the notation of [Pierce](@ref references_texts), section 11.8:
//!
//! \f[ \{l_1 = x_1, \dots, l_n = x_n\} : \{l_1 : T_1, \dots, l_n : T_n\} \f]
//!
//! C, C++, and Rust call such a type a structure, while Pascal, Ada, and the languages of the ML family call it a
//! record, setting aside what object-oriented programming adds to it, such as inheritance.
//!
//! The projections of a record are labeled, the projection \f$ \pi_l \f$ mapping a record to the value of its field
//! labeled \f$ l \f$, which Pierce writes \f$ x.l \f$:
//!
//! \f[ \pi_{l_i}(x) : T_i \f]
//!
//! Two properties distinguish the record from the tuple:
//!
//! - **Labels**: a component is designated by its label, unique within the record, rather than by its position, so that
//!   a projection names the field that it reads, as `get<"x">(r)` does.
//! - **Permutation**: the record calculi differ on the order of the fields. Standard ML identifies the record types
//!   that differ by the order of their fields, whereas the basic calculus of Pierce keeps the order in the type and
//!   relates the permuted types by the subtyping rule S-RcdPerm, section 15.2.
//!
//! The labeled product of the library is kumi::record (see @ref kumi_record_related), an aggregate initialized, like
//! kumi::tuple, from a braced list of fields, each binding an identifier to a value. Two records whose fields differ by
//! their order are distinct types, and neither converts to the other, yet their comparison and their assignment match
//! the fields by identifier, whatever their order.
//!
//! The projection by name takes the identifier of the field, `"x"_id`, in the subscript or in `get`, or the label
//! alone, a kumi::str, in `get<"x">`:
//!
//! @godbolt{doc/glossary/product_record.cpp}
//!
//! A record also has an index order, the order in which its fields are declared, which `std::tuple_size`,
//! `std::tuple_element`, and the `get` overloads that take an index expose. The positional algorithms that keep the
//! fields of a record return a record, kumi::rotate_left and kumi::reverse among them, while an algorithm that adds a
//! component without a label, such as kumi::push_back, does not accept a record.
//!
//! An access by index returns the field, whose type \f$ \{l : T\} \f$ combines the label and the type of the value,
//! while an access by label returns the value, of type \f$ T \f$.
//!
//! <div class="section_buttons">
//!
//! | Previous                                 |                                   Next |
//! |:-----------------------------------------|---------------------------------------:|
//! | [Identity Elements](@ref kumi_identity)  | [Bibliography](@ref kumi_references)   |
//!
//! </div>
