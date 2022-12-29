//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USER_H
#define HOUSEEXCHANGEAPPLICATION_USER_H

#include <iostream>
#include <sstream>
#include <vector>
#include "../House/House.h"

using std::string;
using std::ostream, std::stringstream, std::to_string;

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

    User(const string &username, const string &password, const string &fullname, const string &phoneNum,
         long creditPoints, float rating);

    /**
     * Getter-Setter
     * */


    string getWriteFormat() {
        return this->username + "," + this->password + "," + to_string(this->creditPoints) + "," +
               this->fullname + "," + this->phoneNum + "," + to_string(this->rating) + "," +
               to_string(10);
    }

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getFullname() const;

    void setFullname(const string &fullname);

    const string &getPhoneNum() const;

    void setPhoneNum(const string &phoneNum);

    long getCreditPoints() const;

    void setCreditPoints(long creditPoints);

    float getRating() const;

    void setRating(float rating);

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

    friend ostream &operator<<(ostream &os, User &user);
};

#endif //HOUSEEXCHANGEAPPLICATION_USER_H
