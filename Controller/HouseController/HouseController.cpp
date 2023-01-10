/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Assessment: 3
  Author:
      s3891890, Tran Nam Thai
      s3878246, Pham Anh Thu
      s3891968, Pham Vo Dong
      s3927201, Tran Ngoc Khang
  Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to check)
  Created  date: 11/12/2022
  Acknowledgement: None
*/

#include "HouseController.h"

using std::string, std::cout, std::endl, std::exception, std::remove, std::cin;

/**
 * House constructor
 * @param path
 */
HouseController::HouseController(string path) {
    this->dataPath = path + "./house_data.csv";
    this->loadDataToArray();
}

/******************************************************************
 * Getter-Setter
 ******************************************************************/
 /**
  * Get house array
  * @return HouseArray
  */
const vector<House> &HouseController::getHouseArray() const {
    return HouseArray;
}

/**
 * Get the House object of the input user's username
 * @params: string username of the desired user
 * @return: House house object of result
 * @Err: Throw not found error in the case the user does not list any house (Non existed)
 * */
House HouseController::getUserHouse(const string &username) {
    for (House house: this->HouseArray) {
        if (house.getOwnerUsername() == username) {
            return house;
        }
    }
    throw NotfoundErr(username + " has no house!");
}

/******************************************************************
 * Method implementations
 ******************************************************************/

/**
 * Load Data
 */
void HouseController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[5]);
        CustomDate endDate = CustomDate(line[6]);

        House temp_house = House(line[0], line[1], line[2],
                                 line[3], line[4],
                                 startDate, endDate, stof(line[7]), stof(line[8]), (bool) stoi(line[9]),
                                 stol(line[10]));
        this->HouseArray.push_back(temp_house);
    }
}

/**
 * Prompt house data from current dataState to the console
 * */
void HouseController::showData() {
    houseData(this->HouseArray);
}

/**
 * Show house data
 * @param houses
 */
void HouseController::houseData(vector<House> houses) {
    for (House house: houses) {
        cout << "-------- ID: " << house.getId() << " --------" << endl;
        house.showInfo();
        cout << endl;
    }
}



/**
 * Show info of user house using username input
 * @param username
 */
void HouseController::showUserHouse(const string &username) {
    House h = getUserHouse(username);
    h.showInfo();
}

/**
 *
 * Check house existent
 * @param username
 * @return true if user house exists, otherwise false
 */
bool HouseController::houseExist(const string &username) {
    for (House house: this->HouseArray) {
        if (house.getOwnerUsername() == username && house.isStatus()) {
            return true;
        }
    }
    return false;
}

/**
 * Check house existent but in off state
 * @param username
 * @return true if user house exists, otherwise false
 */
bool HouseController::houseExistButDisable(const string &username) {
    for (House house: this->HouseArray) {
        if (house.getOwnerUsername() == username && !house.isStatus()) {
            return true;
        }
    }
    return false;
}

/**
 * Create new house with House object and add it to the current data array
 * @params: House newHouse
 * */
void HouseController::create(const House &newHouse) {
    this->HouseArray.push_back(newHouse);
    this->writeHouseData();
}

/**
 * Unlist a house
 * @param username
 */
void HouseController::unlistHouse(const string &username) {
    for (House &house: this->HouseArray) {
        if ((house.getOwnerUsername() == username) && house.isStatus()) {

            if ((house.getStartDate() <= CustomDate::getToday()) && (house.getEndDate() >= CustomDate::getToday())) {
                cout << "The house is in renting period and cannot be unlisted" << endl;
            } else if (house.isStatus()) {
                house.setStatus(0);
                this->writeHouseData();
                cout << "Successfully unlisted the house " << house.getId() << "!\n";
            }
        } else if ((house.getOwnerUsername() == username) && (!house.isStatus())) {
            cout << "House " << house.getId() << " of owner " << house.getOwnerUsername() << " is already unlisted"
                 << endl;
        }
    }
}

/**
 * @brief: re-enable house from unlisted status, and re-new listing period
 * The function loops through the data array twice to check if is there any current listed house then process
 * to update the data
 * @param username - house owner's username
 */
void HouseController::enableHouseListing(const string &username) {
    bool houseExist = 0;
    for (House &house: this->HouseArray) {
        if ((house.getOwnerUsername() == username) && house.isStatus()) {
            cout << "House " << house.getId() << " of owner " << house.getOwnerUsername()
                 << " is already being listed"
                 << endl;
            houseExist = 1;
            break;
        } else if ((house.getOwnerUsername() == username) && (!house.isStatus())) {
            /**
             * Data input
             * */
            houseExist = 1;
            string startDateStr, endDateStr;
            CustomDate startDate, endDate;
            house.showInfo();
            cout << "Please input new start date (dd/mm/yyyy): ";
            cin >> startDateStr;
            startDate = *new CustomDate(startDateStr);

            cout << "Please input new end date (dd/mm/yyyy): ";
            cin >> endDateStr;
            endDate = *new CustomDate(endDateStr);



            /**
             * Validate input date
             * */
            if (endDate <= startDate) {
                cout << "End date has to be later than start date" << endl;
                break;
            } else if (startDate < CustomDate::getToday()) {
                cout << "Start date has to be today or in the future" << endl;
                break;
            }

            /**
             * Update house data & write to file
             * */
            house.setStartDate(startDate);
            house.setEndDate(endDate);
            house.setStatus(true);
            this->writeHouseData();
            break;
        }
    }

    if (!houseExist) {
        this->listNewHouse(username);
    }
}

