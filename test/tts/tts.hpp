//==================================================================================================
/**
  TTS - Tiny Test System
  Copyright : TTS Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#pragma once
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#endif
#include <iostream>
namespace tts
{
  inline int usage(const char* name)
  {
    std::cout << "TTS Unit Tests Driver\n";
    std::cout << "Usage: " << name  << " [OPTION...]\n";
    std::cout << "\nFlags:\n";
    std::cout << "  -h, --help        Display this help message\n";
    std::cout << "  -n, --no-color    Disable colored output\n";
    std::cout << "  -p, --pass        Report passing tests\n";
    std::cout << "  -x, --hex         Print the floating results in hexfloat mode\n";
    std::cout << "  -s, --scientific  Print the floating results in scientific mode\n";
    std::cout << "\nParameters:\n";
    std::cout << "  --filter=str      Only run tests with `str` in their description\n";
    std::cout << "  --precision=arg   Set the precision for displaying floating pint values\n";
    std::cout << "  --repeat=arg      Repeat each tests arg times\n";
    std::cout << "  --seed=arg        Set the PRNG seeds (default is time-based)\n";
    std::cout << "\nRange specifics Parameters:\n";
    std::cout << "  --block=arg       Set size of range checks samples (min. 32)\n";
    std::cout << "  --loop=arg        Repeat each range checks arg times\n";
    std::cout << "  --ulpmax=arg      Set global failure ulp threshold for range tests (default is 2.0)\n";
    std::cout << "  --valmax=arg      Set maximal value for range tests (default is code)\n";
    std::cout << "  --valmin=arg      Set minimal value for range tests (default is code)\n";
    std::cout << std::endl;
    return 0;
  }
}
#include <utility>
namespace tts
{
  struct callable
  {
    public:
    using signature_t = void(*)(void*);
    signature_t invoker = {};
    signature_t cleanup = {};
    void*       payload = {};
    constexpr callable() = default;
    template<typename Function>
    constexpr callable(Function f)
            : invoker{invoke<Function>}, cleanup{destroy<Function>}
            , payload{new Function{std::move(f)}}
    {}
    constexpr callable(callable&& other) noexcept
            : invoker{std::move(other.invoker)}, cleanup{std::move(other.cleanup)}
            , payload{std::move(other.payload)}
    {
      other.payload = {};
    }
    ~callable() { cleanup(payload); }
    constexpr callable(const callable&)             = delete;
    constexpr callable& operator=(const callable&)  = delete;
    constexpr callable& operator=(callable&&)       = delete;
    constexpr void operator()()       { invoker(payload); }
    constexpr void operator()() const { invoker(payload); }
    explicit constexpr operator bool() const { return payload != nullptr; }
    private:
    template <typename T>
    static void invoke(void* data) { (*static_cast<T*>(data))(); }
    template <typename T>
    static void destroy(void* data) { delete static_cast<T*>(data); }
  };
}
#include <vector>
#include <string>
namespace tts::detail
{
  inline std::string current_test = "";
  struct test
  {
    void operator()()
    {
      current_test = name;
      behaviour();
    }
    static inline bool acknowledge(test&& f);
    std::string     name;
    tts::callable   behaviour;
  };
  inline std::vector<test> suite = {};
  bool inline test::acknowledge(test&& f)
  {
    suite.emplace_back( std::forward<test>(f));
    return true;
  }
}
#include <cstddef>
#include <iostream>
namespace tts::detail
{
  struct env
  {
    void pass()     { test_count++; success_count++; }
    void fail()     { test_count++; failure_count++; }
    void fatal()    { test_count++; failure_count++; fatal_count++; }
    void invalid()  { test_count++; invalid_count++; }
    int report(std::ptrdiff_t fails, std::ptrdiff_t invalids) const
    {
      auto test_txt = test_count    > 1 ? "tests" : "test";
      auto pass_txt = success_count > 1 ? "successes" : "success";
      auto fail_txt = failure_count > 1 ? "failures" : "failure";
      auto inv_txt  = invalid_count > 1 ? "invalids" : "invalid";
      auto passes   = (fails || invalids) ?  0 : test_count;
      std::cout << "----------------------------------------------------------------\n";
      std::cout << "Results: " << test_count << " " << test_txt << " - "
                << success_count << "/" << passes << " " << pass_txt << " - "
                << failure_count << "/" << fails << " " << fail_txt << " - "
                << invalid_count << "/" << invalids << " " << inv_txt << "\n";
      if(!fails && !invalids) return test_count == success_count ? 0 : 1;
      else                    return (failure_count == fails && invalid_count == invalids) ? 0 : 1;
    }
    int test_count    = 0,
        success_count = 0,
        failure_count = 0,
        fatal_count   = 0,
        invalid_count = 0;
    bool fail_status = false;
  };
}
namespace tts
{
  inline ::tts::detail::env global_runtime;
  inline int report(std::ptrdiff_t fails, std::ptrdiff_t invalids)
  {
    return global_runtime.report(fails,invalids);
  }
}
#include <initializer_list>
#include <sstream>
#include <string>
namespace tts
{
  struct option
  {
    option() = default;
    option( std::string arg ) : token(std::move(arg)), position(token.rfind( '=' )) {}
    auto flag()     const { return token.substr(0, position); }
    bool is_valid() const { return !flag().empty(); }
    template<typename T> T get(T const& def = T{}) const
    {
      T that;
      if(is_valid())
      {
        std::istringstream os(token.substr(position+1));
        if(os >> that) return that;
        else           return def;
      }
      else
      {
        return def;
      }
    }
    std::string token     = "";
    size_t      position  = std::string::npos;
  };
  struct options
  {
    using params_t = std::initializer_list<const char*>;
    option find(const char* f ) const { return find({f}); }
    option find(params_t    fs) const
    {
      for(int i=1;i<argc;++i)
      {
        option o(argv[i]);
        for(auto f : fs)
          if( o.flag() == f ) return o;
      }
      return option{};
    }
    bool operator[](params_t    fs) const { return find(fs).is_valid(); }
    bool operator[](const char* f ) const { return operator[]({f}); }
    template<typename T> T value(params_t fs, T that = {}) const
    {
      if( auto o = find(fs); o.is_valid()) that = o.template get<T>(that);
      return that;
    }
    template<typename T> T value(const char* f, T that = {}) const
    {
      return value({f},that);
    }
    int argc;
    char const** argv;
  };
  inline ::tts::options arguments;
  inline bool           verbose_status;
}
#if !defined(TTS_CUSTOM_DRIVER_FUNCTION)
#  define TTS_CUSTOM_DRIVER_FUNCTION main
namespace tts::detail { constexpr bool use_main = true; }
#else
namespace tts::detail { constexpr bool use_main = false; }
#endif
namespace tts::detail { struct fatal_signal {}; }
#if defined(TTS_MAIN)
int TTS_CUSTOM_DRIVER_FUNCTION([[maybe_unused]] int argc,[[maybe_unused]] char const** argv)
{
  ::tts::arguments = ::tts::options{argc,argv};
  if( ::tts::arguments[{"-h","--help"}] )
    return ::tts::usage(argv[0]);
  ::tts::verbose_status =  ::tts::arguments[{"-p","--pass"}];
  auto nb_tests = ::tts::detail::suite.size();
  std::size_t done_tests = 0;
  try
  {
    for(auto &t: ::tts::detail::suite)
    {
      auto test_count     = ::tts::global_runtime.test_count;
      auto failure_count  = ::tts::global_runtime.failure_count;
      ::tts::global_runtime.fail_status = false;
      t();
      done_tests++;
      if(test_count     == ::tts::global_runtime.test_count)
      {
        ::tts::global_runtime.invalid();
        std::cout << "[!] - " << ::tts::detail::current_test << " : EMPTY TEST CASE\n";
      }
      else if(failure_count  == ::tts::global_runtime.failure_count)
      {
        std::cout << "[V] - " << ::tts::detail::current_test << "\n";
      }
    }
  }
  catch( ::tts::detail::fatal_signal& )
  {
    std::cout << "@@ ABORTING DUE TO EARLY FAILURE @@ - "
              << (nb_tests - done_tests - 1) << " Tests not run\n";
  }
  if constexpr( ::tts::detail::use_main )   return ::tts::report(0,0);
  else                                      return 0;
}
#endif
#ifndef TTS_FUNCTION
#define TTS_FUNCTION TTS_UNIQUE(tts_function)
#endif
#ifndef TTS_REGISTRATION
#define TTS_REGISTRATION TTS_UNIQUE(tts_registration)
#endif
#define TTS_UNIQUE3(ID, LINE) ID##LINE
#define TTS_UNIQUE2(ID, LINE) TTS_UNIQUE3(ID, LINE)
#define TTS_UNIQUE(ID)        TTS_UNIQUE2(ID, __COUNTER__)
#define TTS_CAT(x, y)                     TTS_CAT_I(x, y)
#define TTS_CAT_I(x, y)                   x##y
#define TTS_STRING(...)   TTS_STRING_((__VA_ARGS__))
#define TTS_STRING__(...) #__VA_ARGS__
#define TTS_STRING_(TXT)  TTS_STRING__ TXT
#define TTS_REMOVE_PARENS(x)              TTS_EVAL((TTS_REMOVE_PARENS_I x), x)
#define TTS_REMOVE_PARENS_I(...)          1, 1
#define TTS_APPLY(macro, args)            TTS_APPLY_I(macro, args)
#define TTS_APPLY_I(macro, args)          macro args
#define TTS_EVAL_I(test, x)               TTS_MAYBE_STRIP_PARENS(TTS_TEST_ARITY test, x)
#define TTS_EVAL(test, x)                 TTS_EVAL_I(test, x)
#define TTS_TEST_ARITY(...)               TTS_APPLY(TTS_TEST_ARITY_I, (__VA_ARGS__, 2, 1))
#define TTS_TEST_ARITY_I(a, b, c, ...)    c
#define TTS_MAYBE_STRIP_PARENS(cond, x)   TTS_MAYBE_STRIP_PARENS_I(cond, x)
#define TTS_MAYBE_STRIP_PARENS_I(cond, x) TTS_CAT(TTS_MAYBE_STRIP_PARENS_, cond)(x)
#define TTS_MAYBE_STRIP_PARENS_1(x)       x
#define TTS_MAYBE_STRIP_PARENS_2(x)       TTS_APPLY(TTS_MAYBE_STRIP_PARENS_2_I, x)
#define TTS_MAYBE_STRIP_PARENS_2_I(...)   __VA_ARGS__
#include <string_view>
#include <string>
namespace tts::detail
{
  template<typename T> struct typename_impl
  {
    static auto value() noexcept
    {
  #if defined(_MSC_VER )
      std::string_view data(__FUNCSIG__);
      auto i = data.find('<') + 1,
        j = data.find(">::value");
      auto name = data.substr(i, j - i);
  #else
      std::string_view data(__PRETTY_FUNCTION__);
      auto i = data.find('=') + 2,
        j = data.find_last_of(']');
      auto name = data.substr(i, j - i);
  #endif
      return std::string(name.data(), name.size());
    }
  };
}
namespace tts
{
  template<typename T> inline auto const typename_ = detail::typename_impl<T>::value();
  template<typename T> constexpr auto name(T const&){ return typename_<T>; }
}
namespace tts
{
  template<typename... Ts>
  struct types
  {
    template<typename... Us> constexpr types<Ts...,Us...> operator+( types<Us...> const&) const;
  };
  template<typename... Ls> struct concatenate { using type = decltype( (Ls{} + ...) ); };
  template<typename... Ls> using concatenate_t = typename concatenate<Ls...>::type;
  template<typename... T> struct type {};
  using real_types        = types < double,float>;
  using int_types         = types < std::int64_t , std::int32_t , std::int16_t , std::int8_t>;
  using signed_types      = concatenate_t<real_types,int_types>;
  using uint_types        = types < std::uint64_t , std::uint32_t , std::uint16_t , std::uint8_t>;
  using arithmetic_types  = concatenate_t<real_types,int_types,uint_types>;
}
namespace tts::detail
{
  struct test_capture
  {
    test_capture(const char* id) : name(id) {}
    auto operator+(auto body) const { return test::acknowledge( {name, body} ); }
    const char* name;
  };
  inline std::string current_type = {};
  template<typename... Types> struct test_captures
  {
    test_captures(const char* id) : name(id) {}
    auto operator+(auto body) const
    {
      return test::acknowledge( { name
                                , [=]()
                                  {
                                    ( ( (current_type = " with [T = " + typename_<Types> + "]")
                                      , body(type<Types>())
                                      )
                                    , ...
                                    );
                                    current_type.clear();
                                  }
                                }
                              );
    }
    std::string name;
  };
  template<typename... Types>
  struct test_captures<types<Types...>> : test_captures<Types...>
  {};
  template<typename Generator>
  requires requires(Generator g) { typename Generator::types_list; }
  struct test_captures<Generator> : test_captures<typename Generator::types_list>
  {};
}
#define TTS_CASE(ID)                                                                                \
static bool const TTS_CAT(case_,TTS_FUNCTION) = ::tts::detail::test_capture{ID} + []()              \

#define TTS_CASE_TPL(ID,...)                                                                        \
static bool const TTS_CAT(case_,TTS_FUNCTION) = ::tts::detail::test_captures<__VA_ARGS__>{ID} + []  \

#include <string_view>
#include <ostream>
namespace tts
{
  class source_location
  {
    public:
    [[nodiscard]] static constexpr auto current ( const char* file  = __builtin_FILE()
                                                , int line          = __builtin_LINE()
                                                ) noexcept
    {
      source_location sl{};
      sl.file_ = file;
      sl.line_ = line;
      return sl;
    }
    [[nodiscard]] constexpr auto filename() const noexcept
    {
      std::string_view f(file_);
      return f.substr(f.find_last_of('/')+1);
    }
    [[nodiscard]] constexpr auto line() const noexcept { return line_; }
    friend std::ostream& operator<<(std::ostream& os, source_location const& s)
    {
      return os << "[" << s.filename() << ":" << s.line() << "]";
    }
    private:
    const char* file_{"unknown"};
    int         line_{};
  };
}
#define TTS_FAIL(Message)                                                                           \
  [&]()                                                                                             \
  {                                                                                                 \
    ::tts::global_runtime.fail();                                                                   \
    if(!::tts::global_runtime.fail_status)                                                          \
    {                                                                                               \
      ::tts::global_runtime.fail_status = true;                                                     \
      std::cout << "[X] - " << ::tts::detail::current_test<< "\n";                                  \
    }                                                                                               \
    if( !::tts::detail::current_type.empty())                                                       \
    {                                                                                               \
      std::cout << "  > " << ::tts::detail::current_type << "\n";                                   \
    }                                                                                               \
    std::cout << "    " << ::tts::source_location::current() << " - ** FAILURE **"                  \
              << " : " << Message << std::endl;                                                     \
  }()
#define TTS_FATAL(Message)                                                                          \
  [&]()                                                                                             \
  {                                                                                                 \
    ::tts::global_runtime.fatal();                                                                  \
    if(!::tts::global_runtime.fail_status)                                                          \
    {                                                                                               \
      ::tts::global_runtime.fail_status = true;                                                     \
      std::cout << "[@] - " << ::tts::detail::current_test<< "\n";                                  \
    }                                                                                               \
    if( !::tts::detail::current_type.empty())                                                       \
    {                                                                                               \
      std::cout << "  > " << ::tts::detail::current_type << "\n";                                   \
    }                                                                                               \
    std::cout << "    " << ::tts::source_location::current() << " - @@ FATAL @@"                    \
              << " : " << Message << std::endl;                                                     \
    throw ::tts::detail::fatal_signal();                                                            \
  }()
#include <iostream>
namespace tts
{
  struct logger
  {
    logger(bool status = true) : display(status), done(false) {}
    template<typename Data> logger& operator<<(Data const& d)
    {
      if(display)
      {
        if(!done)
        {
          std::cout << ">> Additionnal information: \n";
          done = true;
        }
        std::cout << d;
      }
      return *this;
    }
    ~logger() { if(display && done) std::cout << "\n"; }
    bool display, done;
  };
}
#define TTS_EXPECT(EXPR, ...)     TTS_EXPECT_ ## __VA_ARGS__ ( EXPR )
#define TTS_EXPECT_(EXPR)         TTS_EXPECT_IMPL((EXPR),TTS_FAIL)
#define TTS_EXPECT_REQUIRED(EXPR) TTS_EXPECT_IMPL((EXPR),TTS_FATAL)
#define TTS_EXPECT_IMPL(EXPR,FAILURE)                                                               \
[&]()                                                                                               \
{                                                                                                   \
  if( TTS_REMOVE_PARENS(EXPR) )                                                                     \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE ( "Expression: "  << TTS_STRING(TTS_REMOVE_PARENS(EXPR)) << " evaluates to false." );   \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}()                                                                                                 \

#define TTS_EXPECT_NOT(EXPR, ...)       TTS_EXPECT_NOT_ ## __VA_ARGS__ ( EXPR )
#define TTS_EXPECT_NOT_(EXPR)           TTS_EXPECT_NOT_IMPL(EXPR,TTS_FAIL)
#define TTS_EXPECT_NOT_REQUIRED(EXPR)   TTS_EXPECT_NOT_IMPL(EXPR,TTS_FATAL)
#define TTS_EXPECT_NOT_IMPL(EXPR,FAILURE)                                                           \
[&]()                                                                                               \
{                                                                                                   \
  if( !(TTS_REMOVE_PARENS(EXPR)) )                                                                  \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE ( "Expression: "  << TTS_STRING(EXPR) << " evaluates to true." );                       \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}()                                                                                                 \

#define TTS_CONSTEXPR_EXPECT(EXPR)                                                                  \
[&]()                                                                                               \
{                                                                                                   \
  static_assert((EXPR), "[TTS] - Error: " TTS_STRING(EXPR) " evaluates to false at compile-time."); \
  ::tts::global_runtime.pass();                                                                     \
}()                                                                                                 \

#define TTS_CONSTEXPR_EXPECT_NOT(EXPR)                                                              \
[&]()                                                                                               \
{                                                                                                   \
  static_assert(!(EXPR), "[TTS] - Error: " TTS_STRING(EXPR) " evaluates to true at compile-time."); \
  ::tts::global_runtime.pass();                                                                     \
}()                                                                                                 \

namespace tts::detail
{
  template<typename L, typename R>
  concept comparable_equal  = requires(L l, R r) { compare_equal(l,r); };
  template<typename L, typename R>
  concept comparable_less   = requires(L l, R r) { compare_less(l,r); };
  template<typename L, typename R> inline constexpr bool eq(L const &l, R const &r)
  {
    if constexpr( comparable_equal<L,R> ) return compare_equal(l,r);
    else                                  return l == r;
  }
  template<typename L, typename R> inline constexpr bool neq(L const &l, R const &r)
  {
    return !eq(l,r);
  }
  template<typename L, typename R> inline constexpr bool lt(L const &l, R const &r)
  {
    if constexpr( comparable_less<L,R> )  return compare_less(l,r);
    else                                  return l < r;
  }
  template<typename L, typename R> inline constexpr bool le(L const &l, R const &r)
  {
    return lt(l, r) || eq(l, r);
  }
  template<typename L, typename R> inline constexpr bool gt(L const &l, R const &r)
  {
    return !le(l,r);
  }
  template<typename L, typename R> inline constexpr bool ge(L const &l, R const &r)
  {
    return !lt(l,r);
  }
}
#include <iomanip>
#include <sstream>
#include <type_traits>
namespace tts
{
  template<typename T>
  concept support_std_to_string = requires(T e) { std::to_string(e); };
  template<typename T>
  concept support_to_string = requires(T e) { to_string(e); };
  template<typename T>
  concept has_to_string = requires(T e) { e.to_string(); };
  template<typename T>
  concept sequence = requires(T e) {std::begin(e); std::end(e); };
  template<typename T>
  concept streamable = requires(T e, std::ostream& o) { o << e; };
  template<typename T> std::string as_string(T const& e)
  {
    if constexpr( std::is_pointer_v<T> )
    {
      std::ostringstream os;
      os << std::string(typename_<T>) << "(" << e << ")";
      return os.str();
    }
    else if constexpr( std::floating_point<T> )
    {
      auto precision = ::tts::arguments.value({"--precision"}, -1);
      bool hexmode   = ::tts::arguments[{"-x","--hex"}];
      bool scimode   = ::tts::arguments[{"-s","--scientific"}];
      std::ostringstream os;
      if(precision != -1 ) os << std::setprecision(precision);
            if(hexmode) os << std::hexfloat   << e << std::defaultfloat;
      else  if(scimode) os << std::scientific << e << std::defaultfloat;
      else              os << e;
      return os.str();
    }
    else if constexpr( support_std_to_string<T> )
    {
      return std::to_string(e);
    }
    else if constexpr( streamable<T> )
    {
      std::ostringstream os;
      os << e;
      return os.str();
    }
    else if constexpr( support_to_string<T> )
    {
      return to_string(e);
    }
    else if constexpr( sequence<T> )
    {
      std::string that = "{ ";
      for(auto const& v : e) that += as_string(v) + " ";
      that += "}";
      return that;
    }
    else
    {
      std::ostringstream os;
      os << "[" << std::string(typename_<T>) << "]@(" << &e << ")";
      return os.str();
    }
  }
  inline std::string as_string(bool b) { return b ? std::string("true") : std::string("false"); }
  inline std::string as_string(std::string const& e)      { return  e;                          }
  inline std::string as_string(std::string_view const& e) { return  std::string(e);             }
  inline std::string as_string(std::nullptr_t)            { return  std::string("nullptr");     }
  inline std::string as_string(const char* e)
  {
    std::ostringstream os;
    os << "char*(" << (void*)e << ")";
    return os.str();
  }
  inline std::string as_string(char* e )
  {
    std::ostringstream os;
    os << "char*(" << (void*)e << ")";
    return os.str();
  }
}
#define TTS_RELATION(A, B, OP, T, F, ...)    TTS_RELATION_ ## __VA_ARGS__ (A,B,OP,T,F)
#define TTS_RELATION_(A, B, OP, T, F)         TTS_RELATION_IMPL(A,B,OP,T,F,TTS_FAIL)
#define TTS_RELATION_REQUIRED(A, B, OP, T, F) TTS_RELATION_IMPL(A,B,OP,T,F,TTS_FATAL)
#define TTS_RELATION_IMPL(A, B, OP, T, F, FAILURE)                                                  \
[&](auto&& a, auto&& b)                                                                             \
{                                                                                                   \
  if( ::tts::detail::OP(a,b) )                                                                      \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE (   "Expression: "  << TTS_STRING(A) << " " T " " << TTS_STRING(B)                      \
            <<  " is false because: " << ::tts::as_string(a) << " " F " " << ::tts::as_string(b)    \
            );                                                                                      \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}(A,B)                                                                                              \

#define TTS_EQUAL(LHS, RHS, ...)          TTS_RELATION(LHS,RHS, eq , "==" , "!=" , __VA_ARGS__)
#define TTS_NOT_EQUAL(LHS, RHS, ...)      TTS_RELATION(LHS,RHS, neq, "!=" , "==" , __VA_ARGS__)
#define TTS_LESS(LHS, RHS, ...)           TTS_RELATION(LHS,RHS, lt , "<"  , ">=" , __VA_ARGS__)
#define TTS_GREATER(LHS, RHS, ...)        TTS_RELATION(LHS,RHS, gt , ">"  , "<=" , __VA_ARGS__)
#define TTS_LESS_EQUAL(LHS, RHS, ...)     TTS_RELATION(LHS,RHS, le , "<=" , ">"  , __VA_ARGS__)
#define TTS_GREATER_EQUAL(LHS, RHS, ...)  TTS_RELATION(LHS,RHS, ge , ">=" , "<=" , __VA_ARGS__)
#define TTS_CONSTEXPR_RELATION(A, B, OP, T, F)                                                      \
{                                                                                                   \
  static_assert ( std::bool_constant<::tts::detail::OP(A,B)>::value                                 \
                , "[TTS] - ** FAILURE** : " TTS_STRING(A) " " T " " TTS_STRING(B) " is false."      \
                );                                                                                  \
  ::tts::global_runtime.pass();                                                                     \
}                                                                                                   \

#define TTS_CONSTEXPR_EQUAL(LHS, RHS)          TTS_CONSTEXPR_RELATION(LHS,RHS, eq , "==" , "!=")
#define TTS_CONSTEXPR_NOT_EQUAL(LHS, RHS)      TTS_CONSTEXPR_RELATION(LHS,RHS, neq, "!=" , "==")
#define TTS_CONSTEXPR_LESS(LHS, RHS)           TTS_CONSTEXPR_RELATION(LHS,RHS, lt , "<"  , ">=")
#define TTS_CONSTEXPR_GREATER(LHS, RHS)        TTS_CONSTEXPR_RELATION(LHS,RHS, gt , ">"  , "<=")
#define TTS_CONSTEXPR_LESS_EQUAL(LHS, RHS)     TTS_CONSTEXPR_RELATION(LHS,RHS, le , "<=" , ">" )
#define TTS_CONSTEXPR_GREATER_EQUAL(LHS, RHS)  TTS_CONSTEXPR_RELATION(LHS,RHS, ge , ">=" , "<=")
#define TTS_TYPE_IS(TYPE, REF)                                                                      \
{                                                                                                   \
  static_assert ( std::is_same_v<TTS_REMOVE_PARENS(TYPE),TTS_REMOVE_PARENS(REF)>                    \
                , "[TTS] - ** FAILURE** : " TTS_STRING(TTS_REMOVE_PARENS(TYPE))                     \
                  " is not the same as " TTS_STRING(TTS_REMOVE_PARENS(REF)) "."                     \
                );                                                                                  \
  ::tts::global_runtime.pass();                                                                     \
}
#define TTS_EXPR_IS(EXPR, TYPE)                                                                     \
{                                                                                                   \
  static_assert ( std::is_same_v<decltype(TTS_REMOVE_PARENS(EXPR)),TTS_REMOVE_PARENS(TYPE)>         \
                , "[TTS] - ** FAILURE** : " TTS_STRING(TTS_REMOVE_PARENS(EXPR))                     \
                  " does not evaluates to an instance of " TTS_STRING(TTS_REMOVE_PARENS(TYPE)) "."  \
                );                                                                                  \
  ::tts::global_runtime.pass();                                                                     \
}
#define TTS_THROW_IMPL(EXPR, EXCEPTION, FAILURE)                                                    \
[&]()                                                                                               \
{                                                                                                   \
  bool tts_caught = false;                                                                          \
                                                                                                    \
  try                 { EXPR; }                                                                     \
  catch(EXCEPTION&  ) { tts_caught = true; }                                                        \
  catch(...)          { }                                                                           \
                                                                                                    \
  if(tts_caught)                                                                                    \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE ( "Expected: " << TTS_STRING(EXPR) << " failed to throw " << TTS_STRING(EXCEPTION) );   \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}()
#define TTS_THROW(EXPR, EXCEPTION, ...)     TTS_THROW_ ## __VA_ARGS__ ( EXPR, EXCEPTION )
#define TTS_THROW_(EXPR, EXCEPTION)         TTS_THROW_IMPL(EXPR, EXCEPTION,TTS_FAIL)
#define TTS_THROW_REQUIRED(EXPR, EXCEPTION) TTS_THROW_IMPL(EXPR, EXCEPTION,TTS_FATAL)
#define TTS_NO_THROW_IMPL(EXPR,FAILURE)                                                             \
[&]()                                                                                               \
{                                                                                                   \
  bool tts_caught = false;                                                                          \
                                                                                                    \
  try        { EXPR; }                                                                              \
  catch(...) { tts_caught = true; }                                                                 \
                                                                                                    \
  if(!tts_caught)                                                                                   \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE ( "Expected: "  << TTS_STRING(EXPR) << " throws unexpectedly." );                       \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}()
#define TTS_NO_THROW(EXPR, ...)     TTS_NO_THROW_ ## __VA_ARGS__ ( EXPR )
#define TTS_NO_THROW_(EXPR)         TTS_NO_THROW_IMPL(EXPR,TTS_FAIL)
#define TTS_NO_THROW_REQUIRED(EXPR) TTS_NO_THROW_IMPL(EXPR,TTS_FATAL)
#include <bit>
#include <cmath>
#include <cstdint>
#include <type_traits>
#include <utility>
namespace tts::detail
{
  inline auto as_int(float a)   noexcept  { return std::bit_cast<std::int32_t>(a); }
  inline auto as_int(double a)  noexcept  { return std::bit_cast<std::int64_t>(a); }
  template<typename T> inline auto bitinteger(T a) noexcept
  {
    auto ia = as_int(a);
    using r_t = std::remove_cvref_t<decltype(ia)>;
    constexpr auto Signmask = r_t(1) << (sizeof(r_t)*8-1);
    return std::signbit(a) ?  Signmask-ia : ia;
  }
}
#include <type_traits>
#include <limits>
#include <cmath>
namespace tts
{
  template<typename T, typename U> inline double absolute_distance(T const &a, U const &b)
  {
    if constexpr(std::is_same_v<T, U>)
    {
      if constexpr(std::is_same_v<T, bool>)
      {
        return a == b ? 0. : 1.;
      }
      else if constexpr(std::is_floating_point_v<T>)
      {
        if((a == b) || (std::isnan(a) && std::isnan(b))) return 0.;
        if(std::isinf(a) || std::isinf(b) || std::isnan(a) || std::isnan(b))
          return std::numeric_limits<double>::infinity();
        return std::abs(a - b);
      }
      else if constexpr(std::is_integral_v<T> && !std::is_same_v<T, bool>)
      {
        auto d0 = static_cast<double>(a), d1 = static_cast<double>(b);
        return absolute_distance(d0, d1);
      }
    }
    else
    {
      using common_t = std::common_type_t<T, U>;
      return absolute_distance(static_cast<common_t>(a), static_cast<common_t>(b));
    }
  }
  template<typename T, typename U> inline double relative_distance(T const &a, U const &b)
  {
    if constexpr(std::is_same_v<T, U>)
    {
      if constexpr(std::is_same_v<T, bool>)
      { return a == b ? 0. : 100.; }
      else if constexpr(std::is_floating_point_v<T>)
      {
        if((a == b) || (std::isnan(a) && std::isnan(b))) return 0.;
        if(std::isinf(a) || std::isinf(b) || std::isnan(a) || std::isnan(b))
          return std::numeric_limits<double>::infinity();
        return 100. * (std::abs(a - b) / std::max(T(1), std::max(std::abs(a), std::abs(b))));
      }
      else if constexpr(std::is_integral_v<T> && !std::is_same_v<T, bool>)
      {
        auto d0 = static_cast<double>(a), d1 = static_cast<double>(b);
        return relative_distance(d0, d1);
      }
    }
    else
    {
      using common_t = std::common_type_t<T, U>;
      return relative_distance(static_cast<common_t>(a), static_cast<common_t>(b));
    }
  }
  template<typename T, typename U> inline double ulp_distance(T const &a, U const &b)
  {
    if constexpr(std::is_same_v<T, U>)
    {
      if constexpr(std::is_same_v<T, bool>)
      {
        return a == b ? 0. : std::numeric_limits<double>::infinity();
      }
      else if constexpr(std::is_floating_point_v<T>)
      {
        using ui_t = std::conditional_t<std::is_same_v<T, float>, std::uint32_t, std::uint64_t>;
        if((a == b) || (std::isnan(a) && std::isnan(b)))
        {
          return 0.;
        }
        else if (std::isunordered(a, b))
        {
          return std::numeric_limits<double>::infinity();
        }
        else
        {
          auto aa = detail::bitinteger(a);
          auto bb = detail::bitinteger(b);
          if(aa > bb) std::swap(aa, bb);
          auto z = static_cast<ui_t>(bb-aa);
          if( std::signbit(a) ^ std::signbit(b) ) ++z;
          return z/2.;
        }
      }
      else if constexpr(std::is_integral_v<T> && !std::is_same_v<T, bool>)
      {
        using u_t = typename std::make_unsigned<T>::type;
        return ((a < b) ? u_t(b - a) : u_t(a - b))/2.;
      }
    }
    else
    {
      using common_t = std::common_type_t<T, U>;
      return ulp_distance(static_cast<common_t>(a), static_cast<common_t>(b));
    }
  }
}
#define TTS_PRECISION_IMPL(LHS, RHS, N, UNIT, FUNC, FAILURE)                                        \
[&]()                                                                                               \
{                                                                                                   \
  auto eval_a = (LHS);                                                                              \
  auto eval_b = (RHS);                                                                              \
  auto r      = FUNC (eval_a,eval_b);                                                               \
  auto& fmt_n = N<1000 ? std::defaultfloat : std::scientific;                                       \
  auto& fmt_r = r<1000 ? std::defaultfloat : std::scientific;                                       \
                                                                                                    \
  if(r <= N)                                                                                        \
  {                                                                                                 \
    ::tts::global_runtime.pass(); return ::tts::logger{false};                                      \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    FAILURE ( "Expected: " << TTS_STRING(LHS) << " == " << TTS_STRING(RHS)                          \
                            << " but "                                                              \
                            << ::tts::as_string(eval_a) << " == " << ::tts::as_string(eval_b)       \
                            << " within " << std::setprecision(2) << fmt_r                          \
                            << r << std::defaultfloat                                               \
                            << " " << UNIT << " when "                                              \
                            << std::setprecision(2) << fmt_n                                        \
                            << N << std::defaultfloat                                               \
                            << " " << UNIT << " was expected."                                      \
            );                                                                                      \
    return ::tts::logger{};                                                                         \
  }                                                                                                 \
}()
#define TTS_PRECISION(L,R,N,U,F, ...)     TTS_PRECISION_ ## __VA_ARGS__ (L,R,N,U,F)
#define TTS_PRECISION_(L,R,N,U,F)         TTS_PRECISION_IMPL(L,R,N,U,F,TTS_FAIL)
#define TTS_PRECISION_REQUIRED(L,R,N,U,F) TTS_PRECISION_IMPL(L,R,N,U,F,TTS_FATAL)
#define TTS_ABSOLUTE_EQUAL(L,R,N,...) TTS_PRECISION(L,R,N,"unit", ::tts::absolute_distance, __VA_ARGS__ )
#define TTS_RELATIVE_EQUAL(L,R,N,...) TTS_PRECISION(L,R,N,"%"   , ::tts::relative_distance, __VA_ARGS__ )
#define TTS_ULP_EQUAL(L,R,N,...)      TTS_PRECISION(L,R,N,"ULP" , ::tts::ulp_distance     , __VA_ARGS__ )
#define TTS_IEEE_EQUAL(L,R,...)       TTS_ULP_EQUAL(L, R, 0, __VA_ARGS__ )
