/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out);
        ~Autoshop();
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles)
        {
            std::vector<Vehicle*>::iterator i;
            for(i = m_vehicles.begin(); i != m_vehicles.end(); i++)
            {
                if(test(*i))
                {
                    vehicles.push_back(*i);
                }
            }
        }
    };
}
#endif
