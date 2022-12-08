//
// Created by Nathan Tran on 08/12/2022.
//



#include "HouseController.h"
#include "../../Data/DataLoader/DataLoader.h"
#include "../../Model/House/House.h"

void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataLoader::loadFile("../Data/house_data.csv");

    CustomDate startTestDate = CustomDate(10, 12, 2023);
    CustomDate endTestDate = CustomDate(10, 12, 2023);
    for (vector<string> line: rawData) {
        House temp_house = House(line[0], line[1],
                                 line[3], line[2], 0,
                                 startTestDate, endTestDate,
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