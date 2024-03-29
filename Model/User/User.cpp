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

#include "User.h"

using std::string, std::endl, std::ostream, std::cout;

bool User::authenticate(string inputPassword) {
    if (inputPassword == this->password) {
        return true;
    }
    return false;
}

string User::getWriteFormat() {
    return this->username + "," + this->password + "," + to_string(this->creditPoints) + "," +
           this->fullname + "," + this->phoneNum + "," + to_string(this->rating) + "," +
           to_string(10);
}

ostream & operator<<(ostream & os, User & user) {
    os << "Username:" << user.username << endl;
    os << "Fullname:" << user.fullname << endl;
    os << "Contact:" << user.phoneNum << endl;
    os << "Credit points:" << user.creditPoints << endl;
    os << "Rating:" << user.rating << endl;
    return os;
}

User::User(const string &username, const string &password, const string &fullname, const string &phoneNum,
           long creditPoints, float rating) : username(username), password(password), fullname(fullname),
                                              phoneNum(phoneNum), creditPoints(creditPoints), rating(rating) {}

const string &User::getUsername() const {
    return username;
}

long User::getCreditPoints() const {
    return creditPoints;
}

void User::setCreditPoints(long creditPoints) {
    User::creditPoints = creditPoints;
}

float User::getRating() const {
    return rating;
}

void User::setRating(float rating) {
    User::rating = rating;
}
