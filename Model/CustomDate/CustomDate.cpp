//
// Created by Nathan Tran on 08/12/2022.
//

#include <iostream>
#include <sstream>
#include <vector>

#include <exception>

#include "CustomDate.h"


/**
 * @author: Tran Nam Thai
 * @Errors codes:
 *   - These errors are thrown in the CustomDate constructor function
 *
 *  410: INVALID_DAY: When the day is not valid (larger than 31 or lower than 1, day 31 in a 30 days-month, etc)
 *  411: INVALID_MONTH: When month is greater than 12 and lower than 1
 *  412: INVALID_YEAR: Year is lower than 2022 (Present year)
 *
 * */

CustomDate::CustomDate(int day, int month, int year) {
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
 * @param: inputString has to follow the format of ("dd/mm/yyyy")
 * */
CustomDate::CustomDate(std::string inputString) {
    //// turn string input into int for further processing
    std::stringstream ss(inputString);
    std::string text;

    std::vector<int> tempArr;
    while (std::getline(ss, text, '/')) {
        try { tempArr.push_back(stoi(text)); }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    //// Repeat the default constructor
    int day = tempArr.at(0);
    int month = tempArr.at(1);
    int year = tempArr.at(2);
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
};

std::string CustomDate::getDate() {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

void CustomDate::showInfo() { std::cout << day << "/" << month << "/" << year << std::endl; }

std::ostream &operator<<(std::ostream &os, const CustomDate &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year << std::endl;
    return os;
};