/**
 * Save the current state of data to file
 * */
void HouseController::writeHouseData() {
    string header = "id,name,address,desc,ownerUsername,startDate,endDate,requiredRating,rating,status,consumingPoint\n";
    string content = header;
    for (House house: this->HouseArray) {
        content += house.to_string() + "\n";
    }
    DataHandler::writeFile(this->dataPath, content);
}

/**
 * Find house on current dataState
 * @params: string id: the house's id on data file
 * @return: object House with input id
 * @Err: Throw not found error in the case the house id is not found
 * */
House HouseController::findByKey(const string &id) {
    for (House house: this->HouseArray) {
        if (house.getId() == id) {
            return house;
        }
    }
    throw NotfoundErr("HOUSE_" + id + "_NOT_FOUND\n");
}

/**
 * Update house rating
 * @param house
 * @param averageRating
 */
void HouseController::updateHouseRating (House house, float averageRating) {
    for (House &house1: this->HouseArray) {
        if (house.getId() == house1.getId()) {
           house1.setRating(averageRating);
            this->writeHouseData();
        }
    }
}

/**
 * The function gathers new House information from User and update the current data state within the program
 * and also trigger write to file function to update the data state on the .csv file
 * @param username
 * @Err: The functions might throw some invalid format errors upon user inputs the data
 */
void HouseController::listNewHouse(const string &username) {
    string houseName, address, desc, ownerUsername, startDate, endDate;
    string tempMinRate, tempConsumingPoint;
    float minRate;
    long consumingPoint;

    try {

        //// Get user's input of the house's details
        cout << "House title:";
        getline(cin, houseName);

        cout << "House address (Hanoi, Hue, Saigon):";
        getline(cin, address);

        if (address == "Hanoi" || address == "Hue" || address == "Saigon") address = address;
        else throw NotfoundErr("The application is only available to users in those cities: Ha Noi, Hue, Sai Gon.\n");

        cout << "Consuming point (number):";
        getline(cin, tempConsumingPoint);
        try {
            consumingPoint = stol(tempConsumingPoint);
        } catch (...) {
            throw ConversionErr("CONSUMING_POINT_CONVERSION_ERROR");
        }

        cout << "Minimum rating (number):";
        getline(cin, tempMinRate);
        try {
            minRate = stof(tempMinRate);
            if (-10 <= minRate && minRate <= 10) minRate = minRate;
            else throw NotfoundErr("Ratings can vary from -10 to +10\n");
        } catch (...) {
            throw ConversionErr("MIN_RATE_CONVERSION_ERROR");
        }

        cout << "Description:";
        getline(cin, desc);

        cout << "Start date (dd/mm/yyyy):";
        getline(cin, startDate);
        CustomDate start;
        if (CustomDate::validDate(startDate)) {
            try {
                start = CustomDate(startDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        cout << "End date (dd/mm/yyyy):";
        getline(cin, endDate);
        CustomDate end;
        if (CustomDate::validDate(endDate)) {
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
            House *tempHouse = new House(houseName, address, desc, username,
                                         start, end, minRate, 0, consumingPoint);
            this->create(*tempHouse);
            DataHandler::clear();
            cout << "-------- NEW HOUSE ADDED --------" << endl;
            tempHouse->showInfo();
        } else {
            cout << "The end date must be greater than the start date!\n";
        }

    } catch (exception const &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
        cout << "Press \"Enter\" to continue ... " << endl;
        cin.ignore();
    }
}

/**
 * Search for suitable house for occupying
 * @param city
 * @param startDate
 * @param endDate
 * @param user
 * @return
 */
vector<House>
HouseController::searchForSuitableHouses(string city, CustomDate startDate, CustomDate endDate, User user) {
    long userCreditPoint = user.getCreditPoints();
    float userRatingScore = user.getRating();

    bool satisfied;

    vector<House> result;
    for (House house: this->HouseArray) {

        bool suitableStartDate = (startDate >= house.getStartDate());
        bool suitableEndDate = (endDate <= house.getEndDate());

        satisfied = (
                (house.getAddress() == city)
                && suitableStartDate
                && suitableEndDate
                && (userCreditPoint >= house.getConsumingPoint())
                && (userRatingScore >= house.getRequiredRating())
                && house.isStatus()
        );

        if (satisfied) {
            result.push_back(house);
        }
    }
    return result;
}

/**
 * Return all houses in the system with start date later than CustomDate::getToday()
 * @return: :vector<House> a vector of result house
 * */
vector<House> HouseController::allAvailableHouse() {
    vector<House> result;
    for (House house: this->HouseArray) {
        if (house.getStartDate() > CustomDate::getToday() && house.isStatus()) {
            result.push_back(house);
            cout << "---------- ID:" << house.getId() << " ----------" << endl;
            house.showInfo();
        }
    }
    cout << endl;
    return result;
}
