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

int main(int argc, const char *argv[]) {
    ///// Running code
    string path = DataHandler::getPath(argv[0]);
    HouseController HC = HouseController(path);
    UserController UC = UserController(path);
    RequestController RC = RequestController(path, HC, UC);
    RatingController rtC = RatingController(path, RC.getRequestArr());

//    RaC.writeFile();
rtC.writeFile();
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
