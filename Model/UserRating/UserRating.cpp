/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Assessment: 3
  Author:
      s3891890, Tran Nam Thai
      s3878246, Pham Anh Thu
      s3891968, Pham Vo Dong
      s3927201, Tran Ngoc Khang
  Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to check)
  Created  date: 11/12/2022
  Acknowledgement: None
*/
#include "UserRating.h"

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



