#!/bin/bash
#
# Build libmagic for Omega.
# Since we're not going to be simulating omega itself, we don't need to link
# with tcmalloc.

INSTALL_DIR=/home/${USER}/xapian/install
if [ ! -d "$INSTALL_DIR" ];
then
  echo "$INSTALL_DIR does not exist!"
  exit 1
fi

CXXABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"
../configure --prefix=${INSTALL_DIR} \
             XAPIAN_CONFIG=../../xapian-core-1.4.0/build/xapian-config \
             CC=/group/vlsiarch/skanev/toolchain_6_1/bin/gcc \
             CXX=/group/vlsiarch/skanev/toolchain_6_1/bin/g++ \
             CXXFLAGS="-std=c++1y -O3 ${CXXABI_FLAGS}"
