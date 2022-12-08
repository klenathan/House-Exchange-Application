//
// Created by Nathan Tran on 08/12/2022.
//

#include "vector"
#include "../../Data/DataLoader/DataLoader.h"
#include "../../Model/User/User.h"

#include "UserController.h"


void UserController::loadDataToArray() {
    vector<vector<string>> rawData = DataLoader::loadFile("../Data/user_data.csv");

    for (vector<string> line: rawData) {
        User temp_user = User(line[0], line[1], stol(line[4]));
        this->userArray.push_back(temp_user);
    }
}

bool UserController::checkUserInArray(const std::string& username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}
