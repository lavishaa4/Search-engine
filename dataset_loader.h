#ifndef DATASET_LOADER_H
#define DATASET_LOADER_H

#include <string>
#include "preprocess.h"
#include "inverted_index.h"

using namespace std;

void loadDataset(
    const string& datasetPath,
    Preprocessor& preprocessor,
    InvertedIndex& invIndex
);

#endif
