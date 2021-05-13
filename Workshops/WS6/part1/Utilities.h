/*
---------------------------------------------------------
Workshop 6 part 1
Filename: Utilities.h
Author:	Yuhuan Zhou
Student ID: 149528192
------------------------------------------------------------
Date 2020-11-03
 I have done all the coding by myself and only copied the
 code that my professor provided to complete my workshops
 and assignments.
-----------------------------------------------------------
*/
#include <sstream>
#include "Vehicle.h"
#include "Car.h"

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
namespace sdds {
    Vehicle *createInstance(std::istream &in);
}

#endif