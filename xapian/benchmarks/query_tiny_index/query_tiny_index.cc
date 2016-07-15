#include "xapian.h"
#include "run_benchmark.h"

void benchmark_setup(Xapian::Database &db, Xapian::Enquire &enquire,
                     Xapian::QueryParser &qparser) {
    qparser.add_prefix("name", "S");
    qparser.add_prefix("capital", "XC");
    qparser.add_prefix("admitted date", "XAD");
    qparser.add_prefix("population", "XP");
    qparser.add_prefix("latitude", "XLA");
    qparser.add_prefix("longitude", "XLO");
}
