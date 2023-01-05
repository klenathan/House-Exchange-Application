//
// Created by phamv on 1/4/2023.
//

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
