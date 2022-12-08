#include <iostream>

#include "Model/User/User.h"
#include "Model/House/House.h"
#include "Model/CustomDate/CustomDate.h"

#include "Data/DataLoader/DataLoader.h"

#include "Controller/UserController/UserController.h"
#include "Controller/HouseController/HouseController.h"

using namespace std;

int main() {

    UserController UC = UserController();
    cout << "status: " << UC.checkUserInArray("user1") << std::endl;

    HouseController HC = HouseController();
    vector<House> houseArr = HC.getUserHouse("user1");

    int counter = 1;
    for(House house: houseArr) {
        cout << "-------- " << counter << " --------" << std::endl;
        house.showInfo();
        cout << endl;
        counter++;
    }

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

//    CustomDate start = CustomDate(12, 10, 2022);
//    CustomDate end = CustomDate(12, 10, 2022);
//    House house = House("happy house", "Hanoi", "user1", "The Happy house", 0,
//                        start,
//                        end, 100, 120);

//    house.showInfo();

//    DataLoader d = DataLoader();
//    DataLoader::loadUserData();
//
//    CustomDate date = CustomDate(12, 10, 2023);
//    date.showInfo();
//    cout << date;


//    std::cout << user1.authenticate("123") << std::endl;
//    std::cout << user1.authenticate("1asd") << std::endl;


    return 0;
}
