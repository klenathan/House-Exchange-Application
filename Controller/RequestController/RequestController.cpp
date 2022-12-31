//
// Created by Nathan Tran on 11/12/2022.
//

#include <iostream>
#include "./RequestController.h"


using std::string, std::cout, std::endl, std::exception;

RequestController::RequestController(string path, HouseController HC, UserController UC) {

    this->dataPath = path + "./requests.csv";
    this->HC = HC;
    this->UC = UC;
    this->loadDataToArray();
}

void RequestController::setRequestArray(const vector<Request> &requestArray) {
    this->requestArr = requestArr;
}

const vector<Request> &RequestController::getRequestArr() const {
    return requestArr;
}

void RequestController::loadDataToArray() {
    vector<vector<string>> rawData = DataHandler::loadFile(this->dataPath);

    for (vector<string> line: rawData) {
        Status status = (*new Request).stoE(line[3]);
        CustomDate startDate = CustomDate(line[4]);
        CustomDate endDate = CustomDate(line[5]);
        Request temp_request = Request(this->UC, this->HC, line[0], line[1], line[2], status, startDate, endDate);
        this->requestArr.push_back(temp_request);
    }
}

void RequestController::create(const Request &newReq) {
    this->requestArr.push_back(newReq);
    this->writeFile();
}

void RequestController::writeFile() {
    string content;
    content += "request_id,username,house_id,status,start_date,end_date\n";
    for (Request request: this->requestArr) {
        content += request.to_string() + "\n";
    }
    cout << DataHandler::writeFile("requests.csv", content);
}

void RequestController::viewRequest(const User user) {
    for (Request request: this->requestArr) {
        if (user.getUsername() == request.getHouse().getOwnerUsername()) {
            cout << "------------------------------" << endl;
            cout << request << endl;
        }
    }
};

bool RequestController::requestExist(const User user) {
    for (Request request: this->requestArr) {
        if (user.getUsername() == request.getHouse().getOwnerUsername()) {
            return true;
        }
    }
    return false;
}

void RequestController::acceptRequest(const User user, const string &id, HouseController houseController) {
    for (int i = 0; i < requestArr.size(); i++) {
        if (user.getUsername() == requestArr[i].getHouse().getOwnerUsername()) {
            if (requestArr[i].getId() == id) {
                Status status = accepted;
                requestArr[i].setStatus(status);
                requestArr.at(i) = requestArr[i];
                this->UC.updateCreditPoint(user, requestArr[i].getUser(), requestArr[i].getHouse().getConsumingPoint());
            } else {
                Status status = rejected;
                requestArr[i].setStatus(status);
                requestArr.at(i) = requestArr[i];
            }
        }
    }

    this->writeFile();
}

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

        if (validDateInput && startDate >= house.getStartDate() && endDate <= house.getEndDate() &&
            user.getUsername() != house.getOwnerUsername()) {
            Status status = (*new Request).stoE("requested");
            Request *tempRequest = new Request(this->UC, this->HC, user.getUsername(), house.getId(), status, start, end);
            this->create(*tempRequest);
            DataHandler::clear();
            cout << "-------- NEW REQUEST --------" << endl;
            tempRequest->showInfo();
        } else {
            cout << "The end date must be greater than the start date/The date input is out of range!\n";
        }

    } catch (exception const &e) {
        cout << "Function stopped due to err: " << "\033[31m" << e.what() << "\033[0m" << endl;

    }
}

/**
 * Get current house ID that the user is occupying or have benn occupied
 * @param user
 * @return house id
 */
string RequestController::getHouseForRating(const User user){
    for (Request request: this->requestArr) {
        if (user.getUsername() == request.getOccupyName() &&
            (       (const char *) request.getStatus() == "accepted"
                ||  (const char *) request.getStatus() == "finished")) {
            cout << request.getHouse().getId();
            return request.getHouse().getId();
        }
    }
}

/**
 * Get username of the occupier
 * @param House house
 * @return occupier username
 */
string RequestController::getOccupierUsername(const House house) {
    for (Request request: this->requestArr) {
        if (house.getId() == request.getHouse().getId()) {
            return request.getUser().getUsername();
        }
    }
};

