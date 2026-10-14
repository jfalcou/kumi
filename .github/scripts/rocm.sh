##======================================================================================================================
##  TTS - Tiny Test System
##  Copyright : TTS Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
#!/bin/bash

# Get the latest ROCm installation
ROCM=$(ls -d /opt/rocm* 2>/dev/null | tail -n 1)

if [ -z "$ROCM" ]; then
    echo "Error: ROCm not found in /opt/rocm/"
else
    export ROCM_PATH="$ROCM"

    # Prepend to environment (hipcc, ROCm clang, hipconfig, ...)
    export PATH="$ROCM/bin:$ROCM/llvm/bin:$PATH"
    export LD_LIBRARY_PATH="$ROCM/lib:$LD_LIBRARY_PATH"
fi
