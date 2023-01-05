#include <iostream>
#include "View/View.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>

#endif

using std::string, std::cout, std::endl;

int main(int argc, const char *argv[]) {
    ///// Running code
    string path = DataHandler::getPath(argv[0]);
    HouseController HC = HouseController(path);
    UserController UC = UserController(path);
    RequestController RC = RequestController(path, HC, UC);
    RatingController rtC = RatingController(path, RC.getRequestArr());


    HC.enableHouseListing("user3");



//    View VC = View(currentPath);
//    VC.welcomeScreen()
//    VC.validateUser();

    return 0;
}
