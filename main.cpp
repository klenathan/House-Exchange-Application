#include <iostream>
#include <random>


#include "Controller/UserController/UserController.h"
#include "Controller/HouseController/HouseController.h"
#include "Controller/RatingController/RatingController.h"

#ifdef _WIN32
#include <Windows.h>
#else

#include <unistd.h>

#endif

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char *argv[]) {



    string currentPath = DataHandler::getPath(argv[0]);
    cout << currentPath << endl;

    HouseController HC = HouseController(currentPath);
    HC.showData();

//    RatingController ratingController = RatingController();
//
//    ratingController.setCurrentUser(user);
//
//    ratingController.rating(house);
//    cout << "status: " << UC.include("user1") << endl;

//
//    UC.showData();
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
//    CustomDate start = CustomDate(12, 10, 2022);
//    CustomDate end = CustomDate(12, 10, 2022);
//    House house = House("happy house", "Hanoi", "The Happy house", "user1", 0,
//                        start,
//                        end, 100, 120);
//    HC.create(house);
//    string housePath = argv[0] + ;

//    string housePath = argv[0] + ;
//    HouseController HC = HouseController(currentPath);
//HC.showData();
//    HC.listNewHouse();

//    HC.writeHouseData();

///////////////////////////////
    return 0;
}
