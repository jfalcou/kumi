# Creating a Tuple

## Aggregate construction
The main way to construct a `kumi::tuple` is to construct it as an aggregate.

<iframe width="100%" height="220px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple%3Cint,double,float%3E+t+%3D+%7B+1,+2.3,+4.5f+%7D%3B%0A++std::cout+%3C%3C+t+%3C%3C+%22%5Cn%22%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50.278634159683236,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),k:49.72136584031678,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',m:100,n:'0',o:'',t:'0')),version:4"></iframe>

Of course, you can also let the compiler deduce the proper type of the `kumi::tuple`:

<iframe width="100%" height="220px" src="https://godbolt.org/e?#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++kumi::tuple+t+%3D+%7B+1,+2.3,+4.5f,+!'6!'+%7D%3B%0A++std::cout+%3C%3C+t+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50.278634159683236,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),k:49.72136584031678,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',m:100,n:'0',o:'',t:'0')),version:4"></iframe>

**KUMI** also provides convenience functions to build tuples in more complex situations.

## `kumi::make_tuple`

**Synopsis:**
```c++
namespace kumi
{
  template <typename... Ts>
  [[nodiscard]] constexpr tuple<std::unwrap_ref_decay_t<Ts>...>  make_tuple(Ts&&... ts);
}
```

Creates a `kumi::tuple` object, deducing the target type from the types of arguments.

**Examples:**

<iframe width="100%" height="220px" src="https://godbolt.org/e?#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aint+main()%0A%7B%0A++auto+t+%3D+kumi::make_tuple(+1,+2.3,+4.5f,+!'6!')%3B%0A++std::cout+%3C%3C+t+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50.278634159683236,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),k:49.72136584031678,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',m:100,n:'0',o:'',t:'0')),version:4"></iframe>

## `tie`

**Synopsis:**
```c++
template <typename... Ts> [[nodiscard]] constexpr tuple<Ts&...> tie(Ts&... ts);
```

Creates a `kumi::tuple` of lvalue references to its arguments.

**Example:**

<iframe width="100%" height="400px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%0Aauto+generate()%0A%7B%0A++return+kumi::tuple%7B1,2.3,4.56f%7D%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++int++++i%3B%0A++double+d%3B%0A++float++f%3B%0A%0A++kumi::tie(+i,d,f+)+%3D+generate()%3B%0A%0A++std::cout+%3C%3C+i+%3C%3C+%22+%22+%3C%3C+d+%3C%3C+%22+%22+%3C%3C+f+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50.278634159683236,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),k:49.72136584031678,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',m:100,n:'0',o:'',t:'0')),version:4"></iframe>

## `forward_as_tuple`

**Synopsis:**
```c++
template <typename... Ts> [[nodiscard]] constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... ts);
```

Constructs a `kumi::tuple` of references to the arguments in `ts`` suitable for forwarding as an
argument to a function. The `kumi::tuple` has rvalue reference data members when rvalues are used
as arguments, and otherwise has lvalue reference data members.

Note that, if the arguments are temporaries, `forward_as_tuple` does not extend their lifetime;
they have to be used before the end of the full expression.

**Example:**

<iframe width="100%" height="460px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ckumi.hpp%3E%0A%23include+%3Ciostream%3E%0A%23include+%3Cvector%3E%0A%23include+%3Cstring%3E%0A%0Atemplate%3Ctypename+Data%3E%0Astd::vector%3Cstd::string%3E+build(Data+d)%0A%7B%0A++return+std::vector%3Cstd::string%3E+(+kumi::get%3C0%3E(d)%0A++++++++++++++++++++++++++++++++++,+std::move(kumi::get%3C1%3E(d))%0A++++++++++++++++++++++++++++++++++)%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++auto+v+%3D+build(+kumi::forward_as_tuple(4,std::string%7B%22the+text+!!%22%7D))%3B%0A%0A++for(auto+const%26+s+:+v)%0A++++std::cout+%3C%3C+s+%3C%3C+%22%5Cn%22%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50.278634159683236,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:executor,i:(argsPanelShown:'1',compilationPanelShown:'0',compiler:g112,compilerOutShown:'0',execArgs:'',execStdin:'',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!((name:kumi,ver:trunk)),options:'-std%3Dc%2B%2B20+-O3',source:1,stdinPanelShown:'1',tree:'1',wrap:'1'),l:'5',n:'0',o:'Executor+x86-64+gcc+11.2+(C%2B%2B,+Editor+%231)',t:'0')),k:49.72136584031678,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',m:100,n:'0',o:'',t:'0')),version:4"></iframe>
