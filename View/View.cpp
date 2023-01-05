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
using std::exception;

/**
 * Constructor
 * @param path
 */
View::View(string path) {

    this->dataPath = path;
    this->HC = HouseController(path);
    this->UC = UserController(path);
    this->RC = RequestController(path, HC, UC);
    this->RaC = RatingController(path, RC.getRequestArr());

    cout << "EEET2482/COSC2082 ASSIGNMENT\n"
            "VACATION HOUSE EXCHANGE APPLICATION\n"
            "Instructors: Mr. Linh Tran & Phong Ngo\n"
            "Group: Group Name\n"
            "s3891890, Tran Nam Thai\n"
            "s3878246, Pham Anh Thu\n"
            "s3891968, Pham Vo Dong\n"
            "s3927201, Tran Ngoc Khang\n" << endl;
}

/**
 * Welcome Screen
 */
void View::welcomeScreen() {
    cout << "|-------- Main Menu -------- |\n"
            "|Use the app as              |\n"
            "|1. Guest                    |\n"
            "|2. Member                   |\n"
            "|3. Admin                    |\n"
            "|4. Exit                     |\n"
            "|----------------------------|"
         << endl;
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

/**
 * Validate User
 */
void View::validateUser() {
    bool check = true;
    string input;

    while (check) {
        try {
            typeAgain:
            cout << "Enter your choice: ";
            cin >> input;
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
                cout << "Invalid choice\n" << endl;
                validateUser();
            }
            cout << endl;
        }
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
            check = true;
        }
    }
}

/**
 * Guess Menu
 */
void View::guessFunction() {
    cout << "|---------------- Guest Menu ----------------|\n"
            "|1. Register                                 |\n"
            "|2. View All Houses Details                  |\n"
            "|3. Return to main menu                      |\n"
            "|4. Exit                                     |\n"
            "|--------------------------------------------|"
         << endl;
    bool check = true;
    string input;
    while (check) {
        try {
            typeAgain:
            cout << "Enter your choice: ";
            cin >> input;
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
                        system("pause");
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
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
            check = true;
        }
    }
}

/**
 * Member Menu
 * @param user
 */
void View::memberFunction(User user) {
    cout << "|--------------Member Menu--------------|\n"
            "|1. View My Information                 |\n"
            "|2. Search For Suitable House           |\n"
            "|3. View all available house            |\n"
            "|4. View sent request                   |\n"
            "|5. View All Requests To My House       |\n"
            "|---------------------------------------|\n"
            "|6. List House                          |\n"
            "|7. Unlist House                        |\n"
            "|8. Rate Houses                         |\n"
            "|9. Rate Occupiers                      |\n"
            "|0. Exit                                |\n"
            "|---------------------------------------|"
         << endl;
    bool check = true;
    string input;
    UC.setCurrentUser(user);

    while (check) {
        try {
            typeAgain:
            cout << "-> Enter your choice: ";
            cin >> input;
            cin.ignore();
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        ////View My Information
                        cout << "\nYour information:\n";
                        UC.showMyData(user.getUsername());
                        cout << "\nYour house:\n";
                        HC.showUserHouse(user.getUsername());
                        system("pause");
                        memberFunction(user);
                    case 2: {
                        //// Search For Suitable House
                        string date[2];
                        View::dateInput(date);
                        this->HouseArray = HC.searchForSuitableHouses(cityInput(), date[0], date[1], user);

                        if (this->HouseArray.size() != 0) {
                            cout << "Your suitable houses are: \n";
                            HC.houseData(this->HouseArray);
                            if (!this->HouseArray.empty()) {
                                RC.request(user, requestToOccupy());
                            }
                        } else {
                            cout << "There are no suitable house for your need " << endl;
                        }
                        system("pause");
                        memberFunction(user);
                    }
                    case 3:
                        ////List House
                        cout << "Available houses: " << endl;
                        if (HC.allAvailableHouse().size() == 0) {
                            cout << "There is no listing house in the system" << endl;
                        }
                        system("pause");
                        memberFunction(user);
                    case 4:
                        //// View sent request
                        RC.viewSentRequest(user);
                        system("pause");
                        memberFunction(user);
                    case 5:
                        //// View All Requests To My House

                        if (RC.viewRequest(user)) {
                            RC.acceptRequest(this->requestIdInput(RC), user);
                        }

                        system("pause");
                        memberFunction(user);
                    case 6:
                        ////List House
                        if (!HC.houseExist(user.getUsername())) {
                            HC.listNewHouse(user.getUsername());
                        } else {
                            cout << "A user can only list 1 house!\n";
                        }
                        system("pause");
                        memberFunction(user);
                    case 7:
                        //// Unlist House
                        HC.unlistHouse(user.getUsername());
                        system("pause");
                        memberFunction(user);
                    case 8:
                        //Rate House
                        if (!RC.getHouseForRating(user).empty()) {
                            cout << "Pending house for rating\n";

                            for (Request request: RC.getHouseForRating(user)) {
                                cout << "\n-------------------------\n";
                                request.showInfo();
                            }
                            cout << "\n-------------------------\n";

                            string requestID;
                            requestID = inputHouseRating(RC.getHouseForRating(user));
                            bool valid = 0;
                            for (Request request: RC.getHouseForRating(user)) {
                                if (request.getId() == requestID && RaC.ratingValid("House", requestID)) {
                                    RaC.rating(request, "House");
                                    valid = 1;
                                }
                            }

                            if (valid == 0) {
                                cout << "You have already rated this request!" << endl;
                            }
                        } else {
                            cout << "You haven't occupied a house yet!/ Your request hasn't been finished yet!\n";
                        }

                        system("pause");
                        memberFunction(user);
                    case 9: {
                        //Rate Occupiers
                        if (!RC.getOccupierUsername(takeCurrentHomeID()).empty()) {
                            cout << "Pending user for rating\n";

                            for (Request request: RC.getOccupierUsername(takeCurrentHomeID())) {
                                cout << "\n-------------------------\n";
                                request.showInfo();
                            }
                            cout << "\n-------------------------\n";
                            string requestID;
                            requestID = inputHouseRating(RC.getOccupierUsername(takeCurrentHomeID()));
                            bool success = 0;

                            for (Request request: RC.getOccupierUsername(takeCurrentHomeID())) {
                                if (request.getId() == requestID && RaC.ratingValid("User", requestID)) {
                                    RaC.rating(request, "User");
                                    success = 1;
                                }
                            }

                            if (success == 0) {
                                cout << "You have already rated this occupier!" << endl;
                            }

                        } else {
                            cout << "There is no occupier for you to rate!\n";
                        }


                        system("pause");
                        memberFunction(user);
                    }
                    case 0:
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
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
            check = true;
        }
    }
}

