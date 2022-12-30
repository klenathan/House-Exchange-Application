//
// Created by ADMIN on 12/15/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_VIEW_H
#define HOUSEEXCHANGEAPPLICATION_VIEW_H

class View {
public:
    View() = default;

    static void welcomeScreen();

    static void validateUser();

    static void guessFunction();

    static void memberFunction();

    static bool isNumber(const std::string &s);

    static std::string *dateInput(std::string *arr);

    static std::string cityInput();

    static std::string requestIdInput();

    static void adminFunction();
};

#endif //HOUSEEXCHANGEAPPLICATION_VIEW_H
