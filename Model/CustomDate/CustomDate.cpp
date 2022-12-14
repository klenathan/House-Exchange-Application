//
// Created by Nathan Tran on 08/12/2022.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <ctime>

#include <exception>

#include "CustomDate.h"
#include "../CustomError/Errors.h"

using std::stringstream, std::string, std::cout, std::endl, std::vector, std::ostream;

/**
 *
 * @author: Tran Nam Thai
 * @Errors codes:
 *   - These errors are thrown in the CustomDate constructor function
 * */

CustomDate::CustomDate(int day, int month, int year) {
    try {
        ///// Day check
        if (day > 31 || day < 1) {
            throw ConversionErr("INVALID_DAY");
        }
        ///// Month check with days
        if (month > 12 || month < 1) {
            throw ConversionErr("INVALID_MONTH");
        } else {
            if (month % 2 == 0) {
                //// Even Months
                if (month == 2) {
                    if (day > 29) throw ConversionErr("INVALID_DAY");
                    else if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28) throw ConversionErr("INVALID_DAY"); // leap year check
                }
                else if (month < 8 && day > 30) throw ConversionErr("INVALID_DAY");
            } else {
                //// Odd months
                if (month > 8 && day > 30) throw ConversionErr("INVALID_DAY");
            }
        }
        //// Year check
        if (year < 2022) {
            throw ConversionErr("INVALID_YEAR");
        }


        // Current time
        time_t currentTime = std::time(0);
        char* dt = ctime(&currentTime);

        // Input time
        time_t rawTime;
        struct tm * inputTime;

        time ( &rawTime );
        inputTime = localtime ( &rawTime );
        inputTime->tm_year = year - 1900;
        inputTime->tm_mon = month - 1;
        inputTime->tm_mday = day;

        std::time_t time = mktime(inputTime);

        char* dt1 = ctime(&time);

        double diff =  difftime (time, currentTime);
        if (diff < 0) throw ConversionErr("INVALID_DATE");

        this->day = day;
        this->month = month;
        this->year = year;
    } catch (std::exception const &e) {
        throw ConversionErr(e.what());
    }
}

/**
 * @param: inputString has to follow the format of ("dd/mm/yyyy")
 * */
CustomDate::CustomDate(string inputString) {
    //// turn string input into int for further processing
    stringstream ss(inputString);
    string text;

    vector<int> tempArr;
    while (getline(ss, text, '/')) {
        try { tempArr.push_back(stoi(text)); }
        catch (std::exception &e) {
            cout << e.what() << endl;
            throw e;
        }
    }

    //// Repeat the default constructor
    int day = tempArr.at(0);
    int month = tempArr.at(1);
    int year = tempArr.at(2);
    try {
        ///// Day check
        if (day > 31 || day < 1) {
            throw ConversionErr("INVALID_DAY");
        }
        ///// Month check with days
        if (month > 12 || month < 1) {
            throw ConversionErr("INVALID_MONTH");
        } else {
            if (month % 2 == 0) {
                //// Even Months
                if (month == 2) {
                    if (day > 29) throw ConversionErr("INVALID_DAY");
                    else if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28) throw ConversionErr("INVALID_DAY"); // leap year check
                }
                else if (month < 8 && day > 30) throw ConversionErr("INVALID_DAY");
            } else {
                //// Odd months
                if (month > 8 && day > 30) throw ConversionErr("INVALID_DAY");
            }
        }
        //// Year check
        if (year < 2022) {
            throw ConversionErr("INVALID_YEAR");
        }


        // Current time
        time_t currentTime = std::time(0);
        char* dt = ctime(&currentTime);

        // Input time
        time_t rawTime;
        struct tm * inputTime;

        time ( &rawTime );
        inputTime = localtime ( &rawTime );
        inputTime->tm_year = year - 1900;
        inputTime->tm_mon = month - 1;
        inputTime->tm_mday = day;

        std::time_t time = mktime(inputTime);

//        char* dt1 = ctime(&time);

//        double diff =  difftime (time, currentTime);
//        if (diff < 0) throw DateErr("Invalid Date");

        this->day = day;
        this->month = month;
        this->year = year;
    } catch (std::exception const &e) {
//        cout <<
        throw DateErr(e.what());
    }
};


/**
 * @return a string format of the date object (dd/mm/yyyy)
 * */
string CustomDate::getDate() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

/**
 * log the date object to console in the format of dd/mm/yyyy
 * */
void CustomDate::showInfo() { cout << day << "/" << month << "/" << year << endl; }


/**
 * @overload the bit-wise << operation
 *
 * */
ostream &operator<<(ostream &os, const CustomDate &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year << endl;
    return os;
};


/** @OVERLOAD DATA COMPARATOR **/
bool operator== (const CustomDate& d1, const CustomDate& d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
};
bool operator!= (const CustomDate& d1, const CustomDate& d2) {
    return d1.year != d2.year || d1.month != d2.month || d1.day != d2.day;
};

bool operator< (const CustomDate& d1, const CustomDate& d2) {
    if (d1.year < d2.year) return true;
    else if (d1.year > d2.year) return false;
    else{
       //// d1.year == d2.year
        if (d1.month < d2.month) return true;
        else if (d1.month > d2.month) return false;
        else {
            //// d1.month == d2.month
            if (d1.day < d2.day) return true;
            else return false;
        }
    }
};
bool operator> (const CustomDate& d1, const CustomDate& d2) {
    if (d1.year > d2.year) return true;
    else if (d1.year < d2.year) return false;
    else{
        //// d1.year == d2.year
        if (d1.month > d2.month) return true;
        else if (d1.month < d2.month) return false;
        else {
            //// d1.month == d2.month
            if (d1.day > d2.day) return true;
            else return false;
        }
    }
};

bool operator<= (const CustomDate& d1, const CustomDate& d2) {
    if (d1.year < d2.year) return true;
    else if (d1.year > d2.year) return false;
    else{
        //// d1.year == d2.year
        if (d1.month < d2.month) return true;
        else if (d1.month > d2.month) return false;
        else {
            //// d1.month == d2.month
            if (d1.day < d2.day) return true;
            else if (d1.day > d2.day) return false;
            else return true;
        }
    }
};
bool operator>= (const CustomDate& d1, const CustomDate& d2) {
    if (d1.year > d2.year) return true;
    else if (d1.year < d2.year) return false;
    else{
        //// d1.year == d2.year
        if (d1.month > d2.month) return true;
        else if (d1.month < d2.month) return false;
        else {
            //// d1.month == d2.month
            if (d1.day > d2.day) return true;
            else if (d1.day < d2.day) return false;
            else return false;
        }
    }
};