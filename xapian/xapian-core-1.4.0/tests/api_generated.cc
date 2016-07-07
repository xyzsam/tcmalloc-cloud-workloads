/** @file api_generated.cc
 * @brief test common features of API classes
 */
/* Warning: This file is generated by /data/home/olly/tmp/xapian-git-snapshot/tags/v1.4.0/xapian/xapian-core/tests/generate-api_generated - do not modify directly! */
/* Copyright (C) 2007,2009,2012,2014,2015,2016 Olly Betts
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include <config.h>

#include "api_generated.h"

#define XAPIAN_DEPRECATED(D) D
#include <xapian.h>

#include "apitest.h"
#include "testutils.h"

using namespace std;

/// Check uncopyable API classes which should have a default ctor actually do.
DEFINE_TESTCASE(defaultctor1, !backend) {
    Xapian::BB2Weight bb2weight;
    Xapian::BM25Weight bm25weight;
    Xapian::BoolWeight boolweight;
    Xapian::DLHWeight dlhweight;
    Xapian::DateRangeProcessor daterangeprocessor(0);
    Xapian::DateValueRangeProcessor datevaluerangeprocessor(0);
    Xapian::DecreasingValueWeightPostingSource decreasingvalueweightpostingsource(0);
    TEST(!decreasingvalueweightpostingsource.get_description().empty());
    Xapian::FixedWeightPostingSource fixedweightpostingsource(0);
    TEST(!fixedweightpostingsource.get_description().empty());
    Xapian::IfB2Weight ifb2weight;
    Xapian::InL2Weight inl2weight;
    Xapian::IneB2Weight ineb2weight;
    Xapian::MultiValueKeyMaker multivaluekeymaker;
    Xapian::NumberRangeProcessor numberrangeprocessor(0, "");
    Xapian::NumberValueRangeProcessor numbervaluerangeprocessor(0, "");
    Xapian::RangeProcessor rangeprocessor;
    Xapian::SimpleStopper simplestopper;
    TEST(!simplestopper.get_description().empty());
    Xapian::StringValueRangeProcessor stringvaluerangeprocessor(0);
    Xapian::TfIdfWeight tfidfweight;
    Xapian::TradWeight tradweight;
    Xapian::ValueCountMatchSpy valuecountmatchspy(0);
    TEST(!valuecountmatchspy.get_description().empty());
    Xapian::ValueMapPostingSource valuemappostingsource(0);
    TEST(!valuemappostingsource.get_description().empty());
    Xapian::ValuePostingSource valuepostingsource(0);
    TEST(!valuepostingsource.get_description().empty());
    Xapian::ValueWeightPostingSource valueweightpostingsource(0);
    TEST(!valueweightpostingsource.get_description().empty());
    return true;
}

/// Test that API classes have a copy ctor and assignment operator.
DEFINE_TESTCASE(copyassign1, !backend) {
    Xapian::Database database;
    TEST(!database.get_description().empty());
    Xapian::Database copy_database(database);
    database = copy_database;

    Xapian::Document document;
    TEST(!document.get_description().empty());
    Xapian::Document copy_document(document);
    document = copy_document;

    Xapian::ESet eset;
    TEST(!eset.get_description().empty());
    Xapian::ESet copy_eset(eset);
    eset = copy_eset;

    Xapian::ESetIterator esetiterator;
    TEST(!esetiterator.get_description().empty());
    Xapian::ESetIterator copy_esetiterator(esetiterator);
    esetiterator = copy_esetiterator;

#ifdef XAPIAN_HAS_INMEMORY_BACKEND
    Xapian::Enquire enquire(Xapian::Database(std::string(), Xapian::DB_BACKEND_INMEMORY));
    TEST(!enquire.get_description().empty());
    Xapian::Enquire copy_enquire(enquire);
    enquire = copy_enquire;
#endif

    Xapian::MSet mset;
    TEST(!mset.get_description().empty());
    Xapian::MSet copy_mset(mset);
    mset = copy_mset;

    Xapian::MSetIterator msetiterator;
    TEST(!msetiterator.get_description().empty());
    Xapian::MSetIterator copy_msetiterator(msetiterator);
    msetiterator = copy_msetiterator;

    Xapian::PositionIterator positioniterator;
    TEST(!positioniterator.get_description().empty());
    Xapian::PositionIterator copy_positioniterator(positioniterator);
    positioniterator = copy_positioniterator;

    Xapian::PostingIterator postingiterator;
    TEST(!postingiterator.get_description().empty());
    Xapian::PostingIterator copy_postingiterator(postingiterator);
    postingiterator = copy_postingiterator;

    Xapian::Query query;
    TEST(!query.get_description().empty());
    Xapian::Query copy_query(query);
    query = copy_query;

    Xapian::QueryParser queryparser;
    TEST(!queryparser.get_description().empty());
    Xapian::QueryParser copy_queryparser(queryparser);
    queryparser = copy_queryparser;

    Xapian::RSet rset;
    TEST(!rset.get_description().empty());
    Xapian::RSet copy_rset(rset);
    rset = copy_rset;

    Xapian::Registry registry;
    Xapian::Registry copy_registry(registry);
    registry = copy_registry;

    Xapian::Stem stem;
    TEST(!stem.get_description().empty());
    Xapian::Stem copy_stem(stem);
    stem = copy_stem;

    Xapian::TermGenerator termgenerator;
    TEST(!termgenerator.get_description().empty());
    Xapian::TermGenerator copy_termgenerator(termgenerator);
    termgenerator = copy_termgenerator;

    Xapian::TermIterator termiterator;
    TEST(!termiterator.get_description().empty());
    Xapian::TermIterator copy_termiterator(termiterator);
    termiterator = copy_termiterator;

    Xapian::ValueIterator valueiterator;
    TEST(!valueiterator.get_description().empty());
    Xapian::ValueIterator copy_valueiterator(valueiterator);
    valueiterator = copy_valueiterator;

    Xapian::WritableDatabase writabledatabase;
    TEST(!writabledatabase.get_description().empty());
    Xapian::WritableDatabase copy_writabledatabase(writabledatabase);
    writabledatabase = copy_writabledatabase;

    return true;
}