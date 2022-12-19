//
// Created by Nathan Tran on 08/12/2022.
//

#include "HouseController.h"
#include "../../Model/User/User.h"

#include <time.h>

using std::string, std::cout, std::endl, std::exception, std::remove;


HouseController::HouseController(string path) {
    this->dataPath = path + "./house_data.csv";
    this->loadDataToArray();
}

/******************************************************************
 * Getter-Setter
 ******************************************************************/
void HouseController::setHouseArray(const vector<House> &houseArray) {
    this->HouseArray = houseArray;
}

const vector<House> &HouseController::getHouseArray() const {
    return HouseArray;
}

/******************************************************************
 * Method implementations
 ******************************************************************/

void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[6]);
        CustomDate endDate = CustomDate(line[7]);

        House temp_house = House(line[0], line[1], line[2],
                                 line[3], line[4], stol(line[5]),
                                 startDate, endDate, stof(line[8]), stof(line[9]), (bool)stoi(line[10]), stol(line[11]));
        this->HouseArray.push_back(temp_house);
    }
}

/**
 * Get the House object of the input user's username
 * @params: string username of the desired user
 * @return: House house object of result
 * @Err: Throw not found error in the case the user does not list any house (Non existed)
 * */

House HouseController::getUserHouse(string username) {
    for (House house: this->HouseArray) {
        if (house.getOwnerUsername() == username) {
            return house;
        }
    }
    throw NotfoundErr(username + " have no house");
}



/**
 * Prompt house data from current dataState to the console
 * */

void HouseController::showData() {
    houseData(this->HouseArray);
}

void HouseController::houseData(vector<House> houses) {
    for (House house: houses) {
        cout << "-------- ID: " << house.getId() << " --------" << endl;
        house.showInfo();
        cout << endl;
    }
}

/**
 * Create new house with House object and add it to the current data array
 * @params: House newHouse
 * */
void HouseController::create(const House &newHouse) {
    this->HouseArray.push_back(newHouse);
    this->writeHouseData();
}

void HouseController::unlistHouse(const string &username) {
    for (int i = 0; i< this->HouseArray.size(); i++) {
        if (this->HouseArray[i].getOwnerUsername() == username) {
            this->HouseArray.erase(this->HouseArray.begin() + i);
            this->writeHouseData();
        }
    }
}

/**
 * Save the current state of data to file
 * */
void HouseController::writeHouseData() {
    string header = "id,name,address,desc,ownerUsername,price,startDate,endDate,requiredRating,rating,status,consumingPoint\n";
    string content = header;
    for (House house: this->HouseArray) {
        content += house.to_string() + "\n";
    }
    DataHandler::writeFile(this->dataPath, content);
}

/**
 * Create new house by input all House attributes
 * @params:
 * */
void HouseController::create(const std::string &name, const std::string &address, const std::string &desc,
                             const std::string &ownerUsername, long price, const CustomDate &startDate,
                             const CustomDate &endDate, float requiredRating, float rating, bool status, long consumingPoint) {
    House newHouse = House(name, address, desc, ownerUsername, price, startDate, endDate, requiredRating, rating, consumingPoint);
    this->HouseArray.push_back(newHouse);
}

/**
 * Find house on current dataState
 * @params: string id: the house's id on data file
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

void HouseController::listNewHouse(const string &username) {
    string houseName, address, desc, ownerUsername, startDate, endDate;
    string tempPrice, tempMinRate, tempConsumingPoint;
    float minRate;
    long price, consumingPoint;

    try {
        cout << "House title: ";
        std::getline(std::cin, houseName);

        cout << "House address (Hanoi, Hue, Saigon): ";
        std::getline(std::cin, address);


        if (address == "Hanoi" || address == "Hue" || address == "Saigon") address = address;
        else throw NotfoundErr("The application is only available to users in those cities: Ha Noi, Hue, Sai Gon.\n");

        cout << "Price (number): ";
        std::getline(std::cin, tempPrice);
        try {
            price = stol(tempPrice);
        } catch (...) {
            throw ConversionErr("PRICE_CONVERSION_ERROR");
        }

        cout << "Consuming point (number): ";
        std::getline(std::cin, tempConsumingPoint);
        try {
            consumingPoint = stol(tempConsumingPoint);
        } catch (...) {
            throw ConversionErr("CONSUMING_POINT_CONVERSION_ERROR");
        }

        cout << "Minimum rating (number): ";
        std::getline(std::cin, tempMinRate);
        try {
            minRate = std::stof(tempMinRate);
            if (-10 <= minRate && minRate <= 10) minRate = minRate;
            else throw NotfoundErr("Ratings can vary from -10 to +10");
        } catch (...) {
            throw ConversionErr("MIN_RATE_CONVERSION_ERROR");
        }


        cout << "Description: ";
        std::getline(std::cin, desc);

        cout << "Start date (dd/mm/yyyy): ";
        std::getline(std::cin, startDate);
        CustomDate start;
        if ((*new CustomDate).validDate(startDate)) {
            try {
                start = CustomDate(startDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        cout << "End date (dd/mm/yyyy): ";
        std::getline(std::cin, endDate);
        CustomDate end;
        if ((*new CustomDate).validDate(endDate)) {
            try {
                end = CustomDate(endDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        bool validDateInput = (end > start);

        if (validDateInput) {
            House *tempHouse = new House(houseName, address, desc, username, price,
                                         start, end, minRate, 0, consumingPoint);
            this->create(*tempHouse);
            DataHandler::clear();
            cout << "-------- NEW HOUSE ADDED --------" << endl;
            tempHouse->showInfo();
        } else {
            cout << "The end date must be greater than the start date!";
        }

    } catch (exception const &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;

    }
}


vector<House> HouseController::searchForSuitableHouses(string city, CustomDate startDate, CustomDate endDate, User user)  {
    long userCreditPoint = user.getCreditPoints();
    float userRatingScore = user.getRating();

    vector<House> result;
    for (House house: this->HouseArray) {
        bool suitableStartDate = (startDate >= house.getStartDate());
        bool suitableEndDate = (endDate <= house.getEndDate());

        if (house.getAddress() == city && suitableStartDate && suitableEndDate && userCreditPoint >= house.getConsumingPoint() && userRatingScore >= house.getRequiredRating()) {
            result.push_back(house);
        }
    }
    houseData(result);
    return result;
}
