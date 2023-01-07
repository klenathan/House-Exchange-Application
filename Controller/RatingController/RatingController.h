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

#ifndef HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/CustomError/Errors.h"
#include "../../Model/Rating/Rating.h"
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

    /********************************************************************
     * Methods
     ******************************************************************/
    void loadDataToRatingArray(vector<Request> requestArray);
public:
    /********************************************************************
     * Constructors
     ******************************************************************/
    RatingController() = default;

    RatingController(string path, vector<Request> requestArray, UserController UC, HouseController HC);

    /********************************************************************
     * Methods
     ******************************************************************/
    void writeFile();

    void rating(const Request &request, const string &decision);

    bool ratingValid(string decision, string id);

    void calculateAverageRating(User user);

    void calculateAverageRating(House house);

};


#endif //HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
