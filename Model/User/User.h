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
#ifndef HOUSEEXCHANGEAPPLICATION_USER_H
#define HOUSEEXCHANGEAPPLICATION_USER_H

#include <iostream>
#include <sstream>
#include <vector>
#include "../House/House.h"

using std::string, std::ostream, std::stringstream, std::to_string;

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

    User(const string &username, const string &password, const long &creditPoints);

    User(const string &username, const string &password, const string &fullname, const string &phoneNum,
         long creditPoints, float rating);

    /**
     * Getter-Setter
     * */

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

    string getWriteFormat();

    void showInfo();

    bool authenticate(string inputPassword);

    friend ostream &operator<<(ostream &os, User &user);
};

#endif //HOUSEEXCHANGEAPPLICATION_USER_H
