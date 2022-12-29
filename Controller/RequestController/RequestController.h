//
// Created by Nathan Tran on 11/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H

#include <vector>
#include "../HouseController/HouseController.h"
#include "../UserController/UserController.h"
#include "../../Model/Request/Request.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/User/User.h"
#include "../../Model/House/House.h"

using std::string, std::vector;

class RequestController {
private:
    vector<Request> requestArr;
    Request currentRequest;
    string dataPath;

    HouseController HC;
    UserController UC;

    void loadDataToArray();

public:
    /**
     * Constructor
     */
    RequestController() = default;

    RequestController(string path, HouseController HC, UserController UC);

    void setRequestArray(const vector<Request> &requestArray);

    /**
     * Method
     */
    void create(const Request &newReq);

//    void create(const std::string &house, const std::string &name, const CustomDate &startDate,
//                const CustomDate &endDate, const Status &status);

    void writeFile();

    void viewRequest(const User user);

    void acceptRequest(User user, const string &id, HouseController houseController);

    void request(const User user, const House house);

    string getHouseForRating(const User user);

    string getOccupierUsername(const House house);
};

#endif //HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
