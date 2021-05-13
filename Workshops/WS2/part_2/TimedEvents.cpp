/*
Name: Filipe Freitas
Student ID: 155737190
Workshop: Workshop 2 part 2
Seneca email: fda-cunha-de-freitas3@myseneca.ca
Date of completion: 2021-01-30
I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
*/

#define _CRT_NO_SECURE_WARNINGS
#include <iomanip>
#include "TimedEvents.h"

namespace sdds
{
	TimedEvents::TimedEvents() 
	{
		rec_no = 0;
		startClock();
		stopClock();
	}

	void TimedEvents::startClock()
	{
		start_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		end_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
		if (rec_no < MAX_RECORDS)
		{
			this->events[rec_no].event_name = name;
			this->events[rec_no].units = "nanoseconds";
			this->events[rec_no].duration = ms;
			rec_no++;
		}
	}

	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.rec_no; i++)
			out << std::setw(20) << std::left
			<< events.events[i].event_name << ' ' << std::setw(12) << std::right
			<< events.events[i].duration.count() << ' '
			<< events.events[i].units << '\n';
		out << "--------------------------\n";
		return out;
	}
}