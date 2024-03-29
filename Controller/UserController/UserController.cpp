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

#include "vector"
#include <iostream>
#include "UserController.h"

using std::string, std::exception, std::isspace, std::isalpha;

/**
 * User constructor
 * @param path
 */
UserController::UserController(string path) {
    this->dataPath = path + "./user_data.csv";
    this->loadDataToArray();
}

/******************************************************************
 * Getter-Setter
 ******************************************************************/
/**
 * Get current user
 * @return currentUser
 */
const User &UserController::getCurrentUser() const {
    return currentUser;
}

/**
 * Set current user
 * @param currentUser
 */
void UserController::setCurrentUser(const User &currentUser) {
    UserController::currentUser = currentUser;
}

/******************************************************************
 * Method implementations
 ******************************************************************/

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
 * Show all data of user
 */
void UserController::showData() {
    for (User user: this->userArray) {
        cout << user << endl;
    }
};

/**
 * Show data of the current user
 * @param username
 */
void UserController::showMyData(const string &username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            cout << user;
        }
    }
};

/**
 * Find user by username
 */
User UserController::findByKey(string username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return user;
        }
    }
    throw NotfoundErr("USER_NOT_FOUND");
}

/**
 * Update user credit point
 * @param houseOwner
 * @param occupier
 * @param consumingPoint
 * @param startDate
 * @param endDate
 */
void UserController::updateCreditPoint (User houseOwner, User occupier, long consumingPoint, CustomDate startDate, CustomDate endDate) {
    for (int i = 0; i < this->userArray.size(); i++) {
        if (userArray[i].getUsername() == houseOwner.getUsername()) {
            userArray[i].setCreditPoints(userArray[i].getCreditPoints() +
                                         consumingPoint * ((*new CustomDate).getDateRange(endDate, startDate)));
        } else if (userArray[i].getUsername() == occupier.getUsername()) {
            userArray[i].setCreditPoints(userArray[i].getCreditPoints() -
                                         consumingPoint * ((*new CustomDate).getDateRange(endDate, startDate)));
        }
        this->writeFile();
    }
}

/**
 * Update occupier rating
 * @param occupier
 * @param averageRating
 */
void UserController::updateUserRating (User occupier, float averageRating) {
    for (int i = 0; i < this->userArray.size(); i++) {
        if (userArray[i].getUsername() == occupier.getUsername()) {
            userArray[i].setRating(averageRating);
        }
        this->writeFile();
    }
}

/**
 * Sign up method
 * @return bool if signup successfully, otherwise false
 */
bool UserController::signup() {
    string username;
    string password;
    string fullname;
    string phoneNum;

    //Check username exists
    bool check = true;
    cout << "-------Sign up-------" << endl;

    try {
        while (check) {
            cout << "Please input username:";
            getline(cin, username);
            try {
                for (char chr: username) {
                    if (isspace(chr)) {
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
            cout << "Please input password:";
            getline(cin, password);
            try {
                for (char chr: password) {
                    if (isspace(chr)) {
                        throw ContainSpace("Password not allow contain space\n");
                    }
                }
                check = false;
            } catch (ContainSpace e) {
                cout << e.what();
                check = true;
            }
        }

        check = true;
        while (check) {
            cout << "Please input fullname:";
            getline(cin, fullname);
            try {
                    if (fullname.length() == 0) {
                        throw ContainSpace("fullname not null\n");
                    }
                check = false;
            } catch (ContainSpace e) {
                cout << e.what();
                check = true;
            }
        }

        check = true;
        while (check) {
            try {
                cout << "Please input phone number:";
                getline(cin, phoneNum);
                if(phoneNum.length() == 0){
                    throw phoneNum;
                }
                for (char chr: phoneNum) {
                    if (isspace(chr) || isalpha(chr)) {
                        throw phoneNum;
                    }else {
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

        cout << "Successfully created an account!\n";
        return true;
    } catch (exception &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;
        cout << "Press \"Enter\" to continue ... " << endl;
    }
}

/**
 * Login method for user
 * @return 1 if successfully login to user account, otherwise 0
 */
bool UserController::login() {
    string username;
    string password;

    cout << "-------Login-------" << endl;

    cout << "Input your username:";
    cin >> username;

    cout << "Input your password:";
    cin >> password;

    for (User user: this->userArray) {
        if (user.getUsername() == username && user.authenticate(password)) {
            this->currentUser = user;
            return 1;
        } else if (user.getUsername() == username && !user.authenticate(password)) {
            cout << "Wrong password!\n";
            return 0;
        }
    }
    cout << "This account does not exist! PLease sign up!\n";
    return 0;
}

/**
 * Login method for admin
 * @return bool 1 if successfully login to admin account, otherwise 0
 */
bool UserController::adminLogin() {
    string username;
    string password;
    cout << "-------Login-------" << endl;

    cout << "Input your username: ";
    cin >> username;

    cout << "Input your password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        User *admin = new User(username, password, "admin", "087654321", 500, 5);
        this->currentUser = *admin;
        delete admin;
        return 1;
    }
    cout << "Wrong username or password!\n";
    return 0;

}


/**
 * Checks if the username exists on the current data state
 * @param: string username
 * @return: bool true if the user exists, otherwise false
 * */
bool UserController::include(const string &username) {
    for (User user: this->userArray) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}