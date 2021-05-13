/*
---------------------------------------------------------
Workshop 6 part 1
Filename: Utilities.cpp
Author:	Yuhuan Zhou
Student ID: 149528192
------------------------------------------------------------
Date 2020-11-03
 I have done all the coding by myself and only copied the
 code that my professor provided to complete my workshops
 and assignments.
-----------------------------------------------------------
*/
#include "Utilities.h"

namespace sdds {
    Vehicle *createInstance(std::istream &in) {
        Vehicle *ptr = nullptr;
        std::string temp;
        getline(in, temp);
        temp.erase(0, temp.find_first_not_of(' '));
        std::stringstream line(temp);
        if (!temp.empty()) {
            if (temp[0] == 'c' || temp[0] == 'C') {
                ptr = new Car(line);
            } else {
                std::string tag{};
                getline(line, tag, ',');
                throw "Unrecognized record type: [" + tag + "]";
            }
        } else{
            ptr = nullptr;
        }
        return ptr;
    }
}