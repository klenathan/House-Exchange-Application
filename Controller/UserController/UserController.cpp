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

bool UserController::signup() {
    string username;
    string password;
    string fullname;
    string phoneNum;

    //Check username exited
    bool check = true;

    while(check){
        cout <<  "PLease input username: ";
        cin >> username;
        if(include(username)){
            cin.ignore();
            cout << "This " << username << " is used!\n";
            check  = include(username);
        }else{
            check = false;
        }
    }

    cout << "Please input password: ";
    cin >> password;

    cin.ignore();
    cout << "Please input fullname: ";
    getline(cin, fullname);

    cout << "Please input phone number: ";
    cin >> phoneNum;

    // Save newUser
    User *newUser = new User(username, password, fullname, phoneNum, 500, 5);
    this->userArray.push_back(*newUser);
    writeFile();

    delete newUser;

    return true;
}



bool UserController::login() {
    string username;
    string password;

    cout << "Input your username: ";
    cin >> username;

    cout << "Input your password: ";
    cin >> password;

    for (User user: this->userArray) {
        if (user.getUsername() == username && user.authenticate(password)) {
            this->currentUser = user;
            return 1;
        }else if(user.getUsername() == username && !user.authenticate(password)){
            cerr << "Wrong password";
            return 0;
        }
    }
    cerr << "This account does not exits! PLease sign up! \n";
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


