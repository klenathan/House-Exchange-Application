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
    void loadDataToArray();
public:
    HouseController();

    std::vector<House> getUserHouse(const std::string& username);

    void showData();

    void create(const House &newHouse);
    void create(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
                     const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status);;

    void findByKey();

    void update();

    void destroy();

    const std::vector<House> &getHouseArray() const;

    void setHouseArray(const std::vector<House> &houseArray);

};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
