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
    bool dateOverlap(const CustomDate &startDate1, const CustomDate &endDate1, const CustomDate &startDate2,
                const CustomDate &endDate2);
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


    void writeFile();

    bool viewRequest(const User &user);

    void viewSentRequest(const User &user);

    void acceptRequest(const string &id, const User &user);

    void request(const User &user, const House & house);

    vector<Request> getHouseForRating(const User user);

    vector<Request> getOccupierUsername(string homeID);

    const vector<Request> &getRequestArr() const;

    bool requestExist(const User user);

    bool updateRequestStatusToFinish(const string &requestid);

};

#endif //HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
