/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include "Autoshop.h"
#include "Car.h"

namespace sdds
{
    Autoshop &Autoshop::operator+=(Vehicle *theVehicle) 
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream &out) 
    {
        out << "--------------------------------\n";
        out << "| Cars in the autoshop!        |\n";
        out << "--------------------------------\n";
        std::vector<Vehicle*>::iterator i;
        for(i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
            (*i)->display(out);
            out << std::endl;
        }
        out << "--------------------------------\n";
    }

    Autoshop::~Autoshop() {
        std::vector<Vehicle*>::iterator i;

        for(i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
            delete *i;
        }
    }

}