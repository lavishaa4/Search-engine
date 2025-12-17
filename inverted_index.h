#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class InvertedIndex{
    public:
    unordered_map<string, unordered_map<int,int> > index;
    int totalDocuments;

    InvertedIndex();
    void addDocument(int docID, const vector<string>& tokens);
};

#endif
