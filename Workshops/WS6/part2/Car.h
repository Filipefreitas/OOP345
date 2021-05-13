/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

namespace sdds{
    class Car : public Vehicle 
    {
        std::string m_maker{};
        char m_condition{};
        double m_topSpeed{};
    public:
        Car() = default;
        explicit Car(std::istream& fin);
        [[nodiscard]] std::string condition() const override;
        [[nodiscard]] double topSpeed() const override;
        void display(std::ostream& out) const override;
        ~Car() override = default;
    };
}


#endif