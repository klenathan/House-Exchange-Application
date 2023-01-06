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

#ifndef HOUSEEXCHANGEAPPLICATION_USERRATING_H
#define HOUSEEXCHANGEAPPLICATION_USERRATING_H

#include <iostream>
#include "../Request/Request.h"

using std::string, std::to_string;

class UserRating {
private:
    Request request;
    float ratingScore;
    string comment;

public:
    /**
     * Constructor
     */
    UserRating() = default;

    UserRating(const Request &request, float ratingScore, const string &comment);

    /**
     * Getter Setter
     */
    const Request &getRequest() const;

    void setRequest(const Request &request);

    float getRatingScore() const;

    void setRatingScore(float ratingScore);

    const string &getComment() const;

    void setComment(const string &comment);

    /**
     * Method
     */
     string getUserRatingWriteFormat();

};


#endif //HOUSEEXCHANGEAPPLICATION_USERRATING_H
