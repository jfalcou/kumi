C++ Specific Terms {#cpp_spec}
==========

## Empty Base Optimization
[EBO](https://eel.is/c++draft/intro.object#7) is a compiler optimization technique. In C++, even an empty struct (one with no data members)
must have a size of at least 1 byte to ensure it has a unique address in memory.

However, if that empty struct is used as a base class, the compiler is allowed to optimize that
space away to 0 bytes. This is critical for high-performance libraries that use many "tag" types
or "stateless" functors, as it prevents memory bloat.

---

## Aggregate type
An [Aggregate](https://eel.is/c++draft/dcl.init.aggr) is a specific kind of class or struct in C++ that is "simple" enough to be initialized
directly with braces {}.

To be an aggregate, a type generally must have:

+ No private or protected non-static data members.
+ No user-declared constructors.
+ No virtual functions.

Aggregates allow for Aggregate Initialization, which is often faster and allows for cleaner syntax
than defining complex constructors.

---

## Structural type

Introduced in C++20, a [Structural Type](https://eel.is/c++draft/temp#param-12) is a class type that can be used as a Non-Type Template Parameter
(NTTP).

Previously, template parameters were limited to integers or pointers. Now, one can pass complex objects
(like a tuple) as a template argument, provided the type is "Structural" (roughly: public members, 
no complex copying logic).

---

## Tuple Protocol

The [Tuple Protocol](https://eel.is/c++draft/dcl.struct.bind) is a set of standardized "hooks" in the C++ Standard Library. By implementing these
hooks for a custom class, one tells the compiler to treat the class like a tuple.

To satisfy the protocol, a type T must specialize:

```cpp
std::tuple_size<T>; //Reports how many elements are in the structure.

std::tuple_element<I, T>;   //Reports the type of the element at index I.

type.get<I>() / get<I>(type); //A function to access the element.
```

It enables Structured Bindings, allowing one to unpack custom types easily

This serves as a manual reflection mechanism, as C++ (prior to C++26) lacks a proper reflection
mechanism to inspect structures, these functions specifications are giving the necessary informations
to the compiler in order to natively adapt your structure to be a tuple.

---

## Containers

In C++ [containers](https://eel.is/c++draft/containers) are structures built in order to store data. There can be different
kinds of containers such as dynamic containers (ex : `std::vector`), there are also
static containers (ex: `std::array`) or associative ones (ex: `std::set`). These
types are often focusing on storing homogeneous data, and some of them have properties
ressembling product types, namely static contiguous containers.
