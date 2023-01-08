# SED Group Assignment

---
# Description
Assume that we are involved in a start-up who came up with an idea to make an app for people to exchange their houses on vacation. The app will allow registered members to use houses of other members when they go on vacation.
# Lecturer
Mr Linh Tran & Phong Ngo. 

# Team Members

Pham Anh Thu (s3878246) 

Pham Vo Dong (s3891968) 

Tran Ngoc Khang (s3927201) 

Tran Nam Thai (s3891890) 

# Features
The program has 2 sets of features: basic feature, required by the lecturer and improved feature that we im proved from ***C. Time Period Feature***
## Basic Features

1. A non-member can register to become a member (information is recorded).
2. A non-member can view all house details (but not their reviews and availability).
3. A member can login with the registered username and password, and can view all of his/her information.
4. An admin can login with predefined username and password, and can view information of all members and houses.
5. A member can list his/her house available to be occupied (with consuming points, and minimum required occupier rating), and unlist it if wanted.
6. A member can search for all available suitable houses for a particular city (suitable with his current credit points and rating score).
Example:
My credit is 100, score = 7
There is a house with consuming point: 150/day, minimum required score is 6.
è This house won’t be available in my search (since I do not have enough credit for it).
7. A member can request to occupy a house.
8. A member can view all requests to his listed house.
9. A member can accept a request (reject all other requests).
10. A member can occupy the successfully requested house.
   
11. A member can rate each of his/her occupied houses (score and comment).
12. A member (house owner) can rate each of the occupiers who had used his/her house
(score and comment).
13. All data must be saved into a file before the program is ended, and loaded into the
program when it is started.


## Improved feature
1. Time overlap handle: automatically reject request that has overlap time with accepted request of a house.