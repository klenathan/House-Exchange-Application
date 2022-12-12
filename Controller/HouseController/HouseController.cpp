//
// Created by Nathan Tran on 08/12/2022.
//

#ifdef _WIN32 || _WIN64
#include <Windows.h>
#else

#include <unistd.h>

#endif

#include "HouseController.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/House/House.h"
#include "../../Model/CustomError/Errors.h"

using std::string, std::cout, std::endl, std::exception;

HouseController::HouseController(string path) {
    this->loadDataToArray(path);
}

void HouseController::loadDataToArray(string path) {
    vector<vector<string>> rawData = DataHandler::loadFile(path + "./house_data.csv");

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
    for (House house: this->HouseArray) {
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
    House newHouse = House(name, address, desc, ownerUsername, price, startDate, endDate, requiredRating, rating,
                           status);
    this->HouseArray.push_back(newHouse);
}

void HouseController::setHouseArray(const vector<House> &houseArray) {
    this->HouseArray = houseArray;
}

const vector<House> &HouseController::getHouseArray() const {
    return HouseArray;
}


void HouseController::listNewHouse() {
    string houseName, address, desc, ownerUsername, startDate, endDate;
    string tempPrice, tempMinRate;
    float minRate;
    long price;

    try {
        cout << "House title: ";
        std::getline(std::cin, houseName);

        cout << "House address (Hanoi, Hue, Danang, HCM): ";
        std::getline(std::cin, address);

        cout << "Price (number): ";
        std::getline(std::cin, tempPrice);
        try {
            price = stol(tempPrice);
        } catch (...) {
            throw ConversionErr("PRICE_CONVERSION_ERROR");
        }


        cout << "Minimum rating (number): ";
        std::getline(std::cin, tempMinRate);
        try {
            minRate = stof(tempMinRate);
        } catch (...) {
            throw ConversionErr("MIN_RATE_CONVERSION_ERROR");
        }


        cout << "Description: ";
        std::getline(std::cin, address);

        cout << "Start date (dd/mm/yyyy): ";
        std::getline(std::cin, startDate);
        CustomDate start;
        try {
            start = CustomDate(startDate);
        } catch (...) {
            throw ConversionErr("DATE_CONVERSION_ERROR");
        }


        cout << "End date (dd/mm/yyyy): ";
        std::getline(std::cin, endDate);
        CustomDate end;
        try {
            end = CustomDate(endDate);
        } catch (...) {
            throw ConversionErr("DATE_CONVERSION_ERROR");
        }

        House *tempHouse = new House(houseName, address, desc, "admin", price,
                                     start, end, minRate, 0, true);
        this->create(*tempHouse);
        DataHandler::clear();
        cout << "-------- NEW HOUSE ADDED --------" << endl;
        tempHouse->showInfo();
    } catch (exception const &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;

    }

}


//    cout << "Hello World" << std::flush;
//    sleep(1);
//    cout << "\r" << "new   " << endl;