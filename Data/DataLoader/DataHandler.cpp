//
// Created by Nathan Tran on 08/12/2022.
//


#include <vector>
#include <iostream>
#include <fstream>
#include "DataHandler.h"

using std::ofstream;

vector<vector<string>> DataHandler::loadFile(std::string src) {
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

bool DataHandler::writeFile(string src, string content) {

    ofstream MyFile(src);
    MyFile << content;
    MyFile.close();
    return 1;
};