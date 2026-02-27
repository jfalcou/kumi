#error This file is for documentation only - DO NOT INCLUDE
/**

@page introduction Type Theoretic Foundations

This introduction does not aim at providing full understanding of type theory, but is more focused on giving a brief yet
extensive overview of the basis that might be of interest to any new or even experienced programmer. Kumi makes extensive
use of some concepts that will be detailed in the following sections.

@section origin Origin 

**Type Theory** is the academic study of type systems used to formalize how types are constructed and composed. 
While Set Theory categorizes elements into sets, Type Theory categorizes data (propositions) and the transformations 
(proofs) applied to them.

In this view:

* **Types** are classifications of data (propositions).
* **Functions/Programs** are the logical steps that transform data (proofs).

---

@section curry_howard The Curry-Howard Correspondence

The **Curry-Howard Correspondence** formalizes the direct link between logical reasoning and type-level reasoning.
Every concept in logic has a direct counter part in type theory.
The following table recapitulates the different operation that can be necessary to understand.

| Logic Name    | Logic Notation      | Type Notation       | Type Name              | C++ Example             |
| :------------ | :-------------------| :-------------------| :----------------------| :-----------------------|
| True          | \f$ \top      \f$   | \f$ \top       \f$  | Unit Type              | `std::monostate`        |
| False         | \f$ \bot      \f$   | \f$ \bot       \f$  | Empty Type             | `void`                  |
| Implication   | \f$ A \to B   \f$   | \f$ A \to B    \f$  | Function               | `std::function<B(A)>`   |
| Not           | \f$ \neg A    \f$   | \f$ A \to 0    \f$  | Function to empty type | `[[noreturn]] void foo` |
| And           | \f$ A \land B \f$   | \f$ A \times B \f$  | Product type           | `std::tuple<A,B>`       |
| Or            | \f$ A \lor B  \f$   | \f$ A + B      \f$  | Sum type               | `std::variant<A,B>`     |

---

@section fundamentals Fundamentals

In order to be able to build more complex type, it is necessary to first define Atomic Terms. In common type theory,
these can be of three different types. There are the natural numbers, often denotated *nat*, then there are boolean
values notated *bool* and formal variables. Formal variables are simply variables reffered to by a symbol.

```cpp
true : bool   // A boolean
42 : nat      // A natural number
x : bool      // A formal variable
```

Then in order to be able to manipulate these types, there is the concept of functions terms. This is simply a function 
in the programming sens. Given a parameter of a type \f$ \sigma \f$ and a return type \f$ \tau \f$ the associated function
is noted \f$ \sigma \rightarrow \tau \f$. The addition of two real numbers can then written as : 
\f$ add : *nat* \rightarrow (*nat* \rightarrow *nat*)\f$

Finally, there are lambda terms, it is associated to concept of anonymous functions/lambdas functions in programming, 
these should sound familiar. They simply represent a way to define new function terms. 

[In the next page](@ref identity), we will see some more specific types that are used as a base for more complex 
operations.

---

* **Reference** [Wikipedia: Type Theory](https://en.wikipedia.org/wiki/Type_theory)

**/
