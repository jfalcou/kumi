#error This file is for documentation only - DO NOT INCLUDE
/**

@page kumi_introduction Type Theoretic Foundations

This introduction does not aim at providing full understanding of type theory, but is more focused on giving a brief yet
extensive overview of the basis that might be of interest to any new or even experienced programmer. **Kumi** makes 
extensive use of some concepts that will be detailed in the following sections. In the current state, the **Kumi** 
library focuses on handling [product types](@ref kumi_product_type).

---

@section origin Origin 

[Type theory](https://en.wikipedia.org/wiki/Type_theory) is the academic study of type systems used to formalize how types are constructed and composed. 
While [Set Theory](https://en.wikipedia.org/wiki/Set_theory) categorizes elements into sets, Type Theory categorizes data (propositions) and the transformations 
(proofs) applied to them.

In this view:

+ **Types** are classifications of data (propositions).
+ **Functions/Programs** are the logical steps that transform data (proofs).

---

@section curry_howard The Curry-Howard Correspondence

The [Curry-Howard Correspondence](https://en.wikipedia.org/wiki/Curry%E2%80%93Howard_correspondence) formalizes the 
direct link between logical reasoning and type-level reasoning.
Every concept in logic has a direct counter part in type theory.
The following table recapitulates the different operation that can be necessary to understand.

| Logic Name    | Logic Notation      | Type Notation       | Type Name              | C++ Example                  |
| :------------ | :-------------------| :-------------------| :----------------------|:-----------------------------|
| True          | \f$ \top      \f$   | \f$ \top       \f$  | Unit Type              | `std::monostate`             |
| False         | \f$ \bot      \f$   | \f$ \bot       \f$  | Empty Type             | `void` (as a non-return type)|
| Implication   | \f$ A \to B   \f$   | \f$ A \to B    \f$  | Function               | `std::function<B(A)>`        |
| Not           | \f$ \neg A    \f$   | \f$ A \to 0    \f$  | Function to empty type | `[[noreturn]] void foo`      |
| And           | \f$ A \land B \f$   | \f$ A \times B \f$  | Product type           | `std::tuple<A,B>`            |
| Or            | \f$ A \lor B  \f$   | \f$ A + B      \f$  | Sum type               | `std::variant<A,B>`          |

---

@section fundamentals Fundamentals

In order to be able to build more complex type, it is necessary to first define Atomic Terms. In common type theory,
these can be of three different types. There are the natural numbers, often denotated *nat*, then there are boolean
values notated *bool* and formal variables.

A **formal variable** is a symbol that stands for an arbitrary term of a given type. It carries no computation of its
own and only serves as a placeholder, such as \f$ x \f$ in the lambda term \f$ \lambda x. x \f$.

```cpp
true : bool   // A boolean
42 : nat      // A natural number
x : bool      // A formal variable
```

Then in order to be able to manipulate these types, there is the concept of functions terms. This is simply a function 
in the programming sense. Given a parameter of a type \f$ \sigma \f$ and a return type \f$ \tau \f$ the associated function
is noted \f$ \sigma \rightarrow \tau \f$. The addition of two real numbers can then written as : 
add : nat \f$ \rightarrow \f$ (nat \f$ \rightarrow \f$ nat)

Finally, there are lambda terms, it is associated to concept of anonymous functions/lambdas functions in programming, 
these should sound familiar. They simply represent a way to define new function terms. 

---

@section cardinality Type Cardinality

In the context of Set Theory, the **Cardinality** of a set is simply the number of element it contains. When translating
it to Type Theory, the cardinality of a type refers to the total number of unique values (or states) an instance of that 
type can possibly represent.

By treating types as set of potential values, we can use standard arithmetic to predict the complexity of our data 
structures. A type like `bool` as a cardinality of 2, the set of it's values is \f$ {true, false} \f$

Understanding cardinality allows us to see types not just as labels, but as mathematical objects where the size of the 
state space dictates how much information a variable can have.

---

To tie these notions back to the library, it is useful to keep the following correspondence in mind: a lambda term
denotes a function, a well-typed term denotes a value of a given type, and a kumi::product_type is how such a term
is concretely stored and decomposed.

| Lambda term              | Well-typed term            | Kumi side                                        |
|:-------------------------|:---------------------------|:-------------------------------------------------|
| \f$ \lambda x. x \f$     | \f$ T \to T \f$            | a callable applied to the elements of a product type |
| \f$ (x_1, ..., x_n) \f$  | \f$ T_1 \times ... \times T_n \f$ | kumi::tuple / kumi::record             |
| projection \f$ \pi_i \f$ | \f$ T_i \f$                | kumi::get<...>                                   |

@note Readers looking for a deeper treatment of these topics may consult the short selection of type-theory
      references gathered in the [References](@ref kumi_references) page.

In the next page, we will see some more specific types that are used as a base for more complex 
operations.

<div class="section_buttons">
 
|                              Next     |
|--------------------------------------:|
| [Identity Types](@ref kumi_identity)  |
 
</div>

**/
