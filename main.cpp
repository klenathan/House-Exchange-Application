#include <iostream>

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


    View::welcomeScreen();
    View::validateUser();
    return 0;
}
