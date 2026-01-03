#include "dataset_loader.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void loadDataset(
    const string& datasetPath,
    Preprocessor& preprocessor,
    InvertedIndex& invIndex
) {
    int docID = 0;

    for (const auto& category : fs::directory_iterator(datasetPath)) {
        if (!category.is_directory()) continue;

        for (const auto& file : fs::directory_iterator(category.path())) {
            if (!file.is_regular_file()) continue;

            ifstream in(file.path());
            if (!in.is_open()) continue;

            stringstream buffer;
            buffer << in.rdbuf();
            string content = buffer.str();

            auto tokens = preprocessor.preprocessText(content);
            invIndex.addDocument(docID, tokens);
            invIndex.totalDocuments++;

            docID++;
        }
    }

    cout << "Loaded " << invIndex.totalDocuments << " documents\n";
}
