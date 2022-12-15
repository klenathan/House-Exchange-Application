//
// Created by ADMIN on 12/15/2022.
//

#include <iostream>
#include "View.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;

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

bool View::inputValidate(std::string string){
//    cout<< string + ": ";
    if(string.length() != 1){
//        cout<<"length not one \n";
        return false;
    }
    if((isdigit(string[0]) == false)){
//        cout<<"is not num\n";
        return false;
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
            if(View::inputValidate(input)){
                int num = stoi(input);
                switch (num) {
                    case 1:
                        // Code for guess
                        std::cout << "guess";
                        break;

                    case 2:
                        // Code for member
                        std::cout << "member";
                        break;
                    case 3:
                        // Code for admin
                        std::cout << "admin";
                        break;
                    default:
                        // Code
                        cout<< "Invalid input! Please try again.";
                        goto typeAgain;
                        break;
                }
                check = false;
            }else {
                    throw input;
            }
            cout<<endl;
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
