#error This file is for documentation only - DO NOT INCLUDE
/**

@page product Product Types 

@section product_construction Product Constructions (The Logic of "AND")

Products represent types where multiple elements exist simultaneously.
The operands of the product are types. 
The structure of a product type is determined by the fixed order of the operands. 

---

@section product_type Product Type \f$ (A \times B) \f$

A **Product Type** is a compound type formed by combining multiple types. 

An instance of a product type in it's simplest form is a called a [tuple](https://en.wikipedia.org/wiki/Tuple).

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
returns the elements at the desired index. Formally it is denoted as : 

\f$ \pi_1(x) : T_1, \pi_2(x) : T_2, ..., \pi_n(x) : T_n \f$

In kumi this corresponds to the `get` functions
```c
auto a = kumi::get<0>(kumi::tuple<int,float>{ 1, 2.f });
```

A product type follows **List Algebra**.
+ **Order Dependence**: Position is identity. \f$ (A, B) \f$ is structurally distinct from \f$ (B, A) \f$ even though they contain the same underlying types.
+ **Cardinality**: The total state space is the **product** of the states of its components: \f$ Card(A \times B) = Card(A) \times Card(B) \f$.

@subsection tuple_programming Programming Languages Considerations 

Product types can also be composed of homogeneous types, such a tuple does not differ from array types. In most programming
models homogeneous product types can be efficiently stored via contiguous location in memory without needing to insert 
padding. By definition, an homogeneous product type can be iterated on by indexing as the gap between two consecutive 
elements is fixed. This property does not hold for their heterogeneous counterpart.

The C++ standard library provides an implementation of a tuple type as well as some special cases. Kumi provides a generic
yet optimized representation of them. Each type provided in the standard can be represented efficiently.

| STL type            | Kumi                    |
|:--------------------|:------------------------|
| std::pair<T1,T2>;   | kumi::tuple<T1,T2>      |
| std::tuple<Ts...>;  | kumi::tuple<Ts...>      |
| std::array<T,5>;    | kumi::tuple<T,T,T,T,T>  |
| std::complex<T>;    | kumi::tuple<T,T>        |

---

@section record_type Record Type \f$ (\{l_A: A\} \times \{l_B: B\}) \f$

A **Record Type** identifies its components by a **unique label** rather than a position. 

An instance of a record type in it's simplest form is a called a [record](https://en.wikipedia.org/wiki/Record_(computer_science)). 
In many programming languages, it is refered to as a struct. (Let aside considerations about object oriented progamming, inheritance, etc...)

A **Record Type** is the labeled version of a Product, it can be seen as the product of mathematical sets. 
Similarily to tuples, it accepts one constructor that takes a variadic number of input that are in this case fields.

Formally it can be written as :

\f$ \{l_1 : x_1, l_2 : x_2, ..., l_n : x_n\} : T_1 \times T_2 \times ... \times T_n \f$

This can be read as : the record is composed of elements of types \f$ T_1 \f$ to \f$ T_n\f$
with corresponding values \f$ x_1 \f$ to \f$ x_n \f$ that are labeled with \f$ l_1 \f$ to \f$ l_n \f$.

The corresponding definition in kumi could look like the following:
```cpp
using namespace kumi::literals;
kumi::record a = { "x"_id = 42, "y"_id = 13.37f, "z"_id = 'd' };
```

To extract values from a record, there are projections that are term constructors.
A projection (often noted \f$ \pi \f$) is a function that given a product type 
returns the elements. In a record, projections are generally labeled instead of indexed. Formally it is denoted as : 

\f$ \pi_{l_1}(x) : T_1, \pi_{l_2}(x) : T_2, ..., \pi_{l_n}(x) : T_n \f$

In kumi this corresponds to the `get` functions
```c
auto a = kumi::get<"x">(kumi::record{ "x"_id = 42, "y"_id = 13.37f, "z"_id = 'd' });
```

One could also use standard projections that are index, this simply modifies the semantic and the type that is returned.
Where \f$ T \f$ denotes the type of the value stored in a record, \f$ \{l:T\} \f$ denotes the combination of the label
and the type of the field. This is the return type of an indexed access on a record.

It follows **Set Algebra** on top of **List Algebra**.
+ **Label Identity**: Components are identified by unique **Labels** (names) rather than position.
+ **Permutation**:  Theoretically, a record is a set of field mappings. In many formal definitions, `{x: int, y: float}` 
                    is isomorphic to `{y: float, x: int}` because the set of labels and their associated types are identical.
+ **Semantic Access**: Access is performed via labels (`get<'x'>(r)`), adding semantic meaning to the structure.

Operation on records are traditionally not structural in the sens that they operate per label, never per 
element. However, as they are internally represented by a tuple, such operation are permitted. As an example, one
could "rotate" a record \f$ n \f$ positions to the left. Mathematically this might not make a lot of sens
whereas for a programmer that has to consider memory representation, this is potentially critical to have.

**/
