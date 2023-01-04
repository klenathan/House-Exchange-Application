//
// Created by phamv on 1/4/2023.
//

#include "RatingController.h"

/**
 * Rating constructor
 * @param path
 * @param requestArray
 */
RatingController::RatingController(string path, vector<Request> requestArray) {
    this->dataPath = path;
    this->loadDataToRatingArray(requestArray);
}
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

const User &RatingController::getCurrentUser() const {
    return currentUser;
}

void RatingController::setCurrentUser(const User &currentUser) {
    RatingController::currentUser = currentUser;
}

void RatingController::test() {
    cout << "Rating-------" << endl;
    for(Rating rating : ratingArray){
        cout << rating.getRequest().getId() << "  " << rating.getHouseRatingScore() << " " << rating.getHouseComment()
        << " " << rating.getUserRatingScore() << " " << rating.getUserComment() << endl;
    }
}

void RatingController::rating(Request request, string decison) {
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
        auto existRequest = std::find_if(ratingArray.begin(), ratingArray.end(),[&requestID](const Rating& obj) {return obj.getRequest().getId() == requestID;});

        if(existRequest != ratingArray.end()){
            auto index = std::distance(ratingArray.begin(), existRequest); // Take index
            Rating rating = ratingArray[index];
            if(decison == "House"){
                rating.setHouseRatingScore(ratingScore);
                rating.setHouseComment(comment);
            }else if(decison == "User"){
                rating.setUserRatingScore(ratingScore);
                rating.setUserComment(comment);
            }
            ratingArray[index] = rating;
        }else{
            Rating tempRating;
            tempRating.setRequest(request);
            if(decison == "House"){
                tempRating.setHouseRatingScore(ratingScore);
                tempRating.setHouseComment(comment);
                tempRating.setUserRatingScore(NAN);
            }else if(decison == "User"){
                tempRating.setHouseRatingScore(NAN);
                tempRating.setUserRatingScore(ratingScore);
                tempRating.setUserComment(comment);
            }
            this->ratingArray.push_back(tempRating);
        }

        writeFile();
        // Save to house_rating_data.csv
//
//        HouseRating *newHouseRatting = new HouseRating(request, ratingScore, comment);
//        this->houseRatingArray.push_back(*newHouseRatting);
//        houseRatingWriteFile();
//
//        delete newHouseRatting;
    } catch (std::exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
        std::cin.ignore();
    }



}

void RatingController::writeFile() {
    string content;
    content += "requestID,houseRatingScore,houseComment,userRatingScore,userComment\n";
    for(Rating rating : this->ratingArray){
        content += rating.getRatingWriteFormat() + "\n";
    }
    cout << DataHandler::writeFile("./rating_data.csv", content);
}





