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
    View VC = View(path);
    VC.welcomeScreen();
    VC.validateUser();

    return 0;
}
