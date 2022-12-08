//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USER_H
#define HOUSEEXCHANGEAPPLICATION_USER_H

#include <iostream>
#include <vector>
#include "../House/House.h"


class User {
private:
    std::string username, password, fullname, phoneNum;
    long creditPoints;
    float rating;
public:
    /**
     * Constructor
     * */
    User() {}

    User(std::string username, std::string password, long creditPoints) {
        this->username = username;
        this->password = password;
        this->creditPoints = creditPoints;
    }

    /**
     * Getter-Setter
     * */
    std::string getUsername() {
        return this->username;
    }

    long getCreditPoints() {
        return this->creditPoints;
    }

    /**
     * Methods
     * */

    void showInfo();
    bool authenticate(std::string inputPassword);
    void addCreditPoints(long additionNum);
    void removeCreditPoints(long additionNum);

    /**
     * Destructor
     * */

//    ~User() {
//        delete this;
//    }

    friend std::ostream & operator<<(std::ostream & os, User & user);
};
#endif //HOUSEEXCHANGEAPPLICATION_USER_H
