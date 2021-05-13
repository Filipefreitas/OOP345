/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-12
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
        const Reservation** cs_res_arr;
        size_t cs_count =  0;

    public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& cs);
        ConfirmationSender(ConfirmationSender&& cs) noexcept;
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        ConfirmationSender& operator=(const ConfirmationSender& cs);
        friend ostream& operator<<(ostream&, ConfirmationSender&);
    };
} 

#endif //SDDS_CONFIRMATIONSENDER_H