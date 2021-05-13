/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iomanip>
#include <sstream>
#include "Book.h"

namespace sdds
{
    const string &Book::title() const 
    {
        return m_title;
    }

    const std::string &Book::country() const 
    {
        return m_country;
    }

    const size_t &Book::year() const 
    {
        return m_year;
    }

    double &Book::price() 
    {
        return m_price;
    }

    Book::Book(const std::string &strBook) 
    {
        stringstream line(strBook);
        string tempToInt{};

        getline(line, m_author, ',');
        m_author.erase(0,m_author.find_first_not_of(' '));
        m_author.erase(m_author.find_last_not_of(' ')+1);

        getline(line, m_title, ',');
        m_title.erase(0,m_title.find_first_not_of(' '));
        m_title.erase(m_title.find_last_not_of(' ')+1);

        getline(line, m_country, ',');
        m_country.erase(0,m_country.find_first_not_of(' '));
        m_country.erase(m_country.find_last_not_of(' ')+1);

        getline(line, tempToInt, ',');
        m_price = stod(tempToInt);

        getline(line, tempToInt, ',');
        m_year = stoi(tempToInt);

        getline(line, m_description, '\n');
        m_description.erase(0, m_description.find_first_not_of(' '));
        m_description.erase(m_description.find_last_not_of(' ')+1);
    }

    ostream &operator<<(ostream &os, Book &src) 
    {
        os << setw(20) << src.m_author << " | ";
        os << setw(22) << src.title() << " | ";
        os << setw(5) << src.country() << " | ";
        os << setw(4) << src.year() << " | ";
        os << setw(6) << fixed << setprecision(2) << src.price() << " | ";
        os << src.m_description << endl;
        return os;
    }

    Book &Book::operator=(const Book &src) 
    {
        if(this != &src){
            m_author = src.m_author;
            m_title = src.m_title;
            m_country = src.m_country;
            m_year = src.m_year;
            m_price = src.m_price;
            m_description = src.m_description;
        }
        return *this;
    }

    Book::Book(const Book &src) 
    {
        *this = src;
    }
}