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
    bool dataChange = 0;

    for (vector<string> line: rawData) {
        Status status = (*new Request).stoE(line[3]);
        CustomDate startDate = CustomDate(line[4]);
        CustomDate endDate = CustomDate(line[5]);
        if (CustomDate::getToday() > endDate) {
            status = finished;
            dataChange = true;
        }
        Request temp_request = Request(this->UC, this->HC, line[0], line[1], line[2], status, startDate, endDate);
        this->requestArr.push_back(temp_request);
    }
    if (dataChange) this->writeFile();
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

bool RequestController::viewRequest(const User &user) {
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
    return exist;
};

void RequestController::viewSentRequest(const User &user) {
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
    }
}


/**
 * Function accept request from House owner through request ID
 * It will print out upon err occurs
 * */

void RequestController::acceptRequest(const string &id, const User &user) {
    bool idFound = false;
    Request resultRequest;
    for (Request &request: this->requestArr) {
        if (request.getId() == id) {
            if (request.getStatus() != Status::requested) {
                cout << "Request " << id << " is not in requested status, please check again" << endl;
            } else {
                idFound = true;
                request.setStatus(Status::accepted);
                this->UC.updateCreditPoint(user, request.getUser(),
                                           request.getHouse().getConsumingPoint(),
                                           request.getStartDate(), request.getEndDate());
                resultRequest = request;
                cout << "Request " << id << " has been accepted successfully" << endl;
            }
        }
    }

    if (idFound) {

        for (Request &request: this->requestArr) {
            if (
                    (request.getHouse().getId() == resultRequest.getHouse().getId())
                    && (request.getId() != id)
                    && (request.getStatus() == Status::requested)
                    && this->dateOverlap(request.getStartDate(), request.getEndDate(), resultRequest.getStartDate(),
                                         resultRequest.getEndDate())
                    ) {

                request.setStatus(Status::rejected);
            }
        }
        this->writeFile();
    }
}
// 10 - 20


bool RequestController::dateOverlap(const CustomDate &startDate1, const CustomDate &endDate1,
                                    const CustomDate &startDate2, const CustomDate &endDate2) {
    if ((startDate1 == endDate2) || (startDate2 == endDate1)) {
        return true;
    } else if ((startDate1 <= startDate2) && (endDate1 >= startDate2)) {
        return true;
    } else if ((startDate2 <= startDate1) && (endDate2 >= startDate1)) {
        return true;
    }
    return false;
}


void RequestController::request(const User &user, const House &house) {
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
        long totalPrice = house.getConsumingPoint() * (CustomDate::getDateRange(end, start));


        bool success = true;
        if (user.getUsername() == house.getOwnerUsername()) {
            cout << "You are the owner of this house so you cannot occupy this house!\n";
            success = false;
        } else if (!validDateInput || (startDate < house.getStartDate()) || (endDate > house.getEndDate())) {
            cout << "The end date must be greater than the start date/The date input is out of range!\n";
            success = false;
        } else if (user.getCreditPoints() < totalPrice) {
            cout << "You don't have enough money!\n";
            success = false;
        } else {
            for (Request &req: this->requestArr) {
                if (
                        (req.getStatus() == Status::accepted) &&
                        (this->dateOverlap(req.getStartDate(), req.getEndDate(), start, end))
                        ) {
                    if ((req.getOccupyName() == user.getUsername())) {
                        cout << "You have already occupied a house from " << req.getStartDate()
                             << " to " << req.getEndDate() << endl;
                        success = false;

                    } else if (req.getHouse().getId() == house.getId()) {
                        cout << "The house " << house.getId() << " is occupied from " <<
                             req.getStartDate() << " to " << req.getEndDate() << endl;
                        success = false;
                    }
                }

            }
        }


        if (success == true) {
            Status status = requested;
            Request *tempRequest = new Request(this->UC, this->HC, user.getUsername(), house.getId(),
                                               status, start, end);
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

