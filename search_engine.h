#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include "inverted_index.h"
#include "preprocess.h"
#include <vector>
#include <utility>

using namespace std;

class SearchEngine {
private:
    InvertedIndex& invIndex;
    Preprocessor& preprocessor;

public:
    SearchEngine(InvertedIndex& idx, Preprocessor& prep);
    vector<pair<int,double> > search(const string& query);
};

#endif
