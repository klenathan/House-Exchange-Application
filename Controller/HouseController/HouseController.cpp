//
// Created by Nathan Tran on 08/12/2022.
//



#include "HouseController.h"
#include "../../Data/DataLoader/DataLoader.h"
#include "../../Model/House/House.h"

void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataLoader::loadFile("../Data/house_data.csv");



    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[5]);
        CustomDate endDate = CustomDate(line[6]);
        House temp_house = House(line[0], line[1],
                                 line[3], line[2], 0,
                                 startDate, endDate,
                                 stol(line[4]), stof(line[7]));
        this->HouseArray.push_back(temp_house);
    }
}

vector<House> HouseController::getUserHouse(std::string username) {
    vector<House> result;
    for (House house: this->HouseArray) {
        if (house.getOwner() == username) result.push_back(house);
    }

    return result;
}