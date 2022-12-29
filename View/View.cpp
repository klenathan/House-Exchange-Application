//
// Created by ADMIN on 12/15/2022.
//

#include <iostream>
#include "View.h"
#include "../Controller/UserController/UserController.h"
#include "../Controller/HouseController/HouseController.h"
#include "../Controller/RequestController/RequestController.h"
#include "../Controller/RatingController/RatingController.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using namespace std;


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
    UserController UC;
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
                            memberFunction();
                            break;
                        }
                    case 3:
                        // Code for admin
                        adminFunction();
                        break;
                    case 4:
                        // Exit
                        break;
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
                 "3. Exit"
              << std::endl;
    bool check = true;
    std::string input;
    UserController UC;
    HouseController HC;
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
                        //Exit
                        break;
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

void View::memberFunction() {
    std::cout << "Member Menu\n"
                 "1.  View My Information\n"
                 "2.  List House\n"
                 "3.  Unlist House\n"
                 "4.  Search For Suitable House\n"
                 "5.  Request To Occupy\n"
                 "6.  View All Requests To My House\n"
                 "7.  Request Handling\n"
                 "8.  Rate Houses\n"
                 "9.  Rate Occupiers\n"
                 "10. Exit"
              << std::endl;
    bool check = true;
    std::string input;
    UserController *UC;
    HouseController *HC;
    User *user;
    RequestController *RequestC;
    RatingController *RatingC;
    vector<House> suitableHouses;
    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        //View My Information
                        UC->showMyData(user->getUsername());
                        memberFunction();
                    case 2:
                        //List House
                        HC->listNewHouse(user->getUsername());
                        memberFunction();
                    case 3:
                        //Unlist House
                        HC->unlistHouse(user->getUsername());
                        memberFunction();
                    case 4: {
                        //Search For Suitable House
                        string date[2];
                        View::dateInput(date);
                        suitableHouses = HC->searchForSuitableHouses(cityInput(), date[0], date[1], (User &&) user);
                        cout << "Your suitable houses is:\n";
                        HC->houseData(suitableHouses);
                        memberFunction();
                    }
                    case 5: {
                        //Request To Occupy
                        if (!suitableHouses.empty()) {
                            RequestC->request((User &&) user, (House &&) suitableHouses);
                            break;
                        }
                        cout << "Find your suitable house first";
                        memberFunction();
                    }
                    case 6:
                        //View All Requests To My House
                        RequestC->viewRequest((User &&) user);
                        memberFunction();
                    case 7:
                        //Request Handling
                        RequestC->acceptRequest((User &&) user, requestIdInput(), (HouseController &&) HC);
                        memberFunction();
                    case 8:
                        //Rate Houses
                        RatingC->rating(HC->findByKey(RequestC->getHouseForRating((User &&) user)));
                        memberFunction();
                    case 9: {
                        //Rate Occupiers
                        RatingC->rating(
                                UC->findByKey(RequestC->getOccupierUsername(HC->getUserHouse(user->getUsername()))),
                                HC->getUserHouseVector(user->getUsername()));
                        memberFunction();
                    }
                    case 10:
                        //Exit
                        break;
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

void View::adminFunction() {
    std::cout << "1. Show all user data \n"
                 "2. View All Houses Details\n"
                 "3. Exit"
              << std::endl;
    bool check = true;
    std::string input;
    UserController UC;
    HouseController HC;
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
                        UC.showData();
                        adminFunction();
                    case 2:
                        //View All Houses Details
                        HC.showData();
                        adminFunction();
                    case 3:
                        //Exit
                        break;
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
    string startDate;
    string endDate;
    while (true) {
        try {
            typeAgain:
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
                goto typeAgain;
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
            typeAgain:
            cout << "Enter your city choice (Hanoi/Saigon/Hue):";
            getline(cin, city);
            if (city == "Hanoi" || city == "Saigon" || city == "Hue") {
                return city;
            } else {
                cout << "Invalid input! Please try again.\n";
                goto typeAgain;
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
string View::requestIdInput() {
    string id;
    Request R;
    while (true) {
        try {
            typeAgain:
            cout << "Enter the request ID that you want to accept:";
            getline(cin, id);
            if (id == R.getId()) {
                return id;
            } else {
                cout << "Can't find this ID.\n";
                goto typeAgain;
            }
        }
        catch (std::exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            std::cin.ignore();
        }
    }
}
