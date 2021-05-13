/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-12
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include "ConfirmationSender.h"

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        cs_res_arr = nullptr;
        cs_count = 0;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] cs_res_arr;
        cs_res_arr = nullptr;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool found = false; 
        for (size_t i = 0; i < cs_count; i++ && !found)
        { 
            if (cs_res_arr[i] == &res)
            { 
                found = true; 
            } 
        }
        
        if (!found) 
        { 
            const Reservation** temp = new const Reservation * [cs_count + 1];
            for (size_t i = 0; i < cs_count; i++)
            { 
                temp[i] = cs_res_arr[i];
            }

            delete[] cs_res_arr;
            temp[cs_count] = &res;
            cs_count++;
            cs_res_arr = std::move(temp);
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        for (size_t i = 0; i < cs_count; i++)
        {
            if (cs_res_arr[i] == &res)
            {
                cs_res_arr[i] = nullptr;
                cs_count--;
            }
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs)
    {
        if (this != &cs)
        {
            cs_count = cs.cs_count;

            if (cs.cs_res_arr != nullptr)
            {
                cs_res_arr = new const Reservation * [cs_count];

                for (size_t i = 0; i < cs_count; i++)
                {
                    cs_res_arr[i] = cs.cs_res_arr[i];
                }
            }
            else
            {
                cs_res_arr = nullptr;
            }

        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) 
    {
        *this = cs;
    }
   
 
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) noexcept
    {
        if (cs.cs_res_arr != nullptr)
        {
            swap(cs_res_arr, cs.cs_res_arr);
            cs_count = cs.cs_count;
            cs.cs_count = 0;
            cs.cs_res_arr = nullptr;
        }        
    }

    ostream& operator<<(ostream& os, ConfirmationSender& cs)
    {
        if (cs.cs_count == 0)
        {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            os << "There are no confirmations to send!\n";
            os << "--------------------------\n";
        }
        else
        {
            os << "--------------------------\n";
            os << "Confirmations to Send\n";
            os << "--------------------------\n";
            for (size_t i = 0; i < cs.cs_count; i++)
            {
                if (cs.cs_res_arr[i] != nullptr)
                {
                    os << *cs.cs_res_arr[i];
                }
            }
            os << "--------------------------\n";
        }
        return os;
    }


} 