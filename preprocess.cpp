#include "preprocess.h"
#include <sstream>
#include <cctype>

using namespace std;

Preprocessor::Preprocessor() {
    string common[] = {
        "the","is","and","or","to","of","in","on","for","with",
        "a","an","by","as","at","from","this","that","it","are"
    };

    for (auto &w : common)
        stopwords.insert(w);
}

vector<string> Preprocessor::preprocessText(const string& text) {
    string cleaned;

    for (char c : text) {
        if (isalnum(c) || c == ' ')
            cleaned += tolower(c);
        else
            cleaned += ' ';
    }

    stringstream ss(cleaned);
    string word;
    vector<string> tokens;

    while (ss >> word) {
        if (stopwords.find(word) == stopwords.end()) {
            tokens.push_back(word);
        }
    }

    return tokens;
}
