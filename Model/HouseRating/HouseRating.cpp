//
// Created by phamv on 12/13/2022.
//

#include "HouseRating.h"


const string &HouseRating::getHomeId() const {
    return homeID;
}

void HouseRating::setHomeId(const string &homeId) {
    homeID = homeId;
}


const string &HouseRating::getUsername() const {
    return username;
}

void HouseRating::setUsername(const string &username) {
    HouseRating::username = username;
}

float HouseRating::getRatingScore() const {
    return ratingScore;
}

void HouseRating::setRatingScore(float ratingScore) {
    HouseRating::ratingScore = ratingScore;
}

const string &HouseRating::getComment() const {
    return comment;
}

void HouseRating::setComment(const string &comment) {
    HouseRating::comment = comment;
}
const string &HouseRating::getRequestId() const {
    return requestID;
}

void HouseRating::setRequestId(const string &requestId) {
    requestID = requestId;
}



HouseRating::HouseRating(const string &homeId, const string &username, const string &requestId, float ratingScore,
                         const string &comment) : homeID(homeId), username(username), requestID(requestId),
                                                  ratingScore(ratingScore), comment(comment) {}


string HouseRating::getHouseRatingWriteFormat() {
    return homeID + "," + this->username + "," + this->requestID + "," + to_string(this->ratingScore) + "," + this->comment;
}


