//
// Created by Nathan Tran on 08/12/2022.
//

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
public:
    /**
     * Controller
     */
    explicit UserController(string path);

    /**
     * Getter Setter
     * */

    const User &getCurrentUser() const;

    void setCurrentUser(const User &currentUser);

    /**
     * Methods
     * */
    void loadDataToArray();

    void showData();

    void writeFile();

    // Authenticate method
    bool signup();
    bool login();
    bool include(const std::string& username);
};

#endif //HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
