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
    HouseController(string path) ;

    /********************************************************************
     * Methods
     ******************************************************************/
    House getUserHouse(const std::string& username);
    void showData();

    /**
     * Create new house with House object and add it to the current data array
     * @param: House newHouse
     *
     * */

    void create(const House &newHouse);
    /**
     * Create new house by input all House attributes
     * @params: House attributes :) too lazy to add in
     * */
    void create(const string &name, const string &address, const string &desc, const string &ownerUsername, long price,
                     const CustomDate &startDate, const CustomDate &endDate, float requiredRating, float rating, bool status);

    void listNewHouse();

    House findByKey(const string &id);

    void updateByID();

    bool validDate(string dateInp);

    void destroy();

    void writeHouseData();

    const std::vector<House> &getHouseArray() const;

    void setHouseArray(const std::vector<House> &houseArray);

    /** User interactions */
    vector<House> searchForSuitableHouses(string city, CustomDate startDate, CustomDate endDate);
    void generateRequest();

};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSECONTROLLER_H
