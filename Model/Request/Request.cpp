//
// Created by Nathan Tran on 08/12/2022.
//

#include "Request.h"


Request::Request(User user, House house, std::string status) {
    this->user = user;
    this->house = house;
    this->status = status;
}