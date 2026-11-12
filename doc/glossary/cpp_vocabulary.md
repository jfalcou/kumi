C++ Vocabulary {#kumi_cpp_vocabulary}
==========

## Empty Base Optimization

A class is empty when it is a class type other than a union, with no non-static data member other than subobjects of
zero size, no virtual function, no virtual base class, and no non-empty base class
([[meta.unary.prop]](https://eel.is/c++draft/meta.unary.prop), `is_empty`). An object of an empty class still occupies
at least one byte, so that two distinct objects have distinct addresses, unless it is a potentially-overlapping
subobject, that is, a base class subobject or a member declared `[[no_unique_address]]`
([[intro.object]/7](https://eel.is/c++draft/intro.object#7)).

The [empty base optimization](https://eel.is/c++draft/intro.object#8) gives an empty base class subobject the size zero,
which the standard requires for a base of a standard-layout class without non-static data members and leaves to the
implementation otherwise ([[intro.object]/8](https://eel.is/c++draft/intro.object#8)), and which two subobjects of
similar types at the same address forbid ([[intro.object]/10](https://eel.is/c++draft/intro.object#10)).

A library that stores many tag types or stateless function objects saves, through the optimization, one byte and the
padding that follows it for each such object. **KUMI** applies it to the empty, non-final element types of kumi::tuple,
and does not use `[[no_unique_address]]`, so that an empty class costs a byte as a member, nothing as a base class, and
nothing as an element of a kumi::tuple:

@godbolt{doc/glossary/vocabulary_ebo.cpp}

---

## Aggregate type

An [aggregate](https://eel.is/c++draft/dcl.init.aggr) is an array, or a class with no user-declared or inherited
constructor, no private or protected direct non-static data member, no private or protected direct base class, and no
virtual function or virtual base class ([[dcl.init.aggr]/1](https://eel.is/c++draft/dcl.init.aggr#1)). Its elements are
its direct base classes, then its non-static data members, which a braced list initializes in order, with the elision of
the inner braces, and which a parenthesized list initializes as well since C++20, without brace elision.

kumi::tuple and kumi::record are aggregates holding a single member that stores the elements, so that a braced list
initializes them by brace elision, whereas a parenthesized list such as `kumi::tuple<int, float> t(1, 2.f)` does not
compile:

@godbolt{doc/glossary/vocabulary_aggregate.cpp}

---

## Structural type

A [structural type](https://eel.is/c++draft/temp.param#12) is a scalar type, an lvalue reference type, or a literal
class type whose base classes and non-static data members are all public, non-mutable, and of structural types or arrays
of them ([[temp.param]/12](https://eel.is/c++draft/temp.param#12)).

Since C++20, the type of a non-type template parameter may be any structural type, where C++17 restricted it to integral
and enumeration types, pointers and lvalue references to objects and functions, pointers to members, `std::nullptr_t`,
and placeholder types, so that floating-point types and structural class types became valid.

**KUMI** takes a label as a template argument of the structural type kumi::str, as the projection `get<"x">` of a record
does. A kumi::tuple whose element types are structural is a valid type of a template parameter, whose values are valid
template arguments, whereas `std::tuple`, whose libstdc++ implementation has non-public base classes, is not:

@godbolt{doc/glossary/vocabulary_structural.cpp}

---

## Tuple Protocol

The tuple protocol is the informal name of the conditions under which a structured binding decomposes a class through
`std::tuple_size`, `std::tuple_element`, and `get`, a term that the standard does not define.

By [[dcl.struct.bind]/7](https://eel.is/c++draft/dcl.struct.bind#7), a structured binding decomposes a type `E` this way
when `std::tuple_size<E>` names a complete class type with a member named `value`: the binding of index `i` has the type
`std::tuple_element<i, E>::type`, and it is initialized by the member function template `e.get<i>()` when the lookup of
`get` in `E` finds a template whose first template parameter is a non-type parameter, and by `get<i>(e)`, found by
argument-dependent lookup alone, otherwise.

Structured bindings decompose two other kinds of types without the protocol
([[dcl.struct.bind]/8](https://eel.is/c++draft/dcl.struct.bind#8)): the arrays, and the classes whose non-static data
members are all direct members of the class or of one of its base classes, accessible where the binding is declared. C++
having no reflection before C++26, a class whose members are not accessible describes its decomposition by hand, through
these specializations.

**KUMI** reads a product type through the same three pieces, with one difference: its algorithms call `get<I>(t)`
unqualified, which finds a free function by argument-dependent lookup and never a member function, so that a class that
provides `get` as a member decomposes in a structured binding and fails kumi::apply. The concept
kumi::concepts::product_type tests `std::tuple_size` and `std::tuple_element` alone.

A class for which these two templates are specialized, and which provides a free `get<I>` returning references to its
members for each value category, is accepted by the algorithms of the library as kumi::tuple is, as `ns::people` is
below.

@godbolt{doc/glossary/vocabulary_adapt_tuple.cpp}

A class becomes a record when its elements are kumi::field types, its `get` takes an identifier, and
kumi::is_record_type_v is specialized for it, or it declares a member alias `is_record_type`. The class `geo::point` is
adapted as a record this way, its `get` taking the identifier of a field and returning a reference for each value
category:

@godbolt{doc/glossary/vocabulary_adapt_record.cpp}

---

## Containers

A [container](https://eel.is/c++draft/containers) of the C++ standard library stores objects of a single value type. The
library provides sequence containers, such as `std::vector` and `std::array`, associative containers, such as
`std::set`, and unordered associative containers, such as `std::unordered_map`, beside the container adaptors, such as
`std::stack`. A sequence container of fixed size and contiguous storage resembles a homogeneous product type, and
`std::array` models kumi::concepts::product_type.

**KUMI** describes containers by two concepts of its own: kumi::concepts::container accepts the built-in arrays and the
classes with the member types `value_type` and `size_type` and the functions `size`, `begin`, and `end`, and
kumi::concepts::static_container adds a size known at compile time, read from a built-in array or from a class template
of the form `Container<T, N>`:

@godbolt{doc/glossary/vocabulary_containers.cpp}

<div class="section_buttons">

| Previous                                |                                       Next |
|:----------------------------------------|-------------------------------------------:|
| [Bibliography](@ref kumi_references)    | [Nomenclature](@ref kumi_nomenclature)     |

</div>
