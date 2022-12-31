//
// Created by phamv on 12/13/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H

#include <vector>
#include <map>
#include <algorithm>
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
    User currentUser;

    string dataPath;

    void loadDataToUserRatingArray();

    void loadDataToHouseRatingArray();

public:
    /**
     * Constructors
     */
    RatingController() = default;

    RatingController(string path);

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

    /**
     * Rating method
     */
    void rating(const House &house); // Rating for house

    void rating(User user); // Rating for user

    /**
     * Calculate average rating
     */
    vector<User> ratingAverage(vector<User> &userArray);

    vector<House> ratingAverage(vector<House> &houseArray);


};


#endif //HOUSEEXCHANGEAPPLICATION_RATINGCONTROLLER_H
