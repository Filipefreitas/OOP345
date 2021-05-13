/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-06-03
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds{
    class Racecar : public Car
    {
        double m_booster{0};
    public:
        explicit Racecar(std::istream& in);
        void display(std::ostream& out) const override;
        [[nodiscard]] double topSpeed() const override;
    };
}



#endif