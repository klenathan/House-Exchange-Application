//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USER_H
#define HOUSEEXCHANGEAPPLICATION_USER_H

#include <iostream>
#include <vector>
#include "../House/House.h"

using std::string;
using std::ostream;

class User {
private:
    string username, password, fullname, phoneNum;
    long creditPoints;
    float rating;
public:
    /**
     * Constructor
     * */
    User() {}

    User(string username, string password, long creditPoints) {
        this->username = username;
        this->password = password;
        this->creditPoints = creditPoints;
    }

    /**
     * Getter-Setter
     * */
    string getUsername() {
        return this->username;
    }

    long getCreditPoints() {
        return this->creditPoints;
    }

    /**
     * Methods
     * */

    void showInfo();
    bool authenticate(string inputPassword);
    void addCreditPoints(long additionNum);
    void removeCreditPoints(long additionNum);

    /**
     * Destructor
     * */

//    ~User() {
//        delete this;
//    }

    friend ostream & operator<<(ostream & os, User & user);
};
#endif //HOUSEEXCHANGEAPPLICATION_USER_H
