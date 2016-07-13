include ../common/Makefile.common

SRCS = query_wiki_abstracts.cc
DB = wiki_abstracts
QUERIES = queries.txt

.PHONY: all
all: query_wiki_abstracts

$(DB):
ifeq ($(wildcard $(DB)),)
	@echo 'ERROR: Symlink to the wiki abstracts database is missing!'
	@exit 1
endif

query_wiki_abstracts: $(SRCS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

run_queries: $(DB) query_wiki_abstracts
	./query_wiki_abstracts $(DB) $(QUERIES)

clean:
	rm -rf *.o
	rm -rf query_wiki
