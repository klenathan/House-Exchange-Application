//
// Created by phamv on 12/13/2022.
//

#include "RatingController.h"


const User &RatingController::getCurrentUser() const {
    return currentUser;
}

void RatingController::setCurrentUser(const User &currentUser) {
    RatingController::currentUser = currentUser;
}


RatingController RatingController::userRatingController(string path) {
    this->dataPath = path + "./user_rating_data.csv";
    this->loadDataToUserRatingArray();
}

RatingController RatingController::houseRatingController(string path) {
    this->dataPath = path + "./house_rating_data.csv";
    this->loadDataToHouseRatingArray();
}



void RatingController::loadDataToUserRatingArray() {
//    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);
//
//    for (vector<string> line:rawData){
//        U
//    }

}

void RatingController::loadDataToHouseRatingArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        HouseRating temp_house_rating = HouseRating(line[0],
                                                    line[1], std::stol(line[2]),
                                                    line[3]);

        this->houseRatingArray.push_back(temp_house_rating);
    }
}

void RatingController::rating(const House &house) {
    long ratingScore;
    string comment;
    string houseId = house.getId();
    string username = this->currentUser.getUsername();


    bool check = true;

    // Display message for feedback
    // TODO Khang please fix for about the words
    cout << "Welcome to feedback site\nNow you have permission for feedback about Houses\n";

    cout << "Please input your rating score in the scale -10 to 10: ";
    cin >> ratingScore;

    while(check){
        if(ratingScore <= -10 || ratingScore >= 10){
            cerr << "Out of scale";
            check = true;
        }else{
            check = false;
        }
    }

    cout << "Please give your comment: \n";
    getline(cin, comment);

    // Save to house_rating_data.csv
    HouseRating *newHouseRatting = new HouseRating(houseId, username, ratingScore, comment);
    this->houseRatingArray.push_back(*newHouseRatting);
    houseRatingWriteFile();

    delete newHouseRatting;

}

void RatingController::rating(const User &user) {

}









