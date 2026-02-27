#error This file is for documentation only - DO NOT INCLUDE
/**

@page identity The Identity Elements (The "0" and "1" of Types)

@tableofcontents

* Just as there are neutral elements for the different mathematical operations, there are neutral elements for types. 
With this said, before building complex types, we must define the identities that govern type algebra. 
These types are the foundational "identity" elements.

---

@section empty Empty Type : \f$ (0 / \bot) \f$

The **Empty Type** is the identity element for **Sums** \f$ (A + 0 \cong A ) \f$.
* **Cardinality**: 0 states. It is mathematically impossible to construct an instance of this type.
* **Algebraic Role**: In logic, it represents a contradiction. In code, it represents a path that can never be taken. 
                      A function returning the Empty Type is a "diverging" function (it never returns).
* **Identity Property**:  Just as \f$ x + 0 = x \f$, having a choice between Type A or an impossible Type 0 is logically 
                          equivalent to simply having Type A.

One cannot write such a type, but could specify a function that returns empty, in C++ this can be expressed the 
following way.
```cpp
[[noreturn]] void foo(){ }
```

---

@section unit Unit Type : \f$ (1 / \top) \f$

The **Unit Type** is the identity element for **Products** \f$ (A \times 1 \cong A) \f$.
Also refered to as the product of no types.

* **Cardinality**: 1 state. It contains exactly one possible value (often written as `()`).
* **Algebraic Role**: It represents "no information" or "success without data." Because there is only one possible state, 
                      the value itself is predictable and thus carries zero entropy.
* **Identity Property**:  Just as \f$ x \times 1 = x \f$, a pair containing Type A and a Unit Type provides no more 
                          information than Type A alone.

In C++ such a type can be written simply as a singleton.
```cpp
struct unit {};
```

[In the next page](@ref product), we will see how to combine these simple types in order to compose what we call 
product types which is the main topic of kumi.

**/
