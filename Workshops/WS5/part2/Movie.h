/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
    class Movie
    {
        string m_title{};
        size_t m_year{};
        string m_description{};
    public:
        Movie() = default;
        [[nodiscard]] const std::string& title() const;
        explicit Movie(const std::string& strMovie);
        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description);
        }
        friend ostream&operator <<(ostream& os, const Movie&src);
    };
}
#endif
