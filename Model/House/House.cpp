//
// Created by Nathan Tran on 08/12/2022.
//

#include "House.h"

using std::cout, std::endl;

void House::showInfo() {
    cout << "ID:" << this->id << endl;
    cout << "Name:" << this->name << endl;
    cout << "Address:" << this->address << endl;
    cout << "Description:" << this->desc << endl;
    cout << "Required rating:" << this->requiredRating << endl;
    cout << "Owner:" << this->ownerUsername << endl;
    cout << "Date range:" << this->startDate.getDate() << " - " << this->endDate.getDate() << endl;
    cout << "Rating:" << this->rating << endl;
    cout << "Status:" << this->status << endl;
    cout << "Consuming point/day:" << this->consumingPoint << endl;
}

/**
 * Full data constructor
 * */
House::House(const string &id, const string &name, const string &address, const string &desc,
             const string &ownerUsername, const CustomDate &startDate,
             const CustomDate &endDate, float requiredRating, float rating, bool status, long consumingPoint) : id(id), name(name),
                                                                                           address(address), desc(desc),
                                                                                           ownerUsername(ownerUsername),
                                                                                           startDate(startDate), endDate(endDate), requiredRating(requiredRating), rating(rating),
                                                                                           status(status), consumingPoint(consumingPoint) {}
/**
 * Constructor without status
 * */
House::House(const string &name, const string &address, const string &desc,
             const string &ownerUsername, const CustomDate &startDate,
             const CustomDate &endDate, float requiredRating, float rating, long consumingPoint) : name(name),
                                                                                                address(address), desc(desc),
                                                                                                ownerUsername(ownerUsername),
                                                                                                startDate(startDate), endDate(endDate), requiredRating(requiredRating), rating(rating),
                                                                                                consumingPoint(consumingPoint) {
    this->id = std::to_string(this->randomID());
}

int House::randomID() {
    srand((unsigned) time(NULL));
    return std::rand() % 10000 + 100;;
}

string House::to_string() {
    string tempStatus = this->status ? "1" : "0";
    return this->id + "," + this->name + "," + this->address + "," +
           this->desc + "," +
           this->ownerUsername + "," +
           this->startDate.getDate() + "," + this->endDate.getDate() + "," +
           std::to_string(this->requiredRating) + "," +
           std::to_string(this->rating) + "," + tempStatus + "," + std::to_string(this->consumingPoint);
}

const string &House::getId() const {
    return id;
}

const string &House::getAddress() const {
    return address;
}

const CustomDate &House::getStartDate() const {
    return startDate;
}

const CustomDate &House::getEndDate() const {
    return endDate;
}

float House::getRequiredRating() const {
    return requiredRating;
}

float House::getRating() const {
    return rating;
}

void House::setRating(float rating) {
    House::rating = rating;
}

long House::getConsumingPoint() const {
    return consumingPoint;
}

void House::setConsumingPoint(long consumingPoint) {
    House::consumingPoint = consumingPoint;
}

void House::setId(const string &id) {
    House::id = id;
}

const string &House::getName() const {
    return name;
}

void House::setName(const string &name) {
    House::name = name;
}

void House::setAddress(const string &address) {
    House::address = address;
}

const string &House::getDesc() const {
    return desc;
}

void House::setDesc(const string &desc) {
    House::desc = desc;
}

const string &House::getOwnerUsername() const {
    return ownerUsername;
}

void House::setOwnerUsername(const string &ownerUsername) {
    House::ownerUsername = ownerUsername;
}


void House::setStartDate(const CustomDate &startDate) {
    House::startDate = startDate;
}

void House::setEndDate(const CustomDate &endDate) {
    House::endDate = endDate;
}

void House::setRequiredRating(float requiredRating) {
    House::requiredRating = requiredRating;
}

bool House::isStatus() const {
    return status;
}

void House::setStatus(bool status) {
    House::status = status;
}


