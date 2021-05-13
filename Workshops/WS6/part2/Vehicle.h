/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

// Workshop 6 - STL Containers
// 2020/02/26 - Cornel

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

namespace sdds
{
	class Vehicle
	{
	public:
		virtual double topSpeed() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual std::string condition() const = 0;
		virtual ~Vehicle() {};
	};
}

#endif
