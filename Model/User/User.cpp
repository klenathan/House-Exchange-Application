//
// Created by Nathan Tran on 08/12/2022.
//


#include "User.h"

using std::string, std::endl, std::ostream;


void User::showInfo() {
    std::cout << "Username: " << this->username << endl;
    std::cout << "Credit points: " << this->creditPoints << endl;
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

ostream & operator<<(ostream & os, User & user) {
    os << "Username: " << user.username << endl;
    os << "Fullname: " << user.fullname << endl;
    os << "Contact: " << user.phoneNum << endl;
    os << "Credit points: " << user.creditPoints << endl;
    return os;
}
