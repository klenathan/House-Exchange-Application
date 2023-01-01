//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
#define HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H

#include <iostream>
#include <ctime>
#include <time.h>

using std::string, std::time_t;

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


    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    /**
     * Methods declarations
     * */
    std::string getDate() const;
    void showInfo();
    bool validDate(string dateInp);
    double getDateRange(const CustomDate& d1, const CustomDate& d2);
    time_t convertToTimeT(CustomDate d);

    friend std::ostream &operator<<(std::ostream &os, const CustomDate &dt);

    /** @OVERLOAD DATA COMPARATOR **/
    friend bool operator== (const CustomDate& d1, const CustomDate& d2);
    friend bool operator!= (const CustomDate& d1, const CustomDate& d2);

    friend bool operator< (const CustomDate& d1, const CustomDate& d2);
    friend bool operator> (const CustomDate& d1, const CustomDate& d2);

    friend bool operator<= (const CustomDate& d1, const CustomDate& d2);
    friend bool operator>= (const CustomDate& d1, const CustomDate& d2);


};
#endif //HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
