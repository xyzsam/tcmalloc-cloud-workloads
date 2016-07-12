// Run some simple queries on the 50 states index.

#include <xapian.h>

#include <fstream>
#include <iostream>
#include <string>

#include <stdlib.h> // For exit().

extern "C" void xiosim_roi_begin() __attribute__ ((noinline));
extern "C" void xiosim_roi_end() __attribute__ ((noinline));

void xiosim_roi_begin() { __asm__ __volatile__ ("":::"memory"); }
void xiosim_roi_end() { __asm__ __volatile__ ("":::"memory"); }

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
      cout << "Usage: ./run_queries path/to/db path/to/queries.txt" << endl;
      return -1;
    }
    std::string db_path = argv[1];
    std::string queries = argv[2];

    ifstream f(queries);
    if (!f.good()) {
        cerr << "An error occurred opening the queries file " << queries << endl;
        return -1;
    }

    // Open the database for searching.
    Xapian::Database db(db_path);
    // Start an enquire session.
    Xapian::Enquire enquire(db);
    Xapian::QueryParser qp;
    qp.set_database(db);
    qp.set_default_op(Xapian::Query::OP_OR);
    qp.add_prefix("name", "S");
    qp.add_prefix("capital", "XC");
    qp.add_prefix("admitted date", "XAD");
    qp.add_prefix("population", "XP");
    qp.add_prefix("latitude", "XLA");
    qp.add_prefix("longitude", "XLO");
    qp.add_prefix("motto", "XM");
    Xapian::Query query;
    Xapian::MSet matches;

    string query_string;
    xiosim_roi_begin();
    while (!f.eof()) {
        getline(f, query_string);
        if (query_string.length() == 0)
            continue;
        query = qp.parse_query(query_string);

        // Parse the query string to produce a Xapian::Query object.
        Xapian::Stem stemmer("english");
        qp.set_stemmer(stemmer);
        qp.set_stemming_strategy(Xapian::QueryParser::STEM_SOME);
        cout << "Parsed query is: " << query.get_description() << endl;

        // Find the top 10 results for the query.
        enquire.set_query(query);
        matches = enquire.get_mset(0, 10);

        // Display the results.
        cout << "Results for query \"" << query_string << "\":\n";
        int position = 1;
        for (Xapian::MSetIterator i = matches.begin(); i != matches.end(); ++i) {
            cout << position << ": " <<  i.get_document().get_data() << "\n";
            position++;
        }
        cout << endl;
    }
    xiosim_roi_end();
    f.close();
    return 0;
}
