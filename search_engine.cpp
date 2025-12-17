#include "search_engine.h"
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

SearchEngine::SearchEngine(InvertedIndex& idx, Preprocessor& prep)
    : invIndex(idx), preprocessor(prep) {}

vector<pair<int,double>> SearchEngine::search(const string& query) {
    auto queryTokens = preprocessor.preprocessText(query);
    unordered_map<int,double> scores;

    for (const auto& word : queryTokens) {
        if (invIndex.index.find(word) == invIndex.index.end())
            continue;

        int docsContainingWord = invIndex.index[word].size();
        double idf = log((double)invIndex.totalDocuments / docsContainingWord);

        for (auto& entry : invIndex.index[word]) {
            int docID = entry.first;
            int tf = entry.second;
            scores[docID] += tf * idf;
        }
    }

    vector<pair<int,double>> results(scores.begin(), scores.end());

    sort(results.begin(), results.end(),
         [](pair<int,double>& a, pair<int,double>& b) {
             return a.second > b.second;
         });

    return results;
}
