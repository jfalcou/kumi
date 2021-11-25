# Accessing a tuple's element

## Structured bindinds
`kumi::tuple` supports structured binding.

<iframe width="100%" height="300px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'@!'+%7D%3B%0A%0A++auto+%5Ba,b,c,d%5D+%3D+t%3B%0A++std::cout+%3C%3C+a+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+b+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+c+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+d+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:37.12793733681462,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:62.87206266318538,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

## `get`

**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I, typename... Ts>
  requires( I<sizeof...(Ts) )
  [[nodiscard]] constexpr decltype(auto) get(tuple<Ts...>& arg) noexcept;

  template<std::size_t I, typename... Ts>
  requires(I<sizeof...(Ts))
  [[nodiscard]] constexpr decltype(auto) get(tuple<Ts...> const& arg) noexcept;
}
```

Extracts the `I`th element from a `kumi::tuple`. Note that `get` will only participate
in overload resolution if its parameter is a valid index within [0, `t.size()`[.

**Example:**

<iframe width="100%" height="300px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'@!'+%7D%3B%0A++std::cout+%3C%3C+get%3C0%3E(t)+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+get%3C1%3E(t)+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+get%3C2%3E(t)+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+get%3C3%3E(t)+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:37.12793733681462,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:62.87206266318538,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>


## `tuple::operator[]`


**Synopsis:**
```c++
namespace kumi
{
  template<std::size_t I> requires(I<sizeof...(Ts))
  constexpr decltype(auto) tuple::operator[](index_t<I>) noexcept;

  template<std::size_t I> requires(I<sizeof...(Ts))
  constexpr decltype(auto) tuple::operator[](index_t<I>) const noexcept;
}
```

As a shortcut, you can also use `operator[]` directly on a `kumi::tuple` using the user-defined
literal constant indexing or the `kumi::index<N>` template variable.

`operator[]` will only participate in overload resolution if its parameter is a valid index within
[0, `t.size()`[.

**Example:**

<iframe width="100%" height="300px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++using+namespace+kumi::literals%3B%0A%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'@!'+%7D%3B%0A++std::cout+%3C%3C+t%5B0_c%5D+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+t%5B1_c%5D+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+t%5B2_c%5D+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+t%5Bkumi::index%3C3%3E%5D+%3C%3C+%22%5Cn%22%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:37.12793733681462,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:62.87206266318538,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
