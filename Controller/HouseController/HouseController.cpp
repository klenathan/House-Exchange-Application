//
// Created by Nathan Tran on 08/12/2022.
//



#include "HouseController.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/House/House.h"

using std::string, std::cout, std::endl;

HouseController::HouseController() {
    this->loadDataToArray();
}

void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile("../Data/house_data.csv");

    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[5]);
        CustomDate endDate = CustomDate(line[6]);
        House temp_house = House(line[0], line[1],
                                 line[2], line[3], stol(line[4]),
                                 startDate, endDate,
                                 stol(line[4]), stof(line[7]));
        this->HouseArray.push_back(temp_house);
    }
}

vector<House> HouseController::getUserHouse(const std::string &username) {
    vector<House> result;
    for (House house: this->HouseArray) {
        if (house.getOwner() == username) result.push_back(house);
    }

    return result;
}

void HouseController::showData() {
    int counter = 0;
    for(House house: this->HouseArray) {
        cout << "-------- index: " << counter << " --------" << endl;
        house.showInfo();
        cout << endl;
        counter++;
    }
}

void HouseController::create(const House &newHouse) {
    this->HouseArray.push_back(newHouse);
}

void HouseController::create(const std::string &name, const std::string &address, const std::string &desc,
                             const std::string &ownerUsername, long price, const CustomDate &startDate,
                             const CustomDate &endDate, float requiredRating, float rating, bool status) {
    House newHouse = House(name, address, desc, ownerUsername, price, startDate, endDate, requiredRating, rating, status);
    this->HouseArray.push_back(newHouse);
}

void HouseController::setHouseArray(const vector<House> &houseArray) {
    this->HouseArray = houseArray;
}

const vector<House> &HouseController::getHouseArray() const {
    return HouseArray;
}
