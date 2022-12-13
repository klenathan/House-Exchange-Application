//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H

#include "../../Data/DataLoader/DataHandler.h"
#include "../../Data/DataLoader/DataHandler.h"
#include "../../Model/User/User.h"

using std::cout, std::endl, std::string;

class UserController {
private:
    vector<User> userArray;
    User currentUser;
    string dataPath;
public:
    UserController(string path) {
        this->dataPath = path + "./user_data.csv";
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
    bool login(const string &username, const string &password);
    bool include(const std::string& username);
};

#endif //HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
