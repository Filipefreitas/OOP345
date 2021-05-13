/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-01-21

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

*/

#ifndef EVENT_H 
#define EVENT_H

#define _CRT_SECURE_NO_WARNINGS
extern unsigned long g_sysClock;

namespace sdds 
{
	class Event 
	{
	private:
		char *m_event;
		size_t m_startTime_in_seconds;
	public:
		Event();
		~Event();
		void display();
		void set(char arr_in[]);
	};
}
#endif

