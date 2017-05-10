#!/bin/bash
#
# Build Omega for the purpose of building a realistic web index.

INSTALL_DIR=/home/${USER}/xapian/install
if [ ! -d "$INSTALL_DIR" ];
then
  echo "Installation directory $INSTALL_DIR does not exist!"
  exit 1
fi

TOOLCHAIN_HOME=/usr/bin

CXXABI_FLAGS="-fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0"
../configure --prefix=${INSTALL_DIR} \
             XAPIAN_CONFIG=${INSTALL_DIR}/bin/xapian-config \
             CC=${TOOLCHAIN_HOME}/gcc \
             CXX=${TOOLCHAIN_HOME}/g++ \
             CXXFLAGS="-I${INSTALL_DIR}/include -std=c++1y -O3 ${CXXABI_FLAGS}" \
             CPPFLAGS=-I$INSTALL_DIR/include \
             LDFLAGS=-L${INSTALL_DIR}/lib \
             LIBS=-luuid \
             PCRE_CONFIG=${INSTALL_DIR}/bin/pcre-config
