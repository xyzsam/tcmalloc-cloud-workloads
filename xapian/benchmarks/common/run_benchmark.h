#ifndef _RUN_BENCHMARK_H_
#define _RUN_BENCHMARK_H_

#define NUM_ITERATIONS 5

void benchmark_setup(Xapian::Database &db, Xapian::Enquire &enquire,
                     Xapian::QueryParser &qparser);

#endif
