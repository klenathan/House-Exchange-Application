//
// Created by Nathan Tran on 08/12/2022.
//

#include "vector"
#include <iostream>
#include "UserController.h"


/**
 * User constructor
 * @param path
 */
UserController::UserController(string path) {
    this->dataPath = path + "./user_data.csv";
    this->loadDataToArray();
}

/**
 * Getter Setter
 */
const User &UserController::getCurrentUser() const {
    return currentUser;
}

void UserController::setCurrentUser(const User &currentUser) {
    UserController::currentUser = currentUser;
}


const vector<User> &UserController::getUserArray() const {
    return userArray;
}

void UserController::setUserArray(const vector<User> &userArray) {
    UserController::userArray = userArray;
}


/**
 * Store data to the user array
 */
void UserController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        User temp_user = User(line[0], line[1], line[3], line[4],
                              stol(line[2]), stof(line[5]));
        this->userArray.push_back(temp_user);
    }
}

/**
 * Write user data to file
 */
void UserController::writeFile() {
    string content;
    content += "username,password,creditPoints,fullname,phoneNum,rating,numberOfRate\n";
    for (User user: this->userArray) {
        content += user.getWriteFormat() + "\n";
    }
    DataHandler::writeFile(this->dataPath, content);
}

/**
 * Show all data
 */
void UserController::showData() {
    for (User user: this->userArray) {
        cout << user << endl;
    }
};

void UserController::showMyData(const string &username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            cout << user;
        }
    }
};

/**
 *
 * */
User UserController::findByKey(string username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return user;
        }
    }
    throw NotfoundErr("USER_NOT_FOUND");
}

void UserController::updateCreditPoint (User houseOwner, User occupier, long consumingPoint, CustomDate startDate, CustomDate endDate) {
    for (int i = 0; i < this->userArray.size(); i++) {
        if (userArray[i].getUsername() == houseOwner.getUsername()) {
            userArray[i].setCreditPoints(userArray[i].getCreditPoints() + consumingPoint * ((*new CustomDate).getDateRange(startDate, endDate)));
        } else if (userArray[i].getUsername() == occupier.getUsername()) {
            userArray[i].setCreditPoints(userArray[i].getCreditPoints() - consumingPoint * ((*new CustomDate).getDateRange(startDate, endDate)));
        }
    }
    this->writeFile();
}

/**
 * Sign up method
 * @return bool
 */
bool UserController::signup() {
    string username;
    string password;
    string fullname;
    string phoneNum;

    //Check username exited
    bool check = true;

    try {
        while (check) {
            cout << "PLease input username: ";
            cin.ignore();
            getline(cin, username);
            try {
                for (char chr: username) {
                    if (std::isspace(chr)) {
                        throw ContainSpace("username can not contain space\n");
                    }
                }

                if (include(username)) {
                    throw username;
                } else {
                    check = false;
                }
            } catch (ContainSpace e) {
                cout << e.what();
                check = true;
            } catch (string username) {
                cout << username << " is used! Please try again\n";
                check = include(username);
            }
        }

        check = true;
        while (check) {
            cout << "Please input password: ";
            getline(cin, password);
            try {
                for (char chr: password) {
                    if (std::isspace(chr)) {
                        throw ContainSpace("Password not allow contain space\n");
                    }
                }
                check = false;
            } catch (ContainSpace e) {
                cout << e.what();
                check = true;
            }
        }


        cout << "Please input fullname: ";
        getline(cin, fullname);

        check = true;
        while (check) {
            try {
                cout << "Please input phone number: ";
                getline(cin, phoneNum);
                for (char chr: phoneNum) {
                    if (std::isspace(chr) || std::isalpha(chr)) {
                        throw phoneNum;
                    } else {
                        check = false;
                    }
                }
            } catch (...) {
                cout << "Invalid phone number!\n";
                check = true;
            }
        }


        // Save newUser
        User *newUser = new User(username, password, fullname, phoneNum, 500, 5);
        this->userArray.push_back(*newUser);
        writeFile();

        delete newUser;

        cout << "Successfully create an account!\n";
        return true;
    } catch (std::exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
    }
}

/**
 * Login method
 * @return bool
 */
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
        } else if (user.getUsername() == username && !user.authenticate(password)) {
            cout << "Wrong password\n";
            return 0;
        }
    }
    cout << "This account does not exits! PLease sign up! \n";
    return 0;
}

bool UserController::adminLogin() {
    string username;
    string password;

    cout << "Input your username: ";
    cin >> username;

    cout << "Input your password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        User admin = *new User(username, password, "admin", "087654321", 500, 5);
        this->currentUser = admin;
        return 1;
    }
    cout << "Wrong username or password\n";
    return 0;

}


/**
 * The function check if the input user's username is exist on the current data state
 * @param: string username
 * @return: bool true when the user existed, false when they aren't
 * */
bool UserController::include(const std::string &username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}



