/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <iomanip>      
#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
namespace sdds
{
    SpellChecker::SpellChecker(const char *filename) 
    {
        ifstream file(filename);
        if(!file)
        {
            throw "Bad file name!";
        }
        else
        {
            string temp;
            size_t i = 0;
            while (file && i < MAX)
        {
                getline(file, m_badWords[i], ' ');
                m_badWords[i].erase(0,m_badWords[i].find_first_not_of(' '));
                m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
                getline(file, m_goodWords[i], '\n');
                m_goodWords[i].erase(0,m_goodWords[i].find_first_not_of(' '));
                m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
                m_replacedWords[i] = 0;
                i++;
            }
            file.close();
        }
    }

    void SpellChecker::operator()(std::string &text)
    {
        for (int i = 0; i < MAX; ++i) 
        {
            while (text.find(m_badWords[i]) != string::npos)
            {
                text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
                m_replacedWords[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const
    {   
        out << "Spellchecker Statistics\n";
        for (int i = 0; i < MAX; ++i)
        {
            out << std::setw(15) << std::setfill(' ') << std:: right << m_badWords[i] << ": " << m_replacedWords[i] << " replacements\n";
        }
    }
}