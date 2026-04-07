##======================================================================================================================
##  TTS - Tiny Test System
##  Copyright : TTS Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
#!/bin/bash

export CUDA_HOME=/opt/cuda

# Get last available sdk version
HPC_BASE=$(ls -d /opt/nvidia/hpc_sdk/Linux_x86_64/*/compilers 2>/dev/null | tail -n 1)

if [ -z "$HPC_BASE" ]; then
    echo "Error: NVIDIA HPC SDK not found in /opt/nvidia/hpc_sdk/Linux_x86_64/"
else
    export HPC_SDK="$HPC_BASE"

    # Prepend to environment
    export PATH=$HPC_SDK/bin:$PATH
    export LD_LIBRARY_PATH=$HPC_SDK/lib:$LD_LIBRARY_PATH
    export CPATH=$CUDA_HOME/targets/x86_64-linux/include:$CUDA_HOME/targets/x86_64-linux/include/cccl:$CPATH
fi
