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
                 "Instructors: Mr. Linh Tran & Phong Ngo Group: Group Name\n\n"
                 "s3891890, Tran Nam Thai\n"
                 "s3878246, Pham Anh Thu\n"
                 "s3891968, Pham Vo Dong\n"
                 "s3927201, Tran Ngoc Khang\n\n"
                 "Main Menu\n"
                 "Use the app as \n1. Guest \n2. Member \n3. Admin"
              << std::endl;
}

bool View::inputValidate(std::string string) {
//    cout<< string + ": ";
    if (string.length() != 1) {
//        cout<<"length not one \n";
        return false;
    }
    if ((isdigit(string[0]) == false)) {
//        cout<<"is not num\n";
        return false;
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
            if (View::inputValidate(input)) {
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
                        }
                        break;
                    case 3:
                        // Code for admin
                        std::cout << "admin";
                        break;
                    default:
                        // Code
                        cout << "Invalid input! Please try again.";
                        goto typeAgain;
                        break;
                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
            system("PAUSE");
        }
        catch (...) {
            // Block of code to handle errors
            std::cout << "Invalid input! Please try again.\n";
            std::cin.ignore();
            check = true;
        }
    }
}

void View::guessFunction() {
    std::cout << "1. Register \n2. View All Houses Details"
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
            if (View::inputValidate(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
//                        Register
                        UC.signup();
//                        TODO users data get over write when signup
                        guessFunction();

                        break;
                    case 2:
//                        View All Houses Details
                        HC.showData();
                        break;
                    default:
                        cout << "Invalid input! Please try again.";
                        goto typeAgain;

                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
//            system("PAUSE");
        }
        catch (...) {
            // Block of code to handle errors
            std::cout << "Invalid input! Please try again.\n";
            std::cin.ignore();
            check = true;
        }
    }
}

void View::memberFunction() {
    std::cout << "Member Menu\n"
                 "1.    View My Information\n"
                 "2.    List House\n"
                 "3.    Unlist House\n"
                 "4.    Search For Suitable House\n"
                 "5.    Request To Occupy\n"
                 "6.    View All Requests To My House\n"
                 "7.    Request Handling\n"
                 "8.    Occupy A House\n"
                 "9.    Rate Houses\n"
                 "10.   Rate Occupiers \n"
              << std::endl;
    bool check = true;
    std::string input;
    UserController UC;
    HouseController HC;
    User user;
    RequestController RequestC;
    RatingController RatingC;
    while (check) {
        try {
            typeAgain:
            std::cout << "Enter your choice:";
            std::cin >> input;
            if (View::inputValidate(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        UC.showData();
                        break;
                    case 2:
                        HC.listNewHouse(user.getUsername());
                        break;
                    case 3:
                        HC.unlistHouse(user.getUsername());
                        break;
                    case 4:
//                        HC.searchForSuitableHouses(,,,user);
                        break;
                    case 5:
                        RequestC.request(user, (House &&) "ádsdasd");
                        break;
                    case 6:
                        RequestC.viewRequest(user);
                        break;
                    case 7:
                        RequestC.acceptRequest(user, "asd" ,HC);
                        break;
                    case 8:
                        break;
                    case 9:
                        RatingC.rating()
                        break;
                    case 10:
                        break;


                    default:
                        cout << "Invalid input! Please try again.";
                        goto typeAgain;

                }
                check = false;
            } else {
                throw input;
            }
            cout << endl;
//            system("PAUSE");
        }
        catch (...) {
            // Block of code to handle errors
            std::cout << "Invalid input! Please try again.\n";
            std::cin.ignore();
            check = true;
        }
    }
}
