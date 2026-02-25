Type-Theoretic Foundations {#type_theory}
==========

## Introduction

**Type Theory** is the academic study of type systems. In computer science it is used to formalize the way types are built and composed together.
Just as Set Theory categorizes numbers, Type Theory categorizes data.

In this view:
* **Types** are classification of data (propositions).
* **Functions/Programs** are the logical steps that transform the data (proofs).

More generally, it governs how compilers reasons about data structure, functions and transformations in the code. 

## The Curry-Howard Correspondence
The relationship between logic and programming is formalized by the **Curry-Howard Correspondence**. 
This mapping explains the direct link between logical reasoning and type level reasonning . 


| Logic Name    | Logic Notation        | Type Notation         | Type Name              | C++ Example           |
| :------------ | :------------         | :---                  | :---                   | :--                   |
| True          | \f$ \top      \f$     | \f$ \top       \f$    | Unit Type              | std::monostate        |
| False         | \f$ \bot      \f$     | \f$ \bot       \f$    | Empty Type             | void                  |
| Implication   | \f$ A \to B   \f$     | \f$ A \to B    \f$    | Function               | std::function\<B(A)\> |
| Not           | \f$ \neg A    \f$     | \f$ A \to \bot \f$    | Function to empty type | [[noreturn]] void foo |
| And           | \f$ A \land B \f$     | \f$ A \times B \f$    | Product type           | std::tuple\<A,B\>     |
| Or            | \f$ A \lor B  \f$     | \f$ A + B  \f$        | Sum type               | std::variant\<A,B\>   |

* **Reference**: [Wikipedia: Type Theory](https://en.wikipedia.org/wiki/Type_theory)

## Product Type
In computer science and type theory, a **Product Type** is a compound type formed by combining multiple other types. It is called a "product" because the total number of possible states the object can be in. This is the mathematical *product* of the states of its components (Cartesian Product). An instance of a product type is a **tuple**.

Crucially, **the order of the operands is fixed**. A product of `(int, float)` is structurally distinct from `(float, int)`, even though they contain the same data.

### Mathematics vs Programming
* **Mathematical Notation:** $A \times B$
* **Logic Equivalent:** $A \land B$ (You have A **AND** you have B)

```cpp
template<typename A, typename B>
struct Product {
    A m0;
    B m1;
};

// Standard Library equivalent
std::pair<A, B>;
std::tuple<A, B>;
```

## Record Type
A **Record Type** is a variation of a Product Type. While a standard Product Type (like a tuple) identifies its components by their position (index 0, index 1...), a Record Type identifies its components by a unique label (name).

This adds a layer of semantic meaning to the data. In C++, structs and classes are Record Types.

### Mathematical vs C++

* **Mathematical Notation**: {label :T1,label2:T2}

* **Access Pattern**: record.label or get<label>(record) instead of get<0>(record)
```cpp
// C++ Implementation
struct User {     // "User" is the Record Type
    int id;       // "id" is a Label for type int
    float score;  // "score" is a Label for type float
};

User u;
u.id = 42; // Access by Label
```

## Unit Type

The **Unit Type** is a type that allows exactly one possible value. Because there is only one option, the value itself conveys no information, the mere existence of the variable is the information.

In algebra, the Unit Type acts as the Identity Element for Product Types. Just as 5×1=5, combining any type T with the Unit Type results in a structure that holds no more information than T alone (T×Unit≅T).
Mathematical vs C++

* **Mathematical Notation**: 1 or ()

* **Logic Equivalent** : \top (True / Always present)

```cpp
// C++ Implementation
struct Unit {}; 

// Standard Library equivalent
std::monostate; 
std::tuple<>; // An empty tuple is a Unit Type
```

## Container Type
## Monoid
A **Monoid** is a concept from abstract algebra that is heavily used in functional programming (especially for operations like fold or reduce).

A type is a **Monoid** if it has:

* **Associativity**: When combining three elements, the grouping doesn't matter: (a+b)+c==a+(b+c).

* **Identity Element**: A neutral value that doesn't change the result: a+Identity==a.
