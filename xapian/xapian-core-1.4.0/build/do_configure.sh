#!/bin/bash
#
# Build static xapian-core library linked with tcmalloc.  Can optionally
# specify a build of tcmalloc with magic instructions.

TCMALLOC_BUILD=${1:-baseline}

USAGE="Usage: $0 [baseline (default) | all_magic]"

INSTALL_SUFFIX=""
if [ "${TCMALLOC_BUILD}" == "baseline" ]
then
  INSTALL_SUFFIX=""
elif [ "${TCMALLOC_BUILD}" == "all_magic" ]
then
  INSTALL_SUFFIX="_all_magic"
else
  echo $USAGE
fi

LIBTCMALLOC_DIR=/home/${USER}/gperftools/install${INSTALL_SUFFIX}
CXXABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"
TCMALLOC_SAFETY_FLAGS="-fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free"
SIZED_DELETE_FLAGS="-fsized-deallocation"
MAGIC_LINKER_SCRIPT="-T ${LIBTCMALLOC_DIR}/spec_linker.ld"

INSTALL_DIR=/home/${USER}/xapian/install

TOOLCHAIN_HOME=/usr/bin
LIBUNWIND_HOME=/usr/local

../configure --prefix=${INSTALL_DIR} \
             --enable-static \
             --disable-shared \
             CC=${TOOLCHAIN_HOME}/gcc \
             CXX=${TOOLCHAIN_HOME}/g++ \
             CFLAGS="-I${LIBUNWIND_HOME}/include -g -O3 ${TCMALLOC_SAFETY_FLAGS} ${SIZED_DELETE_FLAGS}" \
             CPPFLAGS="-I${LIBUNWIND_HOME}/include -I${INSTALL_DIR}/include" \
             CXXFLAGS="-I${LIBUNWIND_HOME}/include -g -std=c++1y -O3 ${CXXABI_FLAGS} ${TCMALLOC_SAFETY_FLAGS} ${SIZED_DELETE_FLAGS} " \
             LDFLAGS="-L${LIBUNWIND_HOME}/lib -O3" \
             LIBS="${MAGIC_LINKER_SCRIPT} ${INSTALL_DIR}/lib/libuuid.a ${LIBTCMALLOC_DIR}/lib/libtcmalloc.a ${LIBUNWIND_HOME}/lib/libunwind.a -pthread -lrt"
