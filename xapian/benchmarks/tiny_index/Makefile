include ../common/Makefile.common
.PHONY: all

DB = statesindex
QUERIES = queries.txt

SRCS = build_database.cc query_tiny_index.cc states.csv support.cc

all: build_database query_tiny_index

build_database: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $@.cc support.cc -o $@ $(LDFLAGS)

query_tiny_index: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $@.cc -o $@ $(LDFLAGS)

run_queries: query_tiny_index
	./query_tiny_index $(DB) $(QUERIES)

clean:
	rm -rf *.o
	rm -rf build_database
	rm -rf query_tiny_index
