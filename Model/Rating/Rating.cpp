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
