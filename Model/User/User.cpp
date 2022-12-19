//
// Created by Nathan Tran on 08/12/2022.
//


#include "User.h"

using std::string, std::endl, std::ostream;


void User::showInfo() {
    std::cout << "Username: " << this->username << endl;
    std::cout << "Credit points: " << this->creditPoints << endl;
    std::cout << "Rating: " << this->rating << endl;


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
    os << "Rating: " << user.rating << endl;
    return os;
}

User::User(const string &username, const string &password, const string &fullname, const string &phoneNum,
           long creditPoints, float rating) : username(username), password(password), fullname(fullname),
                                              phoneNum(phoneNum), creditPoints(creditPoints), rating(rating) {}

float User::getRating() const {
    return rating;
}

void User::setRating(float rating) {
    User::rating = rating;
}
