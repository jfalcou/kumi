C++ Specific Terms {#cpp_spec}
==========

# Empty Base Optimization
EBO is a compiler optimization technique. In C++, even an empty struct (one with no data members) must have a size of at least 1 byte to ensure it has a unique address in memory.

However, if that empty struct is used as a base class, the compiler is allowed to optimize that space away to 0 bytes. This is critical for high-performance libraries that use many "tag" types or "stateless" functors, as it prevents memory bloat.

    Reference: CppReference: Empty base optimization

## Aggregate type
An Aggregate is a specific kind of class or struct in C++ that is "simple" enough to be initialized directly with braces {}.

To be an aggregate, a type generally must have:

    No private or protected non-static data members.

    No user-declared constructors.

    No virtual functions.

Why it matters:
Aggregates allow for Aggregate Initialization, which is often faster and allows for cleaner syntax than defining complex constructors.

## Structural type

Introduced in C++20, a Structural Type is a class type that can be used as a Non-Type Template Parameter (NTTP).

Previously, template parameters were limited to integers or pointers. Now, you can pass complex objects (like a fixed-size vector or a tuple) as a template argument, provided the type is "Structural" (roughly: public members, no complex copying logic).

## Tuple Protocol
Tuple Protocol

The Tuple Protocol is a set of standardized "hooks" in the C++ Standard Library. By implementing these hooks for your custom class, you tell the compiler: "Treat my class like a tuple."

To satisfy the protocol, a type T must specialize:

    std::tuple_size<T>: Reports how many elements are in the structure.

    std::tuple_element<I, T>: Reports the type of the element at index I.

    Provide get<I>(): A function to access the element.

Why is this useful?
It enables Structured Bindings, allowing users to unpack your custom types easily

This serves as a manual reflection mechanism, as C++ (prior to C++26) lacks a proper reflection mechanism to inspect structures, these functions specifications are giving the necessary informations to the compiler
in order to natively adapt your structure to be a tuple.
