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

#ifndef HOUSEEXCHANGEAPPLICATION_REQUEST_H
#define HOUSEEXCHANGEAPPLICATION_REQUEST_H

#include <iostream>
#include "../../Model/House/House.h"
#include "../../Model/User/User.h"
#include "../../Controller/HouseController/HouseController.h"
#include "../../Controller/UserController/UserController.h"

using std::string;

enum Status {
    requested, accepted, finished, rejected
};

class Request {
private:
    string id;
    User user;
    House house;
    Status status; //// Enum: "requested", "accepted", "finished", "rejected"
    CustomDate startDate, endDate;

public:
    Request() = default;

    Request(UserController UC, HouseController HC, const string &id, const string &user, const string &house,
            Status status, const CustomDate &startDate,
            const CustomDate &endDate);

    Request(UserController UC, HouseController HC, const string &user, const string &house, Status status,
            const CustomDate &startDate,
            const CustomDate &endDate);

    /**
     * Getter-Setter
     * */

    Status getStatus() const;

    const User &getUser() const;

    void setUser(const User &user);

    const House &getHouse() const;

    void setHouse(const House &house);

    void setStatus(Status status);

    const CustomDate &getStartDate() const;

    void setStartDate(const CustomDate &startDate);

    const CustomDate &getEndDate() const;

    void setEndDate(const CustomDate &endDate);

    static int randomID();

    string to_string();

    void showInfo();

    Status stoE(const std::string &str);

    inline const char *enumToString(Status s);

    friend ostream &operator<<(ostream &os, Request &request);

    const string &getId() const;

    void setId(const string &id);

    const string &getOccupyName() const;
};

#endif //HOUSEEXCHANGEAPPLICATION_REQUEST_H
