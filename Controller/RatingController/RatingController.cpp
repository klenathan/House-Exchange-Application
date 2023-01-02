//
// Created by phamv on 12/13/2022.
//
#include "RatingController.h"


/**
 * Rating constructor
 * @param path
 */
RatingController::RatingController(string path) {
    this->dataPath = path;
    this->loadDataToUserRatingArray();
    this->loadDataToHouseRatingArray();
}

/**
 * Getter Setter
 */
const User &RatingController::getCurrentUser() const {
    return currentUser;
}

void RatingController::setCurrentUser(const User &currentUser) {
    RatingController::currentUser = currentUser;
}

/**
 * Store data to the user rating array
 */
void RatingController::loadDataToUserRatingArray() {

    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath + "./user_rating_data.csv");
    for (vector<string> line: rawData) {
        UserRating temp_user_rating = UserRating(line[0],
                                                 line[1], std::stol(line[2]),
                                                 line[3]);

        this->userRatingArray.push_back(temp_user_rating);

    }

}

/**
 * Store data to the house rating array
 */
void RatingController::loadDataToHouseRatingArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath + "./house_rating_data.csv");

    for (vector<string> line: rawData) {
        HouseRating temp_house_rating = HouseRating(line[0],
                                                    line[1], std::stol(line[2]),
                                                    line[3]);

        this->houseRatingArray.push_back(temp_house_rating);
    }
}

/**
 * Write house rating data to file
 */
void RatingController::houseRatingWriteFile() {
    string content;
    content += "houseID,username,ratingScore,comment\n";
    for (HouseRating houseRating: this->houseRatingArray) {
        content += houseRating.getHouseRatingWriteFormat() + "\n";
    }

    cout << DataHandler::writeFile("./house_rating_data.csv", content);
}

/**
 * Write user rating data to file
 */
void RatingController::userRatingWriteFile() {
    string content;
    content += "username,houseID,ratingScore,comment\n";
    for (UserRating userRating: this->userRatingArray) {
        content += userRating.getUserRatingWriteFormat() + "\n";
    }

    cout << DataHandler::writeFile("./user_rating_data.csv", content);

}


void RatingController::rating(const House &house) {
    string tempRatingScore;
    float ratingScore;
    string comment;
    const string &houseId = house.getId();
    string username = this->currentUser.getUsername();

    bool check = true;

    // Display message for feedback
    try {
        cout << "Welcome to feedback site\nNow you have permission for feedback about Houses\n";

        while (check) {
            try {
                cout << "Please input your rating score in the scale -10 to 10: ";
                getline(cin, tempRatingScore);
                ratingScore = std::stof(tempRatingScore);
                try {
                    if (ratingScore <= -11 || ratingScore >= 11) {
                        throw ratingScore;
                    } else {
                        check = false;
                    }
                } catch (...) {
                    cout << ratingScore << " Out of scale\n";
                    check = true;

                }
            } catch (...) {
                cout << tempRatingScore << " Invalid input!\n";
                check = true;
            }

        }

        cout << "Please give your comment: \n";
        getline(cin, comment);

        // Save to house_rating_data.csv
        HouseRating *newHouseRatting = new HouseRating(houseId, username, ratingScore, comment);
        this->houseRatingArray.push_back(*newHouseRatting);
        houseRatingWriteFile();

        delete newHouseRatting;
    } catch (std::exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
        std::cin.ignore();
    }

}

/**
 * Rating method for house owner rate user who rented their house
 * @param user which is rated by house owner
 */
void RatingController::rating(User user) {
    string username = user.getUsername();
    string homeID;
    string tempRatingScore;
    float ratingScore;
    string comment;

    bool check = true;

    try {
        //Rating Process
        cout << "Welcome to feedback site\nNow you have permission for feedback about occupier\n";

        while (check) {
            try {
                cout << "Please input your rating score in the scale -10 to 10: ";
                getline(cin, tempRatingScore);
                ratingScore = std::stof(tempRatingScore);
                try {
                    if (ratingScore <= -11 || ratingScore >= 11) {
                        throw ratingScore;
                    } else {
                        check = false;
                    }
                } catch (...) {
                    cout << ratingScore << " Out of scale\n";
                    check = true;

                }
            } catch (...) {
                cout << tempRatingScore << " Invalid input!\n";
                check = true;
            }

        }

        cout << "Please give your comment: \n";
        getline(cin, comment);

        // Save to house_rating_data.csv
        UserRating *newUserRating = new UserRating(username, homeID, ratingScore, comment);
        this->userRatingArray.push_back(*newUserRating);
        userRatingWriteFile();

        delete newUserRating;


    } catch (std::exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
    }
}

bool compareUser(UserRating user1, UserRating user2) {
    return (user1.getUsername() < user2.getUsername());
}

bool compareHouse(HouseRating house1, HouseRating house2) {
    return (house1.getHomeId() < house1.getHomeId());
}

vector<User> RatingController::ratingAverage(vector<User> &userArray) {
    std::map<string, float> userRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;
    string tempUSerName;


    std::sort(this->userRatingArray.begin(), this->userRatingArray.end(), compareUser);
    for (const UserRating &user: this->userRatingArray) {
        if (tempUSerName != user.getUsername()) {

            count = 1;
            tempUSerName = user.getUsername();
            tempRating = user.getRatingScore();
        } else {
            count++;
            tempRating += user.getRatingScore();
        }


        if (count != 0) {
            tempAverage = tempRating / count;
            userRating.insert(std::make_pair(tempUSerName, tempAverage));
            iterator = userRating.find(tempUSerName);
            if (iterator != userRating.end()) {
                iterator->second = tempAverage;
            }
        }
    }


    for (iterator = userRating.begin(); iterator != userRating.end(); iterator++) {

        for (User &user: userArray) {
            if (user.getUsername() == iterator->first) {
                float finalRating = (user.getRating() + iterator->second) / 2;

                user.setRating(finalRating);
            }
        }
    }



    return userArray;
}

vector<House> RatingController::ratingAverage(vector<House> &houseArray) {
    std::map<string, float> houseRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;
    string tempHomeId;


    std::sort(houseRatingArray.begin(), houseRatingArray.end(), compareHouse);
    for (const HouseRating &house: this->houseRatingArray) {
        if (tempHomeId != house.getHomeId()) {

            count = 1;
            tempHomeId = house.getHomeId();
            tempRating = house.getRatingScore();
        } else {
            count++;
            tempRating += house.getRatingScore();
        }


        if (count != 0) {
            tempAverage = tempRating / count;
            houseRating.insert(std::make_pair(tempHomeId, tempAverage));
            iterator = houseRating.find(tempHomeId);
            if (iterator != houseRating.end()) {
                iterator->second = tempAverage;
            }
        }
    }


    for (iterator = houseRating.begin(); iterator != houseRating.end(); iterator++) {
        for (House &house : houseArray) {
            if (house.getId() == iterator->first) {
                float finalRating = (house.getRating() + iterator->second) / 2;

                house.setRating(finalRating);
            }
        }
    }

    return houseArray;
}
