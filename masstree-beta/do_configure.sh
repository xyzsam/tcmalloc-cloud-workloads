#!/bin/bash

LIBTCMALLOC_HOME=/home/${USER}/gperftools/install
LIBUNWIND_HOME=/home/skanev/libunwind/install
LIBSTDCPP_HOME=/group/vlsiarch/skanev/toolchain_6_1/
MAGIC_LINKER_SCRIPT="-T /home/${USER}/gperftools/install_all_magic/spec_linker.ld"
ABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"

./configure CC=/group/vlsiarch/skanev/toolchain_6_1/bin/gcc \
            CXX=/group/vlsiarch/skanev/toolchain_6_1/bin/g++ \
            CXXFLAGS="-g -W -Wall -O3 -fsized-deallocation ${ABI_FLAGS}" \
            LDFLAGS="-static"\
            LIBS="${MAGIC_LINKER_SCRIPT} ${LIBTCMALLOC_HOME}/lib/libtcmalloc.a ${LIBUNWIND_HOME}/lib/libunwind.a ${LIBSTDCPP_HOME}/lib64/libstdc++.a"
