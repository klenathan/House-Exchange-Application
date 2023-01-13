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

    CustomDate(string inputString);


    int getDay() const;


    int getMonth() const;


    int getYear() const;

    /**
     * Methods declarations
     * */
    std::string getDate() const;

    static bool validDate(string dateInp);

    static double getDateRange(const CustomDate &d1, const CustomDate &d2);

    static time_t convertToTimeT(CustomDate d);

    static CustomDate getToday();

    friend std::ostream &operator<<(std::ostream &os, const CustomDate &dt);

    /** @OVERLOAD DATA COMPARATOR **/
    friend bool operator == (const CustomDate &d1, const CustomDate &d2);

    friend bool operator != (const CustomDate &d1, const CustomDate &d2);

    friend bool operator < (const CustomDate &d1, const CustomDate &d2);

    friend bool operator > (const CustomDate &d1, const CustomDate &d2);

    friend bool operator <= (const CustomDate &d1, const CustomDate &d2);

    friend bool operator >= (const CustomDate &d1, const CustomDate &d2);

};

#endif //HOUSEEXCHANGEAPPLICATION_CUSTOMDATE_H
