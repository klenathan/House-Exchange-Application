//
// Created by Nathan Tran on 08/12/2022.
//

#include "House.h"



void House::showInfo() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Address: " << this->address << std::endl;
    std::cout << "Description: " << this->desc << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Required rating: " << this->requiredRating << std::endl;
    std::cout << "Owner: " << this->ownerUsername << std::endl;
    std::cout << "Date range: " << this->startDate.getDate() << " - " << this->endDate.getDate() << std::endl;
//        std::cout << "Status: " << this->status << std::endl;
}