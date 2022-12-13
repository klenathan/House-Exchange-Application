//
// Created by Nathan Tran on 12/12/2022.
//

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

#endif //HOUSEEXCHANGEAPPLICATION_ERRORS_H
