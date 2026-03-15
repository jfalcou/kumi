#error This file is for ducomentation only - DO NOT INCLUDE
/**

 @page nomenclature Nomenclature

 This document establishes the formal vocabulary used throughout the KUMI library
 to ensure consistency across API documentation, error messages, and internal
 implementation details.

 In the context of **KUMI**, a distinction is made between types as stored,
 types as accessed, and the metadata used to describe them.

 ---

 ## Element

 An **element** is the fundamental constituent type of a heterogenous container.
 In literature, this corresponds to the *Value Type* (\f$ T \f$) stored within a node.
 - **Definition:** The raw, decayed type provided during template instantiation.
 - **Example:** In `kumi::tuple<int, double>`, the elements are `int` and `double`.

 ## Member

 A **member** is the functional result of a sub-object access operation, the result of a projection.

 Formally, a member is an **Element** qualified by the value category of the
 container and the cv-qualifiers of the access path.

 - **Definition:** The result of `get<I>(container)`.

 - **Example:** Given `kumi::tuple<int> t`, `get<0>(t)` yields the member `int&`,
 while `get<0>(std::move(t))` yields `int&&`.

 ## Identifier

 An **identifier** is a compile-time constant or type used as a key to resolve
 a specific sub-object within a structure.

 - **Definition:** A unique tag, integral constant, or symbolic name used for
 dispatching and name-binding.

 - **Role:** It decouples the logical "address" of a value from its physical
 offset in memory.

 ## Field

 A **field** is the combination of an **Identifier** and its associated **Element**.

 - **Formal Logic:** Let \f$ I \f$ be an Identifier and \f$ E \f$ be an Element.
 Then \f$ Field = \{I, E\} \f$.

 - **Role:** Fields are used to define the schema of a tuple-like structure.

 ## Label

 A **label** is the external, human-readable representation (string-equivalent)
 associated with an Identifier or Field.

 - **Definition:** The lexical name used for introspection, serialization,
 and diagnostic output.

 - **Note:** While an **Identifier** is a programmatic entity (like a type or
 index), a **Label** is a literal value (typically a `const char*` or `string_view`), in
 kumi, there is a special type used to describe these : kumi::str.

 ---

 ## Summary Table

| Concept       | Formal Analogy             | Domain        | Example                    |
|:--------------|:---------------------------|:--------------|:---------------------------|
| **Element**   | Value Type                 | Static Type   | `float`                    |
| **Member**    | Reference/Access Type      | Invocation    | `float const&`             |
| **Identifier**| Key / Index                | Metadata      | "my_data"_id               |
| **Field**     | Schema Attribute           | Reflection    | `{id, type}` pair          |
| **Label**     | Symbolic Name              | User Interface| `"velocity"`               |

**/
