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


#include <iostream>
#include <sstream>
#include <vector>

#include <exception>
#include <ctime>
#include <time.h>

#include "CustomDate.h"
#include "../CustomError/Errors.h"

using std::stringstream, std::string, std::cout, std::endl, std::vector, std::ostream, std::to_string;

/**
 * Constructor
 * @param day
 * @param month
 * @param year
 */
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
                    else if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28)
                        throw ConversionErr("INVALID_DAY"); // leap year check
                } else if (month < 8 && day > 30) throw ConversionErr("INVALID_DAY");
            } else {
                //// Odd months
                if (month > 8 && day > 30) throw ConversionErr("INVALID_DAY");
            }
        }
        //// Year check
        if (year < 2022) {
            throw ConversionErr("INVALID_YEAR");
        }

        this->day = day;
        this->month = month;
        this->year = year;
    } catch (std::exception const &e) {
        throw ConversionErr(e.what());
    }
}

/**
 * Constructor
 * @param: inputString has to follow the format of ("dd/mm/yyyy")
 * */
CustomDate::CustomDate(string inputString) {
    // turn string input into int for further processing
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

    // Repeat the default constructor
    int day = tempArr.at(0);
    int month = tempArr.at(1);
    int year = tempArr.at(2);
    try {
        // Day check
        if (day > 31 || day < 1) {
            throw ConversionErr("INVALID_DAY");
        }
        // Month check with days
        if (month > 12 || month < 1) {
            throw ConversionErr("INVALID_MONTH");
        } else {
            if (month % 2 == 0) {
                // Even Months
                if (month == 2) {
                    if (day > 29) throw ConversionErr("INVALID_DAY");
                    else if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 28)
                        throw ConversionErr("INVALID_DAY"); // leap year check
                } else if (month < 8 && day > 30) throw ConversionErr("INVALID_DAY");
            } else {
                // Odd months
                if (month > 8 && day > 30) throw ConversionErr("INVALID_DAY");
            }
        }
        // Year check
        if (year < 2022) {
            throw ConversionErr("INVALID_YEAR");
        }

        this->day = day;
        this->month = month;
        this->year = year;
    } catch (std::exception const &e) {
        throw DateErr(e.what());
    }
};

/**
 * Validate Date
 * @param dateInp
 * @return
 */
bool CustomDate::validDate(string dateInp) {
    stringstream ss(dateInp);
    string text;
    vector<int> tempArr;

    while (getline(ss, text, '/')) {
        try { tempArr.push_back(stoi(text)); }
        catch (std::exception &e) {
            cout << e.what() << endl;
            throw e;
        }
    }

    int day = tempArr.at(0);
    int month = tempArr.at(1);
    int year = tempArr.at(2);

    // Current time
    time_t currentTime = std::time(0);

    // Input time
    time_t rawTime;
    struct tm *inputTime;

    time(&rawTime);
    inputTime = localtime(&rawTime);
    inputTime->tm_year = year - 1900;
    inputTime->tm_mon = month - 1;
    inputTime->tm_mday = day;

    std::time_t time = mktime(inputTime);
    double diff = difftime(time, currentTime);
    if (diff < 0) return 0;
    return 1;
}

/**
 * Convert CustomDate type to time_t type
 * @param d
 * @return time
 */
time_t CustomDate::convertToTimeT(CustomDate d) {
    int day = d.getDay();
    int month = d.getMonth();
    int year = d.getYear();

    time_t rawTime;
    struct tm *inputTime;

    time(&rawTime);
    inputTime = localtime(&rawTime);
    inputTime->tm_year = year - 1900;
    inputTime->tm_mon = month - 1;
    inputTime->tm_mday = day;

    time_t time = mktime(inputTime);
    return time;
}

/**
 * Get number of days
 * @param d1
 * @param d2
 * @return sec/86400: number of days
 */
double CustomDate::getDateRange(const CustomDate &d1, const CustomDate &d2) {
    double sec = difftime(CustomDate::convertToTimeT(d1), CustomDate::convertToTimeT(d2));
    return sec / 86400;
}


/**
 * @return a string format of the date object (dd/mm/yyyy)
 * */
string CustomDate::getDate() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

/**
 * Log the date object to console in the format of dd/mm/yyyy
 * */
void CustomDate::showInfo() { cout << day << "/" << month << "/" << year << endl; }

/**
 * Get current date
 * @return
 */
CustomDate CustomDate::getToday() {
    time_t time = std::time(0);
    return CustomDate(localtime(&time)->tm_mday, localtime(&time)->tm_mon + 1, localtime(&time)->tm_year + 1900);
}

/**
 * @overload the bit-wise << operation
 *
 * */
ostream &operator<<(ostream &os, const CustomDate &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year;
    return os;
};


/** @OVERLOAD DATA COMPARATOR **/
bool operator == (const CustomDate &d1, const CustomDate &d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
};

bool operator != (const CustomDate &d1, const CustomDate &d2) {
    return d1.year != d2.year || d1.month != d2.month || d1.day != d2.day;
};

bool operator < (const CustomDate &d1, const CustomDate &d2) {
    if (d1.year < d2.year) return true;
    else if (d1.year > d2.year) return false;
    else {
        // d1.year == d2.year
        if (d1.month < d2.month) return true;
        else if (d1.month > d2.month) return false;
        else {
            // d1.month == d2.month
            if (d1.day < d2.day) return true;
            else return false;
        }
    }
};

bool operator > (const CustomDate &d1, const CustomDate &d2) {
    if (d1.year > d2.year) return true;
    else if (d1.year < d2.year) return false;
    else {
        // d1.year == d2.year
        if (d1.month > d2.month) return true;
        else if (d1.month < d2.month) return false;
        else {
            // d1.month == d2.month
            if (d1.day > d2.day) return true;
            else return false;
        }
    }
};

bool operator <= (const CustomDate &d1, const CustomDate &d2) {
    if (d1.year < d2.year) return true;
    else if (d1.year > d2.year) return false;
    else {
        // d1.year == d2.year
        if (d1.month < d2.month) return true;
        else if (d1.month > d2.month) return false;
        else {
            // d1.month == d2.month
            if (d1.day < d2.day) return true;
            else if (d1.day > d2.day) return false;
            else return true;
        }
    }
};

bool operator >= (const CustomDate &d1, const CustomDate &d2) {
    if (d1.year > d2.year) return true;
    else if (d1.year < d2.year) return false;
    else {
        // d1.year == d2.year
        if (d1.month > d2.month) return true;
        else if (d1.month < d2.month) return false;
        else {
            // d1.month == d2.month
            if (d1.day > d2.day) return true;
            else if (d1.day < d2.day) return false;
            else return true;
        }
    }
};


/******************************************************************
 * Getter-Setter
 ******************************************************************/

int CustomDate::getDay() const {
    return day;
}

int CustomDate::getMonth() const {
    return month;
}

int CustomDate::getYear() const {
    return year;
}
