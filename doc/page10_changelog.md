Change Log {#changelog}
==========

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
