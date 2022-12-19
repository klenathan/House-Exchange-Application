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
    float ratingScore;
    string comment;

public:
    /**
    * Constructor
    */
    HouseRating() = default;

    HouseRating(string homeId, const string &username, float ratingScore, const string &comment);

    /**
     * Getter Setter
     */
    const string &getHomeId() const;

    void setHomeId(const string &homeId);

    const string &getUsername() const;

    void setUsername(const string &username);

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
