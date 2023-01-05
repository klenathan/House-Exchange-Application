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
//    this->setCurrentUser(currentUser);
    this->loadDataToRatingArray(requestArray);
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
    cout << DataHandler::writeFile("./rating_data.csv", content);
}


//const User &RatingController::getCurrentUser() const {
//    return currentUser;
//}
//
//void RatingController::setCurrentUser(const User &currentUser) {
//    RatingController::currentUser = currentUser;
//}

/**
 * Test?
 */
void RatingController::test() {
    cout << "Rating-------" << endl;
    for(Rating rating : ratingArray){
        cout << rating.getRequest().getId() << "  " << rating.getHouseRatingScore() << " " << rating.getHouseComment()
        << " " << rating.getUserRatingScore() << " " << rating.getUserComment() << endl;
    }
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
        auto existRequest = std::find_if(ratingArray.begin(), ratingArray.end(),[&requestID](const Rating& obj) {return obj.getRequest().getId() == requestID;});

        if(existRequest != ratingArray.end()){
            auto index = std::distance(ratingArray.begin(), existRequest); // Take index
            Rating rating = ratingArray[index];
            if(decision == "House"){
                rating.setHouseRatingScore(ratingScore);
                rating.setHouseComment(comment);
            }else if(decision == "User"){
                rating.setUserRatingScore(ratingScore);
                rating.setUserComment(comment);
            }
            ratingArray[index] = rating;
        }else{
            Rating tempRating;
            tempRating.setRequest(request);
            if(decision == "House"){
                tempRating.setHouseRatingScore(ratingScore);
                tempRating.setHouseComment(comment);
                tempRating.setUserRatingScore(NAN);
            }else if(decision == "User"){
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

/**
 * Compare user rating
 * @param rating1
 * @param rating2
 * @return
 */
bool compareUser(Rating rating1, Rating rating2) {
    return(rating1.getRequest().getOccupyName() < rating2.getRequest().getOccupyName());
}

/**
 * Compare house rating
 * @param rating1
 * @param rating2
 * @return
 */
bool compareHouse(Rating rating1, Rating rating2){
    return (rating1.getRequest().getHouse().getId() < rating2.getRequest().getHouse().getId());
}

/**
 * Calculate user average rating
 * @param userArray
 * @return
 */
vector<User> RatingController::calculateAverageRating(vector<User> userArray) {
    std::map<string, float> userRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;
    string tempUSerName;

    std::sort(this->ratingArray.begin(), this->ratingArray.end(), compareUser);
    for (Rating rating : this->ratingArray) {
        if(!isnan(rating.getUserRatingScore())){
            if (tempUSerName != rating.getRequest().getOccupyName()) {
                count = 1;
                tempUSerName =  rating.getRequest().getOccupyName();
                tempRating = rating.getUserRatingScore();
            } else {
                count++;
                tempRating += rating.getUserRatingScore();
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
    }

    for (iterator = userRating.begin(); iterator != userRating.end(); iterator++) {

        for (User &user: userArray) {
            if (user.getUsername() == iterator->first) {
                float finalRating = iterator->second;
                user.setRating(finalRating);
            }
        }
    }

    return userArray;
}

/**
 * Calculate house average rating
 * @param houseArray
 * @return
 */
vector<House> RatingController::calculateAverageRating(vector<House> houseArray) {
    std::map<string, float> houseRating;
    std::map<string, float>::iterator iterator;
    int count;
    float tempRating = 0;
    float tempAverage = 0;
    string tempHomeId;


    std::sort(ratingArray.begin(), ratingArray.end(), compareHouse);
    for (const Rating &rating: this->ratingArray) {
        if(!isnan(rating.getHouseRatingScore())) {
            if (tempHomeId != rating.getRequest().getHouse().getId()) {
                count = 1;
                tempHomeId = rating.getRequest().getHouse().getId();
                tempRating = rating.getHouseRatingScore();
            } else {
                count++;
                tempRating += rating.getHouseRatingScore();
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
    }


    for (iterator = houseRating.begin(); iterator != houseRating.end(); iterator++) {
        for (House &house : houseArray) {
            if (house.getId() == iterator->first) {
                float finalRating = iterator->second;

                house.setRating(finalRating);
            }
        }
    }

    return houseArray;
}
