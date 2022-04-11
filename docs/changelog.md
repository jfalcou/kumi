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

**KUMI** (組) is now independant of the OFW repository.

