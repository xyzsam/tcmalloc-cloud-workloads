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

../configure --prefix=${INSTALL_DIR} \
             --enable-static \
             --disable-shared \
             CC=/group/vlsiarch/skanev/toolchain_6_1/bin/gcc \
             CXX=/group/vlsiarch/skanev/toolchain_6_1/bin/g++ \
             CFLAGS="-I/home/libunwind/install/include -g -O3 ${TCMALLOC_SAFETY_FLAGS} ${SIZED_DELETE_FLAGS}" \
             CPPFLAGS="-I/home/skanev/libunwind/install/include -I${INSTALL_DIR}/include" \
             CXXFLAGS="-I/home/libunwind/install/include -g -std=c++1y -O3 ${CXXABI_FLAGS} ${TCMALLOC_SAFETY_FLAGS} ${SIZED_DELETE_FLAGS} " \
             LDFLAGS="-L/home/libunwind/install/lib -O3" \
             LIBS="${MAGIC_LINKER_SCRIPT} ${INSTALL_DIR}/lib/libuuid.a ${LIBTCMALLOC_DIR}/lib/libtcmalloc.a /home/skanev/libunwind/install/lib/libunwind.a -pthread -lrt"
