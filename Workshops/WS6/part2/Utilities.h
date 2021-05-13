/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
namespace sdds 
{
    Vehicle *createInstance(std::istream &in);
}

#endif