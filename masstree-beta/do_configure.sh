#!/bin/bash


ABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"
./configure CC=/group/vlsiarch/skanev/toolchain_6_1/bin/gcc \
            CXX=/group/vlsiarch/skanev/toolchain_6_1/bin/g++ \
            CXXFLAGS="-g -W -Wall -O3 -fsized-deallocation ${ABI_FLAGS}" \
            LDFLAGS="-static"\
            LIBS="-T /home/$(USER)/gperftools/install_all_magic/spec_linker.ld /home/$(USER)/gperftools/install_all_magic/lib/libtcmalloc.a /home/skanev/libunwind/install/lib/libunwind.a /group/vlsiarch/skanev/toolchain_6_1/lib64/libstdc++.a"
