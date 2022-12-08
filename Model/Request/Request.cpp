//
// Created by Nathan Tran on 08/12/2022.
//

#include "Request.h"

using std::string;

Request::Request(User user, House house, string status) {
    this->user = user;
    this->house = house;
    this->status = status;
}