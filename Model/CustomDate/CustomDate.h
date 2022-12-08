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

    CustomDate(int day, int month, int year) {
        try {
            ///// Day check
            if (day > 31 || day < 1) {
                throw 410;
            }
            ///// Month check with days
            if (month > 12 || month < 1) {
                throw 411;
            } else {
                if (!month % 2) {
                    //// Even Months
                    if (month == 2 && day > 29) throw 410;
                    else if (month < 8 && day > 30) throw 410;
                } else {
                    //// Odd months
                    if (month > 8 && day > 30) throw 410;
                }
            }
            //// Year check
            if (year < 2022) {
                throw 412;
            }
            this->day = day;
            this->month = month;
            this->year = year;
        } catch (int e) {
            std::cout << e;
        }
    }

    /**
     * Methods declarations
     * */
    std::string getDate();
    void showInfo();
    friend std::ostream &operator<<(std::ostream &os, const CustomDate &dt);
};
#endif //HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
