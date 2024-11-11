Change Log {#changelog}
==========

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
