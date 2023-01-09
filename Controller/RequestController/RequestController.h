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

#ifndef HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H

#include <vector>
#include "../HouseController/HouseController.h"
#include "../UserController/UserController.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/Request/Request.h"
#include "../../Model/User/User.h"
#include "../../Model/House/House.h"

using std::string, std::vector;

class RequestController {
private:
    vector<Request> requestArr;
    Request currentRequest;
    string dataPath;

    HouseController *HC;
    UserController *UC;

    void loadDataToArray();

    bool dateOverlap(const CustomDate &startDate1, const CustomDate &endDate1, const CustomDate &startDate2,
                     const CustomDate &endDate2);

public:
    /********************************************************************
     * Constructors
     ******************************************************************/
    RequestController() = default;

    RequestController(string path, HouseController &HC, UserController &UC);

    /********************************************************************
     * Getter Setter
     ******************************************************************/

    vector<Request> getHouseForRating(const User &user);

    vector<Request> getOccupierUsername(const string &homeID);

    const vector<Request> &getRequestArr() const;

    /********************************************************************
     * Methods
     ******************************************************************/
    void create(const Request &newReq);

    void writeFile();

    bool viewRequest(const User &user);

    void viewSentRequest(const User &user);

    void acceptRequest(const string &id, const User &user);

    void request(const User &user, const House &house);

};

#endif //HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
