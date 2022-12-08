//
// Created by Nathan Tran on 08/12/2022.
//


#include <vector>
#include "DataLoader.h"

//void DataLoader::loadUserData() {
//    vector<vector<string>> rawData = loadFile("../Data/user_data.csv");
//    for (vector<string> line: rawData) {
//        for (string cell: line) {
//            std::cout << cell << " | ";
//        }
//        std::cout << std::endl;
//    }
//}

vector<vector<string>> DataLoader::loadFile(std::string src) {
    int counter = 0;
    std::string myText;
    std::ifstream MyReadFile(src);
    vector<vector<string>> result;
    while (getline(MyReadFile, myText)) {
        std::string cell;
        std::stringstream ss(myText);
        vector<string> tempArray;

        if (counter == 0) {
            counter++;
            continue;
        }

        while (getline(ss, cell, ',')) {
            tempArray.push_back(cell);
        }
        result.push_back(tempArray);
    }
    MyReadFile.close();

    return result;
}