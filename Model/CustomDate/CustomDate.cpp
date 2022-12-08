//
// Created by Nathan Tran on 08/12/2022.
//

#include <iostream>
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

std::string CustomDate::getDate() {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year) + "/";
}

void CustomDate::showInfo() { std::cout << day << "/" << month << "/" << year << std::endl; }

std::ostream &operator<<(std::ostream &os, const CustomDate &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year << std::endl;
    return os;
};