# Adapting existing type as tuple

If `kumi::tuple` is the readily available tuple type that **KUMI** can handle,
you can adapt other types to be compatible with **KUMI** operations.

To be able to be used by **KUMI**, you need to adapt your type so it is usable with structured
bindings. This invloves providing specialisation for `std::tuple_size`, `std::tuple_element` and
to provide an ADL-reachable `get<I>` function. Note that the specialisation for the tuple traits
does not require the inclusion of `tuple` header but only `utility`.

Being able to support structured bindings is not enough as some structured bindign compatible
type may not be suitable as a product type. In order to be usable with **KUMI**, your type needs
to opt-in for the so called Product Type Semantic.

This can be done in two ways:
  - exposing an internal `is_product_type` type that evaluates to `void`
  - specialising the `kumi::is_product_type` template class so it exposes a static constant member `value` that evaluates to `true`

Once done, the type is now usable directly in any kind of **KUMI** operation

**Examples:**
  + Using `std::array`

<iframe width="100%" height="450px"  src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ciostream%3E%0A%23include+%3Ckumi.hpp%3E%0A%23include+%3Carray%3E%0A%0Atemplate%3Ctypename+T,+std::size_t+N%3E%0Astruct++kumi::is_product_type%3Cstd::array%3CT,N%3E%3E+%0A++++++:+std::true_type+%0A%7B%7D%3B%0A%0Aint+main()%0A%7B%0A++std::array%3Cfloat,5%3E+vs%7B0.1f,1.2f,2.3f,3.4f,4.5f%7D%3B%0A++kumi::for_each_index(+%5B%5D(int+i,+auto+e)+%0A++++++++++++++++++++++++%7B+%0A++++++++++++++++++++++++++std::cout+%3C%3C+%22%23%22+%3C%3C+i%0A++++++++++++++++++++++++++++++++++++%3C%3C+%22+:+%22+%3C%3C+e+%0A++++++++++++++++++++++++++++++++++++%3C%3C+%22%5Cn%22%3B+%0A++++++++++++++++++++++++%7D%0A++++++++++++++++++++++,+vs%0A++++++++++++++++++++++)%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:74.88250652741515,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:25.11749347258485,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

  + Using `ns::some_box`

<iframe width="100%" height="1000px" src="https://godbolt.org/e#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAMzwBtMA7AQwFtMQByARg9KtQYEAysib0QXACx8BBAKoBnTAAUAHpwAMvAFYTStJg1DIApACYAQuYukl9ZATwDKjdAGFUtAK4sGe1wAyeAyYAHI%2BAEaYxHoADqgKhE4MHt6%2BcQlJAkEh4SxRMVy2mPaOAkIETMQEqT5%2BRXaYDskVVQQ5YZHRegqV1bXpDX3twZ353VwAlLaoXsTI7BzmAMzByN5YANQmy25OvcSYrDvYJhoAgitrG5jbuwDWPngAdAixsSdnlxfMbAqxTAWmwYCi%2BJgA7FYLptNgcvA5NhFUKovjCIVDzjCYV5EkZNngFAB9WLEDDwgiEggAT1itx2ABFNgA3VB4dA7DFY/GCfEc1FYqi0VBMAibKh86FY5AIKqbUzLTnbcH0iXfTGbAiYFixAyanZuXroEAgRIAL0wlM2AEkTpssOtqbSIEwvERJttJcBMAQIEjVHKBL1zAA2WHuhioTCqBaxAj89H8mF4KgBkGa1QkiA25YqnMad2HAhzBiw554VVc5Op3pRzPZ3P0qabQvF0vihWJ/EptBp2vELMMhlmAve1sKZ7yxUQlUXfma7W6zD6w3Gs0W0XZ7Aw%2B20R2YZ2u1Du/len1%2BkNh4GR6OYWPxyGdqs9msZ/v1hn55uj4gl8fljuSkm3aBumdaDjmTYtj%2BbYVliT4gX2A45kOI5FtB46TvejIepcypghc846iKS67LaXxwgisIEEaIBFjqFprvqILGueyynIBWIgFRNHBJqwDEGIhLPpUgjLtRq54OalKkMsZEPnhAFqoRi76raFGiiutFePRhIlFqjBxrsGikMxICsVu6KbDiwTABqNJ0jm3KGRYWLTqqynEapbFUcQ5LccadH0Lp9BsKJuxFKZ5lKi51l4nudyMoKwrOUquYYh5eqkd56n%2BVpOl6aFhluGYJkKCxyJyTFuK2fFDJyjKxAcmiCkYl8vGbCwTDBBAkxgg%2BkqRciiIopCRRmM8yxUKQYAcAAWjNbmKTCjwsBQID8MQumAgghLBFgqgQNsACsVhHfSEDtXgpCbC6RCbJgx4cVyz0vc9lmdq9n2vZpaCuncbj6tsZhmCs5hmP9gPlk9X0w7DEO7ED4NcWD8NuPdOFw5jsNeWjYMmEdbgMHjCoY1jX1udDZObNdEQopTZO9Yp04cNMtCcEdvB%2BBwWikKgnAA5Y1iwrM8x0mYyw8KQBCaCz0z3CA4Ljcs4JHQAnOCqtcFwwPglwR3SGzHCSJzMu85wvBlcZ0vcyzpBwLASBRk0h5kBQzrEMACjKIYJRCAgqAAO5c5LaDanQIrJN7IS0H7gdczzoexHQ3TAFrJWJ8nxAAPKurHQem07yDnB7ZUcLwhcVPgXO8PwggiGI7BSDIgiKCo6g26QuhFAYRgoNY1j6HgERlbAvzsCtV1Mt0BC%2BQw9yTNMqCxskpcALSGgypiC5YZgaJsq9Z8sFsiwsPTUcEUe%2B/7%2BfcLwM%2BYIsksBwJsScDwrPsybHd8xw2CqM7RBiCbFUAADmDKvYMkhNjAGQMgTYWtnjgwgALKwlhrq4EICQIGEtJh3xlgvUgCAjhYBiD1Ug8szDgmeMGMwkgNC7xASA8EisQGSGDMsfQnBjYmVNj/C2IArb4I/hwMwX8eZ8KlkI0gU9iCJGcJIIAA%3D%3D"></iframe>
