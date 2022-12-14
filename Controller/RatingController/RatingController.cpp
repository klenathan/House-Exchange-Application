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
 * Rating method for users rate house which they rented
 * @param house which is rated by user
 */
void RatingController::rating(const House &house) {
    string tempRatingScore;
    long ratingScore;
    string comment;
    const string& houseId = house.getId();
    string username = this->currentUser.getUsername();

    bool check = true;

    // Display message for feedback
    // TODO Khang please fix for about the words
    try{
        cout << "Welcome to feedback site\nNow you have permission for feedback about Houses\n";

        while (check) {
            try{
                cout << "Please input your rating score in the scale -10 to 10: ";
                getline(cin, tempRatingScore);
                ratingScore = std::stol(tempRatingScore);
                try{
                    if (ratingScore <= -11 || ratingScore >= 11) {
                        throw ratingScore;
                    } else {
                        check = false;
                    }
                }catch (...){
                    cout << ratingScore << " Out of scale\n";
                    check = true;

                }
            }catch (...){
                cout << tempRatingScore << " Invalid input!\n";
                check  = true;
            }

        }

        cout << "Please give your comment: \n";
        getline(cin, comment);

        // Save to house_rating_data.csv
        HouseRating *newHouseRatting = new HouseRating(houseId, username, ratingScore, comment);
        this->houseRatingArray.push_back(*newHouseRatting);
        houseRatingWriteFile();

        delete newHouseRatting;
    }catch (std::exception &e){
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
    }

}

/**
 * Rating method for house owner rate user who rented their house
 * @param user which is rated by house owner
 */
void RatingController::rating(const User &user) {

}









