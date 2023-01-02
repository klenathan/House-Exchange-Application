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
        if (CustomDate::getToday() > endDate) {
            status = finished;
        }
        Request temp_request = Request(this->UC, this->HC, line[0], line[1], line[2], status, startDate, endDate);
        this->requestArr.push_back(temp_request);
    }
    this->writeFile();
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
    DataHandler::writeFile("requests.csv", content);
}

void RequestController::viewRequest(const User &user) {
    bool exist = 0;
    for (Request request: this->requestArr) {
        if (user.getUsername() == request.getHouse().getOwnerUsername()) {
            cout << "------------------------------" << endl;
            cout << request << endl;
            exist = 1;
        }
    }
    if (exist == 0) {
        cout << "-> You don't have any request! <-\n";
    }
};

bool RequestController::viewSentRequest(const User &user) {
    bool exist = 0;
    for (Request req: this->requestArr) {
        if (req.getUser().getUsername() == user.getUsername()) {
            cout << "------------------------------" << endl;
            cout << req << endl;
            exist = 1;
        }
    }
    if (exist == 0) {
        cout << "-> You haven't sent any request! <-\n";
        return 0;
    }
    return 1;
}

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
        Status status;
        bool accept = 0;
        if (user.getUsername() == requestArr[i].getHouse().getOwnerUsername()) {
            if (requestArr[i].getId() == id) {
                if (requestArr[i].getStatus() != requested) {
                    cout << "-> Request " << requestArr[i].getId() << " is not in pending status <-" << endl;
                    status = requestArr[i].getStatus();
                } else {
                    status = accepted;
                    this->UC.updateCreditPoint(user, requestArr[i].getUser(),
                                               requestArr[i].getHouse().getConsumingPoint(),
                                               requestArr[i].getStartDate(), requestArr[i].getEndDate());
                    accept = 1;
                }
            } else {
                if (accept == 1) {
                    status = rejected;
                } else {
                    status = requestArr[i].getStatus();
                }
            }
            requestArr[i].setStatus(status);
            requestArr.at(i) = requestArr[i];
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
        if (CustomDate::validDate(startDate)) {
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
        if (CustomDate::validDate(endDate)) {
            try {
                end = CustomDate(endDate);
            } catch (...) {
                throw ConversionErr("DATE_CONVERSION_ERROR");
            }
        } else {
            throw NotfoundErr("INVALID_DATE");
        }

        bool validDateInput = (end > start);
        long totalPrice = house.getConsumingPoint() * ((*new CustomDate).getDateRange(end, start));


        bool success = true;
        if (user.getUsername() == house.getOwnerUsername()) {
            cout << "You are the owner of this house so you cannot occupy this house!\n";
            success = false;
        } else if (!validDateInput || startDate < house.getStartDate() || endDate > house.getEndDate()) {
            cout << "The end date must be greater than the start date/The date input is out of range!\n";
            success = false;
        } else if (user.getCreditPoints() < totalPrice) {
            cout << "You don't have enough money!\n";
            success = false;
        } else {
            for (int i = 0; i < requestArr.size(); i++) {
                if (requestArr[i].getOccupyName() == user.getUsername()) {
                    if ((requestArr[i].getStartDate() < startDate && requestArr[i].getEndDate() < startDate) ||
                        (requestArr[i].getStartDate() > startDate && requestArr[i].getEndDate() > startDate)) {
                        continue;
                    } else {
                        if (requestArr[i].getStatus() == rejected) {
                            continue;
                        } else {
                            cout << "You have already requested/occupied a house from " << requestArr[i].getStartDate()
                                 << " to " << requestArr[i].getEndDate() << endl;
                            success = false;
                        }
                    }
                }
            }
        }


        if (success == true) {
            Status status = requested;
            Request *tempRequest = new Request(this->UC, this->HC, user.getUsername(), house.getId(), status, start,
                                               end);
            this->create(*tempRequest);
            DataHandler::clear();
            cout << "-------- NEW REQUEST --------" << endl;
            tempRequest->showInfo();
        }

    } catch (exception const &e) {
        cout << "Function stopped due to error: " << "\033[31m" << e.what() << "\033[0m" << endl;

    }
}

/**
 * Get current house ID that the user is occupying or have benn occupied
 * @param user
 * @return house id
 */
vector<Request> RequestController::getHouseForRating(const User user) {
    vector<Request> pendingHouseRating;
    for (const Request &request: this->requestArr) {
        if (user.getUsername() == request.getOccupyName() && request.getStatus() == finished) {
            pendingHouseRating.push_back(request);
        }
    }
    return pendingHouseRating;
}

/**
 * Get username of the occupier
 * @param House house
 * @return occupier username
 */
vector<Request> RequestController::getOccupierUsername(string homeID) {
    vector<Request> pendingUseRating;
    for (Request request: this->requestArr) {
        if (homeID == request.getHouse().getId() && request.getStatus() == finished) {
            pendingUseRating.push_back(request);
        }
    }
    return pendingUseRating;
};

bool RequestController::updateRequestStatusToFinish(const std::string &requestid) {

    for (Request &request: this->requestArr) {
        if (request.getId() == requestid) {
            if (request.getStatus() == rejected) {
                cout << requestid << " has already been rejected" << endl;
                return false;
            } else if (request.getStatus() == requested) {
                cout << requestid << " has not been approved" << endl;
                return false;
            } else if (request.getStatus() == finished) {
                cout << requestid << " has already finished" << endl;
                return false;
            }
            request.setStatus(finished);
            this->writeFile();
            return true;
        }
    }
    return false;
}

