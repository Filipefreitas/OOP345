/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-12
I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include "Restaurant.h"

        namespace sdds
        {
            Restaurant::Restaurant()
            {
                rest_reserves = nullptr;
                rest_num = 0;
            }

            Restaurant::~Restaurant()
            {
                delete[] rest_reserves;
                rest_reserves = nullptr;
            }

            Restaurant::Restaurant(const Reservation* reservations[], size_t count)
            {
                rest_num = 0;
                size_t i = 0;
                rest_reserves = new Reservation[count];

                for (i = 0; i < count; ++i)
                {
                    rest_reserves[i] = *reservations[i];
                }
                rest_num = count;
            }

            size_t Restaurant::size() const
            {
                return rest_num;
            }

            ostream& operator<<(ostream& os, const Restaurant& res)
            {
                static size_t CALL_CNT = 0;
                ++CALL_CNT;
                if (res.size() <= 0)
                {
                    os << "--------------------------\n";
                    os << "Fancy Restaurant (" << CALL_CNT << ")\n";
                    os << "--------------------------\n";
                    os << "This restaurant is empty!\n";
                    os << "--------------------------\n";
                }
                else
                {
                    os << "--------------------------\n";
                    os << "Fancy Restaurant (" << CALL_CNT << ")\n";
                    os << "--------------------------\n";
                    for (size_t i = 0; i < res.size(); ++i)
                    {
                        os << res.rest_reserves[i];
                    }
                    os << "--------------------------\n";
                }
                return os;
            }

            Restaurant::Restaurant(const Restaurant& res)
            {                
                if (res.rest_reserves != nullptr)
                {
                    rest_reserves = new Reservation[res.size() + 1];
                    for (size_t i = 0; i < res.size(); ++i)
                    {
                        rest_reserves[i] = res.rest_reserves[i];
                    }
                    rest_num = res.rest_num;
                }
            }

            Restaurant::Restaurant(Restaurant&& res) noexcept
            {
                if (res.rest_reserves != nullptr)
                {
                    swap(rest_reserves, res.rest_reserves);
                    rest_num = res.rest_num;
                    res.rest_num = 0;
                    res.rest_reserves = nullptr;
                }
            }

            Restaurant & Restaurant::operator=(const Restaurant& res)
            {
                
                if (this != &res)
                {
                    delete[] rest_reserves;
                    size_t i = 0;
                    rest_reserves = new Reservation[res.size() + 1];
                    for (i = 0; i < res.size(); ++i)
                    {
                        rest_reserves[i] = res.rest_reserves[i];
                    }
                    rest_num = res.rest_num;
                }
                
                return *this;
            }

            Restaurant& Restaurant::operator=(Restaurant&& res) noexcept
            {

                if (this != &res)
                {
                    rest_reserves = res.rest_reserves;
                    rest_num = res.rest_num;

                    res.rest_reserves = { nullptr };
                    res.rest_num = { 0 };
                }

                return *this;
            }

        } // namespace sdds
