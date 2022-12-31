//
// Created by ADMIN on 12/15/2022.
//

#include <iostream>
#include "View.h"

#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

View::View(string path) {
    this->dataPath = path;

    this->HC = HouseController(path);
    this->UC = UserController(path);
    this->RC = RequestController(path, HC, UC);
    this->RaC = RatingController(path);}


void View::welcomeScreen() {
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n"
                 "VACATION HOUSE EXCHANGE APPLICATION\n"
                 "Instructors: Mr. Linh Tran & Phong Ngo Group: Group Name\n"
                 "s3891890, Tran Nam Thai\n"
                 "s3878246, Pham Anh Thu\n"
                 "s3891968, Pham Vo Dong\n"
                 "s3927201, Tran Ngoc Khang\n"
                 "Main Menu\n"
                 "Use the app as \n"
                 "1. Guest \n"
                 "2. Member \n"
                 "3. Admin\n"
                 "4. Exit"
              << std::endl;
}

/**
 * Check if user input is a number or not
 * @param: string of user input
 * @return: true or false
 */
bool View::isNumber(const string &s) {
    bool hitDecimal = false;
    for (char c: s) {
        if (c == '.' && !hitDecimal) // 2 '.' in string mean invalid
            hitDecimal = true; // first hit here, we forgive and skip
        else if (!isdigit(c))
            return false; // not ., not
    }
    return true;
}


void View::validateUser() {
    bool check = true;
    std::string input;

    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        // Code for guess
                        guessFunction();
                        break;
                    case 2:
                        // Code for member
                        if (UC.login()) {
                            User user = UC.getCurrentUser();
                            memberFunction(user);
                            break;
                        } else {
                            welcomeScreen();
                            validateUser();
                        }
                    case 3:
                        // Code for admin
                        if (UC.adminLogin()) {
                            User admin = UC.getCurrentUser();
                            adminFunction(admin);
                            break;
                        }

                        welcomeScreen();
                        validateUser();
                        break;
                    case 4:
                        // Exit
                        exit(1);
                    default:
                        // Code
                        cout << "Invalid input! Please try again.\n";
                        goto typeAgain;
                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
            check = true;
        }
    }
}

void View::guessFunction() {
    std::cout << "1. Register \n"
                 "2. View All Houses Details\n"
                 "3. Return to main menu\n"
                 "4. Exit"
              << std::endl;
    bool check = true;
    std::string input;
    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        //Register
                        UC.signup();
                        guessFunction();
                    case 2:
                        //View All Houses Details
                        HC.showData();
                        guessFunction();
                    case 3:
                        // Return to main menu
                        welcomeScreen();
                        validateUser();
                    case 4:
                        //Exit
                        exit(1);
                    default:
                        cout << "Invalid input! Please try again.\n";
                        goto typeAgain;
                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
            check = true;
        }
    }
}

void View::memberFunction(User user) {
    std::cout << "Member Menu\n"
                 "1.  View My Information\n"
                 "2.  List House\n"
                 "3.  Unlist House\n"
                 "4.  Search For Suitable House\n"
                 "5.  View All Requests To My House\n"
                 "6.  Rate Houses\n"
                 "7.  Rate Occupiers\n"
                 "8. Exit"
              << std::endl;
    bool check = true;
    std::string input;

    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            std::cin.ignore();
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        //View My Information
                        UC.showMyData(user.getUsername());
                        memberFunction(user);
                    case 2:
                        //List House
                        if(!HC.houseExist(user.getUsername())) {
                            HC.listNewHouse(user.getUsername());
                        } else {
                            cout << "A user can only list 1 house!";
                        }
                        memberFunction(user);
                    case 3:
                        //Unlist House
                        HC.unlistHouse(user.getUsername());
                        memberFunction(user);
                    case 4: {
                        //Search For Suitable House
                        string date[2];
                        View::dateInput(date);
                        this->HouseArray = HC.searchForSuitableHouses(cityInput(), date[0], date[1], user);
                        cout << "Your suitable houses is:\n";
                        HC.houseData(this->HouseArray);
                        if (!this->HouseArray.empty()) {
                            RC.request(user, requestToOccupy());
                        }

                        memberFunction(user);
                    }
                    case 5:
                        //View All Requests To My House
                        RC.viewRequest(user);

                        if (RC.requestExist(user)) {
                            RC.acceptRequest(user, requestIdInput(RC), HC);
                        }
                        memberFunction(user);
                    case 6:
                        //Rate Houses
                        RaC.rating(HC.findByKey(RC.getHouseForRating(user)));
                        memberFunction(user);
                    case 7: {
                        //Rate Occupiers
                        RaC.rating(
                                UC.findByKey(RC.getOccupierUsername(HC.getUserHouse(user.getUsername()))),
                                HC.getUserHouseVector(user.getUsername()));
                        memberFunction(user);
                    }
                    case 8:
                        //Exit
                        exit(1);
                    default:
                        cout << "Invalid input! Please try again.\n";
                        goto typeAgain;
                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
            check = true;
        }
    }
}

