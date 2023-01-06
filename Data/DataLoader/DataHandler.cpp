/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Assessment: 3
  Author:
      s3891890, Tran Nam Thai
      s3878246, Pham Anh Thu
      s3891968, Pham Vo Dong
      s3927201, Tran Ngoc Khang
  Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to check)
  Created  date: 11/12/2022
  Acknowledgement: None
*/

#include <vector>
#include <iostream>
#include "DataHandler.h"

using std::ofstream, std::string, std::cout, std::endl, std::ifstream, std::getline;

/**
 * Load data into a vector
 * @param src
 * @return vector<vector<string>> result
 */
vector<vector<string>> DataHandler::loadFile(string src) {
    int counter = 0;
    string myText;
    ifstream MyReadFile(src);
    vector<vector<string>> result;
    while (getline(MyReadFile, myText)) {
        string cell;
        stringstream ss(myText);
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

/**
 * Get current file path
 * @param src
 * @return string result
 */
string DataHandler::getPath(string src) {
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

/**
 * get OS name
 * @return os name
 */
string DataHandler::getOsName() {
#ifdef _WIN32 || _WIN64
    return "window";
#elif __APPLE__ || __MACH__ || __unix || __unix__ || __linux__
    return "unix_family";
#else
    return "unknown"
#endif
}

/**
 * Clear function
 */
void DataHandler::clear() {
    string os = DataHandler::getOsName();

    if (os == "window") {
        system("cls");
    } else if (os == "unix_family") {
        system("clear");
    } else {
        cout << "unknown OS" << endl;
    }
};

/**
 * Write file
 * @param src
 * @param content
 * @return bool true
 */
bool DataHandler::writeFile(string src, string content) {
    ofstream MyFile(src);
    MyFile << content;
    MyFile.close();
    return 1;
};