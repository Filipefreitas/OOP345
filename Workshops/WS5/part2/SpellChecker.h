/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

using namespace std;

const int MAX = 6;

namespace sdds
{
    class SpellChecker
    {
        string m_badWords[MAX];
        string m_goodWords[MAX];
        size_t m_replacedWords[MAX] = {0};
    public:
        explicit SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const; 
    };
}
#endif