//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H

#include "../../Data/DataLoader/DataHandler.h"

using std::cout, std::endl, std::string, std::getline, std::cin, std::cerr;

class UserController {
private:
    vector<User> userArray;
    User currentUser;
public:
    UserController() {
        this->loadDataToArray();
    }

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

    void writeFile() {
        string content;
        content += "username,password,creditPoints,fullname,phoneNum,rating,numberOfRate\n";
        for (User user : this->userArray) {
            content += user.getWriteFormat() + "\n";
        }
        cout << DataHandler::writeFile("../Data/data-test.txt", content);
    }

    // Authenticate method
    void signup();
    bool login(const string &username, const string &password);
    bool include(const std::string& username);
};

#endif //HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
