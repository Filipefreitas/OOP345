/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-12
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds
{
    class Restaurant
    {
        Reservation* rest_reserves = nullptr;
        int rest_num = 0;

    public:
        Restaurant();
        ~Restaurant();
        Restaurant(const Reservation* reservations[], size_t count);
        Restaurant(const Restaurant& res);
        Restaurant(Restaurant&& res) noexcept;
        Restaurant& operator =(const Restaurant& res); 
        Restaurant& operator =(Restaurant&& res) noexcept;
        size_t size() const;
        friend ostream& operator<<(ostream&, const Restaurant&);
    };

}

#endif //SDDS_RESTAURANT_H