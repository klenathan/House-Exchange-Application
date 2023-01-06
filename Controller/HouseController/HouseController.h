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

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H

#include <iostream>
#include <vector>

#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/User/User.h"
#include "../../Model/House/House.h"

class HouseController {
private:
    std::vector<House> HouseArray;
    House currentUserHouse;
    string dataPath;

    /********************************************************************
     * Methods
     ******************************************************************/
    void loadDataToArray();

    bool listedHouseCheck(const string &username);

public:
    /********************************************************************
     * Constructors
     ******************************************************************/
    HouseController() = default;

    HouseController(string path);

    /********************************************************************
     * Getter Setter
     ******************************************************************/
    const std::vector<House> &getHouseArray() const;

    House getUserHouse(const string &username);

    /********************************************************************
     * Methods
     ******************************************************************/

    void showData();

    void houseData(vector<House> houses);

    void showUserHouse(const string &username);

    bool houseExist(const string &username);

    void create(const House &newHouse);

    void writeHouseData();

    House findByKey(const string &id);

    void updateHouseRating (House house, float averageRating);

    /** User interactions */
    void listNewHouse(const string &username);

    void unlistHouse(const string &username);

    void enableHouseListing(const string &username);

    vector<House> searchForSuitableHouses(string city, CustomDate startDate, CustomDate endDate, User user);

    vector<House> allAvailableHouse();

    };

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
