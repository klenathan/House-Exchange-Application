//
// Created by phamv on 12/13/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSERATING_H
#define HOUSEEXCHANGEAPPLICATION_HOUSERATING_H

#include <iostream>

using std::string, std::to_string;


class HouseRating {
private:
    string homeID;
    string username;
    long ratingScore;
    string comment;

public:
    HouseRating(){}

    HouseRating(string homeId, const string &username, long ratingScore, const string &comment);\


    const string &getHomeId() const;

    void setHomeId(const string &homeId);

    const string &getUsername() const;

    void setUsername(const string &username);

    long getRatingScore() const;

    void setRatingScore(long ratingScore);

    const string &getComment() const;

    void setComment(const string &comment);


    string getHouseRatingWriteFormat(){
        return this->homeID + "," + this->username + "," + to_string(this->ratingScore) + "," + this->comment;
    }
};


#endif //HOUSEEXCHANGEAPPLICATION_HOUSERATING_H
