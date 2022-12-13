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
    this->dataPath = path + "./house_data.csv";
    this->loadDataToArray();

}

/**
 * Getter-Setter
 * */
void HouseController::setHouseArray(const vector<House> &houseArray) {
    this->HouseArray = houseArray;
}

const vector<House> &HouseController::getHouseArray() const {
    return HouseArray;
}

/**
 * Method implementations
 * */

void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[6]);
        CustomDate endDate = CustomDate(line[7]);

        House temp_house = House(line[0], line[1], line[2],
                                 line[3], line[4], stol(line[5]),
                                 startDate, endDate, 7, stof(line[8]), 1);
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

/**
 * Prompt house data from current dataState to the console
 * */
void HouseController::showData() {
    for (House house: this->HouseArray) {
        cout << "-------- ID: " << house.getId() << " --------" << endl;
        house.showInfo();
        cout << endl;
    }
}

/**
 * Create new house with House object and add it to the current data array
 * @param: House newHouse
 *
 * */
void HouseController::create(const House &newHouse) {
    this->HouseArray.push_back(newHouse);
    this->writeHouseData();
}


/**
 * Save the current state of data to file
 * */
void HouseController::writeHouseData() {
    string header = "id,name,address,desc,ownerUsername,price,startDate,endDate,rating,status\n";
    string content = header;
    for (House house: this->HouseArray) {
        content += house.to_string() + "\n";
    }
    DataHandler::writeFile(this->dataPath, content);
}

/**
 * Create new house by input all House attributes
 * @params: House attributes :) too lazy to add in
 * */
void HouseController::create(const std::string &name, const std::string &address, const std::string &desc,
                             const std::string &ownerUsername, long price, const CustomDate &startDate,
                             const CustomDate &endDate, float requiredRating, float rating, bool status) {
    House newHouse = House(name, address, desc, ownerUsername, price, startDate, endDate, requiredRating, rating);
    this->HouseArray.push_back(newHouse);
}

/**
 * Find house on current dataState
 * @param: string id: the house's id on data file
 * @return: object House with input id
 * */
House HouseController::findByKey(const std::string &id) {
    for (House house: this->HouseArray) {
        if (house.getId() == id) {
            return house;
        }
    }
}

void HouseController::updateByID() {
    cout << "Not yet implemented";
}

/**
 * The function gathers new House information from User and update the current data state within the program
 * and also trigger write to file function to update the data state on the .csv file
 *
 * @Err: The functions might throw some invalid format errors upon user inputs the data
 * */

void HouseController::listNewHouse() {
    string houseName, address, desc, ownerUsername, startDate, endDate;
    string tempPrice, tempMinRate;
    float minRate;
    long price;

    try {
        cout << "House title: ";
        std::getline(std::cin, houseName);

        cout << "House address (HN, HUE, DN, HCM): ";
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
        std::getline(std::cin, desc);

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
                                     start, end, minRate, 0);
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