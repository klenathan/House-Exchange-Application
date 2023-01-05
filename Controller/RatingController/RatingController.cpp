//
// Created by phamv on 1/4/2023.
//

#include "RatingController.h"

/**
 * Rating constructor
 * @param path
 * @param requestArray
 */
RatingController::RatingController(string path, vector<Request> requestArray, UserController UC, HouseController HC) {
    this->dataPath = path;
    this->loadDataToRatingArray(requestArray);
    this->UC = UC;
    this->HC = HC;
}

/**
 * Load request data into an array
 * @param requestArray
 */
void RatingController::loadDataToRatingArray(vector<Request> requestArray) {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath + "./rating_data.csv");
    float houseRatingScore;
    float userRatingScore;
    string houseComment;
    string userComment;

    for(vector<string> line :rawData){
        for(Request req: requestArray){
            if(line[0] == req.getId()) {
                if (line[1].empty()) {
                    houseRatingScore = NAN;
                    houseComment = "";
                    userRatingScore = stof(line[3]);
                    userComment = line[4];
                } else if (line[3].empty()) {
                    houseRatingScore = stof(line[1]);
                    houseComment = line[2];
                    userRatingScore = NAN;
                    userComment = "";
                } else {
                    houseRatingScore = stof(line[1]);
                    houseComment = line[2];
                    userRatingScore = stof(line[3]);
                    userComment = line[4];
                }
                Rating tempRating = Rating(req, houseRatingScore, houseComment, userRatingScore, userComment);
                this->ratingArray.push_back(tempRating);
            }
        }
    }
}

/**
 * Write rating data
 */
void RatingController::writeFile() {
    string content;
    content += "requestID,houseRatingScore,houseComment,userRatingScore,userComment\n";
    for(Rating rating : this->ratingArray){
        content += rating.getRatingWriteFormat() + "\n";
    }
    DataHandler::writeFile("./rating_data.csv", content);
}


/**
 * Get rating and comment input from user
 * @param request
 * @param decision
 */
void RatingController::rating(Request request, string decision) {
    string tempRatingScore;
    float ratingScore;
    string comment;

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

        string requestID = request.getId();
        auto existRequest = std::find_if(ratingArray.begin(), ratingArray.end(),[&requestID](const Rating& obj) {
            return obj.getRequest().getId() == requestID;
        });

        if(existRequest != ratingArray.end()){
            auto index = std::distance(ratingArray.begin(), existRequest); // Take index
            Rating rating = ratingArray[index];
            if(decision == "House"){
                rating.setHouseRatingScore(ratingScore);
                rating.setHouseComment(comment);
                ratingArray[index] = rating;
                calculateAverageRating(rating.getRequest().getHouse());
            }else if(decision == "User"){
                rating.setUserRatingScore(ratingScore);
                rating.setUserComment(comment);
                cout << "tempRating: " << rating.getRequest().getUser().getUsername();
                ratingArray[index] = rating;
                calculateAverageRating(rating.getRequest().getUser());
            }

        } else{
            Rating tempRating;
            tempRating.setRequest(request);
            if(decision == "House"){
                tempRating.setHouseRatingScore(ratingScore);
                tempRating.setHouseComment(comment);
                tempRating.setUserRatingScore(NAN);
                this->ratingArray.push_back(tempRating);
                calculateAverageRating(tempRating.getRequest().getHouse());
            } else if(decision == "User"){
                tempRating.setHouseRatingScore(NAN);
                tempRating.setUserRatingScore(ratingScore);
                tempRating.setUserComment(comment);
                this->ratingArray.push_back(tempRating);
                calculateAverageRating(tempRating.getRequest().getUser());
            }
        }

        writeFile();

    } catch (std::exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
        std::cin.ignore();
    }



}

bool RatingController::ratingValid(string decision, string requestID) {

    auto existRequest = std::find_if(ratingArray.begin(), ratingArray.end(),[&requestID](const Rating& obj) {
        return obj.getRequest().getId() == requestID;
    });
    if(existRequest != ratingArray.end()) {
        for (Rating rating: this->ratingArray) {
            if (rating.getRequest().getId() == requestID) {
                if (decision == "House" && isnan(rating.getHouseRatingScore())) {
                    return true;
                } else if (decision == "User" && isnan(rating.getUserRatingScore())) {
                    return true;
                }
            }
        }
    } else {
        return true;
    }
    return false;

}

bool compareUser(Rating rating1, Rating rating2) {
    return(rating1.getRequest().getOccupyName() < rating2.getRequest().getOccupyName());
}

void RatingController::calculateAverageRating(User user) {
    int count = 1;
    float tempRating = 5; // default rating when create an account
    float tempAverage = 0;

    for (Rating rating: ratingArray ) {
        if (!isnan(rating.getUserRatingScore())) {
            if (user.getUsername() == rating.getRequest().getUser().getUsername()) {
                count += 1;
                tempRating += rating.getUserRatingScore();
            }
        }
    }
    cout << tempRating << endl;
    tempAverage = tempRating / count;
    cout << tempAverage << endl;
    this->UC.updateUserRating(user, tempAverage);
}

vector<House> RatingController::calculateAverageRating(vector<House> houseArray) {
    std::map<string, float> houseRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;

    for (Rating rating: ratingArray ) {
        if (!isnan(rating.getHouseRatingScore())) {
            if (house.getId() == rating.getRequest().getHouse().getId()) {
                count += 1;
                tempRating += rating.getHouseRatingScore();
            }
        }
    }

    cout << "a" << tempRating << endl;
    cout << "b" << count << endl;
    cout << "c" << tempAverage << endl;

    tempAverage = tempRating / count;

    this->HC.updateHouseRating(house, tempAverage);
}
