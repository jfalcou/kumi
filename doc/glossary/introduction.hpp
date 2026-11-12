#error This file is for documentation only - DO NOT INCLUDE
//! @page kumi_introduction Type Theoretic Foundations
//!
//! [Type theory](https://en.wikipedia.org/wiki/Type_theory) studies type systems, the formal rules by which a language
//! assigns types to its terms and builds new types from existing ones. **KUMI** implements one family of these
//! constructions, the [product types](@ref kumi_product_type), and borrows from type theory the vocabulary with which
//! its documentation describes them. Tuples and their projections are written in the
//! [usual mathematical notation](https://en.wikipedia.org/wiki/Product_type), \f$ (x_1, \dots, x_n) \f$ and
//! \f$ \pi_i \f$, and records in the notation of [Pierce](@ref references_texts),
//! \f$ \{l_1 = x_1, \dots, l_n = x_n\} \f$.
//!
//! ---
//!
//! @section origin Origin
//!
//! Bertrand Russell introduced a theory of types in 1908, the ramified theory, to avoid the paradoxes of naive
//! [set theory](https://en.wikipedia.org/wiki/Set_theory), and Alonzo Church simplified it in 1940 into the simple
//! theory of types, on which the typed lambda calculi rest.
//!
//! Two styles of typing coexist since: in the Church style, which the examples below follow, every term carries its
//! type, whereas in the Curry style the terms are untyped and the type system assigns types to some of them. Under the
//! Curry-Howard correspondence, the same construction admits a logical reading:
//!
//! + a **type** reads as a proposition,
//! + a **term** of that type, a value or a program, reads as a proof of that proposition.
//!
//! ---
//!
//! @section curry_howard The Curry-Howard Correspondence
//!
//! The [Curry-Howard correspondence](https://en.wikipedia.org/wiki/Curry%E2%80%93Howard_correspondence) relates
//! intuitionistic logic to the typed lambda calculi: each connective of intuitionistic propositional logic has a
//! counterpart type former, and a proof of a formula corresponds to a term of the matching type. Classical principles
//! such as the excluded middle or Peirce's law have no closed term in the simply typed lambda calculus with products,
//! sums, and the empty type, and Griffin showed in 1990 that control operators such as `call/cc` receive the types of
//! these principles.
//!
//! The C++ column gives the nearest construct of the language, C++ having no empty type.
//!
//! <center>
//!
//! | Logic name  | Logic notation      | Type notation       | Type name                  | C++ approximation                          |
//! |:------------|:--------------------|:--------------------|:---------------------------|:-------------------------------------------|
//! | Truth       | \f$ \top \f$        | \f$ 1 \f$           | Unit type                  | `std::monostate`, kumi::unit               |
//! | Falsity     | \f$ \bot \f$        | \f$ 0 \f$           | Empty type                 | none                                       |
//! | Implication | \f$ A \to B \f$     | \f$ A \to B \f$     | Function type              | the function type `B(A)`                   |
//! | Negation    | \f$ \neg A \f$      | \f$ A \to 0 \f$     | Function to the empty type | `[[noreturn]] void f(A)`                   |
//! | Conjunction | \f$ A \land B \f$   | \f$ A \times B \f$  | Product type               | `std::tuple<A, B>`, `kumi::tuple<A, B>`    |
//! | Disjunction | \f$ A \lor B \f$    | \f$ A + B \f$       | Sum type                   | `std::variant<A, B>`                       |
//!
//! </center>
//!
//! ---
//!
//! @section fundamentals Fundamentals
//!
//! A type theory starts from base types and builds every other type from them. The examples below use two base types,
//! **nat**, whose values are 0 and the iterated applications of the successor
//! \f$ S : \mathrm{nat} \to \mathrm{nat} \f$, written 1, 2, and so on, and **bool**, whose values are the constants
//! true and false. The atomic terms are these constants together with the variables.
//!
//! A **formal variable** stands for an arbitrary term of a given type and carries no computation of its own. It is
//! bound when an abstraction introduces it, as \f$ x \f$ is in \f$ \lambda x.\, x \f$, and free otherwise.
//!
//! A **typing judgment** \f$ \Gamma \vdash t : T \f$ states that the term \f$ t \f$ has the type \f$ T \f$ under the
//! context \f$ \Gamma \f$, which assigns a type to each free variable of \f$ t \f$, so that a constant needs an empty
//! context and a free variable an assumption on its type:
//!
//! \f[
//!   \vdash \mathrm{true} : \mathrm{bool} \qquad \vdash 42 : \mathrm{nat}
//!   \qquad x : \mathrm{bool} \vdash x : \mathrm{bool}
//! \f]
//!
//! The type of the functions from \f$ \sigma \f$ to \f$ \tau \f$ is written \f$ \sigma \to \tau \f$. A function type
//! has one argument, so that a function of two arguments is curried and takes them one at a time, and the arrow
//! associates to the right by convention, which drops the parentheses of the type of the curried addition of two
//! natural numbers:
//!
//! \f[ \mathrm{add} : \mathrm{nat} \to (\mathrm{nat} \to \mathrm{nat}) \f]
//!
//! The application of add to one argument yields a function of type \f$ \mathrm{nat} \to \mathrm{nat} \f$.
//!
//! A lambda term \f$ \lambda x.\, t \f$ defines a new function by abstraction over the variable \f$ x \f$ in the term
//! \f$ t \f$. It corresponds to the anonymous function of programming languages, of which the C++ lambda expression is
//! one, and \f$ \lambda x.\, x \f$ is the identity function, of type \f$ T \to T \f$ for any type \f$ T \f$.
//!
//! ---
//!
//! @section cardinality Type Cardinality
//!
//! The cardinality of a set is the number of its elements, and the cardinality of a type, read as the set of its
//! values, is the number of distinct values that an object of that type can hold. The type bool has the cardinality 2,
//! its set of values being \f$ \{\mathrm{true}, \mathrm{false}\} \f$, whereas nat has an infinite cardinality.
//!
//! For a finite type of cardinality \f$ n \f$, \f$ \log_2 n \f$ bits encode one value, an upper bound of the
//! information that an object of the type carries, and the cardinality turns the constructions of types into
//! arithmetic, by which the cardinality of a compound type follows from the cardinalities of its parts.
//!
//! ---
//!
//! @section kumi_correspondence Correspondence with KUMI
//!
//! A lambda term denotes a function, and a well-typed term denotes a value of its type. **KUMI** stores and decomposes
//! the values of product types: kumi::tuple, kumi::record, and kumi::array hold such values and model the concept
//! kumi::concepts::product_type.
//!
//! <center>
//!
//! | Term                          | Type                                               | **KUMI**                                                    |
//! |:------------------------------|:---------------------------------------------------|:------------------------------------------------------------|
//! | \f$ \lambda x.\, x \f$        | \f$ T \to T \f$                                    | a callable, which kumi::map applies to each element of a product type |
//! | \f$ (x_1, \dots, x_n) \f$     | \f$ T_1 \times \dots \times T_n \f$                | kumi::tuple, and kumi::array when all the \f$ T_i \f$ are equal |
//! | projection \f$ \pi_i \f$      | \f$ T_1 \times \dots \times T_n \to T_i \f$        | %kumi::get at the index \f$ i - 1 \f$, which returns a reference to the component |
//!
//! </center>
//!
//! @note Pierce, Harper, Barendregt, and Wadler treat these notions, see the [Bibliography](@ref kumi_references).
//!
//! <div class="section_buttons">
//!
//! |                                          Next |
//! |----------------------------------------------:|
//! | [Identity Elements](@ref kumi_identity)       |
//!
//! </div>
