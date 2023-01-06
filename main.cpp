/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Assessment: 3
  Author:
      s3891890, Tran Nam Thai
      s3878246, Pham Anh Thu
      s3891968, Pham Vo Dong
      s3927201, Tran Ngoc Khang
  Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to check)
  Created  date: 11/12/2022
  Acknowledgement: None
*/

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
