#include <iostream>
#include <chrono>
#include "dataset_loader.h"
#include "preprocess.h"
#include "inverted_index.h"
#include "search_engine.h"

using namespace std;

int main() {
    Preprocessor preprocessor;
    InvertedIndex invIndex;

    // Path to 20 Newsgroups dataset folder
    string datasetPath = "/Users/lavishavalecha/twenty+newsgroups/mini_newsgroups";


    // Load dataset and build inverted index
    loadDataset(datasetPath, preprocessor, invIndex);

    SearchEngine engine(invIndex, preprocessor);

    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    auto start = chrono::high_resolution_clock::now();
    auto results = engine.search(query);
    auto end = chrono::high_resolution_clock::now();

    cout << "\nSearch Results:\n";
    int k = 10;  //printing top 10
    for (int i = 0; i < results.size() && i < k; i++) {
    cout << "Document ID: " << results[i].first
         << " | Score: " << results[i].second << endl;
}


    auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nSearch Time: " << duration.count() << " microseconds\n";
    cout << "Total Documents Indexed: " << invIndex.totalDocuments << endl;
    cout << "Unique Words Indexed: " << invIndex.index.size() << endl;

    return 0;
}
