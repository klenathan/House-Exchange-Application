//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
#define HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H

#include <iostream>


class CustomDate {
private:
    int day, month, year;
public:

    /**
     * Constructor
     * */
    CustomDate() {};

    CustomDate(int day, int month, int year);

    CustomDate(std::string);
    /**
     * Methods declarations
     * */
    std::string getDate();
    void showInfo();
    friend std::ostream &operator<<(std::ostream &os, const CustomDate &dt);
};
#endif //HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
