/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <sstream>
#include <iomanip>
#include "Movie.h"


namespace sdds
{
    const std::string &Movie::title() const 
    {
        return m_title;
    }

    Movie::Movie(const std::string &strMovie) 
    {
        if(!strMovie.empty()) 
        {
            stringstream line(strMovie);
            string tempToInt{};
            getline(line, m_title, ',');
            m_title.erase(0, m_title.find_first_not_of(' '));
            m_title.erase(m_title.find_last_not_of(' ') + 1);

            getline(line, tempToInt, ',');
            m_year = stoi(tempToInt);

            getline(line, m_description, '\n');
            m_description.erase(0, m_description.find_first_not_of(' '));
            m_description.erase(m_description.find_last_not_of(' ') + 1);
        }
        else
        {
            *this = Movie();
        }
    }

    ostream &operator<<(ostream &os, const Movie &src) 
    {
            os << setw(40) << src.m_title << " | ";
            os << setw(4) << src.m_year << " | ";
            os << src.m_description << endl;
        return os;
    }
}