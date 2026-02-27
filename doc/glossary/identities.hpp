#error This file is for documentation only - DO NOT INCLUDE
/**

@page identity The Identity Elements (The "0" and "1" of Types)

Just as there are neutral elements for mathematical operations, there are neutral elements for types. The neutral is a 
mathematical element that has no effect on the computation such that using it results in the identity. The  simplest 
example might be adding 0 to some natural number. With this said, before building complex types, we must define the 
neutrals that govern type algebra. These types are the foundational "identity" elements.

---

@section empty Empty Type : \f$ (0 / \bot) \f$

The **Empty Type** is the identity element for **Sums** \f$ (A + 0 \cong A ) \f$. It represents a type with no 
inhabitants.

* **Cardinality**: 0 states. It is mathematically impossible to construct an instance of this type.

* **Algebraic Role**: In logic, it represents a contradiction. In code, it represents a path that can never be reached. 
                      A function returning the Empty Type is a "diverging" function (it never returns).

* **Identity Property**:  Just as \f$ x + 0 = x \f$, having a choice between Type A or an impossible Type 0 is logically 
                          equivalent to simply having Type A.

One cannot write such a type, but could specify a function that returns empty, in C++ this can be expressed the 
following way.
```cpp
[[noreturn]] void foo() { 
  throw std:runtime_error("Never returns");
}
```

@note As of today, kumi does not provide sum types, so this kind of type is not used. The focus was made on product 
types and their associated algebra.

---

@section unit Unit Type : \f$ (1 / \top) \f$

The **Unit Type** is the identity element for **Products** \f$ (A \times 1 \cong A) \f$. It represents a type with
exactly one inhabitant.

@note It is also refered to as the product of no types.

* **Cardinality**: 1 state. It contains exactly one possible value (often written as `()`).

* **Algebraic Role**: It represents "no information" or "success without data." Because there is only one possible state, 
                      the value itself is predictable and thus carries zero entropy.

* **Identity Property**:  Just as \f$ x \times 1 = x \f$, a pair containing Type A and a Unit Type provides no more 
                          information than Type A alone.

In C++ such a type can be written simply as an empty struct. 
```cpp
struct unit {};
```

[In the next page](@ref product), we will see how to combine the simple types we saw until now in order to create more 
complex types.

**/