void View::adminFunction(User admin) {
    std::cout << "1. Show all user data \n"
                 "2. View All Houses Details\n"
                 "3. Exit"
              << std::endl;
    bool check = true;
    std::string input;
    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            std::cin.ignore();
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        //Show all user data
                        UC.showData();
                        adminFunction(admin);
                    case 2:
                        //View All Houses Details
                        HC.showData();
                        adminFunction(admin);
                    case 3:
                        //Exit
                        exit(1);
                    default:
                        cout << "Invalid input! Please try again.\n";
                        goto typeAgain;

                }
            } else {
                throw input;
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
            check = true;
        }
    }
}

/**
 * Get start-date and end-date input from user
 * @param: Array arr
 * @return: Array of startDate and endDate
 */
string *View::dateInput(string arr[]) {
    string startDate, endDate;
    while (true) {
        try {
            cout << "Start date (dd/mm/yyyy): ";
            std::getline(std::cin, startDate);
            CustomDate start;
            if ((*new CustomDate).validDate(startDate)) {
                try {
                    start = CustomDate(startDate);
                } catch (...) {
                    throw ConversionErr("DATE_CONVERSION_ERROR");
                }
            } else {
                throw NotfoundErr("INVALID_DATE");
            }

            cout << "End date (dd/mm/yyyy): ";
            std::getline(std::cin, endDate);
            CustomDate end;
            if ((*new CustomDate).validDate(endDate)) {
                try {
                    end = CustomDate(endDate);
                } catch (...) {
                    throw ConversionErr("DATE_CONVERSION_ERROR");
                }
            } else {
                throw NotfoundErr("INVALID_DATE");
            }

            bool validDateInput = (end > start);

            if (validDateInput) {
                arr[0] = startDate;
                arr[1] = endDate;
                return arr;

            } else {
                cout << "Invalid input! Please try again.\n";
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
        }
    }

}

/**
 * Get and validate city input from user
 * @return String of the city
 */
string View::cityInput() {
    string city;
    while (true) {
        try {
            cout << "Enter your city choice (Hanoi/Saigon/Hue):";
            getline(cin, city);
            if (city == "Hanoi" || city == "Saigon" || city == "Hue") {
                return city;
            } else {
                cout << "Invalid input! Please try again.\n";
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
        }
    }
}

House View::requestToOccupy() {
    string id;
    while (true) {
        try {
            bool found = false;
            cout << "Enter the house ID you want to occupy:";
            getline(cin, id);
            for (House h:this->HouseArray){
                if (id == h.getId()) {
                    found = true;
                    return h;
                }
            }
            if (found == false) {
                cout << "The id is not exist!\n";
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
        }
    }
}

/**
 * Get and validate request ID input from user
 * @return id
 */
string View::requestIdInput(RequestController rc) {
    string id;
    bool flag = true;
    while (flag) {
        try {
            cout << "Enter the request ID that you want to accept:";
            getline(cin, id);

            for (Request r: rc.getRequestArr()) {
                if (id == r.getId()) {
                    flag = false;
                    return id;
                }
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
        }
    }
}
