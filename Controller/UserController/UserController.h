//
// Created by Nathan Tran on 08/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H


class UserController {
private:
    vector<User> userArray;


public:
    UserController() {
        this->loadDataToArray();
    }

    /**
     * Methods
     * */
    void loadDataToArray();

    bool checkUserInArray(std::string username);
};

#endif //HOUSEEXCHANGEAPPLICATION_USERCONTROLLER_H
