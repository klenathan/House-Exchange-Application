//
// Created by Nathan Tran on 11/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H

#include <vector>
#include "../HouseController/HouseController.h"
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
    void loadDataToArray();

public:
    /**
     * Constructor
     */
    RequestController() = default;
    RequestController(string path);
    void setRequestArray(const vector<Request> &requestArray);
    /**
     * Method
     */
    void create(const Request &newReq);
    void create(const std::string &house, const std::string &name, const CustomDate &startDate,
                const CustomDate &endDate, const Status &status);

    void writeFile();
    void viewRequest(const User user, string currentPath);
    void acceptRequest(User user, const string &id, const string &currentPath);
    void request(const User user, const House house);
};

#endif //HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
