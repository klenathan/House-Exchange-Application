//
// Created by Nathan Tran on 08/12/2022.
//


#include "User.h"


void User::showInfo() {
    std::cout << "Username: " << this->username << std::endl;
    std::cout << "Credit points: " << this->creditPoints << std::endl;
}

bool User::authenticate(std::string inputPassword) {
    if (inputPassword == this->password) {
        return true;
    }
    return false;
}

void User::removeCreditPoints(long additionNum) {
    this->creditPoints -= additionNum;
}


void User::addCreditPoints(long additionNum) {
    this->creditPoints += additionNum;
}

std::ostream & operator<<(std::ostream & os, User & user) {
    os << "Username: " << user.username << std::endl;
    os << "Fullname: " << user.fullname << std::endl;
    os << "Contact: " << user.phoneNum << std::endl;
    os << "Credit points: " << user.creditPoints << std::endl;
    return os;
}
