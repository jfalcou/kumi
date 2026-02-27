Type-Theoretic Foundations {#type_theory}
----------

## Introduction

**Type Theory** is the academic study of type systems used to formalize how types are constructed and composed. 
While Set Theory categorizes elements into sets, Type Theory categorizes data (propositions) and the transformations (proofs) applied to them.

In this view:
* **Types** are classifications of data (propositions).
* **Functions/Programs** are the logical steps that transform data (proofs).

---

## The Curry-Howard Correspondence
The **Curry-Howard Correspondence** formalizes the direct link between logical reasoning and type-level reasoning.
Every concept in logic has a direct counter part in type theory.
The following table recapitulates the notion that can be necessary to understand.

| Logic Name    | Logic Notation      | Type Notation       | Type Name              | C++ Example             |
| :------------ | :-------------------| :-------------------| :----------------------| :-----------------------|
| True          | \f$ \top      \f$   | \f$ \top       \f$  | Unit Type              | `std::monostate`        |
| False         | \f$ \bot      \f$   | \f$ \bot       \f$  | Empty Type             | `void`                  |
| Implication   | \f$ A \to B   \f$   | \f$ A \to B    \f$  | Function               | `std::function<B(A)>`   |
| Not           | \f$ \neg A    \f$   | \f$ A \to 0    \f$  | Function to empty type | `[[noreturn]] void foo` |
| And           | \f$ A \land B \f$   | \f$ A \times B \f$  | Product type           | `std::tuple<A,B>`       |
| Or            | \f$ A \lor B  \f$   | \f$ A + B      \f$  | Sum type               | `std::variant<A,B>`     |

---

## 1. The Identity Elements (The "0" and "1" of Types)

Before building complex types, we must define the identities that govern type algebra. 
These types are the foundational "neutral" elements.

### Empty Type : \$f (0  /  \bot) \$f
The **Empty Type** is the identity element for **Sums** \f$ (A + 0 \cong A ) \f$.
* **Cardinality**: 0 states. It is mathematically impossible to construct an instance of this type.
* **Algebraic Role**: In logic, it represents a contradiction. In code, it represents a path that can never be taken. 
                      A function returning the Empty Type is a "diverging" function (it never returns).
* **Identity Property**: Just as \f$ x + 0 = x \f$, having a choice between Type A or an impossible Type 0 is logically equivalent to simply having Type A.

### Unit Type : \f$ (1  / \top) \f$
The **Unit Type** is the identity element for **Products** \f$ (A \times 1 \cong A) \f$.
* **Cardinality**: 1 state. It contains exactly one possible value (often written as `()`).
* **Algebraic Role**: It represents "no information" or "success without data." Because there is only one possible state, 
                      the value itself is predictable and thus carries zero entropy.
* **Identity Property**: Just as \f$ x \times 1 = x \f$, a pair containing Type A and a Unit Type provides no more information than Type A alone.

---

## 2. Product Constructions (The Logic of "AND")

Products represent types where multiple elements exist simultaneously.

### Product Type \f$ (A \times B) \f$ (The Tuple)
A **Product Type** is a compound type formed by combining multiple types. 

An unlabeled, ordered collection of types. It follows **List Algebra**.

+ **Order Dependence**: Position is identity. \f$ (A, B) \f$ is structurally distinct from \f$ (B, A) \f$ even though they contain the same underlying types.
+ **Cardinality**: The total state space is the **product** of the states of its components: \f$ Card(A \times B) = Card(A) \times Card(B) \t$.

### Example
```cpp
std::tuple<int, float> p; // Ordered product
```

### Record Type \f$ \{label: Type\} \f$  (The Struct)
A **Record Type** identifies its components by a **unique label** rather than a position. 

A **Record Type** is the labeled version of a Product. It follows **Set Algebra**.

+ **Label Identity**: Components are identified by unique **Labels** (names) rather than position.
+ **Permutation**:  Theoretically, a record is a set of field mappings. In many formal definitions, `{x: int, y: float}` is isomorphic to `{y: float, x: int}` 
                    because the set of labels and their associated types are identical.
+ **Semantic Access**: Access is performed via labels (`u.id`), adding semantic meaning to the structure.

### Example 
```cpp
struct User {
    int id;       // Label: id
    float score;  // Label: score
};
```

---

## 3. Sum Constructions (The Logic of "OR")

Sums represent types where a choice is made between different alternatives. They are the mathematical **Dual** of Products.

### Sum Type  \f$ (A + B) \f$ (The Coproduct)
An unlabeled, positional choice between types. 
* **Exclusive Choice**: An instance of \f$ A + B \f$ contains either an A or a B, but never both simultaneously.
* **Cardinality**: The state space is the **sum** of its components: \f$ Card(A + B) = Card(A) + Card(B) \f$.
* **Algebraic Property**: It is the dual of the Product. While a Product asks you to "Take All," a Sum asks you to "Pick One."

### Example
```cpp
std::variant<int, float> p; 
```

### Variant (The Labeled Sum)
A **Variant** is the labeled version of a Sum Type (and thus the dual of the Record).
* **Active Labeling**: Just as a Record has multiple labels present at once, a Variant has exactly **one active label** from a set of possibilities.
* **The Tag**: In C++, `std::variant` implements this as a **Tagged Union**. It uses a small integer (the tag/index) to track which label is currently active, ensuring type safety.

### Example 
```cpp
union particles {
    muons   m;  
    leptons l; 
    quarks  q;
};
```

---

## Container Type (Type Constructors)
A **Container Type** is a **Type Constructor**; it is not a type itself but a function that takes a type \f$ T \f$ and returns a new type \f$ F(T) \f$.

* **Generics:** In C++, these are implemented via Templates.
* **Structure:** It defines the "shape" of the data (e.g., `std::vector`, `std::list`) independently of the contained value.

---

## Monoid
A type is a **Monoid** if it possesses a binary operation to combine elements and an identity element.
It needs to model other mathematical laws such as :
1. **Associativity:** \f$ (a + b) + c = a + (b + c) \f$.
2. **Identity Element:** \f$ a + Identity = a \f$.

**Example:** `std::string` is a monoid where the operation is `+` (concatenation) and the identity is `""`.
