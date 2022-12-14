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

long HouseRating::getRatingScore() const {
    return ratingScore;
}

void HouseRating::setRatingScore(long ratingScore) {
    HouseRating::ratingScore = ratingScore;
}

const string &HouseRating::getComment() const {
    return comment;
}

void HouseRating::setComment(const string &comment) {
    HouseRating::comment = comment;
}


HouseRating::HouseRating(string homeId, const string &username, long ratingScore, const string &comment) : homeID(
        homeId),
                                                                                                           username(
                                                                                                                   username),
                                                                                                           ratingScore(
                                                                                                                   ratingScore),
                                                                                                           comment(comment) {}

string HouseRating::getHouseRatingWriteFormat() {
    return this->homeID + "," + this->username + "," + to_string(this->ratingScore) + "," + this->comment;

}
