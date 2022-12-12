//
// Created by Nathan Tran on 08/12/2022.
//

#include "House.h"

using std::cout, std::endl;

void House::showInfo() {
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
             const string &ownerUsername, long price,
             const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status)
        : id(id), name(name), address(address), desc(desc), ownerUsername(ownerUsername), price(price), startDate(startDate),
          endDate(endDate), requiredRating(requiredRating), rating(rating), status(status) {}

/**
 * Constructor without status
 * */
House::House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
             const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating) :
        name(name), address(address), desc(desc), ownerUsername(ownerUsername), price(price),
        startDate(startDate), endDate(endDate), requiredRating(requiredRating), rating(rating) {
    this->id = std::to_string(this->randomID());
}

int House::randomID() {
    srand((unsigned) time(NULL));
    return std::rand() % 10000 + 100;;
}

const string &House::getId() const {
    return id;
};
