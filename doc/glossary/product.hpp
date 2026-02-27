#error This file is for documentation only - DO NOT INCLUDE
/**

@page product Product Types 

@tableofcontents

@section product_construction Product Constructions (The Logic of "AND")

Products represent types where multiple elements exist simultaneously.
The operands of the product are types. 
The structure of a product type is determined by the fixed order of the operands. 

@subsection product_type Product Type \f$ (A \times B) \f$

A **Product Type** is a compound type formed by combining multiple types. 

An instance of a product type in it's simplest form is a called a tuple.

Such a type only accepts one constructor that takes a variadic number of inputs
and builds the product of them. A product type has a fixed length and the types of 
the elements is fixed. Formally it can be written as :

\f$ (x_1, x_2, ..., x_n) : T_1 \times T_2 \times ... \times T_n \f$

This can be read as : the tuple is composed of elements of types \f$ T_1 \f$ to \f$ T_n\f$
with corresponding values \f$ x_1 \f$ to \f$ x_n \f$.

The corresponding definition in kumi could look like the following:
```cpp
kumi::tuple<int,float,char> a = { 42, 13.37f, 'd' };
```

To extract values from a tuple, there are projections that are term constructors.
A projection (often noted \f$ \pi \f$) is a function that given a product type 
returns the elements. Formally it is denoted as : 

\f$ \pi_1(x) : T_1, \pi_2(x) : T_2, ..., \pi_n(x) : T_n \f$

In kumi this corresponds to the `get` functions
```c
auto a = kumi::get<0>(kumi::tuple<int,float>{ 1, 2.f });
```

A product type follows **List Algebra**.
+ **Order Dependence**: Position is identity. \f$ (A, B) \f$ is structurally distinct from \f$ (B, A) \f$ even though they contain the same underlying types.
+ **Cardinality**: The total state space is the **product** of the states of its components: \f$ Card(A \times B) = Card(A) \times Card(B) \f$.

### Example
```cpp
std::tuple<int, float> p; // Ordered product
```

@note A pair is a special case of a tuple that is composed of only two elements.

* **Reference** [Wikipedia: Tuple](https://en.wikipedia.org/wiki/Tuple)

---

@subsection record_type Record Type \f$ \{label: Type\} \f$  (The Struct)

A **Record Type** identifies its components by a **unique label** rather than a position. 

An instance of a record type is called a struct in many programming languages.
(Let aside considerations about object oriented progamming, inheritance, etc...)

A **Record Type** is the labeled version of a Product, it can be seen as the product of mathematical sets. 
It follows **Set Algebra** on top of **List Algebra**.

Operation on records are traditionally not structural in the sens that they operate per label, never per 
element. However, as they are internally represented by a tuple, such operation are permitted. As an example, one
could "rotate" a record \f$ n \f$ positions to the left. Mathematically this might not make a lot of sens
whereas for a programmer that has to consider memory representation, this is potentially critical to have.

+ **Label Identity**: Components are identified by unique **Labels** (names) rather than position.
+ **Permutation**:  Theoretically, a record is a set of field mappings. In many formal definitions, `{x: int, y: float}` 
                    is isomorphic to `{y: float, x: int}` because the set of labels and their associated types are identical.
+ **Semantic Access**: Access is performed via labels (`u.id`), adding semantic meaning to the structure.

### Example 
```cpp
struct User {
    int id;       // Label: id
    float score;  // Label: score
};
```

* **Reference** [Wikipedia: Record](https://en.wikipedia.org/wiki/Record_(computer_science))

[In the next page](@ref sum), we will see the duals of product types which are called sum types.

**/
