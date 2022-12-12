//
// Created by Nathan Tran on 08/12/2022.
//

#include "vector"
#include <iostream>
#include "UserController.h"


void UserController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile("../Data/user_data.csv");

    for (vector<string> line: rawData) {
        User temp_user = User(line[0], line[1], line[3], line[4],
                              stol(line[2]), stof(line[5]));
        this->userArray.push_back(temp_user);
    }
}

void UserController::showData() {
    for (User user: this->userArray) {
        cout << user << endl;
    }
};

bool UserController::login(const std::string &username, const std::string &password) {
    for (User user: this->userArray) {
        if (user.getUsername() == username && user.authenticate(password)) {
            this->currentUser = user;
            return 1;
        }
    }
    return 0;
}

bool UserController::include(const std::string &username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

const User &UserController::getCurrentUser() const {
    return currentUser;
}

void UserController::setCurrentUser(const User &currentUser) {
    UserController::currentUser = currentUser;
}
