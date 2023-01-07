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

#ifndef HOUSEEXCHANGEAPPLICATION_RATING_H
#define HOUSEEXCHANGEAPPLICATION_RATING_H

#include <iostream>
#include <cmath>

#include "../Request/Request.h"

using std::string, std::isnan;


class Rating {
private:
    Request request;
    float houseRatingScore;
    string houseComment;
    float userRatingScore;
    string userComment;

public:
    Rating() = default;

    Rating(const Request &request, float houseRatingScore, const string &houseComment, float userRatingScore,
           const string &userComment);

    const Request &getRequest() const;

    void setRequest(const Request &request);

    float getHouseRatingScore() const;

    void setHouseRatingScore(float houseRatingScore);

    const string &getHouseComment() const;

    void setHouseComment(const string &houseComment);

    float getUserRatingScore() const;

    void setUserRatingScore(float userRatingScore);

    const string &getUserComment() const;

    void setUserComment(const string &userComment);

    /**
     * Method
     */
     string getRatingWriteFormat();

};


#endif //HOUSEEXCHANGEAPPLICATION_RATING_H
