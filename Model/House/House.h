//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSE_H
#define HOUSEEXCHANGEAPPLICATION_HOUSE_H

#include <iostream>

#include "../CustomDate/CustomDate.h"


class House {
private:
    std::string name, address, desc, ownerUsername;
    long price;
    CustomDate startDate, endDate;
    float requiredRating;
    float rating;
    bool status;
public:
    /**
     * Constructor
     * */

    House() {}

    House(std::string name, std::string address, std::string ownerUsername, std::string desc,
          float requiredRating,
          CustomDate startDate,
          CustomDate endDate,
          long price,
          float rating
    ) {
        this->name = name;
        this->address = address;
        this->ownerUsername = ownerUsername;
        this->desc = desc;
        this->requiredRating = requiredRating;
        this->startDate = startDate;
        this->endDate = endDate;
        this->price = price;
        this->status = false;
    }

    House(std::string name, std::string address, std::string ownerUsername,
          std::string desc,
          CustomDate startDate,
          CustomDate endDate,
          long price, float rating, bool status) {
        this->name = name;
        this->address = address;
        this->ownerUsername = ownerUsername;
        this->desc = desc;
        this->startDate = startDate;
        this->endDate = endDate;
        this->price = price;
        this->status = status;
    }

    /**
     * Getter-Setter
     * */

    void setStatus(bool status) {
        this->status = status;
    }

    std::string getOwner() {
        return this->ownerUsername;
    }

    /**
     * Methods
     * */

    void showInfo();
    /**
     * Destructor
     * */
//    ~House() {
//        delete this;
//    }
};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSE_H
