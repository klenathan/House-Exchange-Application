#include <iostream>
#include <random>


#include "Controller/UserController/UserController.h"
#include "Controller/HouseController/HouseController.h"

#ifdef _WIN32
#include <Windows.h>
#else

#include <unistd.h>

#endif

using std::string;
using std::cout;
using std::endl;



void loadingSequence() {
    int total = 6;
    cout << "hello: " << endl;
    cout << "0/" << total << ": " << std::flush;

    string loading;
    for (int i = 0; i < total; i++) {
        cout << std::flush;
        loading = "";
        for (int j = -1; j < i; j++) {
            loading += "+ ";
        }
        cout << "\r" << i + 1 << "/" << total << ": " << loading << std::flush;
        sleep(1);
    }
    cout << "\ndone" << endl;
}

int main(int argc, const char *argv[]) {



    string currentPath = DataHandler::getPath(argv[0]);
    UserController UC = UserController(currentPath);
//    cout << "status: " << UC.include("user1") << endl;
//
////    UC.showData();
//
//    cout << "Login: " << UC.login("user1", "1223") << endl;
//
//    UC.showData();




//    HC.showData();

//    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n"
//                 "VACATION HOUSE EXCHANGE APPLICATION\n"
//                 "Instructors: Mr. Linh Tran & Phong Ngo Group: Group Name\n\n"
//                 "s3891890, Tran Nam Thai\n"
//                 "sXXXXXXX, Student Name\n"
//                 "sXXXXXXX, Student Name\n"
//                 "sXXXXXXX, Student Name\n\n"
//                 "Use the app as 1. Guest 2. Member 3. Admin" << std::endl;
//    User user1 = User("user1", "123", 123);
//    cout << user1;
//    ptr = &user1;
//    ptr->showInfo();
//    user1.showInfo();
//
//    user1.addCreditPoints(100);
//    user1.showInfo();
///////////////////////////////
    CustomDate start = CustomDate(11, 10, 2022);
    CustomDate end = CustomDate(12, 10, 2022);

    cout << (start <= end) << endl;

//    House house = House("happy house", "Hanoi", "The Happy house", "user1", 0,
//                        start,
//                        end, 100, 120);
//    HC.create(house);
//    string housePath = argv[0] + ;

    HouseController HC = HouseController(currentPath);


    // Test
    vector<House> queryResult = HC.searchForSuitableHouses("HCM", start, end);
    for (House house: queryResult) {
        house.showInfo();
        cout << "=======================" << endl;
    }

    HC.writeHouseData();

///////////////////////////////
    return 0;
}
