//
// Created by ADMIN on 12/15/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_VIEW_H
#define HOUSEEXCHANGEAPPLICATION_VIEW_H

class View {
public:

    static void welcomeScreen();
    static bool inputValidate(std::string string);
    static void validateUser();
    static void guessFunction();
    View()=default;

    static void memberFunction();
};

#endif //HOUSEEXCHANGEAPPLICATION_VIEW_H
