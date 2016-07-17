// Benchmark runner for Xapian.

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/time.h>
#include <xapian.h>

#include "run_benchmark.h"

extern "C" void xiosim_roi_begin() __attribute__ ((noinline));
extern "C" void xiosim_roi_end() __attribute__ ((noinline));

void xiosim_roi_begin() { __asm__ __volatile__ ("":::"memory"); }
void xiosim_roi_end() { __asm__ __volatile__ ("":::"memory"); }

typedef std::vector<Xapian::Query> query_list_t;

void read_query_file(std::ifstream &query_file, Xapian::QueryParser &qparser,
                     query_list_t &queries) {
    while (!query_file.eof()) {
        Xapian::Query query;
        std::string query_string;
        getline(query_file, query_string);
        if (query_string.length() == 0)
            continue;
        query = qparser.parse_query(query_string);
        queries.push_back(query);
    }
}

// Runs the set of queries and returns the elapsed time in milliseconds.
double run_queries(Xapian::Enquire &enquire, Xapian::QueryParser &qparser,
                   query_list_t &queries, std::vector<std::string> &results,
                   unsigned num_results) {
    struct timeval tv_before, tv_after;
    double elapsed_time;
    int rv;

    rv = gettimeofday(&tv_before, NULL);
    if (rv) {
        perror("gettimeofday");
        abort();
    }

    // Perform the searches.
    for (Xapian::Query& query : queries) {
        enquire.set_query(query);
        Xapian::MSet matches = enquire.get_mset(0, num_results);
        for (Xapian::MSetIterator i = matches.begin(); i != matches.end(); ++i) {
            results.push_back(i.get_document().get_data());
        }
    }

    rv = gettimeofday(&tv_after, NULL);
    if (rv) {
        perror("gettimeofday");
        abort();
    }

    elapsed_time = (tv_after.tv_sec - tv_before.tv_sec) * 1E6 +
                   (tv_after.tv_usec - tv_before.tv_usec);
    elapsed_time /= 1E3;
    return elapsed_time;
}

void run_benchmark(Xapian::Enquire &enquire, Xapian::QueryParser &qparser,
                   query_list_t& queries) {
    std::vector<std::string> results;
    double time;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        if (i == 1)
            xiosim_roi_begin();
        time = run_queries(enquire, qparser, queries, results, 10);
        std::cout << "Total elapsed time: " << time << " ms" << std::endl;
    }

    xiosim_roi_end();

    // Do something with the results.
    for (auto& result : results) {
        std::cout << result << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./run_queries path/to/db path/to/queries.txt" << std::endl;
      return -1;
    }
    std::string db_path = argv[1];
    std::string query_fpath = argv[2];

    std::ifstream query_file(query_fpath);
    if (!query_file.good()) {
        std::cerr << "An error occurred opening the queries file " << query_fpath
                  << std::endl;
        return -1;
    }

    Xapian::Database db(db_path);
    Xapian::Enquire enquire(db);
    Xapian::QueryParser qp;
    Xapian::Stem stemmer("english");

    // Read the queries just once.
    query_list_t queries;
    read_query_file(query_file, qp, queries);

    qp.set_database(db);
    qp.set_stemmer(stemmer);
    qp.set_stemming_strategy(Xapian::QueryParser::STEM_SOME);
    qp.set_default_op(Xapian::Query::OP_OR);

    // Let the benchmark do additional setup (e.g. add prefixes).
    benchmark_setup(db, enquire, qp);

    // Run the benchmark.
    run_benchmark(enquire, qp, queries);

    return 0;
}
