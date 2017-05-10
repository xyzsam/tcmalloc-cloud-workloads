Mallacc Cloud Workloads
=======================

These are a set of larger cloud-like workloads to measure the impact of malloc
speedup. We use Xapian, an open-source search engine, and Masstree, a multicore
key-value store. The versions provided here were used to produce all results in
the Mallacc paper; the latest versions can be found at
[xapian.org](https://xapian.org) and
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
toolchains are located in the default directories (e.g. `/usr/bin`). 

**NOTE**: Before running `do_configure.sh`, we also recommend you run
`autoreconf -i` from the top level directory of the source package to generate
the `configure` script for your system and autotools installation.

Then, execute the `do_configure.sh` script, then run `make` and `make install`
from within the build directory to build and install the package.

Other than the toolchain installation directories, do not remove any of the
other CFLAGS/CXXFLAGS specified, like flags about the ABI, sized deletes, etc.
These are important.

## Xapian ##

### Xapian core library and Omega ###

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
libraries are also provided under [deps](xapian/deps). You must first install
the Xapian core library and these dependencies before building Omega. Note that
we did not use Omega itself as a malloc benchmark, so there is no option to
link Omega with a special version of tcmalloc.

### Xapian client drivers ###

We provide three datasets for Xapian benchmarking, and each dataset has its own
client driver. These are located under [xapian/benchmarks](xapian/benchmarks).

* tiny_index: A sample program that runs queries over a very small search index.
* wiki_abstracts: Run queries over an index of Wikipedia page *abstracts*.
* wiki_pages: Run queries over an index of full Wikipedia page text.

To build them, just go to the appropriate folder and run `make`.

### Xapian search databases ###

The Wikipedia datasets were built from Wikipedia dumps, downloaded in July 2016
from [here](https://dumps.wikimedia.org). They were processed and indexed by Omega.
The Xapian databases are availble for download from here:

   * [abstracts](https://storage.googleapis.com/mallacc/wiki_abstracts.tar.xz)
   * [full-pages](https://storage.googleapis.com/mallacc/wiki_pages.tar.xz)

Download them and extract the files to a location.  To make building the search
index more tractable and reduce individual file sizes, we divided the full
wikipedia page index into eight shards. We use a ''stub database'' to
dynamically aggregate them together when we execute queries. The abstracts database
was small enough to not require sharding, but we use a stub database anyways
for consistency. Therefore, you will need to update the stub database file to
point to the place your databases are downloaded and extracted.

Go to the corresponding client driver (query_wiki_abstracts or
query_wiki_pages), open up the file called `stub_database.db`. Update the
paths to the appropriate search index. Each line should look like:

```
auto /path/to/database/default
```

## Masstree ##

Detailed instructions can be found in Masstree's [README](masstree-beta/README.md).
As was the case with Xapian, we provide a `do_configure.sh` script, which you
will need to edit to change toolchain paths.

In general, the steps are as follows:

```bash
cd masstree-beta
./bootstrap.sh
# Edit do_configure.sh.
./do_configure.sh
make
```

# Running the workloads

This section will only discuss running workloads natively, not in simulation.

## Xapian ##

Go to the directory for the dataset you want to run (e.g. wiki_pages). Each
dataset comes with at least one text file of queries to run. Select the one
you want and execute the following command:

```
./query_wiki_pages stub_database.db name_of_queries.txt

# For tiny_index only (no stub database):
./query_tiny_index tiny_index queries.txt
```

The client driver will run the complete set of queries 5 times by default (this
can be changed in common/run_benchmark.h). The driver will record how long
each iteration takes. When all iterations are finished, it will print the
recorded times to stdout, followed by the results of the queries. No printing
will occur until all queries are finished.

## Masstree ##

We ran two of the built-in Masstree performance tests, `wcol11` and `same`.

```bash
./mttest -j1 --no-notebook wcol1
./mttest -j1 --no-notebook -l 10000000 same
```
