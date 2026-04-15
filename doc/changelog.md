Change Log {#changelog}
==========

# Version 4.0 - Flawless Fluorite

### New Features
* **Named Fields & Records**:
    * Introducing named fields and record support (#110, #112).
    * Introducing record protocol and record support in algorithms (#132, #144).
    * Support for types as identifiers and `get` via label (#168, #186).
* **New Algorithms**:
    * Introducing [`generate`](@ref kumi::generate) and [`fill`](@ref kumi::fill) (#107).
    * Introducing [`windows`](@ref kumi::windows) and [`chunks`](@ref kumi::chunks) (#123).
    * Introducing [`filter`](@ref kumi::filter)   and [`filter_not`](@ref kumi::filter_not) (#124).
    * Introducing [`reindex`](@ref kumi::reindex) algorithm (#130).
    * Introducing [`unique`](@ref kumi::unique) and [`all_unique`](@ref kumi::all_unique) algorithms (#139).
    * Introducing [`reduce`](@ref kumi::reduce) and [inclusive and exclusive scans](@ref kumi::inclusive_scan_left) (#137).
    * Introducing [rotate algorithms](@ref kumi::rotate_left)  (#154).
    * Add projection maps support (#182).
    * Implement `map_traits` (#104).
* **Core Logic & Performance**:
    * Introducing `builder` for tuple construction (#111).
    * Introducing [`empty_product_type`](@ref kumi::concepts::empty_product_type) concept (#143).
    * Make `std::array` and static `std::span` behave as product types (#140).
    * Introduce `as_streamable` extension point (#145).
    * Implicit conversion operator on tuples (#152).
    * Removed `.cast()` and callable behavior (#135).
    * Introduce static container adaptation (#158).
    * Move from opt-in to detection for product type semantic (#160).
    * Empty Base Optimization (EBO) support (#163, #167).

### FIXES
* **Compiler & Compatibility**:
    * Reimplement `cartesian_product` for latest MSVC compatibility (#97).
    * Fix shadow warnings (#108).
    * Fix qualification consideration in concepts (#136).
    * Missing `typename` for C++20 (#128).
    * Fix for TTS v3 (#129).
    * Remove spurious semicolons triggering errors on older GCC versions (#188).
* **Logic & Bug Fixes**:
    * Make `std::is_empty` work as expected on tuples and records (#138).
    * Fix IO of field capture of empty type (#165).
    * Improve diagnostic of invalid `get` (#150).
    * Use `static_assert` instead of `requires` for logic errors (#184).
    * Clarify error messages for invalid records (#166).
* **Refinement**:
    * Make `operator<` better (#98).
    * Add `KUMI_ABI` markers to enhance codegen and CUDA `__host__` `__device__` support (#119, #121).
    * Make tuple algorithms accept forwarding references (#127).
    * Move towards `invoke` instead of raw callable application (#161).
    * Simplification of `field_capture` unwrapping (#141).
    * Move concepts to their own namespace (#170).
    * Test missing record algorithms + doc (#178).

### DOC and CI infra
* **Documentation**:
    * Fixup `FetchContent` docs (#91).
    * Rearrange tree links in documentation (#117).
    * Refurbish documentation and fix rendering/links (#185, #197).
    * Fix README code block and badge appearance (#187, #194).

* **CI & Infrastructure**:
    * Move KUMI standalone file to its own branch (#114, #120).
    * Add explicit standalone tests and proper standalone file (#116, #176,#174).
    * Move to CI v10 and update to latest CI infra (#105, #196).
    * Migration to `precommit` (#157).


# Version 3.1 - Exquisite Epidote

## What's Changed

### Infrastructure Changes
  - Migrate CMake infrastructure to [copacabana](https://github.com/jfalcou/copacabana)
  - Integration tests are now run on merge to main.
  - Improved warnings setup in Unit Tests
  - CI now tests for:
    - Android
    - ICPX
    - Mac OS X 14
    - Visual Studio cl.exe
    - Visual Studio clang-cl.exe
    - WASM
  - Documentation is now automatically built on merge to stop polluting PRs.
  - People can use https://jfalcou.github.io/kumi/kumi.tag as a Doxygen Tag File in their own documentation.

### New Features
  - Optimize certain data layout and type computation to reduce symbol length.
  - Add KUMI_TRIVIAL macro to ensure inlining of key functionalities.
  - Add support for homogeneous tuple detection.
  - Implement copy-efficient partition.
  - Implement apply_traits that computes the result of a traits being applied to all elements of a product type.
  - Add support for `std::invoke`-like calls in `apply`, contributed  by **jehelset**.
  - Add `std::array` as a product type, contributed  by **jehelset**.
  - Allow for automatic std adaptation to be disengaged via macro.

### Bug Fixes
  - Fix #55 - Shortcut to pure fold expression whenever possible in reduction.
  - Fix #64 - Adapt kumi::tuple to std::common_reference.
  - Fix #69 - Better apply and for_each SFINAE compliance.
  - Fix #70 - Sign issue with iota.
  - Fix #71 - Support for eductions without init values.
  - Fix #77 - Adjust type computation of cat, contributed by **jehelset**.
  - Fix as_tuple to work with non-product type value type.
  - Fix predicates to work with non-product type.
  - Fix sign issue with count.
  - Fix SFINAE compliance of comparisons operator when used on tuples with non-comparables elements.
  - Fix the definition of the non-empty product type concept.
  - Fix unqualified make_tuple calls that ADL clashed with std::make_tuple.
  - Remove useless != and fix size related checks on comparisons operators.

**Full Changelog**: https://github.com/jfalcou/kumi/compare/v3.0...v3.1

# Version 3.0 - Delicious Datolite

This Release is an API break release.

## What's Changed

### API and Infrastructure Changes
 - kumi::extract and kumi::split are now free functions (See #40)
 - KUMI implementation is now done in split file that get aggregated (See #34)
 - Massive documentation revamping (See #27, #28)
 - Added proper integration tests (See #35)

### New Features
 - Implemented kumi::iota and generate (See #23)
 - Implemented kumi::cartesian_product (See #26)
 - Implemented predicate based operations on tuple (See #25)
 - Implemented kumi::inner_product  (See #36)
 - Implemented kumi::back and kumi::front (See #37)
 - Implemented kumi::reverse (See #39)

### Bug Fixes
 - Fix #18 - Bad interaction with tuple of references (See #19)
 - Improve kumi::flatten implementation (See #20)

## New Contributors
 - **jehelset** made their first contribution in https://github.com/jfalcou/kumi/pull/28

**Full Changelog**: https://github.com/jfalcou/kumi/compare/v2.1...v3.0

# Version 2.1 - Charming Chrysoprase

## What's Changed

### Bug Fixes
 - Improve `kumi::cat` implementation to perform `O(N)` copies.
 - Use include guards to prevent issue when different project use KUMI concurrently.

### New Features
 - Added the `kumi::sized_product_type_or_more` concept
 - Implements `kumi::to_ref` to construct a tuple of references form a reference to a tuple.

**Full Changelog**: https://github.com/jfalcou/kumi/compare/v2.0...v2.1

# Version 2.0 - Bedazzling Beryl

## What's Changed

### Infrastructure
* #6 - Moved kumi.hpp to tuple/kumi.hpp

This is a slightly API breaking change but as the library gains traction, I hanged the file to a
less surprising name.

### Bug Fixes
* #12 - Make == and != SFINAE friendly

### New Features
* #4 - Add map_index
* #5 - Implements pop/push-front/back
* Implement as_flat_ptr to work with tuple as a list of member's pointers
* #7 - `kumi::tuple` supports min and max

**Full Changelog**: https://github.com/jfalcou/kumi/compare/v1.0...v2.0

# Version 1.0 - Amazing Amethyst

## First autonomous public release.

**KUMI** (組) is now independent of the OFW repository.
