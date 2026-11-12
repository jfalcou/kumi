#error This file is for documentation only - DO NOT INCLUDE
//! @page kumi_nomenclature Nomenclature
//!
//! The library distinguishes the types of a product type as stored, its types as accessed, and the metadata that
//! designate its components, under five names:
//!
//! <center>
//!
//! | Notion                                                | Formal analogy               | Domain            | Example                    |
//! |:------------------------------------------------------|:-----------------------------|:------------------|:---------------------------|
//! | [Element](@ref kumi_nomenclature_element)             | Component type \f$ T_i \f$   | Stored type       | `float`                    |
//! | [Member](@ref kumi_nomenclature_member)               | Type of a projection         | Access            | `float const&`             |
//! | [Identifier](@ref kumi_nomenclature_identifier)       | Key                          | Metadata          | `"my_data"_id`             |
//! | [Field](@ref kumi_nomenclature_field)                 | Pair \f$ (I, S) \f$          | Schema            | `"velocity"_id = 1.f`      |
//! | [Label](@ref kumi_nomenclature_label)                 | Name                         | Keys, diagnostics | `"velocity"` as kumi::str  |
//!
//! </center>
//!
//! ---
//!
//! @section kumi_nomenclature_element Element
//!
//! An **element** is the type that a product type holds at a given position, the type \f$ T_i \f$ of the product
//! \f$ T_1 \times \dots \times T_n \f$. The trait kumi::element_t gives it as declared,
//! `std::tuple_element_t<I, std::remove_cvref_t<T>>`, with its qualifiers and references kept, so that the elements of
//! `kumi::tuple<int&, int const>` are `int&` and `int const`.
//!
//! On a record, the element at an index is the type of the field, and kumi::stored_element_t gives the type of the
//! value that the field holds, `float` for a record built from `"x"_id = 1.f`:
//!
//! @godbolt{doc/glossary/element.cpp}
//!
//! ---
//!
//! @section kumi_nomenclature_member Member
//!
//! A **member** is the type of the result of a projection, the type of `get<I>(t)`, which the trait kumi::member_t
//! gives as `decltype(get<I>(std::declval<T&&>()))`.
//!
//! On kumi::tuple, it is the element with the value category and the `const` of the product type applied by reference
//! collapsing: given `kumi::tuple<int> t`, `get<0>(t)` has the type `int&`, `get<0>(std::move(t))` the type `int&&`,
//! and `get<0>` of a `kumi::tuple<int> const` the type `int const&`, whereas on a `kumi::tuple<int&>` the first two
//! have the type `int&`.
//!
//! On an adapted type whose `get` returns by value, the member is that value type. On a record, the member at an index
//! is a reference to the field, and kumi::stored_member_t gives the reference to the value that the field holds:
//!
//! @godbolt{doc/glossary/member.cpp}
//!
//! ---
//!
//! @section kumi_nomenclature_identifier Identifier
//!
//! An **identifier** is a type that designates a field of a product type independently of its position and of its
//! offset in memory. The value `"x"_id`, for instance, has the identifier type `kumi::name<"x">`. The concept
//! kumi::concepts::identifier requires a nested type, and kumi::concepts::index, which describes the integral constants
//! that designate a component by its position, requires a member `value`, so that a type with both, such as
//! `std::integral_constant`, models both concepts. kumi::concepts::projection accepts either:
//!
//! @godbolt{doc/glossary/identifier.cpp}
//!
//! ---
//!
//! @section kumi_nomenclature_field Field
//!
//! A **field** binds an identifier to a value: kumi::field holds a value of a type `T` under an identifier `Id`, and
//! the expression `"x"_id = 42` builds one, which prints as its label and its value.
//!
//! Its type is the ordered pair \f$ (I, S) \f$ of an identifier \f$ I \f$ and the type \f$ S \f$ of the value that it
//! stores, given by kumi::stored_element_t, which is also the record type \f$ \{I : S\} \f$ of a single field. The
//! fields of a kumi::record, or of a kumi::tuple that holds fields, define its schema:
//!
//! @godbolt{doc/glossary/field.cpp}
//!
//! ---
//!
//! @section kumi_nomenclature_label Label
//!
//! A **label** is the name of an identifier as a string known at compile time, of type kumi::str, which the function
//! `label()` of a field returns. The library uses a label as a key, in the projection `get<"x">` of a record and in the
//! subscript of a record by a label that the literal `_l` builds, and in its diagnostics.
//!
//! A `const char*` cannot point to a string literal as a template argument, and `std::string_view` is not a structural
//! type, which is why the structural class kumi::str, of fixed size, holds a label:
//!
//! @godbolt{doc/glossary/label.cpp}
//!
//! <div class="section_buttons">
//!
//! | Previous                                       |
//! |:-----------------------------------------------|
//! | [C++ Vocabulary](@ref kumi_cpp_vocabulary)     |
//!
//! </div>
