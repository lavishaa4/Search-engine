#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Preprocessor {
private:
    unordered_set<string> stopwords;

public:
    Preprocessor();
    vector<string> preprocessText(const string& text);
};

#endif
