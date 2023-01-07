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

#ifndef HOUSEEXCHANGEAPPLICATION_ERRORS_H
#define HOUSEEXCHANGEAPPLICATION_ERRORS_H

#include <iostream>

class ConversionErr: public std::runtime_error {
public:                         // And has an implementation of what()
    ConversionErr(std::string const& msg):
    runtime_error(msg){}
};

class NotfoundErr: public std::runtime_error {
public:
    NotfoundErr(std::string const& msg):
            runtime_error(msg){}
};

class ContainSpace: public std::exception{
private:
    string message;

public:
    ContainSpace(string  msg) : message(msg) {}
    string what () {
        return message;
    }
};

class DateErr: public std::runtime_error {
public:
    DateErr(std::string const& msg):
            runtime_error(msg){}
};
#endif //HOUSEEXCHANGEAPPLICATION_ERRORS_H
