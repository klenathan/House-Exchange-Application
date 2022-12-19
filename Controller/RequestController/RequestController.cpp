//
// Created by Nathan Tran on 11/12/2022.
//

#include <iostream>
#include "./RequestController.h"


using std::string, std::cout, std::endl, std::exception;

RequestController::RequestController(string path) {
    this->dataPath = path + "./requests.csv";
    this->loadDataToArray();
}

void RequestController::setRequestArray(const vector<Request> &requestArray) {
    this->requestArr = requestArr;
}


void RequestController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        CustomDate startDate = CustomDate(line[3]);
        CustomDate endDate = CustomDate(line[4]);
        Status status = (*new Request).stoE(line[2]);
        Request temp_request = Request(line[0], line[1], status, startDate, endDate);
        this->requestArr.push_back(temp_request);
    }

}

void RequestController::create(const Request &newReq) {
    this->requestArr.push_back(newReq);
    this->writeFile();
}

void RequestController::writeFile() {
    string content;
    content += "username,house_id,status,start_date,end_date\n";
    for (Request request: this->requestArr) {
        content += request.to_string() + "\n";
    }
    cout << DataHandler::writeFile("requests.csv", content);
}


void RequestController::viewRequest(const User user, string currentPath) {
    for (Request request: this->requestArr) {
        if (user.getUsername() == (*new HouseController(currentPath)).findByKey(request.getHouse()).getOwnerUsername()) {
            cout << request << endl;
        }
    }
};

void RequestController::request(const User user, const House house) {
    string startDate, endDate;

    try {
        cout << "Start date (dd/mm/yyyy): ";
        std::getline(std::cin, startDate);
        CustomDate start;
        if ((*new CustomDate).validDate(startDate)) {
            try {
                start = CustomDate(startDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        cout << "End date (dd/mm/yyyy): ";
        std::getline(std::cin, endDate);
        CustomDate end;
        if ((*new CustomDate).validDate(endDate)) {
            try {
                end = CustomDate(endDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        bool validDateInput = (end > start);

        if (validDateInput && startDate >= house.getStartDate() && endDate <= house.getEndDate() && user.getUsername() != house.getOwnerUsername()) {
            Status status = (*new Request).stoE("requested");
            Request *tempRequest = new Request(user.getUsername(), house.getId(), status, start, end);
            this->create(*tempRequest);
            DataHandler::clear();
            cout << "-------- NEW REQUEST --------" << endl;
            tempRequest->showInfo();
        } else {
            cout << "The end date must be greater than the start date/The date input is out of range!";
        }

    } catch (exception const &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;

    }
}



