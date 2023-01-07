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

#ifndef HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H

#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/User/User.h"
#include "../../Model/CustomError/Errors.h"


using std::cout, std::endl, std::string, std::getline, std::cin, std::cerr;

class UserController {
private:
    vector<User> userArray;
    User currentUser;
    string dataPath;

    /********************************************************************
     * Methods
     ******************************************************************/
    void loadDataToArray();
public:
    /********************************************************************
     * Constructors
     ******************************************************************/
    UserController() {}

    explicit UserController(string path);

    /********************************************************************
     * Getter Setter
     ******************************************************************/

    const User &getCurrentUser() const;

    void setCurrentUser(const User &currentUser);

    /********************************************************************
     * Methods
     ******************************************************************/

    void writeFile();

    void showData();

    void showMyData(const string &username);

    User findByKey(string username);

    void updateCreditPoint (User houseOwner, User occupier, long consumingPoint, CustomDate startDate, CustomDate endDate);

    void updateUserRating (User occupier, float averageRating);

    // Authenticate method
    bool signup();

    bool login();

    bool adminLogin();

    bool include(const std::string &username);
};

#endif //HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
