//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_REQUEST_H
#define HOUSEEXCHANGEAPPLICATION_REQUEST_H

#include <iostream>
#include "../../Model/House/House.h"
#include "../../Model/User/User.h"


class Request{
private:
    User user;
    House house;
    std::string status; //// Enum: "requested", "accepted", "finished"
public:
    Request() {}

    Request(User user, House house, std::string status);
};
#endif //HOUSEEXCHANGEAPPLICATION_REQUEST_H
