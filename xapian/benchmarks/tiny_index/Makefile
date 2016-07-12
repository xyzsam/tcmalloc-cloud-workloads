.PHONY: all

XAPIAN_HOME = /home/samxi/xapian/install
UUID_HOME = $(XAPIAN_HOME)
TCMALLOC_HOME = /home/$(USER)/gperftools/install
LIBUNWIND_HOME = /home/skanev/libunwind/install

INDEX_NAME = statesindex
QUERIES = queries.txt

CXX = /group/vlsiarch/skanev/toolchain_6_1/bin/g++
CC = /group/vlsiarch/skanev/toolchain_6_1/bin/gcc
SRCS = build_database.cc query_tiny_index.cc states.csv support.cc

CFLAGS = -O3 -g
CPPFLAGS = -I$(XAPIAN_HOME)/include -I$(UUID_HOME)/include
CXXFLAGS = -std=c++1y -fabi-version=2 -D_GLIBCXX_USE_CXX11_ABI=0
LDFLAGS = $(XAPIAN_HOME)/lib/libxapian.a \
					$(UUID_HOME)/lib/libuuid.a \
					$(TCMALLOC_HOME)/lib/libtcmalloc.a \
					$(LIBUNWIND_HOME)/lib/libunwind.a \
					-pthread -lrt -lz

all: build_database query_tiny_index

build_database: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) build_database.cc support.cc -o $@ $(LDFLAGS)

query_tiny_index: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) query_tiny_index.cc -o $@ $(LDFLAGS)

run_queries: query_tiny_index
	./query_tiny_index $(INDEX_NAME) $(QUERIES)

clean:
	rm -rf *.o
	rm -rf build_database
	rm -rf query_tiny_index
