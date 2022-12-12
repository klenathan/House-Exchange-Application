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

string DataHandler::getPath(std::string src) {
    stringstream ss(src);
    string text;
    vector<string> resultArr;
    string result = "";
    while (getline(ss, text, '/')) {
        resultArr.push_back(text);
    }
    resultArr.pop_back();
    for (string folder: resultArr) {
        result += folder + "/";
    }
    return result;
}

std::string DataHandler::getOsName() {
#ifdef _WIN32 || _WIN64
    return "window";
#elif __APPLE__ || __MACH__ || __unix || __unix__ || __linux__
    return "unix_family";
#else
    return "unknown"
#endif
}

void DataHandler::clear() {
    string os = DataHandler::getOsName();

    if (os == "window") {
        system("cls");
    } else if (os == "unix_family") {
        system("clear");
    } else {
        std::cout << "unknown OS" << std::endl;
    }
};

bool DataHandler::writeFile(string src, string content) {

    ofstream MyFile(src);
    MyFile << content;
    MyFile.close();
    return 1;
};