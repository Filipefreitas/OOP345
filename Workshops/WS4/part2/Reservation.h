/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-12
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

namespace sdds
{
	class Reservation
	{
	protected:
		string res_id;
		string res_name;
		string res_email;
		int res_people;
		int res_day;
		int res_hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		friend ostream& operator << (ostream &os, const Reservation& res);
	};
}

#endif