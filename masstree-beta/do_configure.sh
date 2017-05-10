#!/bin/bash

TOOLCHAIN_HOME=/usr
LIBUNWIND_HOME=/usr/local
LIBSTDCPP_HOME=/usr/lib/gcc/x86_64-linux-gnu/6

LIBTCMALLOC_HOME=/home/${USER}/gperftools/install
MAGIC_LINKER_SCRIPT="-T /home/${USER}/gperftools/install/spec_linker.ld"
ABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"

./configure CC=${TOOLCHAIN_HOME}/bin/gcc \
            CXX=${TOOLCHAIN_HOME}/bin/g++ \
            CXXFLAGS="-g -W -Wall -O3 -std=c++14 -fsized-deallocation ${ABI_FLAGS}" \
            LDFLAGS="-static"\
            LIBS="${MAGIC_LINKER_SCRIPT} ${LIBTCMALLOC_HOME}/lib/libtcmalloc.a ${LIBUNWIND_HOME}/lib/libunwind.a ${LIBSTDCPP_HOME}/libstdc++.a"
