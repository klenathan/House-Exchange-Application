#include <iostream>
#include <random>


#include "Controller/UserController/UserController.h"
#include "Controller/HouseController/HouseController.h"
#include "Controller/RatingController/RatingController.h"
#include "Controller/RequestController/RequestController.h"

#ifdef _WIN32
#include <Windows.h>
#else

#include <unistd.h>

#endif

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char *argv[]) {

//    string currentPath = DataHandler::getPath(argv[0]);
//    cout << currentPath << endl;
//    UserController UC = UserController(currentPath);
//    HouseController HC = HouseController(currentPath);
//
//    User user = *new User("user3", "123", "Pham Vo Dong", "03926122231", 500, 10);
////    House house = *new House("3","happy house","Hanoi","The Happy house 1","user1",100,*new CustomDate("12/02/2023"), *new CustomDate("28/02/2023"),3.0,8.000000,1);
//
//    User user2 = *new User("user2", "123", "Pham Vo Dong", "03926122231", 500, 10);
//
//    RatingController ratingController = RatingController(currentPath);
//////
//    ratingController.setCurrentUser(user);
//
////    ratingController.rating(user2, HC.getHouseArray());
////for (User user1 : ratingController.userRatingAverage(const_cast<vector<User> &>(UC.getUserArray()))){
////    cout << user1;
////}
//
//UC.setUserArray(ratingController.ratingAverage(const_cast<vector<User> &>(UC.getUserArray())));
//
//UC.showData();

//    HC.setHouseArray(ratingController.ratingAverage((vector<House> &) HC.getHouseArray()));
//
//    HC.showData();
////
//    ratingController.rating(house);
//UC.signup();


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
    string currentPath = DataHandler::getPath(argv[0]);
    cout << currentPath << endl;
    UserController UC = UserController(currentPath);
    HouseController HC = HouseController(currentPath);
    RequestController RC = RequestController(currentPath, HC, UC);

    CustomDate start = CustomDate(12, 12, 2023);
    CustomDate end = CustomDate(15, 12, 2023);

    User user1 = *new User("user1", "123", "The first user", "0123456789", 500, 8);

    User user2 = *new User("user2", "123", "The first user", "0123456789", 500, 8);
    House house = *new House("900","happy house 1", "Hanoi", "The Happy house", "user1",100,start,end,6,0,0,150);

    RC.acceptRequest(user1, "3789", HC);
    cout << "User requests" << endl;
    RC.viewRequest(user1);
//    RC.request(user2, house);
//    RC.viewRequest(user1, currentPath);

//    UC.signup();
//    HC.listNewHouse("user1");
//    1.	Each member can only add one house to his/her account.
//    if ("user1" != HC.getUserHouse("user1").getOwner()) {
//        HC.listNewHouse("user1");
//    } else {
//        cout << "Each member can only add one house to his/her account.\n";
//    }
//    User user2 = *new User("user2", "123", "The first user", "0123456789", 500, 8);
//

//    HC.searchForSuitableHouses("Hanoi", start, end, user2);

//    HC.showData();



///////////////////////////////


    return 0;
}
