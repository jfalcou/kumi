#error This file is for documentation only - DO NOT INCLUDE
/**

@page sum Sum Types 

@tableofcontents

@section sum_construction Sum Constructions (The Logic of "OR")

Sums represent types where a choice is made between different alternatives. They are the mathematical **Dual** of Products.

@subsection sum_type Sum Type  \f$ (A + B) \f$ (The Coproduct)

An unlabeled, positional choice between types. 
* **Exclusive Choice**: An instance of \f$ A + B \f$ contains either an A or a B, but never both simultaneously.
* **Cardinality**: The state space is the **sum** of its components: \f$ Card(A + B) = Card(A) + Card(B) \f$.
* **Algebraic Property**: It is the dual of the Product. While a Product asks you to "Take All," a Sum asks you to "Pick One."

### Example
```cpp
std::variant<int, float> p; 
```

@subsection variant Variant (The Labeled Sum)
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

**/
