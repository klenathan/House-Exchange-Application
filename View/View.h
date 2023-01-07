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

#ifndef HOUSEEXCHANGEAPPLICATION_VIEW_H
#define HOUSEEXCHANGEAPPLICATION_VIEW_H

#include <iostream>
#include "../Model/User/User.h"
#include "../Model/CustomError/Errors.h"
#include "../Model/House/House.h"
#include "../Controller/HouseController/HouseController.h"
#include "../Controller/UserController/UserController.h"
#include "../Controller/RequestController/RequestController.h"
#include "../Controller/RatingController/RatingController.h"

using std::string;
using std::vector;

class View {
private:
    string dataPath;
    vector<House> HouseArray;

    HouseController HC;
    UserController UC;
    RequestController RC;
    RatingController RaC;

public:
    View() = default;

    View(string path);

    void welcomeScreen();

    void validateUser();

    void guessFunction();

    void memberFunction(User user);

    bool isNumber(const string &s);

    House requestToOccupy();

    string inputHouseRating(vector<Request> pendingArray);

    string inputUserRating(vector<Request> pendingArray);

    string takeCurrentHomeID();

    string takeRequestId(House house, vector<Request> pendingArray);

    string takeRequestId(User user, vector<Request> pendingArray);

    string *dateInput(std::string *arr);

    void renterUpdateRequestStatus();

    string cityInput();

    string requestIdInput(RequestController rc);

    void adminFunction(User admin);

    void pauseFunction();

};

#endif //HOUSEEXCHANGEAPPLICATION_VIEW_H
