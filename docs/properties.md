# Informations about Tuples

## Standard library integration
`kumi::tuple` is compatible with the standard traits pertaining to tuple manipulation, namely
`std::tuple_size` and `std::tuple_element`

**Example:**
<iframe width="100%" height="300px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'6!'+%7D%3B%0A++using+type+%3D+decltype(t)%3B%0A%0A++std::cout+%3C%3C+std::tuple_size%3Ctype%3E::value+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+std::boolalpha+%0A++++++++++++%3C%3C+std::is_same_v%3Cstd::tuple_element_t%3C1,type%3E,double%3E+%0A++++++++++++%3C%3C+%22%5Cn%22%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:52.32375979112271,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:47.67624020887729,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

## `tuple::size`

**Synopsis:**
```c++
namespace kumi
{
  [[nodiscard]] static constexpr auto tuple::size() noexcept;
}
```

Returns the number of elements in a `kumi::tuple`.

**Example:**

<iframe width="100%" height="250px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'6!'+%7D%3B%0A++kumi::tuple+e+%3D+%7B%7D%3B%0A%0A++std::cout+%3C%3C+t.size()+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+e.size()+%3C%3C+%22%5Cn%22%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:47.20626631853786,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:52.79373368146214,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>


## `tuple::empty`

**Synopsis:**
```c++
namespace tuple
{
  [[nodiscard]] static constexpr bool tuple::empty() noexcept;
}
```

Returns `true` if the number of elements in a `kumi::tuple`is equal to 0 and `false` otherwise.

**Example:**

<iframe width="100%" height="250px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'6!'+%7D%3B%0A++kumi::tuple+e+%3D+%7B%7D%3B%0A%0A++std::cout+%3C%3C+std::boolalpha+%3C%3C+t.empty()+%3C%3C+%22%5Cn%22%3B%0A++std::cout+%3C%3C+std::boolalpha+%3C%3C+e.empty()+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:49.92167101827676,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),header:(),k:50.07832898172324,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
