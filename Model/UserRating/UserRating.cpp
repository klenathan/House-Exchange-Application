//
// Created by phamv on 12/13/2022.
//

#include "UserRating.h"

UserRating::UserRating(const string &username, const string &homeId, long ratingScore, const string &comment)
        : username(username), homeID(homeId), ratingScore(ratingScore), comment(comment) {}

const string &UserRating::getUsername() const {
    return username;
}

void UserRating::setUsername(const string &username) {
    UserRating::username = username;
}

const string &UserRating::getHomeId() const {
    return homeID;
}

void UserRating::setHomeId(const string &homeId) {
    homeID = homeId;
}

long UserRating::getRatingScore() const {
    return ratingScore;
}

void UserRating::setRatingScore(long ratingScore) {
    UserRating::ratingScore = ratingScore;
}

const string &UserRating::getComment() const {
    return comment;
}

void UserRating::setComment(const string &comment) {
    UserRating::comment = comment;
}

string UserRating::getUserRatingWriteFormat() {
    return this->username + "," + this->homeID + "," + to_string(this->ratingScore) + "," + this->comment;
}
