#include "inverted_index.h"

using namespace std;

InvertedIndex::InvertedIndex() {
    totalDocuments = 0;
}

void InvertedIndex::addDocument(int docID, const vector<string>& tokens) {
    for (const auto& word : tokens) {
        index[word][docID]++;
    }
}
