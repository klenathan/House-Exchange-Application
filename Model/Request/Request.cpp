//
// Created by Nathan Tran on 08/12/2022.
//

#include "Request.h"

using std::cout, std::endl, std::string, std::ostream;

Status Request::stoE(const std::string& str)
{
    if(str == "requested") return requested;
    else if(str == "accepted") return accepted;
    else if(str == "finished") return finished;
    else if (str == "rejected") return rejected;
}

inline const char* Request::enumToString(Status s) {
    switch (s) {
        case requested:   return "requested";
        case accepted:   return "accepted";
        case finished: return "finished";
        case rejected: return "rejected";
    }
}

void Request::showInfo() {
    cout << "Username: " << this->user << endl;
    cout << "HouseID: " << this->house << endl;
    cout << "Status: " << this->status << endl;
    cout << "Start date: " << this->startDate;
    cout << "End date: " << this->endDate << endl;
}

string Request::to_string() {
    return this->user + "," + this->house + "," + enumToString(this->status) + "," +
           this->startDate.getDate() + "," + this->endDate.getDate();
}

ostream & operator<<(ostream & os, Request & request) {
    os << "Username: " << request.user << endl;
    os << "House: " << request.house << endl;
    os << "Status: " << request.status << endl;
    os << "Credit points: " << request.startDate << endl;
    os << "Rating: " << request.endDate << endl;
    return os;
}

//Constructor
Request::Request(const string &user, const string &house, Status status, const CustomDate &startDate,
                 const CustomDate &endDate) : user(user), house(house), status(status), startDate(startDate),
                                              endDate(endDate) {}

const string &Request::getUser() const {
    return user;
}

void Request::setUser(const string &user) {
    Request::user = user;
}

const string &Request::getHouse() const {
    return house;
}

void Request::setHouse(const string &house) {
    Request::house = house;
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
