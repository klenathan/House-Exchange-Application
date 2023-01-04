#include <iostream>
#include <random>


#include "Controller/UserController/UserController.h"
#include "Controller/HouseController/HouseController.h"
#include "Controller/RatingController/RatingController.h"
#include "Controller/RequestController/RequestController.h"
#include "View/View.h"


#ifdef _WIN32

#include <Windows.h>

#else

#include <unistd.h>

#endif

using std::string;
using std::cout;
using std::endl;

std::string inputHouseRating(vector<Request> pendingArray) {
    string id;
    while (true) {
        try {
            bool found = false;
            cout << "Enter the house ID you want to rating: ";
            getline(cin, id);
            for (Request request: pendingArray) {
                if (id == request.getHouse().getId()) {
                    return id;
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
int main(int argc, const char *argv[]) {
    ///// Running code
    string path = DataHandler::getPath(argv[0]);
    HouseController HC = HouseController(path);
    UserController UC = UserController(path);
    RequestController RC = RequestController(path, HC, UC);
    RatingController rtC = RatingController(path, RC.getRequestArr());
    rtC.test();


//    RaC.writeFile();
    User user = User("user1", "123", 5.000000);
    if (!RC.getHouseForRating(user).empty()) {
        cout << "Pending house for rating\n";

        for (Request request: RC.getHouseForRating(user)) {
            cout << "\n-------------------------\n";
            request.showInfo();
        }
        cout << "\n-------------------------\n";
//
        string homeID;
        homeID = inputHouseRating(RC.getHouseForRating(user));
        for (Request request: RC.getHouseForRating(user)) {
            if (request.getHouse().getId() == homeID) {
                cout << request.getId();
                rtC.rating(request, "House");
            }
        }
    }
    rtC.test();
//    View VC = View(currentPath);
//    VC.welcomeScreen()
//    VC.validateUser();

    //// Test playground <3

//    string currentPath = DataHandler::getPath(argv[0]);
//    UserController UC = UserController(currentPath);
//    HouseController HC = HouseController(currentPath);
//    HC.searchForSuitableHouses("Saigon", *new CustomDate("13/10/2023"),*new CustomDate( "14/10/2023"), UC.getUserArray().at(0));

    return 0;
}
