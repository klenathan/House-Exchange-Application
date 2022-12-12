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
    User user;
    House house;
    Status status; //// Enum: "requested", "accepted", "finished", "rejected"
public:
    Request() = default;

    Request(User user, House house, Status status);

    /**
     * Getter-Setter
     * */

    const User &getUser() const;

    const House &getHouse() const;

    Status getStatus() const;

    void setStatus(Status status);

};

#endif //HOUSEEXCHANGEAPPLICATION_REQUEST_H
