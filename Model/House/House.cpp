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
//        std::cout << "Status: " << this->status << std::endl;
}