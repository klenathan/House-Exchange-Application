//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_REQUEST_H
#define HOUSEEXCHANGEAPPLICATION_REQUEST_H

#include <iostream>
#include "../../Model/House/House.h"
#include "../../Model/User/User.h"

using std::string;

enum Status {
    requested, accepted, finished, rejected
};

class Request {
private:
    string user;
    string house;
    Status status; //// Enum: "requested", "accepted", "finished", "rejected"
    CustomDate startDate, endDate;

public:
    Request() = default;

    Request(const string &user, const string &house, Status status, const CustomDate &startDate,
            const CustomDate &endDate);

    /**
     * Getter-Setter
     * */

    const string &getUser() const;

    void setUser(const string &user);

    const string &getHouse() const;

    void setHouse(const string &house);

    Status getStatus() const;

    void setStatus(Status status);

    const CustomDate &getStartDate() const;

    void setStartDate(const CustomDate &startDate);

    const CustomDate &getEndDate() const;

    void setEndDate(const CustomDate &endDate);


    string to_string();
    void showInfo();
    Status stoE(const std::string& str);
    inline const char* enumToString(Status s);
    friend ostream & operator<<(ostream & os, Request & request);

};

#endif //HOUSEEXCHANGEAPPLICATION_REQUEST_H
