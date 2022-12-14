//
// Created by phamv on 12/13/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USERRATING_H
#define HOUSEEXCHANGEAPPLICATION_USERRATING_H

#include <iostream>

using std::string, std::to_string;

class UserRating {
private:
    string username;
    string homeID;
    long ratingScore;
    string comment;

public:
    /**
     * Constructor
     */
    UserRating() = default;

    UserRating(const string &username, const string &homeId, long ratingScore, const string &comment);

    /**
     * Getter Setter
     */
    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getHomeId() const;

    void setHomeId(const string &homeId);

    long getRatingScore() const;

    void setRatingScore(long ratingScore);

    const string &getComment() const;

    void setComment(const string &comment);

    /**
     * Method
     */
     string getUserRatingWriteFormat();


};


#endif //HOUSEEXCHANGEAPPLICATION_USERRATING_H
