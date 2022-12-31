//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H

#include <iostream>
#include <vector>

#include "../../Model/House/House.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/User/User.h"

class HouseController {
private:
    std::vector<House> HouseArray;
    House currentUserHouse;
    string dataPath;
    void loadDataToArray();
public:
    /********************************************************************
     * Constructors
     ******************************************************************/
    HouseController() = default;
    HouseController(string path) ;

    /********************************************************************
     * Methods
     ******************************************************************/
    House getUserHouse(string username);
    void showData();
    void houseData(vector<House> houses);
    /**
     * Create new house with House object and add it to the current data array
     * @param: House newHouse
     *
     * */

    void create(const House &newHouse);

    void create(const std::string &name, const std::string &address, const std::string &desc,
                                 const std::string &ownerUsername, long price, const CustomDate &startDate,
                                 const CustomDate &endDate, float requiredRating, float rating, bool status, long consumingPoint);

    void listNewHouse(const string &username);

    void unlistHouse(const string &username);

    House findByKey(const string &id);

    void updateByID();

    void writeHouseData();

    const std::vector<House> &getHouseArray() const;

    void setHouseArray(const std::vector<House> &houseArray);

    bool houseExist(string username);

    /** User interactions */
    vector<House> searchForSuitableHouses(string city, CustomDate startDate, CustomDate endDate, User user);

    vector<House> getUserHouseVector(string username);
};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
