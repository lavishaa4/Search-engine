#include <iostream>
#include <chrono>
#include "preprocess.h"
#include "inverted_index.h"
#include "search_engine.h"

using namespace std;

int main() {
    Preprocessor preprocessor;
    InvertedIndex invIndex;

    // Sample documents (replace with 20 Newsgroups dataset)
    vector<string> documents = {
        "Data structures and algorithms are important",
        "Search engines use inverted index",
        "Data science uses data and algorithms"
    };

    for (int i = 0; i < documents.size(); i++) {
        auto tokens = preprocessor.preprocessText(documents[i]);
        invIndex.addDocument(i, tokens);
        invIndex.totalDocuments++;
    }

    SearchEngine engine(invIndex, preprocessor);

    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    auto start = chrono::high_resolution_clock::now();
    auto results = engine.search(query);
    auto end = chrono::high_resolution_clock::now();

    cout << "\nSearch Results:\n";
    for (auto& res : results) {
        cout << "Document " << res.first
             << " | Score: " << res.second << endl;
    }

    auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nSearch Time: " << duration.count() << " microseconds\n";
    cout << "Total Documents: " << invIndex.totalDocuments << endl;
    cout << "Unique Words Indexed: " << invIndex.index.size() << endl;

    return 0;
}
