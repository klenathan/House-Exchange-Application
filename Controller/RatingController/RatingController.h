//
// Created by phamv on 12/13/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/HouseRating/HouseRating.h"
#include "../../Model/UserRating/UserRating.h"
#include "../../Model/House/House.h"
#include "../../Model/User/User.h"
#include "../../Model/CustomError/Errors.h"


using std::cout, std::endl, std::string, std::getline, std::cin, std::cerr;

class RatingController {
private:
    vector<HouseRating> houseRatingArray;
    vector<UserRating> userRatingArray;
//    vector<string> ratingArray;
    User currentUser;

    string dataPath;

    void loadDataToUserRatingArray(vector<Request> requestArray);

    void loadDataToHouseRatingArray(vector<Request> requestArray);


public:
    /**
     * Constructors
     */
    RatingController() = default;

    RatingController(string path, vector<Request> requestArray);

    /**
     * Getter Setter
     */
    const User &getCurrentUser() const;

    void setCurrentUser(const User &currentUser);


    /**
     * Methods
     */
    void houseRatingWriteFile();

    void userRatingWriteFile();

    void writeFile();

    /**
     * Rating method
     */
    void rating(Request request); // Rating for house

    void rating(const User& user, const string& requestID, const string& homeID); // Rating for user

    /**
     * Calculate average rating
     */
    vector<User> ratingAverage(vector<User> &userArray);

    vector<House> ratingAverage(vector<House> &houseArray);

    string getRatingWriteFormat();


};


#endif //HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
