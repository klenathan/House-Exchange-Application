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
public:
    HouseController(){
        this->loadDataToArray();
    }

    void loadDataToArray();

    std::vector<House> getUserHouse(std::string username);



};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
