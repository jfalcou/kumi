# Tuple-related Concepts

## `product_type`

**Synopsis:**
```c++
namespace kumi
{
  template<typename T>
  concept product_type = is_product_type<T>::value
                      && requires(T const& t) { /* implementation specific */ };
}
```

A type `T` models `kumi::product_type` if it opts in for the Product Type semantic and provides
supports for structured bindings.

## `sized_product_type`

**Synopsis:**
```c++
namespace kumi
{
  template<typename T, std::size_t N>
  concept sized_product_type = product_type<T> && (size<T>::value == N);
}
```

A type `T` models `kumi::sized_product_type<N>` if it models `kumi::product_type` and has exactly
`N` elements.
