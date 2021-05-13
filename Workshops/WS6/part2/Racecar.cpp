/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include "Racecar.h"

namespace sdds{

    Racecar::Racecar(std::istream &in) : Car(in) 
    {
        std::string booster;
        getline(in, booster, '\n');
        m_booster = std::stod(booster);
    }

    void Racecar::display(std::ostream &out) const 
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const 
    {
        return Car::topSpeed() * (1 + m_booster);
    }
}