#!/bin/bash
#
# Installs libuuid to the xapian install directory.

../configure --prefix=/home/${USER}/xapian/install \
             CC=/group/vlsiarch/skanev/toolchain_6_1/bin/gcc
