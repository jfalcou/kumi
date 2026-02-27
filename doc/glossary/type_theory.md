Type-Theoretic Foundations {#type_theory}
----------

## Introduction

---

## Monoid
A type is a **Monoid** if it possesses a binary operation to combine elements and an identity element.
It needs to model other mathematical laws such as :
1. **Associativity:** \f$ (a + b) + c = a + (b + c) \f$.
2. **Identity Element:** \f$ a + Identity = a \f$.

**Example:** `std::string` is a monoid where the operation is `+` (concatenation) and the identity is `""`.
