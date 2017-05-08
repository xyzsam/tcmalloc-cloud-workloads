Mallacc Cloud Workloads
=======================

These are a set of larger cloud-like workloads to measure the impact of malloc
speedup. We use Xapian, an open-source search engine, and Masstree, a multicore
key-value store. The versions provided here were used to produce all results in
the Mallacc paper; the latest versions can be found at
[Xapian.org](https://xapian.org) and
[https://github.com/kohler/masstree-beta](https://github.com/kohler/masstree-beta).

For information about the paper, please refer to:

Svilen Kanev, Sam (Likun) Xi, Gu-Yeon Wei, and David Brooks.  
Mallacc: Accelerator Memory Allocation.  
Architectural Support for Operating Systems and Programming Languages, April 2017.
[PDF](http://www.samxi.org/papers/kanev_asplos2017.pdf)

# Installation #

Our system has toolchains installed in non-standard locations, so our build flow
relies on writing `do_configure.sh` scripts that execute `configure` with hard-coded
toolchain locations and other default options. All installable packages come
with such a script. You will need to edit each script to change the toolchain
locations to match your target system, or simply remove all those options if your
toolchains are located in the default directories (e.g. `/usr/bin`). Execute the
`do_configure.sh` script, then run `make` and `make install` from within the build
directory to build and install the package.

Other than the toolchain installation directories, do not remove any of the
other CFLAGS/CXXFLAGS specified, like flags about the ABI, sized deletes, etc.
- these are important.

## Xapian ##

Detailed instructions can be found in Xapian's
[INSTALL](xapian/xapian-core-1.4.0/INSTALL). Here are some general instructions.

We install Xapian (and all its additional dependencies) to
`/home/user/xapian/install`. You can change this to suit your needs, but
remember that the entire Mallacc build flows assumes this installation
directory, so other `do_configure.sh` scripts will need to be changed.

Xapian's primary dependencies are zlib and libuuid. We used libuuid version
1.0.3, provided [here](xapian/deps/libuuid-1.0.3). Use the `do_configure.sh`
script to install libuuid.

When building Xapian's core, you need to select whether to link it against a
version of libtcmalloc with or without the Mallacc special instructions, which
determines which directory the configure script will look for the tcmalloc
installation.  See
[do_configure.sh](xapian/xapian-core-1.4.0/build/do_configure.sh).

If you need to build Omega, you'll also need libmagic and libpcre. These
libraries are also provided under deps. You must first install the Xapian core
library and these dependencies before building Omega. Note that we did not use
Omega itself as a malloc benchmark, so there is no option to link Omega with a
special version of tcmalloc.

## Masstree ##

