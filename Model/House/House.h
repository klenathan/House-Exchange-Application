//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSE_H
#define HOUSEEXCHANGEAPPLICATION_HOUSE_H

#include <iostream>


#include "../CustomDate/CustomDate.h"

using std::to_string;

class House {
private:

    std::string id, name, address, desc, ownerUsername;
    long price;
    CustomDate startDate, endDate;
    float requiredRating;
    bool status;
    float rating;

public:
    /**
     * Constructor
     * */

    House() {}

    /**
     * Partial constructor
     * */
    House(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
          const CustomDate &startDate, const CustomDate &endDate, float rating, float requiredRating);

    /**
     * Full constructor for read file
     */
    House(const string &id, const string &name, const string &address, const string &desc, const string &ownerUsername,
          long price, const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status);

    /**
     * Getter-Setter
     * */


    void setStatus(bool status) {
        this->status = status;
    }

    std::string getOwner() {
        return this->ownerUsername;
    }

    const string &getId() const;

    const string &getAddress() const;

    const CustomDate &getStartDate() const;

    const CustomDate &getEndDate() const;

    float getRequiredRating() const;

    float getRating() const;

    void setRating(float rating);


    string to_string();

    /**
     * Methods
     * */

    static int randomID();

    void showInfo();
    /**
     * Destructor
     * */
//    ~House() {
//        delete this;
//    }
};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSE_H