/**
 * Admin Menu
 * @param admin
 */
void View::adminFunction(User admin) {
    cout << "|-------------- Admin menu --------------|"
            "|1. Show all user data                   |\n"
            "|2. View All Houses Details              |\n"
            "|3. Exit                                 |\n"
            "|----------------------------------------|"
         << endl;
    bool check = true;
    string input;
    while (check) {
        try {
            typeAgain:
            cout << "Enter your choice: ";
            cin >> input;
            cin.ignore();
            if (View::isNumber(input)) {
                int num = stoi(input);
                switch (num) {
                    case 1:
                        //Show all user data
                        UC.showData();
                        system("pause");
                        adminFunction(admin);
                    case 2:
                        //View All Houses Details
                        HC.showData();
                        system("pause");
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
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
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
            getline(cin, startDate);
            CustomDate start;
            if (CustomDate::validDate(startDate)) {
                try {
                    start = CustomDate(startDate);
                } catch (...) {
                    throw ConversionErr("DATE_CONVERSION_ERROR");
                }
            } else {
                throw NotfoundErr("INVALID_DATE");
            }

            cout << "End date (dd/mm/yyyy): ";
            getline(cin, endDate);
            CustomDate end;
            if (CustomDate::validDate(endDate)) {
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
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
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
            cout << "Enter your city choice (Hanoi/Saigon/Hue): ";
            getline(cin, city);
            if (city == "Hanoi" || city == "Saigon" || city == "Hue") {
                return city;
            } else {
                cout << "Invalid input! Please try again.\n";
            }
        }
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
        }
    }
}


House View::requestToOccupy() {
    string id;
    while (true) {
        try {
            bool found = false;
            cout << "Enter the house ID you want to occupy: ";
            getline(cin, id);
            for (House h: this->HouseArray) {
                if (id == h.getId()) {
                    found = true;
                    return h;
                }
            }
            if (found == false) {
                cout << "The id is not exist!\n";
            }
        }
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
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
            cout << "Enter the request ID that you want to accept: ";
            getline(cin, id);

            for (Request r: rc.getRequestArr()) {
                if (id == r.getId()) {

                    flag = false;
                    return id;
                }
            }
            cout << "Cannot find request ID " << id << "\n" << endl;
        }
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
        }
    }
}

string View::inputHouseRating(vector<Request> pendingArray) {
    string id;
    while (true) {
        try {
            bool found = false;
            cout << "Enter the request ID you want to rating: ";
            getline(cin, id);
            for (Request request: pendingArray) {
                if (id == request.getId()) {
                    found = true;
                    return id;
                }
            }
            if (found == false) {
                cout << "The id does not exist!\n";
            }
        }
        catch (exception &e) {
            cout << "Function stopped due to err: " << e.what() << endl;
            cin.ignore();
        }
    }
}

string View::takeCurrentHomeID() {
    string homeID;

    for (House house: HC.getHouseArray()) {
        if (UC.getCurrentUser().getUsername() == house.getOwnerUsername() && house.isStatus()) {
            homeID = house.getId();
        }
    }
    return homeID;
}






