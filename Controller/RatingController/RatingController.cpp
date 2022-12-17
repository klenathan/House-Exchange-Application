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

    cout << DataHandler::writeFile("../Data/data-test.txt", content);
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

    cout << DataHandler::writeFile("../Data/data-test.txt", content);

}

/**
 * Rating method for users rate house which they rented
 * @param house which is rated by user
 */
void RatingController::rating(const House &house) {
    string tempRatingScore;
    float ratingScore;
    string comment;
    const string &houseId = house.getId();
    string username = this->currentUser.getUsername();

    bool check = true;

    // Display message for feedback
    // TODO Khang please fix for about the words
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
    }

}

/**
 * Rating method for house owner rate user who rented their house
 * @param user which is rated by house owner
 */
void RatingController::rating(User user, const vector<House>& houseArray) {
    string username = user.getUsername();
    string homeID;
    string tempRatingScore;
    float ratingScore;
    string comment;

    bool check = true;

    try {
        //Assign currentUser house ID to houseID
        for (House house: houseArray) {
            if (this->currentUser.getUsername() == house.getOwner()) {
                homeID = house.getId();
                break;
            }
        }

        //Rating Process
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

vector<User> RatingController::userRatingAverage(vector<User>& userArray) {
    std::map<string, float> userRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;
    string tempUSerName;


    std::sort(userRatingArray.begin(), userRatingArray.end(), compareUser);
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
        for(User& user : userArray){
            if(user.getUsername() == iterator->first){
                float finalRating = (user.getRating() + iterator->second)/2;

                user.setRating(finalRating);
            }
        }
    }

    return userArray;
}













