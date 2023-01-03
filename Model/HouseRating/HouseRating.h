//
// Created by phamv on 12/13/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSERATING_H
#define HOUSEEXCHANGEAPPLICATION_HOUSERATING_H

#include <iostream>
#include "../Request/Request.h"

using std::string, std::to_string;


class HouseRating {
private:
//    string homeID;
//    string username;
//    string requestID;
    Request request;
    float ratingScore;
    string comment;

public:
    /**
    * Constructor
    */
    HouseRating() = default;

//    HouseRating(const string &homeId, const string &username, const string &requestId, float ratingScore,
//                const string &comment);

    HouseRating(const Request &request, float ratingScore, const string &comment);

    /**
     * Getter Setter
     */
//    const string &getHomeId() const;
//
//    void setHomeId(const string &homeId);
//
//    const string &getUsername() const;
//
//    void setUsername(const string &username);
//
//    float getRatingScore() const;
//
//    void setRatingScore(float ratingScore);
//
//    const string &getComment() const;
//
//    void setComment(const string &comment);
//
//    const string &getRequestId() const;
//
//    void setRequestId(const string &requestId);
    const Request &getRequest() const;

    void setRequest(const Request &request);

    float getRatingScore() const;

    void setRatingScore(float ratingScore);

    const string &getComment() const;

    void setComment(const string &comment);

    /**
     * Method
     */
    string getHouseRatingWriteFormat();
};


#endif //HOUSEEXCHANGEAPPLICATION_HOUSERATING_H
