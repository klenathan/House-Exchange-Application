//
// Created by Nathan Tran on 08/12/2022.
//

#include "Request.h"

using std::string;

Request::Request(User user, House house, Status status) {
    this->user = user;
    this->house = house;
    this->status = status;
}

/**
 * Getter-Setter
 * */

const User &Request::getUser() const {
    return user;
}

const House &Request::getHouse() const {
    return house;
}

Status Request::getStatus() const {
    return status;
}

void Request::setStatus(Status status) {
    Request::status = status;
}
