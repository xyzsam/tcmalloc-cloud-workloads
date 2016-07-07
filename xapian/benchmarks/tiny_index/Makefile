.PHONY: all

XAPIAN_HOME = /home/samxi/xapian/install
UUID_HOME = $(XAPIAN_HOME)
TCMALLOC_HOME = /home/$(USER)/gperftools/install
LIBUNWIND_HOME = /home/skanev/libunwind/install

CXX = /group/vlsiarch/skanev/toolchain_6_1/bin/g++
CC = /group/vlsiarch/skanev/toolchain_6_1/bin/gcc
SRCS = build_database.cc run_queries.cc states.csv support.cc

CFLAGS = -O3 -g
CPPFLAGS = -I$(XAPIAN_HOME)/include -I$(UUID_HOME)/include
CXXFLAGS = -std=c++1y -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0
LDFLAGS = $(XAPIAN_HOME)/lib/libxapian.a \
					$(UUID_HOME)/lib/libuuid.a \
					$(TCMALLOC_HOME)/lib/libtcmalloc.a \
					$(LIBUNWIND_HOME)/lib/libunwind.a \
					-pthread -lrt -lz

all: build_database run_queries

build_database: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) build_database.cc support.cc -o $@ $(LDFLAGS)

run_queries: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) run_queries.cc -o $@ $(LDFLAGS)

clean:
	rm -rf *.o
	rm -rf build_database
	rm -rf run_queries
