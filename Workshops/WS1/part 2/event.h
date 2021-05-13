/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-01-23
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef EVENT_H 
#define EVENT_H
#include<iostream>

namespace sdds 
{
	class Event 
	{
	private:
		char m_event[128];
		size_t m_startTime_in_seconds;
	public:
		Event();
		void display();
		void set(char* arr = NULL);
	};
}
#endif

