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

#include "Request.h"

using std::cout, std::endl, std::string, std::ostream;

Status Request::stoE(const std::string &str) {
    if (str == "requested") return requested;
    else if (str == "accepted") return accepted;
    else if (str == "finished") return finished;
    else if (str == "rejected") return rejected;
}

inline const char *Request::enumToString(Status s) {
    switch (s) {
        case requested:
            return "requested";
        case accepted:
            return "accepted";
        case finished:
            return "finished";
        case rejected:
            return "rejected";
    }
}

void Request::showInfo() {
    cout << "RequestID:" << this->id << endl;
    cout <<  this->user << endl;
    cout << "HouseID:" << this->house.getId() << endl;
    cout << "Status:" << this->status << endl;
    cout << "Start date:" << this->startDate << endl;
    cout << "End date:" << this->endDate << endl;
}

string Request::to_string() {
    return this->id + "," + this->user.getUsername() + "," + this->house.getId() + "," + enumToString(this->status) +
           "," +
           this->startDate.getDate() + "," + this->endDate.getDate();
}

ostream &operator<<(ostream &os, Request &request) {
    cout << "RequestID:" << request.id << endl;
    cout << request.user << endl;
    cout << "HouseID:" << request.house.getId() << endl;
    cout << "Status:" << request.enumToString(request.status) << endl;
    cout << "Start date:" << request.startDate;
    cout << " - End date:" << request.endDate;
    return os;
}

//Constructor
Request::Request(UserController UC, HouseController HC, const string &id, const string &user, const string &house,
                 Status status, const CustomDate &startDate,
                 const CustomDate &endDate) : id(id), status(status), startDate(startDate),
                                              endDate(endDate) {
    this->user = UC.findByKey(user);
    this->house = HC.findByKey(house);
}

Request::Request(UserController UC, HouseController HC, const string &user, const string &house, Status status,
                 const CustomDate &startDate,
                 const CustomDate &endDate) : status(status), startDate(startDate),
                                              endDate(endDate) {
    this->id = std::to_string(this->randomID());
    this->user = UC.findByKey(user);
    this->house = HC.findByKey(house);
}

int Request::randomID() {
    srand((unsigned) time(NULL));
    return std::rand() % 10000 + 100;;
}

const string &Request::getId() const {
    return id;
}

void Request::setId(const string &id) {
    Request::id = id;
}

const string &Request::getOccupyName() const {
    return user.getUsername();
}

Status Request::getStatus() const {
    return status;
}

void Request::setStatus(Status status) {
    Request::status = status;
}

const CustomDate &Request::getStartDate() const {
    return startDate;
}

void Request::setStartDate(const CustomDate &startDate) {
    Request::startDate = startDate;
}

const CustomDate &Request::getEndDate() const {
    return endDate;
}

void Request::setEndDate(const CustomDate &endDate) {
    Request::endDate = endDate;
}

const User &Request::getUser() const {
    return user;
}


void Request::setUser(const User &user) {
    Request::user = user;
}

const House &Request::getHouse() const {
    return house;
}

void Request::setHouse(const House &house) {
    Request::house = house;
}
