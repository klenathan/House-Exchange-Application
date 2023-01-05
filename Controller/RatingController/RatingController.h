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

using std::cout, std::endl, std::string, std::getline, std::cin, std::cerr, std::stof;

class RatingController {
private:
    vector<Rating> ratingArray;
//    User currentUser;
    string dataPath;

    /**
     * Data loader
     */
    void loadDataToRatingArray(vector<Request> requestArray);
public:
    RatingController() = default;
    RatingController(string path, vector<Request> requestArray);


    void rating(Request request, string decision);
    bool ratingValid(string decision, string id);

    void writeFile();

    vector<User> calculateAverageRating(vector<User> userArray);
    vector<House> calculateAverageRating(vector<House> houseArray);

};


#endif //HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
