//
// Created by Nathan Tran on 11/12/2022.
//

#ifndef HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
#define HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H

#include <vector>
#include "../../Model/Request/Request.h"
#include "../../Data/DataLoader/DataHandler.h"

using std::string, std::vector;

class RequestController {
private:
    vector<Request> requestArr;
public:

    RequestController();

};

#endif //HOUSEEXCHANGEAPPLICATION_REQUESTCONTROLLER_H
