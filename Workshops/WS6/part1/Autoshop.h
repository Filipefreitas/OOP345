/*
---------------------------------------------------------
Workshop 6 part 1
Filename: Autoshop.h
Author:	Yuhuan Zhou
Student ID: 149528192
------------------------------------------------------------
Date 2020-11-03
 I have done all the coding by myself and only copied the
 code that my professor provided to complete my workshops
 and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds{
    class Autoshop{
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out);
        ~Autoshop();
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles){
            std::vector<Vehicle*>::iterator i;
            for(i = m_vehicles.begin(); i != m_vehicles.end(); i++){
                if(test(*i)){
                    vehicles.push_back(*i);
                }
            }
        }
    };
}
#endif
