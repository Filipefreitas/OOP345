/*
Name: Filipe Freitas
Student ID: 155737190
Workshop: Workshop 2 part 2
Seneca email: fda-cunha-de-freitas3@myseneca.ca
Date of completion: 2021-01-30
I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds 
{
	const int MAX_RECORDS = 10;
	class TimedEvents 
	{
		int rec_no;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;
		struct 
		{
			std::string event_name{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_RECORDS];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}
#endif