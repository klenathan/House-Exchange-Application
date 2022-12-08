//
// Created by Nathan Tran on 08/12/2022.
//

#include "../Model/User/User.h"

class MemberController {
private:
    User currentLogIn;
public:
    MemberController() {

    }

    void renderMenu() {
        std::cout << "Member menu";
    }

    bool login(std::string username, std::string password) {

        return false;
    }

    ~MemberController() {
        delete this;
    }
};