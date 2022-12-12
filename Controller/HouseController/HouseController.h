//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H

#include <iostream>
#include <vector>

#include "../../Model/House/House.h"

class HouseController {
private:
    std::vector<House> HouseArray;
    House currentUserHouse;
    void loadDataToArray(string path);
public:
    /**
     * Constructors
     * */
    HouseController(string path);

    /**
     * Methods
     * */
    std::vector<House> getUserHouse(const std::string& username);
    void showData();

    /**
     * Create new house with House object and add it to the current data array
     * @param: House newHouse
     *
     * */
    void create(const House &newHouse);
    /**
     * Create new house by input all House attributes
     * @params: House attributes :) too lazy to add in
     * */
    void create(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
                     const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status);

    void listNewHouse();

    House findByKey(const string &id);

    void update();

    void destroy();

    const std::vector<House> &getHouseArray() const;

    void setHouseArray(const std::vector<House> &houseArray);

};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
