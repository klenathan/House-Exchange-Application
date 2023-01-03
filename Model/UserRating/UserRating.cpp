//
// Created by phamv on 12/13/2022.
//

#include "UserRating.h"
//
//UserRating::UserRating(const string &username, const string &homeId, const string &requestId, float ratingScore,
//                       const string &comment) : username(username), homeID(homeId), requestID(requestId),
//                                                ratingScore(ratingScore), comment(comment) {}


UserRating::UserRating(const Request &request, float ratingScore, const string &comment) : request(request),
                                                                                           ratingScore(ratingScore),
                                                                                           comment(comment) {}


const Request &UserRating::getRequest() const {
    return request;
}

void UserRating::setRequest(const Request &request) {
    UserRating::request = request;
}

float UserRating::getRatingScore() const {
    return ratingScore;
}

void UserRating::setRatingScore(float ratingScore) {
    UserRating::ratingScore = ratingScore;
}

const string &UserRating::getComment() const {
    return comment;
}

void UserRating::setComment(const string &comment) {
    UserRating::comment = comment;
}

string UserRating::getUserRatingWriteFormat() {
    return this->request.getId() + "," + to_string(this->ratingScore) + "," + this->comment;
}



