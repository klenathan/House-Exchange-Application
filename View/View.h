//
// Created by ADMIN on 12/15/2022.
//

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

class View {
private:
    string dataPath;
    std::vector<House> HouseArray;

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

    bool isNumber(const std::string &s);

    House requestToOccupy();

    std::string *dateInput(std::string *arr);

    std::string cityInput();

    std::string requestIdInput(RequestController rc);

    void adminFunction(User admin);

};

#endif //HOUSEEXCHANGEAPPLICATION_VIEW_H
