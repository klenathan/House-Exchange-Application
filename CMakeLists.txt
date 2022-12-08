cmake_minimum_required(VERSION 3.23)
project(HouseExchangeApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(HouseExchangeApplication
        main.cpp
        Model/User/User.h Model/CustomDate/CustomDate.h Service/HouseService.cpp Controller/MemberController.cpp Data/DataLoader/DataLoader.h Model/House/House.h Model/CustomDate/CustomDate.cpp Model/User/User.cpp Model/House/House.cpp Data/DataLoader/DataLoader.cpp Controller/UserController/UserController.cpp Controller/UserController/UserController.h Controller/HouseController/HouseController.h Controller/HouseController/HouseController.cpp Model/Request/Request.h Model/Request/Request.cpp)
