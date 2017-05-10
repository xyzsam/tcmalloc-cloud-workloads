#!/bin/bash
#
# Installs libuuid to the xapian install directory.


TOOLCHAIN_HOME=/usr

../configure --prefix=/home/${USER}/xapian/install \
             CC=${TOOLCHAIN_HOME}/bin/gcc
