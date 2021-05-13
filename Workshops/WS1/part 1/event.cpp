/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-01-21

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <cstring>
#include <iomanip>

unsigned long g_sysClock;
using namespace std;

namespace sdds {

    Event::Event() 
    {
        m_event = nullptr;
        m_startTime_in_seconds = 0;
    }

    Event::~Event() 
    {
        if (m_event == nullptr)
        {
            delete[] m_event;
        }
    }

    void Event::display() 
    {
        static int count = 1;
        int hh = 0, mm = 0, ss = 0;

        hh = m_startTime_in_seconds / 3600;
        mm = m_startTime_in_seconds / 60 % 60;
        ss = m_startTime_in_seconds % 60;

        if (m_event == nullptr)
        {
            cout << setw(3) << setfill(' ') << count << ". " << "| No Event |\n";
        }
        else 
        {
            cout << setw(3) << setfill(' ') << count << ". " << setw(2) << setfill('0') << hh << ":" << setw(2)
                << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " => " << m_event << "\n";
        }
        count++;
    }

    void Event::set(char* arr)
    {
        if (arr != nullptr) 
        {
            if (m_event != nullptr) 
            {
                m_event = nullptr;
            }
            m_event = new char[strlen(arr) + 1];
            strcpy(m_event, arr);
            m_startTime_in_seconds = g_sysClock;
        }
        else 
        {
            m_event = nullptr;
            m_startTime_in_seconds = 0;
        }
    }
}