//
// Created by phamv on 1/4/2023.
//

#ifndef HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/Rating/Rating.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/User/User.h"
#include "../UserController/UserController.h"
#include "../HouseController/HouseController.h"


using std::cout, std::endl, std::string, std::getline, std::cin, std::cerr, std::stof;

class RatingController {
private:
    vector<Rating> ratingArray;
    string dataPath;
    UserController UC;
    HouseController HC;
    /**
     * Data loader
     */
    void loadDataToRatingArray(vector<Request> requestArray);
public:
    RatingController() = default;
    RatingController(string path, vector<Request> requestArray, UserController UC, HouseController HC);

    void rating(Request request, string decision);
    bool ratingValid(string decision, string id);
    void calculateAverageRating(User user);
    void calculateAverageRating(House house);

    void writeFile();


};


#endif //HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
