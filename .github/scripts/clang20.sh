##======================================================================================================================
##  KUMI - Compact C++20 Tuple Toolbox
##  Copyright : KUMI Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
#!/bin/sh

ln -sf "$(which clang++-20)" /tmp/clang++
export PATH="/tmp:$PATH"
