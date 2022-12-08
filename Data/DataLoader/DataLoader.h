//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_DATALOADER_H
#define HOUSEEXCHANGEAPPLICATION_DATALOADER_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class DataLoader {
private:
public:
    DataLoader() {}

    static vector<vector<string>> loadFile(std::string src);

    ~DataLoader() { delete this; }
};

#endif //HOUSEEXCHANGEAPPLICATION_DATALOADER_H
