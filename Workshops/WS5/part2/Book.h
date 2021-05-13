/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
    class Book
    {
        string m_author{};
        string m_title{};
        string m_country{};
        size_t m_year{};
        double m_price{};
        string m_description{};

    public:
        Book() = default;
        Book(const Book& src);
        Book&operator=(const Book& src);
        [[nodiscard]] const string& title() const;
        [[nodiscard]] const std::string& country() const;
        [[nodiscard]] const size_t& year() const;
        double& price();
        explicit Book(const std::string& strBook);
        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_description);
        }
        friend ostream&operator <<(ostream& os , Book &src);
    };
}
#endif