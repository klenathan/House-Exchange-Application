//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
#define HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H

#include <iostream>

using std::string;

/**
 * Custom date class for House Exchanging Application written in c++ by team TDTK
 *
 * The class has 3 parameters: day, month, year
 *
 * */

class CustomDate {
private:
    int day, month, year;
public:

    /**
     * Constructors
     * */
    CustomDate() {};

    CustomDate(int day, int month, int year);

    CustomDate(string);

    /**
     * Methods declarations
     * */
    std::string getDate() const;
    void showInfo();
    friend std::ostream &operator<<(std::ostream &os, const CustomDate &dt);
};
#endif //HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
