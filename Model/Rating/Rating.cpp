//
// Created by phamv on 1/4/2023.
//

#include "Rating.h"

using std::to_string;

Rating::Rating(const Request &request, float houseRatingScore, const string &houseComment, float userRatingScore,
               const string &userComment) : request(request), houseRatingScore(houseRatingScore),
                                            houseComment(houseComment), userRatingScore(userRatingScore),
                                            userComment(userComment) {}

const Request &Rating::getRequest() const {
    return request;
}

void Rating::setRequest(const Request &request) {
    Rating::request = request;
}

float Rating::getHouseRatingScore() const {
    return houseRatingScore;
}

void Rating::setHouseRatingScore(float houseRatingScore) {
    Rating::houseRatingScore = houseRatingScore;
}

const string &Rating::getHouseComment() const {
    return houseComment;
}

void Rating::setHouseComment(const string &houseComment) {
    Rating::houseComment = houseComment;
}

float Rating::getUserRatingScore() const {
    return userRatingScore;
}

void Rating::setUserRatingScore(float userRatingScore) {
    Rating::userRatingScore = userRatingScore;
}

const string &Rating::getUserComment() const {
    return userComment;
}

void Rating::setUserComment(const string &userComment) {
    Rating::userComment = userComment;
}

string Rating::getRatingWriteFormat() {
    string houseRatingScore = to_string(this->houseRatingScore);
    string useRatingScore = to_string(this->userRatingScore);
    if(isnan(this->houseRatingScore)){
        houseRatingScore = "";
    }else if(isnan(this->userRatingScore)){
        useRatingScore = "";
    }



    return this->request.getId() + "," + houseRatingScore + "," + this->houseComment + "," +
           useRatingScore + "," + this->userComment;
}
