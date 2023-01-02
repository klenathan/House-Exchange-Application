cmake_minimum_required(VERSION 3.23)
project(HouseExchangeApplication)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ ")

add_executable(HouseExchangeApplication
        main.cpp
        Model/User/User.h Model/CustomDate/CustomDate.h
        Data/DataLoader/DataHandler.h
        Model/House/House.h Model/CustomDate/CustomDate.cpp Model/User/User.cpp
        Model/House/House.cpp Data/DataLoader/DataHandler.cpp
        Controller/UserController/UserController.cpp Controller/UserController/UserController.h
        Controller/HouseController/HouseController.h Controller/HouseController/HouseController.cpp
        Model/Request/Request.h Model/Request/Request.cpp Controller/RequestController/RequestController.cpp
        Controller/RequestController/RequestController.h Model/CustomError/Errors.h
        Controller/RatingController/RatingController.h Model/HouseRating/HouseRating.h
        Controller/RatingController/RatingController.cpp Model/HouseRating/HouseRating.cpp
        Model/UserRating/UserRating.h Model/UserRating/UserRating.cpp View/View.cpp)
