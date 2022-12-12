//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_DATAHANDLER_H
#define HOUSEEXCHANGEAPPLICATION_DATAHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>

using std::string, std::vector, std::stringstream;

class DataHandler {
private:
public:
    DataHandler() {}

    static vector<vector<string>> loadFile(string src);
    static bool writeFile(string src, string content);

    static string getOsName();
    static string getPath(string src);

    static void clear();

    ~DataHandler() { delete this; }
};

#endif //HOUSEEXCHANGEAPPLICATION_DATAHANDLER_H
