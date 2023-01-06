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

#ifndef HOUSEEXCHANGEAPPLICATION_DATAHANDLER_H
#define HOUSEEXCHANGEAPPLICATION_DATAHANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
