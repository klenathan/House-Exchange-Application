//
// Created by Nathan Tran on 08/12/2022.
//

#include "House.h"

using std::cout, std::endl;

void House::showInfo() {
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Address: " << this->address << endl;
    cout << "Description: " << this->desc << endl;
    cout << "Price: " << this->price << endl;
    cout << "Required rating: " << this->requiredRating << endl;
    cout << "Owner: " << this->ownerUsername << endl;
    cout << "Date range: " << this->startDate.getDate() << " - " << this->endDate.getDate() << endl;
    std::cout << "Status: " << this->status << std::endl;
}

/**
 * Full data constructor
 * */
House::House(const string &id, const string &name, const string &address, const string &desc,
             const string &ownerUsername, long price, const CustomDate &startDate, const CustomDate &endDate,
             float requiredRating, bool status) : id(id), name(name), address(address), desc(desc),
                                                  ownerUsername(ownerUsername), price(price), startDate(startDate),
                                                  endDate(endDate), requiredRating(requiredRating), status(status) {};


/**
 * Constructor with status
 * */
House::House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
             const CustomDate &startDate, const CustomDate &endDate, float requiredRating, bool status) :
        name(name), address(address), desc(desc), ownerUsername(ownerUsername), price(price),
        startDate(startDate), endDate(endDate), requiredRating(requiredRating), status(status) {
    this->id = std::to_string(this->randomID());
}


/**
 * Constructor without status
 * */
House::House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
             const CustomDate &startDate, const CustomDate &endDate, float requiredRating) :
        name(name), address(address), desc(desc), ownerUsername(ownerUsername), price(price),
        startDate(startDate), endDate(endDate), requiredRating(requiredRating) {
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
           this->ownerUsername + "," + std::to_string(this->price) + "," +
           this->startDate.getDate() + "," + this->endDate.getDate() + "," +
           std::to_string(this->requiredRating) + "," + tempStatus;
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

