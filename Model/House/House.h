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

#ifndef HOUSEEXCHANGEAPPLICATION_HOUSE_H
#define HOUSEEXCHANGEAPPLICATION_HOUSE_H

#include <iostream>


#include "../CustomDate/CustomDate.h"

using std::to_string, std::string;

class House {
private:
    string id, name, address, desc, ownerUsername;
    long consumingPoint;
    CustomDate startDate, endDate;
    float requiredRating, rating;
    bool status;


public:
    /**
     * Constructor
     * */

    House() {}

    /**
     * Partial constructor
     * */
    House(const string &name, const string &address, const string &desc, const string &ownerUsername,
          const CustomDate &startDate, const CustomDate &endDate, float requiredRating,
          float rating, long consumingPoint);

    /**
     * Full constructor for read file
     */
    House(const string &id, const string &name, const string &address, const string &desc, const string &ownerUsername,
          const CustomDate &startDate, const CustomDate &endDate, float requiredRating,
          float rating, bool status, long consumingPoint);

    /**
     * Getter-Setter
     * */

    void setConsumingPoint(long consumingPoint);

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getDesc() const;

    void setDesc(const string &desc);

    const string &getOwnerUsername() const;

    void setOwnerUsername(const string &ownerUsername);


    long getConsumingPoint() const;

    const CustomDate &getStartDate() const;

    void setStartDate(const CustomDate &startDate);

    const CustomDate &getEndDate() const;

    void setEndDate(const CustomDate &endDate);

    float getRequiredRating() const;

    void setRequiredRating(float requiredRating);

    float getRating() const;

    void setRating(float rating);

    bool isStatus() const;

    void setStatus(bool status);

    string to_string();

    /**
     * Methods
     * */

    static int randomID();

    void showInfo();
};

#endif //HOUSEEXCHANGEAPPLICATION_HOUSE_H
