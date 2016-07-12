include ../common/Makefile.common

SRCS = query_wiki.cc
DB = wiki_abstracts
QUERIES = queries.txt

.PHONY: all
all: query_wiki

$(DB):
ifeq ($(wildcard $(DB)),)
	@echo 'ERROR: Symlink to the wiki abstracts database is missing!'
	@exit 1
endif

query_wiki: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

run_queries: $(DB) query_wiki
	./query_wiki $(DB) $(QUERIES)

clean:
	rm -rf *.o
	rm -rf query_wiki
