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


    House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
          const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating);

    House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
          const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status);


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
