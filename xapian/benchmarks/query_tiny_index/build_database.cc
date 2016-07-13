// Build an index for a small dataset of the 50 states.

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "xapian.h"
#include "support.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
      cout << "Usage: ./run_queries path/to/db/to/create path/to/dataset/to/index" << endl;
      return -1;
    }
    std::string db_path = argv[1];
    std::string dataset = argv[2];

    ifstream f(dataset);
    if (!f.good()) {
        cerr << "An error occurred opening the dataset file " << dataset << endl;
        return -1;
    }

    Xapian::WritableDatabase db(db_path, Xapian::DB_CREATE_OR_OPEN);
    Xapian::Stem stemmer("en");
    db.begin_transaction(0);

    string line;
    while (!f.eof()) {
        getline(f, line);
        if (line.length() == 0)
            continue;
        // Split the line.
        vector<string> elems;
        csv_parse_line(f, elems);
        if (elems.size() == 0)
            continue;

        Xapian::Document doc;
        Xapian::TermGenerator indexer;
        indexer.set_stemmer(stemmer);
        indexer.set_document(doc);

        // Index with prefixes.
        indexer.index_text(elems[0], 1, "S");  // state name
        indexer.index_text(elems[1], 1, "XC"); // capital
        indexer.index_text(elems[2], 1, "XAD"); // admitted date
        indexer.index_text(elems[3], 1, "XP"); // population
        indexer.index_text(elems[4], 1, "XLA"); // latitude
        indexer.index_text(elems[5], 1, "XLO"); // longitude
        indexer.index_text(elems[6], 1, "XM"); // motto

        // Index without prefixes.
        indexer.index_text(elems[0]);  // state name
        indexer.increase_termpos();
        indexer.index_text(elems[1]); // capital
        indexer.increase_termpos();
        indexer.index_text(elems[2]);  // admitted date
        indexer.increase_termpos();
        indexer.index_text(elems[3]);  // population
        indexer.increase_termpos();
        indexer.index_text(elems[4]);  // latitude
        indexer.increase_termpos();
        indexer.index_text(elems[5]);  // longitude
        indexer.increase_termpos();
        indexer.index_text(elems[6]);  // motto
        indexer.increase_termpos();
        indexer.index_text(elems[7]);  // description
        indexer.increase_termpos();

        doc.set_data(elems[7]);
        db.add_document(doc);
    }

    db.commit_transaction();

    f.close();
    return 0;
}
